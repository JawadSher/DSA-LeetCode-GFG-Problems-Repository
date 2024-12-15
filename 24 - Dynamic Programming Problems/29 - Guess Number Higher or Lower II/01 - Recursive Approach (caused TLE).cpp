class Solution {
public:
    // Function to calculate the minimum amount of money needed to guarantee a win
    // in the range [start, end].
    int solve(int start, int end) {
        // Base case: If the start is greater than or equal to end, no money is needed.
        if (start >= end) return 0;

        // Initialize maxi to a very large value to store the minimum amount of money.
        int maxi = INT_MAX;

        // Try every number i in the range [start, end] as a possible guess.
        for (int i = start; i <= end; i++) {
            // Calculate the cost of choosing i as the guess:
            // - i is the cost of guessing i.
            // - The two ranges are [start, i-1] and [i+1, end].
            // Take the maximum of the two subranges since we want to ensure the worst-case scenario.
            maxi = min(maxi, i + max(solve(start, i - 1), solve(i + 1, end)));
        }

        // Return the minimum money needed to guarantee a win for the range [start, end].
        return maxi;
    }
    
    // Wrapper function to start the process with the full range [1, n].
    int getMoneyAmount(int n) {
        // Start solving from range [1, n]
        return solve(1, n);
    }
};
