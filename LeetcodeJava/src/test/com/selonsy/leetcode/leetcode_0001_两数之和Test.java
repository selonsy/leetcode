package com.selonsy.leetcode;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.*;

/**
 * Copyright：Sichen International Co. Ltd.
 *
 * @author selonsy
 * Created on 2019/12/1.
 * Desc : none
 */
public class leetcode_0001_两数之和Test {

    @Test
    void twoSum() {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] answer = {0, 1};

        int[] results = new leetcode_0001_两数之和().twoSum(nums, target);
        int[] results_1 = new leetcode_0001_两数之和().twoSum_1(nums, target);
        assertArrayEquals(answer, results);
        assertArrayEquals(answer, results_1);
    }

    @Test
    void twoSum_1() {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] answer = {0, 1};
        int[] results_1 = new leetcode_0001_两数之和().twoSum_1(nums, target);
        assertArrayEquals(answer, results_1);
    }
}