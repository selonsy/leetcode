#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;
// https://www.nowcoder.com/discuss/263899?type=post&order=time&pos=&page=1
int main()
{
    int epoch, n;
    cin >> epoch >> n;
    int a, b;
    vector<vector<int>> vec(n, vector<int>(2));
    vec.clear();
    vector<int> tvec(2);
    bool flag = false;
    map<int, int> mp;
    int time = 0;
    map<int, int>::iterator imp;
    while (epoch--)
    {
        for (int i = 0; i < n; i++)
        {
            tvec.clear();
            cin >> a >> b;
            tvec.push_back(a);
            tvec.push_back(b);
            vec.push_back(tvec);
            mp.insert(pair<int, int>(b - a, i));
            /* code */
        }
        for (imp = mp.begin(); imp != mp.end(); imp++)
        {
            int index = imp->second;
            time += vec[index][0];
            if (time > vec[index][1])
            {
                flag = true;
                break;
            }
            /* code */
        }
        if (!flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
// 1
// 5
// 2 4
// 1 9
// 1 8
// 4 9
// 3 12