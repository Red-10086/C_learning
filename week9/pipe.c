#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 天生耦合：读写双方必须严格对齐
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
} my_times;
// 核心写入：高度耦合结构体布局
void fwrite_my_times_to_file(FILE *fp, const my_times *t) {
    // 严格按顺序写，任何改动都会导致读失败
    fwrite(&t->year,  sizeof(int), 1, fp);
    fwrite(&t->month, sizeof(int), 1, fp);
    fwrite(&t->day,   sizeof(int), 1, fp);
    fwrite(&t->hour,  sizeof(int), 1, fp);
    fwrite(&t->min,   sizeof(int), 1, fp);
    fwrite(&t->sec,   sizeof(int), 1, fp);
}

// 核心读取：高度耦合结构体布局
void fread_file_to_my_times(FILE *fp, my_times *t) {
    fread(&t->year,  sizeof(int), 1, fp);
    fread(&t->month, sizeof(int), 1, fp);
    fread(&t->day,   sizeof(int), 1, fp);
    fread(&t->hour,  sizeof(int), 1, fp);
    fread(&t->min,   sizeof(int), 1, fp);
    fread(&t->sec,   sizeof(int), 1, fp);
}

// 前钩子：返回 0 表示继续执行，返回非 0 表示拦截
typedef int (*hook_before_t)(const my_times*);

// 后钩子：执行完后做什么
typedef void (*hook_after_t)(const my_times*);

// 全局钩子（可动态替换，不修改核心）
static hook_before_t write_before_hook = NULL;
static hook_after_t  write_after_hook  = NULL;

// 设置钩子（外部扩展用）
void set_write_hooks(hook_before_t before, hook_after_t after) {
    write_before_hook = before;
    write_after_hook  = after;
}

// 带扩展能力的写入入口
void write_my_times_with_hook(FILE *fp, const my_times *t) {
    // 1. 前钩子：开关控制 + 预处理
    if (write_before_hook != NULL) {
        if (write_before_hook(t) != 0) {
            // 拦截：不执行核心写入
            return;
        }
    }

    // 2. 核心耦合逻辑（一行不改）
    fwrite_my_times_to_file(fp, t);

    // 3. 后钩子：后处理
    if (write_after_hook != NULL) {
        write_after_hook(t);
    }
}