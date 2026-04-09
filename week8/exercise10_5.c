/* 
    练习10-5 如果用ary_set(&a[2], 2, 99)调用代码清单11中的ary_set函数会怎样呢?
    请试着执行一下,并探讨其结果.
    void ary_set(int v[], int n, int val)
    {
        int i;

        for (i = 0; i < n; i++)
            v[i] = val;
    }
*/

#include <stdio.h>

enum Number { Length = 10};

void ary_set(int v[], int n, int val);

int main(void)
{
    int a[Length] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //进入被调函数内:for (i = 0; i < n; i++){codes}即*(v+i) = val;n=2;即i = 0和i=1,
    ary_set(&a[2], 2, 99);//对应a[2]和a[3]赋值为99

    for(int i = 0; i < Length; i++)
    {
        printf("a[%d] == %d\n", i, a[i]);
    }
    
    return 0;
}

void ary_set(int v[], int n, int val)
{
    int i;

    for (i = 0; i < n; i++)
    {
        v[i] = val;// *(v+i) = val;
    }
}