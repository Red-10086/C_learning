#include <stdio.h>

int main(void)
{
    int a[5];
    
    int *p_1 = &a[0];
    int *p_2 = a;

    printf("%p\n", p_1);
    printf("%p\n", p_2);

    if(p_1 == p_2)
    {
        printf("&a[0] == a");
    }
    else
    {
        printf("&a[0] != a");
    }

    return 0;
}