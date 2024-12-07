class Solution {
  public:
    // Helper function to calculate derangements recursively with memoization
    int solve(int n, vector<int>& dp) {
        // Base case: For n = 1, no valid dearrangements exist
        if(n == 1) return 0;

        // Base case: For n = 2, exactly one valid dearrangement exists
        if(n == 2) return 1;

        // If the result for this value of n has already been computed, return it
        if(dp[n] != -1) return dp[n];

        // Use the recursive relation:
        // D(n) = (n-1) * (D(n-1) + D(n-2))
        dp[n] = (n-1) * (solve(n-1, dp) + solve(n-2, dp));

        // Return the computed result
        return dp[n];
    }

    // Main function to compute derangements of n items
    int countDer(int n) {
        // Create a memoization array initialized with -1
        // dp[i] will store the number of derangements for i items
        vector<int> dp(n+1, -1);

        // Call the helper function to compute the result
        return solve(n, dp);
    }
};
