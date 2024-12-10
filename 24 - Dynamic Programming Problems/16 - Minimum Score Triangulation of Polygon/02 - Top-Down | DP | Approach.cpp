class Solution {
public:
    // Recursive function with memoization to calculate the minimum score for triangulating the polygon
    // Parameters:
    // - v: vector containing the values of the vertices
    // - i: starting index of the segment
    // - j: ending index of the segment
    // - dp: 2D vector to store previously computed results for subproblems
    int solve(vector<int>& v, int i, int j, vector<vector<int>>& dp) {
        // Base case: If the segment [i, j] has only two vertices, it cannot form a triangle
        if (i + 1 == j) return 0;

        // If the result for this subproblem is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX; // Initialize the answer to the maximum possible value

        // Iterate through all possible middle vertices (k) between i and j
        for (int k = i + 1; k < j; k++) {
            // Calculate the score of forming a triangle with vertices i, k, and j
            // Add the scores of solving the two subproblems [i, k] and [k, j]
            ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k, dp) + solve(v, k, j, dp));
        }

        // Store the computed result for the segment [i, j] in the dp table
        return dp[i][j] = ans;
    }

    // Function to calculate the minimum score triangulation of the polygon
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size(); // Number of vertices in the polygon

        // Initialize a dp table with -1 to indicate uncomputed results
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Call the recursive helper function on the entire polygon
        return solve(values, 0, n - 1, dp);
    }
};
