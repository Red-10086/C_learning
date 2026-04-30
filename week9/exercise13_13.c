/* 
    练习13-13 改写代码清单13-7的程序,将文件作为二进制文件进行复制.
    注意读写时使用fread函数和fwrite函数.
*/

#include <stdio.h>

enum {len = 128};

int main(void)
{
    char temp = 0;
    char filename_src[len] = {0};
    char filename_des[len] = {0};

    printf("请输入要复制的文件名:\n");
    scanf("%127s", filename_src);
    printf("请慎重输入副本文件名,一旦重名,可能清空旧文件而无法恢复.\n");
    printf("请输入副本的文件名:\n");
    scanf("%127s", filename_des);
    FILE *fp_read  = fopen(filename_src, "r");
    FILE *fp_write = fopen(filename_des, "w");

    if(fp_read == NULL)
    {
        puts("原文件文件打开失败\n");
    }
    else if(fp_write == NULL)
    {
        puts("副本文件打开失败\n");
    }
    else
    {
        // fread读到文件末尾会返回0
        while(fread(&temp, sizeof(char), 1, fp_read) != 0)
        {
            // 从hw.dat中读了立刻往hw.bin中写
            fwrite(&temp, sizeof(char), 1, fp_write);
        }
        fclose(fp_read);
        fclose(fp_write);
    }

    return 0;
}