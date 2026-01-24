#include <stdio.h>

void sum(int begin,int end);

int main()
{
    sum(0,10);
    sum(20,30);
    sum(25,35);

    return 0;
}

void sum(int begin,int end)
{
    int i = 0;
    int total = 0;
    for(i=begin ; i<=end ; i++)
    {
        total += i;
    }
    printf("从%d加到%d的结果是：%d\n", begin, end, total);
    return;
}