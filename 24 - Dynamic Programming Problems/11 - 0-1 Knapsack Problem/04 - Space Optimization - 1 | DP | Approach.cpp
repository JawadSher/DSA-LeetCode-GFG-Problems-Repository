class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Get the number of items
        
        // We only need two rows at a time (previous and current), so we create two 1D arrays:
        // prev[] will store the maximum values for the previous item, 
        // curr[] will store the maximum values for the current item.
        vector<int> prev(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);
        
        // Initialize the first row of the DP table for the first item.
        // If the weight of the first item is less than or equal to the current capacity,
        // we store its value in the prev[] array (otherwise 0).
        for(int w = 0; w <= capacity; w++) {
            prev[w] = (weight[0] <= w) ? value[0] : 0; // If the first item's weight <= w, include its value
        }
        
        // Process the remaining items (i from 1 to n-1)
        for(int i = 1; i < n; i++){
            // For each capacity from 0 to the given capacity
            for(int w = 0; w <= capacity; w++){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // Check if the current item's weight can fit in the knapsack
                    include = value[i] + prev[w - weight[i]]; // Add the value of the current item and reduce the capacity
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = prev[w];  // Simply carry forward the value from the previous row without including the item
                
                // Store the maximum value of including or excluding the current item
                curr[w] = max(include, exclude);
            }
            
            // After processing the current item, move curr[] to prev[] to use it in the next iteration
            prev = curr;
        }
        
        // The answer will be in curr[capacity], which contains the maximum value with all items considered
        return curr[capacity];
    }
    
    // Wrapper function that calls the solve function with the given capacity, values, and weights
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
