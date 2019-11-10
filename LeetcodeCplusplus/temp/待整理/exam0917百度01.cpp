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

// 1.给n,m,k,范围1e9，求满足条件的自然数a,b,(n-a)(m-b)<=k,且a+b最小
// acm签到题的感觉..只在n,m中较小的一个减可以保证a+b最小，类似均值不等式的原理...就是和一定的时候2个数越接近积越大，反之也是。
// n,m已经定了，要让他们的和减少最小的情况下积减少最大，就让他们的差值尽量大，所以全减到最小的上保证差值最大。
// (n-a)*m<=k，移项出来O(1)的公式就行
#define LL long long
int main()
{
    LL n, m, k;
    while (~scanf("%lld%lld%lld", &n, &m, &k))
    {
        if (n > m)
            swap(n, m);
        printf("%lld\n", n - k / m);
    }
    return 0;
}