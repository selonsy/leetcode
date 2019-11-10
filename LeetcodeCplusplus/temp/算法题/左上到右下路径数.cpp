/*
1、m*n的棋盘，每次向右或向下移动一格。求有多少种路径。
2、变种，不走格子，走线段。
如：2*2的棋盘，按格子走即为2种。按线段走，即为6种。

3、同上，按格子走，格子有权值，求最小路径和。
*/
#include <iostream>
using namespace std;
int func_a_1(int m, int n)
{
    // 走线段
    // 递归求法，时间复杂度O(2 ^ n)
    if (m == 0 && n == 0)
    {
        return 0;
    }
    if (m == 0 || n == 0)
    {
        return 1;
    }
    return func_a_1(m - 1, n) + func_a_1(m, n - 1);
}
int func_a_2(int m, int n)
{
    // 走线段，非递归求法
    // 其实就是一个排列组合计算，对方向编号，向下是0，向右是1，那么从左上角走到右下角一定要经过 M 个1和 N 个0。
    // 这个题目可以转化为从 M + N 个盒子中挑出 M 个盒子有多少种方法。 就是 C(M + N, M) ，或者C(M + N, N)。
    int sum = 0;
    int sum1 = 1;
    int sum2 = 1;
    if (m >= n)
    {
        // (M+N)!/(N!M!)
        for (int i = m + 1; i <= (m + n); i++)
        {
            sum1 = sum1 * i;
        }
        for (int i = 1; i <= n; i++)
        {
            sum2 = sum2 * i;
        }
    }
    else
    {
        for (int i = n + 1; i <= (m + n); i++)
        {
            sum1 = sum1 * i;
        }
        for (int i = 1; i <= m; i++)
        {
            sum2 = sum2 * i;
        }
    }
    sum = sum1 / sum2;
    return sum;
}
int func_a_3(int m, int n)
{
    // 走线段，非递归求法
    int **Q = new int *[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        Q[i] = new int[n + 1]();
    }
    //初始化
    Q[0][0] = 0;
    for (int j = 1; j <= n; ++j)
        Q[0][j] = 1;
    for (int i = 1; i <= m; ++i)
        Q[i][0] = 1;
    //迭代计算
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            Q[i][j] = Q[i - 1][j] + Q[i][j - 1];
        }
    }
    int res = Q[m][n];
    delete[] Q;
    return res;
}
int func_b_1(int m, int n)
{
    // 走格子，递归求法
    int num = 0;
    if (m == 1 && n == 1)
    {
        return 1;
    }
    if (m > 1)
    {
        num += func_b_1(m - 1, n);
    }
    if (n > 1)
    {
        num += func_b_1(m, n - 1);
    }
    return num;
}
int func_b_2(int m, int n)
{
    // 走格子，非递归求法
    int **d = new int *[m];
    for (int i = 0; i < m; i++)
    {
        d[i] = new int[n];
    }
    d[0][0] = 0;
    for (int i = 1; i < m; i++)
        d[i][0] = 1;
    for (int i = 1; i < n; i++)
        d[0][i] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            d[i][j] = d[i - 1][j] + d[i][j - 1];
        }
    }
    return d[m - 1][n - 1];
}
int func_c_1(int grid[][4], int m, int n)
{
    /*
    * 给定一个矩阵m，从左上角开始每次只能向右走或者向下走，最后达到右下角的位置，
    * 路径中所有数字累加起来就是路径和，返回所有路径的最小路径和，如果给定的m如下，那么路径1,3,1,0,6,1,0就是最小路径和，返回12.
    1 3 5 9
    8 1 3 4
    5 0 6 1
    8 8 4 0
    分析: 对于这个题目，假设m是m行n列的矩阵，那么我们用dp[m][n]来抽象这个问题，
    dp[i][j]表示的是从原点到i,j位置的最短路径和。我们首先计算第一行和第一列，直接累加即可，
    那么对于其他位置，要么是从它左边的位置达到，要么是从上边的位置达到，我们取左边和上边的较小值，然后加上当前的路径值
    
    得到的公式如下:
    m(0,0)            if(i==0 && j==0)
    dp(i,j-1)+m(i,j)  if(i==0)
    dp(i-1,j)+m(i,j)  if(j==0)
    min{dp(i,j-1)+m(i,j),dp(i-1,j)+m(i,j)}  else
    */
    int **dp = new int *[m + 1];
    for (int i = 0; i < m; i++)
        dp[i] = new int[n + 1];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[0][0];
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            }
            else
            {
                int temp1 = dp[i][j - 1] + grid[i][j];
                int temp2 = dp[i - 1][j] + grid[i][j];
                int min = temp1 < temp2 ? temp1 : temp2;
                dp[i][j] = min;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int main()
{
    int m, n;
    cin >> m >> n;

    //走线段，递归
    int a1 = func_a_1(m, n);
    cout << a1 << endl;
    //走线段，非递归(排列组合)
    int a2 = func_a_2(m, n);
    cout << a2 << endl;
    //走线段，非递归
    int a2_1 = func_a_3(m, n);
    cout << a2 << endl;

    //走格子，递归
    int a3 = func_b_1(m, n);
    cout << a3 << endl;
    //走格子，非递归
    int a4 = func_b_2(m, n);
    cout << a4 << endl;

    // 走格子，带权值，求最短路径
    int martix[4][4] = {
        {1, 3, 5, 9},
        {8, 1, 3, 5},
        {5, 0, 6, 1},
        {8, 8, 4, 0}};
    int a5 = func_c_1(martix, 4, 4);
    cout << a5 << endl;
}