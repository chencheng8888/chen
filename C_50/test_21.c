#include <stdio.h>
int N;

int cnt = 0; // 记录种数
void dance(int n, int *a)
{

    if (n == N)
    {
        if (a[n] == 1)
            cnt++; // 如果跳了N次，并且回到了A处，种数加1
        return;    // 返回上一级
    }
    for (int i = 1; i <= 3; i++)
    {
        if (a[n] != i)
        {
            // 检查当前的字母（数字），如果不是自己就令下一步是它，并且调用下一级
            a[n + 1] = i;
            dance(n + 1, a);
        }
    }
}
int main()
{

    while (scanf("%d", &N) && N != 0) // 输入要跳的次数
    {
        int a[200] = {1};
        dance(0, a);         // 从0级开始调用
        printf("%d\n", cnt); // 输出种数
        cnt = 0;             // 还原
    }
    return 0;
}