class Solution {
public:
    // Recursive function with memoization to find the longest palindromic subsequence
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    // - i: current index in the original string
    // - j: current index in the reversed string
    // - dp: 2D vector for memoization to store intermediate results
    int solve(string str, string revStr, int i, int j, vector<vector<int>>& dp) {
        // Base case: if either index exceeds the string length, return 0
        if (i >= str.length() || j >= revStr.length()) 
            return 0;

        // If the result for this state is already computed, return it
        if (dp[i][j] != -1) 
            return dp[i][j];

        // If characters at the current indices match, move to the next indices in both strings
        if (str[i] == revStr[j]) 
            return dp[i][j] = 1 + solve(str, revStr, i + 1, j + 1, dp);
        else {
            // Otherwise, take the maximum result by advancing one index at a time in either string
            int ans = max(solve(str, revStr, i + 1, j, dp), solve(str, revStr, i, j + 1, dp));
            return dp[i][j] = ans; // Store the result in the dp table
        }
    }

    // Main function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create a reversed copy of the original string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // Initialize a 2D dp table with -1 for memoization
        vector<vector<int>> dp(str.length() + 1, vector<int>(revStr.length() + 1, -1));

        // Start the recursive function with initial indices 0 and 0
        return solve(str, revStr, 0, 0, dp);
    }
};
