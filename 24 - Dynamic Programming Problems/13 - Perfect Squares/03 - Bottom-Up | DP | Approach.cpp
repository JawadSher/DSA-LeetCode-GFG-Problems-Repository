class Solution {
public:
    // Function to calculate the minimum number of perfect squares
    int solve(int n){
        // Create a DP array of size n+1 initialized with INT_MAX (a large value representing infinity)
        // dp[i] will store the minimum number of perfect squares required to sum to i.
        vector<int> dp(n+1, INT_MAX);

        // Base case: dp[0] = 0, as no squares are needed to sum to 0.
        dp[0] = 0;

        // Iterate over all values of i from 1 to n
        for(int i = 1; i <= n; i++){
            // For each i, check all perfect squares (j * j) that are less than or equal to i
            for(int j = 1; j * j <= i; j++){
                int SQRT = j * j;  // Square of j

                // If subtracting SQRT from i doesn't make it negative, update dp[i]
                // Take the minimum of the current value of dp[i] and dp[i - SQRT] + 1
                // (the +1 is because we are using one more square, i.e., SQRT)
                dp[i] = min(dp[i], dp[i - SQRT] + 1);
            }
        }

        // Return the minimum number of perfect squares for the number n
        return dp[n];
    }

    // Main function to return the minimum number of perfect squares for n
    int numSquares(int n) {
        return solve(n);  // Call the solve function to calculate the result
    }
};
