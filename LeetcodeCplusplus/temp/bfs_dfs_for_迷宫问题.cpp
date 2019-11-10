//
// Created by devin on 2019-08-25.
//
//广度/深度优先算法（bfs+dfs）理解+例题+对比

//例题：
//《迷宫问题》
//定义一个二维数组：
//0 0 1 0 1 //0表示可走，1表示墙
//0 1 1 1 0 //只能↑↓←→走，不能斜着走
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0 //题目保证了输入是一定有解的
//
//求从左上角（0，0）到右下角（4，4）的最短路线。

//bfs解题核心逻辑伪代码：
//1，将起点推入队列中；
//2，将起点标识为已走过；
//while（队列非空）{
//3，取队列首节点vt，并从队列中弹出；
//4，探索上面取出得节点的周围是否有没走过的节点vf，如果有将所有能走的vf的parents指向vt，并将vf加入队列
//（如果vf等于终点，说明探索完成，退出循环）。
//}
//如果队列为空自然跳出，说明无路可达终点。

//dfs解题核心逻辑伪代码：
//
//1，栈初始化
//2，获得起点，将起点标识为已走过，将起点入栈
//while（栈非空）{
//取栈顶元素vt
//        如果vt周围有为走过的节点vf，则：
//将vf改为已走
//        vf入栈
//没有能走的节点，vt出栈
//}
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
#include<time.h>
#include <windows.h>
#include<set>

using namespace std;
struct BNode//定义结构体BNode
{
    int xx;//自身处于组内的位置
    int yy;
    bool qiang;//是否是墙
    bool walked;//是否走过
    BNode *parents;//指向父节点的指针
};
struct DNode {
    int x;
    int y;
    bool walked;
    int g;
    int f;//f = g+h
    int h;
    DNode *parents;
};

void bfs_maze() {
    int id = 0;
    //int xx, yy;
    queue<BNode *> bfs;//创建BNode指针队列
    vector<vector<BNode>> migong;//创建二维迷宫组
    for (int i = 0; i < 5; i++) {
        vector<BNode> hang;
        for (int j = 0; j < 5; j++) {
            int ii;
            cin >> ii;
            BNode node{i, j, ii, false};
            hang.push_back(node);
        }

        migong.push_back(hang);
    }
    //输入完毕
    int ax[4] = {-1, 1, 0, 0};
    int by[4] = {0, 0, 1, -1};


    bfs.push(&migong[0][0]);//先将起点推进去
    migong[0][0].walked = true;

    BNode *vt;//等下指向父节点的指针
    BNode *vf;//等下指向父节点引申出的子节点

    while (!bfs.empty()) {
        vt = bfs.front();
        bfs.pop();


        if ((*vt).xx >= 1) {//查询左节点是否可以
            vf = &migong[(*vt).xx + ax[0]][(*vt).yy + by[0]];
            if (!(*vf).qiang && !(*vf).walked) {
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;//子节点指向父节点
                if ((*vf).xx == 4 && (*vf).yy == 4) break;//如果是终点节点，结束寻找，跳出循环。
            }
        }
        if ((*vt).xx <= 3) {//查询右节点是否可以
            vf = &migong[(*vt).xx + ax[1]][(*vt).yy + by[1]];
            if (!(*vf).qiang && !(*vf).walked) {
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;
                if ((*vf).xx == 4 && (*vf).yy == 4) break;
            }
        }
        if ((*vt).yy <= 3) {//查询下节点是否可以
            vf = &migong[(*vt).xx + ax[2]][(*vt).yy + by[2]];
            if (!(*vf).qiang && !(*vf).walked) {
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;
                if ((*vf).xx == 4 && (*vf).yy == 4) break;
            }
        }
        if ((*vt).yy >= 1) {//查询上节点是否可以
            vf = &migong[(*vt).xx + ax[3]][(*vt).yy + by[3]];
            if (!(*vf).qiang && !(*vf).walked) {
                bfs.push(vf);
                (*vf).walked = true;
                (*vf).parents = vt;
                if ((*vf).xx == 4 && (*vf).yy == 4) break;
            }
        }

    }


//结束算法，从vf指向的节点开始寻找父节点。
    vector<BNode *> fin;


    while (true) {
        fin.push_back(vf);
        vf = (*vf).parents;
        if ((*vf).xx == 0 && (*vf).yy == 0) {
            fin.push_back(vf);
            break;
        }

    }
//输出
    for (int i = fin.size() - 1; i >= 0; i--) {
        cout << (*fin[i]).xx << "," << (*fin[i]).yy << endl;
    }
}

void dfs_maze() {
    vector<vector<DNode>> migong;//创建二维迷宫组
    for (int i = 0; i < 5; i++) {
        vector<DNode> hang;
        for (int j = 0; j < 5; j++) {
            int ii;
            cin >> ii;
            DNode node{i, j, ii};
            hang.push_back(node);
        }

        migong.push_back(hang);
    }


    /*-----------------------------------dfs----------------------------------------------*/
    vector<vector<DNode>> migong2 = migong;

    stack<DNode *> f;
    f.push(&migong2[0][0]);
    migong2[0][0].walked = true;
    while (!f.empty()) {
        DNode *vt = f.top();
        bool can = true;
        if (vt->x >= 1) {
            DNode *vf = &migong2[vt->x - 1][vt->y];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }
        if (vt->x <= 3) {
            DNode *vf = &migong2[vt->x + 1][vt->y];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }
        if (vt->y >= 1) {
            DNode *vf = &migong2[vt->x][vt->y - 1];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }
        if (vt->y <= 3) {
            DNode *vf = &migong2[vt->x][vt->y + 1];
            if (vf->walked == false) {
                vf->parents = vt;
                vf->walked = true;
                if (vf == &migong2[4][4]) {
                    break;
                }
                f.push(vf);
                can = false;
            }
        }

        if (can) {
            f.pop();
        }

    }


    vector<DNode *> fin2;
    DNode *bb = &migong2[4][4];
    while (true) {

        fin2.push_back(aa);
        if (bb == &migong2[0][0]) {
            break;
        }
        bb = bb->parents;

    }


    int count2 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << migong2[i][j].walked;
            if (migong2[i][j].walked)count2++;
        }
        cout << endl;
    }
    reverse(fin2.begin(), fin2.end());


    for (int i = 0; i < fin.size(); i++) {
        cout << fin[i]->x << " " << fin[i]->y << endl;
    }
}

int main() {
    bfs_maze();
    dfs_maze();
    return 0;
}