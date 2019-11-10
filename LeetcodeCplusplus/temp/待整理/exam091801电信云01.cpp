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
    int n,temp;
    cin>>n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>temp;
        vec.push_back(temp);
    }
    int res=0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        res^=vec[i];
    }
    cout<<res;
    
    
    return 0;
}