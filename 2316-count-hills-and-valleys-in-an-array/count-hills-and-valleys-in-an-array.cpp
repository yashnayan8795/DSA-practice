class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int l = 0, r = 1, result = 0;
        while(r < nums.size() - 1){
            
            if(nums[l] < nums[r] && nums[r] > nums[r + 1])
                result++;
            
            else if(nums[l] > nums[r] && nums[r] < nums[r + 1])
                result++;
            
            if (nums[r] != nums[r + 1])
                l = r;
            r++;
        }
        return result;
    
    }
};