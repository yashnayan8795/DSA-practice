class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) 
            return -1;
      
        int n = grid.size(); 
        grid[0][0] = 1; 
        queue<pair<int, int>> q; 

        q.emplace(0, 0); 
      
        for (int p = 1; !q.empty(); p++) {
            for (int k = q.size(); k > 0; --k) {
                auto [row, col] = q.front(); 
                q.pop(); 

                if(row==n-1 && col== n-1)
                    return p;  //path ka length
                for (int x = row - 1; x <= row + 1; ++x) {
                    for (int y = col - 1; y <= col + 1; ++y) {
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0) {

                            grid[x][y] = 1; 
                            q.emplace(x, y); 
                        }
                    }
                }

            }
        }
      
        return -1;
    }
    
};