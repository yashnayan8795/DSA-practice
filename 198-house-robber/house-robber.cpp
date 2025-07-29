class Solution {
public:
    int t[101];
    int rob(vector<int>& nums) {
        int n = nums.size();

        memset(t,-1,sizeof(t));

        return solve(nums, 0, n);
    }
    // recursion+ dp memoization 
    int solve(vector<int>& nums, int k, int n) {
        if (k >= n) return 0;

        if(t[k] !=-1) return t[k];

        int steal = nums[k] + solve(nums, k + 2, n);
        int skip = solve(nums, k + 1, n);
        return t[k]=max(steal, skip);
    }
};
