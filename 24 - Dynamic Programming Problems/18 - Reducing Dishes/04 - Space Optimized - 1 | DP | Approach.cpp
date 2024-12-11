class Solution {
public:
    // Function to calculate the maximum "like-time coefficient"
    // satisfaction: vector containing satisfaction values of dishes
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Create two 1D DP arrays to store results of the current and next iterations
        // We use two arrays instead of a 2D table to optimize space
        vector<int> curr(n + 1, 0); // Current state
        vector<int> next(n + 1, 0); // Next state

        // Iterate over the satisfaction array in reverse order
        // satis represents the current index in the satisfaction array
        for (int satis = n - 1; satis >= 0; satis--) {
            // Iterate over possible time multipliers in reverse order
            for (int time = satis; time >= 0; time--) {
                // Option 1: Include the current dish
                // Add its contribution to the result, and increment the time multiplier
                int include = satisfaction[satis] * (time + 1) + next[time + 1];

                // Option 2: Exclude the current dish
                // Skip the current dish, keeping the same time multiplier
                int exclude = 0 + next[time];

                // Store the maximum of the two options in the current DP array
                curr[time] = max(include, exclude);
            }

            // Move the current state to the next state for the next iteration
            next = curr;
        }

        // Return the maximum value starting from index 0 with time multiplier 1
        return curr[0];
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting ensures that we process less satisfying dishes first
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Use the solve function to compute the result
        return solve(satisfaction);
    }
};
