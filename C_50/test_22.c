#include <stdio.h>
#define CLK_TCK 100
int main()
{
    long long C1, C2;
    scanf("%ld %ld", &C1, &C2);
    long long det, pdet;
    det = (C2 - C1) / CLK_TCK;
    pdet = (C2 - C1) % CLK_TCK;
    if (pdet >= 50)
    {
        det++;
    }
    long long hour = det / 3600;
    int minute = (det - 3600 * hour) / 60;
    int second = det - 3600 * hour - 60 * minute;
    printf("%02ld:%02d:%02d", hour, minute, second);

    return 0;
}