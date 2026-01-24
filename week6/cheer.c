#include <stdio.h>

void cheer(int i);

int main(void)
{
    cheer(2.2);
    
    return 0;
}

void cheer(int i)
{
    printf("cheer %d", i);
}
