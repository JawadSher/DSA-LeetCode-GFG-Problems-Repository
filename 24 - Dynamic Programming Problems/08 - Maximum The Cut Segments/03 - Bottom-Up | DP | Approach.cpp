class Solution
{
    public:
    // Function to calculate the maximum number of cuts using an iterative approach
    int solve(int n, int x, int y, int z){
        // Initialize a dp array with size (n+1) and set all values to INT_MIN
        // INT_MIN is used to indicate invalid states where no cuts are possible
        vector<int> dp(n+1, INT_MIN);

        // Base case: If the length is 0, no cuts are needed
        dp[0] = 0;

        // Iterate through all lengths from 1 to n
        for(int i = 1; i <= n; i++){
            // If a cut of length x is possible, update dp[i]
            if(i-x >= 0) dp[i] = max(dp[i], dp[i-x] + 1);

            // If a cut of length y is possible, update dp[i]
            if(i-y >= 0) dp[i] = max(dp[i], dp[i-y] + 1);

            // If a cut of length z is possible, update dp[i]
            if(i-z >= 0) dp[i] = max(dp[i], dp[i-z] + 1);
        }

        // Return the maximum number of cuts for length n
        // If no valid cuts are possible, dp[n] will still be INT_MIN
        return dp[n];
    }
    
    // Function to calculate the maximum number of cuts that can be made
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Call the solve function to calculate the maximum cuts
        int maxCuts = solve(n, x, y, z);

        // If the result is negative, it means no valid cuts are possible
        if(maxCuts < 0) return 0;

        // Return the maximum number of valid cuts
        return maxCuts;
    }
};
