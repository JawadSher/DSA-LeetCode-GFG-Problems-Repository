class Solution {
public:
    // Recursive helper function to check if we can partition the array into two subsets
    int solve(vector<int>& nums, int index, int n, int target) {
        // Base case: If the index exceeds the array size, return 0 (no valid partition)
        if(index >= n) return 0;
        
        // If the target becomes negative, return 0 (not possible to partition)
        if(target < 0) return 0;
        
        // If the target becomes zero, it means we've found a valid partition (return 1)
        if(target == 0) return 1;

        // Option 1: Include the current element and try to partition with the reduced target
        int include = solve(nums, index+1, n, target - nums[index]);
        
        // Option 2: Exclude the current element and try to partition without changing the target
        int exclude = solve(nums, index+1, n, target - 0);

        // Return true if either including or excluding the current element leads to a valid partition
        return include or exclude;
    }

    // Main function to check if we can partition the array into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int total = 0;

        // Calculate the total sum of the elements in the array
        for(auto & num : nums) total += num;

        // If the total sum is odd, we cannot partition it into two equal subsets
        if(total & 1) return 0;

        // Set the target as half of the total sum
        int target = total / 2;

        // Call the solve function to check if we can find a subset that sums to 'target'
        return solve(nums, 0, nums.size(), target);
    }
};
