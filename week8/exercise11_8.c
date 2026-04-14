/* 
    练习11-8 编写如下函数,删除字符串str内所有的数字字符
        void del_digit(char *str){codes}
    例如,如果接受"AB1C9",就返回"ABC".
    注意不要使用下标运算符.

    思路1:先检查原字符串数组s1中有没有数字字符('0'~'9').
        如无则原样退出.
        如有:再复制一个等长数组s2,将s1分段映射到s2.
            比如"ABCD3EFG2HI5JK467L"
            A-D正常(*s2 = *s1),E-G用新映射(*s2 = *s1 + 1),
            H-I用映射(*s2 = *s1 + 2),J-K用映射(*s2 = *s1 + 3),
            L和'\0'用映射(*s2 = *s1 + 6).
                临界点无外乎s1中数字字符的下标,可以用一个数组(也可以是链表-按需创建
                ,可惜我还不会)单独存储.
    思路2:这样至少要遍历两遍,最坏的情况得额外创建两个和s1等长的数组.
        直接创建两个指针(p1和p2),同时从首元素开始,p1和p2同步递增以遍历数组,
        p2每碰到一个元素都要判定是否是数字字符,p1不动,p2自增一次(指向下一个元素),
        再判定p2所指是否是...直到p2所指不是数字字符,将p2所指元素赋给p1,
        直到p2碰到'\0':将'\0'复制给p1所指,然后p1自增以p1将剩余元素全部写'\0'.

*/

#include <stdio.h>
#include <string.h>

int is_digit(const char *s);/* 返回1表示是数字字符,返回0表示不是 */
void del_digit(char *str);

int main(void)
{
    char string[128] = {0};
    printf("请输入字符串:\n");
    scanf(" %127s", string);

    del_digit(string);
    
    printf("去除数字字符后: \"%s\" \n", string);

    return 0;
}


void del_digit(char *str)
{
    int len = strlen(str) + 1;
    int n = 0;
    const char * const start = str;/* 指向原数组的头 */
    const char * const end = str + len;/* 指向原数组的末位后一位,不可解引用和修改 */
    char *p_effective = str;/* 用来写有效内容的指针 */
    char *p_explorer = str;/* 用来"探路"的指针 */

    for( ; p_explorer < end ; p_effective++, p_explorer++ )
    {
        /* 先判定p_explorer指向的是否是数字字符,是则继续探索:步进一次,再判断 */
        /* 并且避免p_explorer越界访问 */
        /* 先检查边界,确定未越界再访问:p_explorer < end必须在前面 */
        while( p_explorer < end && is_digit(p_explorer) == 1 )
        {
            p_explorer++;
        }

        /* 直到所指非数字,将p_explorer所指元素(非数字)赋值给p_effective所指元素 */
        *p_effective = *p_explorer;
    }
    /* 最终p_explorer一定指向原字符串末尾的'\0' */

    /* 覆写原字符串,防止信息残留 */
    for( ; p_effective < end; p_effective++)
    {
        *p_effective = '\0';
    }

}

int is_digit(const char *s)/* 返回1表示是数字字符,返回0表示不是 */
{
    int result = 0;
    if(*s >= '0' && *s <= '9')
    {
        result = 1;
    }

    return result;
}