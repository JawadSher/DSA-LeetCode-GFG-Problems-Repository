class Solution {
public:
    // Function to calculate the number of combinations using dynamic programming
    int solve(vector<int>& nums, int target) {
        // Edge case: If the target is negative or the input array is empty, return 0
        if(target < 0 || nums.empty()) return 0;

        // Create a DP array to store the number of ways to achieve each target sum
        vector<int> dp(target + 1, 0);

        // Base case: There's only one way to make a sum of 0 (choose nothing)
        dp[0] = 1;

        // Iterate over all possible target values from 1 to the given target
        for(int currentTarget = 1; currentTarget <= target; currentTarget++) {
            // Iterate through each number in the input array
            for(int numIndex = 0; numIndex < nums.size(); numIndex++) {
                // Check if the current number can contribute to the current target
                if(currentTarget - nums[numIndex] >= 0) {
                    // Handle potential integer overflow
                    if (dp[currentTarget] > INT_MAX - dp[currentTarget - nums[numIndex]]) {
                        dp[currentTarget] = INT_MAX; // Set to INT_MAX if overflow occurs
                    } else {
                        // Update dp[currentTarget] by adding the ways to achieve the reduced target
                        dp[currentTarget] += dp[currentTarget - nums[numIndex]];
                    }
                }
            }
        }

        // Return the number of combinations to make the target sum
        return dp[target];
    }

    // Main function to calculate the number of combinations
    int combinationSum4(vector<int>& nums, int target) {
        // Call the DP-based solve function
        return solve(nums, target);
    }
};
