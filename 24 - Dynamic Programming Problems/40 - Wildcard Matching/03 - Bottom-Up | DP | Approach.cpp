class Solution {
public:
    // Function to determine if the string matches the pattern using dynamic programming
    int solve(string &str, string &ptrn) {
        int n = str.length(); // Length of the string
        int m = ptrn.length(); // Length of the pattern

        // DP table to store the results of subproblems
        // dp[i][j] represents whether the first `i` characters of the string match the first `j` characters of the pattern
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base case: An empty string matches an empty pattern
        dp[0][0] = true;

        // Handle cases where the string is empty but the pattern has characters
        for (int j = 1; j <= m; j++) {
            bool flag = true; // Check if all characters in the pattern up to `j` are '*'
            for (int k = 1; k <= j; k++) {
                if (ptrn[k - 1] != '*') { // If a non-'*' character is found, stop
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag; // Set `dp[0][j]` to true if all characters are '*', otherwise false
        }

        // Fill the DP table for cases where both string and pattern have characters
        for (int i = 1; i <= n; i++) { // Iterate over the string
            for (int j = 1; j <= m; j++) { // Iterate over the pattern
                // Case 1: Characters match or the pattern has '?'
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Case 2: Pattern has '*'
                // - '*' can match the current character in the string (move string pointer `i-1`)
                // - '*' can match zero characters (move pattern pointer `j-1`)
                else if (ptrn[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                // Case 3: Characters do not match and there's no wildcard
                else {
                    dp[i][j] = false;
                }
            }
        }

        // The result for the full string and pattern is stored in `dp[n][m]`
        return dp[n][m];
    }

    // Main function to check if the string matches the pattern
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
