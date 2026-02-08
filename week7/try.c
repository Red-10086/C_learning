#include <stdio.h>
#define N 2
#define M N+1
#define NUM (M+1)*M

int main(void)
{
    int i,n=0;
    for(i = 1; i <= NUM; i++)
    {
        n++;
        printf("%d ", n);
    }

    printf("\n");
    printf("%d\n", NUM);
    printf("%lf\n", NUM);
    
    return 0;
}