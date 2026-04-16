#include <stdio.h>
#include <string.h>
#include <math.h>
#include "strto.h"

enum signs { Unsigned_Number, Positive, Negative };

long long strtoLL(const char *nptr);

/* ptr_to_first_num指向+或-符号后的第一个数字 */
long long str_to_unsignedlonglong(const char *ptr_to_first_num);

// int main(void)
// {
//     long long Number = 0;
//     char str[128] = {0};

//     printf("请输入整数:\n");
//     scanf(" %s", str);

//     Number = strtoLL(str);
//     printf("%lld", Number);

//     return 0;
// }

long long strtoLL(const char *nptr)
{
    long long Number = 0;
    long long i = 0;

    /* 为0时,字符串表示无符号整数,为1时表示正数,为2时表示负数,为EOF时表示错误 */
    long long signed_type = 0;

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
    for(i = 1; signed_type != EOF && nptr[i] != '\0'; i++)
    {
        if(nptr[i] < '0' || nptr[i] > '9')
        {
            signed_type = EOF;
            break;
        }
    }

    switch(signed_type){
        case Positive:
            Number = str_to_unsignedlonglong(nptr+1);// +1表示跳过符号位
            break;
        case Negative:
            Number = -1 * str_to_unsignedlonglong(nptr+1);// +1表示跳过符号位
            break;
        case Unsigned_Number:
            Number = str_to_unsignedlonglong(nptr);
            break;
        case EOF:
            printf("输入格式有误\n");
            break;
    }

    return Number;
}

/* ptr_to_first_num指向+或-符号后的第一个数字 */
long long str_to_unsignedlonglong(const char *ptr_to_first_num)
{
    long long Number = 0;                       // 字符串对应整数
    long long len = strlen(ptr_to_first_num);   // 不含+或-符号的string length
    
    const char *begin = ptr_to_first_num;       // 首个数字字符坐标,自此始.
    const char *end = ptr_to_first_num + len;   // 末元素后一位,不可及
    const char *p_traverse = NULL ;             // 用于遍历字符串的指针

    for(p_traverse = begin; p_traverse < end; p_traverse++)
    {
        /* 累加:例如,对于"1234":
            指向'1': Number = 0 * 10 + '1'-'0' = 1
            指向'2': Number = 1 * 10 + '2'- '0' = 12
            指向'3': Number = 12 * 10 + '3' - '0' = 123
            指向'4': Number = 123 * 10 + '4' - '0' = 1234 
            指向'\0':结束
        */
        Number = Number * 10 + (*p_traverse - '0');
    }

    return Number;
}