#include <stdio.h>

int main()
{
    //变量初始化
    int amount = 100;
    int price = 0;
    int change = amount-price;
    
    //输入商品价格
    printf("请输入金额（元）：");
    scanf("%d",&price);

    //输入票面（消费者支付的金额）
    printf("请输入票面：");
    scanf("%d",&amount);

    //票面减去价格得到找零,如果金额不足则提示
    change = amount-price;
    if(change>=0)
    {
        printf("找您%d元。\n",change);
    }
    else
    {
        printf("您支付的金额不足，请再支付%d元", -change);
    }

    return 0;
}