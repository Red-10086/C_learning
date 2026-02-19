#include <stdio.h>

int main(void)
{
    int n = 1;
    size_t A[10] = {0};
    A[0] = sizeof 1;
    A[1] = sizeof +1;
    A[2] = sizeof -1;
    A[3] = sizeof(unsigned)-1;
    A[4] = sizeof(double)-1;
    A[5] = sizeof((double)-1);
    A[6] = sizeof n+2;
    A[7] = sizeof (n+2);
    A[8] = sizeof (n+2.0);
    A[9] = sizeof ((double)1);
    
    for(int i = 0; i < (sizeof(A)/sizeof(A[0])); i++)
    {
        printf("A[%d] = %zu\t", i, A[i]);
    }

    return 0;
}