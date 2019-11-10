
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
typedef char ElemType;
typedef struct tree_node
{
    ElemType data;
    tree_node *left_child;
    tree_node *right_child;
} tree_node, *tree;

tree create_tree(ElemType *elem, int last)
{
    int i = 1;
    tree *node_array = (tree *)malloc(sizeof(tree) * (last + 1)); //存储所有节点的指针
    tree root = (tree_node *)malloc(sizeof(tree_node));
    root->data = elem[0];
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
void pre(tree_node *root)
{
    if (root)
    {
        cout << root->data << endl;
        pre(root->left_child);
        pre(root->right_child);
    }
}
int main()
{
    int n;
    cin >> n;
    ElemType *elem = new ElemType[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> elem[i];
    tree_node *root = create_tree(elem, n);
    pre(root);
    return 0;
}