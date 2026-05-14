#include <stdio.h>
#include <stdlib.h>

enum {page_size = 16};

int main(void)
{
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
        return 1;
    }

    buf = temp_buf;
    offset_header = buf;
    page_num++;

    // 偏移头逐页偏移,并且紧随着新页开辟
    // offset表示偏移头相对buf首地址的偏移量
    for(int offset = 0; ;)
    {
        // 剩余空间不够再写一页了,只额外开辟一页
        if(offset_header + page_size > buf +page_num * page_size )
        {
            temp_buf = realloc(buf, (page_num+1) * page_size);
            if(temp_buf == NULL)
            {
                return 1;
            }
            page_num++;
            buf = temp_buf;
            offset_header = buf + offset;
            // offset_header = buf + (page_num - 1) * pagesize;
        }

        // stdin中成功读到的字符个数,小于一页:要么发生错误,要么stdin中字符个数不够了-读完了
        if(fread(offset_header, sizeof(char), page_size, stdin) < page_size)
        {
            // 检查,处理字符串的codes
            break;
        }
        
        // 写完一页,向后偏移一页距离,并保存偏移后,偏移头的偏移量
        offset_header += page_size;
        offset = offset_header - buf;
    }
    // 处理读进来的/n,/r之类的零散字符,并补'\0'
    // codes

    free(buf);
    buf = NULL;
    temp_buf = NULL;
    offset_header = NULL;
    page_num = 0;

    return 0;
}