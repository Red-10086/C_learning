#include <stdio.h>

void swamp(int x, int y);

int main(void)
{
    int a = 5;
    int b = 6;
    swamp(a,b);
    printf("a = %d b = %d\n", a, b);

    return 0;
}

void swamp(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}