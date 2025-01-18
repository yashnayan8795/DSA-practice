class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        vector<vector<int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        deque<pair<int, int>> queue;
        queue.push_back({0, 0});

        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop_front();
            int row = current.first / cols, col = current.first % cols;
            int cost = current.second;

            if (row == rows - 1 && col == cols - 1) return cost;

        
            if (visited[row][col]) continue;

            visited[row][col] = true;

            for (int k = 1; k <= 4; ++k) {
                int newRow = row + directions[k][0], newCol = col + directions[k][1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newIndex = newRow * cols + newCol;

                    if (grid[row][col] == k)
                        queue.push_front({newIndex, cost});
                    else
                        queue.push_back({newIndex, cost + 1});
                }
            }
        }

        return -1;
    }
};