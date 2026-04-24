#ifndef MY_STRUCT_SORT_H
#define MY_STRUCT_SORT_H

enum Const_numbers { name_Len = 64 , student_Number = 5};
enum Name_index { first, second, third };

typedef struct student 
{
    char name[name_Len];
    int height;
    float weight;
    long schols;
} junior;

// 函数原型声明
extern void sort_goods_name(junior *arr, int n);
extern void sort_Height(junior *arr, int n);
extern void swap_junior(junior *x, junior *y);
extern int should_Swap_string_Is_Not_Ascending(const char *u, const char *v);

#endif