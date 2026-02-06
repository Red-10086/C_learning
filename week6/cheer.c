#include <stdio.h>

void cheer(int i);

int main(void)
{
    int a = 0;
    scanf("%d", &a);
    cheer(2.2);
    int i = 0;
    printf("%d", i);
    
    return 0;
}

void cheer(int i)
{
    printf("cheer %d", i);
}
