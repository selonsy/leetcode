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

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
* Welcome to vivo !
*/

int getCountOfApp(const char *input)
{
    if (NULL == input)
    {
        return 0;
    }
    int cnt = 0;
    for (int i = 0; input[i] != 0; ++i)
    {
        if (input[i] == ',')
        {
            ++cnt;
        }
    }
    return cnt / 2;
}

//id start from 0
int getPositionOfApp(const char *input, const int id)
{
    int cntOfComma = id * 2 + 1;
    int i = 0;
    for (; input[i] != 0 && cntOfComma != 0; ++i)
    {
        if (input[i] == ',')
        {
            --cntOfComma;
        }
    }
    while (input[--i] != ' ' && input[i] != '#')
        ;
    return i + 1;
}

#define APP_MAX 1000
#define DP_MAX 2048
int disks[APP_MAX];
int mems[APP_MAX];
int users[APP_MAX];
int dp[DP_MAX * DP_MAX];

int solution(const char *input)
{
    const int countOfApp = getCountOfApp(input);
    if (0 == countOfApp)
    {
        return 0;
    }
    int res = 0;

    int disk = 0;
    int mem = 0;

    sscanf(input, "%d %d", &disk, &mem);

    for (int i = 0; i < countOfApp; ++i)
    {
        const int pos = getPositionOfApp(input, i);
        sscanf(input + pos, "%d,%d,%d", &disks[i], &mems[i], &users[i]);
    }
    int ***vec;
    vec = new int **[countOfApp+1];
    for (int i = 0; i < countOfApp+1; i++)
    {
        vec[i] = new int *[disk+1];
    }
    for (int i = 0; i < countOfApp+1; i++)
    {
        for (int j = 0; j < disk+1; j++)
        {
            vec[i][j] = new int[mem+1];
        }
    }
    // vector<vector<int> > vec__(countOfApp,vector<int>(mem));
    vector<vector<vector<int> > > vec_(countOfApp,vector<vector<int> >(disk,vector<int>(mem,0)));
    for (int i = 1; i < countOfApp + 1; i++)
    {
        for (int j = 1; j < disk + 1; j++)
        {
            for (int k = 1; k < mem + 1; k++)
            {
                if (disks[i] > j || mems[i] > k)
                {
                    vec[i][j][k] = vec[i - 1][j][k];
                }
                else
                {
                    int value1 = vec[i - 1][j - disks[i]][k - mems[i]] + users[i];
                    int value2 = vec[i - 1][j][k];
                    vec[i][j][k] = max(value1, value2);
                }
            }
        }
    }
    return vec[countOfApp][disk][mem];
}

int main(int argc, char *args[])
{
    char input[10000];
    cin.getline(input, 10000);
    cout << solution(input) << endl;
}