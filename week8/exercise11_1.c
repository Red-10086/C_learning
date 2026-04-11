/* 
    练习11-1 将代码清单11-3中对p的赋值进行如下修改:
        p = "456" + 1;
    请编写程序确认运行结果,并分析结果.

    清单11-3:
        #include <stdio.h>

        int main(void)
        {
            char *p = "123";

            printf("p = \"%s\"\n", p);

            p = "456";		

            printf("p = \"%s\"\n", p);

            return 0;
        }
*/

#include <stdio.h>

    int main(void)
    {
        char *p = "123";

        printf("p = \"%s\"\n", p);
   
        // 分析: "456"即字符串标签,退化成指向首字符的常量指针,+1表示向高地址移动1byte
        // 而字符型变量每个占位1byte,所以p被赋值为字符串的首字符地址+1,即次字符'5'的地址
        // %s打印时从p存储的地址开始打印,遇到'\0'停止:只打印"56"
        p = "456" + 1;

        printf("p = \"%s\"\n", p);

        return 0;
    }