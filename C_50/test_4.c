#include <stdio.h>
int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
        return num2;
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int a, b;
    a = max(num1, num2);
    b = num1 + num2 - a;
    do
    {
        int r = a % b;
        if (r == 0)
        {
            printf("%d", b);
            break;
        }
        else
        {
            a = b;
            b = r;
        }

    } while (1);
    return 0;
}