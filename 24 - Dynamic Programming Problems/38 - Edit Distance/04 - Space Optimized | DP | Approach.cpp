class Solution {
public:
    // Helper function to calculate the minimum edit distance using dynamic programming
    int solve(string word1, string word2) {
        int n = word1.length(); // Length of the first string
        int m = word2.length(); // Length of the second string

        // Create two 1D arrays to store the current and next row values of the dp table
        vector<int> curr(m+1, 0); // Current row (for the current i-th character in word1)
        vector<int> next(m+1, 0); // Next row (for the next i+1-th character in word1)

        // Initialize the next row for the case when word1 is empty
        for(int j = 0; j < m; j++) next[j] = m - j;

        // Iterate over word1 from bottom to top (i = n-1 to i = 0)
        for(int i = n-1; i >= 0; i--) {
            // Iterate over word2 from right to left (j = m-1 to j = 0)
            for(int j = m-1; j >= 0; j--) {
                // Set the base case for when word2 is empty (fill in the current row's last column)
                curr[m] = n - i;

                int ans = 0;
                // If characters match, take the result from the next row's next column
                if(word1[i] == word2[j]) ans = next[j+1];
                else {
                    // Otherwise, calculate the costs of insertion, deletion, and replacement:
                    int insertAns = 1 + curr[j+1];    // Insert a character from word2 into word1
                    int deleteAns = 1 + next[j];      // Delete a character from word1
                    int replaceAns = 1 + next[j+1];  // Replace a character in word1 with word2

                    // Take the minimum of these three options
                    ans = min({insertAns, deleteAns, replaceAns});
                }

                // Store the result for the current cell in the current row
                curr[j] = ans;
            }
            // Update the next row to be the current row after finishing one iteration
            next = curr;
        }

        // The final result is stored in curr[0], which represents the minimum edit distance
        return curr[0];
    }

    // Main function to calculate the minimum edit distance between word1 and word2
    int minDistance(string word1, string word2) {
        // Edge case: if one of the strings is empty, the result is the length of the other string
        if(word1.length() == 0) return word2.length();
        if(word2.length() == 0) return word1.length();
        
        // Call the solve function to compute the result
        return solve(word1, word2);
    }
};
