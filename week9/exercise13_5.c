/* 
    练习13-5 在代码清单13-4的程序中,加上表示当前"心情"的字符串.
    即,在显示上一次的运行时间(和上一次的心情)之后,提示输入"当前的心情:",
    从键盘读入字符串再写入文件.
    例如,如果输入"极好!!",那么程序在下一次运行时,就应显示"上一次运行是在
    XXXX年XX月XX日XX时XX分XX秒,心情极好!!".

    清单13-4大略:
        文件名datetime.dat
        主函数:
            get_data();     // 获得并显示上一次运行时的日期和时间
            put_data();     // 写入本次运行时的日期和时间
*/

#include <time.h>
#include <stdio.h>

enum {mood_len = 128};

void get_data(const char *f);    // 获得并显示上一次运行时的日期和时间
void put_data(const char *f);    // 写入本次运行时的日期和时间

int main(void)
{
    // 不可随意更改文件名,只写模式会清空文件原内容
    char data_file[] = "datetime.dat";

    get_data(data_file);

    put_data(data_file);

    return 0;
}

// 获得并显示上一次运行时的日期和时间,f为要读的文件
void get_data(const char *f)
{
    FILE *fp = fopen(f, "r");
    // 只读模式找不到,说明没创建,是第一次运行.
    if(fp == NULL)
    {
        fprintf(stdout, "本程序第一次运行\n");
    }
    else
    {
        int year, mon, day, hour, min, sec;
        char mood[mood_len] = {0};
        char tips[sizeof("心情")] = "心情";
        fscanf(fp, "%d %d %d %d %d %d %s %s", &year, &mon, &day, &hour, &min, &sec, tips, mood);
        fprintf(stdout, "上一次运行是在%d年%d月%d日%d时%d分%d秒,%s%s!!\n", year, mon, day, hour, min, sec, tips, mood);
        fclose(fp);
    }
    fp = NULL;


}


// 写入本次运行时的日期和时间,f为要写的文件
void put_data(const char *f)
{
    // 获取时间戳
    time_t current = time(NULL);
    // 分解时间戳为无名结构体(struct tm),生成一个指向该结构体的指针
    struct tm *time_p = localtime(&current);

    FILE *fp = fopen(f, "w");
    if(fp == NULL)
    {
        printf("文件打开失败\n");
    }
    else
    {
        char mood[mood_len] = {0};
        char tips[sizeof("心情")] = "心情";
        printf("当前的心情:\n");
        scanf("%127s", mood);
        
        // 依次写入年月日时分秒
        fprintf(fp, "%d %d %d %d %d %d %s %s"
            , time_p->tm_year + 1900, time_p->tm_mon + 1, time_p->tm_mday,
             time_p->tm_hour, time_p->tm_min, time_p->tm_sec, tips, mood
        );

        fclose(fp);
    }
    fp = NULL;
}