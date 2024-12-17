class Solution {
public:
    // Helper function to compute the longest common subsequence using optimized space
    int solve(string &text1, string &text2) {
        int n = text1.length(); // Length of the first string
        int m = text2.length(); // Length of the second string

        // Create two 1D arrays for the current and next rows in the DP table
        // This reduces the space complexity to O(m) instead of O(n*m)
        vector<int> curr(m + 1, 0); // Current row being processed
        vector<int> next(m + 1, 0); // Next row (from the previous iteration)

        // Iterate over the strings in reverse order
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0; // Variable to store the result for the current state
                
                // Case 1: Characters match, include them in the LCS
                if (text1[i] == text2[j]) 
                    ans = 1 + next[j + 1];
                else
                    // Case 2: Characters don't match, take the maximum:
                    // a) Skip the current character of text1
                    // b) Skip the current character of text2
                    ans = max(next[j], curr[j + 1]);
                
                // Store the result in the current row
                curr[j] = ans;
            }

            // Update the next row to the current row for the next iteration
            next = curr;
        }

        // The final answer (LCS of the entire strings) is stored in curr[0]
        return curr[0];
    }

    // Main function to compute the longest common subsequence
    int longestCommonSubsequence(string text1, string text2) {
        // Call the helper function and return the result
        return solve(text1, text2);
    }
};
