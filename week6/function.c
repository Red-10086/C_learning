#include <stdio.h>

int main(void)
{
    void f(void);
    f();
    printf("here\n");

    return 0;
}

void f(void)
{
    int a[10]={0};
    a[9] = 1;
    printf("%d\n", a[9]);
}