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
int res = 0;
void getvalue(string s, int n, long t, int now)
{
    if (n == 0 && now == t)
    {
        res++;
        return;
    }
    if (n == 1)
    {
        if (now + 9 == t || now - 9 == t)
        {
            res++;
        }
        return;
    }
    int addNum = 0;
    for (int i = 1; i <= n; i++)
    {
        addNum = addNum * 10 + (s[i - 1] - '0');
        string news = s + to_string(i);
        getvalue(news, n - i, t, now + addNum);
        if (n != 9)
        {
            getvalue(news, n - i, t, now - addNum);
        }
    }
}
int main()
{
    string s, t;
    cin >> s >> t;
    long tt = atoi(t.c_str());
    getvalue(s, s.size(), tt, 0);
    cout << res;
}
