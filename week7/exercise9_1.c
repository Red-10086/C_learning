/* 
    练习9- 将list0903.c中的数组str的声明改为下面这样，查看程序运行结果。
    char str[] = "ABC\0DEF"
*/

#include <stdio.h>

int main(void)
{
    char str[] = "ABC\0DEF";

    printf("字符串str为 \"%s\" ", str);

    return 0;
}