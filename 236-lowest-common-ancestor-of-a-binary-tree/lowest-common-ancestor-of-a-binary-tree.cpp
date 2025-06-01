/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL) return root;
        if(root==p || root==q) return root;
        if(p==q) return p;
        TreeNode* leftlca= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightlca= lowestCommonAncestor(root->right,p,q);

        if(leftlca!= NULL && rightlca!= NULL) 
            return root;
        else if(leftlca!= NULL)
            return leftlca;
        else
            return rightlca;
    }
};