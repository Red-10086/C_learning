#include <stdio.h>
#include "my_struct_sort.h"
#include <string.h>

void swap_junior(junior *x, junior* y);

// 交换两个结构体的所有成员(值)
void swap_junior(junior *x, junior* y)
{
    junior tmp = *x;
    *x = *y;
    *y = tmp;
}