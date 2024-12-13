class Solution {
public:
    // Function to check if a subset sum equal to 'target' exists using dynamic programming with space optimization
    int solve(vector<int>& nums, int n, int target) {
        // Arrays to store the current and next row of the dp table
        vector<int> curr(target+1, 0);   // To store the result for the current index
        vector<int> next(target+1, 0);   // To store the result for the next index (used in the transition)

        // Base case: sum of 0 can always be formed (empty subset)
        curr[0] = 1;
        next[0] = 1;

        // Iterate over all indices of nums in reverse (from n-1 to 0)
        for(int index = n-1; index >= 0; index--) {
            // Iterate over all possible target sums from 1 to the desired target sum
            for(int t = 1; t <= target; t++) {
                int include = 0;
                // If the current number can be included (i.e., target - nums[index] >= 0)
                if(t - nums[index] >= 0) include = next[t - nums[index]];

                // Exclude the current element (i.e., use the result from the next index with the same target)
                int exclude = next[t];

                // The result for curr[t] is the logical OR of including or excluding the element
                curr[t] = include or exclude;
            }

            // Move the current row to the next row for the next iteration
            next = curr;
        }

        // The final result is stored in next[target], which tells if the target sum can be achieved
        return next[target];
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, it can't be partitioned into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Call the solve function to check if a subset with sum equal to 'target' exists
        return solve(nums, n, target);
    }
};
