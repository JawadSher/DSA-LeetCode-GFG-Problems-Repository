// User function template for C++
class Solution {
  public:
    // Recursive function to solve the problem with memoization
    int solve(vector<int>& arr, int i, int n, vector<int>& dp){
        // Base case: If the index i is out of bounds, return 0 (no more elements to pick)
        if(i >= arr.size()) return 0;
        
        // If the result for the current index i is already computed, return it from the memoization table
        if(dp[i] != -1) return dp[i];
        
        // Option 1: Include the current element arr[i] in the sum, 
        // then move 2 steps forward (i+2) to ensure no adjacent elements are selected
        int include = solve(arr, i+2, n, dp) + arr[i];
        
        // Option 2: Exclude the current element arr[i] from the sum, 
        // then move 1 step forward (i+1) to check the next element
        int exclude = solve(arr, i+1, n, dp) + 0; // Adding 0 doesn't affect the result
        
        // Store the maximum sum of including or excluding the current element in the dp array
        dp[i] = max(include, exclude);
        
        // Return the computed result for the current index i
        return dp[i];
    }

    // Function to find the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size(); // Get the size of the input array
        
        // Initialize the memoization array dp with -1 to indicate uncomputed results
        // dp[i] will store the maximum sum starting from index i
        vector<int> dp(n+1, -1);
        
        // Start the recursive process from index 0
        int sum = solve(arr, 0, n-1, dp);
        
        // Return the maximum sum obtained
        return sum;
    }
};
