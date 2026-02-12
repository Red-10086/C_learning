#include <stdio.h>

int main(void)
{
    static double arr[5];
    // static double a = 0.0,然后用a给arr[i]赋值不可行，
    // 因为仅仅传递了值，并没有变arr[]元素的存储期

    for(int i = 0; i < 5; i++)
    {
        printf("arr[%d] == %lf\n", i, arr[i]);
    }

    return 0;
}