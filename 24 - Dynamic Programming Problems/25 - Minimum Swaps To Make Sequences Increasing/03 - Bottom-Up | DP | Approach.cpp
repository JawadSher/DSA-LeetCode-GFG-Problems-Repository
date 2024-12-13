class Solution {
public:
    // Function to solve the problem iteratively using bottom-up dynamic programming
    // `nums1` and `nums2` are the input arrays
    // `index` represents the current position in the arrays
    // `n` is the size of the arrays
    // `swapped` indicates whether the elements were swapped
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
        // Create a DP table with dimensions [n+1][2]
        // `dp[i][0]` represents the minimum swaps required starting at index `i` when no swap is made at `i-1`
        // `dp[i][1]` represents the same but when a swap is made at `i-1`
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Start filling the DP table from the last index towards the first
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX; // Initialize the minimum swaps for the current state to a large value

                // Determine the previous elements
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // If the previous state involved a swap, adjust `prev1` and `prev2`
                if (swapped) swap(prev1, prev2);

                // Case 1: No swap at the current index
                // Check if the current elements maintain the increasing order without a swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];

                // Case 2: Swap at the current index
                // Check if swapping the current elements maintains the increasing order
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);

                // Store the result in the DP table for the current index and swap state
                dp[index][swapped] = ans;
            }
        }

        // Return the minimum swaps required starting from the first actual element without a swap
        return dp[1][0];
    }

    // Main function to find the minimum number of swaps needed
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of both arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Initialize the process by calling the iterative DP function
        bool swapped = 0;
        return solve(nums1, nums2, 1, n, swapped);
    }
};
