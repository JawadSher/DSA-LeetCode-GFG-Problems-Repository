class Solution {
public:
    // Recursive function to check if the pattern matches the string with memoization
    int solve(string &str, string &ptrn, int i, int j, vector<vector<int>> &dp) {
        // Base case: If both string and pattern are exhausted, return true
        if (i < 0 && j < 0) return true;

        // Base case: If pattern is exhausted but the string is not, return false
        if (j < 0) return false;

        // Base case: If string is exhausted
        if (i < 0) {
            // Check if the remaining characters in the pattern are all '*'
            for (int k = 0; k <= j; k++) {
                if (ptrn[k] != '*') return false;
            }
            return true;
        }

        // Check if the result for this state is already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Case 1: If characters match or the pattern has '?', move both pointers
        if (str[i] == ptrn[j] || ptrn[j] == '?') {
            dp[i][j] = solve(str, ptrn, i - 1, j - 1, dp);
        }
        // Case 2: If the pattern has '*', there are two possibilities:
        // - Treat '*' as matching the current character (move string pointer `i` only)
        // - Treat '*' as matching zero characters (move pattern pointer `j` only)
        else if (ptrn[j] == '*') {
            dp[i][j] = solve(str, ptrn, i - 1, j, dp) || solve(str, ptrn, i, j - 1, dp);
        }
        // Case 3: If characters don't match and it's not a wildcard, return false
        else {
            dp[i][j] = false;
        }

        // Return the computed result for this state
        return dp[i][j];
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        int n = s.length(); // Length of the string
        int m = p.length(); // Length of the pattern

        // Initialize a 2D DP array with -1, where dp[i][j] represents the result
        // of matching the first i characters of the string with the first j characters of the pattern
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Start the recursive process with memoization
        return solve(s, p, n - 1, m - 1, dp);
    }
};
