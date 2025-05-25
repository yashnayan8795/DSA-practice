/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        if(root ==null) return 0;

        int leftdiam= diameterOfBinaryTree(root.left);
        int rightdiam= diameterOfBinaryTree(root.right);
        int currdiam= height(root.left)+height(root.right);

        return Math.max(Math.max(leftdiam,rightdiam),currdiam);
    }

    public int height(TreeNode root){
        if(root== null) return 0;
        int leftht = height(root.left);
        int rightht = height(root.right);

        return Math.max(leftht, rightht) + 1;

    }
}