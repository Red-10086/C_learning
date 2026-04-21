#include <stdio.h>
#include "my_struct_sort.h"

void swap_Junior(Junior *x, Junior* y);

// 交换两个结构体的所有成员(值)
void swap_Junior(Junior *x, Junior* y)
{
    Junior tmp = *x;
    *x = *y;
    *y = tmp;
}