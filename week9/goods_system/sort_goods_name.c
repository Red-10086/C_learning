#include <stdio.h>
#include "my_struct_sort.h"
#include <string.h>

void sort_goods_name(Junior *arr_struct, int n);
int should_Swap_string_Is_Not_Ascending(const char *u, const char *v);

int main(void)
{
    Junior arr[student_Number] = {0};
    for(int i = 0; i < student_Number; i++)
    {
        // name是数组名,会退化,不需要&
        printf("请输入第%d个同学的名字:\n", i+1);        
        scanf("%s", arr[i].name);
    }
    
    // 排序前打印
    printf("排序前:\n");
    for(int i = 0; i < student_Number; i++)
    {
        printf("第%d个同学的名字:%-10s\n", i+1, arr[i].name);
    }

    sort_goods_name(arr, student_Number);

    // 排序后打印
    printf("排序后:\n");
    for(int i = 0; i < student_Number; i++)
    {
        printf("第%d个同学的名字:%-10s\n", i+1, arr[i].name);
    }

    return 0;
}

// 按 姓名成员的首字母顺序, 为结构体数组内前n个结构体排序(按A-Z的升序)
void sort_goods_name(Junior *arr_struct, int n)
{
    // 首字母大写检查
    for(int i = 0; i < n; i++)
    {
        if(arr_struct[i].name[first] >= 'a' && arr_struct[i].name[first] <= 'z' )
        {
            arr_struct[i].name[first] += ('A' - 'a');
        }
    }

    // 冒泡排序
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            // 首字母顺序:升序该用前>后作为交换触发条件(逆序-交换)!!!
            // 先前错误写法:if(arr_struct[ j ].name[first] < arr_struct[ j+1 ].name[first] )
            // if(arr_struct[ j ].name[first] > arr_struct[ j+1 ].name[first] )
            
            // 如果(不是升序){就要交换}
            if( should_Swap_string_Is_Not_Ascending(arr_struct[j].name, arr_struct[j+1].name) )
            {
                swap_Junior(&arr_struct[j], &arr_struct[j+1]);
            }
        }
    }
}

int should_Swap_string_Is_Not_Ascending(const char *u, const char *v)
{
    // 默认逆序
    int need_Swap = 1;
    // 定义两个只读指针
    const char *p_u = NULL, *p_v = NULL;
    char u_temp_name[name_Len], v_temp_name[name_Len];

    // 复制u、v字符串到“临时字符串数组”中
    p_u = strcpy(u_temp_name, u);
    p_v = strcpy(v_temp_name, v);

    // 小写英文字母一律转大写
    for( int i = 0 ; u_temp_name[i] != '\0' ; i++ )
    {
        if(u_temp_name[i] >= 'a' && u_temp_name[i] <= 'z' )
        {
            u_temp_name[i] += ('A'-'a');
        }
    }
    for( int i = 0 ; v_temp_name[i] != '\0' ; i++ )
    {
        if(v_temp_name[i] >= 'a' && v_temp_name[i] <= 'z' )
        {
            v_temp_name[i] += ('A'-'a');
        }
    }


    // 逐个比较首字母、次字母等,直到其中一个姓名结束
    for( ; *p_u != '\0' && *p_v != '\0' ; p_u++, p_v++)
    {
        if(*p_u < *p_v)
        {
            need_Swap = 0;
            break;
        }
        else if(*p_u > *p_v)
        {
            need_Swap = 1;
            break;
        }
        // 首字母相同则继续读次字符进行比较,直到一个结束
    }

    // 其中一个字符串读取结束了
    // 全为'\0'即重名,说顺序也好,逆序也罢,无所谓了
    if( *p_u == '\0' && *p_v == '\0' )
    {
        need_Swap = 0;
    }
    // 字符串u先结束
    else if( *p_u == '\0' && *p_v != '\0' )
    {
        need_Swap = 0;
    }
    // 字符串v先结束
    else if( *p_u != '\0' && *p_v == '\0' )
    {
        need_Swap = 1;
    }

    return need_Swap;
}