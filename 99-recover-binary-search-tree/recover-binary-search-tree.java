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
    private TreeNode first= null;
    private TreeNode second = null;
    private TreeNode prev= new TreeNode(Integer.MIN_VALUE);

    public void recoverTree(TreeNode root) {
        if(root== null)
            return;
        traverseTree(root);
        if(first!= null&&second!=null){
            swap(first,second);
        }    
    }
    private void swap(TreeNode x,TreeNode y){
        int temp = x.val;
        x.val = y.val;
        y.val = temp;
    }
    private void traverseTree(TreeNode root) {
        if (root == null) return;
        traverseTree(root.left);
        if (first == null && prev.val > root.val) {
            first = prev;
        }
        if (first != null && prev.val > root.val) {
            second = root;
        }
        prev = root;

        traverseTree(root.right);
    }
}