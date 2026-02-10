#include <stdio.h>

#define Three 3
#define Four 4

int main(void)
{
    
    int Matrix_A[Four][Three] = 
    {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}, 
        {10, 11, 12}
    };

    int Matrix_B[Three][Four] = 
    {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
    };

    int Matrix_Product[Four][Four] = {{0}};

    for(int i = 0; i < Four; i++)
    {
        for(int j = 0; j < Four; j++)
        {
            for(int k = 0; k < Three ; k++)
            {
                Matrix_Product[i][j] += (Matrix_A[i][k] * Matrix_B[k][j]); 
            }
        }
    }
    
    printf("Marix_Product = {\n");
    for(int i = 0; i < Four; i++)
    {
        for(int j = 0; j < Four; j++)
        {
            printf("%4d", Matrix_Product[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
    
    return 0;
}