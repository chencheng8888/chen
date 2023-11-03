#include <stdio.h>
int n;
int a[200][200];                 // 构建矩阵
int b[100][100][100][100] = {0}; // 记忆矩阵，减少运算量
int max = -1000;                 // 记录当前的最大值（先让其足够小）
int cur;                         // 记录此时计算的值
int Max(int a, int b)
{ // 选出两者之间较大的那一个
    if (a > b)
        return a;
    else
        return b;
}
int compute(int i, int j, int x, int y)
{ // 计算当前矩阵的大小

    if (j == y && i == x)
    { // 当只有1*1的矩阵时
        b[i][j][x][y] += a[x][y];
    }
    else if (j == y && i < x)
    { // 当只有一行时
        b[i][j][x][y] = b[i][j][x - 1][y] + a[x][y];
    }
    else if (i == x && j < y)
    { // 当只有一列时
        b[i][j][x][y] = b[i][j][x][y - 1] + a[x][y];
    }
    else
    { // 除开条状的情况
        int num = 0;
        for (int k = j; k <= y; k++)
        {
            num += a[x][k];
        }
        b[i][j][x][y] = b[i][j][x - 1][y] + num;
    }

    return b[i][j][x][y]; // 返回计算结果
}
int main()
{

    scanf("%d", &n); // 输入边长

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]); // 读取矩阵的每个元素
        }
    }
    int i, j, x, y; //(i,j)为子矩阵左上角的点的坐标,(x,y)为子矩阵右下角的点的坐标
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (x = i; x <= n; x++)
            {
                for (y = j; y <= n; y++)
                {
                    cur = compute(i, j, x, y);
                    max = Max(max, cur); // 更新最大值
                }
            }
        }
    }
    // 搜索结束
    // 输出最大值
    printf("%d\n", max);
    return 0;
}