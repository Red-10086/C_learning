#include <stdio.h>

int main()
{
    for(int i = 2; i<=1000; i++)
    {
        int number = i;
        int k = 0;
        int count = 0;
        int isSpecial = 0;

        do{
            k += number%10;
            number = number/10;
        }while(number != 0);

        for(;;)
        {
            isSpecial = 0;
            if(k%2 == 0)
            {
                if(k == 2)
                {
                    isSpecial = 1;
                    break;
                }
                k /= 2;
                count += 1;
                isSpecial = 1;
            }
            else
            {
                isSpecial = 0;
                break;
            }
        }
        if(isSpecial == 1)
        {
            printf("数字%d是特殊的,\t各个数位之和可以被2整除%d次\n",i , (count+1));
        }
    }

    return 0;
}