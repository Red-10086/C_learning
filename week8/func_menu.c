#include <stdio.h>

char* menu(char *p_to_choice);/* 打印提示信息,并接收用户选择的操作 */

// int main(void)
// {
//     menu();
//     return 0;
// }

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
        p_to_choice = getchar();
        if(p_to_choice >= '0' && p_to_choice <= '4')
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