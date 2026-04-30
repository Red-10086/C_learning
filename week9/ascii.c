#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    char c = 0;
    FILE *fp = NULL;

    fp = fopen("ascii.bin", "wb");

    if(fp ==  NULL)
    {
        puts("打开失败\n");
    }
    else
    {
        c = CHAR_MIN;
        // 从CHAR_MIN到CHAR_MAX,循环一轮,再次成为CHAR_MIN时结束.
        do{
            fwrite(&c, sizeof(char), 1, fp);   
            c++; 
        }while(c != CHAR_MIN);

        fclose(fp);
    }


    return 0;
}