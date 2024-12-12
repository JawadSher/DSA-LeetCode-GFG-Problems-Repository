class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a more efficient approach with binary search.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create a vector `ans` to store the elements of the current LIS.
        // It will not necessarily be the actual LIS but will have the same length.
        vector<int> ans;
        
        // Add the first element to the LIS tracker.
        ans.push_back(nums[0]);

        // Iterate over the rest of the elements in the array.
        for (int i = 1; i < n; i++) {
            // If the current element is greater than the last element of `ans`,
            // it extends the LIS, so add it to the end of `ans`.
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } 
            // Otherwise, replace the smallest element in `ans` that is greater than
            // or equal to the current element using `lower_bound`.
            else {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        // The size of the `ans` vector represents the length of the LIS.
        return ans.size();
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
