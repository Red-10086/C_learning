/*
    练习13-12 改写代码清单13-4的程序,将日期和时间作为struct tm型的值
    直接向二进制文件进行读写操作.
    
	清单13-4:

#include <time.h>
#include <stdio.h>

char data_file[] = "datetime.dat";				 文件名 

--- 取得并显示上一次运行时的日期和时间 ---
void get_data(void)
{
    FILE *fp;

    if ((fp = fopen(data_file, "r")) == NULL)				 打开文件 
        printf("本程序第一次运行。\n");
    else {
        int year, month, day, h, m, s;

        fscanf(fp, "%d %d %d %d %d %d", &year, &month, &day, &h, &m, &s);
        printf("上一次运行是在%d年%d月%d日%d时%d分%d秒。\n",
                                        year, month, day, h, m, s);
        fclose(fp);											 关闭文件 
    }
}

--- 写入本次运行时的日期和时间 ---
void put_data(void)
{
    FILE *fp;
    time_t current = time(NULL);				 当前日历时间 
    struct tm *timer = localtime(&current);		 分解时间

    if ((fp = fopen(data_file, "w")) == NULL)				 打开文件 
        printf("\a文件打开失败。\n");
    else {
        fprintf(fp, "%d %d %d %d %d %d\n",
                timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday,
                timer->tm_hour,		   timer->tm_min,	  timer->tm_sec);
        fclose(fp);											 关闭文件 
    }
}
        
int main(void)
{
    get_data();			 取得并显示上一次运行时的日期和时间 
    
    put_data();			 写入本次运行时的日期和时间 
    
    return 0;
}
            
    思路1:既然有一个变量(current)能存储全部的时间信息,那就只读写它,
    读出来用localtime函数分解即可,可惜不符合题目要求(太简单了,没有考察能力).
    思路2:用fwrite函数按顺序逐个保存成员以保存整个结构体struct tm,但是读出来的时候,需要
    额外的结构体(C原生的struct tm不可写)来装,或者一群变量来装.
*/
            
            
#include <stdio.h>
#include <time.h>

typedef struct {
    int tm_year;
    int tm_mon;
    int tm_mday;
    int tm_hour;
    int tm_min;
    int tm_sec;
} my_times;

// // 按顺序把结构体src_struct的成员写入流fp
void fwrite_my_times_to_file(const my_times *src_struct, FILE *fp);

// 把流fp中存储的结构体信息,按顺序写入des_struct的成员
void fread_file_to_my_times(my_times *des_struct, FILE *fp);

// // 把不可写的struct tm装进自己写的my_times结构体
my_times *wrap_struct_tm_to_my_times(my_times *des, const struct tm *src);

int main(void)
{
    time_t c = time(NULL);
    struct tm *timer = localtime(&c);

    my_times temp_struct = {0};

    // 将timer所指的分解好的时间写进t
    wrap_struct_tm_to_my_times(&temp_struct, timer);

    // 按顺序把t的成员写入流fp
    FILE *fp = NULL;
    fp = fopen("test.bin", "wb+");
    if(fp == NULL)
    {
        puts("err\n");
    }
    else
    {
        fwrite_my_times_to_file(&temp_struct, fp);
        fclose(fp);
    }
    fp = NULL;

    // 按顺序把流fp写入t的成员
    fp = fopen("test.bin", "rb+");
    if(fp == NULL)
    {
        puts("err\n");
    }
    else
    {
        fread_file_to_my_times(&temp_struct, fp);
        fclose(fp);
    }
    fp = NULL;
    
    return 0;
}

// 按顺序把结构体src_struct的成员写入流fp
void fwrite_my_times_to_file(const my_times *src_struct, FILE *fp)
{
    fseek(fp, 0, SEEK_CUR);
    fwrite(&src_struct->tm_year, sizeof(int), 1, fp);
    fwrite(&src_struct->tm_mon, sizeof(int), 1, fp);
    fwrite(&src_struct->tm_mday, sizeof(int), 1, fp);
    fwrite(&src_struct->tm_hour, sizeof(int), 1, fp);
    fwrite(&src_struct->tm_min, sizeof(int), 1, fp);
    fwrite(&src_struct->tm_sec, sizeof(int), 1, fp);
    fseek(fp, 0, SEEK_CUR);
}

// 把流fp中存储的结构体信息,按顺序写入des_struct的成员
void fread_file_to_my_times(my_times *des_struct, FILE *fp)
{
    fseek(fp, 0, SEEK_CUR);
    fread(&des_struct->tm_year, sizeof(int), 1, fp);
    fread(&des_struct->tm_mon, sizeof(int), 1, fp);
    fread(&des_struct->tm_mday, sizeof(int), 1, fp);
    fread(&des_struct->tm_hour, sizeof(int), 1, fp);
    fread(&des_struct->tm_min, sizeof(int), 1, fp);
    fread(&des_struct->tm_sec, sizeof(int), 1, fp);
    fseek(fp, 0, SEEK_CUR);
}

// 把不可写的struct tm装进自己写的my_times结构体
my_times *wrap_struct_tm_to_my_times(my_times *des, const struct tm *src)
{
    my_times *tmp = des;
    
    // 将localtime所得时间转为现实时间
    des->tm_year  = src->tm_year + 1900;    
    des->tm_mon   = src->tm_mon  + 1;
    des->tm_mday  = src->tm_mday;
    des->tm_hour  = src->tm_hour;
    des->tm_min   = src->tm_min;
    des->tm_sec   = src->tm_sec;

    return tmp;
}
