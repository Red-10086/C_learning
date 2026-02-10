#include <stdio.h>

#define Number 5

int vx[Number] = {0};
int idx[Number] = {0};

int search_idx(const int v[], int id[], int key, int n);

int main(void)
{
    for(int i = 0; i < Number; i++)
    {
        printf("vx[%d]:", i);
        scanf("%d", &vx[i]);
    }

    int ky = 0;
    printf("你要查找的元素是:");
    scanf("%d", &ky);

    //相符个数和顺序输出相符索引
    int count = search_idx(vx, idx, ky, Number);
    printf("数组vx[]中含有该元素的数量是:%d\n", count);

    for(int i = 0; i < count; i++)
    {
        printf("v[%d] == %d\n", idx[i], ky);
    }
    
    return 0;
}

int search_idx(const int v[], int id[], int key, int n)
{
    // v[]被遍历的数组,id[]存储相符（与key相等元素的）索引的数组,
    // key:查找标准,n:查找范围.
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(v[i] == key)
        {
            id[sum] = i;//存索引i，不是存值v[i]
            sum++;
        }
    }
    return sum;
}