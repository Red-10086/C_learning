/*
	显示数组元素的值和地址
*/

#include <stdio.h>
#include <stddef.h>

#define TYPE_NAME(x) _Generic((x), \
    int *: "int* 指针", \
    double *: "double* 指针", \
    char *: "char* 指针", \
    int: "int 标量", \
    unsigned: "unsigned 标量", \
    double: "double 标量", \
    char: "char 标量", \
    long long: "有符号 long long", \
    default: "其他类型" \
)

int main(void)
{
	int i;
	int a[5] = {1, 2, 3, 4, 5};
	int *p = a;				/* p指向a[0] */

    printf("a 的类型是：%s\n", TYPE_NAME(a));
    printf("p 的类型是：%s\n", TYPE_NAME(p));
    printf("a+1 的类型是：%s\n", TYPE_NAME(a+1));
    printf("p+1 的类型是：%s\n", TYPE_NAME(p+1));
    printf("(p+2)-(a+1) 的类型是：%s\n", TYPE_NAME((p+2)-(a+1)));
    printf("(p+3)-(a+4) 的类型是：%s\n", TYPE_NAME((p+3)-(a+4)));

	return 0;
}
