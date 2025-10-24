#include <stdio.h>

int main()
{
    int a, b, c;
    a = 5;
    b = 6;
    c = 0;

    c = a;
    a = b;
    b = c;

    printf("a= %d b= %d", a, b);

    return 0;
}