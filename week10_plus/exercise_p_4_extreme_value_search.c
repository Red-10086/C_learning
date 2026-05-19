/* 
测验：通用极值查找器（函数指针回调）
任务
写一个在一维 int 数组中查找“极端元素”的通用函数。
什么是“极端”不由该函数决定，而由调用者通过函数指针传入的比较逻辑决定。
在 main 中，用同一个查找函数，配合三种不同的比较规则，分别找出：
最大值
最小值
绝对值最大的值
强制约束
必须用 typedef 给该比较函数指针类型起别名。
查找函数内部不得出现 if-else 或 switch 来区分“找最大/最小/绝对值”等逻辑——所有差异必须来自传入的函数指针。
不得使用全局变量传递规则或结果

思路:
    接收一个一维数组(数组名,长度),和"查找行为本身".
    "查找模式"这一信息不在函数内决定,而是由调用方传来的函数指针蕴含.
*/

#include <stdio.h>
#include <math.h>

typedef int (*m_func)(const int *arr, size_t arr_length);

// 数组最大值
int max_value(const int *arr, size_t arr_length);

// 数组最小值
int min_value(const int *arr, size_t arr_length);

// 数组绝对值最大值
int max_absolute_value(const int *arr, size_t arr_length);

// 根据注入的策略,获取一个数组中前n个元素中的极值
int extreme_value(const int *arr, size_t arr_length, m_func p);

int arr[] = {-5, -28, -10, 31, 23, -48, 46, -73, -97, -74, 39, 36, 35, 7, -38};

int main(void)
{
    int extr_1 = extreme_value(arr, sizeof(arr)/sizeof(int), &max_value);
    int extr_2 = extreme_value(arr, sizeof(arr)/sizeof(int), &min_value);
    int extr_3 = extreme_value(arr, sizeof(arr)/sizeof(int), &max_absolute_value);

    printf("%d\n", extr_1);
    printf("%d\n", extr_2);
    printf("%d\n", extr_3);

    return 0;
}

// 数组最大值
int max_value(const int *arr, size_t arr_length)
{
    // int maxi = 0有风险,万一全比0小就会得到错值.
    int maxi = arr[0];

    for(size_t i = 1; i < arr_length; i++)
    {
        maxi = maxi > arr[i] ? maxi : arr[i];
    }

    return maxi;
}

// 数组最小值
int min_value(const int *arr, size_t arr_length)
{
    int mini = arr[0];

    for(size_t i = 1; i < arr_length; i++)
    {
        mini = mini < arr[i] ? mini : arr[i];
    }

    return mini;
}

// 数组绝对值最大值
int max_absolute_value(const int *arr, size_t arr_length)
{
    // max_absolutely表示绝对值最大的数组元素
    int max_absolutely = arr[0];

    for(size_t i = 1; i < arr_length; i++)
    {
        max_absolutely = (long long )max_absolutely * (long long)max_absolutely > (long long)arr[i] * (long long)arr[i] ? max_absolutely : arr[i];
    }

    return max_absolutely;
}

// 根据注入的策略,获取一个数组中前n个元素中的极值
int extreme_value(const int *arr, size_t arr_length, m_func p)
{
    int extreme_value = 0;

    extreme_value = p(arr, arr_length);

    return extreme_value;
}
