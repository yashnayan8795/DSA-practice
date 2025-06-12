class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        sort(candidates.begin(), candidates.end());
        combsum(candidates, target,combin,0, ans);
        return ans;
    }

    void combsum(vector<int>& candidates, int target, vector<int>& combin,int idx, vector<vector<int>>& ans) {
        if(target<0) return;
        if (target == 0) {
            ans.push_back(combin);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            combin.push_back(candidates[i]);
            combsum(candidates,target - candidates[i], combin, i+1  ,ans );
            combin.pop_back();
        }
    }
};