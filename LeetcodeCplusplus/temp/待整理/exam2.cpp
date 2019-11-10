#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

struct node
{
    int val, left, right;
    node(int val, int left, int right) : val(val), left(left), right(right) {}
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<node> tree;
        vector<int> in(N, 0);
        for (int i = 0; i < N; i++)
        {
            int val, left, right;
            cin >> val >> left >> right;
            tree.push_back(node(val, left, right));
            if (left != -1)
                in[left]++;
            if (right != -1)
                in[right]++;
        }
        int root = -1;
        for (int i = 0; i < N; i++)
        {
            if (in[i] == 0)
            {
                root = i;
                break;
            }
        }
        int weight = 0, cnt = 1;
        bool flag = true;
        queue<node> q;
        q.push(tree[root]);
        while (!q.empty())
        {
            int tmp_weight = 0;
            int cur_cnt = cnt;
            cnt = 0;
            for (int i = 0; i < cur_cnt; i++)
            {
                node tmp = q.front();
                q.pop();
                tmp_weight += tmp.val;
                if (tmp.left != -1)
                {
                    q.push(tree[tmp.left]);
                    cnt++;
                }
                if (tmp.right != -1)
                {
                    q.push(tree[tmp.right]);
                    cnt++;
                }
            }
            if (tmp_weight <= weight)
            {
                flag = false;
                break;
            }
            weight = tmp_weight;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}