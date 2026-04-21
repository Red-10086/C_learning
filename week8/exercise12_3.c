/* 
    练习12-3 编写如下函数,从键盘输入int型,long型,和double型的值,
    将这些值作为结构体xyz的成员,返回该结构体的值.
*/

#include <stdio.h>

struct xyz
{
    int x;
    long y;
    double z;
};

struct xyz scan_xyz(void);

int main(void)
{
    struct xyz someone;
    someone = scan_xyz();
    printf("someone.x == %d\n", someone.x);
    printf("someone.y == %ld\n", someone.y);
    printf("someone.z == %lf\n", someone.z);

    return 0;
}

struct xyz scan_xyz(void)
{
    struct xyz s;
    printf("请输入整数x:\n");   scanf("%d", &s.x);
    printf("请输入整数y:\n");   scanf("%ld", &s.y);
    printf("请输入小数z:\n");   scanf("%lf", &s.z);

    return s;
}