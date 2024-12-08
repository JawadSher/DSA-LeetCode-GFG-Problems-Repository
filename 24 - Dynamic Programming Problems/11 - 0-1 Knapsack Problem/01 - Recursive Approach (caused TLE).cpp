class Solution {
  public:
    // Recursive function to solve the knapsack problem
    int solve(int capacity, vector<int> &value, vector<int> &weight, int index){
        
        // Base case: If we are at the first item (index 0)
        if(index == 0){
            // If the weight of the first item is less than or equal to the remaining capacity, return its value
            if(weight[0] <= capacity) return value[0];
            // Otherwise, return 0 because we cannot include this item in the knapsack
            else return 0;
        }
        
        // Variable to store the value if we include the current item
        int include = 0;
        // Check if the current item's weight is less than or equal to the remaining capacity
        if(weight[index] <= capacity) {
            // If we include the current item, reduce the capacity by the item's weight, and add its value
            // Recursively solve the remaining problem (remaining capacity and items)
            include = solve(capacity - weight[index], value, weight, index-1) + value[index];
        }
        
        // Variable to store the value if we exclude the current item
        int exclude = 0;
        // If we exclude the current item, just solve the problem with the remaining items and the same capacity
        exclude = solve(capacity, value, weight, index-1);
        
        // Return the maximum of the two values: including the item or excluding the item
        return max(include, exclude);
    }
    
    // Function to initialize and call the recursive function to solve the knapsack problem
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        int n = wt.size();  // Get the number of items
        // Start the recursive function with the full capacity and all items (index n-1)
        return solve(capacity, val, wt, n-1);
    }
};
