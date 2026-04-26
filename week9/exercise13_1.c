/* 
    练习13-1 代码清单13-1中的程序只能打开名为"abc"的文件.请将程序改为从键盘读入
    文件名,如果存在该名称的文件,就显示"该文件存在",否则就显示"该文件"不存在.
*/

#include <stdio.h>

enum {str_len = 128};

int main(void)
{
    FILE *fp;

    const char *filename = NULL;
    char temp[str_len] = {0};

    // 从键盘输入文件名
    printf("请输入文件名:\n");
    scanf("%127s", temp);
    filename = temp;

    // 根据fopen返回值判断是否成功打开文件
    // const char *filename = NULL;
    fp = fopen(filename, "r");
    
    if (fp == NULL)
    {
        printf("该文件不存在\n");
    }
    else
    {
        printf("该文件存在\n");
        
        // int fclose(FILE *stream)
        fclose(fp);
    }
    
    return 0;
}
// 错误写法:
// const char *类型指针不能用scanf按地址写
// 指向NULL的指针也不能用scanf写(对NULL解引用)
// // 指向的内容不可变,但是指针可以换指向
// const char *filename = NULL;
// printf("请输入要读取的文件名:\n");
// scanf("%s", filename);
// FILE *fopen(const char *flename, const char *mode)