class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int result = -1;

        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int ds=gsum(nums[i]);

            if(m.count(ds)){
                result =max(result,nums[i]+m[ds]);
            }
            m[ds]=max(m[ds],nums[i]);

        }
        return result;
    }
    int gsum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;

        }   
        return sum;
    }
};