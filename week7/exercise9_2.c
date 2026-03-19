/* 
    如何让下述初始化赋值得到的字符串s变成空字符串?请编写程序实现
        char s[] = "ABC";
*/

#include <stdio.h>

int main(void)
{
    /* 按要求初始化 */
    char s[] = "ABC";

    
    s[0] = '\0';/* 空字符串:首字符即为'\0' */
    

    printf("字符串s内容:%s\n", s);
    printf("sizeof(s) == %zu\n", sizeof(s));

    return 0;
}