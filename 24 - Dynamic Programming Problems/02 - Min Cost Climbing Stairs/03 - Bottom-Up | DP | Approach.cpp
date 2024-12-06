class Solution {
public:
    // Function to calculate the minimum cost to climb the stairs using tabulation
    int solve(vector<int>& cost, int n) {
        // Step 1: Create a DP table `dp` of size `n+1` to store the minimum cost at each step
        vector<int> dp(n + 1);

        // Step 2: Initialize the base cases
        // If starting at the first step, the cost is simply `cost[0]`
        dp[0] = cost[0];
        // If starting at the second step, the cost is simply `cost[1]`
        dp[1] = cost[1];

        // Step 3: Fill the DP table for steps from 2 to n-1
        for (int i = 2; i < n; i++) {
            // The minimum cost to reach step `i` is the cost at step `i` plus
            // the minimum cost to reach either of the two previous steps
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Step 4: The minimum cost to reach the top is the minimum of the last two steps
        return min(dp[n - 1], dp[n - 2]);
    }

    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        // Call the `solve` function with the cost array and its size
        return solve(cost, cost.size());
    }
};
