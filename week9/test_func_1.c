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

my_times *wrap_struct_tm_to_my_times(my_times *des, const struct tm *src);

int main(void)
{
    my_times a = {0};
    time_t c = time(NULL);
    struct tm *timer = localtime(&c);
    wrap_struct_tm_to_my_times(&a, timer);
    printf("%d\n", a.tm_sec);

    return 0;
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