#include <iostream>
using namespace std;
template <typename T>
struct BinaryTreeNode
{
    BinaryTreeNode<T> *_left;    //左孩子
    BinaryTreeNode<T> *_right;   //右孩子
    T _data;                     //数据
    BinaryTreeNode(T data = T()) //结点自己的构造函数，T()为一个匿名对象。
        : _left(NULL)            //初始化为空
          ,
          _right(NULL), _data(data)
    {
    }
};
typedef BinaryTreeNode<int> Node;

//1.前序遍历（当前结点-->左子树-->右子树。）
void _PrevOrder(Node *_root)
{
    Node *tmp = _root;
    if (tmp == NULL)
    {
        return;
    }
    cout << tmp->_data << " ";
    _PrevOrder(tmp->_left);
    _PrevOrder(tmp->_right);
}
//2.中序遍历
void PrevOrder()
{
    // _PrevOrder(_root);
    cout << endl;
}