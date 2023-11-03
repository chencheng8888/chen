#include <stdio.h>
#include <math.h>
double Max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    double max = 0;
    scanf("%d", &n); // 输入组数
    int a[10000][2];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i][0], &a[i][1]);
        int c;
        c = a[i][0] * a[i][0] + a[i][1] * a[i][1];
        max = Max(sqrt(c), max);
    }
    printf("%.2f", max);
    return 0;
}