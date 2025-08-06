class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int odd = 0;
        int count = 0;
        int l = 0;
        int r = 0;
        while(r<n)
        {
            if(nums[r]%2 != 0)
            {
                odd++;
                count = 0;
            }
            while(odd == k)
            {
                ++count;
                odd -= nums[l++]&1; 
            }
            ans += count;
            r++;
        }
        return ans;
    }
};