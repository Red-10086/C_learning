#include <stdio.h>

#define Number 10

int arr[Number] = {69,  80,   -79,   95,   -72,   -97,   -21,   44,   57,   10};

int min_of(const int v[], int n);

int main(void)
{
    printf("数组arr中的最小值是:%d", min_of(arr, Number));

    return 0;
}

//最小值函数，可以返回数组前n个元素中的最小值
int min_of(const int v[], int n)
{
    int Minimum = v[0];

    for(int i = 1; i < n; i++)
    {
        if(v[i] < Minimum)
        {
            Minimum = v[i];
        }
    }

    return Minimum;
}