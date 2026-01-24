#include <stdio.h>

int main(void)
{
    //定义变量和初始化
    const int Number = 10;
    int i;
    int x;
    int counts[10];
    for( i = 0; i < Number; i++)
    {
        counts[i]=0;
    }

    //读取输入并计数
    printf("请输入0-9之间的整数,输入-1表示结束：");
    scanf("%d", &x);
    while(x!=-1)
    {
        if(x>=0 && x<=9)
        {
            counts[x]++;
        }
        scanf("%d", &x);
    }

    //遍历并打印计数结果
    for(i = 0 ; i < Number ; i++)
    {
        printf("%d出现次数: %d\n", i, counts[i]);
    }

    return 0;
}