#include <stdio.h>

int main(void)
{
    int a = 0b10010011;
    int b = 0b00001111;

    printf("a & b = %x", a&b);
    printf("a | b = %x", a|b);
    printf("a ^ b = %x", a^b);



    return 0;
}