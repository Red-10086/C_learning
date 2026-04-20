/* 
    练习12-1 在代码清单12-3的基础上,编写显示对象takao各成员地址的程序.
    在此不列出具体代码,只概述12-3内容:
    12-3中声明了struct student类型:
    struct student {
        char name[64];
        int height;
        float weight;
        long schols;
    };
    声明 struct student类 的 对象takao
    初始化了各成员,打印了各成员.
*/

#include <stdio.h>

enum {Name_length = 64};

struct student
{
    char name[Name_length];
    int height;
    float weight;
    long schols;
};

int main(void)
{
    // 结构体需要初始化(对成员逐一赋值 或者 定义初始化)
    // 初始化后,未提及的成员,值自动为0
    struct student takao = { "Takao", 173, 87.3 };

    
    printf("%s\n", (takao.name));
    printf("%d\n", (takao.height));
    printf("%f\n", (takao.weight));
    printf("%ld\n", (takao.schols));
    printf("%p\n", &(takao.name));
    printf("%p\n", &(takao.height));
    printf("%p\n", &(takao.weight));
    printf("%p\n", &(takao.schols));
    printf("%zu\n", sizeof(takao.name));
    printf("%zu\n", sizeof(takao.height));
    printf("%zu\n", sizeof(takao.weight));
    printf("%zu\n", sizeof(takao.schols));

    return 0;
}