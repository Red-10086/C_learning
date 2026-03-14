/*
	不依赖编译器，格式化输出二进制数
*/

#include <stdio.h>

/*--- 输出无符号整数的二进制格式 ---*/
void print_bits(unsigned x)
{
    int i;

    //自高位起,从左向右逐位输出二进制数.
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
    putchar('\n');
}

int main(void)
{
	unsigned a;

	printf("请输入非负整数。\n");
	printf("a : ");   scanf("%u", &a);

    printf("\na = ");   print_bits(a);

	return 0;
}
// /*--- 返回无符号整数x中设置的位数(包括先导0) ---*/
// int count_bits(unsigned x)
// {
// 	int bits = 0;
// 	while (x) {
// 		if (x & 1U) bits++;
// 		x >>= 1;
// 	}
// 	return bits;
// }

// /*--- 返回本编译器中unsigned型的位数 ---*/
// int int_bits(void)
// {
// 	return count_bits(~0U);
// }