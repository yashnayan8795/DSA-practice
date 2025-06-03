class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r]==0){
                if(k==0){
                    while(nums[l]!=0) l+=1;
                    l+=1;

                }else{
                    k-=1;

                }
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};