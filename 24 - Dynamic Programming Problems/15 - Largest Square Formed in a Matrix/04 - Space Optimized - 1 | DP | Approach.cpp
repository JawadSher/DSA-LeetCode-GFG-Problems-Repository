// User function Template for C++
class Solution {
  public:
    // Function to compute the largest square submatrix with all 1s using space optimization
    int solve(vector<vector<int>>& mat, int& maxi) {
        // Edge case: If the matrix is empty, return 0
        if (mat.empty()) return 0;
        
        // Dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();
        
        // Two 1D vectors to store the current and next rows of the DP table
        vector<int> curr(m + 1, 0); // Current row
        vector<int> next(m + 1, 0); // Next row
        
        // Iterate through the matrix in reverse (bottom to top, right to left)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // Fetch values from the next row and the current row (for right, diagonal, and down)
                int right = curr[j + 1];       // Cell to the right
                int diagnol = next[j + 1];    // Diagonal cell
                int down = next[j];           // Cell below
                
                // If the current cell contains 1, calculate the size of the square ending here
                if (mat[i][j] == 1) {
                    curr[j] = 1 + min({right, diagnol, down}); // Add 1 to the smallest adjacent square
                    maxi = max(maxi, curr[j]);                // Update the maximum square size
                } else {
                    curr[j] = 0; // If the cell contains 0, it cannot form a square
                }
            }
            
            // Update the `next` row to the current row for the next iteration
            next = curr;
        }
        
        return next[0]; // This value is not used but returned for compatibility
    }

    // Main function to find the size of the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        solve(mat, maxi); // Compute the largest square using the solve function
        return maxi; // Return the maximum square size
    }
};
