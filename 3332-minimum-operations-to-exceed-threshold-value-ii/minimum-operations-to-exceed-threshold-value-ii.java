class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Integer> prior = new PriorityQueue<>();
        for (int n : nums) {
            if (n < k) prior.add(n);
        }

        int o = 0;

        while (!prior.isEmpty()) {
            int a = prior.poll();
            o++;

            if (prior.isEmpty()) break;

            int b= prior.poll();
            long newValue = 2L * a + b;

            if (newValue < k) prior.add((int) newValue);
        }

        return o;
    }
}