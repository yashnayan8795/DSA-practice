class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i =0;i+1<nums.size();i++){
            if(nums[i]==nums[i+1]){
                nums[i]=2*nums[i];
                nums[i+1]=0;

            }
        }
        int i =0;
        for(auto it:nums){
            //sare point collect karo zero wale endse phele
            if(it!=0) nums[i++]=it;
        }

        while(i<nums.size())
            nums[i++]=0;
            // jo bhi humare bache hue vlues hai unko 0 karo ith element  ko
        return nums;

    }
};