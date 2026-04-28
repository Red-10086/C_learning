/* 
    练习13-8 请参考代码13-7编写一个程序,在界面上显示文件内容的同时,
    执行复制操作(即同时输出到目标文件流和标准输出流).

    思路:三个读写头,一个只读,两个只写,仿照书上那样,用int ch做中间变量
    1ch = fgetc(src_stream);
    2fputc(ch, des_stream);
    3fputc(ch, stdout);
*/

#include <stdio.h>

int main(void)
{
    // 指向原文件流
    FILE *src_fp = NULL;
    // 指向目标文件流
    FILE *des_fp = NULL;

    // 原文件名
    char src_filename[FILENAME_MAX] = {0};
    // 目标文件名
    char des_filename[FILENAME_MAX] = {0};

    printf("请输入要复制的原文件名:\n");
    scanf("%s", src_filename);
    printf("请输入要复制的目标文件名:\n");
    scanf("%s", des_filename);

    src_fp = fopen(src_filename, "r");
    des_fp = fopen(des_filename, "w");

    if(src_fp == NULL)
    {
        printf("原文件打开失败\n");
    }
    else if(des_fp == NULL)
    {
        printf("目标文件打开失败\n");
    }
    else
    {
        int ch = 0;
        while(1)
        {
            // 读字符
            ch = fgetc(src_fp);

            // 只要没读到结束字符,就继续
            if(ch != EOF)
            {
                // 向目标文件流写字符
                fputc(ch, des_fp);
                // 向标准输出流写字符
                fputc(ch, stdout);
            }
            // 读到了结束字符就结束
            else
            {
                break;
            }
        }

        // 使用完成,关闭文件流
        fclose(src_fp);
        fclose(des_fp);
    }
    src_fp = NULL;
    des_fp = NULL;

    return 0;
}