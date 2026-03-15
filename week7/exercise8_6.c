/* 
    练习8-6 不使用递归的方法来实现函数factorial(阶乘函数)
*/

#include <stdio.h>

enum factorial_0 { fac_0 = 1 };

long long unsigned factorial(long long unsigned n);

int main(void)
{
    long long unsigned n = 0;
    printf("请输入一个正整数:\n");
    scanf("%llu", &n);
    printf("%llu的阶乘是%llu", n, factorial(n));
    
    return 0;
}

long long unsigned factorial(long long unsigned n)
{
    long long unsigned result = 0;
    if(n > 0)
    {    
        result = fac_0;
        for(int i = 1; i <= n; i++)
        {
            result *= i;
        }
    }
    else if(n == 0)
    {
        result = fac_0;
    }

    return result;
}