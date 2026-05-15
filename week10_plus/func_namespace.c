#include <stdio.h>
#include <stdlib.h>
#include "junior_manage.h"

// 接受一个字符型指针的地址,为所指指针开辟内存空间并读入任意长度的string(开启namespace),在函数内令一级指针指向该内存段
int create_name_space(char **p_str);

// 关闭所指指针的namespace
int destroy_name_space(char **p_str);

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