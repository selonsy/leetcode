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

// leetcode 237
//请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
//现有一个链表 – head = [4,5,1,9]，它可以表示为:
//4 -> 5 -> 1 -> 9

//示例 1:
//输入: head = [4,5,1,9], node = 5
//输出: [4,1,9]
//解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

//示例 2:
//输入: head = [4,5,1,9], node = 1
//输出: [4,5,9]
//解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

//说明:
//链表至少包含两个节点。
//链表中所有节点的值都是唯一的。
//给定的节点为非末尾节点并且一定是链表中的一个有效节点。
//不要从你的函数中返回任何结果。

//解题思路
//我们删除一个节点会碰到什么问题？下面删除3
//1 -> 2 -> 3 -> 4
//但是我们没有2的指针，该怎么办呢？我们可以将3=3.next
//1 -> 2 -> 4 -> 4
//这样我们通过删除4实现我们的操作。

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next == nullptr)
            return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {
    cout << "exam.cpp say Hello world!" << endl;
    return 0;
}
