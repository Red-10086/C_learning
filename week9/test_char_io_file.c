#include <stdio.h>
#include <time.h>

enum {len = 128};

typedef struct {
    int tm_year;
    int tm_mon;
    int tm_mday;
    int tm_hour;
    int tm_min;
    int tm_sec;
} my_times;

typedef struct {
    // char *a;
    int b;
    char c[len];
} my_str;

// // 按顺序把结构体src_struct的成员写入流fp
void fwrite_my_times_to_file(const my_times *src_struct, FILE *fp);

// 把流fp中存储的结构体信息,按顺序写入des_struct的成员
void fread_file_to_my_times(my_times *des_struct, FILE *fp);

// // 把不可写的struct tm装进自己写的my_times结构体
my_times *wrap_struct_tm_to_my_times(my_times *des, const struct tm *src);

int main(void)
{
    
    my_times temp_struct = {0};
    my_str   temp_strings = {/* .a = "ABCD", */ .b = 1, .c = "ABCD"};
    
    FILE *fp = NULL;
    // 按顺序读流fp,记录入temp_struct
    fp = fopen("test_char_io_file.bin", "rb+");
    if(fp == NULL)
    {
        puts("err\n");
    }
    else
    {
        // fread_file_to_my_times(&temp_struct, fp);
        fread(&temp_struct, sizeof(temp_struct), 1, fp);
        fread(&temp_strings, sizeof(temp_strings), 1, fp);
        printf("上次运行时间是%d年%d月%d日%d时%d分%d秒\n", 
            temp_struct.tm_year, temp_struct.tm_mon, temp_struct.tm_mday, 
            temp_struct.tm_hour, temp_struct.tm_min, temp_struct.tm_sec);
            fclose(fp);
        }
        
    fp = NULL;
        
    // 获取当前时间
    time_t c = time(NULL);
    struct tm *timer = localtime(&c);

    // 将timer所指的分解好的时间写进temp_struct
    wrap_struct_tm_to_my_times(&temp_struct, timer);

    fp = fopen("test_char_io_file.bin", "wb+");
    // 按顺序把temp_struct的成员写入流fp
    if(fp == NULL)
    {
        puts("err\n");
    }
    else
    {
        // fwrite_my_times_to_file(&temp_struct, fp);
        fwrite(&temp_struct, sizeof(temp_struct), 1, fp);
        fwrite(&temp_strings, sizeof(temp_strings), 1, fp);

        // printf("sizeof(temp_strings.a) = %zu\n", sizeof(temp_strings.a));
        printf("sizeof(temp_strings.b) = %zu\n", sizeof(temp_strings.b));
        printf("sizeof(temp_strings.c) = %zu\n", sizeof(temp_strings.c));
        printf("sizeof(temp_strings)   = %zu\n", sizeof(temp_strings));

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
