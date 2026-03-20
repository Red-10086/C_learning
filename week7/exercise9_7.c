/* 
    练习9-7 编写如下函数，是字符串s显示n次.
        void put_stringn(const char s[], int n){codes}
        例如,若s和n分别为"ABC"he3,则显示"ABCABCABC".
        思路:也就是说遍历-打印n次输入的字符串s[]
        可以分为打印函数(打印一次)和打印次数函数
*/

#include <stdio.h>

void put_str(const char s[]);/* 只负责打印一次字符串 */
void put_stringn(const char s[], int n);

int main(void)
{
    char str[128] = {'\0'};
    int num = 0;

    printf("输入要重复的字符串:\n");
    scanf("%s", str);
    printf("输入要重复的次数:\n");
    scanf("%d", &num);// 可不能昏了头写成%c &num了,那样子'1'就不是1,'2'就不是2了

    put_stringn(str, num);

    return 0;
}

void put_str(const char s[])/* 只负责打印一次字符串 */
{
    int i = 0;

    while(s[i] != '\0')
    {
        putchar(s[i]);
        i++;/* 确保"打印头"一直向前-遍历,避免死循环 */
    }
}

void put_stringn(const char s[], int n)
{
    putchar('\"');//添加前引号
    for(int i = 0; i < n; i++)
    {
        put_str(s);
    }
    putchar('\"');//添加后引号
}