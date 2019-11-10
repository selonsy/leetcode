//
// Created by devin on 2019-05-30.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<queue>
#include<list>
#include<functional>
#include<map>
#include<string>
#include<sstream>

using namespace std;

// leetcode 138
// 复制带随机指针的链表
/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。

输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。

提示：你必须返回给定头的拷贝作为对克隆列表的引用。
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr)
            return nullptr;
        //先进行浅拷贝
        //先设置一个哨兵节点，方便直接从头拷贝
        Node *header = new Node(-1, nullptr, nullptr);
        Node *p = header;
        Node *q = head;
        map<Node *, Node *> m; // 保存原链表和新建链表的对应关系，方便后期进行随机指针的赋值。
        while (q) {//拷贝next指针
            Node *tmp = new Node(q->val, nullptr, nullptr);
            p->next = tmp;
            m[q] = tmp;
            p = p->next;
            q = q->next;
        }
        //拷贝random指针
        p = header->next;
        q = head;
        while (q) {
            p->random = m[q->random];
            q = q->next;
            p = p->next;
        }
        return header->next;
    }

    Node *copyRandomList_1(Node *head) {
        if (!head) return nullptr;
        Node *ite = head;
        while (ite) { // 用next连接
            Node *n = new Node(ite->val, ite->next, nullptr);
            ite->next = n;
            ite = n->next;
        }
        ite = head;
        while (ite) { // 连接random
            if (ite->random) ite->next->random = ite->random->next;
            ite = ite->next->next;
        }
        ite = head;
        Node *ret = head->next;
        while (ite->next) { // 有丝分裂(大雾)
            Node *c = ite->next;
            ite->next = ite->next->next;
            ite = c;
        }
        return ret;
    }
};

int main() {
    cout << "exam.cpp say Hello world!" << endl;
    return 0;
}
