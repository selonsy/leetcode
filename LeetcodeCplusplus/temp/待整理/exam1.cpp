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
#include <map>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    int left;
    int right;
    int depth;
    Node(int x, int l, int r)
    {
        data = x;
        left = l;
        right = r;
        lchild = nullptr;
        rchild = nullptr;
        depth = -1;
    }
};
//广度优先遍历
int print_at_level(Node *root, int level)
{
    int res = 0;
    Node *tmp;
    int count = 1;
    if (root == NULL)
    {
        return 0;
    }
    std::queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp == NULL)
        {
            count++;
            if (count == level + 1)
            {
                // printf("\n");
            }
            if (!q.empty())
            {
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        if (count == level)
        {
            res += tmp->data;
            // printf("%d ", tmp->data);
        }
        if (tmp->lchild)
        {
            q.push(tmp->lchild);
        }
        if (tmp->rchild)
        {
            q.push(tmp->rchild);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M;
        int value, left, right;
        cin >> M;
        vector<Node *> v_p;
        // vector<unordered_map<int,map<int,int> > > vec_m;
        vector<int> vec_t(M, 0);
        for (int j = 0; j < M; j++)
        {
            cin >> value >> left >> right;
            Node *p = new Node(value, left, right);
            v_p.push_back(p);

            // map<int, int> map_t_t;
            // unordered_map<int, map<int, int>> map_t;
            // map_t_t.insert(pair<int, int>(left, value));
            // map_t.insert(pair<int, map<int, int>>(value, map_t_t));
            if (left != -1 || right != -1)
            {
                vec_t[left] = 1;
                vec_t[right] = 1;
            }
            // vec_m.push_back(map_t);
        }
        int head_index; // 找到根节点
        for (int i = 0; i < vec_t.size(); i++)
        {
            if (vec_t[i] == 0)
            {
                head_index = i;
                break;
            }
        }
        // 构建二叉树 
        Node *head = v_p[head_index];
        head->depth = 1;
        deque<Node *> dp;
        dp.push_back(head);
        int depth = 2;
        while (!dp.empty())
        {
            Node *pp = dp.front();
            if (pp->left != -1)
            {
                pp->lchild = v_p[pp->left];
                pp->lchild->depth = depth;
                dp.push_back(v_p[pp->left]);
            }
            else if (pp->right != -1)
            {
                pp->rchild = v_p[pp->right];
                pp->rchild->depth = depth;
                dp.push_back(v_p[pp->right]);
            }
            depth++;
        }
        // // 分层统计权值和
        // for(int i = 0; i < vec_t.size(); i++)
        // print_at_level(head);
        // /* code */
    }
    return 0;
}