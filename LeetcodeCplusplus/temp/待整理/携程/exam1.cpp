#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <stack>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    };
};
/*请完成下面这个函数，实现题目要求的功能*/
/******************************结束写代码******************************/
ListNode *partition(ListNode *head, int m)
{
    if (head == NULL)
        return NULL;
    ListNode *root = new ListNode(0);
    ListNode *pre = root;
    ListNode *p = head;
    root->next = head;
    while (p && p->val <= m)
    {
        pre = p;
        p = p->next;
    }
    ListNode *q = pre;
    while (p)
    {
        if (p->val <= m)
        {
            q->next = p->next;
            p->next = pre->next;
            pre->next = p;
            pre = p;
            p = q;
        }
        q = p;
        p = p->next;
    }
    return root->next;
}

int main()
{
    ListNode *head = NULL;
    ListNode *node = NULL;
    int m;
    cin >> m;
    int v;
    while (cin >> v)
    {
        if (head == NULL)
        {
            node = new ListNode(v);
            head = node;
        }
        else
        {
            node->next = new ListNode(v);
            node = node->next;
        }
    }
    head = partition(head, m);
    if (head != NULL)
    {
        cout << head->val;
        node = head->next;
        delete head;
        head = node;
        while (head != NULL)
        {
            cout << "," << head->val;
            node = head->next;
            delete head;
            head = node;
        }
    }
    cout << endl;
    return 0;
}
