#include <stdio.h>

#define MaxCounts 100
#define ERR -1
#define Six 6
#define Seven 7
#define Eight 8
#define Nine 9
#define Ten 10

int Numbers = 0;/* 学生人数 */
int Scores[MaxCounts] = {0};/* 学生分数数组 */
int counts[5] = {0};/* 分数划档数组 */
int maxmin[2] = {0};//存储最高分和最低分的数组,索引0存储最高，索引1存储最低


double average(const int arr[], int n);/* 平均值函数 */
void find_max_min(const int arr1[], int n, int arr2[]);/* 查找最大最小值函数 */
void count_scores(const int arr1[], int n, int arr2[]);/* 分数划档函数 */
void print_histogram(const int arr[]);/* 直方图打印函数 */
void put_chars(int n, char c);/* 打印字符函数 */

int main(void)
{
    /* Replay: */
    //读输入人数
    printf("请输入学生人数:\n");
    scanf("%d", &Numbers);
    
    //逐个读输入:输入学生分数，存储到数组中
    for(int i = 0; i < Numbers; i++)
    {
        printf("请输入第%d位学生的分数:\n", i+1);
        scanf("%d", &Scores[i]);
    }

    //调用相关函数计算，可以打印返回值，也可以就地（在函数体内）打印
    printf("统计结果:\n");

    /* 调用平均值函数 */
    double ave = 0.0;
    ave = average(Scores, Numbers);
    if(ave != ERR)
    {
        printf("这%d名学生们的平均分是: %.2f 分\t\n", Numbers, ave);
    }
/*     else
    {
        printf("错误\n");//由于未知原因,加上这段代码后开始编译时有概率进入死循环,故弃用之
        goto Replay;
    } */
    
    /* 调用查找最大最小值函数,打印最高、最低分 */
    find_max_min(Scores, Numbers, maxmin);
    printf("最高分是:%4d\t\n最低分是%4d\t\n", maxmin[0], maxmin[1]);

    /* 调用统计分数段函数,然后打印输出 */
    count_scores(Scores, Numbers, counts);
    printf("分数段统计:\n");
    printf("不及格人数(0-59):   %4d\n", counts[0]);
    printf("刚及格人数(60-69):  %4d\n", counts[1]);
    printf("中等人数(70-79):    %4d\n", counts[2]);
    printf("良好人数(80-89):    %4d\n", counts[3]);
    printf("优秀人数(90-100):   %4d\n", counts[4]);

    /* 打印直方图函数 */
    print_histogram(counts);

    return 0;
}

//求数组前n个元素的平均值
double average(const int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if(n)
    {
        return (double)sum/n;
    }
    else
    {
        return ERR;
    }
}


/* 不同元素代表对应分档学生数量:
不及格 (0～59) —— counts[0]
及格 (60～69) —— counts[1]
中等 (70～79) —— counts[2]
良好 (80～89) —— counts[3]
优秀 (90～100) —— counts[4] */
//arr1学生分数表,n学生人数,arr2分数划档
void count_scores(const int arr1[], int n, int arr2[])
{
    int class = 0;
    for(int i = 0; i < n; i++)
    {
        class = arr1[i] / 10;//整数除法
        if(class < Six)//不及格
        {
            arr2[0] += 1;
            continue;
        }
        else if(class == Ten)//100分,优秀
        {
            arr2[4] += 1;
            continue;
        }
        switch(class)
        {
            //及格
            case Six:
                arr2[1] += 1;
                break;
            //中等
            case Seven:
                arr2[2] += 1;
                break;
            //良好
            case Eight:
                arr2[3] += 1;
                break;
            //优秀
            case Nine:
                arr2[4] += 1;
                break;
        }
    }
}

//arr1分数数组 n学生数量 arr2极值数组
void find_max_min(const int arr1[], int n, int arr2[])
{
    int max = arr1[0];
    int min = arr1[0];
    
    for(int i = 1; i < n; i++)
    {
        if(arr1[i] > max)
        {
            max = arr1[i];
        }
        else if(arr1[i] < min)
        {
            min = arr1[i];
        }
    }

    arr2[0] = max;
    arr2[1] = min;
}

// n打印次数 c打印字符
void put_chars(int n, char c)//char类型应该用 '*' 而非 "*" 这是一个问题点
{
    for(int i = 0; i < n; i++)
    {
        putchar(c);
    }
    putchar('\n');
}
// 将数组arr[]以直方图打印出来
void print_histogram(const int arr[])
{
    printf("直方图:\t\n");    
    printf("不及格:\t");    put_chars(arr[0], '*');
    printf("刚及格\t");     put_chars(arr[1], '*');
    printf("中等:\t");      put_chars(arr[2], '*');
    printf("良好:\t");      put_chars(arr[3], '*');
    printf("优秀:\t");      put_chars(arr[4], '*');
}