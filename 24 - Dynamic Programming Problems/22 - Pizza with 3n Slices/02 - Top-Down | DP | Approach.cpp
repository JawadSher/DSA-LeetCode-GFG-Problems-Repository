class Solution {
public:
    // Helper function to solve the subproblem of picking non-adjacent slices
    int solve(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        // Base case: If we've chosen n slices or exceed the valid range, return 0 (no sum)
        if (n == 0 || index > endIndex) return 0;

        // If the result for this subproblem has already been computed, return the cached value
        if (dp[index][n] != -1) return dp[index][n];

        // Option 1: Take the slice at the current index and move two steps forward
        int takeSlice = slices[index] + solve(index + 2, endIndex, slices, n - 1, dp);
        
        // Option 2: Skip the slice at the current index and move one step forward
        int noTakeSlice = 0 + solve(index + 1, endIndex, slices, n, dp);

        // Store the result for the current subproblem in the dp table
        return dp[index][n] = max(takeSlice, noTakeSlice);
    }

    // Main function to find the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size(); // Total number of slices
        
        // Initialize dp table for case 1 (picking slices from index 0 to k-2)
        vector<vector<int>> dp(k, vector<int>(k, -1)); 
        // Case 1: Exclude the last slice (pick slices from index 0 to k-2)
        int case1 = solve(0, k - 2, slices, k / 3, dp);

        // Initialize dp table for case 2 (picking slices from index 1 to k-1)
        vector<vector<int>> dp1(k, vector<int>(k, -1)); 
        // Case 2: Exclude the first slice (pick slices from index 1 to k-1)
        int case2 = solve(1, k - 1, slices, k / 3, dp1);

        // Return the maximum of the two cases
        return max(case1, case2);
    }
};
