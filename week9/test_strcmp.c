#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("strcmp(\"A\", \"B\") = %d\n", strcmp("A", "B"));   // 预期：负数
    printf("strcmp(\"B\", \"A\") = %d\n", strcmp("B", "A"));   // 预期：正数
    printf("strcmp(\"A\", \"A\") = %d\n", strcmp("A", "A"));   // 预期：0
    printf("strcmp(\"A\", \"AA\") = %d\n", strcmp("A", "AA")); // 预期：负数（短者优先）
    
    return 0;
}