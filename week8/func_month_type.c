/* 
    区分月份种类
*/
#include <stdio.h>

enum month_types {solar, lunar, leap, regular};/* 大月,小月,闰二月,平二月 */

enum month_number {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec,
                    January = 1, February, March, April, May, June, July, August, September, October, November, December };

enum month_types identify_type(int *y, int *m);/* 判定月份类型 */

enum month_types identify_type(int *y, int *m)/* 判定月份类型 */
{
    enum month_types result = -1;

    switch (*m)
    {
        case Jan: case Mar: case May: case Jul: case Aug: case Oct: case Dec:
            result = solar;
            break;

        case Apr: case Jun: case Sep: case Nov:
            result = lunar;
            break;

        case Feb:
            if(is_leap_year(y))
            {
                result = leap;
            }
            else
            {
                result = regular;
            }
            break;
    }

    return result;
}