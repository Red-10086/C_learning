/* 
题目一：动态数组扩容（考 malloc + realloc）
编写程序，先读取正整数 N，然后读取 N 个整数存入动态数组。接着读取正整数 M，
再读取 M 个整数，追加到原数组末尾（总长度变为 N+M）。最后输出所有 N+M 个整数。

输入格式:
3
10 20 30
2
40 50

输出格式:
10 20 30 40 50

要求
先用 malloc 或 calloc 分配初始 N 个空间
用 realloc 扩容到 N+M 个空间
必须 free
如果任何一次分配失败，输出 Allocation failed 并返回 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // 指针实现数组
    int *a = NULL;
    // 接收内存开辟函数返回值的临时指针
    int *temp = NULL;
    
    // 要录入N个整数
    int N = 0;
    scanf("%d", &N);

    temp = (int *)malloc(N * sizeof(int));

    // 开辟失败立刻退出
    if(temp == NULL)
    {
        printf("Allocation failed\n");
        free(a);
        return 1;
    }
    // 开辟成功,a指向新内存
    else
    {
        a = temp;
    }

    // 开辟成功,逐个录入
    for(int i = 0 ; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    // 追加M个整数
    int M = 0;
    scanf("%d", &M);

    // 开辟新内存,大小为M+N个sizeof(int)
    temp = (int *)realloc((void *)a , (M + N) * sizeof(int));

    // 开辟失败立刻退出
    if(temp == NULL)
    {
        printf("Allocation failed\n");
        free(a);
        return 1;
    }
    // 开辟成功则将a指向新内存
    else
    {
        a = temp;
    }

    // 从N到M+N-1,在原来N个整数后面追加M个整数
    for(int i = N; i < M+N; i++)
    {
        scanf("%d", &a[i]);
    }

    // 全部输出
    for(int i = 0; i < M+N; i++)
    {
        printf("%d ", a[i]);
    }

    // 释放a,野指针置零
    free(a);
    a = NULL;
    temp = NULL;

    return 0;
}