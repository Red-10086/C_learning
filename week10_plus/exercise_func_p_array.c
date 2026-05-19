/* 
函数指针数组 实现策略分发(无容灾设计,演示用) 取代 硬编码的分支结构
*/
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int max(int a, int b);
int min(int a, int b);

typedef int (*operation) (int , int);

operation method[] = {&add, &sub, &mul, &div, &mod, &max, &min};

int main(void)
{   
    int a = 0;
    int b = 0;
    int i = 0;

    printf("请输入a:\n");       scanf(" %d", &a);
    printf("请输入b:\n");       scanf(" %d", &b);
    printf("请输入i:\n");
    printf("输入0表示a+b\n");
    printf("输入1表示a-b\n");
    printf("输入2表示a*b\n");
    printf("输入3表示a/b\n");
    printf("输入4表示a%%b\n");
    printf("输入5表示max(a,b)\n");
    printf("输入6表示min(a,b)\n");
    scanf(" %d", &i);

    printf("计算结果为:%d\n",  method[i](a, b));

    return 0;
}

int add(int a, int b)
{
    int sum = a + b;
    
    return sum;
}

int sub(int a, int b)
{
    int diff = a - b;

    return diff;
}

int mul(int a, int b)
{
    int pro = a * b;

    return pro;
}

int div(int a, int b)
{
    int quo = 0;
    if(b != 0)
    {
        quo = a / b;
    }
    else
    {
        quo = EOF;
        printf("错误,0不可以做除数\n");
    }

    return quo;
}

int mod(int a, int b)
{
    int rem = 0;
    if(b != 0)
    {
        rem = a % b;
    }
    else
    {
        rem = EOF;
        printf("错误,0不可以做除数\n");
    }

    return rem;
}

int max(int a, int b)
{
    int maxi = a > b ? a : b;

    return maxi;
}

int min(int a, int b)
{
    int mini = a > b ? b : a;

    return mini;
}