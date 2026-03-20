/* 
    编写如下函数,返回字符串s中字符c的个数(没有则返回0)
*/

#include <stdio.h>

int str_chnum(const char s[], int c);

int main(void)
{
    int c = 0;
    int result = 0;
    char str[128] = {'\0'};


    printf("请输入字符串:\n");
    scanf("%s", str);
    printf("请输入要查找的单字符:\n");
    scanf(" %c", &c);/* 空格%c 清空空白符号 */

    result = str_chnum(str, c);

    printf("字符串 \"%s\" 中,字符'%c'出现了%d次", str, c, result);

    return 0;
}

int str_chnum(const char s[], int c)
{
    int index = 0;/* 下标 */
    int num = 0;/* 字符c的个数 */

    while(s[index] != '\0')/* 遍历字符串,到尾 ('\0') 即止 */
    {
        //index++;索引自增在前则下标0永远不会被检查,逻辑错误导致吞头

        if(s[index] == c)/* 找到就计数一次 */
        {
            num++;
        }

        index++;/* 难怪最经典的for循环,设计步进在最后 */
    }

    return num;
}