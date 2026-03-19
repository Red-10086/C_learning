/* 
    练习9-3 编写一段程序,对list0907.c进行如下改写
        将字符串的个数3改为更大的数,将其值定义为对象式宏.
        在最初的for语句读取"$$$$$"时,停止读取操作.
        在第二个for语句显示"$$$$$"前输入的所有字符串.

    
	读取并显示字符串数组
    #include <stdio.h>

    int main(void)
    {
        int  i;
        char s[3][128];

        for (i = 0; i < 3; i++) {
            printf("s[%d] : ", i);
            scanf("%s", s[i]);
        }

        for (i = 0; i < 3; i++)
            printf("s[%d] = \"%s\"\n", i, s[i]);

        return 0;
    }

    思路1:不用scanf,直接用getchar(),如果输入的是连续的5个$,就停止,否则继续.
        优点:一旦写成,足够灵敏,"真的"如题干所说,"精确停止".(但其实没必要,用户不关心细节)
        缺点:需要多重逻辑判断处理边界条件:是否是$,是否连续5个,5个不连续/连续4个怎么办...
    思路2:用scanf一股脑读进来,先找有没有五个'$'字符,再判断连续,如有则包括$在内,全部写null
        优点:没学过处理字符串的方法(str_len等函数),可以直接使用已经学过的内容:查找/遍历数组
        以及判断字符是否相等

*/

#include <stdio.h>

#define num_of_str 10/* 字符串个数 */
#define len_of_arr 128/* 字符串数组长度 */

int len(const char arr[]);/* 返回字符串长度 */
/* 判断字符串是否相等,返回0表示不相等,返回1表示相等 */
int is_equal_string(const char str1[], const char str2[]);

int main(void)
{
    const char END_SIGN[] = "$$$$$";
    
    int  i;
    int j;
    char s[num_of_str][len_of_arr];

    for (i = 0; i < num_of_str; i++) 
    {
        printf("s[%d] : ", i);
        scanf("%s", s[i]);
        
        if(is_equal_string(s[i], END_SIGN))/* 读到"$$$$$"为止 */
        {
            break;
        }
    }

    for (i = 0; i < num_of_str; i++)
    {
        if(is_equal_string(s[i], END_SIGN))/* 打印到"$$$$$"之前为止 */
        {
            break;
        }
        
        printf("s[%d] = \"%s\"\n", i, s[i]);
    }

    return 0;
}

/* 返回0表示字符串不相等,返回1表示字符串相等 */
int is_equal_string(const char str1[], const char str2[])
{
    int len_1 = 0;/* str1字符串长度 */
    int len_2 = 0;/* str2字符串长度 */
    int is_equal = 0;/* 返回值 */

    len_1 = len(str1);
    len_2 = len(str2);

    if(len_1 != len_2)/* 字符串长度不同,自然不相等 */
    {
        is_equal = 0;
    }
    else/* 长度相等,然后逐个判断字符是否相等 */
    {
        is_equal = 1;/* 默认相等 */

        for(int i = 0; i < len_1; i++)/* 只要出现一个不同字符,两字符串就不相等 */
        {
            if(str1[i] != str2[i])
            {
                is_equal = 0;
                break;
            }
        }
    }

    return is_equal;
}

/* 只要是合法的字符串,都能返回字符串长度 */
int len(const char str[])
{
    int i;
    for(i = 0; i < len_of_arr; i++)
    {
        if(str[i] == '\0')
        {
            break;
        }
    }

    return i;
}