class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a space-optimized dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create two 1D DP arrays, `curr` and `next`, initialized with 0.
        // `curr` represents the current state, and `next` represents the state of the next row in the 2D DP table.
        vector<int> curr(n + 1, 0); 
        vector<int> next(n + 1, 0);

        // Iterate over the array in reverse order for `currIndex`.
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            // Iterate over possible values of `prevIndex` in reverse order.
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                
                // Option 1: Include the current element in the LIS.
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    // If there is no previous element or the current element is greater,
                    // include the current element in the LIS.
                    include = 1 + next[currIndex + 1];
                }

                // Option 2: Exclude the current element and proceed.
                int exclude = next[prevIndex + 1];

                // Store the maximum of including or excluding the current element in `curr`.
                curr[prevIndex + 1] = max(include, exclude);
            }

            // Update `next` to the current state for the next iteration.
            next = curr;
        }

        // The result for the entire array (starting at index 0 with no previous element) is stored in `curr[0]`.
        return curr[0];
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
