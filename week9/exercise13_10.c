/* 
    练习13-10 请参考代码清单13-7编写一个程序,将所有英文大写字母转换为
    小写字母的同时执行复制操作.
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
                // 如果遇到大写字母,转小写
                if(ch >= 'A' && ch <= 'Z')
                {
                    ch = ch + 'a' - 'A';
                    
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