class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        permute(nums, 0, ans);
        return ans;
    }
private:
    void permute(vector<int> nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); j++) {
                if (j == i || nums[j] != nums[i]) {
                    swap(nums[i], nums[j]);
                    permute(nums, i + 1, ans);
                }
            }
        }
    }
};