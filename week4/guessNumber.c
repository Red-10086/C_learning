#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //生成一个1-100间的机数
    srand(time(0));
    int number = rand() % 100 + 1;
    int N = 0;
    int a = 0;

    //打印提示性内容，循环。
    printf("现在有一个1-100间的随机整数，你来猜猜看是几\n");
    printf("你猜的数字是：");
    do{
        scanf("%d", &N);//输入口
        a++;
        if(N > number)//判断
        {
            printf("猜的偏大，请再猜：");
        }
        else if(N < number)
        {
            printf("猜的偏小，请再猜：");
        }
    }while(N != number);
    printf("猜对了，你总共猜了%d次", a);

    return 0;
} 