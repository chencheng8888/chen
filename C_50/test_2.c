#include <stdio.h>
int main()
{
    int sub1, sub2;
    int pass1, pass2;
    pass1 = 0;
    pass2 = 0;
    scanf("%d %d", &sub1, &sub2);
    if ((sub1 < 0 || sub1 > 100) || (sub2 < 0 || sub2 > 100))
    {
        printf("it is error");
        return 0;
    }
    switch (sub1 / 10)
    {
    case 10:
        pass1 = 1;
        break;
    case 9:
        pass1 = 1;
        break;
    case 8:
        pass1 = 1;
        break;
    case 7:
        pass1 = 1;
        break;
    case 6:
        pass1 = 1;
        break;
    default:
        pass1 = 0;
        break;
    }
    switch (sub2 / 10)
    {
    case 10:
        pass2 = 1;
        break;
    case 9:
        pass2 = 1;
        break;
    case 8:
        pass2 = 1;
        break;
    case 7:
        pass2 = 1;
        break;
    case 6:
        pass2 = 1;
        break;
    default:
        pass2 = 0;
        break;
    }
    if (pass1 && pass2)
    {
        printf("it is pass");
    }
    else
    {
        printf("it is not pass");
    }
    return 0;
}