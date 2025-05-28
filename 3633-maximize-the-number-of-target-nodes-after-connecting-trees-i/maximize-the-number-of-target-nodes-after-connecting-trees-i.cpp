class Solution {
public:
    #define pii pair<int,int>

    int BFS(int start, vector<vector<int>>& adj, int k){
        int count = 0;
        queue<pii> q;
        q.push({start, -1});
        while(q.size()> 0 && k >= 0){
            int size = q.size();
            count += size;
            for(int i=0; i<size; i++){
                pii current = q.front();
                q.pop();
                int u = current.first;
                int parent = current.second;
                for(int v : adj[u]){
                    if(v!=parent) q.push({v,u});
                }
            }
            k--;
        }
        return count;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<int> ans(n);
        //build the tree
        vector<vector<int>> adj1(n), adj2(m);
        for(auto & edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto & edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        //find the best node from second tree;
        int best = 0;
        for(int i=0; i<m; ++i){
            best = max(best, BFS(i, adj2, k-1));
        }
        for(int i=0; i<n; i++){
            int currentAns = BFS(i, adj1, k);
            ans[i] =  currentAns + best;
        }
        return ans;
    }
};