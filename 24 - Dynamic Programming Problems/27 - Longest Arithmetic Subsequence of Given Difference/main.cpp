class Solution {
public:
    // Function to find the length of the longest arithmetic subsequence with the given difference
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();  // Get the size of the input array
        unordered_map<int, int> dp;  // Map to store the longest subsequence length for each element

        int ans = 0;  // Variable to store the maximum length of any subsequence found so far

        // Iterate through each element of the array
        for(int i = 0; i < n; i++) {
            // Calculate the previous element in the subsequence with the given difference
            int temp = arr[i] - difference;

            // If there's a subsequence ending with `temp`, we get its length from dp. If not, set prevAns to 0
            int prevAns = dp.count(temp) ? dp[temp] : 0;

            // Update the longest subsequence ending at arr[i], adding 1 to the length of the previous subsequence
            dp[arr[i]] = 1 + prevAns;

            // Update the maximum subsequence length found so far
            ans = max(ans, dp[arr[i]]);
        }

        // Return the maximum length of the subsequence found
        return ans;
    }
};
