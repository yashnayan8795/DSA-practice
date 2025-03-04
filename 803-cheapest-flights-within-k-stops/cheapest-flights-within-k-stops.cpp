class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //      vector<vector<pair<int, int>>> grid(n); 
        
    //     for(auto i:flights)
    //         grid[i[0]].push_back({i[1],i[2]});

    //     queue<pair<int,pair<int,int>>> q;
    //     q.push({0,{src,0}});

    //     vector<int> dist(n,1e9);
    //     dist[src]=0;
    //     while(!q.empty()){
    //         auto it=q.front();
    //         q.pop();

    //         int stop=it.first;
    //         int node= it.second.first;
    //         int cost= it.second.second;

    //         if(stop>k) continue;
    //         for (auto j : grid[node])
    //         {
    //             int gridnode = j.first;
    //             int edges_w = j.second;
    //             if (cost + edges_w < dist[gridnode] && stop <= k)
    //             {
    //                 dist[gridnode] = cost + edges_w;
    //                 q.push({stop + 1, {gridnode, cost + edges_w}});
    //             }
    //         }
    //     }
    //     if (dist[dst] == 1e9)
    //         return -1;
    //     return dist[dst];
    // }
        int INF = 0x3f3f3f3f; 
        vector<int> distances(n, INF);
        vector<int> previousIterationDistances; 
        distances[src] = 0; 
        for (int i = 0; i < k + 1; ++i) {
            
            previousIterationDistances = distances;

            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
              
                if (previousIterationDistances[from] < INF) {
                    distances[to] = min(distances[to], previousIterationDistances[from] + price);
                }
            }
        }
        return distances[dst] == INF ? -1 : distances[dst];
    }
};      