class Solution {
public:
    // Function to calculate derangements using space-optimized approach
    int solve(int n) {
        // Base case: For n = 1, there are no valid derangements
        if (n == 1) return 0;

        // Base case: For n = 2, there is exactly one valid derangement
        if (n == 2) return 1;

        // Initialize variables to store results for the last two states
        // prev: D(n-2), curr: D(n-1)
        int prev = 0; // D(1)
        int curr = 1; // D(2)

        // Loop to calculate D(n) iteratively using the relation:
        // D(i) = (i-1) * (D(i-1) + D(i-2))
        for (int i = 3; i <= n; i++) {
            // Compute the next derangement value
            int next = (i - 1) * (curr + prev);

            // Update prev and curr for the next iteration
            prev = curr;
            curr = next;
        }

        // Return the result for D(n)
        return curr;
    }
    
    // Main function to calculate derangements
    int countDer(int n) {
        // Delegate the computation to the solve function
        return solve(n);    
    }
};
