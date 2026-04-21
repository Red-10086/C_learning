#ifndef MY_STRUCT_SORT_H
#define MY_STRUCT_SORT_H

enum Const_numbers { name_Len = 64 , student_Number = 2};
enum Name_index { first, second, third };

typedef struct student 
{
    char name[name_Len];
    int height;
    float weight;
    long schols;
} Junior;

// 函数原型声明
extern void sort_Name(Junior *arr, int n);
extern void sort_Height(Junior *arr, int n);
extern void swap_Junior(Junior *x, Junior *y);

#endif