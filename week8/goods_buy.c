#include <stdio.h>

enum array_parameters { twenty_types = 20 , goods_name_length = 128, product_number_length = 50 };// 数组的参数

/* 要可修改,当然得是用字符型数组实现"字符串数组" */ 
char goods_name[twenty_types][goods_name_length] = {0};// 商品名
char goods_product_number[twenty_types][product_number_length] = {0};// 商品编号

int goods_inventory[twenty_types] = {0};// 商品库存
double goods_price[twenty_types] = {0};// 商品价格

void goods_entry(void)
{
    const char * entry_strings[] = 
    {
        "请输入商品编号:",
        "请输入商品名称:",
        "请输入商品单价:",
        "请输入录入数量:"
    };

    printf("%s", entry_strings[0]);
    char tmp_0[product_number_length] = {0};
    scanf("%s", tmp_0);
    int index = 返回索引 编号查询和分配函数(tmp_0);

    printf("%s", entry_strings[1]);
    scanf("%s", goods_name[index]);     // 按索引录入商品名

    printf("%s", entry_strings[2]);
    char tmp_1[goods_name_length] = {0};
    while(1)
    {
        scanf(" %s", tmp_1);             // 读取商品价格-字符串
        if(strtof(tmp_1) != EOF && strtof(tmp_1) > 0)
        {
            goods_price[index] = strtof(tmp_1);
            break;
        }
        else
        {
            printf("输入有误,请重新输入一个小数.\n");
        }
    }

    printf("%s", entry_strings[3]);

}

/* 买商品函数,需求:商品索引 */
void goods_bye(const int goods_index)
{

}