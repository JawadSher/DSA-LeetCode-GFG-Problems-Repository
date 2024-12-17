class Solution {
public:
    // Helper function to recursively find the length of the longest common subsequence
    int solve(string &text1, string &text2, int i, int j) {
        // Base case: if either string is exhausted, no subsequence is possible
        if (i >= text1.length() || j >= text2.length()) return 0;
        
        int ans = 0; // Initialize the answer for the current state

        // Case 1: Characters match, include them in the subsequence
        if (text1[i] == text2[j]) 
            return 1 + solve(text1, text2, i + 1, j + 1);
        else {
            // Case 2: Characters don't match, explore two possibilities:
            // a) Skip the current character of text1
            // b) Skip the current character of text2
            // Take the maximum of these two possibilities
            ans = max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
        }
        
        return ans; // Return the result for the current state
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Start the recursive computation from the beginning of both strings
        return solve(text1, text2, 0, 0);
    }
};
