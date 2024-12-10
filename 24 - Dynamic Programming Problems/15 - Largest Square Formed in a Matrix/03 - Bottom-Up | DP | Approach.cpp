// User function Template for C++
class Solution {
  public:
    // Function to solve the problem using the bottom-up DP approach
    int solve(vector<vector<int>>& mat, int& maxi) {
        // Edge case: If the input matrix is empty, return 0
        if (mat.empty()) return 0;
        
        // Dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();
        
        // DP table to store the size of the largest square ending at each cell
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Extra row and column for boundary conditions
        
        // Iterate through the matrix in reverse (bottom to top, right to left)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Get values from adjacent cells in the DP table
                int right = dp[i][j + 1];       // Cell to the right
                int diagnol = dp[i + 1][j + 1]; // Diagonal cell
                int down = dp[i + 1][j];        // Cell below

                // If the current cell contains 1, calculate the size of the square ending here
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({right, diagnol, down}); // Add 1 to the smallest adjacent square
                    maxi = max(maxi, dp[i][j]);                // Update the maximum square size
                } else {
                    dp[i][j] = 0; // If the cell contains 0, it cannot form a square
                }
            }
        }
        
        return dp[0][0]; // This value is not used but returned for compatibility
    }

    // Main function to find the size of the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        solve(mat, maxi); // Compute the largest square using the solve function
        return maxi; // Return the maximum square size
    }
};
