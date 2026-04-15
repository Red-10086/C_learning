/*
    练习11-10 编写如下函数,实现与库函数atoi\atol\atof相同的功能.
        int strtoi(const char *nptr){codes}
        long strtoL(const char *nptr){codes}
        double strtod(const char *nptr){codes}
    
    思路:先实现:只兼容无符号十进制的形式
        检测字符串是否是纯数字字符(double的话仅允许多一个. 即小数点),
        是则继续,否则退出

        对于int和long
        先量字符串长度strlen,确定是几位数,

        逐位将char字符转为
        对应的int数字(如char '0'转化为 int 0),
        再赋予位序,比如输入"1234",那么,返回:
            1*10e3 + 2*10e2 + 3*10e1 +4*10e0
        
        反正用atoi/atoL处理不能用int/long范围表示的数是未定义行为,
        不管上下限
        
        对于double,也类似,只是需要先确定小数点'.'
        然后以小数点为界,
        逐位将char字符转为对应的double数字(如char '0'转化为 int 0.0),
        例如输入:"12.56",返回:
            1.0*10e1 + 2.0*10e0 + 4.0*10e-1 +6.0*10e-2

        然后处理符号
*/
#include <limits.h>