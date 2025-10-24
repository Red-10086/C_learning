#include <stdio.h>

int main()
{
    //变量初始化
    int number = 0;
    int sum = 0;
    int n = 0;

    //读输入并计数
    printf("请输入数字以求平均数，输入-1表示结束：");
    do{
        scanf("%d", &number);
        if(number!=-1)
        {
            sum += number;
            n++;
        }
    }while(number != -1);
    //计算平均数并输出
    if(n!=0)
    {
        printf("%lf", 1.0*sum/n);
    }
    else
    {
        printf("没有合法输入，无平均数。");
    }

    return 0;
}


// #include <stdio.h>

// int main()
// {
//     //变量初始化
//     int number = 0;
//     int sum = 0;
//     int n = 0;

//     // 读取第一个输入
//     printf("请输入数字以求平均数，输入-1表示结束：");
//     scanf("%d", &number);
//     // 基于第一个输入决定是否进入循环
//     while (number != -1) 
//     {
//     // 处理当前输入
//     sum += number;
//     n++;
//     // 读取下一个输入，为下一轮循环做准备
//     scanf("%d", &number);
//     }

//     //计算平均数并输出
//     if(n!=0)
//     {
//         printf("%lf", 1.0*sum/n);
//     }
//     else
//     {
//         printf("没有合法输入，无平均数。");
//     }

//     return 0;
// }