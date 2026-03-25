/* 
    练习9-11 编写一段程序,对代码清单9-12进行如下改写.
        将字符串的个数3改为更大的数,将其值定义为对象式宏
        将字符串的字符数改为128,将其制也定义为对象式宏
        生成读取字符串数组的函数.和练习9-3一样,在读取到"$$$$$"后,停止读取操作
        显示"$$$$$"前输入的所有字符串.
*/

#include <stdio.h>

#define row 10
#define length 128


void get_strary(const char s[][length], int r);/* 读取字符串数组 */
void put_strary(const char s[][length], int r);/* 打印字符串数组 */
int is_five_dollars(const char s[][length]);/* 判断是否是结束字符串 */

int main(void)
{
    char cs[row][length] = {{'\0'}};
    
	put_strary(cs, row);
    
	return 0;
}

void get_strary(const char s[][length], int r)
{
    for(int i = 0; i < r; i++)
    {
        printf("请输入字符串:\n");
        scanf("%s", s[i]);

        if(is_5$())
        {
            break;
        }
        else
        {
            continue;
        }
    }

}


int is_five_dollars(const char s[][length])/* 判断字符串是否是"$$$$$",是则返回1,否则返回0 */
{
    int rusult = 0;
    int dollars = 0;
    
    for(int i = 0; s[][i] != '\0'; i++)
    {
        if(s[])
    }
    
}

void put_strary(const char s[][length], int r)
{
    
}