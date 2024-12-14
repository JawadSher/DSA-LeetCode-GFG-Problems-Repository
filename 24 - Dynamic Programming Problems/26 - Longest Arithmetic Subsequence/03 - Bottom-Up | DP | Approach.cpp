class Solution {
  public:
    // Function to find the length of the longest arithmetic progression (AP) in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;
        
        int ans = 0; // Variable to store the maximum length of AP found
        
        // `dp[i]` is an unordered map where the key is the difference `diff`
        // and the value is the length of the longest AP ending at index `i` with that difference
        unordered_map<int, int> dp[n + 1];
        
        // Iterate through all pairs of elements to build the `dp` table
        for(int i = 1; i < n; i++) { // Start from the second element
            for(int j = 0; j < i; j++) { // Compare with all previous elements
                // Calculate the common difference between arr[i] and arr[j]
                int diff = arr[i] - arr[j];
                int count = 1; // Minimum length of AP (current pair)
                
                // If there exists an AP ending at `j` with the same `diff`, retrieve its length
                if(dp[j].count(diff)) count = dp[j][diff];
                
                // Extend the AP by including the current element at `i`
                dp[i][diff] = 1 + count;

                // Update the maximum length of AP found so far
                ans = max(ans, dp[i][diff]);
            }
        }
        
        // Return the maximum length of AP
        return ans;
    }
};
