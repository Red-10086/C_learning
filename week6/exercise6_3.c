#include <stdio.h>

int cube(int x);

int main(void)
{
    int x = 0;
    scanf("%d", &x);
    printf("%d", cube(x));

    return 0;
}

int cube(int x)
{
    return x*x*x;
}