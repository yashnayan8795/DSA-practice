class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        vector<vector<int>> t(n,vector<int>(n,2));
    
        for (int i=0;i<n;i++) {
            mp[arr[i]]=i;
        }
        
        int ml=0;
        for (int j=1;j<n;j++) {
            for (int k=j +1; k<n;k++) {
                int target=arr[k]-arr[j];
                if (mp.count(target) && mp[target]< j) {
                    int  i= mp[target];
                    t[j][k] = t[i][j] + 1;
                }
                ml = max(ml, t[j][k]);
            }
        }
        return ml >= 3 ? ml : 0;
    }
};