#include <stdio.h>

#define Three 3
#define Four 4

void Mat_print(int a, int b, int m[a][b]);
void Mat_Mult(const int u[Four][Three], const int v[Three][Four], int w[Four][Four]);

int main(void)
{
    //初始化
    int Matrix_A[Four][Three] = 
    {
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}, 
        {0, 0, 0}
    };
    int Matrix_B[Three][Four] = 
    {
        {1, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 0, 1, 0}
    };
    int Matrix_Product[Four][Four] = {{0}};
    
    //矩阵相乘
    Mat_Mult(Matrix_A, Matrix_B, Matrix_Product);
    
    //打印矩阵
    printf("Matrix_A = \n");
    Mat_print(Four, Three, Matrix_A);
    printf("Matrix_B = \n");
    Mat_print(Three, Four, Matrix_B);
    printf("Matrix_Product = \n");
    Mat_print(Four, Four, Matrix_Product);
    
    return 0;
}

void Mat_print(int a, int b, int m[a][b])
{
    printf("{\n");
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
    printf("}\n");
}
void Mat_Mult(const int u[Four][Three], const int v[Three][Four], int w[Four][Four])
{
    for(int i = 0; i < Four; i++)
    {
        for(int j = 0; j < Four; j++)
        {
            for(int k = 0; k <Three; k++)
            {
                w[i][j] += (u[i][k] * v[k][j]);
            }
        }
    }
}