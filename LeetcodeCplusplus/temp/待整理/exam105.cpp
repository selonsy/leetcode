#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minsum(vector<vector<int>> a, vector<int> &reg, vector<string> &my)
{
    vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), a[0][0]));

    for (int i = 1; i < a.size(); i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }
    for (int j = 1; j < a[0].size(); j++)
    {
        dp[0][j] = dp[0][j - 1] + a[0][j];
    }
    for (int i = 1; i < a.size(); i++)
    {
        for (int j = 1; j < a[0].size(); j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    /*for (int i = 0; i < dp.size(); i++){
        for (int j = 0; j < dp[0].size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    int i = dp.size() - 1;
    int j = dp[0].size() - 1;
    while (i >= 0 && j >= 0)
    {
        reg.push_back(a[i][j]);
        my.push_back(to_string(i) + " " + to_string(j));
        if (i > 0 && j > 0)
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
            continue;
        }
        else if (i == 0)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    return dp[a.size() - 1][a[0].size() - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            v1.push_back(a);
        }
        v.push_back(v1);
    }

    vector<int> reg;
    vector<string> my;
    int res = minsum(v, reg, my);
    // reverse(reg.begin(), reg.end());
    reverse(my.begin(), my.end());
    for (int i = 0; i < reg.size(); i++)
    {
        // cout << reg[i] << endl;
        cout << my[i] << endl;
    }

    // system("pause");
    return 0;
}