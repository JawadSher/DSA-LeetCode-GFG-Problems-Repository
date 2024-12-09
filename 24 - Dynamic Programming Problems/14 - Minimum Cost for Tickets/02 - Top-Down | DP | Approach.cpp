class Solution {
public:
    // Recursive function to calculate the minimum cost using memoization
    int solve(vector<int>& days, vector<int>& costs, int n, int index, vector<int>& dp) {
        // Base case: if the index is out of bounds, no cost is required
        if (index >= n) 
            return 0;

        // If the result is already computed for the current index, return it (memoization)
        if (dp[index] != -1) 
            return dp[index];

        // **Cost for a 1-day pass**:
        // Move to the next day and add the cost of a 1-day pass
        int cost1 = solve(days, costs, n, index + 1, dp) + costs[0];
        
        // **Cost for a 7-day pass**:
        // Find the first day not covered by the 7-day pass (days[index] + 7)
        int i; 
        for (i = index; i < n && days[i] < days[index] + 7; i++);
        // Recursively calculate the cost from that day and add the cost of a 7-day pass
        int cost7 = solve(days, costs, n, i, dp) + costs[1];
        
        // **Cost for a 30-day pass**:
        // Find the first day not covered by the 30-day pass (days[index] + 30)
        for (i = index; i < n && days[i] < days[index] + 30; i++);
        // Recursively calculate the cost from that day and add the cost of a 30-day pass
        int cost30 = solve(days, costs, n, i, dp) + costs[2];

        // Store the minimum cost for the current index in the memoization table
        dp[index] = min(cost1, min(cost7, cost30));

        // Return the computed minimum cost for the current index
        return dp[index];
    }

    // Main function to calculate the minimum cost of traveling
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Create a memoization table initialized to -1
        vector<int> dp(days.size() + 1, -1);
        // Start calculating from the first day
        return solve(days, costs, days.size(), 0, dp);
    }
};
