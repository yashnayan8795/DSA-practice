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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightview(root,0,ans);
        return ans;

    }
    void rightview(TreeNode* root,int level,vector<int>& ds){
        
        if(root==NULL) return;
        if(level == ds.size()) {
            ds.push_back(root->val);
        }
        rightview(root->right,level+1,ds);
        rightview(root->left,level+1,ds);
    }
};