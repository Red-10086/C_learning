/* 
学生信息系统（考三种类型+struct + 三 alloc 综合）
描述:
编写程序，管理学生信息。每个学生有：学号（int）、姓名（char* 动态字符串）、成绩（double）。
第一阶段：读取正整数 N，录入 N 个学生。姓名长度不定，用 malloc 动态分配。
第二阶段：读取正整数 M，追加 M 个学生。学生数组用 realloc 扩容。
第三阶段：输出所有 N+M 个学生的信息。

输入格式:
2
1001 Alice
85.5
1002 Bob
90.0
1
1003 Charlie
78.5

输出格式:
1001 Alice 85.50
1002 Bob 90.00
1003 Charlie 78.50

要求:
项目	            要求
学生结构体	        struct Student { int id; char *name; double score; };
学生数组	        struct Student *arr，先用 calloc 分配 N 个（清零初始化）
姓名字符串	        每个姓名用 malloc 单独分配，长度按实际输入
扩容	            realloc 把学生数组扩到 N+M 个
释放	            先 free 每个学生的 name，再 free 学生数组
失败处理	        任何 alloc 失败输出 Allocation failed 并返回 1
*/

/* 
思路:
1先定义学生结构体
struct Student {
    int id;
    char *name;     // 动态字符串，不是 char name[20]
    double score;
};
2读学生个数N,calloc开辟内存空间(学生个数N*sizeof(学生结构体)),
通过scanf和临时变量/临时数组接受输入(未来可以加输入检查,现在不管)
    开辟失败即free并退出
    开辟成功...待议

3读追加个数M,recalloc开辟新内存空间(学生个数(N+M)*sizeof(学生结构体))
    开辟失败即free并退出
    开辟成功...待议
4do something

5free

因为姓名长度不定,用 malloc 动态分配,相对于"结构体内嵌char数组"和"维护一个全局的二维char数组"
两种用char数组来装长度不定的名字的方案,占空比更优,且可以按需扩容。

*/

#include <stdio.h>
#include <stdlib.h>

// 学生,成员:id,指向姓名的指针,成绩
typedef struct student
{
    int id;
    char *p_name;
    double score;
} junior;

int main(void)
{


    return 0;
}