#include <stdio.h>
#include <string.h>

enum Const_Numbers {length = 128};

char *read_str(char *s);

char *read_str(char *s)
{
    printf("请输入字符串:\n");
    scanf(" %127s", s);

    return s;
}