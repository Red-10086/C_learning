/* 
练习7-6
    编写程序确认对无符号整数执行算术运算不会发生数据溢出
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define byte_to_bit 8

int main(void)
{
    unsigned x = 4294967294;
    unsigned y = 4;
    unsigned sum = 0;

    sum = x + y;

    // 打印无符号整数能表示的最大值:pow(2,32) - 1 = 4294967295 = 0xFFFFFFFF
    printf("%10u\n", UINT_MAX);
    
    printf("%10u\n", x);
    printf("%10u\n", y);
    printf("%10u\n", sum);

    return 0;
}