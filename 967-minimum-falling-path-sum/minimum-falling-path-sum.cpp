class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // Start from base case

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int down = dp[i + 1][j];
                int left = (j > 0) ? dp[i + 1][j - 1] : 1e9;
                int right = (j < n - 1) ? dp[i + 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({down, left, right});
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};