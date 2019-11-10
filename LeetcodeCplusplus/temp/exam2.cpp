#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int n, i, j, dp[100010], x[100010], max_len;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> x[i];
    dp[0] = 1;
    for (i = 1; i < n; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (x[i] > x[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    for (i = max_len = 0; i < n; i++)
        max_len = max(max_len, dp[i]);
    cout << max_len << endl;

    return 0;
}
