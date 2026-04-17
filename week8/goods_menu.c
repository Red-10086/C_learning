#include <stdio.h>
#include <time.h>

enum arrays_lengths { message_array_length = 6, error_array_length = 10};
enum choices {first_choice, enter_goods, search_goods, buy_goods, print_all_goods, exit_system, last_choice};
enum error_types { please_retype, input_type_error, input_value_error };

int *product_menu(void);

int main(void)
{
    menu();

    return 0;
}

int *product_menu(void)
{
    enum choices user_choice = 0;

    while(1)
    {
        user_choice = 0;
        const char * pointer_message[message_array_length] = 
        {
            "=== 商品库存管理系统 ===",
            "1. 录入商品",
            "2. 查询商品",
            "3. 购买商品",
            "4. 显示所有商品",
            "5. 退出"
        };

        const char * pointer_error_types[error_array_length] = {0};
        pointer_error_types[please_retype] = "请重新输入";
        pointer_error_types[input_type_error] = "输入类型错误";
        pointer_error_types[input_value_error] = "输入值错误";  
    
        // 打印控制台菜单
        for(int i = 0; i < message_array_length; i++)
        {
            // %s需要指针(*(p+i)),而非指针的指针(p+i) 
            printf("%s\n", pointer_message[i]);
        }
    
        /* 如果输入类型错误,打印错误提示,等待3秒后再次加载菜单 */
        if(scanf("%d", user_choice) == 0)
        {
            printf("%s\n", pointer_error_types[please_retype]);
            printf("%s\n", pointer_error_types[input_type_error]);
            sleep(3);
            continue;
        }

        /* 如果输入值错误,打印错误提示,等待3秒后再次加载菜单 */
        if(user_choice <= first_choice || user_choice >= last_choice )
        {
            printf("%s\n", pointer_error_types[please_retype]);
            printf("%s\n", pointer_error_types[input_value_error]);
            sleep(3);
            continue;
        }

        /* 输入类型和输入值检查完毕,允许接收输入 */
        break;
    }

    return user_choice;
}