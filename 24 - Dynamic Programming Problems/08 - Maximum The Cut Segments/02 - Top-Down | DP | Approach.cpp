class Solution
{
    public:
    // Recursive function with memoization to calculate the maximum number of cuts
    int solve(int n, int x, int y, int z, vector<int>& dp){
        // Base case: If the length is exactly 0, no further cuts are needed
        if(n == 0) return 0;
        // Base case: If the length becomes negative, this is an invalid case
        if(n < 0) return INT_MIN;

        // If the result for the current length `n` is already computed, return it
        if(dp[n] != -1) return dp[n];

        // Try cutting a segment of length x and recursively calculate the cuts
        int a = solve(n-x, x, y, z, dp) + 1;
        // Try cutting a segment of length y and recursively calculate the cuts
        int b = solve(n-y, x, y, z, dp) + 1;
        // Try cutting a segment of length z and recursively calculate the cuts
        int c = solve(n-z, x, y, z, dp) + 1;

        // Store the result in the dp array for future use
        dp[n] = max(a, max(b, c));

        // Return the computed result for the current length `n`
        return dp[n];
    }

    // Function to find the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Create a dp array initialized with -1 to indicate uncomputed states
        vector<int> dp(n+1, -1);

        // Call the recursive function with memoization to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z, dp);

        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;

        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
