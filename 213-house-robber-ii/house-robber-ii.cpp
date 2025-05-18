class Solution {
public:
    int t[101];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        memset(t,-1,sizeof(t));
        int path1= solve(nums, 0, n-1);// leaving last house

        memset(t, -1, sizeof(t));
        int path2 = solve(nums, 1, n); // leaving first house

        return max(path1,path2);
    }
    // recursion
    int solve(vector<int>& nums, int k, int n) {
        if (k >= n) return 0;


        if(t[k] !=-1) return t[k];

        int steal = nums[k] + solve(nums, k + 2, n);
        int skip = solve(nums, k + 1, n);

        return t[k]=max(steal, skip);
    }
};
