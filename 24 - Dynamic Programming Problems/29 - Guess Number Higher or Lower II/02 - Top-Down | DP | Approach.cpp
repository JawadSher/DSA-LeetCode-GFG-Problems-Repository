class Solution {
public:
    // Recursive function to calculate the minimum money required to guarantee a win
    // for the range [start, end]. We use dynamic programming to memoize the results.
    int solve(int start, int end, vector<vector<int>>& dp) {
        // Base case: If start is greater than or equal to end, no money is needed.
        if (start >= end) return 0;

        // Check if the result is already computed (memoized). If so, return it.
        if (dp[start][end] != -1) return dp[start][end];

        // Initialize maxi with a very large value to store the minimum amount of money.
        int maxi = INT_MAX;

        // Try every number i in the range [start, end] as a potential guess.
        for (int i = start; i <= end; i++) {
            // Calculate the cost of guessing i:
            // - i is the cost of guessing i.
            // - The two ranges are [start, i-1] and [i+1, end].
            // We want to minimize the worst-case scenario, so we take the maximum
            // of the two subranges and add the cost of guessing i.
            maxi = min(maxi, i + max(solve(start, i - 1, dp), solve(i + 1, end, dp)));
        }

        // Memoize the result for this range [start, end] and return the calculated value.
        return dp[start][end] = maxi;
    }

    // Function to initiate the process for the full range [1, n]
    int getMoneyAmount(int n) {
        // Create a 2D DP table to store the minimum money required for each range.
        // Initialize all values to -1 to signify that they are not computed yet.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Start solving for the range [1, n]
        return solve(1, n, dp);
    }
};
