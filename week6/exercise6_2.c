#include <stdio.h>

int min3(int num1, int num2,int num3);

int main(void)
{
    int a = 0, b = 0, c = 0;
    
    printf("请输入a的值:\n");   scanf("%d", &a);
    printf("请输入b的值:\n");   scanf("%d", &b);
    printf("请输入c的值:\n");   scanf("%d", &c);
    
    printf("%d、%d、%d中最小的一个是:%d\n", a, b, c, min3(a,b,c));
    
    return 0;
}

int min3(int num1, int num2,int num3)
{
    int min = num1;
    if(num2 < min) 
    {
        min = num2;
    }
    
    if(num3 < min) 
    {
        min = num3;
    }

    return min;
}