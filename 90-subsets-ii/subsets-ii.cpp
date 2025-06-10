class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;
        ps(nums, ans, 0, allsubsets);
        return allsubsets;
    }
    
    void ps(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets) {
        if(i == nums.size()) {
            allsubsets.push_back(ans);  
            return;
        }
        
        ans.push_back(nums[i]);
        ps(nums, ans, i+1, allsubsets);
        ans.pop_back();
        // modification to subset 1 problem here--
        int idx=i+1;
        while(idx<nums.size() && nums[i]==nums[idx]){
            idx++;
        }
        ps(nums,ans,idx,allsubsets);
    }
};