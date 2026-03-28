enum beyond_bound_state { Downward = -1, False = 0, Upward = 1 };
enum month_days {
    First_day = 1,    /* 1 日 */
    Second_day,       /* 2 日 */
    Third_day,        /* 3 日 */
    Fourth_day,       /* 4 日 */
    Fifth_day,        /* 5 日 */
    Sixth_day,        /* 6 日 */
    Seventh_day,      /* 7 日 */
    Eighth_day,       /* 8 日 */
    Ninth_day,        /* 9 日 */
    Tenth_day,        /* 10 日 */
    Eleventh_day,     /* 11 日 */
    Twelfth_day,      /* 12 日 */
    Thirteenth_day,   /* 13 日 */
    Fourteenth_day,   /* 14 日 */
    Fifteenth_day,    /* 15 日 */
    Sixteenth_day,    /* 16 日 */
    Seventeenth_day,  /* 17 日 */
    Eighteenth_day,   /* 18 日 */
    Nineteenth_day,   /* 19 日 */
    Twentieth_day,    /* 20 日 */
    Twenty_first_day, /* 21 日 */
    Twenty_second_day,/* 22 日 */
    Twenty_third_day, /* 23 日 */
    Twenty_fourth_day,/* 24 日 */
    Twenty_fifth_day, /* 25 日 */
    Twenty_sixth_day, /* 26 日 */
    Twenty_seventh_day,/* 27 日 */
    Twenty_eighth_day,/* 28 日 */
    Twenty_ninth_day, /* 29 日 */
    Thirtieth_day,    /* 30 日 */
    Thirty_first_day  /* 31 日 */
};

enum month_number {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec,
                    January = 1, February, March, April, May, June, July, August, September, October, November, December };

enum month_types {solar, lunar, leap, regular};/* 大月,小月,闰二月,平二月 */

加n天,减n天,都无所谓;

/* 先int date = *d ± n; */


void date_move(int *y, int *m, int *d, int n)
{
    int i = 10000;
    *d += n;/* 日期直接变动 */
    while(i--)/* 防止无限循环,一万年的跨度查日期也没什么意义 */
    {
        enum beyond_bound_state beyond_date = 日_越界判定函数(y, m, d);
        
        if(beyond_date)
        {
            日期越界修正(y, m, d, beyond_date);
            continue;
        }
        else
        {
            break;
        }
    }
    
}



















日期越界修正(int *y, int *m, int *d, int beyond_date);
日期越界修正(int *y, int *m, int *d, int beyond_date)/* 每调用一次只向前或向后修正一个月 */
{
    switch (beyond_date){
        
        case Downward:
            *m -= 1;/* 回到前一个月 */
            
            enum beyond_bound_state beyond_month = 月_越界判定函数(m);
            if(beyond_month)
            {
                月份越界修正(y, m, beyond_month);
            }

            int up_date = up_bound(y, m);
            *d += up_date;/* 加上月份回退产生的盈余日期 */
            break;
        case Upward:
            int up_date = up_bound(y, m);
            d -= up_date;/* 扣除本月剩余日期 */
            *m += 1;/* 进入下一个月*/

            enum beyond_bound_state beyond_month = 月_越界判定函数(m);
            if(beyond_month)
            {
                月份越界修正(y, m, beyond_month);
            }
            break;
    }
}



月份越界修正(int *y, int *m, int beyond_month)
{
    switch (beyond_month){
        case Downward:
            *m = Dec;
            *y -= 1;
            break;
        
        case Upward:
            *m = Jan;
            *y += 1;
            break;
    }
}

月_越界判定函数(int *m)
{
    enum beyond_bound_state result = False;
    if(*m < Jan)
    {
        result = Downward;
    }
    else if(*m > Dec)
    {
        result = Upward;
    }
    else
    {
        result = False;
    }

    return result;
}

enum month_days up_bound(int *y, int *m)/* 日上界函数 */
{
    int result = 0;
    enum month_types temp_type = indentify_month_type(y, m);/* 获得月份类型 */

    switch (temp_type){/* 根据月份类型决定上界:一个月的最大日期 */
        case solar:
            result = Thirty_first_day;
            break;

        case lunar:
            result = Thirtieth_day;
            break;
        
        case leap:
            result = Twenty_ninth_day;
            break;

        case regular:
            result = Twenty_eighth_day;
            break;
    }
}

enum beyond_bound_state 日_越界判定函数(int *y, int *m, int *d)
{
    enum beyond_bound_state result = False;

    enum month_days up_date = up_bound(y, m);/* 月末 */
    enum month_days lo_date = First_day;/* 月初 */

    if(*d < lo_date)
    {
        result = Downward;
    }
    else if(*d > up_date)
    {
        result = Upward;
    }
    else
    {
        result = False;
    }

    return result;
}