/*
编写set_n函数，返回将无符号整数x的第pos位到第pos+n-1位的pos位起n位设为1后的值。
    unsigned set_n(unsigned x, int pos, int n){codes}

编写reset_n函数，返回将无符号整数x的第pos位开始的pos位起n位设为0后的值.
    unsigned reset_n(unsigned x, int pos, int n){codes}

编写inverse_n函数，返回将无符号整数x的第pos位开始的pos位起n位取反后的值.
    unsigned inverse_n(unsigned x, int pos, int n){codes}
*/

/* 
pos位起n位设1 等价于(或者说是后一个问题的子问题) 获取一个目标掩码,然后用按位或运算写1
例子：低位起1-4位设1
掩码:…… 0000 0000 1111U
思路1(通解1):无符号整数,比特位有权重,给了位数信息即可用ΣB_i所得整数作为掩码
思路2(通解2):已经掌握了生成单个位取1掩码的方法:unsigned mask = 1U << pos-1获得pos位为1的掩码
按照要求得到目标掩码,将目标掩码拆解成一些 单个位取1的掩码,生成这些小掩码,然后用按位或计算出目标掩码
思路3(高效特解):如果要获得低位起连续3位为1的掩码,可以利用减法的特性:0b1000-0b0001 = 0b0111,
将b0111左移pos-1位,即可得从pos位起,3位都设为1的掩码
*/
#include <stdio.h>

void print_bits(unsigned x);/* 打印二进制数 */
unsigned mask_OR(int pos, int n);/* 返回一个掩码，函数外用或运算写1 */
unsigned mask_AND(int pos, int n);/* 返回一个掩码，函数外用与运算写0 */
unsigned mask_XOR(int pos, int n);/* 返回一个掩码，函数外用异或运算反转 */
unsigned set_n(unsigned x, int pos, int n);/* 用掩码给特定位写1 */
unsigned reset_n(unsigned x, int pos, int n);/* 用掩码给特定位写0 */
unsigned inverse_n(unsigned x, int pos, int n);/* 用掩码反转特定位 */

int main(void)
{
    print_bits(set_n(0b010101010101, 5, 4));        putchar('\n');
    print_bits(reset_n(0b010101010101, 5, 4));      putchar('\n');
    print_bits(inverse_n(0b010101010101, 5, 4));    putchar('\n');
    return 0;
}


unsigned mask_OR(int pos, int n)/* 返回一个掩码，函数外用或运算写1 */
{
    unsigned a = 1U;
    a = a << n;
    a = a - 1U;/* 获得一个"低n位掩码" */
    a = a << pos-1;/* 将掩码移到有效位置 */
    
    return a;
}

unsigned set_n(unsigned x, int pos, int n)/* 用掩码给特定位写1 */
{
    return x | mask_OR(pos, n);
}


unsigned mask_AND(int pos,int n)/* 返回一个掩码，函数外用与运算写0 */
{
    unsigned a = 1U;/* 0000 0001 */
    a = a << n;/* 0010 0000 */
    a = a - 1U;/* 获得一个"低n位全1掩码" 0001 1111*/

    // a = ~a;/* 1110 0000 问题:左移unsigned int会补0,解决:先移位再反转 */
    // a = a << pos-1;

    a = a << pos-1;
    a = ~a;

    return a;
}

unsigned reset_n(unsigned x, int pos, int n)/* 用掩码给特定位写0 */
{
    return x & mask_AND(pos, n);
}

unsigned mask_XOR(int pos, int n)/* 返回一个掩码，函数外用异或运算反转 */
{
    unsigned a = 1U;
    a = a << n;/* 例 0100 0000 */
    a = a - 1;/* 例 0011 1111 */
    a = a << pos-1;/* 例 0111 1110 */

    return a;
}

unsigned inverse_n(unsigned x, int pos, int n)/* 用掩码反转特定位 */
{
    return x ^ mask_XOR(pos, n);
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