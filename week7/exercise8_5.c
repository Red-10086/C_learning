/* 
    练习8-5 请在程序中定义性别\季节等枚举类型,并有效利用它们.
*/
#include <stdio.h>

enum gender { Male, Female };/* 性别 */
enum season { Spring, Summer, Autumn, Winter};/* 季节 */


int main(void)
{
    /* 枚举变量 */
    enum gender gend = -1;
    enum season seas = -1;

    /* 字符串数组 */
    char gender_array[2][20] ={ {"先生"}, {"女士"} };
    char season_array[4][20] = {{"春天"}, {"夏天"}, {"秋天"}, {"冬天"}};
    char dish_array[4][20] = {{"春笋炒肉片"}, {"凉拌苦瓜"}, {"清蒸大闸蟹"} ,{"萝卜炖羊肉"}};

    /* 打印提示内容并读输入 */
    printf("请输入一个数字代表您的性别:男性 0 , 女性 1\n");
    scanf("%d", &gend);
    printf("请输入一个数字代表您喜欢的季节:春天 0 , 夏天 1, 秋天 2, 冬天3\n");
    scanf("%d", &seas);

    /* 根据性别称呼 */
    switch(gend)
    {
        case Male:
            printf("这位%s,", gender_array[Male]); 
            break;
        case Female:
            printf("这位%s,", gender_array[Female]); 
            break;
        default:
            printf("性别输入错误\n");
            break;    
    }
    /* 根据季节推荐菜品 */
    switch(seas)
    {
        case Spring:
            printf("%s推荐的菜品是%s.", season_array[Spring], dish_array[Spring]);
            break;
        case Summer:
            printf("%s推荐的菜品是%s.", season_array[Summer], dish_array[Summer]);
            break;
        case Autumn:
            printf("%s推荐的菜品是%s.", season_array[Autumn], dish_array[Autumn]);
            break;
        case Winter:
            printf("%s推荐的菜品是%s.", season_array[Winter], dish_array[Winter]);
            break;
        default:
            printf("季节输入错误\n");
            break;   
    }

    return 0;
}