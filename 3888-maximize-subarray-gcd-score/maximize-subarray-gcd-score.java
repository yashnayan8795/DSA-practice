class Solution {
    public long maxGCDScore(int[] A, int k) {
        int n = A.length, B[] = new int[n], low;
        long res = 0;
        for (int i = 0; i < n; i++) {
            int a = A[i], count = 0, minPow = Integer.MAX_VALUE;
            for (int j = i; j < n; j++) {
                a = gcd(a, A[j]);
                low = A[j] & -A[j];
                if (low < minPow) {
                    minPow = low;
                    count = 0;
                }
                if (low == minPow) {
                    count++;
                }
                long cur = 1L * a * ((count <= k) ? 2 : 1) * (j - i + 1);
                res = Math.max(res, cur);
            }
        }
        return res;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}