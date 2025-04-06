
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);  // Step 1: Sort the array
        int n = nums.length;
        int[] dp = new int[n];      // dp[i] = size of subset ending at nums[i]
        int[] parent = new int[n];  // to reconstruct the subset
        Arrays.fill(dp, 1);         // every number is a subset of size 1
        Arrays.fill(parent, -1);    // initially no parent
        int maxSize = 0, maxIndex = -1;

        // Step 2: Fill dp and parent
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Step 3: Reconstruct the subset
        List<Integer> subset = new ArrayList<>();
        while (maxIndex != -1) {
            subset.add(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }

        return subset;
    }
}