#include <stdio.h>

int rescu(int n);

int main(void)
{
    rescu(10);

    return 0;
}

int rescu(int n)
{
    if(n>0)
    {
        return n*rescu(n-1);
    }
    else
    {
        return 1;
    }
}