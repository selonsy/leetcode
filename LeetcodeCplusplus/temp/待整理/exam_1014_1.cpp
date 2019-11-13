#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <list>
#include <iomanip>
using namespace std;

int DynamicPathPlanning(vector<vector<int>> &Grid)
{
    int n = Grid.size();
    int m = Grid[0].size();
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    int k = 0;
    while (k < m && Grid[0][k] == 0)
        dp[0][k++] = 1;
    k = 0;
    while (k < n && Grid[k][0] == 0)
        dp[k++][0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (Grid[i][j] == 0 && Grid[i][j - 1] == 0)
                dp[i][j] += dp[i][j - 1];
            if (Grid[i][j] == 0 && Grid[i - 1][j] == 0)
                dp[i][j] += dp[i - 1][j];
        }
    }
    return dp[n - 1][m - 1];
}
int main()
{
    int res;

    int _matrixGrid_rows = 0;
    int _matrixGrid_cols = 0;
    cin >> _matrixGrid_rows >> _matrixGrid_cols;
    vector<vector<int>> _matrixGrid(_matrixGrid_rows);
    for (int _matrixGrid_i = 0; _matrixGrid_i < _matrixGrid_rows; _matrixGrid_i++)
    {
        for (int _matrixGrid_j = 0; _matrixGrid_j < _matrixGrid_cols; _matrixGrid_j++)
        {
            int _matrixGrid_tmp;
            cin >> _matrixGrid_tmp;
            _matrixGrid[_matrixGrid_i].push_back(_matrixGrid_tmp);
        }
    }

    res = DynamicPathPlanning(_matrixGrid);
    cout << res << endl;

    return 0;
}