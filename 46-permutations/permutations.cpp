class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getper(nums,ans,0);
        return ans;
    }
    void getper(vector<int>& nums, vector<vector<int>>& ans, int idx){
        if(idx==nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i=idx;i<nums.size();i++){
            //if (i != idx && nums[i] == nums[idx]) continue;  // Skip duplicates
            swap(nums[idx],nums[i]);
            getper(nums,ans,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
};