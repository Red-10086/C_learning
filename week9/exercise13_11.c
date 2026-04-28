/* 
    练习13-11 编写一个程序,读取含有10个double型元素的数组的所有元素值.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {len = 10};

int main(void)
{
    double arr_1[len] = {0};
    double arr_2[len] = {0};

    // 设定种子(初态)
    srand((int)time(NULL));
    for(int i = 0; i < len; i++)
    {
        // 生成10个随机浮点数
        // 第一次调用是初态(srand设定),后续每次调用都是新的状态-新随机数
        arr_1[i] = (double) rand() / RAND_MAX;
        printf("%23.21lf\n", arr_1[i]);
    }
    puts("以上为要存入文件的浮点数.\n");

    FILE *fp = NULL;
    // 打开文件,存入-只写 二进制格式
    fp = fopen("hellofloat.bin", "wb");
    if(fp == NULL)
    {
        puts("文件打开失败.\n");
    }
    else
    {
        fwrite(arr_1, sizeof(arr_1[0]), len, fp);
        
        // 使用完毕,关闭文件
        fclose(fp);
    }
    fp = NULL;

    // 打开文件,读取-只读 二进制格式
    fp = fopen("hellofloat.bin", "rb");
    if(fp == NULL)
    {
        puts("文件打开失败.\n");
    }
    else
    {
        fread(arr_2, sizeof(arr_2[0]), len, fp);
        for(int i = 0; i < len; i++)
        {
            printf("%23.21lf\n", arr_2[i]);
        }
        puts("以上为文件中读到的浮点数.\n");

        // 使用完毕
        fclose(fp);
    }
    fp = NULL;

    return 0;
}