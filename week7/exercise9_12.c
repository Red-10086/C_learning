/* 
    练习9-12 编写如下函数,将所接受的字符串函数中存储的n个字符串的字符逆向显示
        void rev_string(char s[][128], int n){codes}
    例如,若s中接受的是{"SEC", "ABC"},则将其更新为{"CES", "CBA"}.
    
    逻辑拆分:
    main(){
        读函数(read);
        逆向并显示函数(rev_string);
        return 0;
    }

    rev_string{
        逆向函数(reverse);
        显示函数(write);
    }
    reverse{
        逐行遍历{
            行内-取字符串长度(s_len);
            行内-遍历字符串一半长度{
                关于数组"中轴"对称,首尾交换一次
            }
        }
    }
    s_len/read/write{略}
*/

#include <stdio.h>

#define row 10/* 字符串数组行数 */
#define arrlen 128/* 字符串数组列数 */

enum Numbers {five = 5};

void rev_string(char s[][arrlen], int n);/* s共n行,调用write和reverse需要他们给传总行数信息*/
void read(char s[][arrlen], int n);/* n:字符串数组的row,总行数 */
void write(char s[][arrlen], int n);/* 逐行写,直到遇见"$$$$$",或写完共n行 */
void reverse(char s[][arrlen], int n);/* 逐行反转s[][],共n行 */
int s_len(char s[][arrlen], int i);/* 字符串长度(不包括'\0') */
int is_five_dollars(char s[][arrlen], int i);/* 二维字符数组s下标i对应字符串 */

int main(void)
{
    char str[row][arrlen];
    
    read(str, row);
    rev_string(str, row);

    return 0;
}

void rev_string(char s[][arrlen], int n)
{
    reverse(s, n);
    write(s, n);
}

void read(char s[][arrlen], int n)/* n:字符串数组的row,总行数 */
{
    printf("请输入一些字符串,输入 \"$$$$$\"表示结束:\n");
    for(int i = 0, done = 0; i < n; i++)
    {
        scanf("%s", s[i]); /* 读 */

        done = is_five_dollars(s, i);/* 判断,是则结束读取,否则继续 */

        if(done)
        {
            break;
        }
    }
}


void write(char s[][arrlen], int n)/* 逐行写 */
{
    for(int i = 0, done = 0; i < n; i++)
    {
        done = is_five_dollars(s, i);

        if(done)/* 判断,是则结束打印,否则继续 */
        {
            break;
        }
        
        printf("%s\n", s[i]); /* 写 */
    }
}

void reverse(char s[][arrlen], int n)/* 逐行反转s[][],共n行 */
{
    for(int i = 0; i < n; i++)/* 逐行遍历 */
    {
        int len = s_len(s, i);

        for(int j = 0; j <= (len - 1) / 2; j++)/* 行内原地调头 */
        {
            int temp = 0;

            temp            = s[i][j];
            s[i][j]         = s[i][len-1-j];
            s[i][len-1-j]   = temp;
        }
    }
}

int is_five_dollars(char s[][arrlen], int i)/* 二维字符数组s下标i对应字符串 */
{
    int is_target_string = 0;/* 默认不是 */
    int len = s_len(s, i);/* 量字符串长度,不包含'\0' */

    if(len == five)/* 长度匹配 */
    {
        int j = 0;
        int counts = 0;
        while(s[i][j])/* 配合j++ 遍历字符串s[i] */
        {
            if(s[i][j] == '$')
            {
                counts++;
            }

            if(counts == five)/* '$'总数匹配 */
            {
                is_target_string = 1;
                break;
            }

            j++;
        }
    }

    return is_target_string;
}

int s_len(char s[][arrlen], int i)/* 字符串长度(不包括'\0') */
{
    int j = 0;
    
    while(s[i][j])
    {
        j++;
    }

    return j;
}