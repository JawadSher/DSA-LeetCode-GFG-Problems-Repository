class Solution {
public:
    // Constant to store the modulo value as the result can be large
    static const int MOD = 1e9 + 7;

    // Recursive function with memoization to calculate the number of ways
    long long solve(int dice, int faces, int target, vector<vector<long long>>& dp) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If no dice are left but the target is not zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is already zero, it's also invalid
        if (target == 0 && dice != 0) return 0;

        // Base case: If no dice are left and the target is zero, it's a valid way
        if (dice == 0 && target == 0) return 1;

        // If the current state has already been computed, return the stored result
        if (dp[dice][target] != -1) return dp[dice][target];

        // Initialize the number of ways for the current state
        long long ans = 0;

        // Loop through all possible outcomes for a single dice roll
        for (int i = 1; i <= faces; i++) {
            // Recursively calculate the ways for the remaining dice and updated target
            ans = (ans + solve(dice - 1, faces, target - i, dp)) % MOD;
        }

        // Store the result in the dp table and return it
        return dp[dice][target] = ans;
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Create a 2D dp table initialized with -1 to indicate uncomputed states
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));

        // Call the recursive helper function with the initial values
        return solve(n, k, target, dp);
    }
};
