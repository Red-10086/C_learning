#include <stdio.h>

int main()
{
    int hours1, minutes1;
    int hours2, minutes2;
    int delta_T;

    //读输入
    printf("请输入第一个时间点（几时几分）：");
    scanf("%d %d", &hours1, &minutes1);
    printf("请输入第二个时间点（几时几分）：");
    scanf("%d %d", &hours2, &minutes2);

    //计算时间差
    delta_T = hours2 * 60 + minutes2 - hours1 * 60 - minutes1;

    //打印输出
    printf("相差 %d 时 %d 分", delta_T / 60, delta_T % 60);

    return 0;
}