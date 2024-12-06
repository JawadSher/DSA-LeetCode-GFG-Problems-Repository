class Solution {
public:
    // Recursive function to solve the coin change problem
    int solveRecursive(vector<int>& coins, int x) {
        // Base case: If the remaining amount is 0, no more coins are needed
        if(x == 0) return 0;

        // Base case: If the remaining amount is negative, return an invalid result
        if(x < 0) return INT_MAX;

        // Initialize the minimum number of coins needed to a large value
        int mini = INT_MAX;

        // Iterate over each coin in the list
        for(int i = 0; i < coins.size(); i++) {
            // Recursive call: Try using the current coin and solve for the remaining amount
            int ans = solveRecursive(coins, x - coins[i]);

            // If the recursive result is valid, update the minimum number of coins
            if(ans != INT_MAX) 
                mini = min(mini, 1 + ans); // Add 1 to include the current coin
        }

        // Return the minimum number of coins required to make up the amount x
        return mini;
    }

    // Main function to find the minimum number of coins to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
        // Call the recursive function to compute the result
        int ans = solveRecursive(coins, amount);

        // If no valid combination of coins is found, return -1
        if(ans == INT_MAX) return -1;

        // Otherwise, return the computed result
        return ans;
    }
};
