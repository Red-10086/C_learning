#ifndef JUNIOR_MANAGE_H
#define JUNIOR_MANAGE_H

// 页长
enum {page_size = 16};

// 学生,成员:id,指向姓名的指针,成绩
typedef struct student
{
    int id;
    char *p_name;
    double score;
} junior;

// 接受一个字符型指针的地址,为所指指针开辟内存空间并读入任意长度的string(开启namespace),在函数内令一级指针指向该内存段
extern int create_name_space(char **p_str);

// 关闭所指指针的namespace
extern int destroy_name_space(char **p_str);

#endif