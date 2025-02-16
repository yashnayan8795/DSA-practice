class Solution {
    bool helper(vector<int>& ans, vector<bool>& used, int n, int idx) {
        if (idx==ans.size())
            return true;
        if (ans[idx]!=0)
            return  helper(ans, used, n, idx + 1);

        for (int i=n; i>=1;i--) {
            if (used[i])
                continue;
            ans[idx]=i;


            used[i]=true;
            if (i==1) {
                if (helper(ans,used,n,idx+1))

                    return true;
            }
            else if (idx+i<ans.size()&&ans[idx +i]== 0) {
                ans[idx+i] = i;
                if (helper(ans,used, n, idx + 1))
                    return true;

                    
                ans[idx +i] = 0;
            }
            ans[idx]= 0;
            used[i] =false;
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n - 1, 0);

        vector<bool> used(n + 1, false);
        helper(ans,used, n, 0);

        return ans;
    }
};