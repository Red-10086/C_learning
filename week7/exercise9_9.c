/* 
    编写如下函数,逆向显示字符串s的字符
        void rev_string(char s[]){codes}
    例如,若s中接受的是"SEC",则将其数组更新为"CES"

    思路:数组原地倒序(不止字符串,而是几乎所有数组,字符串要对'\0'特殊处理)的方法.
    法1:创建一个新数组,原样复制旧数组,然后逆序覆写旧数组.
    法2:创建一个临时变量和一个装长度的变量,用sizeof量出数组长度length,然后用length/2作为for循环边界,让i遍历:0<=i<=length/2(length是偶数的话正好,是奇数的话,刚好不会越过"中线",且"中线不会被交换",即无论长度的奇偶性,都能只交换一遍-原地调头).
    法2资源占用更少.

    但是! 字符串末尾是'\0',必须特殊处理!!!
*/

#include <stdio.h>

void rev_string(char s[]);/* 字符串原地调头 */

int main(void)
{
    char str[128] = {'\0'};

    printf("请输入字符串:\n");
    scanf("%s", str);

    printf("字符串正序: \"%s\" \n", str);

    rev_string(str);
    printf("字符串倒序: \"%s\" \n", str);

    return 0;
}

void rev_string(char s[])/* 字符串原地调头 */
{
    int length = 0;/* 字符串长度 */
    int tmp = 0;/* 交换数组元素的临时变量 */

    for( ; s[length] != '\0'; length++){}/* 量字符串长度,如遇空字符串,则length还是0 */

    //for(int i = 0; i <= length/2; i++) 
    //对一般数组原地调头可行,但是对字符串呢?答:会把'\0'包进去,不可行

    for(int i = 0; i <= (length-1)/2; i++)/* s[length]此时一定为'\0',剔除.length为奇数,中间值自交换,无伤大雅 */
    {
        tmp = s[i];
        s[i] = s[length -1 - i];/* 2倍中点坐标减i,得i关于中点的对称点 */
        s[length -1 -i] = tmp;
    }

}