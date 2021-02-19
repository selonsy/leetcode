//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//
//
// 示例 1:
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
//
//
// 示例 2:
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
// Related Topics 数组 动态规划
// 👍 951 👎 0

// 题目名称：乘积最大子数组
// 作者：selonsy 时间：2021-02-18 19:34:59
/*
解题思路：
标签：动态规划
遍历数组时计算当前最大值，不断更新
令imax为当前最大值，则当前最大值为 imax = max(imax * nums[i], nums[i])
由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin，imin = min(imin * nums[i], nums[i])
当负数出现时则imax与imin进行交换再进行下一步计算
时间复杂度：O(n)
*/
package main

import "fmt"

func main() {
	nums := []int{0, 2}
	fmt.Println(maxProduct(nums))
	fmt.Println(maxProduct1(nums))
	fmt.Println("done")
}

// 暴力法
func maxProduct1(nums []int) int {
	l := len(nums)
	if l <= 0 {
		return -1
	}
	max := nums[0]
	for i := 0; i < l; i++ {
		temp := nums[i]
		if temp > max {
			max = temp
		}
		for j := i + 1; j < l; j++ {
			temp = temp * nums[j]
			if temp > max {
				max = temp
			}
		}
	}
	return max
}

//
//leetcode submit region begin(Prohibit modification and deletion)
func maxProduct(nums []int) int {
	return 0
}

//leetcode submit region end(Prohibit modification and deletion)
