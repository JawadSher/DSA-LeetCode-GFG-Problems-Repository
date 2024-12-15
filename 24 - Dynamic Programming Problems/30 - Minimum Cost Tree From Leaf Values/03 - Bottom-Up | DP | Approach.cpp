class Solution {
public:
    // Function to compute the minimum cost of merging the array into a single leaf value
    // `arr`: The input array of leaf values
    // `maxi`: Precomputed map storing the maximum values for all subarrays
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();

        // `dp[i][j]` stores the minimum cost to merge elements in the range `[i, j]`
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Base case: Cost of merging a single element is zero
        for(int i = 0; i < arr.size(); i++) dp[i][i] = 0;

        // Iterate over subarray lengths from 2 to `n`
        for(int len = 2; len <= n; len++) {
            for(int left = 0; left <= n - len; left++) {
                int right = left + len - 1; // Calculate the right index for the current subarray
                
                // Try splitting the subarray at each possible position `i`
                for(int i = left; i < right; i++) {
                    // Compute the cost of this split:
                    // 1. `maxi[{left, i}] * maxi[{i+1, right}]`: Cost of combining the maximum values of the two partitions
                    // 2. `dp[left][i] + dp[i+1][right]`: Cost of solving the left and right partitions
                    dp[left][right] = min(dp[left][right], 
                        maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }
            }
        }

        // Return the result for the entire array `[0, n-1]`
        return dp[0][n-1];
    }

    // Main function to calculate the minimum cost tree from leaf values
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // Precompute the maximum values for all subarrays `[i, j]`
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < arr.size(); i++) {
            // For a subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, compute the maximum as the larger of:
                // - The current element `arr[j]`
                // - The maximum of the previous subarray `[i, j-1]`
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Call the solve function to calculate the result using dynamic programming
        return solve(arr, maxi);
    }
};
