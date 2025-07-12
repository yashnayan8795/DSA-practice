class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        

        vector<vector<int>> allSubsets;
        vector<int> ans;
        ps(nums,ans,0,allSubsets);
        return allSubsets;
    }
    
    void ps(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets) {
        if(i == nums.size()) {
            allsubsets.push_back(ans);  
            return;
        }
        
        ans.push_back(nums[i]);
        ps(nums, ans, i+1, allsubsets);
        
        ans.pop_back();
        ps(nums, ans, i+1, allsubsets);
    }
};