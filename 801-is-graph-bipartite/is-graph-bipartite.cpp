class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }

        return true;
    }
    
private:
    bool dfs(int node,int col,vector<vector<int>>& grid,vector<int>& color){
        color[node]=col;
        for(auto i : grid[node]){
            if(color[i]==-1){
                if(dfs(i,!col,grid,color)==false){
                    return false;
                }
            }
            else if(color[i]==col){
                return false;
            }

        }
        return true;

    }
    
};