class Solution {
public:
    // Helper function to solve the subproblem of picking non-adjacent slices
    int solve(int index, int endIndex, vector<int>& slices, int n) {
        // Base case: If we've chosen n slices or we exceed the valid range, return 0 (no sum)
        if (n == 0 || index > endIndex) return 0;

        // Option 1: Take the slice at the current index and move two steps forward
        int takeSlice = slices[index] + solve(index + 2, endIndex, slices, n - 1);
        
        // Option 2: Skip the slice at the current index and move one step forward
        int noTakeSlice = 0 + solve(index + 1, endIndex, slices, n);

        // Return the maximum of taking or skipping the current slice
        return max(takeSlice, noTakeSlice);
    }

    // Main function to find the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size(); // Total number of slices
        // Case 1: Exclude the last slice (pick slices from index 0 to k-2)
        int case1 = solve(0, k - 2, slices, k / 3);
        
        // Case 2: Exclude the first slice (pick slices from index 1 to k-1)
        int case2 = solve(1, k - 1, slices, k / 3);

        // Return the maximum of the two cases
        return max(case1, case2);
    }
};
