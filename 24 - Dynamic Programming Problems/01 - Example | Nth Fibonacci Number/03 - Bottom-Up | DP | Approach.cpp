class Solution {
  public:
    int nthFibonacci(int n) {
        // Create a vector to store Fibonacci numbers up to the nth term.
        // The size is n+1 because we want to include the 0th term.
        vector<int> dp(n + 1);

        // Base cases of the Fibonacci sequence:
        dp[0] = 0; // F(0) = 0
        dp[1] = 1; // F(1) = 1

        // Use a loop to calculate Fibonacci numbers from F(2) to F(n).
        for (int i = 2; i <= n; i++) {
            // The nth Fibonacci number is the sum of the two preceding numbers:
            // F(i) = F(i-1) + F(i-2)
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the nth Fibonacci number.
        return dp[n];
    }
};
