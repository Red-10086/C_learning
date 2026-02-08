/* 输入一个整数，连续品示出该整数个*（使用for语句） */
#include <stdio.h>
int main(void)
{   
    int i,no;
    printf("正整数:");
    scanf("%d", &no);
    for(i = 1; i<= no; i++)
        putchar('*');
    putchar("n");
    return 0;
}

// /* 显示出一个直角在左下方的等腰直角三角形 */
// #include <stdio.h>
// /*连续显示出n个*/
// void put_stars(int n)
// {
//     /* 递减的控制表达式和代码清单6一6一样。 */
//     /* 我的吐槽：下面的这玩意在纸质书上看不出空格，像是n-->0，
//     搞得像C++一样，尖括号到处飞 */
//     while (n-- > 0)
//         putchar('*');
// }

// int main (void)
// {

//     int i, len;

//     printf("生成一个直角在左下方的等腰直角三角形。\n");
//         printf("短边:");
//         scanf("%d", &len);
//         for(i = 1; i <= len; i++)
//         {
//             put_stars(i);
//             putchar('\n');
//         }
//     return 0;
// }