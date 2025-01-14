class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(int val: nums){
            x=x^val;
        }
        return x;
    }
};