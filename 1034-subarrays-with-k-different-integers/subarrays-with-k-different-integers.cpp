class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k)-slidingWindowAtMost(nums,k-1);
    }
    int slidingWindowAtMost(vector<int>& nums, int distinctK) {
        unordered_map<int, int> freq;

        int l = 0;
        int total = 0;

        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;
            while (freq.size() > distinctK) {
                freq[nums[l]]--;

                if (freq[nums[l]] == 0)

                    freq.erase(nums[l]);
                l++;
            }
            total += (r-l+1);
        }
        return total;
    }
};