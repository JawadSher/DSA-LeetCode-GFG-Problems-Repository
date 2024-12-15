class Solution {
public:
    // Recursive function to calculate the minimum cost of combining leaf values
    // `arr`: The input array of leaf values
    // `maxi`: Precomputed map containing the maximum values for all subarrays
    // `left`, `right`: The current range being considered
    // `dp`: Memoization table to store results of subproblems
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
        // Base case: If there is only one element, the cost is zero
        if(left == right) return 0;

        // If the result for this subproblem is already computed, return it
        if(dp[left][right] != -1) return dp[left][right];

        int mini = INT_MAX; // Initialize minimum cost to a very high value

        // Try every possible split point `i` between `left` and `right`
        for(int i = left; i < right; i++) {
            // Calculate the cost of this split:
            // 1. `maxi[{left, i}] * maxi[{i+1, right}]`: Cost of combining the maximum leaf values from the two partitions
            // 2. Recursive calls to solve for the left and right partitions
            mini = min(mini, 
                maxi[{left, i}] * maxi[{i+1, right}] + 
                solve(arr, maxi, left, i, dp) + 
                solve(arr, maxi, i+1, right, dp)
            );
        }

        // Store the result in the `dp` table for future use
        return dp[left][right] = mini;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // `dp` table to memoize results for subproblems
        // `dp[i][j]` will store the minimum cost to combine leaf nodes in the range `[i, j]`
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Precompute the maximum values for all subarrays `[i, j]`
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < arr.size(); i++) {
            // For subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, the maximum is the larger of:
                // - The current element `arr[j]`
                // - The maximum of the previous subarray `[i, j-1]`
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Solve the problem for the full range `[0, n-1]` using the recursive function
        return solve(arr, maxi, 0, arr.size() - 1, dp);
    }
};
