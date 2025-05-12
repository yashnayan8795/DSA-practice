class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // for (int i =0; i <k; i++) {
        //     int l= nums[n -1];
        //     for (int j =n -1; j> 0;j--) {
        //         nums[j]=nums[j - 1];
        //     }
        //     nums[0] =l;
        // }  
        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin() + k);  
        reverse(nums.begin() + k, nums.end());  
    }
};
