class Solution {
public:
    // Helper function to calculate the longest palindromic subsequence using dynamic programming
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    // - i: current index in the original string
    // - j: current index in the reversed string
    int solve(string str, string revStr, int i, int j) {
        int n = str.length();  // Length of the original string
        int m = revStr.length();  // Length of the reversed string

        // 2D dp table to store the length of the longest palindromic subsequence
        // dp[i][j] represents the longest common subsequence between str[i..n-1] and revStr[j..m-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));  // Initialize with 0

        // Bottom-up dynamic programming approach: start from the end of both strings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;  // Variable to store the current result

                // If characters match, add 1 to the result and check the next characters in both strings
                if (str[i] == revStr[j]) {
                    ans = 1 + dp[i + 1][j + 1];  // Move diagonally (i+1, j+1)
                }
                // If characters do not match, take the maximum of two possible options
                // - Move forward in the original string (i+1, j)
                // - Move forward in the reversed string (i, j+1)
                else {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }

                // Store the computed result in the dp table
                dp[i][j] = ans;
            }
        }

        // Return the result stored at dp[0][0], which represents the length of the longest palindromic subsequence
        return dp[0][0];
    }

    // Main function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create the reversed version of the input string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());  // Reverse the string

        // Call the helper function to calculate the longest palindromic subsequence
        return solve(str, revStr, 0, 0);
    }
};
