class Solution {
public:
    // Function to calculate the minimum money required to guarantee a win
    // for the range [1, n]. We use dynamic programming to solve the problem.
    int solve(int n) {
        // Create a 2D DP table (n+2 x n+2) initialized to 0.
        // dp[start][end] will store the minimum money required to guarantee a win in the range [start, end].
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Start filling the DP table from the bottom-up approach.
        // We iterate from n down to 1 for the 'start' index.
        for (int start = n; start >= 1; start--) {
            // For each 'start', we iterate from 'start' to 'n' for the 'end' index.
            for (int end = start; end <= n; end++) {
                // If start == end, it means there's only one number in the range,
                // so no money is needed (continue to the next iteration).
                if (start == end) continue;
                else {
                    // Initialize 'maxi' to a very large value to store the minimum money.
                    int maxi = INT_MAX;

                    // Try every number 'i' in the range [start, end] as a possible guess.
                    for (int i = start; i <= end; i++) {
                        // Calculate the cost of choosing 'i':
                        // - 'i' is the cost of guessing 'i'.
                        // - We then look at the two subranges: [start, i-1] and [i+1, end].
                        // The worst-case scenario is the maximum of the two subranges, 
                        // and we want to minimize the maximum cost.
                        maxi = min(maxi, i + max(dp[start][i - 1], dp[i + 1][end]));
                    }

                    // Store the result in the DP table for the range [start, end].
                    dp[start][end] = maxi;
                }
            }
        }

        // The result for the full range [1, n] is stored in dp[1][n].
        return dp[1][n];
    }
    
    // Wrapper function to start the process with the range [1, n].
    int getMoneyAmount(int n) {
        // Call the solve function with the full range [1, n].
        return solve(n);
    }
};
