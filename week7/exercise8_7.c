/* 
    练习8-7 编写如下函数,求出从n个不同整数中取出r个整数的组合数C(n,r).
        int combiantion(int n, int r)
        {
            codes
        }
    C(n,r)的定义如下:
        C(n, r) = C(n-1, r-1) + C(n-1, r)
        且C(n, 0) = C(n, n) = 1
        且C(n, 1) = n
    考察内容:递归函数
*/

#include <stdio.h>

enum com_err { com_err = -1 };

int combination(int n, int r);

int main(void)
{
    /* 定义变量并初始化 */
    int count = 0;/* 组合数 */
    int n = 0;
    int r = 0;

    /* 打印提示信息 */
    printf("请输入两个自然数n和r,确保n >= r:\n");
    printf("n:");
    scanf("%d", &n);
    printf("r:");
    scanf("%d", &r);

    /* 求组合数 */
    count = combination(n, r);

    /* 打印结果 */
    if(count == com_err)
    {
        printf("error:%d", com_err);
    }
    else
    {   
        printf("C(%d, %d) == %d", n, r, count);
    }

    return 0;
}

int combination(int n, int r)
{
    /* 确保n大于等于r,否则无法终止,栈溢出;且确保传入值无负数-逻辑无谬误 */
    if(r > n || n < 0 || r < 0)
    {
        return com_err;
    }

    /* 定义返回值 */
    int result = 0;

    /* 递归终止的基准 */
    if( r == 0 )/* C(n,0) == 1 */
    {
        result = 1;
    }
    else if( r == n )/* C(n,n) == 1 */
    {
        result = 1;
    }
    else if( r == 1 )/* C(n,1) == n */
    {
        result = n;
    }
    /* 以上都不满足-问题拆解得还不够小, 继续"递"-拆解成
    更小问题:C(n,r) == C(n-1, r-1) + C(n-1, r)  */
    else
    {
        result = combination(n-1, r-1) + combination(n-1, r);
    }
    
    return result;
}

//有逻辑问题的试错:
// switch (r)
// {
//     case 0:
//     result = 1;
//     break;
//     case 1:
//     result = n;
//     break;
// }
// if(r == n)
// {
//     result = n;
// }
// else/* 尾递归,有问题,对于r == 1且 r!=n的情况 会再次进入递归而非如预期退出*/
// {
//     result = combination(n-1, r-1) + combination(n-1, r);
// }