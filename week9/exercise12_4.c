/* 
    练习12-4 对代码清单12-7进行改写.
    不将姓名身高等数据作为初始值,而是从键盘输入.
    可以选择按身高进行升序排序,或者按照姓名的顺序进行排序.

    12-7:
    声明结构体(模板){姓名 身高 体重 奖学金}
    交换函数(交换两个同类型结构体的所有成员)
    排序函数(调用交换函数)

    主程序{
        定义初始化了一个结构体数组 = {5个学生结构体(具体值)};
        遍历打印结构体数组
        排序函数()
        遍历打印结构体数组
    }
*/

#include <stdio.h>
#include "my_struct_sort.h"

int main(void)
{
    Junior arr[student_Number] = {0};
    for(int i = 0; i < student_Number; i++)
    {
        // name是数组名,会退化,不需要&
        printf("请输入第%d个同学的名字:\n", i+1);        scanf("%s", arr[i].name);
        
        // 其余都是算术型对象,需要&运算符告诉scanf地址在哪.
        printf("请输入第%d个同学的身高(cm):\n", i+1);    scanf("%d", &arr[i].height);
        printf("请输入第%d个同学的体重(kg):\n", i+1);    scanf("%f", &arr[i].weight);
        printf("请输入第%d个同学的奖学金数额:\n", i+1);  scanf("%ld", &arr[i].schols);
    }
    
    // 排序前打印
    printf("排序前:\n");
    for(int i = 0; i < student_Number; i++)
    {
        printf("第%d个同学的名字:%-10s\t", i+1, arr[i].name);
        printf("第%d个同学的身高(cm):%4d\t", i+1, arr[i].height);
        printf("第%d个同学的体重(kg):%4.2f\t", i+1, arr[i].weight);
        printf("第%d个同学的奖学金数额:%8ld\n", i+1, arr[i].schols);
    }
    
    int choice = 0;
    while(!(choice == 1 || choice == 2))
    {
        printf("按名字排序请输入1\n");
        printf("按身高排序请输入2\n");
        scanf(" %d", &choice);
    }
    switch (choice){
        case 1:
            sort_Name(arr, student_Number);
            break;
        case 2:
            sort_Height(arr, student_Number);
            break;
    }

    // 排序后打印
    printf("排序后:\n");
    for(int i = 0; i < student_Number; i++)
    {
        printf("第%d个同学的名字:%-10s\t", i+1, arr[i].name);
        printf("第%d个同学的身高(cm):%4d\t", i+1, arr[i].height);
        printf("第%d个同学的体重(kg):%4.2f\t", i+1, arr[i].weight);
        printf("第%d个同学的奖学金数额:%8ld\n", i+1, arr[i].schols);
    }
    
    return 0;
}






// 雪藏的方案
// enum Const_numbers { name_Len = 64 , student_Number = 5 , label_Number = 4};
// enum Labels { student_Name , student_Height , student_Weight , student_Schols };
// char* Labels[label_Number] = {NULL, NULL, NULL, NULL};
// Labels[student_Name]   = "姓名";
// Labels[student_Height] = "身高(cm)";
// Labels[student_Weight] = "体重(kg)";
// Labels[student_Schols] = "奖学金(元)";
// for(int i = 0; i < student_Number; i++)
// {
    //     printf("请输入第%d个同学的%s\n", i+1, Labels[i]);
    // 难以按序号换用scanf格式说明符-接口不通用
// }