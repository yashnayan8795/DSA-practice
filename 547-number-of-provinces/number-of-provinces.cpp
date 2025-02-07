class Solution {
private:
    void dfsfrombegin(int start, vector<vector<int>>& adj , vector<int>& visited){
        visited[start]=1;
        for(auto it : adj[start]){
            if(!visited[it]){
                dfsfrombegin(it,adj,visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjLs(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfsfrombegin(i,adjLs,visited);
            }
        }
        return count;
    }
};