#include <stdio.h>
#include "my_struct_sort.h"
#include <string.h>

void swap_junior(senior *x, senior* y);

// 交换两个结构体的所有成员(值)
void swap_junior(senior *x, senior* y)
{
    senior tmp = *x;
    *x = *y;
    *y = tmp;
}