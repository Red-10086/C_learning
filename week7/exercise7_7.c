/* 
    创建一个程序，从键盘输入float、double、long double型变量，并显示其值。
    注意试着输入各种各样的值，并验证其动作。
*/
#include <stdio.h>

int main(void)
{
    float a = 0.0;
    double b = 0.0;
    long double c = 0.0;

    scanf("%f", &a);
    scanf("%lf", &b);
    scanf("%Lf", &c);

    printf("%f\n", a);
    printf("%lf\n", b);
    printf("%Lf\n", c);

    return 0;
}