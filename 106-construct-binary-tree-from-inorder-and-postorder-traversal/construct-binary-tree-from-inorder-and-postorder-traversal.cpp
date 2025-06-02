class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }
        int post_idx = postorder.size() - 1;
        return buildTreeHelper(postorder, post_idx, inorder, 0, inorder.size()-1, inorder_map);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& postorder, int& post_idx,vector<int>& inorder, int in_start, int in_end,unordered_map<int, int>& inorder_map) {
        if (in_start > in_end || post_idx < 0) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[post_idx--]);

        auto it = inorder_map.find(root->val);

        if (it != inorder_map.end()) {
            int in_idx = it->second;
            root->right = buildTreeHelper(postorder, post_idx, inorder, in_idx + 1, in_end, inorder_map);
            root->left = buildTreeHelper(postorder, post_idx, inorder, in_start, in_idx - 1, inorder_map);
        }

        return root;
    }
};