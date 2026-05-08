import java.util.*;
class Solution {
    static final int MAXV = 1000001;
    static int[] spf = buildSPF();
    static int[] buildSPF() {
        int[] spf = new int[MAXV];
        for(int i = 0; i < MAXV; i++) {
            spf[i] = i;
        }
        for(int i = 2; i * i < MAXV; i++) {
            if(spf[i] == i) {
                for(int j = i * i; j < MAXV; j += i) {
                    if(spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        return spf;
    }
    boolean isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }
    List<Integer> getPrimeFactors(int x) {
        List<Integer> factors = new ArrayList<>();
        while(x > 1) {
            int p = spf[x];
            factors.add(p);
            while(x % p == 0) {
                x /= p;
            }
        }
        return factors;
    }
    public int minJumps(int[] nums) {
        int n = nums.length;
        Map<Integer, List<Integer>> primeToIndices = new HashMap<>();
        for(int i = 0; i < n; i++) {
            List<Integer> factors = getPrimeFactors(nums[i]);
            for(int p : factors) {
                primeToIndices
                    .computeIfAbsent(p, k -> new ArrayList<>())
                    .add(i);
            }
        }

        Queue<Integer> q = new LinkedList<>();

        int[] dist = new int[n];
        Arrays.fill(dist, -1);

        boolean[] usedPrime = new boolean[MAXV];

        q.offer(0);
        dist[0] = 0;

        while(!q.isEmpty()) {

            int idx = q.poll();

            if(idx == n - 1) {
                return dist[idx];
            }

            // left
            if(idx - 1 >= 0 && dist[idx - 1] == -1) {

                dist[idx - 1] = dist[idx] + 1;
                q.offer(idx - 1);
            }

            // right
            if(idx + 1 < n && dist[idx + 1] == -1) {

                dist[idx + 1] = dist[idx] + 1;
                q.offer(idx + 1);
            }

            int val = nums[idx];

            // teleport only if current value is PRIME
            if(isPrime(val) && !usedPrime[val]) {

                usedPrime[val] = true;

                List<Integer> nextIndices = primeToIndices.get(val);

                if(nextIndices != null) {

                    for(int nextIdx : nextIndices) {

                        if(dist[nextIdx] == -1) {

                            dist[nextIdx] = dist[idx] + 1;
                            q.offer(nextIdx);
                        }
                    }
                }
            }
        }

        return -1;
    }
}