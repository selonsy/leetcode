/*
1.判断链表是否有环。
2.确定有环链表的入口地址。
3.求环的长度。
*/

#include <iostream>
using namespace std;
#include <unordered_set>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    /*
    1.判断链表是否有环。
    使用 unordered_set 存放走过的节点，如果再次遇到，则有环。
    空间换时间，都是 O(n)的复杂度。
    */
    bool hasCycle_map(ListNode *head)
    {
        unordered_set<ListNode *> uc;
        ListNode *p = head;
        while (p)
        {
            // 迭代器内部判断是否查找成功，与end()比较，忽略具体的实现细节。
            if (uc.find(p) != uc.end())
            {
                return true;
            }
            uc.insert(p);
            p = p->next;
        }
        return false;
    }

    /*
    1.判断链表是否有环。
    快慢指针法，即采用两个指针walker和runner，walker每次移动一步而runner每次移动两步。
    当walker和runner第一次相遇时，证明链表有环。
    */
    bool hasCycle_fast_slow(ListNode *head)
    {
        ListNode *walker = head;
        ListNode *runner = head;
        while (runner && runner->next)
        {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
                return true;
        }
        return false;
    }
    /*
    2.确定有环链表的入口地址。
    寻找环入口的方法就是采用快慢指针，第一次相遇时停止，记录位置信息 P1。另一指针 P2 从表头开始，
    P1 & P2 再次相遇的地方就是环入口的位置。
    */
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *walker = head;
        ListNode *runner = head;
        while (runner && runner->next)
        {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
                break;
        }
        if (!runner || !runner->next)
            return nullptr;
        ListNode *headWalker = head;
        ListNode *crossWalker = walker;
        while (headWalker != crossWalker)
        {
            headWalker = headWalker->next;
            crossWalker = crossWalker->next;
        }
        return headWalker;
    }
    /*
    3.求环的长度。
    利用上面求出的环入口，再走一圈就可以求出长度。
    */
    int cycleLen_1(ListNode *head)
    {
        ListNode *cycleIn = detectCycle(head);
        int len = 1;
        ListNode *walker = cycleIn;
        while (walker->next != cycleIn)
        {
            ++len;
            walker = walker->next;
        }
        return len;
    }
    /*
    3.求环的长度。
    当快慢指针相遇时，继续移动直到第二次相遇，此时快指针移动的距离正好比慢指针多一圈。
    */
    int cycleLen_2(ListNode *head)
    {
        ListNode *walker = head;
        ListNode *runner = head;
        int len = 0;
        for (int i = 0; i < 2; i++)
        {
            while (runner && runner->next)
            {
                if (i == 1)
                    len++;
                walker = walker->next;
                runner = runner->next;
                if (walker == runner)
                    break;
            }
        }
        // while (runner && runner->next)
        // {
        //     walker = walker->next;
        //     runner = runner->next;
        //     if (walker == runner)
        //         break;
        // }
        // int len = 0;
        // while (runner && runner->next)
        // {
        //     ++len;
        //     walker = walker->next;
        //     runner = runner->next;
        //     if (walker == runner)
        //         break;
        // }
        return len;
    }
};