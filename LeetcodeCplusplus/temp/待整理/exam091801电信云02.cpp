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
vector<string> split(const string &str, const string &delim)
{
    vector<string> res;
    if ("" == str)
        return res;
    //先将要切割的字符串从string类型转换为char*类型
    char *strs = new char[str.length() + 1]; //不要忘了
    strcpy(strs, str.c_str());

    char *d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while (p)
    {
        string s = p;     //分割得到的字符串转换为string类型
        res.push_back(s); //存入结果数组
        p = strtok(NULL, d);
    }
    return res;
}
int mark[10000];
int ans1[10000], ans2[10000];
int main()
{
    string s;
    cin >> s;
    if (s == ";")
    {
        cout << "True";
        return 0;
    }
    vector<string> vec = split(s, ";");
    string a, b;
    a = vec[0], b = vec[1];
    memset(mark, 0, sizeof(mark));
    memset(ans1, 0, sizeof(ans1));
    memset(ans2, 0, sizeof(ans2));
    int len1 = a.size();
    int len2 = b.size();
    if (len1 != len2)
    {
        cout << "False";
        return 0;
    }
    int top = 1;
    for (int i = 0; i < len1; i++)
    {
        int t = (int)a[i];
        if (mark[t] == 0)
        {
            mark[t] = top;
            ans1[i] = mark[t];
            top++;
        }
        else
        {
            ans1[i] = mark[t];
        }
    }
    memset(mark, 0, sizeof(mark));
    top = 1;
    for (int i = 0; i < len2; i++)
    {
        int t = (int)b[i];
        if (mark[t] == 0)
        {
            mark[t] = top;
            ans2[i] = mark[t];
            top++;
        }
        else
        {
            ans2[i] = mark[t];
        }
    }
    for (int i = 0; i < len1; i++)
    {
        if (ans1[i] != ans2[i])
        {
            cout << "False";
            return 0;
        }
    }
    cout << "True";
    return 0;
}