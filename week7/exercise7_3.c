/* 
编写rrotate函数，返回无符号整数x右移n位后的值
unsigned rrotate(unsigned x, int n){codes}
编写lrotate函数，返回无符号整数x左移n位后的值
unsigned lrotate(unsigned x, int n){codes}
 */
#include <stdio.h>
#include <limits.h>

#define byte_to_bit 8

//返回无符号整数x右移n位后的值
unsigned rrotate(unsigned x, int n);

//返回无符号整数x左移n位后的值
unsigned lrotate(unsigned x, int n);

//将无符号整数x按二进制输出
void print_bits(unsigned x);

int main(void)
{
    //定义 初始化
    unsigned number = 0;/* 非负整数 */
    unsigned counts = 0;/* 位移位数 */
    unsigned out = 0;/* 循环条件变量 */
    
    //读输入
    do{
        printf("请输入一个非负整数:");
        scanf("%u", &number);
        printf("请输入位移的位数:");
        scanf("%u", &counts);
        
        //输入检测
        if(number > 0)
        {
            //如果左移会高位溢出或counts大于unsigned包含的位数
            if((number > (UINT_MAX >> counts)) || (counts >= byte_to_bit * sizeof(unsigned)))
            {
                printf("溢出,请重试.\n");
                continue;
            }
        }

        //输出位移后的值
        printf("%u的二进制形式:\n");
        print_bits(number);    putchar('\n');
        
        printf("%u右移%u位后的值(二进制):\n", number, counts);
        print_bits(rrotate(number, counts));    putchar('\n');
        
        printf("%u左移%u位后的值(二进制):\n", number, counts);
        print_bits(lrotate(number, counts));    putchar('\n');

        //正常执行完
        out = 1;
    }while(out == 0);

    return 0;
}

unsigned rrotate(unsigned x, int n)
{
    unsigned r_number = 0;
    r_number = x >> n;

    return r_number;
}

unsigned lrotate(unsigned x, int n)
{
    unsigned r_number = 0;
    r_number = x << n;

    return r_number;
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