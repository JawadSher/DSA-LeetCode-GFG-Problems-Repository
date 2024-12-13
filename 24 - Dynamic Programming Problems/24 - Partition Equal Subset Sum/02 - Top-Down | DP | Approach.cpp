class Solution {
public:
    // Recursive function with memoization to check if a subset sum equals the target
    int solve(vector<int>& nums, int index, int n, int target, vector<vector<int>> &dp) {
        // Base case: If we've processed all elements and haven't reached the target, return 0
        if(index >= n) return 0;
        
        // If the target becomes negative, return 0 (we can't have a negative sum)
        if(target < 0) return 0;
        
        // If the target becomes zero, it means we've found a subset whose sum equals the target
        if(target == 0) return 1;

        // Check if the result for this subproblem has already been computed
        if(dp[index][target] != -1) return dp[index][target];

        // Option 1: Include the current element (nums[index]) in the subset and reduce the target
        int include = solve(nums, index + 1, n, target - nums[index], dp);
        
        // Option 2: Exclude the current element and try the next index with the same target
        int exclude = solve(nums, index + 1, n, target, dp);

        // Memoize the result for the current index and target
        return dp[index][target] = include or exclude;  // Use logical OR to check if either option works
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, return false because it can't be partitioned into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Create a memoization table to store results for subproblems
        // dp[i][j] will store whether it's possible to form sum 'j' using the first 'i' elements
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        // Call the recursive function to check if a subset sum equal to 'target' exists
        return solve(nums, 0, n, target, dp);
    }
};
