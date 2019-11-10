/*
001、A、B两个数组，要求输出A中存在而B中不存在的元素。#【vivo】
002、一个单向链表，输入m，n，要求在第m和第n区间之内的元素倒序存储并输出此链表。#【vivo】
003、有n种礼品，每个礼品对应一个热度值，总金额为k，每个礼品只能买一次，如何购买可以使得所有礼品的总热度值最高。#【vivo】 
*/

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
#include <list>
#include <unordered_map>
using namespace std;

#include "base/List.h"
#include "base/Output.h"

void ds001()
{
    // 001、A、B两个数组，要求输出A中存在而B中不存在的元素。#【vivo】
    // 思路：
    // 使用unordered_map存储B的元素，遍历A，输出不在B里面的元素。
    // 查找是否是B中的元素，O(1)，遍历A，O(n)。

    // input example：
    int a[5] = {1, 2, 3, 4, 5};
    int b[6] = {2, 3, 5, 6, 7};

    unordered_map<int, bool> map;
    for (int x : b)
    {
        map.insert(pair<int, bool>(x, true));
    }
    for (int y : a)
    {
        if (map.find(y) != map.end()) // 没有找到使用 map.find(y) != map.end() 判断
            continue;
        cout << y << endl; // 输出：1 4
    }
}

void ds002()
{
    // 002、一个单向链表，输入m，n，要求在第m和第n区间之内的元素倒序存储并输出此链表。#【vivo】
    // 思路：

    // input example:
    LinkList<int> _list(vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));
    int m = 2, n = 7;
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    list<int> li;
    list<int> li_pre, li_after;
    for (int i = 0; i < vec.size(); i++)
    {
        if (i < m - 1)
            li_pre.push_back(vec[i]);
        else if (i >= m - 1 && i <= n - 1)
            li.push_front(vec[i]);
        else
            li_after.push_back(vec[i]);
    }

    output<int>::o_list(li_pre);
    output<int>::o_list(li);
    output<int>::o_list(li_after);
    li_pre.splice(li_pre.end(), li);
    output<int>::o_list(li_pre);
    output<int>::o_list(li);
    li_pre.splice(li_pre.end(), li_after);
    output<int>::o_list(li_pre);
    output<int>::o_list(li_after);
}

struct ListNode
{
    int data;
    struct ListNode *next;
};

ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    if (!head || !head->next || n == m)
        return head; //预处理
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = head; //删除节点常用手段考虑加个头指针
    struct ListNode *pre = NULL;
    struct ListNode *p = L;
    int temp_m = m;
    int temp_n = n;
    //将p转移到反转链表的第一个节点，pre保存前一个节点
    while (temp_m-- >= 1)
    {
        pre = p;
        p = p->next;
    }

    struct ListNode *reverse_head = NULL;
    struct ListNode *reverse_tail = p;
    struct ListNode *reverse_tail_after = NULL;
    struct ListNode *q = NULL;
    //进行反转
    while (temp_n - m > 0)
    {
        q = p->next;
        reverse_tail_after = q->next;
        p->next = reverse_head;
        reverse_head = p;
        p = q;
        temp_n--;
    }

    p->next = reverse_head;
    reverse_head = p;
    pre->next = reverse_head;

    reverse_tail->next = reverse_tail_after;
    return L->next;
}
int main()
{
    ds002();
    return 0;
}