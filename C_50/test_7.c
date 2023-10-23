#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[100];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num % 2 != 0)
        {
            a[j] = num;
            j++;
        }
    }
    int product = 1;
    for (int i = 0; i < j; i++)
    {
        product *= a[i];
    }
    printf("%d", product);
    return 0;
}