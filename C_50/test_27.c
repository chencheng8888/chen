#include <stdio.h>
#include <stdlib.h>
double Q;
int N;
double Max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}
void dfs(int index, double sum, int cn, double *a, int *b, double *c)
{
    if (index == cn + 1 && sum <= Q)
    {
        *c = Max(*c, sum);
        return;
    }
    for (int i = 0; i <= cn; i++)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            // 对于每个值它都可以选择是否加上它
            dfs(index + 1, sum, cn, a, b, c);
            dfs(index + 1, sum + a[i], cn, a, b, c);
            b[i] = 0;
        }
    }
}
int main()
{
    while (scanf("%lf%d", &Q, &N) && N != 0)
    { // 输入报销额度和发票数
        double a[100] = {0};
        int b[100] = {0};                             // 用来判断该支票是否计算过
        double *c = (double *)malloc(sizeof(double)); // 用来记录最大值
        *c = 0;
        int j = 0;
        for (int i = 0; i < N; i++)
        {
            int m;
            double sum = 0;
            int tag = 1;     // 判断支票是否合法 ，默认为合法的
            scanf("%d", &m); // 输入发票的物品数
            getchar();
            for (int j = 1; j <= m; j++)
            {
                char type;
                double amount;

                scanf("%c:%lf", &type, &amount); // 输入种类和每个物品的面额
                getchar();
                if ((amount <= 600) && ((type - 'A') <= 2))
                {
                    sum += amount; // 如果种类是'A','B','C'的一种，并且每个商品的面额小于600，就积累总面额
                }
                else
                {
                    tag = 0; // 否则就标记该支票为不合法的
                }
            }
            if (sum <= 1000 && tag == 1)
            { // 如果支票面额不超过1000并且支票合法，就将支票面额加入到a数组中
                a[j] = sum;
                j++;
            }
            else
                continue;
        }

        dfs(0, 0, j - 1, a, b, c);
        printf("%.2lf\n", *c);
        free(c);
        N = 0;
    }

    return 0;
}