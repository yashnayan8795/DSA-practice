class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum=n*(n+1)/2;
        int dcount= n/m;
        int dsum= m*dcount*(dcount+1)/2;

        return totalSum-2* dsum;
    }
};