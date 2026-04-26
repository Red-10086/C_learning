/* 
    练习13-3 改写清单13-2中的程序,将从文件读入的个人信息按身高排序后显示.

    清单13-2概述:
    以只读模式打开文件hw.dat
    判断打开是否成功:
        若打开失败,则程序结束,
        若打开成功,则用fscanf函数读一次:name(str),height(int),weight(double)
            每读一次,若成功读到3个项目,则
                将name,height,weight打印
                人数++
                总身高+=height
                总体重+=weight
            直到文件结束或读取错误(一次未读到3个项目),结束循环
        打印身高平均值和体重平均值
        关闭文件
    程序结束
    hw.dat内容:
    Aiba 160 59.3
    Kurata 162 51.6
    Masaki 182 76.5
    Tanaka 170 60.7
    Tsuji 175 83.9
    Washio 175 72.5

    思路:
    题目要求:1读文件 2将读到的个人信息排序后打印
    这就需要
        0声明合适的结构体,定义合适的结构体数组
        1只读模式打开hw.dat并用fscanf读取,用结构体数组暂存 
        2关闭文件hw.dat
        3将结构体数组按身高排序
        4顺序打印结构体数组
*/

#include <stdio.h>

enum {name_len = 128 , arr_len = 10};

typedef struct student
{
    char name[name_len];
    int height;
    double weight;
} senior;

// 按身高(升序)对senior数组排序
void sort_senior_height(senior *arr, int number);
// 交换x和y所指senior
void swap_senior(senior *x, senior *y);
// 打印数组arr下标为i的senior信息
void print_senior(senior *arr, int i);

int main(void)
{
    // 记录总人数
    int number = 0;

    // 暂存读到的个人信息
    senior arr[arr_len] = {0};

    // 只读模式打开文件hw.dat
    FILE *fp = fopen("hw.dat", "r");

    if(fp == NULL)
    {
        printf("读取失败\n");
    }
    else
    {
        // 成功读取的项目个数
        int successful_number = 0;
        for(int i = 0; i < arr_len; i++)
        {
            successful_number = 
            fscanf(fp, "%s%d%lf", arr[i].name, &arr[i].height, &arr[i].weight);

            // 成功读取并写入一个senior则计数并继续,否则退出
            if(successful_number == 3)
            {
                number++;
                continue;
            }
            else
            {
                break;
            }
        }

        // 如成功打开文件,最终关闭文件hw.dat
        fclose(fp);
    }

    // 读取并暂存完成,排序前打印
    printf("排序前:\n");
    for(int i = 0; i < number; i++)
    {
        print_senior(arr, i);
    }
    
    // 按身高排序
    sort_senior_height(arr, number);
    
    // 排序后打印
    printf("排序后:\n");
    for(int i = 0; i < number; i++)
    {
        print_senior(arr, i);
    }

    return 0;
}

// 按身高(升序)对senior数组排序
void sort_senior_height(senior *arr, int number)
{
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number - i - 1; j++)
        {
            if(arr[j].height > arr[j+1].height)
            {
                swap_senior(&arr[j], &arr[j+1]);
            }
        }
    }
}

// 交换指针x和指针y所指senior
void swap_senior(senior *x, senior *y)
{
    senior temp = *x;
    *x = *y;
    *y = temp;
}

// 打印数组arr下标为i的senior信息
void print_senior(senior *arr, int i)
{
    printf("第%d个同学的名字:%-10s\t", i+1, arr[i].name);
    printf("第%d个同学的身高(cm):%4d\t", i+1, arr[i].height);
    printf("第%d个同学的体重(kg):%4.2f\n", i+1, arr[i].weight);
}