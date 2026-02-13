#define ERR -1
double average(const int arr[], int n);

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