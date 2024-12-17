class Solution {
public:
    // Helper function to compute the longest common subsequence using bottom-up dynamic programming
    int solve(string &text1, string &text2) {
        int n = text1.length(); // Length of the first string
        int m = text2.length(); // Length of the second string

        // Create a 2D DP table initialized with 0
        // dp[i][j] represents the length of the LCS of text1[i..n-1] and text2[j..m-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Iterate over the strings in reverse order to fill the DP table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0; // Variable to store the result for the current state
                
                // Case 1: Characters match, include them in the LCS
                if (text1[i] == text2[j]) 
                    ans = 1 + dp[i + 1][j + 1];
                else
                    // Case 2: Characters don't match, take the maximum:
                    // a) Skip the current character of text1
                    // b) Skip the current character of text2
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                
                // Store the result in the DP table
                dp[i][j] = ans;
            }
        }

        // The final answer (LCS of the entire strings) is stored in dp[0][0]
        return dp[0][0];
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Call the helper function and return the result
        return solve(text1, text2);
    }
};
