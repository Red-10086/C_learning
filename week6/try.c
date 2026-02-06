#include <stdio.h>

int main(void)
{
    double temp = 1.0;
    int n = 2;
    int x = 5;
    while(n-- > 0)
    {
        temp *= x;
    }

    return 0;
}