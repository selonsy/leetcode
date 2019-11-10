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

// 2.给n个任务，每个任务一个ddl，一个完成该任务需要的时间，一次只能做一个任务直到做完，问可不可能每个任务都在ddl之前完成。范围2e5
// 贪心..对ddl排序，先做ddl小的就是最优解....
#define LL long long
struct node
{
    int a, b;
} t[200005];
bool cmp(node x, node y)
{
    return x.b < y.b;
}
int main()
{
    int i, j;
    int n;
    scanf("%*d");
    while (~scanf("%d", &n))
    {
        for (i = 0; i < n; i++)
            scanf("%d%d", &t[i].a, &t[i].b);
        sort(t, t + n, cmp);
        LL sum = 0;
        for (i = 0; i < n; i++)
        {
            sum += t[i].a;
            if (sum > 1LL * t[i].b)
                break;
        }
        puts(i == n ? "Yes" : "No");
    }
    return 0;
}