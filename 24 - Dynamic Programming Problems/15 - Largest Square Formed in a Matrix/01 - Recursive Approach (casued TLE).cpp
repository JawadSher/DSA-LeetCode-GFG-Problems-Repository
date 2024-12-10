// User function Template for C++
class Solution {
  public:
    // Recursive function to find the size of the largest square ending at (i, j)
    int solve(vector<vector<int>>& mat, int i, int j, int &maxi) {
        // Base condition: If out of bounds, return 0
        if (i >= mat.size() || j >= mat[0].size()) return 0;

        // Recursive calls to calculate the size of squares in three directions:
        int right = solve(mat, i, j + 1, maxi);       // Square ending to the right
        int diagnol = solve(mat, i + 1, j + 1, maxi); // Square ending diagonally
        int down = solve(mat, i + 1, j, maxi);        // Square ending below

        // If the current cell contains 1
        if (mat[i][j] == 1) {
            // Calculate the size of the square ending at (i, j)
            int ans = 1 + min(right, min(diagnol, down));
            
            // Update the maximum square size
            maxi = max(maxi, ans);
            return ans; // Return the size of the square at (i, j)
        }

        // If the current cell contains 0, it cannot form a square
        return 0;
    }

    // Main function to find the largest square submatrix with all 1s
    int maxSquare(vector<vector<int>>& mat) {
        int maxi = 0; // Variable to store the maximum square size
        solve(mat, 0, 0, maxi); // Start solving from the top-left corner
        return maxi; // Return the maximum square size
    }
};
