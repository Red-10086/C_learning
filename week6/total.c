#include <stdio.h>

#define NameStrenth 49

const int array_Strenth = 50;

int serchId = 0;/* 存储商品索引的全局变量 */
int itemId = 0;/* 存储商品ID的全局变量 */
int user_Choice = 0;/* 存储用户选择的全局变量 */

//定义并初始化要用到的平行数组
int product_ID[50] = {0};/* 商品ID库 */
char product_Names[50][50] = {0};/* 商品名库 */
double product_Prices[50] = {0};/* 商品价格库 */
int product_Stock[50] = {0};/*商品库存量库*/

//声明函数
void addItem(void);/* 录入函数 */
void product_Query_System(void);/* 查询函数 */


int main(void)
{


    while(1)
    {
        /* 菜单，初始页面 */
        printf("请选择你想要的的服务:\n");
        printf("输入-1退出程序\n");
        /* 默认值不能有业务意义，所以不能有0 */
        printf("输入1开始录入商品\n");
        printf("输入2开始查询商品\n");
        /* printf("输入3开始\n");
        printf("输入4开始\n");
        printf("输入5开始\n"); */

        /* 读取用户选择 */
        int user_Choice = 0;
        scanf("%d", &user_Choice);

        if(user_Choice == -1)
        {
            break;/* 特殊处理，避免使用goto语句，switch中的break只能打破本层结构（switch本身） */
        }

        /* 根据选择进入服务 */
        switch(user_Choice)
        {
            case 1:
                printf("您正在使用录入功能:\n");
                addItem();
                break;

            case 2:
                printf("您正在使用查询功能:\n");
                product_Query_System();
                break;

            case 3:
                printf("您正在使用购买功能\n");

                break;

            /*             case 4:

                break;

            case 5:

                break; */
            default:
                printf("非法输入，请重试\n");
        }
        
        //显示延迟
        printf("输入任意数字继续\n");
        int anyth;
        scanf("%d", &anyth);
    }

    return 0;
}

void addItem(void)
{
    for(;;)
    {
        int find_out = 0;
        int first_zero = -1;
        
        /* 检查库中是否已经存在该商品 */
        printf("请输入您要添加的商品ID:\n");
        scanf("%d", &itemId);

        /* 找首个非零位，备用，如果ID库中没找到ID，就用首个非零位装 */
        for(int i = 0; i <= array_Strenth; i++)
        {
            if(product_ID[i] == 0)
            {
                first_zero = i;
                break;
            }
        }

        /* 确认添加的商品是否存在 */
        for(int i = 0; i <= array_Strenth; i++)
        {
            if(itemId == product_ID[i])
            {
                find_out = 1;
                break;
            }
        }
        

        /* 录入功能 */
        printf("请输入您要录入的商品ID:\n");
        scanf("%d", &itemId);
        product_ID[serchId] = itemId;
        printf("请输入商品%d的商品名:\n", serchId);
        scanf("%49s", product_Names[serchId]);
        printf("请输入商品%d的价格:\n", serchId);
        scanf("%lf", &product_Prices[serchId]);
        printf("请输入商品%d的库存量:\n", serchId);
        scanf("%d", &product_Stock[serchId]);
        printf("商品添加成功！\n");

        /*继续或返回主菜单*/
        printf("输入-1返回主菜单\n");
        printf("输入任意非-1的数字继续\n");
        scanf("%d", &user_Choice);
        if(user_Choice == -1)
        {
            break;
        }
    }
}

void product_Query_System(void)
{
    /* 查询功能 */
    for(;;)
    {
        printf("请输入您要查询的商品ID:\n");
        scanf("%d", &serchId);
        printf("ID编号为%d的商品 %s 价格为 %lf ,库存容量为 %d ", serchId, product_Names[serchId], 
        product_Prices[serchId], product_Stock[serchId]);

        /*继续或返回主菜单*/
        printf("输入-1返回主菜单\n");
        printf("输入任意非-1的数字继续\n");
        scanf("%d", &user_Choice);
        if(user_Choice == -1)
        {
            break;
        }
    }
}


