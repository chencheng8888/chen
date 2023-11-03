#include <stdio.h>
#include <math.h>
_Bool isprime(int num)
{ // 判断一个数是否是素数
    if (num == 1)
        return 0;
    if (num == 2 || num == 3)
        return 1;
    for (int i = 2; i <= sqrt(num); i++)
    { // 只用递增到根号num即可
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (isprime(i))
        {
            printf("%d ", i); // 如果是素数，就打印输出这个数
        }
    }
    return 0;
}