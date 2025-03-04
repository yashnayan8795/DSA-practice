class Solution {

    vector<int> drow= {-1,0,1,0};
    vector<int> dcol= {0,1,0,-1};
    bool valid(vector<vector<int>>& heights,int mid){
        int rows= heights.size();
        int columns= heights[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(columns));
        queue<int> qrow;
        queue<int> qcol;
        qrow.push(0);
        qcol.push(0);
        vis[0][0]=true;
        while(!qrow.empty()){
            int currow=qrow.front();
            qrow.pop();
            int curcol=qcol.front();
            qcol.pop();
            for(int d=0;d<4;d++){
                int nrow = currow + drow[d];
                int ncol = curcol + dcol[d];
                if (nrow < 0 || nrow >= rows || ncol < 0 || ncol >= columns) {  
                    continue;
                }
                if (vis[nrow][ncol]) {  
                    continue;
                }
                if (abs(heights[nrow][ncol] - heights[currow][curcol]) > mid) {  
                    continue;
                }
                vis[nrow][ncol] = true;
                qrow.push(nrow);
                qcol.push(ncol);

            }
        }
        return vis[rows-1][columns-1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0;
        int high = (int)1e6;
    
        while (low < high) {
            int mid = (low + high) / 2;
            if (valid(heights, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};