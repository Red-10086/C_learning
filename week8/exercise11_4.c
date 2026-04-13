/* 
    练习11-4 不使用下标运算符,编写如下函数,显示字符串s.
        void put_string (const char *s){codes}

    思路:不使用下标运算符,可以用解引用 *p.
        s指向首字符时
        s+i指向首字符后第i个字符
        需要设置截止
        何为截止?
        1使用库函数size_t strlen(const *s)返回字符串长度n(不含NULL),
        遍历索引i从0到n-1的字符
        2直接用s+i,i自增来遍历,直到*(s+i) == '\0';
        3s自增遍历(while(*s++);)

        本质上都是以字符串末位'\0'为结束标志.

        这二者都难以用到sizeof函数来量数组长度/字符串字面量长度来获得边界条件,
        因为传入的是指针,不是完整数组.
*/

#include <stdio.h>
#include <string.h>

void put_string(const char* s);

int main(void)
{
    char *s = "123456789";

    put_string(s);

    return 0;
}

void put_string(const char* s)
{
    // int i = 0;
    // while(*(s+i) != '\0')
    // {
    //     putchar(*(s+i));
    //     i++;
    // }

    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        putchar(*(s+i));
    }

    // int t = s;
    // while(*s++)
    // {
    //     putchar(*s);
    // }
}