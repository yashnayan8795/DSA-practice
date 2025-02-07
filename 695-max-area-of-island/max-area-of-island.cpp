class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0},{0, 1}, {0, -1}};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    grid[r][c] = 0;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        area++;
                        for (auto [dx, dy] : directions) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                                q.push({nx, ny});
                                grid[nx][ny] = 0;
                            }
                        }
                    }

                    max_area = max(max_area, area);
                }
            }
        }
        
        return max_area;
    }
};