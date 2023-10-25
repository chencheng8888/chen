//这是第一次写的代码，会超时，但运行没问题
#include <stdio.h>
int n;
int a[200][200];    // 构建矩阵
int max = -1000; // 记录当前的最大值（先让其足够小）
int cur;            // 记录此时计算的值
int Max(int a, int b)
{ // 选出两者之间较大的那一个
    if (a > b)
        return a;
    else
        return b;
}
int compute(int i, int j, int x, int y)
{                // 计算当前矩阵的大小
    int num = 0; // 记录矩阵的大小
    for (int p = i; p <= x; p++)
    {
        for (int q = j; q <= y; q++)
        {
            num += a[p][q]; // 计算
        }
    }
    return num; // 返回计算结果
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