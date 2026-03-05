#include <stdio.h>

int main(void)
{
    printf("float:\t\t%llubytes\ndouble:\t\t%llubytes\nlong double:\t%llubytes\n", sizeof(float), sizeof(double), sizeof(long double));

    return 0;
}