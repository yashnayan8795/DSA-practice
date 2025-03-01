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
    TreeNode* solve(vector<int>& preorder,int prestart,int preend,
                    vector<int>& postorder, int poststart,int postend,
                    unordered_map<int,int>& postmap){
                        if(prestart<0 ||prestart>=preorder.size()|| prestart>preend ||poststart>postend)
                            return nullptr;

                        int value =preorder[prestart];
                        TreeNode* root=new TreeNode(value);

                        int leftprestart=prestart+1;
                        if(prestart==preend) return root;

                        int leftvalue=preorder[prestart+1];
                        int leftpreend=prestart+postmap[leftvalue] - poststart+1;
                        
                        int rightprestart=leftpreend+1;
                        int rightpreend=preend;

                        int leftpoststart=poststart;
                        int leftpostend=postmap[leftvalue];

                        int rightpoststart = leftpostend + 1;
                        int rightpostend = postend - 1;


                        root->left = solve(preorder, leftprestart, leftpreend, 
                                        postorder, leftpoststart, leftpostend, postmap);
                        root->right = solve(preorder, rightprestart, rightpreend,
                                        postorder, rightpoststart, rightpostend, postmap);

        return root;
                    }






    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postMap;

        for(int i=0; i<postorder.size(); i++){
            postMap[postorder[i]] = i;
        }
        
        TreeNode* root = solve(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postMap);
        return root;
    }
};