/* 
    练习13-6 编写程序实现从键盘读入文件名,计算该文件的行数(换行符的个数)并显示在界面上
*/

#include <stdio.h>

int main(void)
{
    // 换行符个数
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
            if(ch == '\n')
            {
                number++;
            }
        // 读到的不是结束符则继续
        }while( ch != EOF );

        // 最后一行没有换行符,但是也得计入总行数
        number++;

        fclose(fp);
    }

    printf("共有%d行", number);

    return 0;
}