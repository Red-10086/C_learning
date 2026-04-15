#include <stdio.h>
#include <string.h>
#include <math.h>

enum signs { Unsigned_Number, Positive, Negative };

int strtoi(const char *nptr);
/* ptr_to_first_num指向+或-符号后的第一个数字 */
int str_to_unsigned(const char *ptr_to_first_num);

int main(void)
{
    int Number = 0;
    char str[128] = {0};

    printf("请输入整数:\n");
    scanf(" %s", str);

    Number = strtoi(str);
    printf("%d", Number);

    return 0;
}

int strtoi(const char *nptr)
{
    int Number = 0;
    int i = 0;

    /* 为0时,字符串表示无符号整数,为1时表示正数,为2时表示负数,为EOF时表示错误 */
    int signed_type = 0;

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
            Number = str_to_unsigned(nptr+1);// +1表示跳过符号位
            break;
        case Negative:
            Number = -1 * str_to_unsigned(nptr+1);// +1表示跳过符号位
            break;
        case Unsigned_Number:
            Number = str_to_unsigned(nptr);
            break;
        case EOF:
            printf("输入格式有误\n");
            break;
    }

    return Number;
}

/* ptr_to_first_num指向+或-符号后的第一个数字 */
int str_to_unsigned(const char *ptr_to_first_num)
{
    int Number = 0;                 // 字符串对应整数
    int len = strlen(ptr_to_first_num);         // 不含符号位的string length

    for(int i = 0; i < len ; i++)
    {
        /* 累加:
            i=0: Number = 0 * 10 + 1 = 1
            i=1: Number = 1 * 10 + 2 = 12
            i=2: Number = 12 * 10 + 3 = 123
            i=3: Number = 123 * 10 + 4 = 1234 */
        Number = Number * 10 + (ptr_to_first_num[i] - '0');
    }

    return Number;
}