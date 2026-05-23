class Solution {
    public boolean check(int[] nums) {
        int x = nums.length;
        int count = 0;

        for (int i = 1; i < x; i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
            }
        }

        if (nums[x - 1] > nums[0]) {
            count++;
        }

        return count <= 1;
    }
}