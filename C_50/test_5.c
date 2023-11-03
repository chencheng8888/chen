#include <stdio.h>
#include <math.h>
_Bool isprime(int num)
{
    if (num == 2 || num == 3)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
                return 0;
            else
                continue;
        }
        return 1;
    }
}
int main()
{
    int cnt = 0;
    for (int i = 2; i <= 100; i++)
    {
        if (isprime(i) && cnt <= 5)
        {
            cnt++;
            if (cnt == 5)
            {
                cnt = 0;
                printf("%2d\n", i);
            }
            else
            {
                printf("%2d ", i);
            }
        }
    }
    return 0;
}