// Apporach 1 : Left to Right Approach
class Solution {
  public:
    // Recursive function to solve the problem
    int solve(vector<int>& arr, int i, int n){
        // Base case: If the index exceeds the size of the array, return 0 (no more elements to pick)
        if(i > n) return 0;

        // Base case: If we reach the last element, return its value
        if(i == n) return arr[i];
        
        // Option 1: Include the current element arr[i] and move two steps forward (i+2)
        int include = solve(arr, i+2, n) + arr[i];
        
        // Option 2: Exclude the current element arr[i] and move one step forward (i+1)
        int exclude = solve(arr, i+1, n) + 0; // Adding 0 doesn't affect the result
        
        // Return the maximum sum between including and excluding the current element
        return max(include, exclude);
    }
    
    // Function to find the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        
        // Start the recursive process from index 0
        int sum = solve(arr, 0, n-1);
        
        return sum;  // Return the maximum sum obtained
    }
};

// Approach 2 : Right to Left Approach
class Solution {
  public:
    // Recursive function to solve the problem
    int solve(vector<int>& arr, int n){
        // Base case: If n is negative, we return 0 (no more elements to pick)
        if(n < 0) return 0;

        // Base case: If n is 0, return the first element
        if(n == 0) return arr[0];
        
        // Option 1: Include the current element arr[n] and move two steps back (n-2)
        int include = solve(arr, n-2) + arr[n];
        
        // Option 2: Exclude the current element arr[n] and move one step back (n-1)
        int exclude = solve(arr, n-1) + 0; // Adding 0 doesn't affect the result
        
        // Return the maximum sum between including and excluding the current element
        return max(include, exclude);
    }
    
    // Function to find the maximum sum without adjacent elements
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();  // Get the size of the array
        
        // Start the recursive process from the last index (n-1)
        int sum = solve(arr, n-1);
        
        return sum;  // Return the maximum sum obtained
    }
};


