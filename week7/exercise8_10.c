/* 
    练习 8-10 改写代码清单8-0的程序,将数字字符的出现次数用并排的 * 表示.
    注意和代码清单5-2和练习5-9一样
    清单8-10:
    #include <stdio.h>

    int main(void)
    {
        int i, ch;
        int cnt[10] = {0};		

        while ((ch = getchar()) != EOF) {
            if (ch >= '0' && ch <= '9')
                cnt[ch - '0']++;
        }

        puts("数字字符的出现次数");
        for (i = 0; i < 10; i++)
            printf("'%d'：%d\n", i, cnt[i]);

        return 0;
    }
*/
#include <stdio.h>

int main(void)
{
    int ch = 0;/* 临时变量 */
    int counts[10] = {0};/* 统计字符出现次数 */

    while(1)
    {
        ch = getchar();
        if(ch >= '0' && ch <= '9')
        {
            counts[ch - '0']++;/* '某数字' 对应数组下标 某数字 */
        }
        else if(ch == EOF)
        {
            break;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        printf("数字字符\'%d\'出现次数为 %d :", i, counts[i]);
        for(int j = 0; j < counts[i]; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}