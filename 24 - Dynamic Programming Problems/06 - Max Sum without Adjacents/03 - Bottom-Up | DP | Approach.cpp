// User function template for C++
class Solution {
  public:
    // Function to find the maximum sum without adjacent elements using bottom-up DP
    int solve(vector<int>& arr){
        int n = arr.size();  // Get the size of the input array
        
        // Initialize the dp array where dp[i] will store the maximum sum up to index i
        vector<int> dp(n, 0);
        
        // Base case: The first element is the only element we can take in the beginning
        dp[0] = arr[0];
        
        // Iterate through the array from the second element to the last element
        for(int i = 1; i < n; i++){
            // Option 1: Include the current element arr[i], 
            // we add arr[i] and the maximum sum excluding the previous element (dp[i-2])
            int include = dp[i-2] + arr[i];
            
            // Option 2: Exclude the current element arr[i], 
            // we just take the maximum sum until the previous element (dp[i-1])
            int exclude = dp[i-1];
            
            // Store the maximum sum at index i
            dp[i] = max(include, exclude);
        }
        
        // The last element in dp stores the maximum sum without adjacent elements
        return dp[n-1];
    }
    
    // Main function to find the maximum sum
    int findMaxSum(vector<int>& arr) {
        
        // Call the solve function and get the result
        int sum = solve(arr);
        
        // Return the maximum sum
        return sum;
    }
};
