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




class FindElements {
public:
    unordered_set<int> newvalues;

    void newtree(TreeNode* root) {
        if (!root) return;
        newvalues.insert(root->val);
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            newtree(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            newtree(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root-> val=NULL;
        newtree(root);
    }
    
    bool find(int target) {
        return newvalues.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */