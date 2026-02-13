#include <stdio.h>

int counts[5] = {1,2,3,4,5};

void print_histogram(const int arr[]);/* 直方图打印函数 */
void put_chars(int n, char c);/* 打印字符函数 */

int main(void)
{
    print_histogram(counts);

    return 0;
}

// n打印次数 c打印字符
void put_chars(int n, char c)//char类型应该用 '*' 而非 "*" 这是一个问题点
{
    for(int i = 0; i < n; i++)
    {
        putchar(c);
    }
    putchar('\n');
}

void print_histogram(const int arr[])
{
    printf("直方图:\t\n");    
    printf("不及格:\t");    put_chars(arr[0], '*');
    printf("刚及格\t");     put_chars(arr[1], '*');
    printf("中等:\t");      put_chars(arr[2], '*');
    printf("良好:\t");      put_chars(arr[3], '*');
    printf("优秀:\t");      put_chars(arr[4], '*');
}