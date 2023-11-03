#include <stdio.h>
#include <string.h>
char a[100000][5];
int b[100000] = {0};
int c[100000] = {0};
int n;
void he(int i)
{
    int sum = 0;
    for (int j = 0; j < strlen(a[i]); j++)
    {
        sum += (a[i][j] - '0');
    }
    b[i] = sum;
}
void sort(int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int mid = (left + right) / 2;
    int temp = b[mid];
    while (i <= j)
    {
        while (b[j] > temp)
            j--;
        while (b[i] < temp)
            i++;
        if (i <= j)
        {
            int tmp = b[i];
            b[i] = b[j];
            b[j] = tmp;
            i++;
            j--;
        }
    }
    sort(left, j);
    sort(i, right);
}
int search()
{
    int k = 0;
    for (int i = 0; i < n;i++)
    {
       if(i==0){
        c[k]=b[i] ;
        k++ ;
        continue ;
       }
       if(b[i]!=b[i-1]){
        c[k]=b[i] ;
        k++ ;
       }
    }
    return k;
}
int main()
{

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        he(i);
    }
    sort(0, n - 1);
    int indx = search();
    printf("%d\n", indx);
    for (int i = 0; i < indx; i++)
    {
        if (i != 0)
            printf(" %d", c[i]);
        else
            printf("%d", c[i]);
    }
}