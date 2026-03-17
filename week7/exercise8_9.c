/* 
    练习8-9 创建一个程序,计算标准输入中出现的行数
*/

#include <stdio.h>

int main(void)
{
    int ch = 0;
    int count = 0;
    while((ch = getchar()) != EOF)
    {
        switch(ch)
        {
            case '\n':  count++; break;
            default:    break;
        }
    }

    printf("标准输入中一共有%d行\n", count);

    return 0;
}