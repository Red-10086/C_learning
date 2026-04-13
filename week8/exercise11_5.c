/* 
    不使用下标运算符,编写如下函数,返回字符串s种字符c的个数(若不存在,则为0).
        int str_chnu(const char*s, int c){codes}
    
    思路:仍然是s自增遍历到'\0',只是每轮做的事变成了检查字符是否相等
*/

#include <stdio.h>

int str_chnum(const char *s, int c);

int main(void)
{
    printf("“strchr 返回 char 却接受 const char，是 C 语言对历史的妥协。”\n");
    char *s = "Onion";
    char tmp[128] = {0};
    char ch = 0;

    printf("请输入字符串:");
    scanf("%s", tmp);/* 按&tmp[0]写入 */
    
    s = tmp;/* 重定向 */

    printf("请输入要查找的字符:");
    scanf("%c", &ch);

    printf("字符'%c'有%d个", ch, str_chnum(s, ch));

    return 0;
}

int str_chnum(const char *s, int c)
{
    int result = 0;/* 字符串s中含有字符c的个数, 默认没有 */

    /* 错误案例:吞头,s自增后,s指向下一个字符,永远是下一个字符参与判断 */
    // while(*s++) 解引用检查,自增,s以自增后的值参与运算;成也因此:strlen函数,败也因此:'吞头'
    // {
    //     if(*s == c)
    //     {
    //         result++;
    //     }
    // }
    
    /* 以'\0'为结束标志,不支持检查'\0' */
    for(int i = 0; *(s+i) != '\0'; i++)
    {
        if(*(s + i) == c)
        {
            result++;
        }
    }

    return result;
}