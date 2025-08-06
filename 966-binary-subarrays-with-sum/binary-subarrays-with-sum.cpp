class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
    
        unordered_map<int, int> count_map;
        count_map[0]= 1;
        int ans=0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int m = sum - goal;
            if (count_map.find(m) != count_map.end()) {
                ans += count_map[m];  
            }
            count_map[sum] += 1; 
        }
        return ans;
    }
};