#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<mem.h>

int inf = -9999;
using namespace std;

//为了增强复用性，这里封装成类模板，虚拟类型为T
template<class T>
struct Graph {
    //存放顶点
    vector<T> vertex;
    //存放边
    vector<vector<int>> edge;
    //标记数组
    bool book[100];

    //构造函数
    Graph(int n, int m);

    //析构函数
    ~Graph();

    //递归深度优先遍历
    void DFS_recursion(int cur);

    //非递归深度优先遍历
    void DFS_stack(int cur);

    //广度优先遍历
    void BFS(int cur);
};

template<class T>
Graph<T>::Graph(int n, int m) {
    //为了使顶点对应的下标符合人类思维（从1起），这里的容器大小分配为n+1；
    vertex.resize(n + 1);
    edge.resize(n + 1);
    for (int i = 0; i < n + 1; i++) {
        edge[i].resize(n + 1);
    }
    //初始化邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) edge[i][j] = 0;
            else edge[i][j] = inf;
        }
    }
    cout << "请输入各条边的两个邻点" << endl;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        //这里使用无向图，故边应用edge[a][b]=edge[b][a]=1;初始化
        edge[a][b] = edge[b][a] = 1;
    }
    ////因为各顶点的值为设为int类型，故为了方便，将各顶点的值初始化为其下标
    for (int i = 1; i <= m; i++) {
        vertex[i] = i;
    }
    //标记数组初始化
    memset(book, 0, 100);
}

template<class T>
Graph<T>::~Graph() {
    vertex.clear();
    edge.clear();
}

template<class T>
void Graph<T>::DFS_recursion(int cur) {
    book[cur] = true;
    cout << vertex[cur];
    for (int i = 0; i < vertex.size(); i++) {
        if (edge[cur][i] == 1 && book[i] == 0) {
            DFS_recursion(i);
        }
    }
}

template<class T>
void Graph<T>::DFS_stack(int cur) {
    stack<int> s;
    s.push(cur);
    while (!s.empty()) {
        int top = s.top();
        if (book[top] == 0) {
            cout << top;
            book[top] = 1;
        } else s.pop();
        for (int i = 0; i < vertex.size(); i++) {
            if (book[i] == 0 && edge[top][i] == 1) {
                s.push(i);
                break;
            }
        }
    }
    return;
}

template<class T>
void Graph<T>::BFS(int cur) {
    queue<int> q;
    q.push(cur);
    book[cur] = 1;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << vertex[front];
        for (int i = 0; i < vertex.size(); i++) {
            if (edge[front][i] == 1 && book[i] == 0) {
                q.push(i);
                book[i] = 1;
            }
        }
    }
}

int main() {
    //将类模板实例化为模板类，再将模板类实例化为一个对象
    Graph<T> *G = new Graph<int>(5, 5);

    cout << "深度优先遍历（递归）如下：" << endl;
    G->DFS_recursion(1);
    memset(G->book, 0, 100);
    cout << endl;

    cout << "深度优先遍历（非递归）如下:" << endl;
    G->DFS_stack(1);
    memset(G->book, 0, 100);
    cout << endl;

    cout << "广度优先队列遍历如下：" << endl;
    G->BFS(1);
    cout << endl;

    system("pause");
    return 0;
}
