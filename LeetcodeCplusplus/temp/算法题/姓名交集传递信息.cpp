/*
题目：
有若干个人，姓名分别为：AEEN,EENF,ENFD,EFDC,FDCV
设两个人的姓名的交集为3个及以上字符，代表可以进行消息传递。
现在设消息起始点：AEEN，以及消息接受者：FDCV。
求可以将消息传递到接受者的最短的路径，如果无法传递则返回-1.
输入：
5                           //表示人数
AEEN,EENF,ENFD,EFDC,FDCV    //姓名
AEEN                        //SOURCE
FDCV                        //TARGET
输出：
AEEN,EENF,ENFD,EFDC,FDCV    //路径

输入：
6                                //表示人数
AEEN,EENC,ENCF,EEND,ENDE,NDEZ    //姓名
AEEN                             //SOURCE
NDEZ                             //TARGET
输出：
AEEN,EEND,ENDE,NDEZ              //路径

*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
bool is_transfer(string name1, string name2)
{
    if (name1.size() == 0 || name2.size() == 0)
        return false;
    int res = 0;
    int len1 = name1.size(), len2 = name2.size(), len = len1 > len2 ? len1 : len2;
    int m = 0, n = 0;
    sort(name1.begin(), name1.end());
    sort(name2.begin(), name2.end());
    for (int i = 0; i < len; i++)
    {
        if (m == len1 || n == len2)
            break;
        if (name1[m] == name2[n])
        {
            res += 1;
            m++;
            n++;
        }
        else if (name1[m] < name2[n])
        {
            m++;
        }
        else
        {
            n++;
        }
    }
    return res >= 3;
}
vector<string> get_transfers(string name, list<string> names)
{
    vector<string> res;
    for (list<string>::iterator i = names.begin(); i != names.end(); i++)
    {
        if (is_transfer(name, *i))
        {
            res.push_back(*i);
        }
    }
    return res;
}
void shortest_path(int n, vector<string> names, string source, string target)
{
    vector<string> res = {source};
    list<string> list;
    for (auto &i : names)
    {
        list.push_back(i);
    }
    string curr = source;
    // stack<TreeNode *> nodeStack; //使用C++的STL标准模板库
    // nodeStack.push(root);
    // TreeNode *node;
    // while (!nodeStack.empty())
    // {
    //     node = nodeStack.top();
    //     cout << node->val;
    //     nodeStack.pop();
    //     if (node->right)
    //     {
    //         nodeStack.push(node->right); //先将右子树压栈
    //     }
    //     if (node->left)
    //     {
    //         nodeStack.push(node->left); //再将左子树压栈
    //     }
    // }
    while (curr != target)
    {
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> names;
    string t_name = "";
    for (int i = 0; i < n; i++)
    {
        char c = getchar();
        if (c != ',')
        {
            t_name += c;
        }
        else
        {
            names.push_back(t_name);
        }
    }
    string source, target;
    cin >> source >> target;
    shortest_path(n, names, source, target);
    return 0;
}
/*
5
AEEN,EENF,ENFD,EFDC,FDCV
AEEN
FDCV
*/