/* 
    编写如下函数,将*y年*m约*d日的日期,修改为其前一天或后一天的日期.
        void decrement_date(int *y, int *m, int *d){codes}往前走一天
        void increment_date(int *y, int *m, int *d){codes}往后走一天
    注意计算时要考虑到闰年的问题.
    试错:
    {
        1,3,5,7,8,10,12是31天
        4,6,9,11月是30天
        2月:闰年(能被400整除 或 被四整除但不能被100整除)29天,平年28天
        前移一天:
            不跨月:非每月1日,都是日期减一;
            不跨年的跨月:是每月1日,考虑月份:
                2,4,6,8,9,11月1日,  往前一天都是*m减1, *d变为31
                5,7,10,12月1日,     往前一天都是*m减1, *d变为30
                3月1日,             往前一天:*m减1, 闰年则*d变为29日/平年则*d变为28日
            跨年(也跨月):1月1日,             往前一天:*y减1,*m变为12,*d变为31

        后移一天:
            跨年(其实也跨月):12月31日(*y加1,*m=1,*d=1)
            不跨年但跨月:1/3/5/7/8/10月31日;4/6/9/11月30;平年2月28/闰年2月29
                全都是*m+=1,*d=1
            其余日期(因为不跨月)都是*d+=1;

        细碎的分支结构太麻烦了,干脆这样:
            把一年分为大月(1,3,5,7,8,10,12)/小月(4,6,9,11)/闰月(2)
        
        闰年检查函数(int *y)
        {
            if(*y%4 == 0 && *y%100 != 0) || (*y%400 == 0)//整数除法用余数而不是商判断
            是则返回1, 否则返回0
        }
        前移一天:
            检查*d,非1则*d-=1;
            1月1日跨年特殊处理
            *d==1则先做*m-=1进入前一月,再根据*m进入分支:
                *m == 大月(枚举类)则*d = 31
                    若*m <= 0则 *m += 12;*y -= 1;//跨年
                *m == 小月则*d = 30
                *m == 闰月则检查*y:
                    if( 闰年检查 )
                    {
                        (闰年则)*d = 29;
                    }
                    else
                    {
                        (平年则)*d = 28;
                    }
        后移一天:
            12月31日跨年特殊处理
            大月
                若*m == 12则 *d = 1;*m = 1;*y += 1;
                否则 *d == 31 ? *d = 1, *m += 1 : *d += 1
            小月则 *d == 30 ? *d = 1, *m += 1 : *d += 1
            闰月则 
                if(*d == 29)肯定是闰年
                {
                    *m += 1;
                    *d = 1;   
                }
                else if(*d == 28)
                {
                    if(闰年检查(*y))
                    {
                        (闰年则)*d += 1;
                    }
                    else
                    {
                        (平年则)*m += 1;
                        *d = 1;
                    }
                }
                else
                {
                    *d += 1;
                }
    }

    正解:以一年的视角来看,只有2月29日存在与否是变量,其他全都是常量.
        先算出*d对应一年中的第几天-dates,只要变化在一年内,±n天都可以直接加减
        然后用结果dates的新值反推几月几日
        如果跨年,则先处理跨年(也无非是加减几个365/366,年的视角不用考虑具体月份)
        等到0<*d<当年年限(365/366)后,仍按上面的年内变化处理.
*/

#include <stdio.h>

enum months { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

void decrement_date(int *y, int *m, int *d);/* 时间正流一日 */
void increment_date(int *y, int *m, int *d);/* 时间倒流一日 */
void move_date(int *y, int *m, int *d, int n);/* n为正表示时间正流n日,为负则表示时间"倒流"n日 */
int is_leap_year(int year_id);/* 输入年份,如闰年,返回1,否则返回0 */

int main(void)
{
    int year = 1;
    int month = Jan;
    int day = 1;

    printf("请用整数输入今年年份:\n");        scanf("%d", &year);
    printf("请用整数输入本月月份:\n");        scanf("%d", &month);
    printf("请用输入今天是多少号:\n");        scanf("%d", &day);
    
    decrement_date(&year, &month, &day);    printf("昨天是:%d年%d月%d日\n", year, month, day);
    increment_date(&year, &month, &day);    printf("今天是:%d年%d月%d日\n", year, month, day);
    increment_date(&year, &month, &day);    printf("明天是:%d年%d月%d日\n", year, month, day);

    return 0;
}

void decrement_date(int *y, int *m, int *d)
{
    move_date(y, m, d, -1);
}

void increment_date(int *y, int *m, int *d)
{
    move_date(y, m, d, 1);
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

int is_leap_year(int year_id)
{
    int result = 0;

    if(year_id % 400 == 0 || year_id % 100 != 0 && year_id % 4 == 0)
    {
        result = 1;
    }

    return result;
}