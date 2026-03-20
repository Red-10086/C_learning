/* 
    练习9-8 编写如下函数,实现字符串的逆向输出.
        void put_stringr(const char s[]){codes}
    例如,将"SEC"显示为"CES".
    思路1:逆序输出字符串,因为数组传进字符串之后,就没法直接用sizeof量字符串长度
        ,可以等价于用一个数组装下s[]所有元素,然后逆序输出,但是太麻烦.
    思路2:先数一遍-字符串长度len,然后用for(int i = len - 1; i >= 0; i--)循环打印s[i]
*/
void put_stringr(const char s[]);

#include <stdio.h>

int main(void)
{
    put_stringr("CES");

    return 0;
}

void put_stringr(const char s[])
{
    int len = 0;

    for( ; s[len] != '\0'; len++)
    {
        /* 循环退出时,len表示第一个'\0'的下标,也是字符串(不含'\0'
        部分)的长度.对于空字符串,不会进入循环，也没有步进. */
    }

    putchar('\"');/* 打印左引号 */
    for(int i = len - 1; i >= 0; i--)/* 逆序输出,从到达'\0'之前最后一个下标逆序遍历 */
    {
        putchar(s[i]);
    }
    putchar('\"');/* 打印右引号 */

}