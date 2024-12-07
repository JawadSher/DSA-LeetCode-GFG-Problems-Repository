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
    
    // Function to calculate the number of ways to paint the fence with n posts and k colors
    int solve(int n, int k){
        // Base case: If there is only one post, there are k ways to paint it with k colors
        if(n == 1) return k;
        
        // Base case: If there are two posts, there are k * k ways to paint them
        // (each post can be painted with any of the k colors)
        if(n == 2) return add(k, multi(k, k-1));
        
        // Recurrence relation:
        // The number of ways to paint n posts is calculated as:
        // dp[n] = (dp[n-1] * (k-1)) + (dp[n-2] * (k-1))
        // This is based on the fact that we can paint the nth post in (k-1) ways to avoid
        // repeating the color of the (n-1)th post.
        int ans = add(multi(solve(n-2, k), k-1), multi(solve(n-1, k), k-1));
        
        // Return the calculated number of ways to paint n posts
        return ans;
    }

    // Main function to initiate the calculation and return the result
    int countWays(int n, int k) {
        return solve(n, k);  // Call the solve function to calculate the result
    }
};
