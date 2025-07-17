class Solution {
public:
    int maximumLength(vector<int>& A, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int a : A)
            for (int b = 0; b < k; b++)
                res = max(res, dp[b][a % k] = dp[a % k][b] + 1);
        return res;
    }
};