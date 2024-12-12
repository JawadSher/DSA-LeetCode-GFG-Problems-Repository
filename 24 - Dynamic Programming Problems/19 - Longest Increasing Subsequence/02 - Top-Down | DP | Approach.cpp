class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using recursion with memoization.
    // Parameters:
    // - nums: The array of numbers.
    // - currIndex: The current index being considered.
    // - prevIndex: The index of the previous element included in the subsequence.
    // - dp: A 2D memoization table to store results of subproblems.
    int solve(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp) {
        int n = nums.size(); // Get the size of the array.

        // Base case: If we reach the end of the array, return 0.
        if (currIndex == n) return 0;

        // Check if the result for the current state is already computed.
        // Note: `prevIndex+1` is used to handle the -1 index case.
        if (dp[currIndex][prevIndex + 1] != -1) return dp[currIndex][prevIndex + 1];

        int include = 0; // Variable to store the result of including nums[currIndex].

        // Check if the current element can be included in the subsequence.
        // It can be included if:
        // - There is no previous element included (prevIndex == -1), OR
        // - The current element is greater than the last included element.
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solve(nums, currIndex + 1, currIndex, dp); // Include nums[currIndex].
        }

        // Exclude the current element and move to the next.
        int exclude = solve(nums, currIndex + 1, prevIndex, dp);

        // Store the result in the memoization table and return it.
        return dp[currIndex][prevIndex + 1] = max(include, exclude);
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Initialize a 2D DP table with -1 to indicate uncomputed states.
        // Dimensions are n x (n+1) to handle the case where prevIndex == -1.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Start the recursion from the first element with no previous element (-1).
        return solve(nums, 0, -1, dp);
    }
};
