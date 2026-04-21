#include <stdio.h>
#include "my_struct_sort.h"

void sort_Name(Junior *arr_struct, int n);

// 按 姓名成员的首字母顺序, 为结构体数组内前n个结构体排序(按A-Z的升序)
void sort_Name(Junior *arr_struct, int n)
{
    // 首字母大写检查
    for(int i = 0; i < n; i++)
    {
        if(arr_struct[i].name[first] >= 'a' && arr_struct[i].name[first] <= 'z' )
        {
            arr_struct[i].name[first] += ('A' - 'a');
        }
    }

    // 冒泡排序
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            // 首字母顺序:升序该用前>后作为交换触发条件(逆序-交换)!!!
            // 先前错误写法:if(arr_struct[ j ].name[first] < arr_struct[ j+1 ].name[first] )
            if(arr_struct[ j ].name[first] > arr_struct[ j+1 ].name[first] )
            {
                swap_Junior(&arr_struct[j], &arr_struct[j+1]);
            }
        }
    }
}