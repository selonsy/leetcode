// Date: 2020-10-24 12:27:43

//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学 
// 👍 5131 👎 0


package leetcode.editor.cn;


import leetcode.editor.cn.model.ListNode;

import static leetcode.editor.cn.util.ListNodeUtl.createListNodeByArray;
import static leetcode.editor.cn.util.ListNodeUtl.printListNode;

//Java：两数相加
public class P2AddTwoNumbers {
    public static void main(String[] args) {
        Solution solution = new P2AddTwoNumbers().new Solution();
        ListNode l1 = createListNodeByArray(new int[]{2, 4, 3});
        printListNode(l1);
        ListNode l2 = createListNodeByArray(new int[]{5, 6, 4});
        printListNode(l2);
        ListNode res = solution.addTwoNumbers(l1, l2);
        printListNode(res);
        System.out.println("done!");
    }

    //leetcode submit region begin(Prohibit modification and deletion)

    /**
     * Definition for singly-linked list.
     * public class ListNode {
     * int val;
     * ListNode next;
     * ListNode() {}
     * ListNode(int val) { this.val = val; }
     * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            int temp = 0;
            int len1 = countLengthOfList(l1);
            int len2 = countLengthOfList(l2);
            int len = java.lang.Integer.max(len1, len2);
            ListNode head = null;
            ListNode pointer = null;
            ListNode tempNode = null;
            for (int i = 0; i < len; i++) {
                if (l1 != null && l2 != null) {
                    int t = (l1.val + l2.val + temp) % 10;
                    temp = l1.val + l2.val + temp - 10 >= 0 ? 1 : 0;
                    tempNode = new ListNode(t);
                } else if (l1 != null && l2 == null) {
                    tempNode = new ListNode(l1.val);
                } else if (l1 == null && l2 != null) {
                    tempNode = new ListNode(l2.val);
                }
                if (pointer != null) {
                    pointer.next = tempNode;
                }
                pointer = tempNode;
                if (head == null) head = pointer;
                l1 = l1.next;
                l2 = l2.next;
            }
            return head;
        }

        private int countLengthOfList(ListNode list) {
            int len = 0;
            while (list != null) {
                len += 1;
                list = list.next;
            }
            return len;
        }

    }
//leetcode submit region end(Prohibit modification and deletion)

}