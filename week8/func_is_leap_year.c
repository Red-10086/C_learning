int is_leap_year(int *y);

int is_leap_year(int *y)
{
    int is_lp_yr = 0;/* 是闰年 */
    
    /* 整数除法是否整除,使用余数而非商判定 */
    if( ( ( *y % 100 != 0 ) && ( *y % 4 == 0 ) ) || ( *y % 400 == 0 ) )
    {
        is_lp_yr = 1;
    }
    else
    {
        is_lp_yr = 0;
    }

    return is_lp_yr;
}