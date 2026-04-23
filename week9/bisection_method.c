#include <stdio.h>

enum { len = 16 };

int *bisection(int *s, int keyword);

int main(void)
{
    int arr[len] = {0};
    for(int i = 0; i < len; i++)
    {
        arr[i] = 3 * i;
    }
    
    int *des_ptr = bisection(arr, 29);

    if(des_ptr == NULL)
    {
        printf("始终没找到\n");
    }
    else 
    {
        printf("找到了,索引值为%d\n", *des_ptr);
    }
    
    return 0;
}

int *bisection(int *s, int keyword)
{
    int number = 0;
    int found_it = 0;
    int *left = s;
    int *right = s+len-1;
    int *mid = left + (right - left)/2 ;
    int *des = NULL;


    for(int i = 0; found_it != 1 && i < len; i++/* , number++ */)
    {
        // 找到了-目标地址des就是mid
        if( keyword == *mid )
        {
            found_it = 1;
            des = mid;
            continue;
        }
        // 该在右边,左边界变为mid,右边界不变
        else if( keyword > *mid )
        {
            left = mid+1;
            mid = left + (right - left)/2;
        }
        // 该在左边,右边界变为mid,左边界不变
        else if( keyword < *mid )
        {
            right = mid-1;
            mid = left + (right - left)/2;
        }
        // 始终没找到
        if( left > right )
        {
            des = NULL;
            break;
        }
    }
    printf("总共找了%d次\n", number);

    return des;
}