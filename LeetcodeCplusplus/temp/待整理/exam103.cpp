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
using namespace std;

/**
 * Welcome to vivo !
 */

#define MAX_NUM 100

int solution(int boxs[], int N)
{
    // TODO Write your code here
    if (N == 0)
        return 0;
    int res = 0;
    vector<int> vec(10, 0);
    for (int i = 0; i < N; i++)
    {
        vec[boxs[i]]++;
    }
    for (int x : vec)
    {
        res += x * x;
    }

    return res;
}

int main()
{
    string str("");
    getline(cin, str);
    int boxs[MAX_NUM];
    int i = 0;
    char *p;
    int count = 0;

    const char *strs = str.c_str();
    p = strtok((char *)strs, " ");
    while (p)
    {
        boxs[i] = atoi(p);
        count++;
        p = strtok(NULL, " ");
        i++;
        if (i >= MAX_NUM)
            break;
    }

    int num = solution(boxs, count);
    cout << num << endl;
    return 0;
}