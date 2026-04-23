/*
	练习12-5 改写代码清单12-9的程序,使其能够选择两种方法-输入目的地坐标的方法,
    以及输入x方向和y方向的行驶距离的方法.
    例如:假设当前坐标值为{5.0, 3.0}, 想要移动至{7.5, 8.9}.输入坐标时,输入7.5和8.9,
    输入行驶距离时,则输入2.5和5.9

    思路:
    主程序:开动汽车分支(select==1)多一个子分支+对应提示信息和逻辑
    分支0退出
    分支1-子分支1输入dest坐标-仍旧调用move函数...与原来一样
    分支1-子分支2输入距离,分支内计算出dest坐标(u+δu)并传给move函数,其余没有区别.
*/

#include <math.h>
#include <stdio.h>

#define sqr(n)  ((n) * (n))

/*=== 表示点的坐标的结构体 ===*/
typedef struct  {
	double x;	/* X坐标 */
	double y;	/* Y坐标 */
} Point, Delta;

/*=== 表示汽车的结构体 ===*/
typedef struct  {
	Point  pt;		/* 当前位置 */
	double fuel;	/* 剩余燃料 */
} Car;

/*--- 返回点pa和点pb之间的距离---*/
double distance_of(Point pa, Point pb)
{
	return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

/*--- 显示汽车的当前位置和剩余燃料 ---*/
void put_info(Car c)
{
	printf("当前位置：(%.2f, %.2f)\n", c.pt.x, c.pt.y);
	printf("剩余燃料：%.2f升\n", c.fuel);
}

/*--- 使c指向的汽车向目标坐标dest行驶 ---*/
int move(Car *c, Point dest)
{
	double d = distance_of(c->pt, dest);	/* 行驶距离 */
	if (d > c->fuel)						/* 行驶距离超过了燃料 */
		return 0;							/* 无法行驶 */
	c->pt = dest;		/* 更新当前位置（向dest移动） */
	c->fuel -= d;		/* 更新燃料（减去行驶距离d所消耗的燃料） */
	return 1;								/* 成功行驶 */
}

int main(void)
{
	Car mycar = {{0.0, 0.0}, 90.0};

	while (1) {
		int select;
		Point dest;			/* 目的地的坐标 */
        Delta displacement; /* 位移 */

		put_info(mycar);	/* 显示当前位置和剩余燃料 */

		printf("开动汽车吗【Yes···1 / No···0】\n");
		scanf("%d", &select);
		if (select != 1)
        {
            break;
        }
        else
        {
            while(1)
            {
                printf("选择输入目的地坐标请按1\n");
                printf("选择输入行驶距离请按2\n");
                scanf("%d", &select);
                
                switch(select)
                {
                    case 1:
                        printf("目的地的X坐标:\n");  scanf("%lf", &dest.x);
                        printf("        Y坐标:\n");  scanf("%lf", &dest.y);
                        if (!move(&mycar, dest))
                        puts("\a燃料不足无法行驶.\n");
                        break;
                    case 2:
                        printf("向X方向行驶:\n");  scanf("%lf", &displacement.x);
                        printf("向Y方向行驶:\n");  scanf("%lf", &displacement.y);
                        dest.x = displacement.x + mycar.pt.x;
                        dest.y = displacement.y + mycar.pt.y;
                        if (!move(&mycar, dest))
                        puts("\a燃料不足无法行驶.\n");
                        break;
                    default:
                        printf("输入有误,请重新输入.\n");
                        break;
                }
                /* 输入正常,退出子循环 */
                if( select == 1 || select == 2 )
                {
                    break;
                }
            }
        }
		
	}

	return 0;
}
