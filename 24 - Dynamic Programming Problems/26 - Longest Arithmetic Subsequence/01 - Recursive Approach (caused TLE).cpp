class Solution {
  public:
    // Helper function to recursively find the length of the longest arithmetic progression (AP)
    // ending at the current index with a given common difference `diff`.
    int solve(vector<int>& arr, int index, int diff) {
        // Base case: if the index goes out of bounds, return 0
        if(index < 0) return 0;

        int ans = 0;
        // Iterate backwards from the current index to find elements that can form an AP
        for(int j = index - 1; j >= 0; j--) {
            // Check if the difference between arr[index] and arr[j] matches the given `diff`
            if(arr[index] - arr[j] == diff) {
                // Recursively find the length of AP ending at arr[j] and update `ans`
                ans = max(ans, 1 + solve(arr, j, diff));
            }
        }
        
        // Return the maximum length of AP found
        return ans;
    }
    
    // Function to find the length of the longest arithmetic progression in the array
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has 2 or fewer elements, the entire array is an AP
        if(n <= 2) return n;

        int ans = 0;
        // Iterate through all pairs of elements to calculate the common difference `diff`
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Calculate the common difference and start a recursive search
                // The length of the AP is at least 2 (the current pair)
                ans = max(ans, 2 + solve(arr, i, arr[j] - arr[i]));
            }
        }
        
        // Return the maximum length of the AP found
        return ans;
    }
};
