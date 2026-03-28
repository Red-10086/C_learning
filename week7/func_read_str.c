/* 
    读函数逻辑:
        循环A
        {
            读;
            判断;
        }
    判断逻辑:
        量字符串长度(不包含'\0'),非5直接退出
        长度为5,再用一个变量'$'字符个数,是5则确认结束读取(break循环A)
        两层判断,确保精确匹配:
            不先判断长度就数个数,长字符串可以稀疏地包含5个'$',逻辑错误;
            判断是否是$的连续性又复杂且不直观.
            定长+计数,确保精确匹配"$$$$$".
*/
#define arrlen 128
#define row 10

enum Numbers {five = 5};

// char str[row][arrlen] = {{0}};

void read(char s[][arrlen], int n);/* n:字符串数组的row,总行数 */
int s_len(char s[][arrlen], int i);/* 字符串长度(不包括'\0') */
int is_five_dollars(char s[][arrlen], int i);/* 二维字符数组s下标i对应字符串 */


void read(char s[][arrlen], int n)/* n:字符串数组的row,总行数 */
{
    for(int i = 0, done = 0; i < n; i++)
    {

        scanf("%s", s[i]); /* 读 */

        done = is_five_dollars(s, i);/* 判断,是则结束读取,否则继续 */

        if(done)
        {
            break;
        }
    }
}

int s_len(char s[][arrlen], int i)/* 字符串长度(不包括'\0') */
{
    int j = 0;
    
    while(s[i][j])
    {
        j++;
    }

    return j;
}

int is_five_dollars(char s[][arrlen], int i)/* 二维字符数组s下标i对应字符串 */
{
    int is_target_string = 0;/* 默认不是 */
    int len = s_len(s, i);/* 量字符串长度,不包含'\0' */

    if(len == five)/* 长度匹配 */
    {
        int j = 0;
        int counts = 0;
        while(s[i][j])/* 配合j++ 遍历字符串s[i] */
        {
            if(s[i][j] == '$')
            {
                counts++;
            }

            if(counts == five)/* '$'总数匹配 */
            {
                is_target_string = 1;
                break;
            }

            j++;
        }
    }

    return is_target_string;
}