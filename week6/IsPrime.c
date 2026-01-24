#include <stdio.h>

//素数检验函数，默认传递的参数count是素数，如是则返回1，否则返回0
int isPrime(int count)
{
    int ret = 1;
    int k;
    for(k = 2; k < count; k++)
    {
        if(count%k == 0)
        {
            ret = 0;
            break;
        }
    }
    return ret;
}

int main(void)
{
    //定义变量和初始化
    int m = 0;
    int n = 0;
    int sum = 0;

    //提示词
    printf("请输入前小后大的两个正整数，我们会给出他们之间包含的素数有多少\n");

    //读输入
    scanf("%d %d", &m, &n);
    if(m==1)
    {
        m = 2;
    }

    //判断素数,是则计数，否则略过
    for(int i = m; i<=n; i++)
    {   
        if(isPrime(i))
        {
            sum ++;
        }
    }

    //打印结果
    printf("%d到%d之间一共有%d个素数", m, n, sum);

    return 0;
}