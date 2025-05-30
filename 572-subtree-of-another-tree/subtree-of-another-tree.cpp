/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL || subRoot== NULL) return root==subRoot;   
        if(root->val==subRoot->val && isIdentical(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool isIdentical(TreeNode* p, TreeNode* q){
        if (p ==NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        if (p->val != q->val) return false;
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
    
};