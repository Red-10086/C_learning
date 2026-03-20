/* 
    编写如下函数，若字符串s中含有字符c（若涵有多个,以先出现的为准),则返回该元素的下标值,否则返回-1
        int str_char(const char s[], int c){codes}
*/

#include <stdio.h>

#define str_len 128

int str_char(const char s[], int c);

int main(void)
{
    int cu = 0;
    char str[str_len] = {'\0'};

    printf("请输入字符串:\n");
    scanf("%s", str);
    printf("请输入要查找的单字符:\n");

    /* %c前导空格以忽略空白字符,如换行符 回车符 */
    scanf(" %c", &cu);/* %c说明符能读取任何字符:包括换行、空格 */

    
    if(str_char(str, cu) == -1)
    {
        printf("字符串中没找到该字符");
    }
    else
    {
        printf("字符%c的下标是:%d", cu, str_char(str, cu));
    }

    return 0;
}

int str_char(const char s[], int c)/* 查找字符串中是否存在字符c,找到就返回下标,否则返回-1 */
{
    int index_c = 0;

    while(s[index_c] != c && s[index_c] != '\0')/* s[index_c] != '\0'确保不会无限循环---数组越界 */
    {
        /* 没找到c且字符串未结束,自增以访问下一个下标 */
        index_c++;
    }

    /* 如果始终都没找到,那么退出循环时,s[index_c]应该等于'\0',即下标指到了字符串的末尾 */
    if(s[index_c] == '\0')
    {
        index_c = -1;
    }
    
    return index_c;
}