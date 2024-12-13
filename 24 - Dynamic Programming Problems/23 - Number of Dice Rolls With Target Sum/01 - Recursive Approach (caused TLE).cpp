class Solution {
public:
    // Recursive function to calculate the number of ways to roll the dice to achieve the target
    long long solve(int dice, int faces, int target) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If no dice are left but the target is not zero, it's not a valid way
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is zero, it's also invalid
        if (target == 0 && dice != 0) return 0;

        // Base case: If no dice are left and the target is zero, it's a valid way
        if (dice == 0 && target == 0) return 1;

        // Initialize a variable to store the number of ways
        long long ans = 0;

        // Loop through all possible outcomes for a single dice roll
        for (int i = 1; i <= faces; i++) {
            // Recursively calculate the ways to achieve the remaining target
            // after rolling one die with the current face value `i`
            ans += solve(dice - 1, faces, target - i);
        }

        // Return the total number of ways
        return ans;
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper recursive function
        return solve(n, k, target);
    }
};
