#include <stdio.h>
#include <stdlib.h>  // strtol 在此头文件

int main(void)
{
    char str[] = "123abc";   // 待转换的字符串
    char *end;               // 用于接收"停止位置"的指针变量
    long val;                // 用于接收转换结果
    
    val = strtol(str, &end, 10);  // 核心调用
    
    printf("转换结果: %ld\n", val);      // 输出: 123
    printf("停止位置: %s\n", end);       // 输出: "abc"
    printf("停止位置偏移: %ld\n", end - str);  // 输出: 3
    
    return 0;
}