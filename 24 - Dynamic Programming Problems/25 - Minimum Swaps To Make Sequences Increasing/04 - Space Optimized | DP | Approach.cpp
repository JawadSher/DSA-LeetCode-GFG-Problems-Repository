class Solution {
public:
    // Function to solve the problem iteratively with optimized space
    // `nums1` and `nums2` are the input arrays
    // `index` is the starting index for processing
    // `n` is the size of the arrays
    // `swapped` is the initial state indicating whether a swap was performed
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
        // DP arrays to store the results of the current and previous states
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Variables to store the state of swapping for the previous index
        int swap = 0;    // Minimum swaps needed if the previous state involved a swap
        int noswap = 0;  // Minimum swaps needed if the previous state did not involve a swap
        int currswap = 0;    // Current state when a swap occurs
        int currnoswap = 0;  // Current state when no swap occurs

        // Iterate backwards from the second last index to the first index
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX; // Initialize the minimum swaps for this state

                // Determine the previous elements
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // Adjust previous elements if the previous state was swapped
                if (swapped) {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                // Case 1: No swap at the current index
                // Check if the current elements maintain the increasing order without a swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;

                // Case 2: Swap at the current index
                // Check if swapping the current elements maintains the increasing order
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + swap);

                // Update the current state variables
                if (swapped)
                    currswap = ans; // If current state involves a swap
                else
                    currnoswap = ans; // If current state does not involve a swap
            }

            // Update the previous state variables for the next iteration
            swap = currswap;
            noswap = currnoswap;
        }

        // Return the minimum swaps needed starting from index 1 without a swap
        return min(swap, noswap);
    }

    // Main function to find the minimum number of swaps required
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of the arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Call the solve function to compute the result
        bool swapped = 0;
        return solve(nums1, nums2, 1, n, swapped);
    }
};
