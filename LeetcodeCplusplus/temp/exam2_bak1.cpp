#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

long long res[10001] = {0};
const long long mod = 1000000007;

int main() {
    int n;
    res[0] = 1;
    res[2] = 1;
    res[4] = 2;
    res[6] = 5;

    cin >> n;

    for (int i = 8; i <= n; i += 2) {
        int left = 0;
        long long result = 0;
        while (left < i) {
            result += (res[left] * res[n - left - 2]) % mod;
            result %= mod;
            left += 2;
        }
        res[i] = result;
    }
    cout << res[n] << endl;
    return 0;
}