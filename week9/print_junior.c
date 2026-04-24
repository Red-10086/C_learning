#include <stdio.h>
#include <string.h>
#include "my_struct_sort.h"

void print_junior(junior *arr, int i);

void print_junior(junior *arr, int i)
{
    printf("第%d个同学的名字:%-10s\t", i+1, arr[i].name);
    printf("第%d个同学的身高(cm):%4d\t", i+1, arr[i].height);
    printf("第%d个同学的体重(kg):%4.2f\t", i+1, arr[i].weight);
    printf("第%d个同学的奖学金数额:%8ld\n", i+1, arr[i].schols);
}