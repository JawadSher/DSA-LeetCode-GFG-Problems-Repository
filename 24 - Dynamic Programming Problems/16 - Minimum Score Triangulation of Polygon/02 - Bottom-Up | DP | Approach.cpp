class Solution {
public:
    // Function to calculate the minimum score triangulation of the polygon using bottom-up DP
    int solve(vector<int>& v) {
        int n = v.size(); // Number of vertices in the polygon

        // DP table where dp[i][j] represents the minimum score for triangulating the segment [i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over all possible starting indices in reverse (bottom-up DP)
        for (int i = n - 1; i >= 0; i--) {
            // Iterate over all possible ending indices for segments larger than 2 vertices
            for (int j = i + 2; j < n; j++) {
                int ans = INT_MAX; // Initialize the minimum score for the segment [i, j]

                // Try every possible middle vertex k between i and j
                for (int k = i + 1; k < j; k++) {
                    // Calculate the score of forming a triangle (i, k, j) and add subproblem scores
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }

                // Store the minimum score for the segment [i, j]
                dp[i][j] = ans;
            }
        }

        // The final result is stored in dp[0][n-1], which represents the entire polygon
        return dp[0][n - 1];
    }

    // Main function to calculate the minimum score triangulation
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); // Number of vertices in the polygon

        // Call the DP function
        return solve(values);
    }
};
