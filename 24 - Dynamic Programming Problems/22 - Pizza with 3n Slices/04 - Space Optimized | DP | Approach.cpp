class Solution {
public:
    // Helper function to solve the problem of picking non-adjacent slices
    int solve(vector<int>& slices){
        int k = slices.size();  // Total number of slices (3 * n)

        // Initialize 3 arrays for dynamic programming:
        // prev, curr, and next are used to store the results of previous, current, and next steps, respectively.
        vector<int> prev(k+2, 0);    // To store the results of the previous step for dp
        vector<int> curr(k+2, 0);    // To store the results of the current step for dp
        vector<int> next(k+2, 0);    // To store the results of the next step for dp

        // DP for case 1 (excluding the last slice)
        for (int index = k - 2; index >= 0; index--) {  // Iterate backwards through the slices (0 to k-2)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward (to avoid picking adjacent slices)
                int takeSlice = slices[index] + next[n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + curr[n];
                
                // Store the maximum of the two options (take or skip)
                prev[n] = max(takeSlice, noTakeSlice);
            }
            // Update the dp arrays by shifting
            next = curr;   // Move current to next
            curr = prev;   // Move previous to current
        }

        // Store the result for case 1, excluding the last slice
        int case1 = curr[k / 3];  // We start from index 0 and need to pick k/3 slices

        // DP for case 2 (excluding the first slice)
        vector<int> prev1(k+2, 0);   // To store the results for the second case
        vector<int> curr1(k+2, 0);   // To store the current results for the second case
        vector<int> next1(k+2, 0);   // To store the next step results for the second case

        // Iterate through slices for case 2, starting from index 1 and excluding the first slice
        for (int index = k - 1; index >= 1; index--) {  // Iterate backwards through the slices (1 to k-1)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward
                int takeSlice = slices[index] + next1[n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + curr1[n];
                
                // Store the maximum of the two options (take or skip)
                prev1[n] = max(takeSlice, noTakeSlice);
            }
            // Update the dp arrays by shifting
            next1 = curr1;   // Move current to next
            curr1 = prev1;   // Move previous to current
        }

        // Store the result for case 2, excluding the first slice
        int case2 = curr1[k / 3];  // We start from index 1 and need to pick k/3 slices

        // Return the maximum of the two cases
        return max(case1, case2);
    }

    // Main function to calculate the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);  // Call the solve function to compute the result
    }
};
