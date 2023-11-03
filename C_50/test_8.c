#include <stdio.h>
int Min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n;
    int a[100] = {0};
    int sum = 0;
    int min = 100;
    int max = 0;
    double grade;
    while (scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
            min = Min(min, a[i]);
            max = Max(max, a[i]);
        }
        grade = (double)(sum - min - max) / (n - 2);
        printf("%.2f", grade);
    }
    return 0;
}