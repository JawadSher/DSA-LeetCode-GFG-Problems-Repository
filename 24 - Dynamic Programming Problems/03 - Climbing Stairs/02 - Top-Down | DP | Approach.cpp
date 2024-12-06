class Solution {
public:
    // Function to calculate the number of ways to reach the top of the stairs using memoization
    int solve(int n, vector<int>& dp) {
        // Base case: If we are at the first step (n == 0), there's exactly one way to reach the top
        if(n == 0) return 1;

        // Base case: If `n` is negative, return 0 as it's an invalid path
        if(n < 0) return 0;

        // If the value for this step (`n`) is already calculated and stored in `dp`, return it (Memoization)
        if(dp[n] != -1) return dp[n];

        // Recursively calculate the number of ways to reach the top from the current step
        // We can reach step `n` by either coming from step `n-1` or step `n-2`
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        // Return the calculated result for step `n`
        return dp[n];
    }

    // Main function to start the process of calculating the number of ways to climb to the top
    int climbStairs(int n) {
        // Initialize a memoization array `dp` of size `n+1`, with all values set to -1
        // `dp[i]` will store the number of ways to reach step `i`
        vector<int> dp(n + 1, -1);

        // Call the recursive function to calculate the number of ways to reach the top
        return solve(n, dp);
    }
};
