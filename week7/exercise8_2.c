#include <stdio.h>

#define max(x, y) (((x) > (y) ? (x) : (y)))

int main(void)
{
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    max(a,b);
    max(max(a,b), max(c,d));
    printf("%d\n", max(max(a,b), max(c,d)));
    printf("%d\n", max(max(max(a, b), c), d));

    return 0;
}