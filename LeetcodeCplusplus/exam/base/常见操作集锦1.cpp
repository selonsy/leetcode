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
/*
目录
101、声明二维数组，输入二维数组，输出二维数组
*/
void 声明二维数组_输入二维数组_输出二维数组_101()
{
    int rows, columns, temp;
    cin >> rows >> columns;
    //1.vector动态初始化
    vector<vector<int>> a1(rows, vector<int>(columns, 1));
    vector<vector<int>> a2(rows);
    for (int i = 0; i < rows; i++)
    { //初始化
        for (int j = 0; j < columns; j++)
        {
            cin >> temp;
            a1[i][j] = temp;
            a2[i].push_back(temp);
        }
    }
    //输出
    for (int i = 0; i < rows; i++)
    { //初始化
        for (int j = 0; j < columns; j++)
        {
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }

    //使用一维数组模拟二维数组
    int a3[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << a3[i * columns + j] << " "; //a0[i*columns+j]等价于a0[i][j]
        }
        cout << endl;
    }
    // 静态二维数组
    int a4[2][3] = {1, 2, 3, 4, 5, 6};

    //动态二维数组,申请空间
    int **a5 = new int *[rows];
    for (int i = 0; i < rows; i++)
        a5[i] = new int[columns];
    //释放空间
    for (int i = 0; i < rows; i++)
        delete[] a5[i];
    delete[] a5;
}
int main()
{
    cout << "Hello World" << endl;
    声明二维数组_输入二维数组_输出二维数组_101();
    return 0;
}