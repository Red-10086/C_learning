/* 
    编写如下 set_idx函数,接收元素类型为int型,元素个数为n的数组,并为所有元素赋值:
    值与下标相同.
        void set_idx(int *v, int n){...}
*/

#include <stdio.h>

enum Number { Length = 15 };

void set_idx(int *v, int n);

int main(void)
{
    int a[Length] = {0};

    set_idx(a, Length);

    for(int i = 0; i < Length; i++)
    {
        printf("a[%2d] == %d\n", i, a[i]);
    }

    return 0;
}

void set_idx(int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        v[i] = i;
        //等价于i[v] = i;
        //下标运算符的本质即指针算术后解引用:都等价于 *(v+i) = i;
    }
}