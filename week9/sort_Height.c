#include <stdio.h>
#include <string.h>
#include "my_struct_sort.h"

void sort_Height(junior *arr_struct, int student_Number);

// 按 身高顺序, 为结构体数组内前n个结构体排序(升序)
void sort_Height(junior *arr_struct, int n)
{
    // 冒泡排序
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            // 首字母顺序:升序该用前>后作为交换触发条件(逆序-交换)!!!
            if(arr_struct[ j ].height > arr_struct[ j+1 ].height )
            {
                swap_junior(&arr_struct[j], &arr_struct[j+1]);
            }
        }
    }
}