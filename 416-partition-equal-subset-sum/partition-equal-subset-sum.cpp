class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        
        if (totalSum % 2 != 0) return false; 
        
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSumUtil(n - 1, target, nums, dp);
    }
        bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0)
            return dp[ind][target] = true;
        if (ind == 0)
            return dp[ind][target] = (arr[0] == target);
        if (dp[ind][target] != -1)
            return dp[ind][target];
        bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
        bool taken = false;
        if (arr[ind] <= target)
            taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = notTaken || taken;
    }
};

