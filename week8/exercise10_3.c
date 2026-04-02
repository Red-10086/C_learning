/* 
    练习0-3 编写如下函数,将n1/n2/n3指向的三个int型整数按升序排列.
*/

#include <stdio.h>

enum number {num = 3};

void sort3(int *n1, int *n2, int *n3);
void swap(int *px, int *py);

int main(void)
{
    int x,y,z;
    printf("x:"); scanf("%d", &x);
    printf("y:"); scanf("%d", &y);
    printf("z:"); scanf("%d", &z);

    sort3(&x, &y, &z);

    printf("升序排列:\n");
    printf("x=%d\n", x);
    printf("y=%d\n", y);
    printf("z=%d\n", z);

    return 0;
}

void sort3(int *n1, int *n2, int *n3)
{
    // // *n1 *n2 升序排列
    // if(*n1 > *n2)
    // {
    //     swap(n1, n2);/* 交换n1/n2所指对象的值 */
    // }
    
    // // *n2 *n3 升序排列
    // if(*n2 > *n3)
    // {
    //     swap(n2, n3);/* 交换n2/n3所指对象的值 */
    // }
    // 3个及以上的排序可不是简单的一轮交换就能搞定的.

    int sort[num] = {*n1, *n2, *n3};/* 某种程度上来说,也是值传递 */

    for(int i = 0; i < num; i++)
    {
        for(int k = 0; k < num-i-1; k++)
        {
            if(sort[k] > sort[k+1])
            {
                int temp  = sort[k];
                sort[k]   = sort[k+1];
                sort[k+1] = temp;
            }
        }
    }

    *n1 = sort[0];
    *n2 = sort[1];
    *n3 = sort[2];
}