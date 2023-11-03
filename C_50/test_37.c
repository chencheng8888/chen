#include <stdio.h>
#include <string.h>
typedef struct
{
    char tnum[20];
    int tryn;
    int lnum;
} tester;
tester p[1005];
void sort(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    sort(left, mid);
    sort(mid + 1, right);
    tester tmp[1005];
    int i = left, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (p[i].tryn < p[j].tryn)
            tmp[k++] = p[i++] ;
        if (p[i].tryn > p[j].tryn)
            tmp[k++] = p[j++];
    }
    while (i <= mid)
        tmp[k++] = p[i++];
    while (j <= right)
        tmp[k++] = p[j++];
    for (int l = 0; l < k; l++)
        p[left + l] = tmp[l];
}
int search(int aim, int N)
{
    int left = 0, right = N - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (aim == p[mid].tryn)
        {
            return mid;
        }
        if (aim < p[mid].tryn)
        {
            right = mid-1;
            mid = (left + right) / 2;
        }
        if (aim > p[mid].tryn)
        {
            left = mid+1;
            mid = (left + right) / 2;
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", &p[i].tnum, &p[i].tryn, &p[i].lnum);
    }
    sort(0, N - 1);
    int M;
    scanf("%d",&M) ;
    int snum[1005];
    int index[1005] ;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &snum[i]);
        index[i]=search(snum[i],N) ;
    }
    for(int i=0;i<M;i++){
        printf("%s %d\n",p[index[i]].tnum,p[index[i]].lnum) ;
    }
    return 0 ;
}