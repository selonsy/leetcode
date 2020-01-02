package com.selonsy.leetcode;

//        maximum-depth-of-binary-tree / 104
//
//        给定一个二叉树，找出其最大深度。
//
//        二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//        说明: 叶子节点是指没有子节点的节点。
//
//        示例：
//        给定二叉树 [3,9,20,null,null,15,7]，
//
//         3
//        / \
//       9  20
//         /  \
//        15  7
//
//        返回它的最大深度 3 。

//        解题思路：
//        题目要求求出二叉树的最大深度，我们知道，每个节点的深度与它左右子树的深度有关，且等于其左右子树最大深度值加上 1，可以写作：
//        maxDepth(root) = max(maxDepth(root.left), maxDepth(root.right)) + 1

//        推导过程整体如下：
//        maxDepth(3-root)
//        =
//        max(maxDepth(4-sub), maxDepth(20-sub)) + 1
//        =
//        max(1, max(maxDepth(15-sub), maxDepth(7-sub)) + 1) + 1
//        =
//        max(1, maxDepth(1, 1) + 1) + 1
//        =
//        max(1, 2) + 1
//        =
//        2 + 1
//        =
//        3
//        在推导过程中我们看到 maxDepth() 函数频繁出现，即我们在频繁地求取某节点的最大深度。由此可见，「求节点的最大深度」是该题的子问题，该题最直观的解答方式是用递归求解。

import static java.lang.Integer.max;

//Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

public class leetcode_0104_二叉树的最大深度 {

    public int maxDepth(TreeNode root) {
//        明确函数作用
//        该函数的作用用一句话概括就是：计算节点的最大深度。
//
//        函数输入：确定的节点
//        函数输出：该节点的最大深度
//
//        何时结束
//        当输入的节点为空节点时，我们无需继续计算其子树的深度，此时可以直接结束递归函数，并返回空节点的深度为 0。
//
//        何时调用
//        当输入节点为非空节点时，该节点的深度取决于其左右子树的深度，即：
//        maxDepth(root) = max(maxDepth(root.left), maxDepth(root.right)) + 1
//        此时需要进行函数的递归调用。
        if (root == null) {
            return 0;
        }
        return max(maxDepth(root.left),maxDepth(root.right))+1;
    }
}
