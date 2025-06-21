class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        if (n <= 1) return 0;

        int j = 0;
        int curr = 0;
        int maxval = 0;

        for (int i = 0; i < n - 1; i++) {
            maxval = Math.max(maxval, i + nums[i]);

            if (i == curr) {
                j++;
                curr = maxval;

                if (curr >= n - 1) break;
            }
        }

        return j;
    }
}
