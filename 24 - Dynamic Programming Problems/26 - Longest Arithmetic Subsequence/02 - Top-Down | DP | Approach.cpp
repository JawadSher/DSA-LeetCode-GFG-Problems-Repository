class Solution {
  public:
    // Helper function to recursively find the length of the longest arithmetic progression (AP)
    // ending at the current index `index` with a given common difference `diff`.
    // The `dp` array is used for memoization to avoid redundant computations.
    int solve(vector<int>& arr, int index, int diff, unordered_map<int, int> dp[]) {
        // Base case: if the index goes out of bounds, return 0
        if(index < 0) return 0;

        // If the result for the current `index` and `diff` is already calculated, return it
        if(dp[index].count(diff)) return dp[index][diff];
        
        int ans = 0;
        // Iterate backward from the current index to find elements that can extend the AP
        for(int j = index - 1; j >= 0; j--) {
            // Check if the difference between arr[index] and arr[j] matches the given `diff`
            if(arr[index] - arr[j] == diff) {
                // Recursively find the length of the AP ending at arr[j] and update `ans`
                ans = max(ans, 1 + solve(arr, j, diff, dp));
            }
        }
        
        // Store the result in the `dp` array and return it
        return dp[index][diff] = ans;
    }
    
    // Function to find the length of the longest arithmetic progression (AP) in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;
        
        // `dp[i]` is an unordered map where the key is the difference `diff` and the value
        // is the length of the longest AP ending at index `i` with that difference
        unordered_map<int, int> dp[n + 1];
        
        int ans = 0; // Variable to store the maximum length of AP found
        // Iterate through all pairs of elements to calculate the common difference `diff`
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Calculate the common difference and start a recursive search
                // The length of the AP is at least 2 (the current pair)
                ans = max(ans, 2 + solve(arr, i, arr[j] - arr[i], dp));
            }
        }
        
        // Return the maximum length of AP found
        return ans;
    }
};
