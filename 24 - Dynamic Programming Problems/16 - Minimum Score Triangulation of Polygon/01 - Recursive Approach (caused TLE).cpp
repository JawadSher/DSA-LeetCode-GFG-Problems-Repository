class Solution {
public:
    // Recursive function to calculate the minimum score for triangulating the polygon
    // Parameters:
    // - v: vector containing the values of the vertices
    // - i: starting index of the segment
    // - j: ending index of the segment
    int solve(vector<int>& v, int i, int j) {
        // Base case: If the segment [i, j] has only two vertices, it cannot form a triangle
        if (i + 1 == j) return 0;

        int ans = INT_MAX; // Initialize the answer to the maximum possible value

        // Iterate through all possible middle vertices (k) between i and j
        for (int k = i + 1; k < j; k++) {
            // Calculate the score of forming a triangle with vertices i, k, and j
            // Add the scores of solving the two subproblems [i, k] and [k, j]
            ans = min(ans, v[i] * v[k] * v[j] + solve(v, i, k) + solve(v, k, j));
        }

        return ans; // Return the minimum score for the segment [i, j]
    }

    // Function to calculate the minimum score triangulation of the polygon
    int minScoreTriangulation(vector<int>& values) {
        // Call the recursive helper function on the entire polygon
        return solve(values, 0, values.size() - 1);
    }
};
