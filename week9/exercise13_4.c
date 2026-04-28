/* 
    练习13-4 请采用代码13-2的文件写入形式,编写一个从键盘读取姓名身高和体重,
    并将这些数据写入文件的程序.

    需求:
    1控制台提示输入人数,然后逐个输入并用结构体(senior{name,height,weight})暂存姓名,身高,体重
    2用fopen()只写模式清空/新建一个文件,逐个写入senior,用空格分隔开同一senior的不同成员,
    用回车分隔开不同senior
    3fclose

    思路:
    0声明结构体senior
    1提示输入人数number
    2初始化数组arr[number]
    3控制台提示输入,数组元素各成员按顺序和提示接收输入:只用scanf返回值做简单的输入检查,
    成功则继续,失败则打印提示,重新读取
    4创建一个流fp,并以只写模式打开文件,并判断是否打开成功,成功则继续,否则程序结束
    5用fprintf(fp, "%s %d %d\n", .name, .hei, .wei)写入文件
    6关闭文件

    7用程序exercise13_3(读文件)测试写入结果

*/
#include <stdio.h>

enum { name_len = 128 };

typedef struct{
    char name[name_len];
    int height;
    double weight;
} senior;

int main(void)
{
    // 读总人数
    int number = 0;
    // while(scanf("%d", &number) == 0 || number <= 0 )
    do
    {    
        printf("请输入要保存的总人数:\n");
        int read_success = scanf("%d", &number);
        // 读取成功
        if( read_success == 1 && number > 0 )
        {
            break;
        }
        // 读取有误或失败
        else
        {
            printf("输入有误,请重新输入.\n");
            
            // 清空输入缓冲区以及换行符
            char c;
            while ((c = getchar()) != '\n' && c != EOF); 
            
            continue;
        }
    }while( 1 );
    
    // 暂存各对象信息
    senior arr[number];
    for(int i = 0; i < number ; i++)
    {
        printf("请输入第%d名同学的姓名:\n", i+1);   scanf("%s", arr[i].name);    
        printf("请输入第%d名同学的身高:\n", i+1);   scanf("%d", &arr[i].height);
        printf("请输入第%d名同学的体重:\n", i+1);   scanf("%lf", &arr[i].weight);
    }

    // 只写模式打开文件
    // 初学阶段,不要用while反复打开为好,容易栈溢出,我猜想"实现重新打开"需要严格的审核流程
    FILE *fp = fopen("senior.txt", "w");
    if(fp == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        // 一行写一个senior,用空格间隔不同成员
        for(int i = 0; i < number; i++)
        {
            fprintf(fp, "%s %d %lf\n", arr[i].name, arr[i].height, arr[i].weight);
        }

        // 结束时关闭文件
        fclose(fp);
    }
    fp = NULL;
    
    return 0;
}