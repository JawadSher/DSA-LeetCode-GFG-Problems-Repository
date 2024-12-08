// Solution class for 0/1 Knapsack problem
class Solution {
  public:
    // Recursive function to solve the 0/1 Knapsack problem
    int solve(int capacity, vector<int> &value, vector<int> &weight, int index){
        // Base case: if we've considered all items, return the value of the last item
        // if it fits in the knapsack, otherwise return 0
        if(index == 0){
            if(weight[0] <= capacity) return value[0];
            else return 0;
        }
        
        // Initialize variables to store the maximum value with and without the current item
        int include = 0;
        
        // If the current item fits in the knapsack, consider including it
        if(weight[index] <= capacity) {
            // Recursively call the function with the remaining capacity and items
            include = solve(capacity - weight[index], value, weight, index-1) + value[index];
        }
        
        // Consider excluding the current item
        int exclude = solve(capacity, value, weight, index-1) + 0;
        
        // Return the maximum value between including and excluding the current item
        return max(include, exclude);
    }
    
    // Function to initialize and call the recursive solve function
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        // Get the number of items
        int n = wt.size();
        
        // Call the recursive solve function with the initial capacity and all items
        return solve(capacity, val, wt, n-1);
    }
};
