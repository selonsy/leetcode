package leetcode.editor.cn.util;

import leetcode.editor.cn.model.ListNode;

import java.util.List;

public class ListNodeUtl {

    public static void printListNode(ListNode list) {
        while (list != null) {
            System.out.print(list.val);
            if (list.next != null)
                System.out.print("->");
            list = list.next;
        }
        System.out.println();
    }

    public static ListNode createListNodeByArray(int[] arr) {
        ListNode head = null;
        ListNode p = null;
        for (int i : arr) {
            ListNode t = new ListNode(i);
            if (p != null) {
                p.next = t;
            }
            p = t;
            if (head == null) head = p;
        }
        return head;
    }
}
