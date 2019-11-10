/*
* leetcode 探索算法面试题汇总
* author：selonsy
* time：2019_07_23_18_11_50
*/
#include<vector>
#include<iostream>
#include<assert.h>
#include<unordered_map>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

class Pin_duo_duo {
public:
    int test() {
        cout << "Hello world!";
    }
};
// 堆、栈、队列
class LeetCode_HeapSatckQueue {
public:
    void test() {
        cout << "Hello world!" << endl;
    }
    // 数组中的第K个最大元素
    int findKthLargest_test() {
        /*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/
        vector<int> nums = {3,2,3,1,2,4,5,5,6};
        findKthLargest(nums,4);
    }
    int findKthLargest(vector<int>& nums, int k) {

    }
};

class LeetCode_String {
public:


    // 字符串：反转字符串
    void reverseString_test() {
/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

示例 1：
输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：
输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
*/

        vector<char> ss = {'h', 'e', 'l', 'l', 'o'};
        reverseString1(ss);
    }

    void reverseString1(vector<char> &s) {
        int length = s.size();
        for (int i = 0; i < length / 2; ++i) {
            char t = s[i];
            s[i] = s[length - 1 - i];
            s[length - 1 - i] = t;
        }
        cout << "[";
        for (int j = 0; j < length; ++j) {
            cout << "\"" << s[j] << "\"";
            if (j != length - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }

    void reverseString2(vector<char> &s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    // 字符串：字符串中的第一个唯一字符
    int firstUniqChar_test() {
/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.

注意事项：您可以假定该字符串只包含小写字母。
         * */
        string s = "loveleetcode";
        cout << firstUniqChar(s);
    }

    int firstUniqChar(string s) {
        int arr[26];
        for (int i = 0; i < s.length(); ++i) {
            arr[s[i] - 97]++;
        }
        for (int j = 0; j < s.length(); ++j) {
            if (arr[s[j] - 97] == 1) {
                return j;
            }
        }
        return -1;
    }
};

class Leetcode_Array {
public:
    // 乘积最大子序列
    int maxProduct_test() {
/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

个人理解:可以为一个值,必须要连续.

访问到每个点的时候，以该点为子序列的末尾的乘积，要么是该点本身，要么是该点乘以以前一点为末尾的序列，注意乘积负负得正，
故需要记录前面的最大最小值。
*/
        vector<int> nums = {2, 3, -2, 4};
        cout << maxProduct(nums);
    }

    int maxProduct(vector<int> &nums) {
        int posMax = nums[0];
        int negMax = nums[0];
        int ret = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tempPosMax = posMax;
            int tempNegMax = negMax;
            posMax = max(nums[i], max(nums[i] * tempPosMax, nums[i] * tempNegMax));
            negMax = min(nums[i], min(nums[i] * tempPosMax, nums[i] * tempNegMax));
            ret = max(ret, posMax);
        }
        return ret;
    }

    // 和最大子序列
    int maxSum_test() {
        vector<int> nums = {2, -3, 2, 3};
        cout << maxSum(nums);
    }

    int maxSum(vector<int> &nums) {
        int sum = nums[0];
        int t = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            t = t + nums[i];
            if (t > 0 && t > sum)sum = t;
            if (t < 0) t = 0;
        }
        return sum;
    }
};

int main() {
    LeetCode_String _string;
    Leetcode_Array _array;
    Pin_duo_duo pdd;
    cout << "Begin" << endl;

    pdd.test();
//    _string.firstUniqChar_test();
//    _array.maxProduct_test();
    cout << endl << "Done" << endl;
//    system("pause");
    return 0;
}