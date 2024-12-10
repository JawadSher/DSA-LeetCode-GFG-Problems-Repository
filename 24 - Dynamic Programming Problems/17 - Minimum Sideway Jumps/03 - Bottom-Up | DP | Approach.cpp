class Solution {
public:
    // Function to solve the problem using dynamic programming
    int solve(vector<int>& obstacles) {
        int n = obstacles.size() - 1; // Get the last position in the obstacles array
        // Initialize the dp table with large values (1e9), where dp[lane][pos] represents the minimum jumps required
        // to reach the end from position 'pos' in 'lane'.
        vector<vector<int>> dp(4, vector<int>(n + 1, 1e9));

        // Base case: at the last position (n), no more jumps are needed, hence 0 jumps for all lanes
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        // Iterate from the second-last position to the start of the array
        for(int pos = n - 1; pos >= 0; pos--) {
            // Try all 3 lanes (1, 2, 3) for each position
            for(int lane = 1; lane <= 3; lane++) {

                // If the next position is not blocked by the current lane, no jump is needed
                if(obstacles[pos + 1] != lane) {
                    dp[lane][pos] = dp[lane][pos + 1]; // Carry over the result from the next position
                } else {
                    // If the next position is blocked, we need to jump to a different lane
                    int ans = 1e9; // Initialize the answer to a large value (to minimize later)

                    // Try all 3 possible lanes (1, 2, 3) to find the best jump option
                    for(int i = 1; i <= 3; i++) {
                        // If the current lane is not the lane we're trying to jump to, and the lane is not blocked
                        if(lane != i && obstacles[pos] != i) {
                            // Add 1 for the jump and update the answer with the minimum jumps required
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }
                    dp[lane][pos] = ans; // Store the result for this position and lane
                }
            }
        }

        // Return the minimum jumps required starting from position 0 with lane 2.
        // We also consider the case where we might need one jump to lane 1 or lane 3.
        return min({dp[2][0], dp[1][0] + 1, dp[3][0] + 1});
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles); // Call the solve function to get the result
    }
};
