#define row 10
#define arrlen 128

void rev_string(char s[][arrlen], int n);/* s共n行,调用write和reverse需要他们给传总行数信息*/
void write(char s[][arrlen], int n);/* 逐行写,直到遇见"$$$$$",或写完共n行 */
void reverse(char s[][arrlen], int n);/* 逐行反转s[][],共n行 */
int s_len(char s[][arrlen], int i);/* 第i行字符串长度(不包括'\0') */



void rev_string(char s[][arrlen], int n)
{
    reverse(s, n);
    write(s, n);
}

/* 
    reverse{
        逐行遍历{
            行内-取字符串长度(s_len);
            行内-遍历字符串一半长度{
                关于数组"中轴"对称,首尾交换一次
            }
        }
    }
*/
void reverse(char s[][arrlen], int n)/* 逐行反转s[][],共n行 */
{
    for(int i = 0; i < n; i++)/* 逐行遍历 */
    {
        int len = s_len(s, i);

        for(int j = 0; j <= (len - 1) / 2; j++)/* 行内原地调头 */
        {
            int temp = 0;

            temp            = s[i][j];
            s[i][j]         = s[i][len-1-j];
            s[i][len-1-j]   = temp;
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