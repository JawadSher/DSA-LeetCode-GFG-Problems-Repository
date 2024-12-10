class Solution {
public:
    // Function to solve the problem using dynamic programming with space optimization
    int solve(vector<int>& obstacles) {
        int n = obstacles.size() - 1; // Get the last position in the obstacles array

        // Create two vectors to represent the current and next state of the dp table
        // curr[lane] represents the minimum jumps required from the current position in the lane.
        // next[lane] represents the minimum jumps required from the next position in the lane.
        vector<int> curr(4, INT_MAX); // Initialize the current state with large values (INT_MAX).
        vector<int> next(4, INT_MAX); // Initialize the next state with large values (INT_MAX).

        // At the last position (n), no jumps are needed, so we set all lanes to 0
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        // Iterate from the second-last position to the start of the array
        for (int pos = n - 1; pos >= 0; pos--) {
            // Try all 3 lanes (1, 2, 3) for each position
            for (int lane = 1; lane <= 3; lane++) {

                // If the next position is not blocked by the current lane, no jump is needed
                if (obstacles[pos + 1] != lane) {
                    curr[lane] = next[lane]; // Carry over the result from the next position
                } else {
                    // If the next position is blocked, we need to jump to a different lane
                    int ans = INT_MAX; // Initialize the answer to a large value (to minimize later)

                    // Try all 3 possible lanes (1, 2, 3) to find the best jump option
                    for (int i = 1; i <= 3; i++) {
                        // If the current lane is not the lane we're trying to jump to, and the lane is not blocked
                        if (lane != i && obstacles[pos] != i) {
                            // Add 1 for the jump and update the answer with the minimum jumps required
                            ans = min(ans, 1 + next[i]);
                        }
                    }

                    // Store the minimum jumps required for this position and lane in the curr array
                    curr[lane] = ans;
                }
            }

            // After processing all lanes for this position, move the next state to curr
            next = curr;
        }

        // Return the minimum side jumps required starting from position 0 with lane 2.
        // We also consider the case where we might need one jump to lane 1 or lane 3.
        return min({curr[2], curr[1] + 1, curr[3] + 1});
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles); // Call the solve function to get the result
    }
};
