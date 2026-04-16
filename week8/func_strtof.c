#include <stdio.h>
#include <string.h>
#include <math.h>

enum signs { Unsigned_Number, Positive, Negative };
enum lengths { Length = 128};

double str_to_double(const char *nptr);

/* ptr_to_first_num指向+或-符号后的第一个数字 */
double str_to_unsigned_double(const char *ptr_to_first_num, const char *decimal_point);

int main(void)
{
    double Number = 0;
    char str[Length] = {0};

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

    /* 指向小数点字符'.'对应元素的指针 */
    const char *pointer_decimal_point = NULL;

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
            pointer_decimal_point = &nptr[i];
            point_num++;
            if(point_num > 1)
            {
                /* 有多个小数点'.',错误 */
                signed_type = EOF;
                break;
            }
        }
    }

    // 可惜,不能修改原数组
    // /* 没有小数点的默认为整数,末尾加".0" */
    // if(point_num == 0)
    // {
    //     /* 需要确保没有越界,即加了".0"后,原字符串长度+".0"长度 < 字符串数组长度,
    //     从而能以不破坏数据的形式在末尾补'\0' */
    //     if(strlen(nptr) + strlen(".0") < Length)
    //     {
    //        strcat(nptr, ".0");
    //     }
    //     else
    //     {
    //         /* 不够长,错误 */
    //         signed_type = EOF;
    //     }
    // }

    switch(signed_type){
        case Positive:
            // +1表示跳过符号位
            Number = str_to_unsigned_double(nptr+1, pointer_decimal_point);
            break;
        case Negative:
            // +1表示跳过符号位
            Number = -1 * str_to_unsigned_double(nptr+1, pointer_decimal_point);
            break;
        case Unsigned_Number:
            Number = str_to_unsigned_double(nptr, pointer_decimal_point);
            break;
        case EOF:
            printf("输入格式有误\n");
            break;
    }

    return Number;
}

/* ptr_to_first_num指向+或-符号后的第一个数字 */
double str_to_unsigned_double(const char *ptr_to_first_num, const char *decimal_point)
{
    double Number = 0.0;                    // 字符串对应浮点数
    double Number_int_part = 0.0;           // 整数部分
    double Number_decimal_part = 0.0;       // 小数部分
    
    int len = strlen(ptr_to_first_num);  // 不含+或-符号的string length
    
    const char *begin = ptr_to_first_num;       // 首个数字字符坐标,自此始.
    const char *end = ptr_to_first_num + len;   // 末元素后一位,不可及
    const char *p_traverse = NULL ;             // 用于遍历字符串的指针

    /* 从整数的首位数字开始 */
    p_traverse = begin;
    /* 有小数点(decimal_point != NULL)
        p_traverse < decimal_point
        无小数点((decimal_point == NULL))
        p_traverse < end
     */
    const char* Upper_limit = (decimal_point == NULL ? end : decimal_point);
    while(p_traverse < Upper_limit)
    {
        /* 比如123.456的整数部分:
            p指向'1'; N = 0*10 + '1'- '0';
            p指向'2'; N = 1*10 + '2'- '0';
            p指向'3'; N = 12*10 + '3'- '0';
            结束
        */
        Number_int_part = Number_int_part * 10 + (*p_traverse-'0');
        p_traverse++;
    }

    /* 如果有小数点(decimal_point != NULL),正常处理小数部分 */
    /* 如果无小数点(decimal_point == NULL),直接跳过小数部分 */
    if(decimal_point != NULL)
    {
        p_traverse = decimal_point + 1;
        Upper_limit = end;
        while(*p_traverse != '\0' && p_traverse < Upper_limit)
        {
            /* 比如123.456的整数部分:
                p指向'4'; N = 0.0 + ('4'- '0') * pow(0.1, '4'距离小数点的位数 );
                p指向'5'; N = 0.4 + ('5'- '0') * pow(0.1, &('5') - &('.') );
                p指向'6'; N = 0.45 + ('6'- '0') * pow(0.1, &('6') - &('.') );
                即:
                N = 0.0 + 4 * 0.1^1
                N = 0.4 + 5 * 0.1^2
                N = 0.45 + 6 * 0.1^3
                结束
            */
            Number_decimal_part = Number_decimal_part + 
            (*p_traverse - '0') * pow(0.1, p_traverse - decimal_point);
            
            p_traverse++;
        }
    }

    Number = Number_int_part + Number_decimal_part;

    return Number;
}