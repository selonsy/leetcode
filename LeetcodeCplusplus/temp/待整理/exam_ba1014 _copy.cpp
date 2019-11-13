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
#include <iomanip>
using namespace std;
int main()
{
    double n;
    int m;
    while (scanf("%lf %d", &n, &m))
    {
        double res = 0;
        for (int i = 0; i < m; i++)
        {
            res += n;
            n = sqrt(n);
        }
        // printf("%.2lf\n", res);
        cout << setiosflags(ios::fixed) << setprecision(2) << res << endl;
    }
    return 0;
}