#include <stdio.h>

#define swap(type, a, b) type conv = a; a = b; b = conv;

int main(void)
{
    int x = 5;
    int y = 10;
    /* 交换前 */
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    swap(int, x, y);
    /* 交换后 */
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}