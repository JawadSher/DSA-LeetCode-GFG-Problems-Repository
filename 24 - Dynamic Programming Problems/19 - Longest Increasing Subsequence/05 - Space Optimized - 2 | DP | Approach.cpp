class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a simple dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create a 1D DP array where dp[i] represents the length of the LIS ending at index `i`.
        vector<int> dp(n, 1);

        // Iterate through the array to build the DP table.
        for (int currIndex = 1; currIndex < n; currIndex++) {
            // For each `currIndex`, check all previous indices (`prevIndex`) to find
            // the longest increasing subsequence that can be extended by `nums[currIndex]`.
            for (int prevIndex = 0; prevIndex < currIndex; prevIndex++) {
                // If the current element is greater than the previous element,
                // update dp[currIndex] to include the LIS ending at `prevIndex`.
                if (nums[currIndex] > nums[prevIndex]) {
                    dp[currIndex] = max(dp[currIndex], dp[prevIndex] + 1);
                }
            }
        }

        // The length of the LIS is the maximum value in the DP array.
        // Use `max_element` to find the maximum value in the DP array.
        return *max_element(dp.begin(), dp.end());
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
