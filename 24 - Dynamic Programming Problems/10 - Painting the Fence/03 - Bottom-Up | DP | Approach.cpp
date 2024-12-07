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
        // Initialize a dynamic programming (DP) array to store the number of ways to paint i posts
        // dp[i] will store the number of ways to paint i posts
        vector<int> dp(n+1, -1);
        
        // Base case: For 1 post, there are k ways to paint it using k colors
        dp[1] = k;
        
        // Base case: For 2 posts, there are k * k ways to paint them
        // The first post can be painted with any of the k colors, and the second post can be painted with any of the k colors
        dp[2] = add(k, multi(k, k-1));
        
        // Fill the DP array iteratively for posts from 3 to n
        // Use the recurrence relation:
        // dp[i] = (dp[i-1] * (k-1)) + (dp[i-2] * (k-1))
        for(int i = 3; i <= n; i++){
            // Calculate the number of ways to paint i posts:
            // - The first part (dp[i-1] * (k-1)) represents the case where the i-th post is painted with a different color than the (i-1)-th post
            // - The second part (dp[i-2] * (k-1)) represents the case where the i-th post is painted with a different color than the (i-1)-th post
            dp[i] = add(multi(dp[i-2], k-1), multi(dp[i-1], k-1));
        }
        
        // Return the result for the nth post
        return dp[n];
    }
    
    // Main function to compute the number of ways to paint the fence
    int countWays(int n, int k) {
        // Call the solve function to compute the result
        return solve(n, k);
    }
};
