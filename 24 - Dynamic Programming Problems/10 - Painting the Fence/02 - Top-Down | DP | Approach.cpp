class Solution {
  public:
    // Helper function to add two integers
    int add(int a, int b){
        return (a + b);  // Returns the sum of a and b
    }
    
    // Helper function to multiply two integers
    int multi(int a, int b){
        return (a * b);  // Returns the product of a and b
    }
    
    // Recursive function with memoization to calculate the number of ways to paint the fence
    // n: number of posts, k: number of colors, dp: memoization array
    int solve(int n, int k, vector<int>& dp){
        // Base case 1: If there is only one post, there are k ways to paint it with k colors
        if(n == 1) return k;

        // Base case 2: If there are two posts, there are k * k ways to paint them
        if(n == 2) return add(k, multi(k, k-1));
        
        // If the result for the current number of posts is already computed (cached), return it
        if(dp[n] != -1) return dp[n];
        
        // Recursive case: Use the recurrence relation to calculate the number of ways to paint n posts
        // D(n) = (D(n-1) * (k-1)) + (D(n-2) * (k-1))
        dp[n] = add(multi(solve(n-2, k, dp), k-1), multi(solve(n-1, k, dp), k-1));
        
        // Return the result for the current number of posts
        return dp[n];
    }

    // Main function to initialize the DP array and call the solve function
    int countWays(int n, int k) {
        // Create a memoization array to store the result for each number of posts (initially -1)
        vector<int> dp(n+1, -1);
        
        // Call the solve function to calculate and return the result
        return solve(n, k, dp);
    }
};
