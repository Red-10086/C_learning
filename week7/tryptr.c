#include <stdio.h>

int main(void)
{
    int arr_2[4][3] = {0};
    int i = 0;
    int j = 0;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("arr_2[%d][%d] address: %p\n",i ,j, (void*)&arr_2[i][j]);
        }
    }

    return 0;
}