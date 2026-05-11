class Solution {
    public int[] separateDigits(int[] nums) {
        int length = 0;
        for(int num : nums) {
            int temp = num;
            while(temp > 0) {
                length++;
                temp /= 10;
            }
        }
        int[] res = new int[length];
        int index = res.length - 1;
        for(int i = nums.length - 1; i >= 0; i--) {
            int temp = nums[i];
            while(temp > 0) {
                res[index--] = temp % 10;
                temp /= 10;
            }
        }
        return res;

    }
}