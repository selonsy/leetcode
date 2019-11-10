#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<list>
#include<functional>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;


static int n;
static const int maxn = 2 * 1e4 + 10;
static vector<int> ve;
static vector<int> G[maxn];
static vector<int> vis;

int __gcd(int n, int m)
{
    return m == 0 ? n : __gcd(m, n%m);
}

void dfs(int x,int sum, int& tans)
{
    tans = max(tans, sum);
    for (int i = 0; i < G[x].size(); i++)
    {
        int v = G[x][i];
        if (vis[v]) continue;
        vis[v] = 1;
        dfs(x, sum + 1, tans);
        vis[v] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    ve.resize(n, 0); vis.resize(n, 0);
    for (int i = 0; i < n; i++) cin >> ve[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (__gcd(ve[i], ve[j])>1)
            {
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        vis[i] = 1;
        int tans = 0;
        dfs(i, 1, tans);
        vis[i] = 0;
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}