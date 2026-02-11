/*
	求4名学生在两次考试中3课程的总分并显示（函数版）
*/

#include <stdio.h>

#define Four 4
#define Three 3
#define Two 2

/*--- 将4行3列矩阵a和b的和存储在c中 ---*/

void Mat_Merge(const int u[Four][Three], const int v[Four][Three], int w[Two][Four][Three])
{
    for(int i = 0; i < Two; i++)
    {
        for(int j = 0; j < Four; j++)
        {
            for(int k = 0; k <Three; k++)
            {
                if(i == 0)
                {
                    w[i][j][k] = u[j][k]; 
                }
                else if(i == 1)
                {
                    w[i][j][k] = v[j][k];
                }
            }
        }
    }
}

/*--- 显示二维矩阵m ---*/
void Mat_print_2(int a, int b, int m[a][b])
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

/*--- 显示三维矩阵m ---*/
void Mat_print_3(int a, int b, int c, int m[a][b][c])
{
    printf("{\n");
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            for(int k = 0; k < c; k++)
            {
                printf("%4d", m[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("}\n");
}

int main(void)
{
	int tensu1[4][3] = { {91, 63, 78}, {67, 72, 46}, {89, 34, 53}, {32, 54, 34} };
	int tensu2[4][3] = { {97, 67, 82}, {73, 43, 46}, {97, 56, 21}, {85, 46, 35} };
	int table[2][4][3] = {{{0}}};			/* 总表 */

	/* 求总表*/
    Mat_Merge(tensu1, tensu2, table);

	puts("第一次考试的分数");  Mat_print_2(Four, Three, tensu1);	/* 显示第一次考试的分数 */
	puts("第二次考试的分数");  Mat_print_2(Four, Three, tensu2);	/* 显示第二次考试的分数 */
	puts("总表");        Mat_print_3(Two, Four, Three, table);		/* 显示总表 */

	return 0;
}
