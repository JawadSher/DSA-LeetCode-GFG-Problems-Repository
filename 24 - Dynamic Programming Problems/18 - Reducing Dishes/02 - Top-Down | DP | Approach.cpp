class Solution {
public:
    // Recursive function to calculate the maximum "like-time coefficient"
    // satisfaction: vector containing satisfaction values
    // index: current index in the satisfaction array
    // time: current time multiplier for calculating the "like-time coefficient"
    // dp: memoization table to store intermediate results
    int solve(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {
        int n = satisfaction.size();

        // Base case: If all dishes have been considered, return 0
        if (index == n) return 0;

        // Check if the result for this state is already computed
        if (dp[index][time] != -1) return dp[index][time];

        // Option 1: Include the current dish in the calculation
        // Add its contribution and move to the next dish with incremented time
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1, dp);

        // Option 2: Exclude the current dish from the calculation
        // Move to the next dish without incrementing the time
        int exclude = 0 + solve(satisfaction, index + 1, time, dp);

        // Store the maximum result in the memoization table
        dp[index][time] = max(include, exclude);

        // Return the result for the current state
        return dp[index][time];
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting helps to efficiently decide whether to include or exclude
        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();

        // Step 2: Create a memoization table initialized to -1
        // dp[i][j] represents the maximum "like-time coefficient" starting from index i with time j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Step 3: Call the recursive function starting with index 0 and time 1
        return solve(satisfaction, 0, 1, dp);
    }
};
