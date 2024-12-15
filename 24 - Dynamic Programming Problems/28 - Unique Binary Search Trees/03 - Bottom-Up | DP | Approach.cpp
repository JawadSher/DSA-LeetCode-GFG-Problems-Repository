class Solution {
public:
    // Function to calculate the number of unique BSTs for 'n' nodes using a bottom-up approach.
    int solve(int n) {
        // Create a dp array of size (n+1) to store the results for subproblems.
        // dp[i] will hold the number of unique BSTs that can be formed with 'i' nodes.
        vector<int> dp(n+1, 0);

        // Base cases:
        // When there are 0 nodes, there is 1 unique BST (an empty tree).
        // When there is 1 node, there is 1 unique BST (the single node as the root).
        dp[0] = dp[1] = 1;

        // Fill the dp array for all values from 2 to n (Bottom-Up approach).
        for (int i = 2; i <= n; i++) {
            // Calculate the number of unique BSTs for 'i' nodes.
            for (int j = 1; j <= i; j++) {
                // Treat 'j' as the root node.
                // The left subtree has (j-1) nodes.
                // The right subtree has (i-j) nodes.
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        // Return the result for 'n' nodes.
        return dp[n];
    }

    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        return solve(n); // Call the helper function with the input 'n'.
    }
};
