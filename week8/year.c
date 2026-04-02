#include <stdio.h>

enum months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

int is_leap_year(int year_id);/* 输入年份,如闰年,返回1,否则返回0 */
void move_date(int *y, int *m, int *d, int n);/* n为正表示时间正流n日,为负则表示时间"倒流"n日 */

int main(void)
{
    // printf("请用整数输入今年年份:\n");        scanf("%d", &year);
    // printf("请用整数输入本月月份:\n");        scanf("%d", &month);
    // printf("请用输入今天是多少号:\n");        scanf("%d", &day);
    // printf("请输入你希望往前或往后数多少天,负整数表示往前,正整数表示往后:\n");
    // scanf("%d", &n);
    int year = 2026;
    int month = Mar;
    int day = 31;
    int n = 0;

    for( n = 0; n <= 1000; n += 7)/* 测试 */
    {
        /* 每轮循环都得重新设定 */
        year = 2026;
        month = Mar;
        day = 31;

        move_date(&year, &month, &day, n);
        
        if(n < 0)
        {
            printf("向前移动%d天后的日期是:%d年%d月%d日\n", -n, year, month, day);
        }
        else if( n > 0)
        {   
            printf("向后移动%d天后的日期是:%d年%d月%d日\n", n, year, month, day);
        }
        else
        {
            printf("移动%d天后的日期仍是:%d年%d月%d日\n", n, year, month, day);
        }
}
    
    return 0;
}


int is_leap_year(int year_id)
{
    int result = 0;

    if(year_id % 400 == 0 || year_id % 100 != 0 && year_id % 4 == 0)
    {
        result = 1;
    }

    return result;
}
void move_date(int *y, int *m, int *d, int n)/* n为正表示时间正流n日,为负则表示时间"倒流"n日 */
{
    /* 由当前年份信息确认所有月份天数 */
    int month_days[13] = {0};
    month_days[Jan] = 31;   month_days[Feb] = 28;   month_days[Mar] = 31;
    month_days[Apr] = 30;   month_days[May] = 31;   month_days[Jun] = 30;
    month_days[Jul] = 31;   month_days[Aug] = 31;   month_days[Sep] = 30;
    month_days[Oct] = 31;   month_days[Nov] = 30;   month_days[Dec] = 31;
    if(is_leap_year(*y)){
        month_days[Feb] = 29;
    }

    /* dates表示该日期在年内的序号-以1月1日起为第1天,12月31日为最后一天 */
    int dates = *d;
    for(int i = Jan; i < *m; i++)
    {
        dates += month_days[i];
    }
    dates += n;

    /* 处理跨年 */
    for( ; dates > ( 365 + is_leap_year(*y) ) || dates <= 0 ;)
    {
        if( dates <= 0 )
        {
            *y -= 1;
            dates = dates + 365 + is_leap_year(*y);
        }
        else if( dates > ( 365 + is_leap_year(*y) ) )
        {
            dates = dates - 365 - is_leap_year(*y);
            *y += 1;
        }
    }

    if(is_leap_year(*y))/* 如果处理完跨年,年份会有变动,需要重新设定2月总天数 */
    {
        month_days[Feb] = 29;
    }

    for(int i = Jan; i <= Dec; i++)/* 必须遍历到12月,不能用<号 */
    {
        if(dates > month_days[i])
        {
            dates -= month_days[i];
        }
        else/* dates <= month_days[i]时,i即表示dates对应月份,dates就表示当月日期 */
        {
            *d = dates;
            *m = i;
            break;
        }
    }
}