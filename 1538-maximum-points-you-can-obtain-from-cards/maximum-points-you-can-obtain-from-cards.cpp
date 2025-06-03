class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0;

        int n= cardPoints.size();
        for(int i=0; i< k ;i++){
            lsum += cardPoints[i];

        }
        int maxsum=lsum;
        // int rindex =k-1;

        for (int j = 0; j < k; j++) {
            lsum -= cardPoints[k - 1 - j];         
            rsum += cardPoints[n - 1 - j];         
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};