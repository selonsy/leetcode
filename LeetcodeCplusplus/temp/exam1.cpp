#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;
int par[100110], vis[100110];
int find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void init(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[x] = y;
    return;
}
int main() {
    int np, nl;
    cin >> np >> nl;
    int gg = 0;
    init(np + nl);
    int d;
    cin >> d;
    for (int l = 1; l <= d; l++) {
        int t1, t2;
        cin >> t1 >> t2;
        gg = 1;
        unite(t1, np + t2);
    }
    if (!gg) cout << np << endl;
    else {
        set<int> s;
        for (int i = 1; i <= np; i++) {
            int p = find(i);
            s.insert(p);
        }
        cout << s.size() - 1 << endl;
    }
    return 0;
}