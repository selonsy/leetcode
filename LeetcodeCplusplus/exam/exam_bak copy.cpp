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

static int N, K;
static int M;

bool check_nums(int x)
{
    do
    {
        if (x % 10 == K)
            return true;
        x /= 10;
    } while (x);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M >> K;
        int ans = 0;
        for (int i = 0; i <= M; i++)
        {
            if (check_nums(i))
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}