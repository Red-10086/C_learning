/* 
    练习9-11 编写一段程序,对代码清单9-12进行如下改写.
        将字符串的个数3改为更大的数,将其值定义为对象式宏
        将字符串的字符数改为128,将其制也定义为对象式宏
        生成读取字符串数组的函数.和练习9-3一样,在读取到"$$$$$"后,停止读取操作
        显示"$$$$$"前输入的所有字符串.
*/

#include <stdio.h>

#define row 10
#define length 128

/*--- 显示字符串数组 ---*/
void put_strary(const char s[][6], int n)/* 必须指定第二维及更低维数组的长度,第一维省略以传递指针 */
{
	int i;
	for (i = 0; i < n; i++)
		printf("s[%d] = \"%s\"\n", i, s[i]);/* 打印第i+1行-下标i存储的字符串 */
}

int main(void)
{
	char cs[][6] = {"Turbo", "NA", "DOHC"};

	put_strary(cs, 3);

	return 0;
}
