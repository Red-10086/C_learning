/* 
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
*/
enum month_types {solar, lunar, leap, regular};/* 大月,小月,闰二月,平二月 */
enum month_number {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec,
January = 1, February, March, April, May, June, July, August, September, October, November, December };

int is_leap_year(int *y);/* 判定:是闰年? */
void decrement_date(int *y, int *m, int *d);/* 前移一日 */
enum month_types identify_type(int *y, int *m);/* 判定月份类型 */

void decrement_date(int *y, int *m, int *d)
{
    enum month_types m_type = -1;/* 月份类型 */

    if(*d != 1)/* 非月首日,日期减一 */
    {
        *d -= 1;
    }
    else
    {
        *m -= 1;/* 跨月 */
        
        

    }


}
