#include <stdio.h>

enum {name_len = 128 , arr_len = 10};

typedef struct student
{
    char name[name_len];
    int height;
    double weight;
} senior;

// 交换指针x和指针y所指senior
void swap_senior(senior *x, senior *y)
{
    senior temp = *x;
    *x = *y;
    *y = temp;
}

// 按身高(升序)对senior数组排序
void sort_senior_height(senior *arr, int number)
{
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number - i - 1; j++)
        {
            // 隔离问题,逐步debug,发现问题在此:冒泡逻辑写错了,写丢了一个"+1"
            // if(arr[j].height > arr[j].height)
            if(arr[j].height > arr[j+1].height)
            {
                swap_senior(&(arr[j]), &(arr[j+1]));
            }
        }
    }
}


void print_senior(senior *arr, int i)
{
    printf("第%d个同学的名字:%-10s\t", i+1, arr[i].name);
    printf("第%d个同学的身高(cm):%4d\t", i+1, arr[i].height);
    printf("第%d个同学的体重(kg):%4.2f\t", i+1, arr[i].weight);
}

int main(void)
{
    senior arr[arr_len] = {
        {"Aiba", 160, 59.3},
        {"Kurata", 162, 51.6},
        {"Masaki", 182, 76.5},
        {"Tanaka", 170, 60.7},
        {"Tsuji", 175, 83.9},
        {"Washio", 175, 72.5}
    };
    int number = 6;
    sort_senior_height(arr, number);
    for(int i = 0; i < number; i++)
    {
        print_senior(arr, i);
    }

    return 0;
}