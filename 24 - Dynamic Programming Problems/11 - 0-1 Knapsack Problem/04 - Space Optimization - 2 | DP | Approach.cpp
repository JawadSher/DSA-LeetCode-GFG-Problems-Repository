class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Get the number of items
        
        // Create a 1D array `curr[]` to store the maximum value for each weight capacity from 0 to the given capacity.
        // It will store the result of the current item.
        vector<int> curr(capacity + 1, 0); 
        
        // Initialize the first row of the DP table for the first item.
        // If the weight of the first item is less than or equal to the current capacity,
        // we store its value in the `curr[]` array (otherwise 0).
        for(int w = 0; w <= capacity; w++) {
            curr[w] = (weight[0] <= w) ? value[0] : 0; // If the first item's weight <= w, include its value
        }
        
        // Process the remaining items (i from 1 to n-1)
        for(int i = 1; i < n; i++){
            // For each capacity from the given weight to 0 (iterating backwards)
            // This prevents overwriting results of the current item during the same iteration
            for(int w = capacity; w >= 0; w--){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // Check if the current item's weight can fit in the knapsack
                    include = value[i] + curr[w - weight[i]]; // Add the value of the current item and reduce the capacity
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = curr[w];  // Simply carry forward the value from the previous item (same weight)
                
                // Store the maximum value of including or excluding the current item
                curr[w] = max(include, exclude);  // The optimal solution for this capacity is the best of both cases
            }
        }
        
        // The final answer is in `curr[capacity]`, which contains the maximum value achievable with the given capacity
        return curr[capacity];
    }
    
    // Wrapper function that calls the solve function with the given capacity, values, and weights
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
