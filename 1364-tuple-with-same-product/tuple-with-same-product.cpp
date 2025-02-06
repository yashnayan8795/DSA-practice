class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int t = 0;

        unordered_map<int, int> mp; 
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int p = nums[j] * nums[i];
                mp[p]++;
            }
        }

        for(unordered_map<int,int>::iterator it=mp.begin(); it!= mp.end();it++) {
            int p = it->first;
            int f = it->second;

            t += (f*(f-1))/2;
        }

        return t * 8;
    }
};