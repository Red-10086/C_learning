#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned any = 0;//主变量
    unsigned left_movement = 0;//左移结果
    unsigned right_movement = 0;//右移结果
    unsigned n = 0;//位移位数
    unsigned go_out = 0; //和循环条件一起处理高位溢出
    long long unsigned power = 1;//幂
    
    do{
        power = 1;

        printf("请输入任意非负整数:");
        scanf("%u", &any);
        printf("要位移的位数:");
        scanf("%u", &n);

        for(int i = 0; i < n; i++)
        {
            power *= 2;
        }
        
        //左移等价于乘以2^n,乘积溢出等价于左移高位溢出
        if(((long long unsigned)any * power) > UINT_MAX)
        {
            printf("左移高位溢出,请重试\n");
        }
        else
        {
            left_movement = any << n;
            right_movement = any >> n;
            
            //输出比较
            printf("any = %u\n", any);
            //左移
            printf("any * 2^%u = %u\n", n, any*power);
            printf("left_movement = %u\n", left_movement);
            //右移
            printf("any / 2^%u = %u\n", n, any/power);
            printf("right_movement = %u\n", right_movement);

            //成功运行并退出
            go_out = 1;
        }
    }while(go_out == 0);

    return 0;
}
// printf("%u\t%u\t%u", sizeof(unsigned), sizeof(long long unsigned), sizeof((long long unsigned)any*power));
// 用于确认(long long unsigned)any * power的类型转换行为是否符合预期    