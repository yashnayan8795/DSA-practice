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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxwidth=0;
        while(q.size()>0){
            int currlevel=q.size();
            unsigned long long stidx= q.front().second;
            unsigned long long endidx=q.back().second;
            maxwidth= max(maxwidth,(int)(endidx-stidx+1));
            for(int i=0;i< currlevel;i++){
                auto curr=q.front();
                q.pop();
                if(curr.first->left!=NULL) q.push({curr.first->left,2*curr.second+1});
                if(curr.first->right!=NULL) q.push({curr.first->right,2*curr.second+2});
            }
        }
        return maxwidth;
    }
};