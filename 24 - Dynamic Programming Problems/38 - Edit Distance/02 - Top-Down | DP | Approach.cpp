class Solution {
public:
    // Helper function to calculate the minimum distance (edit distance) using recursion and memoization
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Base cases: If one string is fully traversed, the remaining length of the other string is the answer
        if (i >= n) return m - j;  // If word1 is fully traversed, we need to insert remaining characters of word2
        if (j >= m) return n - i;  // If word2 is fully traversed, we need to delete remaining characters of word1

        // If the result for this subproblem is already computed (cached in dp table), return it
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;

        // If characters at the current positions match, move to the next character in both strings
        if (word1[i] == word2[j]) return solve(word1, word2, i + 1, j + 1, dp);
        else {
            // If characters do not match, consider the three possible operations:
            // 1. Insert a character into word1 (move j ahead in word2)
            int insertAns = 1 + solve(word1, word2, i, j + 1, dp);

            // 2. Delete a character from word1 (move i ahead in word1)
            int deleteAns = 1 + solve(word1, word2, i + 1, j, dp);

            // 3. Replace a character in word1 (move both i and j ahead)
            int replaceAns = 1 + solve(word1, word2, i + 1, j + 1, dp);

            // The minimum of these three options gives the optimal edit distance at this step
            ans = min({insertAns, deleteAns, replaceAns});
        }

        // Store the computed result in the dp table and return it
        return dp[i][j] = ans;
    }

    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        // Create a dp table initialized to -1 (indicating that no subproblem has been solved yet)
        // dp[i][j] represents the minimum edit distance between word1[0..i-1] and word2[0..j-1]
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));

        // Call the solve function starting from the beginning of both strings
        return solve(word1, word2, 0, 0, dp);
    }
};
