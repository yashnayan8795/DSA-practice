class Solution {
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    
    void dfs(vector<vector<int>>& grid, int x, int y, int time, vector<vector<int>>& visited) {
        int m = grid.size(), n = grid[0].size();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                if (visited[nx][ny] > time + 1) {
                    visited[nx][ny] = time + 1;
                    dfs(grid, nx, ny, time + 1, visited);
                }
            }
        }
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    continue;
                }
                if (grid[i][j] == 2) {
                    visited[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j, 0, visited);
                }
            }
        }

        int maxTime = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == INT_MAX) {
                    return -1;
                }
                if (visited[i][j] != INT_MAX) {
                    maxTime = max(maxTime, visited[i][j]);
                }
            }
        }

        return maxTime;
    }
};