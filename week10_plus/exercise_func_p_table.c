/* 
函数指针-表驱动-策略分发
测验 2：函数指针数组分发（为菜单框架预演）
任务:
实现一个极简命令行菜单系统，支持 4 个选项：

选项	        动作
1	    显示提示 "Add student"
2	    显示提示 "Delete student"
3	    显示提示 "Show all"
0	    显示提示 "Exit" 并结束程序

写一个无限循环，每次循环:
打印选项列表；
读取用户输入的一个整数；
通过函数指针数组直接调用对应函数——main 中不得出现 switch 或 if-else 来根据输入分发动作。
强制要求
必须定义一个函数指针数组，数组元素指向上述四个动作函数。
必须处理非法输入（输入越界时通过函数指针数组的边界检查或哨兵机制提示错误，而非用 switch 的 default）。
四个动作函数必须是无参、返回 void 类型（或返回 int 表示是否退出主循环，由你决定，但分发逻辑仍须通过函数指针完成）。

*/

#include <stdio.h>

// typedef void (*func_p)(void);

typedef struct student{
    int age;
    long id;
} junior;

typedef int (*s_func)(junior *, size_t);

// 
void func_menu(s_func);

// add_student函数:追加学生
int func_add_student(junior *arr_student, size_t arr_size);

// delete_student函数:删除学生
int func_delete_student(junior *arr_student, size_t arr_size);

// show all函数:展示所有,需要传入数组和数组长度
int func_show_all(junior *arr_student, size_t arr_size);

// 退出函数
int func_exit(junior *arr_student, size_t arr_size);

enum { arr_len = 6};

s_func func_table[] = { func_exit, func_add_student, func_delete_student, func_show_all };

int main(void)
{
    junior arr_student[arr_len] = {0};

    int choice = 1;
    do
    {
        printf("请输入:\n");
        printf("1:\tAdd\tstudent\n");
        printf("2:\tDelete\tstudent\n");
        printf("3:\tShow\tall\n");
        printf("0:\tExit\n");
        int c = scanf(" %d", &choice);

        // 如果:c == 0,没读到整数
        if(c == 0)
        {
            printf("输入有误,请重试\n");
        }
        // 如果读到了整数,但是读到的下标 choice > func_table长度(向右超表) 或 choice < 0(向左超表)
        else if(choice < 0 || choice >= sizeof(func_table)/sizeof(func_table[0]))
        {
            printf("输入有误,请重试\n");
        }
        else
        {
            // 表头:func_table[choice]
            func_table[choice](arr_student, arr_len);
        }

    }while(choice != 0);
    
    return 0;
}

// add_student函数:追加学生
int func_add_student(junior *arr_student, size_t arr_size)
{
    int c = arr_student[arr_size-1].age;
    c += c;
    
    int success = 1;
    printf("添加成功\n");

    return success;
}
// delete_student函数:删除学生
int func_delete_student(junior *arr_student, size_t arr_size)
{
    int c = arr_student[arr_size-1].age;
    c += c;
    
    int success = 1;
    printf("删除成功\n");

    return success;
}
// show all函数:展示所有,需要传入数组和数组长度
int func_show_all(junior *arr_student, size_t arr_size)
{
    int c = arr_student[arr_size-1].age;
    c += c;
    
    int success = 1;
    printf("展示成功\n");

    return success;
}
// 退出函数
int func_exit(junior *arr_student, size_t arr_size)
{
    int c = arr_student[arr_size-1].age;
    c += c;
    
    int success = 1;
    printf("退出成功\n");

    return success;
}

/* 
测试结果:
PS C:\Users\asus\Desktop\Hello\C_Learning\week10_plus> cd "c:\Users\asus\Desktop\Hello\C_Learning\week10_plus\" ; if ($?) { gcc -Wall -Wextra -Werror exercise_func_p_table.c -o exercise_func_p_table } ; if ($?) { .\exercise_func_p_table }
请输入:
1:      Add     student
2:      Delete  student
3:      Shoe    all
0:      Exit
1
添加成功
请输入:
1:      Add     student
2:      Delete  student
3:      Shoe    all
0:      Exit
2
删除成功
请输入:
1:      Add     student
2:      Delete  student
3:      Shoe    all
0:      Exit
3
展示成功
请输入:
1:      Add     student
2:      Delete  student
3:      Shoe    all
0:      Exit
4
PS C:\Users\asus\Desktop\Hello\C_Learning\week10_plus> cd "c:\Users\asus\Desktop\Hello\C_Learning\week10_plus\" ; if ($?) { gcc -Wall -Wextra -Werror exercise_func_p_table.c -o exercise_func_p_table } ; if ($?) { .\exercise_func_p_table }
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
1
添加成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
2
删除成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
3
展示成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
4
PS C:\Users\asus\Desktop\Hello\C_Learning\week10_plus> cd "c:\Users\asus\Desktop\Hello\C_Learning\week10_plus\" ; if ($?) { gcc -Wall -Wextra -Werror exercise_func_p_table.c -o exercise_func_p_table } ; if ($?) { .\exercise_func_p_table }
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
1
添加成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
2
删除成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
3
展示成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
4
PS C:\Users\asus\Desktop\Hello\C_Learning\week10_plus> cd "c:\Users\asus\Desktop\Hello\C_Learning\week10_plus\" ; if ($?) { gcc -Wall -Wextra -Werror exercise_func_p_table.c -o exercise_func_p_table } ; if ($?) { .\exercise_func_p_table }
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
1
添加成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
2
删除成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
3
展示成功
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
4
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
5
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
6
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
7
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
8
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
9
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
-1
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
-2
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
^Z
输入有误,请重试
请输入:
1:      Add     student
2:      Delete  student
3:      Show    all
0:      Exit
0
退出成功
PS C:\Users\asus\Desktop\Hello\C_Learning\week10_plus> 
*/