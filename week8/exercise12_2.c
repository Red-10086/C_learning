/* 
    练习12-2 代码清单12-5中,结构体对象sanaka的各成员的值都有初始值(定义时
    即初始化).该写这个程序,声明时不为其赋初始值,并且各成员的值从键盘输入.
*/

#include <stdio.h>

typedef struct student 
{
    char name[64];
    int height;
    float weight;
    long schols;
} Junior;

int main(void)
{
    Junior sanaka;

    /* sanaka.height等是算数类型对象而非指针,必须要给scanf传指针:&对象 */
    printf("请输入sanaka的名字:\n");        scanf("%s", sanaka.name);
    printf("请输入sanaka的身高(cm):\n");    scanf("%d", &sanaka.height);
    printf("请输入sanaka的体重(kg):\n");    scanf("%f", &sanaka.weight);
    printf("请输入sanaka的奖学金数额:\n");  scanf("%ld", &sanaka.schols);
    
    printf("sanaka的名字是 \"%s\" \n", sanaka.name);
    printf("sanaka的身高是%dcm\n", sanaka.height);
    printf("sanaka的体重是%.2fkg\n", sanaka.weight);
    printf("sanaka的奖学金数额是%ld元\n", sanaka.schols);

    return 0;
}