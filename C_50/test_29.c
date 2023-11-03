#include <stdio.h>
int sum = 0;
int N;
int a[10];
int b[10] = {0};
void dfs(int step, int product)
{
    if (step == 2)
    {
        sum += product;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            if (step == 0)
            {
                dfs(step + 1, 10 * a[i]);
            }
            if (step == 1)
            {
                dfs(step + 1, product + a[i]);
            }
            b[i] = 0;
        }
    }
}
int main()
{

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    dfs(0, 0);
    printf("%d\n",sum) ;
    return 0;
}