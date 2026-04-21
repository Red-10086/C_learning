#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

long safe_strtol(const char *str) {
    char *end;
    errno = 0;  // 清零错误标志
    
    long val = strtol(str, &end, 10);
    
    // 检查1：没有可转换的数字
    if (end == str) {
        printf("错误：没有可转换的数字\n");
        return 0;
    }
    
    // 检查2：溢出
    if (errno == ERANGE && (val == LONG_MAX || val == LONG_MIN)) {
        printf("错误：数值溢出\n");
        return 0;
    }
    
    // 检查3：末尾有非法字符（可选，取决于需求）
    if (*end != '\0') {
        printf("警告：末尾有未转换字符 \"%s\"\n", end);
    }
    
    return val;
}

int main(void)
{
    long tmp = 0;
    tmp = safe_strtol("123");      // 正常
    printf("%ld\n", tmp);

    tmp = safe_strtol("abc");      // 错误：没有可转换的数字
    printf("%ld\n", tmp);

    tmp = safe_strtol("123abc");   // 警告：末尾有未转换字符
    printf("%ld\n", tmp);
    
    tmp = safe_strtol("99999999999999999999");  // 错误：数值溢出
    printf("%ld\n", tmp);
    
    return 0;
}