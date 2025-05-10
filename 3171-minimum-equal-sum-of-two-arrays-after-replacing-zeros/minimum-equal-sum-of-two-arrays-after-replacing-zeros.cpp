class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int len = max(n, m);
        long long sumA = 0;
        long sumB = 0;
        int zeroA =0;
        int zeroB =0;
        
        for (int i = 0; i < len; ++i) {
            if (i < n) {
                sumA += a[i];
                if (a[i] == 0) 
                    ++zeroA;
            }
            if (i < m) {
                sumB += b[i];
                if (b[i] == 0) 
                    ++zeroB;
            }
        }
        long long newSumA= sumA + zeroA;
        long long newSumB= sumB + zeroB;

        if (newSumA >newSumB && zeroB==0) 
            return -1;
        if (newSumB >newSumA && zeroA==0) 
            return -1;
        return max(newSumA, newSumB);
    }
};