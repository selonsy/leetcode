
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

/*
给定一个完全二叉树的层序遍历结果，要求输出该二叉树的前序，中序，后序输出结果。
注：若为空，则用"#"显示（PS:"#"节点没有子节点，可能构不成完全二叉树）
例如：
层序输入：0 1 2 3 4 5 6
前序输出：0 1 3 4 2 5 6
后序输出：3 4 1 5 6 2 0
中序输出：3 1 4 0 5 2 6
*/
typedef char ElemType;
typedef struct tree_node
{
    ElemType data;
    tree_node *left_child;
    tree_node *right_child;
} tree_node, *tree;
//层序遍历构建
tree create_tree_cengxu(vector<char> elem, int last)
{
    int i = 1;
    tree *node_array = (tree *)malloc(sizeof(tree) * (last + 1)); //存储所有节点的指针
    tree root = (tree_node *)malloc(sizeof(tree_node));
    root->data = elem[1];
    node_array[1] = root; //构建根节点

    for (i = 2; i <= last; i++)
    {
        if (elem[i] == '#')
        {
            node_array[i] = NULL;
            continue;
        }

        tree_node *p = (tree_node *)malloc(sizeof(tree_node));
        p->data = elem[i];
        p->left_child = NULL;
        p->right_child = NULL;
        node_array[i] = p; //新建一个节点

        tree_node *father_node = node_array[i / 2];
        if (i % 2 == 0)
            father_node->left_child = p;
        else
            father_node->right_child = p; //将其与父节点建立关联
    }
    free(node_array);
    return root;
}
//三种输出方式
void pre(tree_node *root)
{
    if (root)
    {
        cout << root->data << " ";
        pre(root->left_child);
        pre(root->right_child);
    }
}
void in(tree_node *root)
{
    if (root)
    {
        in(root->left_child);
        cout << root->data << " ";
        in(root->right_child);
    }
}
void post(tree_node *root)
{
    if (root)
    {
        post(root->left_child);
        post(root->right_child);
        cout << root->data << " ";
    }
}

int main()
{
    vector<char> vec = {'*', '0', '1', '2', '3', '#', '5', '6'};
    int len = vec.size() - 1;
    //注意：为了方便起见，下标从1开始。所以上面的 “*” 无用。

    tree_node *root = create_tree_cengxu(vec, len);
    pre(root);
    cout << endl;
    in(root);
    cout << endl;
    post(root);
    return 0;
}