class Solution {
  public:
    // Function to find the length of the longest arithmetic progression (AP) in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();

        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;

        int ans = 2; // Minimum length of an AP is 2

        // `dp` is a 2D map where:
        // - The first key represents the index `i` of the array
        // - The second key represents the difference `diff`
        // - The value is the length of the longest AP ending at `i` with common difference `diff`
        unordered_map<int, unordered_map<int, int>> dp;

        // Iterate through all pairs of elements to fill the `dp` map
        for(int i = 1; i < n; i++) { // Start from the second element
            for(int j = 0; j < i; j++) { // Compare with all previous elements
                // Calculate the common difference between `arr[i]` and `arr[j]`
                int diff = arr[i] - arr[j];

                // Retrieve the length of the AP ending at `j` with the same `diff`
                // If no such AP exists, initialize it with length 1 (current pair)
                int count = dp[j][diff] ? dp[j][diff] : 1;

                // Update the length of the AP ending at `i` with the same `diff`
                dp[i][diff] = count + 1;

                // Update the maximum length of AP found so far
                ans = max(ans, dp[i][diff]);
            }
        }

        // Return the maximum length of AP found
        return ans;
    }
};
