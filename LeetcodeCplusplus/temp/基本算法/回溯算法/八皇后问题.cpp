#include <iostream>
#include <math.h>
using namespace std;

// ”八皇后问题“：
// 在8X8格的国际象棋上摆放八个皇后（棋子），使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

int n = 4;               //设置皇后数量
int *queen = new int(n); //queen数组记录每个皇后位置
int t = 0;               //计数

bool is_ok(int row)
{ //判断设置的皇后是否在同一行，同一列，或者同一斜线上
    for (int j = 0; j < row; j++)
    {
        // queen[row]：记录的就是第 row 行中，皇后的位置，即列号。
        if (queen[row] == queen[j] ||           //同一列，同一行不可能
            row - queen[row] == j - queen[j] || //左上到右下的斜线
            row + queen[row] == j + queen[j])   //左下到右上的斜线
            return false;
    }
    return true;
}
void back_tracking(int row = 0) //算法函数，从第0行开始遍历
{
    if (row == n)
    {
        t++; //判断若遍历完成，就进行计数，这里表示共计有多少种
        //下面的for循环是把八皇后按要求打印出来。
        for (int i = 0; i < n; i++)
        {
            int a = queen[i];
            // cout << a << endl;
            for (int j = 0; j < n; j++)
            {
                if (j == a)
                    cout << "#"; //表示皇后
                else

                    cout << "@";
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int col = 0; col < n; col++) //遍历棋盘每一列
    {
        queen[row] = col;           //将皇后的位置记录在数组
        if (is_ok(row))             //判断皇后的位置是否有冲突
            back_tracking(row + 1); //递归，计算下一个皇后的位置
    }
}

int main()
{
    back_tracking();
    cout << "共计 " << t << " 种" << endl;
    return 1;
}