class Solution {
public:
    // Function to calculate the nth Catalan number using a mathematical formula.
    int solve(int n) {
        // Initialize a variable to store the computed Catalan number.
        // Using 'long long' to handle intermediate results that might exceed int limits.
        long long catalan = 1;

        // Compute the value of (2n)! / n! in a loop.
        // This is a part of the Catalan number formula: C(n) = (2n)! / ((n+1)! * n!).
        for (int i = 0; i < n; i++) {
            // Update 'catalan' using the current term of the formula.
            // Multiply by (2n - i) and divide by (i + 1) iteratively.
            catalan = catalan * (2 * n - i) / (i + 1);
        }

        // Divide the computed value by (n + 1) to complete the Catalan number calculation.
        return catalan / (n + 1);
    }

    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        // Call the helper function 'solve' to compute the nth Catalan number.
        return solve(n);
    }
};
