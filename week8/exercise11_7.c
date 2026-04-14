/* 
    练习11-7 不使用下标运算符,实现代码清单9-1的str_toupper和str_tolower函数.

    // 将字符串中的英文字母转为大写字母 
	void str_toupper(char s[])
	{
		int i = 0;
		while (s[i]) {
			s[i] = toupper(s[i]);
			i++;
		}
	}
	// 将字符串中的英文字母转为小写字母 
	void str_tolower(char s[])
	{
		int i = 0;
		while (s[i]) {
			s[i] = tolower(s[i]);
			i++;
		}
	}

	思路:while(*s++){if(is_lower(s)) *s -= 32; }
		while(*s++){if(is_uper(s)) *s += 32; }
*/

#include <stdio.h>

void str_toupper(char *s);
void str_tolower(char *s);

int main(void)
{
	char str[128] = {0};
	printf("请输入英文字符串:");
	scanf(" %s", str);

	str_tolower(str);
	printf("全小写: \"%s\" \n", str);
	str_toupper(str);
	printf("全大写: \"%s\" \n", str);

	return 0;
}

void str_toupper(char *s)
{
	// while(*s++)/* 吞头 */
	for(; *s != '\0'; s++)
	{
		/* 是小写字母 */
		if(*s >= 'a' && *s <= 'z')
		{
			/* ascii英文字母转大写 */
			*s -= 32; 
		}
	}
}

void str_tolower(char *s)
{
	// while(*s++)/* 吞头 */
	for(; *s != '\0'; s++)
	{
		/* 是大写字母 */
		if(*s >= 'A' && *s <= 'Z')
		{
			/* ascii英文字母转小写 */
			*s += 32;
		}
	}
}