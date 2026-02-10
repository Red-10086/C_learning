#include <stdio.h>

#define Number 10

int arr[Number] = {69,  80,   -79,   95,   -72,   -97,   -21,   44,   57,   10};

void rev_intary(int v[], int n);/* 倒序排列函数 */

int main(void)
{
    printf("有一个数组:{");
    for(int i = 0; i < Number; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("}\n");

    rev_intary(arr, Number);

    printf("它被倒序排列后:{");
    for(int i = 0; i < Number; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("}\n");

    return 0;
}

void rev_intary(int v[], int n)
{
/*可以这样做，但是不好，多创造了一个数组，浪费了一倍的内存空间*/
/*     int rev[n];

    for(int i = 0; i < n; i++)
    {
        rev[i] = v[i];
    }

    for(int i = 0; i < n; i++)
    {
        v[i] = rev[n-1-i];
    } */
    int temp = 0;
    // 原地交换，不需要额外数组
    /* for(int i = 0; i < n; i++) */
    //注释中的是错误例子，逻辑错误：数组原地首尾交换了两次，又回到了原来的数组
    for(int i = 0; i < n/2; i++)/* 就像一条打孔纸带，在正中间对折，重合的孔交换位置
    那么只遍历到折痕左侧就能恰好遍历完一半的纸带，交换所有的孔 */
    {
        temp = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = temp;
    }
}