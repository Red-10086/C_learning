#include <stdio.h>

int sumup(int x);

int main(void)
{
    int n = 0;
    printf("请输入一个正整数n，我们将输出1到n之间所有的整数的和\n");
    scanf("%d", &n);

    printf("1到%d之间所有的整数和是:%d", n, sumup(n));

    return 0;
}

int sumup(int x)
{
    double temp = 0.0;
    while(x > 0){
        temp += x;
        x--;
    }
    return temp;
}