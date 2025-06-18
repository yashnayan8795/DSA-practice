class Solution {
    public int[] nextGreaterElements(int[] nums) {
        
        int[] ans = new int[nums.length];
        Stack<Integer> stack = new Stack<>();

        for (int i = 2 * nums.length - 1; i >= 0; i--) {
            int curr = nums[i % nums.length];
            while (!stack.isEmpty() && stack.peek() <= curr) {
                stack.pop();
            }

            if (i < nums.length) {
                ans[i] = stack.isEmpty() ? -1 : stack.peek();
            }

            stack.push(curr);
        }

        return ans;
    }
}
