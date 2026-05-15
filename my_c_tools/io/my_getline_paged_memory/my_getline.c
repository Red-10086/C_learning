/* 
    函数create_name_space(),  -->以分页缓冲区<--  ,实现了对stdin内任意长度的一行字符的读取
    可以帮助理解内存分页
*/

#include <stdlib.h>
#include <stdio.h>
#include "mytool_paged.h"

enum { PAGE_SIZE = 16 };   /* 分页大小，教学用 */

ssize_t my_getline_paged(char **line)
{
    char *buf = NULL;
    char *temp = NULL;
    char *offset = NULL;    /* 当前写入位置 */
    int pages = 0;
    size_t pos = 0;         /* 总写入字节数 */
    int c;

    if (line == NULL) return -1;

    /* 初始一页 */
    buf = malloc(PAGE_SIZE);
    if (buf == NULL) return -1;
    pages = 1;
    offset = buf;

    while ((c = fgetc(stdin)) != EOF) {
        /* 检查是否需要新页 */
        if (offset >= buf + pages * PAGE_SIZE) {
            temp = realloc(buf, (pages + 1) * PAGE_SIZE);
            if (temp == NULL) {
                free(buf);
                return -1;
            }
            pages++;
            buf = temp;
            offset = buf + pos;   /* 重定位到续写位置 */
        }

        *offset++ = (char)c;
        pos++;

        if (c == '\n') break;
        if (c == '\r') {
            int next = fgetc(stdin);
            if (next != '\n' && next != EOF) ungetc(next, stdin);
            break;
        }
    }

    if (pos == 0 && c == EOF) {
        free(buf);
        return -1;
    }

    /* 精确截断到实际长度 + '\0' */
    temp = realloc(buf, pos + 1);
    if (temp != NULL) buf = temp;
    buf[pos] = '\0';

    *line = buf;
    return (ssize_t)pos;
}

void my_freeline_paged(char **line)
{
    if (line && *line) {
        free(*line);
        *line = NULL;
    }
}