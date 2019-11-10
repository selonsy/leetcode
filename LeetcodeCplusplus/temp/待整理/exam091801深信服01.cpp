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

#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 999
using namespace std;
int n, m;
int e[6][6] = {0};
void Init()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            e[i][j] = -1;
        }
    }

    e[0][1] = 12;
    e[1][0] = 12;

    e[2][3] = 3;
    e[3][2] = 3;

    e[1][2] = 10;
    e[2][1] = 10;

    e[3][4] = 4;
    e[3][4] = 4;

    e[2][5] = 6;
    e[5][2] = 6;

    e[5][0] = 16;
    e[0][5] = 16;

    e[4][5] = 2;
    e[5][4] = 2;

    e[1][4] = 7;
    e[4][1] = 7;
}
// void Input()
// {
//     int a, b, c;
//     for (int i = 1; i <= m; ++i)
//     {
//         cin >> a >> b >> c;
//         e[a][b] = c;
//     }
// }
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
}
void Output(int a,int b)
{
    cout << "dis[" << a << "][" << b << "] = " << e[a][b] << endl;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cout << "dis[" << i << "][" << j << "] = " << e[i][j] << endl;
}
int main()
{
    char M,N;
    cin>>M>>N;
    int a,b;
    a=M-65;
    b=N-65;
    
    Init();
    // Input();
    Floyd();
    // Output();
}