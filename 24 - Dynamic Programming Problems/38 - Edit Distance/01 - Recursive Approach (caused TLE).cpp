class Solution {
public:
    // Helper function to calculate the minimum distance (edit distance) recursively
    int solve(string word1, string word2, int i, int j) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Base cases: If one string is fully traversed, the remaining length of the other string is the answer
        if (i >= n) return m - j;  // If word1 is fully traversed, we need to insert remaining characters of word2
        if (j >= m) return n - i;  // If word2 is fully traversed, we need to delete remaining characters of word1
        
        int ans = 0;

        // If characters at the current positions match, move to the next character in both strings
        if (word1[i] == word2[j]) return solve(word1, word2, i + 1, j + 1);
        else {
            // If characters do not match, consider the three possible operations:
            // 1. Insert a character into word1 (move j ahead in word2)
            int insertAns = 1 + solve(word1, word2, i, j + 1);

            // 2. Delete a character from word1 (move i ahead in word1)
            int deleteAns = 1 + solve(word1, word2, i + 1, j);

            // 3. Replace a character in word1 (move both i and j ahead)
            int replaceAns = 1 + solve(word1, word2, i + 1, j + 1);

            // The minimum of these three options gives the optimal edit distance at this step
            ans = min({insertAns, deleteAns, replaceAns});
        }

        // Return the minimum edit distance
        return ans;
    }

    // Main function that calculates the minimum distance between word1 and word2
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);  // Start the recursion from the beginning of both strings
    }
};
