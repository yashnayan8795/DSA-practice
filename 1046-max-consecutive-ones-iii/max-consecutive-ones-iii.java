class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0;
        int zeroes = 0;
        int maxlen = 0;
        int n = nums.length;

        for (int r=0;r < nums.length;r++) {
            if (nums[r] == 0) {
                zeroes++;
            }
            if (zeroes > k) {
                if (nums[l] == 0) {
                    zeroes--;
                }
                l++;
            }
            maxlen = Math.max(maxlen, r - l + 1);
        }
        return maxlen;
    }
}
