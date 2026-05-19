/* 
硬编码的分支结构实现策略分发
*/
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);

int main(void)
{
    int (*p)(int , int);
    
    int choice = 0;
    int a = 0;
    int b = 0;

    while(1)
    {
        printf("请输入a:\n");       scanf(" %d", &a);
        printf("请输入b:\n");       scanf(" %d", &b);
        printf("请输入choice:\n");
        printf("输入1表示a+b\n");
        printf("输入2表示a-b\n");
        printf("输入3表示a*b\n");
        printf("输入4表示a/b\n");
        printf("输入5表示a%%b\n");
        printf("输入-1表示退出:\n");
        scanf(" %d", &choice);

        switch(choice)
        {
            case 1:
                p = add;
                break;
            case 2:
                p = sub;
                break;
            case 3:
                p = mul;
                break;
            case 4:
                p = div;
                break;
            case 5:
                p = mod;
                break;
            case -1:
                break;
            default:
                printf("无效选项\n");
                p = NULL;
                break;
        }

        if(choice == -1)
        {
            printf("程序结束");
            break;
        }
        else if(p != NULL)
        {
            printf("计算结果为:%d\n", p(a, b));
        }
        else
        {
            continue;
        }
    }

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