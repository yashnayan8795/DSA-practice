class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase; 
        deque<int> decrease;

        int maxLen = 0;
        int left = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];

            
            while (!increase.empty() && n < increase.back()) {
                increase.pop_back();
            }
            increase.push_back(n);

            while (!decrease.empty() && n > decrease.back()) {
                decrease.pop_back();
            }
            decrease.push_back(n);

            while (!increase.empty() && !decrease.empty() &&
                   (decrease.front() - increase.front() > limit)) {
                if (nums[left] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front()) {
                    increase.pop_front();
                }
                ++left;
            }

            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
    }
};
