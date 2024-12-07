// User function template for C++
class Solution {
  public:
    // Function to find the maximum sum without adjacent elements using space-optimized DP
    int solve(vector<int>& arr){
        int n = arr.size();  // Get the size of the input array
        
        // Initialize the two variables to store the previous two results
        int prev2 = 0;  // prev2 stores the maximum sum up to index i-2
        int prev1 = arr[0];  // prev1 stores the maximum sum up to index i-1 (initially, it's the first element)
        
        // Iterate through the array starting from the second element
        for(int i = 1; i < n; i++){
            // Option 1: Include the current element arr[i]
            int include = prev2 + arr[i];
            
            // Option 2: Exclude the current element arr[i]
            int exclude = prev1;  // We just carry forward prev1 as it's the maximum sum up to the previous index
            
            // The result for the current index i is the maximum of include and exclude options
            int ans = max(include, exclude);
            
            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;  // prev2 moves to prev1
            prev1 = ans;    // prev1 stores the maximum sum for the current index
        }
        
        // The final answer is stored in prev1 (which is the maximum sum for the entire array)
        return prev1;
    }
    
    // Main function to find the maximum sum
    int findMaxSum(vector<int>& arr) {
        
        // Call the solve function and get the result
        int sum = solve(arr);
        
        // Return the maximum sum
        return sum;
    }
};
