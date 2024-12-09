class Solution {
public:
    // Function to calculate the minimum cost using dynamic programming
    long long solve(vector<int>& days, vector<int>& costs, int n) {
        // Create a DP table to store the minimum cost for each starting day
        // Initialize all values to a very large number (LLONG_MAX)
        vector<long long> dp(n + 1, LLONG_MAX);
        
        // Base case: if there are no more days to cover, the cost is 0
        dp[n] = 0;

        // Traverse the days array from the last travel day to the first
        for (int k = n - 1; k >= 0; k--) {
            // **Cost for a 1-day pass**:
            // Add the cost of a 1-day pass and move to the next day
            long long cost1 = dp[k + 1] + costs[0];
            
            // **Cost for a 7-day pass**:
            // Find the first day not covered by the 7-day pass (days[k] + 7)
            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++);
            // Add the cost of a 7-day pass and use the precomputed result from dp[i]
            long long cost7 = dp[i] + costs[1];
            
            // **Cost for a 30-day pass**:
            // Find the first day not covered by the 30-day pass (days[k] + 30)
            for (i = k; i < n && days[i] < days[k] + 30; i++);
            // Add the cost of a 30-day pass and use the precomputed result from dp[i]
            long long cost30 = dp[i] + costs[2];

            // Store the minimum cost for day k in the DP table
            dp[k] = min(cost1, min(cost7, cost30));
        }

        // Return the minimum cost starting from the first day
        return dp[0];
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Call the solve function with the days, costs, and number of days
        return solve(days, costs, days.size());
    }
};
