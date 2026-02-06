#include <stdio.h>

int sqr(int x);
int pows(int y);

int main(void)
{
    int x = 0;
    puts("请输入数字:");
    scanf("%d", &x);
    printf("%d的四次方是:%d\n", x, pows(x));

    return 0;
}

int sqr(int x)
{
    return x*x;
}

int pows(int y)
{
    return sqr( sqr(y) );
}