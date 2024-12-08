class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Number of items
        
        // DP table to store the maximum value for each subproblem (capacity, number of items)
        // dp[i][w] will store the maximum value with the first i items and a knapsack capacity of w
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        
        // Initialize the first row of the DP table (only for the first item)
        // We fill the DP table by checking if the current item can be included in the knapsack
        for(int w = weight[0]; w <= capacity; w++){
            dp[0][w] = (weight[0] <= w) ? value[0] : 0;  // If the first item's weight is less than or equal to the capacity, include its value
        }
        
        // Fill the rest of the DP table for all the other items (i > 0)
        for(int i = 1; i < n; i++){
            for(int w = 0; w <= capacity; w++){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // If the current item can fit in the knapsack
                    include = value[i] + dp[i-1][w - weight[i]];  // Add its value and reduce the capacity accordingly
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = dp[i-1][w];  // Simply carry forward the value from the previous row, without including the item
                
                // Store the maximum value of including or excluding the current item
                dp[i][w] = max(include, exclude);
            }
        }
        
        // The answer will be in dp[n-1][capacity], which contains the maximum value with all items and the given capacity
        return dp[n - 1][capacity];
    }
    
    // Wrapper function that calls the solve function
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
