class Solution {
public:
    // Helper function to calculate the longest palindromic subsequence using space optimization
    // Parameters:
    // - str: the original string
    // - revStr: the reversed string
    int solve(string str, string revStr) {
        int n = str.length();  // Length of the original string
        int m = revStr.length();  // Length of the reversed string

        // Two 1D arrays to represent the current and next rows of the dp table
        // `curr[j]`: Represents dp[i][j] for the current row
        // `next[j]`: Represents dp[i+1][j] for the next row
        vector<int> curr(m + 1, 0);  // Initialize the current row with 0
        vector<int> next(m + 1, 0);  // Initialize the next row with 0
        
        // Traverse the dp table from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;  // Variable to store the result for dp[i][j]

                // If the characters match, add 1 to the result from the diagonal (next[j+1])
                if (str[i] == revStr[j]) {
                    ans = 1 + next[j + 1];  // Move diagonally (i+1, j+1)
                } else {
                    // If the characters do not match, take the maximum of:
                    // - The value from the row below (next[j]) representing dp[i+1][j]
                    // - The value from the column to the right in the current row (curr[j+1])
                    ans = max(next[j], curr[j + 1]);
                }

                // Store the computed result in the current row
                curr[j] = ans;
            }

            // Update the `next` row to become the current row for the next iteration
            next = curr;
        }

        // The result is stored in `curr[0]`, which represents dp[0][0]
        return curr[0];
    }

    // Main function to calculate the longest palindromic subsequence
    int longestPalindromeSubseq(string str) {
        // Create a reversed copy of the original string
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        // Call the helper function to calculate the result
        return solve(str, revStr);
    }
};
