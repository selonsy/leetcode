package leetcode.test;

import leetcode.leetcode_0001_Two_Sum_两数之和;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;


class leetcode_0001_Two_Sum_两数之和_Test {

    @Test
    void twoSum() {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] answer = {0, 1};

        int[] results = new leetcode_0001_Two_Sum_两数之和().twoSum(nums, target);
        int[] results_1 = new leetcode_0001_Two_Sum_两数之和().twoSum_1(nums, target);
        assertArrayEquals(answer, results);
        assertArrayEquals(answer, results_1);
    }

    @Test
    void twoSum_1() {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] answer = {0, 1};
        int[] results_1 = new leetcode_0001_Two_Sum_两数之和().twoSum_1(nums, target);
        assertArrayEquals(answer, results_1);
    }
}