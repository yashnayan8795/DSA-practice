class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> mp, mpc, mpr, mpcc;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j< mat[0].size(); ++j){
                mp[mat[i][j]] = i;     mpc[mat[i][j]] = j;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            int n = arr[i];
            mpr[mp[n]]++;    
            
            mpcc[mpc[n]]++;
            if(mpr[mp[n]] == mat[0].size() || mpcc[mpc[n]] == mat.size()) return i;
        }
        return -1;
    }
};