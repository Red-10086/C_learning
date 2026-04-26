/* 
    练习13-2 编写程序,从键盘读入文件名,消去该名称文件的内容.
    提示:以只写模式打开文件即可(用只写模式"w"打开文件后,文件的内容就被消除了)
*/

#include <stdio.h>

enum {str_len = 128};

int main(void)
{
        FILE *fp;

    const char *filename = NULL;
    char temp[str_len] = {0};

    // 从键盘输入文件名
    // printf("请输入要->清空<-的文件名:\n");
    // scanf("%127s", temp);
    filename = temp;

    // 根据fopen返回值判断是否成功打开文件
    // const char *filename = NULL;
    // fp = fopen(filename, "w");
    
    if (fp == NULL)
    {
        printf("该文件不存在\n");
    }
    else
    {
        printf("该文件存在,已清除文件内容\n");
        
        // int fclose(FILE *stream)
        // fclose(fp);
    }

    return 0;
}