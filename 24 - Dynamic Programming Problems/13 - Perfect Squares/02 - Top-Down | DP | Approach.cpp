class Solution {
public:
    // Recursive function to calculate the minimum number of perfect squares 
    // using memoization to avoid redundant calculations
    int solve(int n, vector<int> &dp){
        // Base case: dp[0] = 0, as 0 can be represented by 0 perfect squares
        dp[0] = 0;

        // If the result for the current value of n has already been computed, return it
        if(dp[n] != -1) return dp[n];

        // Initialize ans to the maximum possible value, which is n (since n can be represented
        // by the sum of n 1's (1^2), which is the worst case)
        int ans = n;

        // Try all perfect squares less than or equal to n
        for(int i = 1; i * i <= n; i++){
            // The current square number
            int SQRT = i * i;

            // Recursively calculate the minimum squares needed for the remaining value (n - SQRT)
            ans = min(ans, solve(n - SQRT, dp) + 1); // Add 1 for the current perfect square used
        }

        // Store the result for the current value of n to avoid recalculating it
        dp[n] = ans;

        // Return the minimum number of perfect squares for the current value of n
        return dp[n];
    }

    // Main function to calculate the minimum number of perfect squares for the input n
    int numSquares(int n) {
        // Create a DP array of size n+1 initialized with -1 (indicating that no value has been computed yet)
        vector<int> dp(n+1, -1);

        // Call the recursive function with memoization to compute the result
        return solve(n, dp);
    }
};
