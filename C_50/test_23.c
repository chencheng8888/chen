#include <stdio.h>
#include <string.h>
int main()
{
    char a[1002];
    gets(a);
    int b[10] = {0};
    for (int i = 0; i < strlen(a); i++)
    {
        b[a[i] - '0']++;
    }

    for (int j = 0; j <= 9; j++)
    {
        if (b[j] != 0)
        {
            printf("%d:%d\n", j, b[j]);
        }
    }
    return 0;
}