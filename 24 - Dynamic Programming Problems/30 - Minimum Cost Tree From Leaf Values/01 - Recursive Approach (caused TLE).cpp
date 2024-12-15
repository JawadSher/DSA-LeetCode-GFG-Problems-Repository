class Solution {
public:
    // Recursive function to calculate the minimum cost to combine leaf nodes
    int solve(vector<int>& arr, map<pair<int, int>, int> & maxi, int left, int right) {
        // Base case: If there is only one leaf node, no cost is required
        if(left == right) return 0;

        int mini = INT_MAX; // Initialize minimum cost to a very high value

        // Try every possible split point `i` between `left` and `right`
        for(int i = left; i < right; i++) {
            // Calculate the cost for this split:
            // maxi[{left, i}] * maxi[{i+1, right}] gives the product of the largest
            // leaf values in the two partitions
            // Add recursive costs for the left and right partitions
            mini = min(mini, 
                maxi[{left, i}] * maxi[{i+1, right}] + 
                solve(arr, maxi, left, i) + 
                solve(arr, maxi, i+1, right)
            );
        }

        return mini; // Return the minimum cost for the current range
    }

    int mctFromLeafValues(vector<int>& arr) {
        // Precompute the maximum value in all subarrays using a map
        map<pair<int, int>, int> maxi;

        // Fill the maxi map with maximum values for every subarray [i, j]
        for(int i = 0; i < arr.size(); i++) {
            // For subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, the maximum is the larger of:
                // - The current element arr[j]
                // - The maximum of the previous subarray [i, j-1]
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Call the recursive function to compute the minimum cost
        // The range is the entire array: [0, arr.size() - 1]
        return solve(arr, maxi, 0, arr.size()-1);
    }
};
