//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
//
//
//
// 进阶：
//
//
// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？
//
//
//
//
// 示例 1:
//
//
//输入: nums = [1,2,3,4,5,6,7], k = 3
//输出: [5,6,7,1,2,3,4]
//解释:
//向右旋转 1 步: [7,1,2,3,4,5,6]
//向右旋转 2 步: [6,7,1,2,3,4,5]
//向右旋转 3 步: [5,6,7,1,2,3,4]
//
//
// 示例 2:
//
//
//输入：nums = [-1,-100,3,99], k = 2
//输出：[3,99,-1,-100]
//解释:
//向右旋转 1 步: [99,-1,-100,3]
//向右旋转 2 步: [3,99,-1,-100]
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
//
//
//
//
// Related Topics 数组
// 👍 878 👎 0

// 题目名称：旋转数组
// 作者：selonsy 时间：2021-02-19 16:49:14
/*
解题思路：
*/
package main

import "fmt"

func main() {
	nums1 := []int{1, 2, 3, 4, 5, 6, 7}
	k1 := 3
	nums2 := []int{-1, -100, 3, 99}
	k2 := 2
	rotate2(nums1, k1)
	fmt.Println(nums1)
	rotate2(nums2, k2)
	fmt.Println(nums2)

	fmt.Print("done")
}

// 暴力法
func rotate1(nums []int, k int) {
	l := len(nums)
	tempNum := make([]int, l, l)
	for j := 0; j < l; j++ {
		tempNum[(j+k)%l] = nums[j]
	}
	copy(nums, tempNum)
}

// 数组翻转法
// 先将数组全部翻转，然后把前半部分翻转，再把后半部分翻转
func reverse(nums []int) {
	for i := 0; i < len(nums)/2; i++ {
		nums[i], nums[len(nums)-1-i] = nums[len(nums)-1-i], nums[i]
	}
}
func rotate2(nums []int, k int) {
	l := k % len(nums)
	reverse(nums)
	reverse(nums[0:l])
	reverse(nums[l:])
}

//leetcode submit region begin(Prohibit modification and deletion)
func rotate(nums []int, k int) {
	l := len(nums)
	tempNum := make([]int, l, l)
	for j := 0; j < l; j++ {
		tempNum[(j+k)%l] = nums[j]
	}
	copy(nums, tempNum)
}

//leetcode submit region end(Prohibit modification and deletion)
