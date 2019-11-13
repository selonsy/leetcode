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

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int BestMatch(vector<int> LimitArray, vector<vector<int>> DegMatrix)
{
    int res = 0;
    int p_count = DegMatrix.size();
    int r_count = LimitArray.size();
    vector<bool> visited(p_count, false);
    while (p_count)
    {
        for (int i = 0; i < r_count; i++)
        {
            if (LimitArray[i] <= 0)
                continue;
            int max_t = 0;
            int j_index;
            for (int j = 0; j < p_count; j++)
            {
                if (visited[j] == false && DegMatrix[j][i] > max_t)
                {
                    max_t = DegMatrix[j][i];
                    j_index = j;
                }
            }
            LimitArray[i]--;
            res += max_t;
            visited[j_index] = true;
        }
        p_count--;
    }
    return res;
}
/******************************结束写代码******************************/

int main()
{
    int res;

    int _LimitArray_size = 0;
    int _DegMatrix_rows = 0;
    int _DegMatrix_cols = 0;
    cin >> _DegMatrix_rows >> _DegMatrix_cols;

    _LimitArray_size = _DegMatrix_cols;

    vector<int> _LimitArray;
    int _LimitArray_item;
    for (int _LimitArray_i = 0; _LimitArray_i < _LimitArray_size; _LimitArray_i++)
    {
        cin >> _LimitArray_item;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        _LimitArray.push_back(_LimitArray_item);
    }

    vector<vector<int>> _DegMatrix(_DegMatrix_rows);
    for (int _DegMatrix_i = 0; _DegMatrix_i < _DegMatrix_rows; _DegMatrix_i++)
    {
        for (int _DegMatrix_j = 0; _DegMatrix_j < _DegMatrix_cols; _DegMatrix_j++)
        {
            int _DegMatrix_tmp;
            cin >> _DegMatrix_tmp;
            _DegMatrix[_DegMatrix_i].push_back(_DegMatrix_tmp);
        }
    }

    res = BestMatch(_LimitArray, _DegMatrix);
    cout << res << endl;

    return 0;
}
