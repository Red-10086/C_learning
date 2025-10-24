#include <stdio.h>

int main()
{
    //变量初始化
    int count = 0;
    int digit = 0;

    //输入正整数
    printf("请输入一个整数：");
    scanf("%d", &count);

    //判断位数
    if(count<0)
    {
        count = -count;
    }
    while(count>0)
    {
        count/=10;
        digit++;
    }

    //输出计算结果
    printf("你输入的这个整数是%d位数", digit);

    return 0;
}