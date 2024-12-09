class Solution {
public:
    // Recursive function to calculate the number of combinations
    int solve(vector<int>& nums, int target) {
        // Base case: If the target becomes negative, no valid combination is possible
        if(target < 0) return 0;

        // Base case: If the target becomes zero, one valid combination is found
        if(target == 0) return 1;

        // Initialize a variable to store the number of valid combinations
        int ans = 0;

        // Iterate through each number in the array
        for(int i = 0; i < nums.size(); i++) {
            // Recursively reduce the target by the current number and add the result
            ans += solve(nums, target - nums[i]);
        }

        // Return the total number of valid combinations for the current target
        return ans;
    }

    // Main function to calculate the number of combinations for a given target
    int combinationSum4(vector<int>& nums, int target) {
        // Call the recursive function to solve the problem
        return solve(nums, target);
    }
};
