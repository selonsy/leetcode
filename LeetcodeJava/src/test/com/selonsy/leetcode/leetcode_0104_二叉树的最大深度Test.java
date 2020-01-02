package com.selonsy.leetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Copyright：Sichen International Co. Ltd.
 *
 * @author selonsy
 * Created on 2019/12/1.
 * Desc : none
 */
class leetcode_0104_二叉树的最大深度Test {

    @Test
    void maxDepth() {
        //        给定二叉树 [3,9,20,null,null,15,7]，
        //
        //         3
        //        / \
        //       9  20
        //         /  \
        //        15  7

        int[] tree = new int[]{3, 9, 20, -1, -1, 15, 7};
        ArrayList<TreeNode> nodes = new ArrayList<TreeNode>();
        TreeNode root = new TreeNode(tree[0]);

        nodes.add(root);
        int index = 0;
        for (int i = 1; i < tree.length; i = i + 2) {
            int l = tree[i];
            int r = tree[i + 1];
            TreeNode left = null, right = null;
            if (l != -1) left = new TreeNode(l);
            if (r != -1) right = new TreeNode(r);
            nodes.add(left);
            nodes.add(right);
            if (nodes.get(index) != null) {
                if (left != null) nodes.get(index).left = left;
                if (right != null) nodes.get(index).right = right;
            }
            index++;
        }

        int actual = new leetcode_0104_二叉树的最大深度().maxDepth(root);
        assertEquals(3, actual);
    }
}

//Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}