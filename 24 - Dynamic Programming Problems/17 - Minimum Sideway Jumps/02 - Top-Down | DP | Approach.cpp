class Solution {
public:
    // Recursive function with memoization to solve the problem
    int solve(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>>& dp) {
        int n = obstacles.size() - 1; // Last position in the obstacles array
        
        // Base case: If we have reached the last position, no more jumps are needed
        if(currpos == n) return 0;

        // If this state has already been computed, return the cached result from dp table
        if(dp[currlane][currpos] != -1) return dp[currlane][currpos];

        // If the next position is not blocked by the current lane, move to the next position without jumping
        if(obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1, dp);
        } else {
            int ans = INT_MAX; // Initialize the answer to a large value (for minimization)

            // Try all 3 possible lanes (1, 2, 3) and find the minimum side jump
            for(int i = 1; i <= 3; i++) {
                // If the current lane is not the lane we're trying to move to, and the next lane is not blocked
                if(currlane != i && obstacles[currpos] != i) {
                    // Recursively calculate the number of jumps, adding 1 for the jump
                    ans = min(ans, 1 + solve(obstacles, i, currpos, dp));
                }
            }

            // Store the result in the dp table to avoid recomputation and return the answer
            return dp[currlane][currpos] = ans;
        }
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(); // Get the size of the obstacles array
        
        // Initialize the dp table with -1 (indicating uncomputed states)
        // dp[i][j] represents the minimum jumps needed from lane i at position j
        vector<vector<int>> dp(4, vector<int>(n - 1, -1)); 

        // Start from lane 2 and position 0, then call the recursive solve function
        return solve(obstacles, 2, 0, dp);
    }
};
