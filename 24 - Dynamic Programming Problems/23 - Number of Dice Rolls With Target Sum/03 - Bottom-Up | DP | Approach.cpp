class Solution {
public:
    // Constant to store the modulo value as the result can be large
    static const int MOD = 1e9 + 7;

    // Function to calculate the number of ways to roll dice to achieve the target using bottom-up DP
    long long solve(int dice, int faces, int target) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If there are no dice but the target is non-zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is already zero, it's also invalid
        if (target == 0 && dice != 0) return 0;

        // Create a 2D DP table where dp[d][t] represents the number of ways to achieve
        // the target `t` using `d` dice
        vector<vector<long long>> dp(dice + 1, vector<long long>(target + 1, 0));

        // Initialize the base case: There is exactly one way to achieve a target of 0 with 0 dice
        dp[0][0] = 1;

        // Iterate over the number of dice
        for (int d = 1; d <= dice; d++) {
            // Iterate over the target values
            for (int t = 1; t <= target; t++) {
                long long ans = 0;

                // Consider each face value from 1 to `faces`
                for (int f = 1; f <= faces; f++) {
                    // If the current target `t` is greater than or equal to the face value `f`,
                    // add the number of ways to achieve the remaining target (t-f) with one less die
                    if (t - f >= 0) 
                        ans = (ans + dp[d - 1][t - f]) % MOD;
                }

                // Update the DP table for the current number of dice and target
                dp[d][t] = ans;
            }
        }

        // Return the number of ways to achieve the target with the given number of dice
        return dp[dice][target];
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper function to solve the problem using bottom-up DP
        return solve(n, k, target);
    }
};
