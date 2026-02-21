/* 
编写set函数，返回将无符号整数x的第pos位设为1后的值
    unsigned set(unsigned x, int pos){codes}
    编写reset函数，返回将无符号整数x的第pos位设为0后的值
    unsigned reset(unsigned x, int pos){codes}
    编写inverse函数，返回将无符号整数x的第pos位取反后的值
    unsigned invers(unsigned x, int pos){codes}
*/

#include <stdio.h>

#define byte_to_bit 8

unsigned set(unsigned x, int pos);/* pos位写1 */
unsigned reset(unsigned x, int pos);/* pos位写0 */
unsigned invers(unsigned x, int pos);/* pos位取反 */
void print_bits(unsigned x);/* 打印二进制数 */

int main(void)
{
    unsigned number = 0;/* 测试数 */
    unsigned count = 0;/* 要修改的位数 */

    printf("请输入一个非负整数:");
    scanf("%u", &number);
    printf("请输入要修改的位数:");
    scanf("%u", &count);

    print_bits(set(number, count)); putchar('\n');
    print_bits(reset(number, count)); putchar('\n');
    print_bits(inverse(number, count)); putchar('\n');

    return 0;
}

void print_bits(unsigned x)
{
    int i;

    // 自高位起,从左向右逐位输出二进制数.
    // sizeof(unsigned)可以替换为int_bits() 
	for (i = byte_to_bit * sizeof(unsigned) - 1; i >= 0; i--)
    {
        //后缀U表示无符号整数,0U表示无符号整数0,1U表示无符号整数1.
        putchar(((x >> i) & 1U) ? '1' : '0');

        //每8位空一格，最后一位不空
        if((i % 8 == 0) && (i != 0))
        {
            putchar(' ');
        }
    }
}
