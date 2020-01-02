package com.selonsy.leetcode;

import java.util.HashMap;

/**
 * two_sum / 1
 */
public class leetcode_0001_两数之和 {

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] result = new int[2];

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                result[0] = map.get(target - nums[i]);
                result[1] = i;
            } else {
                map.put(nums[i], i);
            }
        }
        return result;
    }

    public int[] twoSum_1(int[] nums, int target) {
        int[] indices = new int[2];

        for (int i = 0; i < nums.length; i++) {
            int current = nums[i];
            for (int j = i + 1; j < nums.length; j++) {
                if (current + nums[j] == target) {
                    indices[0] = i;
                    indices[1] = j;
                }
            }
        }

        return indices;
    }
}
