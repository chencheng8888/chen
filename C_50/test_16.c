#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char temp;
    scanf("%d", &n);                                                                              // 先输入组数
    int num_a[200] = {0}, num_e[200] = {0}, num_i[200] = {0}, num_o[200] = {0}, num_u[200] = {0}; // 创建一个数组来储存每一组的元音数目
    temp = getchar();                                                                             // 将上面的scanf的'\n'读取出来
    for (int i = 1; i <= n; i++)
    {
        char a[200];         // 创建字符数组来储存字符串
        gets(a);             // 输入字符串
        int len = strlen(a); // 读取其长度
        for (int j = 0; j < len; j++)
        { // 开始计数
            switch (a[j])
            {
            case 'a':
                num_a[i]++;
                break;
            case 'e':
                num_e[i]++;
                break;
            case 'i':
                num_i[i]++;
                break;
            case 'o':
                num_o[i]++;
                break;
            case 'u':
                num_u[i]++;
                break;
            }
        }
        // 计数完成后开始下一组
    }
    for (int i = 1; i <= n; i++)
    { // 遍历每一组的元音数组
        printf("a: %d\n", num_a[i]);
        printf("e: %d\n", num_e[i]);
        printf("i: %d\n", num_i[i]);
        printf("o: %d\n", num_o[i]);
        printf("u: %d\n", num_u[i]);
        if (i != n)
        {
            printf("\n");
        }
        // 除了最后一组，其他组之间要有空白行
    }
    return 0;
}