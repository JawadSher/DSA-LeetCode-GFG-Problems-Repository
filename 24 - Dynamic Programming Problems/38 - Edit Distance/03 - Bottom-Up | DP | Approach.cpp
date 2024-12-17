class Solution {
public:
    // Helper function to calculate the minimum edit distance using dynamic programming
    int solve(string word1, string word2) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Create a dp table with dimensions (n+1) x (m+1), initialized to 0
        // dp[i][j] represents the minimum edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Initialize the base cases for the last row and last column of the dp table
        for (int j = 0; j < m; j++) dp[n][j] = m - j;  // If word1 is empty, we need to insert all characters from word2
        for (int i = 0; i < n; i++) dp[i][m] = n - i;  // If word2 is empty, we need to delete all characters from word1
        
        // Fill the dp table by processing the strings from bottom-right to top-left
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int ans = 0;

                // If characters at current positions match, no operation is needed, take the result from the next diagonal cell
                if (word1[i] == word2[j]) {
                    ans = dp[i+1][j+1];
                }
                else {
                    // Otherwise, calculate the costs for insertion, deletion, and replacement:
                    int insertAns = 1 + dp[i][j+1];    // Insert a character from word2 into word1 (move j ahead)
                    int deleteAns = 1 + dp[i+1][j];    // Delete a character from word1 (move i ahead)
                    int replaceAns = 1 + dp[i+1][j+1]; // Replace a character in word1 (move both i and j ahead)

                    // The minimum of these three options gives the optimal edit distance at this cell
                    ans = min({insertAns, deleteAns, replaceAns});
                }
                
                // Store the result in the dp table
                dp[i][j] = ans;
            }
        }

        // The final result is stored in dp[0][0], which represents the minimum edit distance between word1 and word2
        return dp[0][0];
    }

    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        return solve(word1, word2);  // Call the solve function to compute the result
    }
};
