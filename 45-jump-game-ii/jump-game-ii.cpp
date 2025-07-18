class Solution {
public:
    int jump(vector<int>& nums) {
       int n= nums.size();
       if(n==1){
           return 0;
       } 
       int jumps=0;
       int curr_end=0;
       int curr_far=0;
       for(int i=0;i<n-1;++i){
           curr_far=max(curr_far,i+nums[i]);
           if(i==curr_end){
               curr_end =curr_far;
               jumps++;
           }
       }
       return jumps;
    }
};

