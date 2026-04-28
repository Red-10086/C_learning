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
    fp = fopen("test.bin", "w+");
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
    fp = fopen("test.bin", "r+");
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

    printf("%d\n", temp_struct.tm_year);
    printf("%d\n", temp_struct.tm_mon);
    printf("%d\n", temp_struct.tm_mday);
    printf("%d\n", temp_struct.tm_hour);
    printf("%d\n", temp_struct.tm_min);
    printf("%d\n", temp_struct.tm_sec);
    
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
