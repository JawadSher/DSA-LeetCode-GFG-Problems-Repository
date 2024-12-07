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
        // Base case: When there is only 1 post, there are k ways to paint it with k colors
        if(n == 1) return k;

        // Base case: When there are 2 posts, there are k * k ways to paint them
        // The first post can be painted with any of the k colors, and the second post can be painted with any of the k colors
        if(n == 2) return add(k, multi(k, k-1));
        
        // Initializing the values for the first two posts (dp[1] and dp[2])
        // prev2 represents dp[i-2] (previous to the current value)
        // prev1 represents dp[i-1] (the previous value)
        int prev2 = k;  // Ways to paint the first post
        int prev1 = add(k, multi(k, k-1));  // Ways to paint two posts

        // Iteratively calculate the number of ways to paint posts from 3 to n
        for(int i = 3; i <= n; i++){
            // Calculate the number of ways to paint the i-th post:
            // - The first part (multi(prev2, k-1)) represents the case where the i-th post is painted with a different color than the (i-1)-th post
            // - The second part (multi(prev1, k-1)) represents the case where the i-th post is painted with a different color than the (i-1)-th post
            int current = add(multi(prev2, k-1), multi(prev1, k-1));
            
            // Move the values forward for the next iteration
            prev2 = prev1;  // Update prev2 to the value of prev1
            prev1 = current;  // Update prev1 to the new current value
        }

        // Return the result for the nth post, which is stored in prev1
        return prev1;
    }

    // Main function to compute the number of ways to paint the fence
    int countWays(int n, int k) {
        // Call the solve function to compute the result
        return solve(n, k);
    }
};
