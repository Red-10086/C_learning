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
// #include "junior_manage.h"

// 页长
enum {page_size = 16};

// 学生,成员:id,指向姓名的指针,成绩
typedef struct student
{
    int id;
    char *p_name;
    double score;
} junior;

// 清空输入缓冲区
void clear_input();

// 接受一个字符型指针的地址,为所指指针开辟内存空间并读入任意长度的string(开启namespace),在函数内令一级指针指向该内存段
int create_name_space(char **p_str);

// 关闭所指指针的namespace
int destroy_name_space(char **p_str);



int main(void)
{
    // 初始个数
    int N = 0;
    // 追加个数
    int M = 0;
    // 总个数
    int Sum = 0;
    junior *arr = NULL;
    junior *temp_arr = NULL;

    
    // 开辟空间装结构体
    printf("请输入要录入的学生个数:\n");
    scanf("%d", &N);
    temp_arr = (junior *)calloc(N, sizeof(junior));
    
    if(temp_arr == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    else
    {
        Sum += N;
        arr = temp_arr;
    }
    
    // 赋值
    for(int i = 0; i < N; i++)
    {
        printf("请输入第%d个学生的学号:\n", i+1);       scanf("%d", &arr[i].id);
        printf("请输入第%d个学生的成绩:\n", i+1);       scanf("%lf", &arr[i].score);
        
        printf("请输入第%d个学生的姓名:\n", i+1);
        clear_input();
        int c = create_name_space(&arr[i].p_name);
        if( c == EOF )
        {
            printf("内存分配失败\n");
            destroy_name_space(&arr[i].p_name);
            free(arr);
            return 1;
        }
    }

    // 询问是否追加
    int append = -1;
    while(1)
    {
        printf("要追加学生吗?追加请输入1,不追加请输入0\n");
        scanf("%d", &append);
        if( append == 1 || append == 0 )
        {
            break;
        }
        else
        {
            printf("输入有误,请重新输入\n");
        }
    }
    if( append == 1 )
    {
        printf("请输入要追加的学生个数:\n");
        scanf("%d", &M);
        temp_arr = (junior *)realloc(arr, (M+N)*sizeof(junior));
        if(temp_arr == NULL)
        {
            printf("内存分配失败\n");
            return 1;
        }
        else
        {
            Sum += M;
            arr = temp_arr;
        }

        // 赋值
        for(int i = N; i < M+N; i++)
        {
            printf("请输入第%d个学生的学号:\n", i+1);       scanf("%d", &arr[i].id);
            printf("请输入第%d个学生的成绩:\n", i+1);       scanf("%lf", &arr[i].score);
            
            printf("请输入第%d个学生的姓名:\n", i+1);
            clear_input();
            int c = create_name_space(&arr[i].p_name);
            if( c == EOF )
            {
                printf("内存分配失败\n");
                destroy_name_space(&arr[i].p_name);
                free(arr);
                return 1;
            }
        }
    }




    puts("已录入学生:\n");
    for(int i = 0; i < Sum; i++)
    {
        printf("%-15d", arr[i].id);
        printf("%-6.2lf", arr[i].score);
        printf("%s\n", arr[i].p_name);
    }


    for(int i = 0; i < Sum; i++)
    {
        destroy_name_space(&arr[i].p_name);
    }
    free(arr);
    arr = NULL;
    temp_arr = NULL;

    return 0;
}

// 清空输入缓冲区
void clear_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// 接受一个字符型指针的地址,为所指指针开辟内存空间并读入任意长度的string(开启namespace),在函数内令一级指针指向该内存段
int create_name_space(char **p_str)
{
    // 判断是否正常工作
    int is_normal = 1;

    // 缓冲区首地址
    char *buf = NULL;
    char *temp_buf = NULL;

    // 偏移头
    char *offset_header = NULL;

    // 总页数
    int page_num = 0;

    // 分配内存空间
    temp_buf = (char *)malloc(page_size);

    if( temp_buf == NULL )
    {
        free(buf);
        buf = NULL;
        is_normal = EOF;
        return is_normal;
    }

    buf = temp_buf;
    offset_header = buf;
    page_num++;

    // 偏移头逐页偏移,并且紧随着新页开辟
    // offset表示偏移头相对buf首地址的偏移量
    int offset = 0;

    // 表示是否要退出读取循环
    int should_out_of_read = 0;
    for(; should_out_of_read == 0 ;)
    {
        // 检查:如果剩余空间不够再写一页了,只额外开辟一页
        if(offset_header + page_size > buf +page_num * page_size )
        {
            temp_buf = realloc(buf, (page_num+1) * page_size);
            if(temp_buf == NULL)
            {
                free(buf);
                is_normal = EOF;
                return is_normal;
            }
            page_num++;
            buf = temp_buf;
            offset_header = buf + offset;
            // 不好的方案,纯粹靠数字巧合,脆弱且强耦合:
            // offset_header = buf + (page_num - 1) * page_size;
        }
        
        // 表示是否要退出页内循环,默认不退出
        int should_out_of_page = 0;
        // 页内循环,遇到'\r'或者'\n'就退出
        // offset_header通常读16次(一页),最后一次读完,offset_header++,指向下一页首
        for(char *End = offset_header + page_size;
            offset_header < End && should_out_of_page == 0;
            offset_header++)
        {
            int c = fgetc(stdin);
            // 如果接收到EOF,buf末尾补0,退出
            if(c == EOF)
            {
                *offset_header = '\0';
                should_out_of_page = 1;
                should_out_of_read = 1;
                break;
            }
            // 没接收到EOF,正常用偏移头给buf写值
            *offset_header = c;
            // 如果读进了一个回车符'\r'
            if(*offset_header == '\r')
            {
                // 立刻再读一个
                c = fgetc(stdin);
                // 如果紧接的是换行符,吃掉stdin中残留的换行符,
                // 并将读入的'\r'换成'\0',一行读取结束
                if(c == '\n')
                {
                    *offset_header = '\0';
                    should_out_of_page = 1;
                    should_out_of_read = 1;
                    break;
                }
                else
                {
                    // 如果'\r'不是'\n',原样放回去.
                    ungetc(c, stdin);
                    // 孤立的 \r 也当作行结束,替换成'\0'
                    *offset_header = '\0';
                    should_out_of_page = 1;
                    should_out_of_read = 1;
                    break;
                }
            }
            // 如果读进了一个换行符'\n'
            else if(*offset_header == '\n')
            {
                *offset_header = '\0';
                should_out_of_page = 1;
                should_out_of_read = 1;
                break;
            }
        }
        
        // 最后一次读完,offset_header++,指向下一页首,需要记下偏移量
        offset = offset_header - buf;
    }

    // 令p_str所指一级指针指向保存好字符串的内存段
    *p_str = buf;

    // 防止有其他指针指向同一块内存
    buf = NULL;
    offset_header = NULL;
    offset = 0;

    return is_normal;
}

// 关闭所指指针的namespace
int destroy_name_space(char **p_str)
{
    int free_successed = 1;
    free(*p_str);
    *p_str = NULL;

    return free_successed;
}