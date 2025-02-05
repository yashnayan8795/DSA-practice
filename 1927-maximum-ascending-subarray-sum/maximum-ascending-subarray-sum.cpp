class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int csum = nums[0];
        int msum = nums[0];
        for(int i=1;i<nums.size();i++){

            if(nums[i-1]<nums[i]){
                csum += nums[i];
            }
            else{
                msum = max(msum,csum);
                csum=nums[i];
            }
        }
        return max(msum,csum);
    }
};