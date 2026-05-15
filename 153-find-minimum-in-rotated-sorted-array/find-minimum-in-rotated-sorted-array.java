class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int st = 0;
        int end = n - 1;
        while (st < end) {
            int mid = st + (end - st)/2;

            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end = mid ;
            }
        }
        return nums[end];
    }
}