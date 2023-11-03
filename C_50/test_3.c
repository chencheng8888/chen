#include <stdio.h>
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        if (i <= 3)
        {
            for (int j = 1; j <= i; j++)
            {
                printf(" ");
            }
            for (int k = 1; k <= (7 - 2 * i); k++)
            {
                printf("*");
            }
            printf("\n");
        }
        else
        {
            for (int j = 1; j <= (6 - i); j++)
            {
                printf(" ");
            }
            for (int k = 1; k <= (2 * i - 5); k++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}