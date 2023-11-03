#include <stdio.h>
int main()
{
    int n;
    int a[100];
    int sum = 0;
    double average;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    average = (double)sum / n;
    printf("%.2f", average);
    return 0;
}