class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(m, grid[0][0]);
        vector<int> curr(m, 0);
        for (int i = 1; i < m; i++)
            prev[i] = prev[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            curr[0] = prev[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                curr[i] = min(curr[i - 1], prev[i]) + grid[i][j];
            swap(prev, curr); 
        }
        return prev[m - 1];

    }
};