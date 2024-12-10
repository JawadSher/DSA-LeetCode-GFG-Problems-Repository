class Solution {
public:
    // Gap Strategy Implementation for Minimum Score Triangulation
    int solve(vector<int>& v) {
        int n = v.size(); // Number of vertices in the polygon

        // DP table where dp[i][j] represents the minimum score for triangulating the segment [i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Outer loop controls the gap between i and j
        // Gap of 2 means the segment [i, j] has at least 3 vertices, enough to form a triangle
        for (int gap = 2; gap < n; gap++) {
            // Inner loop iterates over all valid starting indices i for a given gap
            for (int i = 0; i + gap < n; i++) {
                int j = i + gap; // Calculate the ending index j based on the gap

                dp[i][j] = INT_MAX; // Initialize dp[i][j] to the maximum value

                // Iterate over all possible middle vertices (k) between i and j
                for (int k = i + 1; k < j; k++) {
                    // Calculate the score of forming a triangle (i, k, j)
                    // Add the scores of solving the two subproblems [i, k] and [k, j]
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
                }
            }
        }

        // The final result is stored in dp[0][n-1], which represents the entire polygon
        return dp[0][n - 1];
    }

    // Main function to calculate the minimum score triangulation
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); // Number of vertices in the polygon
        return solve(values); // Call the gap strategy function
    }
};
