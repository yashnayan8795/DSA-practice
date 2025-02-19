class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);

        }
        vector<int> indegree(numCourses,0);
        for(int j=0;j<numCourses;j++)
            for(auto it:adj[j])
                indegree[it]++;


        queue<int> q;
        for(int k=0;k<numCourses;k++){
            if(indegree[k]==0){
                q.push(k);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses)
            return topo;
        else
            return {};
        
    }
};