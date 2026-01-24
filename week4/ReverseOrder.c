#include <stdio.h>

int main()
{
    //初始化
    int Number = 0;
    int digit = 0;
    int rev = 0;

    //输入整数
    printf("请输入一个整数：");
    scanf("%d", &Number);

    //逆序
    while(Number>0)
    {
        digit = Number%10;
        rev = rev*10 + digit;
        printf("Number=%d digit=%d rev=%d");/*调试输出*/
        Number/=10;
    }

    //输出
    printf("%d", rev);

    return 0;
}