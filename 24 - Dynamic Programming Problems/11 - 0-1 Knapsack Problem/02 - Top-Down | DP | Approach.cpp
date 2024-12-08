class Solution {
  public:
    // Recursive function with memoization to solve the knapsack problem
    int solve(int capacity, vector<int> &value, vector<int> &weight, int index, vector<vector<int>>& dp){
        
        // Base case: If we are at the first item (index 0)
        if(index == 0){
            // If the weight of the first item is less than or equal to the remaining capacity, return its value
            if(weight[0] <= capacity) return value[0];
            // Otherwise, return 0 because we cannot include this item in the knapsack
            else return 0;
        }
        
        // If the solution for the current subproblem (index and capacity) has already been computed, return the result from dp table
        if(dp[index][capacity] != -1) return dp[index][capacity];
        
        // Variable to store the value if we include the current item
        int include = 0;
        // Check if the current item's weight is less than or equal to the remaining capacity
        if(weight[index] <= capacity) {
            // If we include the current item, reduce the capacity by the item's weight, and add its value
            // Recursively solve the remaining problem (remaining capacity and items)
            include = solve(capacity - weight[index], value, weight, index-1, dp) + value[index];
        }
        
        // Variable to store the value if we exclude the current item
        int exclude = 0;
        // If we exclude the current item, just solve the problem with the remaining items and the same capacity
        exclude = solve(capacity, value, weight, index-1, dp);
        
        // Store the result in the dp table and return the maximum of the two values: including or excluding the item
        dp[index][capacity] = max(include, exclude);
        
        return dp[index][capacity];
    }
    
    // Function to initialize and call the recursive function to solve the knapsack problem
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        int n = wt.size();  // Get the number of items
        
        // Create a memoization table (dp) to store solutions of subproblems
        // dp[i][j] will store the maximum value that can be obtained with the first i items and a knapsack capacity of j
        vector<vector<int>> dp(n+1, vector<int>(capacity + 1, -1));
        
        // Start the recursive function with the full capacity and all items (index n-1)
        return solve(capacity, val, wt, n-1, dp);
    }
};
