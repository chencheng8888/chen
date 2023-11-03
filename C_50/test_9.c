#include <stdio.h>
int main()
{
    int year, mouth, day;
    scanf("%d-%d-%d", &year, &mouth, &day);
    int num = 0;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        switch (mouth)
        {
        case 12:
            num += 30;
        case 11:
            num += 31;
        case 10:
            num += 30;
        case 9:
            num += 31;
        case 8:
            num += 31;
        case 7:
            num += 30;
        case 6:
            num += 31;
        case 5:
            num += 30;
        case 4:
            num += 31;
        case 3:
            num += 29;
        case 2:
            num += 31;
        case 1:
            num += day;
        }
    }
    else
    {
        switch (mouth)
        {
        case 12:
            num += 30;
        case 11:
            num += 31;
        case 10:
            num += 30;
        case 9:
            num += 31;
        case 8:
            num += 31;
        case 7:
            num += 30;
        case 6:
            num += 31;
        case 5:
            num += 30;
        case 4:
            num += 31;
        case 3:
            num += 28;
        case 2:
            num += 31;
        case 1:
            num += day;
        }
    }
    printf("%d", num);
    return 0;
}