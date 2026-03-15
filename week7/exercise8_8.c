/* 
    练习8-8 创建一个函数,使用辗转相除法求两个整数值 x 和 y 的最大公约数
        int gcd(int x, int y){codes}
    算法:
        1取出x\y中较大的那一个(假设是x)
        2以较大的x为被除数,较小的y为除数,求余数和商
        3当余数为0,则最大公因数等于当前除数的值
        4当余数不为0,则以原除数为被除数,余数为除数继续相除
        核心:
        能整除 gcd(a, b) == b
        不能整除 gcd(a, b) == gcd(b, a mod b)

    错误:辗转相除到最后是除数为最大公约数, ——不是商—— ！
*/

#include <stdio.h>

enum gcd_err { gcd_err = -1 };
enum gcd_paramenters { one = 1066, other = 1453};

int gcd(int x, int y);

int main(void)
{
    int result = gcd(one, other);
    printf("%d和%d的最大公约数是:%d", one, other, result);

    return 0;
}

int gcd(int x, int y)
{
    int tmp = 0;/* 交换中介 */
    int quotient = 0;/* 商 */
    int remainder = 0;/* 余数 */
    int greatest_common_divisor = 0;/* 最大公约数 */

    /* 确保大数在前---做被除数 */
    if(x < y)
    {
        tmp = x;
        x = y;
        y = tmp;
    }

    if(y)/* 确保除数非零,然后求商取余 */
    {
        quotient = x / y;
        remainder = x % y;
    }

    if(remainder == 0)
    {
        greatest_common_divisor = y;/* 曾犯错:g_c_d = quotient */
    }
    else
    {
        /* 尾递归, gcd(x, y) == gcd(y , x % y) */
        greatest_common_divisor = gcd(y, remainder);
    }

    return greatest_common_divisor;
}