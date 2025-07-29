class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }


    // int coinChange(vector<int>& coins, int amount) {

    //     // vector<int> dp(amount+1,-1);
    //     // int result = solveRec(coins, amount,dp);

    //     // if(result== INT_MAX)  return -1;
    //     // return result;
    //     return solveTab(coins,amount);

    // }

    //tabulation
    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    // memoization

    int solveRec(vector<int>& coins, int amount,vector<int>& dp){
        if(amount == 0)
            return 0;
        if(amount < 0)
            return INT_MAX;

        if(dp[amount]!=-1) return dp[amount];

        int mini = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int ans = solveRec(coins, amount - coins[i],dp);
            if(ans != INT_MAX){
                mini = min(mini, 1 + ans);
            }
        }
        dp[amount]=mini;
        return mini;
    }
};
