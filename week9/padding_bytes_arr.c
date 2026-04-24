#include <stdio.h>

int main(void)
{
    char arr[3][6] = 
    {
    "ABC",
    "PAUL",
    "OK"
    };

    char *p = &arr[0][0];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            printf("%c\t", *(p++));
        }
        putchar('\n');
    }

    return 0;
}