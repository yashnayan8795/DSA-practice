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
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
            std::unordered_map<int, int> inorderMap;
            for (int i = 0; i < inorder.size(); ++i) {
                inorderMap[inorder[i]] = i;
            }
            return buildTreeHelper(preorder, 0, preorder.size() - 1, inorderMap, 0, inorder.size() - 1);
        }
    private:
        TreeNode* buildTreeHelper(const vector<int>& preorder, int preStart, int preEnd,
                                  const unordered_map<int, int>& inorderMap, int inStart, int inEnd) {
            if (preStart > preEnd || inStart > inEnd) {
                return nullptr; 
            }
            TreeNode* root = new TreeNode(preorder[preStart]);
            int inIndex = inorderMap.at(preorder[preStart]);
            int leftSubtreeSize = inIndex - inStart;
            root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inorderMap, inStart, inIndex - 1);
            root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorderMap, inIndex + 1, inEnd);
            return root;
        }
    };