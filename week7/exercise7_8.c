/* 
    输入一个实数，使用sizeof运算符显示三种浮点型的长度
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("float\t\t类型的长度是 %u bytes\n", sizeof(float));
    printf("double\t\t类型的长度是 %u bytes\n", sizeof(double));
    printf("long double\t类型的长度是 %u bytes\n", sizeof(long double));

    return 0;
}