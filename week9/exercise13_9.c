/* 
    练习13-8 请参考代码13-7编写一个程序,将所有英文小写字母转换为大写字母的同时,
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

    // 读写模式
    src_fp = fopen(src_filename, "r+");
    // 只写模式
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
                // 如果遇到小写字母,转大写
                if(ch >= 'a' && ch <= 'z')
                {
                    ch = ch + 'A' - 'a';
                    // 1读写头会"滑动,必须前移才能回到原字符
                    // // 两次清空缓冲区,保护文件
                    // fseek(src_fp, 0, SEEK_CUR);
                    // fputc(ch, src_fp);
                    // fseek(src_fp, 0, SEEK_CUR);
                    // 写入原文件
                    // 2搞了半天原来是你
                    // ch = ch + 'a' - 'A';
                    // 3fseek(src_fp, -1, SEEK_CUR);
                    // fputc(ch, src_fp);
                    // fseek(src_fp, -1, SEEK_CUR);
                    // 看来更新模式,原地更换都很难做到.
                    
                    // 回到原字符
                    fseek(src_fp, -1, SEEK_CUR);
                    // 覆写
                    fputc(ch, src_fp);
                    // 清空缓冲区
                    fseek(src_fp, 0, SEEK_CUR);
                }
                // 写入目标文件
                fputc(ch, des_fp);
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


    return 0;
}