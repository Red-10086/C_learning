#include <stdio.h>
int main()
{
    int ant;
    int boy;

    printf("请输入两个整数：");
    scanf("%d, %d", &ant, &boy);

    printf("%d + %d = %d\n", ant, boy, ant + boy);

    return 0;
}