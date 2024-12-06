class Solution {
public:
    // Function to calculate the number of ways to climb `n` stairs using dynamic programming
    int climbStairs(int n) {
        // Create a dp array where dp[i] will store the number of ways to reach the ith step
        vector<int> dp(n+1, 0);

        // Base case: There's one way to reach the 0th step (by staying at the start)
        dp[0] = 1;

        // Base case: If n >= 1, there's one way to reach the 1st step (by taking a single step)
        if(n >= 1) dp[1] = 1;

        // Iterate from the 2nd step to the nth step
        for(int i = 2; i <= n; i++) {
            // The number of ways to reach step i is the sum of:
            //   - the number of ways to reach step i-1 (taking 1 step)
            //   - the number of ways to reach step i-2 (taking 2 steps)
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Return the number of ways to reach the nth step
        return dp[n];
    }
};
