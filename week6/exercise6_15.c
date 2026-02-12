#include <stdio.h>

void put_count(void);

int main(void)
{
    int i = 5;
    while(i--)
    {
        put_count();
    }

    return 0;
}

void put_count(void)
{
    static int numbers = 0;
    numbers++;
    printf("被调用了%d次\n", numbers);
}