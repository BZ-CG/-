package cn.pzhu.cg.offer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

/**
 * @Author:CG-PC
 * @Date:2018/9/11
 * @Time:22:18
 */

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }
}

public class GetBinaryTreeAValue {
    private ArrayList<ArrayList<Integer>> result = new ArrayList<>();
    private int temp;

    void dfs(TreeNode cur,int count,ArrayList<Integer> list) {
        int curCount = count + cur.val;
        if (curCount > temp) {
            return;
        } else if (curCount < temp) {
            if (cur.left != null) {
                list.add(cur.val);
                dfs(cur.left,curCount,list);
                list.remove(list.size()-1);
            }
            if(cur.right != null) {
                list.add(cur.val);
                dfs(cur.right,curCount,list);
                list.remove(list.size()-1);
            }
        } else {
            if (cur.left == null && cur.right == null) {
                list.add(cur.val);
                result.add(new ArrayList<Integer>(list));
                list.remove(list.size()-1);
            }
            return;
        }
    }

    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root, int target) {
        if (root == null) {
            return result;
        }
        temp = target;

        dfs(root,0,new ArrayList<Integer>());
        Collections.sort(result, new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                return -(o1.size() - o2.size());
            }
        });
        return result;
    }

//    public static void main (String[] args) {
//        TreeNode root = new TreeNode(10);
//        root.left = new TreeNode(5);
//        root.left.left = new TreeNode(7);
//        root.right = new TreeNode(12);
//
//        ArrayList<ArrayList<Integer>> list = FindPath(root,12);
//    }
}
