#include <iostream>
#include <vector>

/*

给定一个无向或者有向图，求任意两点的最短距离，并输出路径。

本程序的输出样式，可酌情进行修改。
如：求任意两点之间的最短路径问题。
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
// 源点2到1的最短路径长度：7
// Path：2->1
// 源点2到2的最短路径长度：0
// Path：2->2
// 源点2到3的最短路径长度：10
// Path：2->3
// 源点2到4的最短路径长度：15
// Path：2->4
// 源点2到5的最短路径长度：21
// Path：2->4->5
// 源点2到6的最短路径长度：12
// Path：2->3->6

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
int dis[n][n];						   //存储源点到各个顶点的最短路径

vector<int> path[n][n];

int main()
{
	for (int i = 0; i < n; i++) //初始化
	{

		for (int j = 0; j < n; j++)
		{
			dis[i][j] = L[i][j];
			path[i][j].push_back(i + 1);
			path[i][j].push_back(j + 1);
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//dis[i] = min(dis[i],dis[j] + L[j][i]);
				if (dis[k][i] > dis[k][j] + L[j][i]) //求源点到节点的最短路径，利用现有的L矩阵
				{
					dis[k][i] = dis[k][j] + L[j][i];

					path[k][i].clear(); //保存并更新路径
					path[k][i].insert(path[k][i].end(), path[k][j].begin(), path[k][j].end());
					path[k][i].push_back(i + 1);
				}
			}
			for (int m = 0; m < i; m++) //更新节点最短路径
			{
				for (int j = 0; j < n; j++)
				{
					if (dis[k][m] > dis[k][j] + L[j][m])
					{
						dis[k][m] = dis[k][j] + L[j][m];
						path[k][m].clear(); //保存并更新路径
						path[k][m].insert(path[k][m].end(), path[k][j].begin(), path[k][j].end());
						path[k][m].push_back(m + 1);
					}
				}
			}
		}
	}

	vector<int>::iterator ite;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "源点" << k + 1 << "到" << i + 1 << "的最短路径长度：" << dis[k][i] << endl
				 << "Path：";
			for (ite = path[k][i].begin(); ite != path[k][i].end(); ++ite)
			{
				if (ite == path[k][i].begin())
					cout << *ite;
				else
					cout << "->" << *ite;
			}
			cout << endl;
		}
	}
	return 0;
}
