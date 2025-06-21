class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int maxval = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxval) {
                return false;
            }
            maxval = Math.max(maxval, i + nums[i]);
            if (maxval >= n - 1) {
                return true;
            }
        }
        return false;
    }
}