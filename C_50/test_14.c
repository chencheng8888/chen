#include <stdio.h>
int Min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int main()
{
    int n;
    int min, temp;
    int x = 0;
    int a[100];
    while (scanf("%d", &n) && n != 0)
    {
        for (int i = 0; i < n; i++)
        {

            scanf("%d", &a[i]);
            if (i == 0)
                min = a[i];
            temp = Min(min, a[i]);
            if (temp < min)
            {
                min=temp ;
                x=i ;
            }
        }
        a[x] = a[0];
        a[0] = min;
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}