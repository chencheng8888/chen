#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[100] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j;
            for (j = i - gap; j >= 0 && (abs(temp) < abs(a[j])); j -= gap)
            {
                a[j + gap] = a[j];
            }
            a[j + gap] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
            printf("%d\n", a[i]);
        else
            printf("%d ", a[i]) ;
    }
    return 0;
}