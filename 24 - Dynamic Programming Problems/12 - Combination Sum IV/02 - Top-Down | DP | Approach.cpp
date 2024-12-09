class Solution {
public:
    // Recursive function to calculate the number of combinations with memoization
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        // Base case: If the target becomes negative, no valid combination is possible
        if(target < 0) return 0;

        // Base case: If the target becomes zero, one valid combination is found
        if(target == 0) return 1;

        // If the result for the current target has already been calculated, return it
        if(dp[target] != -1) return dp[target];

        // Initialize a variable to store the number of valid combinations for the current target
        int ans = 0;

        // Iterate through each number in the array
        for(int i = 0; i < nums.size(); i++) {
            // Recursively calculate combinations for the reduced target
            ans += solve(nums, target - nums[i], dp);
        }

        // Store the calculated result in the memoization table
        dp[target] = ans;

        // Return the result for the current target
        return dp[target];
    }

    // Main function to calculate the number of combinations for a given target
    int combinationSum4(vector<int>& nums, int target) {
        // Initialize a memoization table with -1 (uncomputed state)
        vector<int> dp(target + 1, -1);

        // Call the recursive function to solve the problem with memoization
        return solve(nums, target, dp);
    }
};
