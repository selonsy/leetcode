//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
// 示例 1：
//
//
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
//
//
// 示例 2：
//
//
//输入：l1 = [], l2 = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：l1 = [], l2 = [0]
//输出：[0]
//
//
//
//
// 提示：
//
//
// 两个链表的节点数目范围是 [0, 50]
// -100 <= Node.val <= 100
// l1 和 l2 均按 非递减顺序 排列
//
// Related Topics 递归 链表
// 👍 1551 👎 0

// 题目名称：合并两个有序链表
// 作者：selonsy 时间：2021-02-23 20:16:47
/*
解题思路：
*/
package main

import "fmt"

func main() {
	// TODO:

	fmt.Print("done")
}

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil && l2 == nil {
		return nil
	}
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var head *ListNode
	var tail *ListNode
	for p1, p2 := l1.Val, l2.Val; l1 != nil || l2 != nil; {
		left, right := p1, p2
		if p1 > p2 {
			left, right = p2, p1
		}
		if head == nil {

		}
	}

	return nil
}

//leetcode submit region end(Prohibit modification and deletion)
