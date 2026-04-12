/* 
    练习11-2 在代码清单1-4中,各数组(指针数组和二维数组)的字符串个数3是作为常量
    嵌在程序(for语句的控制表达式)中的.请编写一段程序,将其改写为通过计算求出.

    清单11-4:
    #include <stdio.h>

    int main(void)
    {
        int  i;
        char a[][5] = {"LISP", "C", "Ada"};
        char *p[]   = {"PAUL", "X", "MAC"};

        for (i = 0; i < 3; i++)
            printf("a[%d] = \"%s\"\n", i, a[i]);

        for (i = 0; i < 3; i++)
            printf("p[%d] = \"%s\"\n", i, p[i]);

        return 0;
    }

    思路1:
        子数组名a[i]会退化成指针, p[i]就是指向第i个字符串的指针.
        循环:i从0到n(设置最大值防止死循环):
            (内层循环)每轮自a[i]或p[i]所指元素(*a[i] 或 *p[i])开始,遍历字符串,
                直到'\0',
            计数一次并进入下一轮循环
        但是外循环没有明确的结束条件:怎么判断不是字符串?C没有type函数.
    
    思路2:
        数格子.
        数组实现的字符串是连续排列的(连续有序的字符型数组):
            sizeof(a)/sizeof(a[0]),可以得到a中有几个char a[][5]
        指针实现的字符串无法保证字符串间排列的顺序和连续性.
        但是指针数组是连续的(连续有序的指针变量):
            sizeof(p)/sizeof(p[0]),可以得到a中有几个char *p

*/

#include <stdio.h>

int main(void)
{
    char a[][5] = {"LISP", "C", "Ada"};/* 字符串的数组:   元素为字符型数组 */
    char * p[]  = {"PAUL", "X", "MAC"};/* 字符型指针的数组:元素为字符型指针 */

    int count_of_a = sizeof(a) / sizeof(a[0]);
    int count_of_p = sizeof(p) / sizeof(p[0]);

    /* codes */

    return 0;
}