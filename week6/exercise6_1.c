#include <stdio.h>

int min2(int num1, int num2);

int main(void)
{
    int a = 0, b = 0;
    
    printf("请输入两个整数：\n");
    for(;;)
    {
        if(scanf("%d %d", &a, &b) != 2)
        {
            printf("输入有误，请重新输入:\n");
            while(getchar() != '\n'); 
            continue;
        }
        break;
    }
    
    printf("%d和%d中最小的一个是:%d", a, b, min2(a, b));
    
    return 0;
}

int min2(int num1, int num2)
{
    int min = num1;

    if(num2 < min)
    {
        min = num2;
    }

    return min;
}