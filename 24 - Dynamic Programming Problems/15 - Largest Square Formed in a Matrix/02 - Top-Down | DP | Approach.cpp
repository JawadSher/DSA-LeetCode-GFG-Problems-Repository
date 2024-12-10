// User function Template for C++
class Solution {
  public:
    // Recursive function with memoization to find the size of the largest square ending at (i, j)
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp) {
        // Base condition: If out of bounds, return 0
        if (i >= mat.size() || j >= mat[0].size()) return 0;

        // If the value is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];
        
        // If the current cell contains 0, it cannot form a square
        if (mat[i][j] == 0) return dp[i][j] = 0;

        // Recursive calls to calculate the size of squares in three directions:
        int right = solve(mat, i, j - 1, dp);         // Square ending to the left
        int diagnol = solve(mat, i - 1, j, dp);       // Square ending diagonally
        int down = solve(mat, i - 1, j - 1, dp);      // Square ending above

        // Store the size of the square ending at (i, j) in the dp table
        return dp[i][j] = 1 + min({right, diagnol, down});
    }

    // Main function to find the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        int n = mat.size();
        int m = mat[0].size();

        // Create a memoization table and initialize it with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Iterate through the matrix and calculate the largest square ending at each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxi = max(maxi, solve(mat, i, j, dp)); // Update the maximum square size
            }
        }

        return maxi; // Return the maximum square size
    }
};
