class Solution {
public:
    // Function to solve the problem using bottom-up dynamic programming
    // satisfaction: vector containing satisfaction values of dishes
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Create a DP table to store the maximum "like-time coefficient" values
        // dp[i][j] represents the maximum value achievable starting from index i with time j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Iterate over the satisfaction array in reverse order
        // satis represents the current index in the satisfaction array
        for (int satis = n - 1; satis >= 0; satis--) {
            // Iterate over the possible time values in reverse order
            for (int time = satis; time >= 0; time--) {
                // Option 1: Include the current dish
                // Add its contribution to the result, and increment the time multiplier
                int include = satisfaction[satis] * (time + 1) + dp[satis + 1][time + 1];

                // Option 2: Exclude the current dish
                // Skip the current dish, keeping the same time multiplier
                int exclude = 0 + dp[satis + 1][time];

                // Store the maximum of the two options in the DP table
                dp[satis][time] = max(include, exclude);
            }
        }

        // Return the maximum value starting from index 0 with time multiplier 1
        return dp[0][0];
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting ensures we process less satisfying dishes first
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Use the solve function to compute the result
        return solve(satisfaction);
    }
};
