class Solution {
  public:
    // Function to calculate derangements using tabulation (iterative dynamic programming)
    int solve(int n) {
        // Create a DP array to store the number of derangements for each value from 0 to n
        vector<int> dp(n + 1, -1);

        // Base cases:
        // For n = 1, there are no valid derangements
        dp[1] = 0;

        // For n = 2, there is exactly one valid derangement
        dp[2] = 1;

        // Fill the DP array iteratively using the relation:
        // D(i) = (i-1) * (D(i-1) + D(i-2))
        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        // Return the result for n
        return dp[n];
    }

    // Main function to calculate derangements
    int countDer(int n) {
        // Delegate the computation to the solve function
        return solve(n);
    }
};
