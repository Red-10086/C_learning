#include <stdio.h>
#define Count 2
#define Amount 2.5


int main(void)
{
    int a = 0;
    int *ptr = &a;
    printf("%p", (void*)ptr );


    return 0;
}