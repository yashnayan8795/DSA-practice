class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> nextRow = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curRow(n);
            for (int j = 0; j < n; j++) {
                int down = nextRow[j];
                int left = (j > 0) ? nextRow[j - 1] : 1e9;
                int right = (j < n - 1) ? nextRow[j + 1] : 1e9;
                curRow[j] = matrix[i][j] + min({down, left, right});
            }
            nextRow = curRow;
        }

        return *min_element(nextRow.begin(), nextRow.end());
    }
};