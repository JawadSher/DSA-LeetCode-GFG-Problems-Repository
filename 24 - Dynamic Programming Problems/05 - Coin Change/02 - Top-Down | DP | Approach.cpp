class Solution {
public:
    // Helper function to solve the coin change problem using recursion with memoization
    int solve(vector<int>& coins, int x, vector<int>& dp) {
        // Base case: If the target amount is 0, no coins are needed
        if(x == 0) return 0;

        // Base case: If the target amount is negative, return an invalid result
        if(x < 0) return INT_MAX;

        // If the result for the current amount is already computed, return it
        if(dp[x] != -1) return dp[x];

        // Initialize the minimum number of coins required to a large value
        int mini = INT_MAX;

        // Iterate through each coin
        for(int i = 0; i < coins.size(); i++) {
            // Recursive call: Try using the current coin and solve for the remaining amount
            int ans = solve(coins, x - coins[i], dp);

            // If the recursive result is valid, update the minimum number of coins
            if(ans != INT_MAX) 
                mini = min(mini, 1 + ans); // Add 1 to include the current coin
        }

        // Store the computed result in the memoization array
        dp[x] = mini;

        // Return the computed result
        return mini;
    }

    // Main function to find the minimum number of coins needed to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
        // Create a memoization array initialized with -1
        vector<int> dp(amount + 1, -1);

        // Call the recursive helper function with memoization
        int ans = solve(coins, amount, dp);

        // If no valid combination of coins can form the amount, return -1
        if(ans == INT_MAX) return -1;

        // Otherwise, return the computed result
        return ans;
    }
};
