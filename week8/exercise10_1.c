/* 
    练习10-1 编写函数adjust_point,如果n指向的值小于0,就将其修改为0;
    如果值大于100,就将其修改为100(如果是0~100的值,则不修改).
        void adjust_point(int *n){codes}
*/

#include <stdio.h>

void adjust_point(int *n);

int main(void)
{
    int count = 0;
    int *pointer = &count;
    
    printf("请输入一个整数:\n");
    scanf("%d", &count);

    adjust_point(pointer);/* 等价于传 &count */

    printf("程序处理后:%d\n", count);

    return 0;
}

void adjust_point(int *n)
{
    if(*n < 0)// n所指对象<0
    {
        *n = 0;
    }
    else if(*n > 100)// n所指对象>100
    {
        *n = 100;
    }
    else
    {
        // do nothing
    }
}