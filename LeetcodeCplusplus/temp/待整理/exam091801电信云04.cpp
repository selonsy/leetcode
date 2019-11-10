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
int mark[1000001];
int ans1[101000], ans2[010010];
bool isIsomorphic(char *s, char *t)
{
    memset(mark, 0, sizeof(mark));
    memset(ans1, 0, sizeof(ans1));
    memset(ans2, 0, sizeof(ans2));

    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2)
        return false;

    int top = 1; ///记录出现了几个的字符
    for (int i = 0; i < len1; i++)
    {
        if (mark[(int)s[i]] == 0)
        {
            mark[(int)s[i]] = top;     ///标记字符
            ans1[i] = mark[(int)s[i]]; ///赋值
            top++;
        }
        else
        {

            ans1[i] = mark[(int)s[i]];
        }
    }
    memset(mark, 0, sizeof(mark));
    top = 1;
    for (int i = 0; i < len2; i++)
    {
        if (mark[(int)t[i]] == 0)
        {
            mark[(int)t[i]] = top;
            ans2[i] = mark[(int)t[i]];
            top++;
        }
        else
        {

            ans2[i] = mark[(int)t[i]];
        }
    }

    int flag = 0;
    for (int i = 0; i < len1; i++)
        if (ans1[i] != ans2[i])
            return false;

    return true;
}