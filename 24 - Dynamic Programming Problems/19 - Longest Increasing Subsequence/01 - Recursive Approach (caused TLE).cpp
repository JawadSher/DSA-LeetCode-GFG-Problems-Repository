class Solution {
public:
    // Helper function to find the length of the Longest Increasing Subsequence (LIS)
    // using recursion. 
    // Parameters:
    // - nums: The array of numbers.
    // - currIndex: The current index being considered.
    // - prevIndex: The index of the previous element included in the subsequence.
    int solve(vector<int>& nums, int currIndex, int prevIndex) {
        int n = nums.size(); // Get the size of the array.

        // Base case: If we reach the end of the array, return 0.
        if (currIndex == n) return 0;

        int include = 0; // Variable to store the result of including nums[currIndex].
        
        // Check if the current element can be included in the subsequence.
        // It can be included if:
        // - There is no previous element included (prevIndex == -1), OR
        // - The current element is greater than the last included element.
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solve(nums, currIndex + 1, currIndex); // Include nums[currIndex].
        }

        // Exclude the current element and move to the next.
        int exclude = solve(nums, currIndex + 1, prevIndex);

        // Return the maximum of including or excluding the current element.
        return max(include, exclude);
    }

    // Main function to calculate the length of the Longest Increasing Subsequence.
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1); // Start with the first element and no previous element.
    }
};
