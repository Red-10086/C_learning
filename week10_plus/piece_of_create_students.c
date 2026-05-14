#include <stdio.h>
#include <stdlib.h>

// 缓冲区的页宽度
enum {buf_page_len = 32};

// 学生,成员:id,指向姓名的指针,成绩
typedef struct student
{
    int id;
    char *p_name;
    double score;
} junior;

int main(void)
{
    int N = 0;
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
        arr = temp_arr;
    }
    
    // 赋值
    for(int i = 0; i < N; i++)
    {
        printf("请输入第%d个学生的学号:\n", i+1);       scanf("%d", &arr[i].id);
        // printf("请输入第%d个学生的姓名:\n", i+1);       scanf("%s", arr[i].p_name);
        printf("请输入第%d个学生的成绩:\n", i+1);       scanf("%lf", &arr[i].score);
    }
    
    // scanf("%s", arr[i].p_name);
    // 即使用"格式字符串"(如char *s = "%128s", scanf(s, arr[i].p_name)),也难以实现真正的“可变长”

    printf("请输入第%d个学生的姓名:\n", i+1);
    
    // 按arr[i].p_name存的地址值,往该地址写值

    // 开辟缓冲区
    char *buf_area = NULL;
    char *temp_buf_area = NULL;
    temp_buf_area = (char *)malloc(buf_page_len * sizeof(char));
    
    if(temp_buf_area == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    buf_area = temp_buf_area;

    // j是页索引
    for(int j = 0, should_out = 0; ; j++)
    {
        // i是页内索引
        for(int i = j * buf_page_len; i < (j+1) * buf_page_len ; i++)
        {
            // 不停地读,直到读到换行符或回车符(一般而言,读一行(无论多长)是不会有'\r'或'\n'的)
            // 同时检验'\r'和'\n',是为了兼容windows的'\r''\n'和Linux的'\n'
            fread(buf_area+i, sizeof(char), 1, stdin);
            if( *(buf_area+i) == '\r' || *(buf_area+i) == '\n' )
            {
                // 读入了换行,手动换成'\0'结尾
                *(buf_area+i) = '\0';
                should_out = 1;

                // 清空缓冲区残留的不可见字符.
                printf("输入任意数字继续\n");
                scanf(" %*d");
                break;
            }
        }

        // 遇到回车,直接退出.
        if(should_out == 1)
        {
            break;
        }
        // 没遇到回车,但是page用完了,需要跨页,先创建新页
        else
        {
            // 新buf宽度 = (当前页索引+2)*页宽度
            // 例如,当前页索引为6时,总页数为7(从0-6),新的总页数为6+2 == 8
            temp_buf_area = realloc(buf_area, (j+2) * buf_page_len);
            if(temp_buf_area == NULL)
            {
                printf("内存分配失败\n");
                return 1;
            }
            buf_area = temp_buf_area;
        }
    }


    // 打印
    for(int i = 0; i < N; i++)
    {
        // printf("%-20d %-20s %-8.2lf\n", arr[i].id, arr[i].p_name, arr[i].score);
    }

    // 释放
    free(arr);
    arr = NULL;
    temp_arr = NULL;
    temp_read_p = NULL;

    return 0;
}