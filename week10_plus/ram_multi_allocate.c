#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // 用于初始化随机数种子

int main(void)
{
    void *p;
    int cnt = 0;
    long long *arr;
    // 计算100MiB可以容纳多少个long long
    size_t n = (100L * 1024L * 1024L) / sizeof(long long); 

    // 使用当前时间作为随机数种子，确保每次运行生成的序列都不同
    srand((unsigned int)time(NULL));

    while ( (p = malloc(100L * 1024L * 1024L)) ) {
        cnt++;
        arr = (long long *)p;
        
        // 写入64位随机值，破坏重复性，使每一页内存几乎不可压缩
        for (size_t i = 0; i < n; i++) {
            arr[i] = arr[i] & 0U;
            for(int j = 0; j < 4; j ++)
            {
                arr[i] = arr[i] << 16;
                arr[i] += (long long)rand();
            }

            // 注意：rand()返回的是一个int。对于long long，我们只用了部分位。
            // 但这已经足够让每个页面的内容都变得随机。
        }

        printf("分配了%d00MB的空间\n", cnt);
    }

    printf("内存分配失败，程序终止。\n");
    return 0;
}