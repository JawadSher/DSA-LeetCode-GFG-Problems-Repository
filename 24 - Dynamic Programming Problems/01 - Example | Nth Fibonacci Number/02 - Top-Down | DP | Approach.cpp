class Solution {
  public:
    int nthFibonacci(int n) {
        // Create a vector to store computed Fibonacci values, initialized to -1.
        // This is used for memoization to avoid redundant calculations.
        vector<int> dp(n + 1, -1);

        // Base case: If n is 0 or 1, the Fibonacci value is n itself.
        if (n == 0 || n == 1) 
            return n;

        // Check if the value for the nth Fibonacci number is already computed.
        // If dp[n] is not -1, it means the value is already stored in the memoization table.
        if (dp[n] != -1) 
            return dp[n];

        // Recursive case: Compute the nth Fibonacci number by summing the (n-1)th and (n-2)th numbers.
        dp[n] = nthFibonacci(n - 1) + nthFibonacci(n - 2);

        // Store the computed value in dp[n] and return it.
        return dp[n];
    }
};
