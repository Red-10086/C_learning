#include <stdio.h>

int main(void)
{
    char s[] = "Hello World";
    
    printf("%s\n", s);           // 完整输出
    printf("%.5s\n", s);         // 精度 5：Hello
    printf("%15s\n", s);         // 右对齐，宽度 15
    printf("%-15s\n", s);        // 左对齐，宽度 15
    printf("%15.5s\n", s);       // 右对齐，宽度 15，精度 5
    printf("%-15.5s\n", s);      // 左对齐，宽度 15，精度 5
    
    return 0;
}