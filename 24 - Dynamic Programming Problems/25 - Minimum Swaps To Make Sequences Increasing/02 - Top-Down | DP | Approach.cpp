class Solution {
public:
    // Recursive helper function to solve the problem
    // `nums1` and `nums2` are the input arrays
    // `index` represents the current position in the arrays
    // `n` is the size of the arrays
    // `swapped` indicates if the previous elements were swapped
    // `dp` is the memoization table to store results of subproblems
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped, vector<vector<int>>& dp) {
        // Base case: if we reach the end of the arrays, no swaps are needed
        if (index >= n) return 0;

        // Check if the current subproblem has already been solved
        if (dp[index][swapped] != -1) return dp[index][swapped];

        // Initialize the minimum swaps required as a large value
        int ans = INT_MAX;

        // Retrieve the previous elements in both arrays
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // If the previous elements were swapped, reverse them
        if (swapped) swap(prev1, prev2);

        // Case 1: No swap at the current index
        // Check if the current elements maintain the increasing order without a swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, n, 0, dp);

        // Case 2: Swap at the current index
        // Check if swapping the current elements maintains the increasing order
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, n, 1, dp));

        // Store the result in the memoization table and return
        return dp[index][swapped] = ans;
    }

    // Main function to find the minimum number of swaps needed
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of both arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Initialize the memoization table with -1 (unvisited state)
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start solving from the first actual element
        bool swapped = 0;
        return solve(nums1, nums2, 1, n, swapped, dp);
    }
};
