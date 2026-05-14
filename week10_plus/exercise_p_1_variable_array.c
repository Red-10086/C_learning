/* 
习题8-10 输出学生成绩
本题要求编写程序，根据输入学生的成绩，统计并输出学生的平均成绩、最高成绩和最低成绩。建议使用动态内存分配来实现。

输入格式：
输入第一行首先给出一个正整数N，表示学生的个数。接下来一行给出N个学生的成绩，数字间以空格分隔。

输出格式：
按照以下格式输出：

average = 平均成绩
max = 最高成绩
min = 最低成绩
结果均保留两位小数。

输入样例：
3
85 90 95
输出样例：
average = 90.00
max = 95.00
min = 85.00
*/

#include <stdio.h>
#include <stdlib.h>

double average(int *arr, int n);
double max(int *arr, int n);
double min(int *arr, int n);

int main(void)
{
    // 读学生个数
    int N;
    if(scanf("%d", &N) == 0)
    {
        printf("error\n");
        scanf("%d", &N);
    }

    // 开辟N个int大小的内存空间
    int *a = NULL;
    a = (int *)malloc(N * sizeof(int));

    // 若开辟失败,即刻退出
    if(a == NULL)
    {
        return 1;
    }

    // 若成功,逐个录入学生成绩
    for(int i = 0; i < N; i++)
    {
        if( scanf("%d", &a[i]) == 0)
        {
            printf("error\n");
            scanf("%d", &N);
        }
    }

    printf("average = %lf\n", average(a, N));
    printf("max = %lf\n", max(a, N));
    printf("min = %lf\n", min(a, N));

    free(a);

    return 0;
}

double average(int *arr, int n)
{
    int sum = 0;
    double ave = 0.0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    ave = (double)sum / n;

    return ave;
}

double max(int *arr, int n)
{
    double maxi = arr[0];

    for(int i = 0; i < n; i++)
    {
        // 有更大的,就取更大的值
        if( maxi < arr[i] )
        {
            maxi = arr[i];
        }
    }

    return maxi;
}

double min(int *arr, int n)
{
    double mini = arr[0];
    
    for(int i = 0; i < n; i++)
    {
        // 有更小的,就取更小的值
        if( mini > arr[i] )
        {
            mini = arr[i];
        }
    }

    return mini;
}