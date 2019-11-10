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

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        b.push_back(t);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res ^= (a[i] + b[j]);
        }
    }
    cout << res;
}
