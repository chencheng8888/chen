#include <stdio.h>
#include <string.h>
int main()
{
    char a[4];
    scanf("%s", &a);
    int num = strlen(a);
    if (num == 1)
    {
        for (int i = 1; i <= (a[0] - '0'); i++)
        {
            printf("%d", i);
        }
    }
    if (num == 2)
    {
        for (int i = 1; i <= (a[0] - '0'); i++)
        {
            printf("S");
        }
        for (int i = 1; i <= (a[1] - '0'); i++)
        {
            printf("%d", i);
        }
    }
    if (num == 3)
    {
        for (int i = 1; i <= (a[0] - '0'); i++)
        {
            printf("B");
        }
        for (int i = 1; i <= (a[1] - '0'); i++)
        {
            printf("S");
        }
        for (int i = 1; i <= (a[2] - '0'); i++)
        {
            printf("%d", i);
        }
    }
    return 0 ;
}