#include <stdio.h>
#include <string.h>
#include <math.h>

enum signs { Unsigned_Number, Positive, Negative };

double str_to_double(const char *nptr);

/* ptr_to_first_num指向+或-或.符号后的第一个数字 */
double str_to_unsigned_double(const char *ptr_to_first_num, int point);

int main(void)
{
    double Number = 0;
    char str[128] = {0};

    printf("请输入浮点数:\n");
    scanf(" %s", str);

    Number = str_to_double(str);
    printf("%lf", Number);

    return 0;
}

double str_to_double(const char *nptr)
{
    double Number = 0;
    int i = 0;

    /* 为0时,字符串表示无符号浮点数,为1时表示正数,为2时表示负数,为EOF时表示错误 */
    int signed_type = 0;

    /* 表示小数点字符'.'对应元素的索引 */
    int point_index = 0;

    /* 表示小数点字符'.'的个数 */
    int point_num = 0;

    /* 首位检查 */
    if(nptr[i] == '+')
    {
        signed_type = Positive;
    }
    else if(nptr[i] == '-')
    {
        signed_type = Negative;
    }
    else if(nptr[i] >= '0' && nptr[i] <= '9')
    {
        signed_type = Unsigned_Number;
    }
    else
    {
        signed_type = EOF;
    }

    /* 逐位检查 */
    for(i = 1; signed_type != EOF && point_num <= 1 && nptr[i] != '\0'; i++)
    {
        if((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '.')
        {
            signed_type = EOF;
            break;
        }
        else if(nptr[i] == '.')
        {
            point_index = i;
            point_num++;
            if(point_num > 1)
            {
                /* 有多个小数点'.',错误 */
                signed_type = EOF;
                break;
            }
        }
    }

    switch(signed_type){
        case Positive:
            // +1表示跳过符号位, -1表示小数点相对nptr+1索引近了一位
            Number = str_to_unsigned_double(nptr+1, point_index-1);
            break;
        case Negative:
            // +1表示跳过符号位, -1表示小数点相对nptr+1索引近了一位
            Number = -1 * str_to_unsigned_double(nptr+1, point_index-1);
            break;
        case Unsigned_Number:
            Number = str_to_unsigned_double(nptr, point_index);
            break;
        case EOF:
            printf("输入格式有误\n");
            break;
    }

    return Number;
}

/* ptr_to_first_num指向+或-或.符号后的第一个数字 */
double str_to_unsigned_double(const char *ptr_to_first_num, int point)
{
    double Number = 0.0;                 // 字符串对应浮点数
    int len = strlen(ptr_to_first_num);  // 不含+或-符号的string length

    for(int i = 0; i < point ; i++)
    {
        /* 数位从左至右:i从0到len-1,位权重从高到低:10的len-1次方到0次方 */
        /* 特别地,如果这个字符串表示的数没有超过浮点数范围,那么它每一数位
        的权重:pow(10.0,len-i-1)也不会,double转换不会导致越界 */
        Number = Number + 
        (*(ptr_to_first_num+i) - '0') * (double)pow(10.0, point - i -1);
    }

    /* 跳过符号'.',继续加小数部分 */
    for(int i = point+1; i < len; i++)
    {
        Number = Number + 
        (*(ptr_to_first_num+i) - '0') * (double)pow(10.0, -(i-point));

    }

    return Number;
}