// User function Template for C++
class Solution {
  public:
    // Function to compute the largest square submatrix with all 1s using in-place modification
    int solve(vector<vector<int>>& mat) {
        // Edge case: If the matrix is empty, return 0
        if (mat.empty()) return 0;

        // Dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();

        // Variable to store the size of the largest square
        int maxi = 0;

        // Traverse the matrix from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // If the cell is in the last row or last column, no need to modify its value
                if (i == n - 1 || j == m - 1) {
                    maxi = max(maxi, mat[i][j]); // Update `maxi` if the cell contains `1`
                } else if (mat[i][j] == 1) {
                    // If the current cell contains `1`, calculate the size of the square
                    mat[i][j] = 1 + min({mat[i + 1][j], mat[i][j + 1], mat[i + 1][j + 1]});
                    maxi = max(maxi, mat[i][j]); // Update `maxi` if the square size increases
                }
            }
        }

        return maxi; // Return the size of the largest square
    }

    // Main function to find the size of the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        return solve(mat); // Call the solve function
    }
};
