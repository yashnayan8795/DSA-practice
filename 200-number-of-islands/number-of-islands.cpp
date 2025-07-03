class Solution {
private:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.emplace(i, j);
        grid[i][j] = '0'; 

        int row = grid.size();
        int col = grid[0].size();
        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newRow = r + delRow[k];
                int newCol = c + delCol[k];

                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && grid[newRow][newCol] == '1') {
                    grid[newRow][newCol] = '0'; 
                    q.emplace(newRow, newCol);
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') { 
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
