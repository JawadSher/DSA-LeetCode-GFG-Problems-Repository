class Solution {
public:
    int numTrees(int n) {
        // Base case: If there are 0 or 1 nodes, there is only 1 unique BST possible.
        if(n <= 1) return 1;

        int ans = 0; // Initialize the variable to store the total number of unique BSTs.

        // Loop through each number i from 1 to n.
        // Treat 'i' as the root of the BST.
        for(int i = 1; i <= n; i++) {
            // Recursively calculate the number of unique BSTs for the left and right subtrees.
            // Left subtree has (i-1) nodes.
            // Right subtree has (n-i) nodes.
            ans += numTrees(i-1) * numTrees(n-i);
        }

        // Return the total count of unique BSTs for n nodes.
        return ans;
    }
};
