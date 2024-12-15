class Solution {
public:
    // Helper function to calculate the number of unique BSTs for 'n' nodes using memoization.
    int solve(int n, vector<int>& dp) {
        // Base case: If there are 0 or 1 nodes, there is only 1 unique BST possible.
        if(n <= 1) return 1;

        // Check if the result for 'n' is already computed and stored in dp.
        if(dp[n] != -1) return dp[n];

        int ans = 0; // Initialize the variable to store the total number of unique BSTs.

        // Loop through each number i from 1 to n.
        // Treat 'i' as the root of the BST.
        for(int i = 1; i <= n; i++) {
            // Recursively calculate the number of unique BSTs for the left and right subtrees.
            // Left subtree has (i-1) nodes.
            // Right subtree has (n-i) nodes.
            ans += solve(i-1, dp) * solve(n-i, dp);
        }

        // Store the computed result for 'n' in the dp array for future use.
        return dp[n] = ans;
    }

    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        // Create a dp array initialized with -1 to indicate uncomputed results.
        vector<int> dp(n+1, -1);

        // Call the helper function with the initial value of 'n' and the dp array.
        return solve(n, dp);
    }
};
