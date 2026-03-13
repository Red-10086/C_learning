#include <stdio.h>

void bubble(int ar[], int n)/* ar数组名,n为数组长/需要排序元素总长 */;

int main(void)
{
    /* 待排序数组和数组长度 */
    int Sort[] = {53, 10, 55, 99, 60, 34, 78, 91, 74, 79, 72, 20, 47, 92, 1, 24, 33, 84, 54, 97, 59, 27, 51, 43, 66, 9, 67, 0, 29, 21, 28, 18, 17, 30, 58, 11, 68, 35, 80, 71, 31, 42, 52, 64, 86, 2, 45, 44, 8, 57};
    int Len = sizeof(Sort)/sizeof(int);
    
    /* 排序前的数组,对比 */
    printf("排序前:\n");
    for(int k = 0; k < Len; k++)
    {
        printf("%4d", Sort[k]);  // 优化输出格式
        if ((k + 1) % 10 == 0) printf("\n");  // 每 10 个换行
    }
    putchar('\n');
    
    /* 冒泡排序 */
    bubble(Sort, Len);
    
    /* 打印排序后的结果 */
    printf("排序后:\n");
    for(int k = 0; k < Len; k++)
    {
        printf("%4d", Sort[k]);  // 优化输出格式
        if ((k + 1) % 10 == 0) printf("\n");  // 每 10 个换行
    }
    putchar('\n');

    return 0;
}

void bubble(int ar[], int n)/* ar数组名,n为数组长/需要排序元素总长 */
{
    /* 排序用哑指标 */
    int i = 0;
    int j = 0;
    int flags = 0;

    /* 冒泡排序 */
    for(i = 0; i < n-1; i++, flags = 0)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                /* 相邻逆序就交换 */
                int tmp = ar[j+1];
                ar[j+1] = ar[j];
                ar[j] = tmp;

                /* 交换一次就计数一次 */
                flags++;
            }
        }
        if(flags == 0)/* 如果始终都没有交换,说明已经有序 */
        {
            break;
        }
    }
}