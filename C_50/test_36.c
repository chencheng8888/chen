#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[8];
    int year;
    int month;
    int day;
} person;
void swap(person p[], int a, int b)
{
    char temp1[8];
    strcpy(temp1, p[a].name);
    int temp2 = p[a].year;
    int temp3 = p[a].month;
    int temp4 = p[a].day;
    strcpy(p[a].name, p[b].name);
    strcpy(p[b].name, temp1);
    p[a].year = p[b].year;
    p[b].year = temp2;
    p[a].month = p[b].month;
    p[b].month = temp3;
    p[a].day = p[b].day;
    p[b].day = temp4;
}
int older(person p[], int a, int b)
{
    if (p[a].year > p[b].year)
    {
        return 0;
    }
    else if (p[a].year == p[b].year && ((p[a].month > p[b].month) || (p[a].month == p[b].month && p[a].day >= p[b].day))){
        return 0 ;
    }
    else return 1;
}
void sort(person p[], int left, int right)
{
    if(left>=right) return ;
    int i=left ,j=right ;
    int mid=(left+right)/2 ;
    while(i<=j){
        while(older(p,j,mid)) j-- ;
        while(older(p,mid,i)) i++ ;
        if(i<=j){
            swap(p,i,j) ;
            i++ ;
            j-- ;
        }
    }
    sort(p,left,j) ;
    sort(p,i,right) ;

}
int main()
{
    int num;
    scanf("%d", &num);
    person p[100005];
    int tmp = num;
    for (int i = 0; i < tmp;)
    {
        scanf("%s %d/%d/%d", &p[i].name, &p[i].year, &p[i].month, &p[i].day);
        if ((2014 - p[i].year > 200) || ((2014 - p[i].year == 200) && ((p[i].month < 9) || (p[i].month == 9 && p[i].day < 6))))
        {
            tmp--;
        }
        else if ((p[i].year > 2014) || ((p[i].year == 2014) && ((p[i].month > 9) || (p[i].month == 9 && p[i].day > 6))))
        {
            tmp--;
        }
        else
            i++;
    }
    sort(p,0,tmp-1) ;
    printf("%d %s %s", tmp,p[tmp-1].name,p[0].name);
    return 0;
}