#include <stdio.h>

enum{Two = 2, Six = 6};

int main(void)
{
    //分数库
    int Scores[Six][Two] = {{0}};

    for(int i = 0; i < Six; i++)
    {
        printf("请输入同学 %d 的语文分数:", i+1);
        scanf("%d", &Scores[i][0]);//下标从0开始数！
        printf("请输入同学 %d 的数学分数:", i+1);
        scanf("%d", &Scores[i][1]);
    }

    for(int i = 0; i < Six; i++)
    {
        
    }

    return 0;
}