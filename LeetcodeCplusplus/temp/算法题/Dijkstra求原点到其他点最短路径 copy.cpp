#include <iostream>
#include <vector>

/*

给定一个无向或者有向图，求原点到任意一点的最短距离，并输出路径。

本程序的输出样式，可酌情进行修改。
// 源点1到1的最短路径长度：0
// Path：1->1
// 源点1到2的最短路径长度：7
// Path：1->2
// 源点1到3的最短路径长度：9
// Path：1->3
// 源点1到4的最短路径长度：20
// Path：1->3->4
// 源点1到5的最短路径长度：20
// Path：1->3->6->5
// 源点1到6的最短路径长度：11
// Path：1->3->6

*/

using namespace std;
const int inf = 999999;
const int n = 6;
int L[n][n] = {0, 7, 9, inf, inf, 14,
               7, 0, 10, 15, inf, inf,
               9, 10, 0, 11, inf, 2,
               inf, 15, 11, 0, 6, inf,
               inf, inf, inf, 6, 0, 9,
               14, inf, 2, inf, 9, 0}; //存储图中的路径
int dis[n];                            //存储源点到各个顶点的最短路径

vector<int> path[n];

int main()
{
    for (int i = 0; i < n; i++) //初始化
    {
        dis[i] = L[0][i];
        path[i].push_back(1);
        path[i].push_back(i + 1);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //dis[i] = min(dis[i],dis[j] + L[j][i]);
            if (dis[i] > dis[j] + L[j][i]) //求源点到节点的最短路径，利用现有的L矩阵
            {
                dis[i] = dis[j] + L[j][i];

                path[i].clear(); //保存并更新路径
                path[i].insert(path[i].end(), path[j].begin(), path[j].end());
                path[i].push_back(i + 1);
            }
        }
        for (int m = 0; m < i; m++) //更新节点最短路径
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[m] > dis[j] + L[j][m])
                {
                    dis[m] = dis[j] + L[j][m];
                    path[m].clear(); //保存并更新路径
                    path[m].insert(path[m].end(), path[j].begin(), path[j].end());
                    path[m].push_back(m + 1);
                }
            }
        }
    }
    vector<int>::iterator ite;
    for (int i = 0; i < n; i++)
    {
        cout << "源点1到" << i + 1 << "的最短路径长度：" << dis[i] << endl
             << "Path：";
        for (ite = path[i].begin(); ite != path[i].end(); ++ite)
        {
            if (ite == path[i].begin())
                cout << *ite;
            else
                cout << "->" << *ite;
        }
        cout << endl;
    }

    return 0;
}


