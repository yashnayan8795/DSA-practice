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
    public TreeNode solve(int prestart, int poststart, int preend, int[] preorder, int[] postorder) {
        if (prestart > preend) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[prestart]);
        if (prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart + 1]; 

        int j = poststart;
        while (postorder[j] != nextNode) {
            j++;
        }
        int num = j - poststart + 1;
        
        root.left = solve(prestart + 1, poststart, prestart + num, preorder, postorder);

        root.right = solve(prestart + num + 1, j + 1, preend, preorder, postorder);
        return root;
    }

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = preorder.length;
        return solve(0, 0, n - 1, preorder, postorder);
    }
}