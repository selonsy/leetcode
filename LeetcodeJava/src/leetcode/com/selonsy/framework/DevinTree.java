package com.selonsy.framework;

import java.util.ArrayList;

/**
 * Copyright：Sichen International Co. Ltd.
 * 提供二叉树相关的常用操作
 * @author selonsy
 * Created on 2019/12/1.
 * Desc : none
 */
public class DevinTree {
    /**
     * 根据层序遍历进行二叉树的构建
     * @param array int类型的数组，值为-1表示空节点
     * @return 构造完成的二叉树的根节点
     */
    public static TreeNode refactorTreeWithLevelOrder(ArrayList<Integer> array) {
        ArrayList<TreeNode> nodes = new ArrayList<TreeNode>();
        TreeNode root = new TreeNode(array.get(0));

        nodes.add(root);
        int index = 0;
        for (int i = 1; i < array.size(); i = i + 2) {
            int l = array.get(i).intValue();
            int r = array.get(i + 1).intValue();
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
        return root;
    }
}
