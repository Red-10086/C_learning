#include <stdio.h>

int main(void)
{
    size_t a = sizeof(1+2.0);
    printf("%zu", a);

    return 0;
}