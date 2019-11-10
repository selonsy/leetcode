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
using namespace std;
vector<vector<int>> m(6, vector<int>(6, 65));
vector<int> dist(6, 65), flag(6, 0), pre(6, -1);
void init()
{
    for (int i = 0; i < 6; i++)
    {
        m[i][i] = 0;
    }
    m[0][1] = m[1][0] = 12;
    m[2][3] = m[3][2] = 3;
    m[1][2] = m[2][1] = 10;
    m[3][4] = m[4][3] = 4;
    m[2][5] = m[5][2] = 6;
    m[0][5] = m[5][0] = 16;
    m[4][5] = m[5][4] = 2;
    m[1][5] = m[5][1] = 7;
    m[2][4] = m[4][2] = 5;
}
int main()
{
    init();
    char src, des;
    cin >> src >> des;
    int s = src - 'A', d = des - 'A';
    if (src == des)
    {
        cout << 0 << endl;
        cout << src << " " << des << endl;
        return 0;
    }

    int idx = s, dst = 0;
    dist[s] = 0;
    while (flag[d] != 1)
    {
        flag[idx] = 1;
        for (int i = 0; i < 6; i++)
        {
            if (!flag[i] && (dist[i] > dst + m[idx][i]))
            {
                dist[i] = dst + m[idx][i];
                pre[i] = idx;
            }
        }
        idx = 7, dst = 66;
        for (int i = 0; i < 6; i++)
        {
            if (!flag[i] && dist[i] < dst)
            {
                dst = dist[i];
                idx = i;
            }
        }
    }
    cout << dist[d] << endl;
    vector<int> path;
    path.push_back(d);
    while (pre[d] != -1)
    {
        d = pre[d];
        path.push_back(d);
    }
    int sz = path.size() - 1;
    cout << char('A' + path[sz]);
    for (int i = sz - 1; i >= 0; i--)
        cout << " " << char('A' + path[i]);
    cout << endl;
    return 0;
}