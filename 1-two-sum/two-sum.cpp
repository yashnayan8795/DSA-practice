class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int d=target-nums[i];
            if(mp.find(d)!=mp.end()){
                return {mp[d],i};

            }
            mp[nums[i]]=i;
        }
        return {-1,1};
    }
};