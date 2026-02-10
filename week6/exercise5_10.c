#include <stdio.h>

#define Three 3
#define Four 4

int main(void)
{
    
    int Matrix_A[Four][Three] = {{0}};

    int Matrix_B[Three][Four] = {{0}};

    int Matrix_Product[Four][Four] = {{0}};

    //输入A的元素
    for(int i = 0; i < Four; i++)
    {
        for(int j = 0; j < Three; j++)
        {
            printf("请输入Matrix_A %d行 %d列的元素: ", i+1, j+1);
            scanf("%d", &Matrix_A[i][j]);
        }
    }

    //输入B的元素
    for(int i = 0; i < Three; i++)
    {
        for(int j = 0; j < Four; j++)
        {
            printf("请输入Matrix_B %d行 %d列的元素: ", i+1, j+1);
            scanf("%d", &Matrix_B[i][j]);
        }
    }

    //矩阵乘法
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

    //打印矩阵A
    printf("Marix_A = {\n");
    for(int i = 0; i < Four; i++)
    {
        for(int j = 0; j < Three; j++)
        {
            printf("%4d", Matrix_A[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
    
    //打印矩阵B
    printf("Marix_B = {\n");
    for(int i = 0; i < Three; i++)
    {
        for(int j = 0; j < Four; j++)
        {
            printf("%4d", Matrix_B[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
    
    //打印矩阵乘积
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