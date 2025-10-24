#include <stdio.h>
#include <gsl/gsl_sf.h>
#include <gsl/gsl_sf_bessel.h>

int main()
{
    //变量初始化
    int a = 0;
    int n = 0;
    const int TEN = 10;/*用来决定for循环次数的常数*/
    int N = 0;/*输入数字的个数*/
    int OddNumbers_Input = 0;/*输入奇数个数*/
    int OddNumbers_Ouput = 0;/*不重复的奇数组合个数*/

    //数组初始化
    int Numbers [10];
    for(int j=0;j<TEN;j++)
    {
        Numbers[j] = 0;
    }

    //用户决定需要输入多少数字
    printf("你想输入多少个0到9之间的整数，输入你的答案：");
    scanf("%d", &N);
    
    //用户输入N个数字,统计每个数字被输入了多少次
    printf("请输入 %d 个数字：", N);
    for(int i=0;i<N;i++)
    {
        int a = 0;
        scanf("%d", &a);
        if(a<=9 && a>=0)
        {
            Numbers[a]++;
        }
    }

    //统计输入了多少个奇数
    for(int i=1;i<TEN;i+=2)
    {
        OddNumbers_Input += Numbers[i];
    }

    //算出这N个数字在N个数位上任意排列可能有多少种不同的结果：


    return 0;
}