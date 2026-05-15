/* 使用示例
gcc my_getline.c plain.c -o plain;.\plain
输入: Sebastian Maximilian Alexander Christopher Wellington
结果: Sebastian Maximilian Alexander Christopher Wellington
PS C:\Users\asus\Desktop\Hello\C_Learning\my_c_tools\io\my_getline_paged_memory> 
*/
#include <stdio.h>
#include "mytool_paged.h"

int main(void)
{
    char *line = NULL;
    
    printf("输入: ");
    if (my_getline_paged(&line) != -1) {
        printf("结果: %s\n", line);
        my_freeline_paged(&line);
    }
    
    return 0;
}