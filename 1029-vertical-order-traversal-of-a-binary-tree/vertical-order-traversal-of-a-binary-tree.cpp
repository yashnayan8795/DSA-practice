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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        if (root == NULL) return {};

        q.push({root, {0, 0}}); // {node, {hd, level}}

        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            TreeNode* front = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].insert(front->val); // use multiset to keep values sorted

            if (front->left) 
                q.push({front->left, {hd - 1, level + 1}});
            if (front->right) 
                q.push({front->right, {hd + 1, level + 1}});
        }

        vector<vector<int>> ans;
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

