#include <stdio.h>

int main()
{
    int N = 0;
    int fact = 1;
    
    //输入
    printf("请输入一个正整数：");
    scanf("%d", &N);

    //阶乘
    for(int i=1; i<=N; i++)
    {
        fact*=i;
        printf("i=%d,fact=%d\n", i, fact);
    }
    printf("N! = %d", N);

    return 0;
}