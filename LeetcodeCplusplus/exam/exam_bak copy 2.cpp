#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <functional>
#include <cstring>
#include <cmath>
#include <stack>
#include <climits>
#include <unordered_map>
using namespace std;

static string s, c;
static int n, m, v;
static unordered_map<string, int> hashs;
static unordered_map<string, int> value;
typedef pair<string, int> pii;
static vector<pii> ve;

void analysis()
{
    stack<pii> st;

    for (int i = 0; i < s.length();)
    {
        if (s[i] == '(')
        {
            st.push(make_pair(string(1, s[i]), 0));
            i++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z' || s[i] == '?')
        {
            string t(1, s[i]);
            int j = i + 1;
            while (j < n && isdigit(s[j]))
                ++j;
            int cnt = atoi(s.substr(i + 1, j - i).c_str());
            if (cnt == 0)
                cnt = 1;
            st.push(make_pair(t, cnt));
            i = j;
        }
        else if (s[i] == ')')
        {
            int j = i + 1;
            while (j < n && isdigit(s[j]))
                ++j;
            int cnt = atoi(s.substr(i + 1, j - i).c_str());
            ve.clear();
            while (!st.empty() && st.top().first != "(")
            {
                auto top = st.top();
                st.pop();
                top.second *= cnt;
                ve.push_back(top);
            }
            st.pop();
            while (!ve.empty())
            {
                st.push(ve.back());
                ve.pop_back();
            }
            i = j;
        }
    }
    while (!st.empty())
    {
        auto top = st.top();
        st.pop();
        hashs[top.first] += top.second;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> s >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> v;
        value[c] = v;
    }
    analysis();
    int cnt = 0;
    for (auto &v : hashs)
    {
        if (v.first == "?")
            cnt = v.second;
        else
            n -= value[v.first] * v.second;
    }
    cout << n / cnt << endl;
    return 0;
}