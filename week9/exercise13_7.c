/* 
    练习13-7 编写程序,实现从键盘读入文件名,计算该文件的字符数并显示在界面上.
*/

#include <stdio.h>

int main(void)
{
    // 字符个数
    int number = 0;
    // 文件名
    char fname[FILENAME_MAX];
    
    // 读文件名
    fprintf(stdout, "请输入要读取的文件:\n");
    fscanf(stdin, "%s", fname);

    // 只读模式打开文件
    FILE *fp = fopen(fname, "r");
    if(fp == NULL)
    {
        fprintf(stdout, "读取失败.\n");
    }
    else
    {
        // 装fgetc返回值的临时变量,即此轮循环读到的字符
        int ch = 0;
        do
        {
            ch = fgetc(fp);
            number++;
        // 读到的不是结束符则继续
        }while( ch != EOF );

        fclose(fp);
    }

    printf("共有%d个字符", number);

    return 0;
}