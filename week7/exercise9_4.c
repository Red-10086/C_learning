/* 
    练习9-4 编写一个函数,使字符串s为空字符串
    void null_string(char s[]){codes}

*/

#include <stdio.h>

void null_string(char s[]);

void null_string(char s[])
{
    s[0] = '\0';/* 决不能是'0',应该是'\0',即null字符 */

    return;
}