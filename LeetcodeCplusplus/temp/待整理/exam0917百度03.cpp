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

// 3.给一个树，节点1-n，点1是黑色点n是白色其他无色，2个人轮流操作博弈，1号每轮选一个黑色点，染黑相邻无色的点，2号每轮选白点同样操作。（选的点必须有相邻的无色点）第一个操作不了的人输。问这场博弈谁赢...范围1e5
// 反正是树，就当做1是根节点。所以白色能染最高的白色点下的所有点，黑色能染剩下的点，所以关键是白色最高点多高，所以开局双方都在1-n的最短路上染，染相邻了局势就定了。
// 然后根据这个局势，算出来黑白能染色几次，染色多的赢。
// 分分钟口头ac..代码写了至少40分钟..写的非常难看，删删改改的..感觉有其他方法..
#define LL long long
struct node
{
    int v, ne;
} a[200005];
int k;
int h[100005];
int fa[100005];
bool vi[100005];
int color[100005];
int co1, co2;
void add(int u, int v) //初始k=1
{
    a[k].v = v, a[k].ne = h[u], h[u] = k++;
}
void find_fa(int x)
{
    vi[x] = 1;
    for (int i = h[x]; i; i = a[i].ne)
    {
        if (vi[a[i].v] == 0)
            fa[a[i].v] = x, find_fa(a[i].v);
    }
}
int get_dis(int x)
{
    if (fa[x] == 1)
        return 1;
    return get_dis(fa[x]) + 1;
}

void coloring1(int x)
{
    int flag = 0;
    for (int i = h[x]; i; i = a[i].ne)
    {
        int ne = a[i].v;
        if (color[ne] == 0)
        {
            color[ne] = 1;
            flag++;
            coloring1(ne);
        }
    }
    if (flag != 0)
        co1++;
}
void coloring2(int x)
{
    int flag = 0;
    for (int i = h[x]; i; i = a[i].ne)
    {
        int ne = a[i].v;
        if (color[ne] == 0)
        {
            color[ne] = 2;
            flag++;
            coloring2(ne);
        }
    }
    if (flag != 0)
        co2++;
}
int get_fa(int x, int count)
{
    if (count == 0)
        return x;
    return get_fa(fa[x], count - 1);
}
int main()
{
    int i, j;
    int n;
    scanf("%*d");
    while (~scanf("%d", &n))
    {
        k = 1;
        memset(h, 0, sizeof(h));
        memset(fa, 0, sizeof(fa));
        memset(vi, 0, sizeof(vi));
        memset(color, 0, sizeof(color));
        for (i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        find_fa(1);
        int dis = get_dis(n);
        int fa2 = get_fa(n, (dis - 1) / 2);
        co1 = 0, co2 = 0;
        color[1] = 1, color[n] = 2;
        int it = n;
        for (i = 0; i < (dis - 1) / 2; i++)
        {
            color[fa[it]] = 2;
            it = fa[it];
        }
        coloring1(1);
        for (i = 1; i <= n; i++)
        {
            if (color[i] == 2)
                coloring2(i);
        }
        puts(co2 <= co1 ? "niuniu" : "niumei");
    }
    return 0;
}