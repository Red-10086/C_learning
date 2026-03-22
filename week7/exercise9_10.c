/* 
    练习9-10 编写如下函数,将字符串s中的数字字符全部删除.
        void del_digit(char s[]){codes}
    例如传入"AB1C9"则返回"ABC"
    思路:不仅要查找,还要把数字字符全部删除
    法0:直接查找数字字符然后全部替换,但是替换什么都不好,替换成空格会在打印时
    多出一堆空格,替换成不可见字符也不好(令人费解:你写这么多操作符是要干嘛?)
    法1:每查找到一个数字元素,记住其下标,向后遍历直到下一个非数字字符,
        然后将后续字符全部向前缩(下标一同缩小);然后接着查找下一个数字字符
        缺点:人能听懂,机器听不懂:啊?什么啊?
    法2:创建一个新的空字符数组,用来装下旧字符串中的所有非数字字符:
    遍历旧数组,if 数字字符,跳过;否则全部顺序录入新数组.然后将新数组覆盖旧数组.
        优点:逻辑简单
        缺点:可能空间占用大,但是我想不出更好的办法了.
*/
#include <stdio.h>

void del_digit(char s[]);/* 删除字符串中的数字字符 */
int s_len(char s[]);/* 字符串长度(不包括'\0') */

int main(void)
{
    char str[128] = {'\0'};

    printf("请输入带数字的字符串:\n");
    scanf("%s", str);
    printf("去掉数字字符后:\n");
    del_digit(str);
    putchar('\"');
    printf("%s", str);
    putchar('\"');

    return 0;
}

void del_digit(char s[])/* 删除字符串中的数字字符 */
{
    const int LENGTH = s_len(s) + 1;/* 新字符串需要装'\0',多留一个元素 */
    
    int i = 0;
    char cp[LENGTH];
    
    for(i = 0; i < LENGTH; i++)/* 初始化 */
    {
        cp[i] = '\0';
    }

    int temp_index = 0;
    for(i = 0; s[i] != '\0'; i++)/* 读取字符串非'\0'部分 */
    {
        if(s[i] < '0' || s[i] > '9')/* 读s[],只把非数字字符顺序写入cp[] */
        {
            cp[temp_index] = s[i];
            temp_index++;
        }
    }

    for(i = 0; i < LENGTH; i++)/* 将新字符串覆写旧字符串,包括末尾'\0' */
    {
        s[i] = cp[i];
    }

    return;
}

int s_len(char s[])/* 字符串长度(不包括'\0') */
{
    int length = 0;
    
    while(s[length])
    {
        length++;
    }

    return length;
}