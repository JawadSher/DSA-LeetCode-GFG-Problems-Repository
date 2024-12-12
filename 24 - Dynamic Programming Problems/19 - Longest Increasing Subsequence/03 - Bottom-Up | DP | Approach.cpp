class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a bottom-up dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create a 2D DP table initialized with 0.
        // dp[currIndex][prevIndex+1] represents the length of LIS starting at `currIndex`
        // with the previous element being `nums[prevIndex]`.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Iterate over the array in reverse order for `currIndex`.
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            // Iterate over the possible values of `prevIndex` in reverse order.
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                
                // Option 1: Include the current element in the LIS.
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    // If there is no previous element or the current element is greater,
                    // include the current element in the LIS.
                    include = 1 + dp[currIndex + 1][currIndex + 1];
                }

                // Option 2: Exclude the current element and proceed.
                int exclude = dp[currIndex + 1][prevIndex + 1];

                // Take the maximum of including or excluding the current element.
                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }

        // Return the result for the entire array (starting at index 0 with no previous element).
        return dp[0][0];
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
