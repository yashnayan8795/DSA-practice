class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for (auto& t : times) 
            adj[t[0]].push_back({t[2], t[1]}); // {time, destination}
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> minTime(n + 1, INT_MAX);
        
        pq.push({0, k});  
        minTime[k] = 0;

        while (!pq.empty()) {
            auto [curTime, node] = pq.top();
            pq.pop();

            if (curTime > minTime[node]) continue;

            for (auto& [time, neighbor] : adj[node]) {
                if (curTime + time < minTime[neighbor]) {
                    minTime[neighbor] = curTime + time;
                    pq.push({minTime[neighbor], neighbor});
                }
            }
        }

        int maxDelay = *max_element(minTime.begin() + 1, minTime.end());
        return maxDelay == INT_MAX ? -1 : maxDelay;
    }
};
