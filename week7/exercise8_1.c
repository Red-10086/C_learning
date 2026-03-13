#include <stdio.h>

#define diff(x, y) (((x)>(y) ? ((x)-(y)) : ((y)-(x))))

int main(void)
{
    int x = 15;
    int y = 17;

    printf("%d", diff(x, y));

    return 0;
}