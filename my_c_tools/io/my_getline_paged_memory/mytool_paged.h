#ifndef MYTOOL_PAGED_H
#define MYTOOL_PAGED_H

#include <stdio.h>

/* 分页版行读取器
 * 从 stdin 读取一行，按固定页大小动态扩展
 * 返回：实际读取字符数（不含 '\0'），EOF 返回 -1
 * 调用者负责 free(*line) */
ssize_t my_getline_paged(char **line);

/* 释放缓冲区 */
void my_freeline_paged(char **line);

#endif