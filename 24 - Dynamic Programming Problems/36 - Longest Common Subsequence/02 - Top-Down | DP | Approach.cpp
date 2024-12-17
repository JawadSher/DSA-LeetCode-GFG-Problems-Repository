class Solution {
public:
    // Helper function to recursively find the length of the longest common subsequence with memoization
    int solve(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        // Base case: if either string is exhausted, no subsequence is possible
        if (i >= text1.length() || j >= text2.length()) return 0;

        // Check if the result for this state has already been computed
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0; // Initialize the answer for the current state

        // Case 1: Characters match, include them in the subsequence
        if (text1[i] == text2[j]) 
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp);
        else {
            // Case 2: Characters don't match, explore two possibilities:
            // a) Skip the current character of text1
            // b) Skip the current character of text2
            // Take the maximum of these two possibilities
            ans = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
        }

        // Store the computed result in the memoization table
        return dp[i][j] = ans;
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Create a 2D vector for memoization initialized with -1
        // dp[i][j] stores the result of solve for indices i and j
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        
        // Start the recursive computation from the beginning of both strings
        return solve(text1, text2, 0, 0, dp);
    }
};
