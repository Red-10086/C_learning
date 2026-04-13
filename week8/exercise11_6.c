/* 
    练习11-6 不使用下标运算符,编写如下函数,若字符串s中含有字符c(若含有多个,
    以先出现的为准),则返回指向该字符串的指针,否则返回空指针.
        char *str_chr(const char *s, int c){codes}
*/

/* 若字符串s中含有字符c(若含有多个,以先出现的为准),
则返回指向该字符串的指针,否则返回空指针 */
#include <stdio.h>

char *str_chr(const char *s, int c);

int main(void)
{
    const char *str = "Filosofia";/* 查找的字符串 */
    char ch = 0;/* 要查找的字符 */
    char tmp = 0;

    int index = 0;/* 表示字符的位置:第index个(首字符为第1个) */

    // printf("请输入字符串:");
    // scanf("%s", str);
    printf("请输入要查找的字符:");
    scanf(" %c", &ch);

    // tmp = *str_chr(str, ch);危险,函数可能返回NULL,对NULL解引用立刻就会崩溃
    const char *chpointer = NULL;/* 指向字符串中某字符的指针 */
    
    chpointer = str_chr(str, ch);/* 必须用const char*类型来接收 */

    if(chpointer != NULL)/* 避免对空指针解引用 */
    {
        tmp = *chpointer;
        index = chpointer - str + 1;
        printf("字符'%c'找到了,是字符串\"%s\"中的第%d个字符.\n", tmp, str, index);
    }
    else
    {
        printf("没找到.");
    }

    return 0;
}

char *str_chr(const char *s, int c)
{
    char *result = NULL;/* 默认置NULL */

    while(*s)
    {
        if(*s == c)/* 查找,找到即定向并退出-以先出现的为准 */
        {
            /* 危险:将承诺为const的内存区域的坐标赋给了"可读可写"的普通指针 */
            /* 但题目要求我返回char *类型,没有办法,将const char*类型直接返回
            也是隐式转换,所以只能先显式转换,在调用时直接使用const char*类型接收来
            "打补丁" */
            result = (char *)s;
            break;
        }

        s++;
    }

    return result;/* 找到了就返回指向第一个c的指针,否则返回NULL */
}

