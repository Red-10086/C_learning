

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