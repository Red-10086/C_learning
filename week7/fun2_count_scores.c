#define Six 6
#define Seven 7
#define Eight 8
#define Nine 9
#define Ten 10

int counts[5] = {0};


void count_scores(const int arr1[], int n, int arr2[]);


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