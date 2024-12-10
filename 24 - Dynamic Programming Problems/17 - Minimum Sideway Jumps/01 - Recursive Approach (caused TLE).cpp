class Solution {
public:
    // Recursive function to solve the problem with dynamic programming
    int solve(vector<int>& obstacles, int currlane, int currpos) {
        int n = obstacles.size() - 1; // The last position in the obstacles array
        // If we have reached the last position, no more jumps are needed
        if(currpos == n) return 0;

        // If the next position is not blocked by the current lane
        if(obstacles[currpos + 1] != currlane) {
            return solve(obstacles, currlane, currpos + 1); // Move to the next position without jumping
        } else {
            int ans = INT_MAX; // Initialize the answer to a large value (to minimize later)
            // Try all 3 lanes (1, 2, 3) to check for the minimum jumps
            for(int i = 1; i <= 3; i++) {
                // If the current lane is not the one we're trying, and the next lane is not blocked
                if(currlane != i && obstacles[currpos] != i) {
                    // Recursively solve the problem, with one additional jump (1 +)
                    ans = min(ans, 1 + solve(obstacles, i, currpos));
                }
            }
            return ans; // Return the minimum number of jumps found
        }
    }

    // Main function to return the minimum number of side jumps
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0); // Start from lane 2 and position 0 (the first obstacle)
    }
};
