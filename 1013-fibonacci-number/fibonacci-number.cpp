class Solution {
 public:
  int fib(int n) {
    if (n <=1)
      return n;

    vector<int> dp{0, 0, 1}; // we store the value of latest 3 fibonnacis

    for (int i = 2; i <= n; ++i) {
      dp[0] = dp[1];
      dp[1] = dp[2];
      dp[2] = dp[0] + dp[1];
    }

    return dp.back();
  }
};