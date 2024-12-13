class Solution {
public:
    // Helper function to solve the problem of picking non-adjacent slices
    int solve(vector<int>& slices) {
        int k = slices.size();  // Total number of slices (3 * n)

        // Initialize two DP tables:
        // dp[i][n] stores the maximum sum of slices we can pick from index i with n slices left to pick.
        vector<vector<int>> dp(k + 2, vector<int>(k, 0)); // For the first case, we exclude the last slice
        vector<vector<int>> dp1(k + 2, vector<int>(k, 0)); // For the second case, we exclude the first slice

        // DP for case 1 (excluding the last slice)
        for (int index = k - 2; index >= 0; index--) {  // Iterate backwards through the slices (0 to k-2)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward (to avoid picking adjacent slices)
                int takeSlice = slices[index] + dp[index + 2][n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + dp[index + 1][n];
                
                // Store the maximum of the two options (take or skip)
                dp[index][n] = max(takeSlice, noTakeSlice);
            }
        }

        // Store the result for case 1, excluding the last slice
        int case1 = dp[0][k / 3];  // We start from index 0 and need to pick k/3 slices

        // DP for case 2 (excluding the first slice)
        for (int index = k - 1; index >= 1; index--) {  // Iterate backwards through the slices (1 to k-1)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward
                int takeSlice = slices[index] + dp1[index + 2][n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + dp1[index + 1][n];
                
                // Store the maximum of the two options (take or skip)
                dp1[index][n] = max(takeSlice, noTakeSlice);
            }
        }

        // Store the result for case 2, excluding the first slice
        int case2 = dp1[1][k / 3];  // We start from index 1 and need to pick k/3 slices

        // Return the maximum of the two cases
        return max(case1, case2);
    }

    // Main function to calculate the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);  // Call the solve function to compute the result
    }
};
