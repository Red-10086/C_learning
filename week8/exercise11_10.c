/*
    练习11-10 编写如下函数,实现与库函数atoi\atol\atof相同的功能.
        int strtoi(const char *nptr){codes}
        long strtoL(const char *nptr){codes}
        double strtod(const char *nptr){codes}
    
    思路:
        1先实现:只兼容无符号十进制的形式

        对于int和long
        先量字符串长度strlen,确定是几位数,

        逐位将char字符转为
        对应的int数字(如char '0'转化为 int 0),
        再赋予位序,比如输入"1234",那么,返回:
            1*10e3 + 2*10e2 + 3*10e1 +4*10e0
        
        反正用atoi/atoL处理不能用int/long范围表示的数是未定义行为,
        不管上下限.
        
        对于double,也类似,只是需要先确定小数点'.'
        然后以小数点为界,
        逐位将char字符转为对应的double数字(如char '0'转化为 int 0.0),
        例如输入:"12.56",返回:
            1.0*10e1 + 2.0*10e0 + 4.0*10e-1 +6.0*10e-2

        1.5另外,有条错误的路:
            不管小数点,先当做int逐位乘10的幂,再根据小数点位置整体除一个10的幂.
            这在数学上可行,但是上下界完全被int或者long之类的锁死了,和double
            上下界显然不同,与库函数atof:"结果值不能用double表示时未定义"
            不符:可能存在能用double表示的确没法用这种方式处理(超出int范围),
            或者double表示不了(某些long long int)的却用这种方式处理-浪费.
        
        2然后处理符号:在外部加首位符号检查和整体符号检查(检查是否只有+或-或.)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int strtoi(const char *nptr);
long strtoL(const char *nptr);
double strtof(const char *nptr);


int main(void)
{
    char str[128];
    scanf(" %s", str);
    printf("%d", strtoi(str));

    return 0;
}

int str_to_unsigned(const char *nptr)
{
    int Number = 0;                 // 字符串对应整数
    int len = strlen(nptr);         // 不含符号位的string length

    for(int i = 0; i < len ; i++)
    {
        /* 数位从左至右:i从0到len-1,位权重从高到低:10的len-1次方到0次方 */
        /* 特别地,如果这个字符串表示的数没有超过整数范围,那么它每一数位
        的权重:pow(10.0,len-i-1)也不会,int转换不会导致越界 */
        Number = Number + (*(nptr+i) - '0') * (int)pow(10.0, len-i-1);
    }

    return Number;
}



long strtoL(const char *nptr);
double strtof(const char *nptr);