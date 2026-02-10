#include <stdio.h>

#define Number 10

int arr[Number] = {69, 80, -79, 95, -72, -97, -21, 44, 57, 10};
int rev[Number] = {0};

void intary_rcpy(int v1[], const int v2[], int n);/* 倒序排列函数 */

int main(void)
{
    printf("有一个数组arr[]:\n{");
    for(int i = 0; i < Number; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("}\n");

    intary_rcpy(rev, arr, Number);

    printf("将它倒序保存到另一个数组rev[]中:\n{");
    for(int i = 0; i < Number; i++)
    {
        printf("%d\t", rev[i]);
    }
    printf("}\n");

    return 0;
}

void intary_rcpy(int v1[], const int v2[], int n)
{
    //这样传入数组，可以在函数内直接改变原数组的值，这是指针的内容，在指针章节会讲
    for(int i = 0; i < n; i++)
    {
        v1[n-1-i] = v2[i];
    }
}