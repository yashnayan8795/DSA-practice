class Solution {
    public boolean isGood(int[] nums) {
        int maxi =0;
        for(int x: nums){
            maxi = Math.max(maxi, x);
        }
        if(nums.length != maxi +1){
            return false;
        }

        int[] freq = new int[maxi + 1];
        for(int x: nums){
            if(x<1 || x > maxi) return false;

            freq[x]++;
        }
        for (int i = 1; i < maxi; i++) {

            if (freq[i] != 1) return false;
        }

        return freq[maxi] ==2;
    }
}