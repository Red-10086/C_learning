#include <stdio.h>

int main()
{
    double foot;
    double inch;

    printf("请分别输入身高的英尺和英寸，");
    printf("如输入\"5 7\"表示5英尺7英寸：");

    scanf("%lf %lf", &foot, &inch);

    printf("身高是%lf米。\n",((foot + inch /12.0 ) * 0.3048));
    
    return 0;
}