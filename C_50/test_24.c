#include <stdio.h>
#include <string.h>
int main()
{
    char a[102];
    fgets(a,sizeof(a),stdin) ;
    int num = 0;
    for (int i = 0; i < strlen(a)-1; i++)
    {
        num += (a[i] - '0');
    }
    if (num == 0)
    {
        printf("ling");
        return 0;
    }
    int d[20]={0};
    int k = 0;
    while (num != 0)
    {
        d[k] = num % 10;
        num /= 10;
        k++;
    }
    for (int i = k - 1; i >= 0; i--)
    {
       
    
        if (d[i] == 0)
        {
            printf("ling");
        }
        if (d[i] == 1)
        {
            printf("yi");
        }
        if (d[i] == 2)
        {
            printf("er");
        }
        if (d[i] == 3)
        {
            printf("san");
        }
        if (d[i] == 4)
        {
            printf("si");
        }
        if (d[i] == 5)
        {
            printf("wu");
        }
        if (d[i] == 6)
        {
            printf("liu");
        }
        if (d[i] == 7)
        {
            printf("qi");
        }
        if (d[i] == 8)
        {
            printf("ba");
        }
        if (d[i] == 9)
        {
            printf("jiu");
        }
        if (i != 0)
            printf(" ");
    }
    return 0;
}