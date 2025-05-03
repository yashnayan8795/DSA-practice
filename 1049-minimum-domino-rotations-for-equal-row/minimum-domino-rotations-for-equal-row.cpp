class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=solve(tops,bottoms,tops[0]);
        if(tops[0]!=bottoms[0]){
            ans= min(ans,solve(tops,bottoms,bottoms[0]));

        }
        return (ans==INT_MAX) ? -1 : ans;
    }
private:
    int solve(vector<int>& tops, vector<int>& bottoms, int target) {
        int top = 0;
        int bottom = 0;
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target)
                return INT_MAX; 
            if (tops[i] != target)
                top++;   
            if (bottoms[i] != target)
                bottom++;
        }
        return min(top, bottom);
    }
};