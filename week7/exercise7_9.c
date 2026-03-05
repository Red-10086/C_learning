/* 
    创建一个程序，输入一个实数作为面积，求面积为该实数的正方形的边长
    思路：读一个正数s输入，sqrt(s)函数求其平方根，打印输出
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double s = 0.0;
    do{
        printf("请输入正方形面积:");
        scanf("%lf", &s);
        if(s <= 0.0)
        {
            printf("面积不能为0或负数,请重新输入.\n");
        }
    }while(s <= 0.0);

    printf("正方形边长为:%lf", sqrt(s));

    return 0;
}