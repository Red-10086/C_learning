/* 
练习7-4:
    编写set函数，返回将无符号整数x的第pos位设为1后的值
    unsigned set(unsigned x, int pos){codes}
    编写reset函数，返回将无符号整数x的第pos位设为0后的值
    unsigned reset(unsigned x, int pos){codes}
    编写inverse函数，返回将无符号整数x的第pos位取反后的值
    unsigned inverse(unsigned x, int pos){codes}
*/

#include <stdio.h>

unsigned set(unsigned x, int pos);/* pos位写1 */
unsigned reset(unsigned x, int pos);/* pos位写0 */
unsigned inverse(unsigned x, int pos);/* pos位取反 */
unsigned mask_OR(int pos);/* 返回掩码，函数外将掩码按位或 | ,可以给特定位写1 */
unsigned mask_AND(int pos);/* 返回掩码，函数外将掩码按位与 & ,可以给特定位写0 */
unsigned mask_XOR(int pos);/* 返回掩码，函数外将掩码按位异或 ^ ,可以反转特定位 */
void print_bits(unsigned x);/* 打印二进制数 */

int main(void)
{
    unsigned number = 0;/* 测试数 */
    unsigned count = 0;/* 要修改的位数 */
    
    /* 提示输入 */
    printf("请输入一个非负整数:\n");
    scanf("%u", &number);
    printf("例如:数字 5 的二进制是 101,最低位(第1位)是1,第2位是0,第3位是1.\n");
    printf("请输入您想修改的位数(1~32):\n");
    scanf("%u", &count);
    
    /* 输出对应值 */
    printf("以下依次是:%u、第%u位写1、第%u位写0、反转第%u位 的二进制形式\n", number, count, count, count);
    print_bits(number);                     putchar('\n');
    print_bits(set(number, count));         putchar('\n');
    print_bits(reset(number, count));       putchar('\n');
    print_bits(inverse(number, count));     putchar('\n');
    
    return 0;
}

unsigned set(unsigned x, int pos)/* pos位写1 */
{
    return x | mask_OR(pos);/* 用或写1 */
}

unsigned reset(unsigned x, int pos)/* pos位写0 */
{
    return x & mask_AND(pos);/* 用与写0 */
}
unsigned inverse(unsigned x, int pos)/* pos位取反 */
{
    return x ^ mask_XOR(pos);
}

unsigned mask_OR(int pos)/* 返回掩码，函数外将掩码按位或 | ,可以给特定位写1 */
{
    unsigned a = 1U;/* 比如要获得第3(pos)位为1的掩码0100,应将0001左移3-1位*/
    a = a << (pos-1);
    
    return a;
}

unsigned mask_AND(int pos)/* 返回掩码，函数外将掩码按位与 & ,可以给特定位写0 */
{
    unsigned a = 1U;
    a = a << (pos-1);/* 比如要获得第3(pos)位为1的掩码0100,应将0001左移3-1位*/
    a = ~a;/* 获得一个除自低向高第 pos 位外,其余全1的掩码 */
    
    return a;
}

unsigned mask_XOR(int pos)/* 返回掩码，函数外将掩码按位异或 ^ ,可以反转特定位 */
{
    unsigned a = 1U;
    a = a << (pos-1);/* 比如要获得第3(pos)位为1的掩码0100,应将0001左移3-1位*/
    
    return a;
}


void print_bits(unsigned x)/* 输入无符号整数x,函数打印其二进制形式 */
{
    int i;
    
    // 自高位起,从左向右逐位输出二进制数.
    // sizeof(unsigned)可以替换为int_bits() 
    for (i = 8 * sizeof(unsigned) - 1; i >= 0; i--)/*8:byte to bit*/
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