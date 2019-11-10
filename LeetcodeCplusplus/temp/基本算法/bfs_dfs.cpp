#include <stack>
#include <queue>
#include <iostream>
using namespace std;
//
// Created by devin on 2019-08-25.
//
/*

                      A
                    /   \
                   B     C
                 /  \   /  \
                D   E   F   G

深度优先遍历(DFS) : A B D E C F G

广度优先遍历(BFS) : A B C D E F G

先序遍历：A B D E C F G

中序遍历：D B E A F C G

后序遍历：D E B F G C A

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//深度优先遍历(DFS)[从头开始，栈保存，非空弹出，先压右子树，再押左子树]
void depthFirstSearch(TreeNode *root)
{
    stack<TreeNode *> nodeStack; //使用C++的STL标准模板库
    nodeStack.push(root);
    TreeNode *node;
    while (!nodeStack.empty())
    {
        node = nodeStack.top();
        cout << node->val;
        nodeStack.pop();
        if (node->right)
        {
            nodeStack.push(node->right); //先将右子树压栈
        }
        if (node->left)
        {
            nodeStack.push(node->left); //再将左子树压栈
        }
    }
}
//DFS 递归实现
void dfs(TreeNode *root)
{
    if (root)
    {
        cout << root->val;
        dfs(root->left);
        dfs(root->right);
    }
}
//广度优先遍历(BFS)[从头开始，队保存，非空弹出队头，先入队左子树，再入队右子树]
void breadthFirstSearch(TreeNode *root)
{
    queue<TreeNode *> nodeQueue; //使用C++的STL标准模板库
    nodeQueue.push(root);
    TreeNode *node;
    while (!nodeQueue.empty())
    {
        node = nodeQueue.front();
        nodeQueue.pop();
        cout << node->val;
        if (node->left)
        {
            nodeQueue.push(node->left); //先将左子树入队
        }
        if (node->right)
        {
            nodeQueue.push(node->right); //再将右子树入队
        }
    }
}
