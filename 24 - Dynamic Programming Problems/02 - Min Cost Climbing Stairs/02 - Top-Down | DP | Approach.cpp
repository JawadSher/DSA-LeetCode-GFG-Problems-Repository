class Solution {
public:
    // Function to recursively calculate the minimum cost to climb stairs starting from index `i`
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        // Base case 1: If we are at the first step, the cost is simply the cost of step 0
        if (i == 0) return cost[0];
        // Base case 2: If we are at the second step, the cost is simply the cost of step 1
        if (i == 1) return cost[1];

        // Step 3: If the result for this step is already computed (memoized), return it
        if (dp[i] != -1) return dp[i];

        // Step 2: Calculate the minimum cost for the current step
        // Add the cost at the current step to the minimum of:
        //   - the cost of taking 1 step back
        //   - the cost of taking 2 steps back
        dp[i] = cost[i] + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));

        // Return the memoized result
        return dp[i];
    }

    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        // Step 1: Create a memoization array `dp` initialized with -1
        // The size of `dp` is `cost.size() + 1` to handle the maximum index
        vector<int> dp(cost.size() + 1, -1);

        // Start from the last two possible steps to reach the top and return the minimum
        return min(solve(cost, cost.size() - 1, dp), solve(cost, cost.size() - 2, dp));
    }
};
