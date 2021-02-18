
//Date:2020-10-25 20:33:10

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 4502 👎 0


package leetcode.editor.cn;

//Java：无重复字符的最长子串
public class P3LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        Solution solution = new P3LongestSubstringWithoutRepeatingCharacters().new Solution();
        // TO TEST
        int res1 = solution.lengthOfLongestSubstring("abcabcbb");
        int res2 = solution.lengthOfLongestSubstring("bbbbb");
        int res3 = solution.lengthOfLongestSubstring("pwwkew");
        System.out.println(res1 + " " + res2 + " " + res3);
        assert res1 == 3 : "error";
        assert res2 == 1 : "error";
        assert res3 == 3 : "error";
    }

    //leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
        public int lengthOfLongestSubstring(String s) {
            
            return 0;
        }
    }
//leetcode submit region end(Prohibit modification and deletion)

}
