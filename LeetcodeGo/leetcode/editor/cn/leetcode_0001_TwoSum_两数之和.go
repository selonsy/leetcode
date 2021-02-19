//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
// 你可以按任意顺序返回答案。
//
//
//
// 示例 1：
//
//
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
//
//
// 示例 2：
//
//
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
//
//
// 示例 3：
//
//
//输入：nums = [3,3], target = 6
//输出：[0,1]
//
//
//
//
// 提示：
//
//
// 2 <= nums.length <= 103
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// 只会存在一个有效答案
//
// Related Topics 数组 哈希表
// 👍 10294 👎 0

// 两数之和
// selonsy-2021-02-18 15:38:41
/*
解题思路：哈希表 or 暴力法
*/
package main

import "fmt"

func main() {
	target := 9
	nums := []int{2, 7, 11, 15}

	res := twoSum(nums, target)
	fmt.Println(res)

	res1 := twoSum1(nums, target)
	fmt.Println(res1)

	fmt.Println("done")
}

// 暴力法，时间复杂度O(N*N)，空间复杂度O(N)
func twoSum1(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return nil
}

// 哈希表，时间复杂度O(N)，空间复杂度O(N)
//leetcode submit region begin(Prohibit modification and deletion)
func twoSum(nums []int, target int) []int {
	hash := make(map[int]int, 0)
	for i, v := range nums {
		if j, ok := hash[target-v]; ok {
			return []int{j, i}
		}
		hash[v] = i
	}
	return nil
}

//leetcode submit region end(Prohibit modification and deletion)
