class Solution {
public:
    // Recursive function to calculate the minimum number of perfect squares 
    int solve(int n){
        // Base case: If n is 0, no numbers are needed to sum to 0.
        if(n == 0) return 0;

        // Initialize ans with a large number. We'll try to minimize this value.
        int ans = INT_MAX;

        // Loop through all possible perfect squares less than or equal to n
        for(int i = 1; i * i <= n; i++) {
            // Recursively calculate the minimum number of perfect squares for the remaining value
            // After subtracting the current perfect square (i * i) from n
            ans = min(ans, solve(n - i*i) + 1);
        }

        // Return the minimum number of perfect squares for the given n
        return ans;
    }

    // Main function to call the solve function and return the result for the input n
    int numSquares(int n) {
        return solve(n);
    }
};
