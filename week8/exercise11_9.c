/* 
练习11-9 使用本节中学习的库函数(strlen、strcpy、strncpy、
strcat、strncat、strcmp、strncmp这几个函数)编写程序

编写一个简易字符串处理菜单程序，用户可以选择不同的字符串操作。

===== 字符串处理菜单 =====
1. 显示字符串长度 (strlen)
2. 复制字符串 (strncpy)
3. 比较两个字符串 (strcmp)
4. 连接两个字符串 (strncat)
0. 退出
=========================
请选择操作：
*/

#include <stdio.h>
#include <string.h>

enum Const_Numbers { length = 128, five = 5 };

char* menu(char *p_to_choice);
char *read_str(char *s);

int main(void)
{
    char str_1[length] = {0};
    char str_2[length] = {0};
    char choice = 0;

    while(choice != '0')
    {
        menu(&choice);
        switch(choice)
        {
            case '0':
                printf("程序结束\n");
                break;

            case '1':
                read_str(str_1);
                printf("字符串长度:%d\n", strlen(str_1));
                break;

            case '2':
                read_str(str_1);
                read_str(str_2);
                strncpy(str_1, str_2, five);
                /* 必须保证strlen(s2) + 1 <= n <= s1总容量 */
                if( strlen(str_2) + 1 > five )
                {
                    *(str_1+five) = '\0';/* 手动补'\0' */
                }
                printf("将后一个字符串前五个字符复制到第一个字符串后:%s\n", str_1);
                break;
            
            case '3':
                read_str(str_1);
                read_str(str_2);
                if(strcmp(str_1, str_2) == 0)/* 返回0表示相等 */
                    printf("比较结果:相等\n");
                else
                    printf("比较结果:不相等\n");
                break;

            case '4':
                read_str(str_1);
                read_str(str_2);
                
                /* 够长-符合边界条件-直接连 */
                if(length >= strlen(str_1) + strlen(str_2) +1)
                {
                    strcat(str_1, str_2);
                }
                /* 不够长-最多把str_1剩下部分填满且留一个'\0'位置 */
                else
                {
                    /* 多减一个1预留'\0'位置 */
                    int n = length - strlen(str_1) - 1;
                    
                    /* n显然大于等于0,对于正整数,strncat能很好地处理边界
                    情况:n=0时直接不写,末尾写'\0' */
                    strncat(str_1, str_2, n);
                }
                printf("连接两个字符串:%s\n", str_1);
                break;

            default :
                printf("请重试\n");
                break;
        }
    }

    return 0;
}



char* menu(char *p_to_choice)
{
    printf("===== 字符串处理菜单 =====\n");
    printf("1. 显示字符串长度 (strlen)\n");
    printf("2. 复制字符串 (strncpy)\n");
    printf("3. 比较两个字符串 (strcmp)\n");
    printf("4. 连接两个字符串 (strncat)\n");
    printf("0. 退出\n");
    printf("=========================\n");
    printf("请选择操作:\n");
    do{
        scanf(" %c", p_to_choice);
        if(*p_to_choice >= '0' && *p_to_choice <= '4')
        {
            break;
        }
        else
        {
            printf("输入有误,请重新输入:\n");
        }
    }while(1);

    return p_to_choice;
}

char *read_str(char *s)
{
    printf("请输入字符串:\n");
    scanf(" %127s", s);

    return s;
}
