class Solution {
public:
    // Function to solve the coin change problem using bottom-up dynamic programming
    int solve(vector<int>& coins, int x) {
        // Create a dp array where dp[i] represents the minimum number of coins needed to make up amount i
        vector<int> dp(x + 1, INT_MAX);

        // Base case: 0 coins are needed to make up amount 0
        dp[0] = 0;

        // Iterate over each amount from 1 to x
        for(int i = 1; i <= x; i++) {
            // Check each coin to see if it can contribute to the current amount
            for(int j = 0; j < coins.size(); j++) {
                // If the current coin can be used (i - coins[j] >= 0) 
                // and the subproblem dp[i - coins[j]] has a valid solution (not INT_MAX)
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    // Update dp[i] to the minimum of its current value and the result of using this coin
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        // If the amount x cannot be formed with the given coins, return -1
        if(dp[x] == INT_MAX) return -1;

        // Otherwise, return the minimum number of coins needed to make up amount x
        return dp[x];
    }

    // Main function to find the minimum number of coins to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
        // Use the bottom-up approach to solve the problem
        return solve(coins, amount);
    }
};
