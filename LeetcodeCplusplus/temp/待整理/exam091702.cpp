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
#include <climits>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int res = INT_MAX;
    int temp1, temp2;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            /* code */
            temp1 = (n - i) * (m - j);
            temp2 = i + j;
            if ((temp1 <= k) && (temp2 < res))
                res = temp2;
            else if (temp1 > k || temp2 >= res)
                break;
        }
        /* code */
    }
    cout << res;
    return 0;
}