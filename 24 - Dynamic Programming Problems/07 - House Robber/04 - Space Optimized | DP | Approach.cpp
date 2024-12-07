class Solution {
public:
    // Function to solve the problem using dynamic programming (optimized space approach)
    // `money`: vector containing the amounts of money in each house
    // `n`: the number of houses
    int solve(vector<int>& money, int n) {
        // Base cases:
        // prev2 represents the maximum money robbed from houses up to index 0
        // prev1 represents the maximum money robbed from houses up to index 1
        int prev2 = money[0];  // Only one house, so rob it
        int prev1 = max(money[0], money[1]);  // Take the maximum of robbing the first or second house

        // Iterate through the remaining houses starting from index 2
        for (int i = 2; i < n; i++) {
            // Option 1: Rob the current house (house i), and add money from house i to the result of robbing house i-2 (prev2)
            int include = prev2 + money[i];

            // Option 2: Skip the current house (house i), and keep the maximum from the previous house (prev1)
            int exclude = prev1 + 0;

            // Calculate the maximum money we can rob up to house i by choosing either to include or exclude house i
            int current = max(include, exclude);

            // Update prev2 and prev1 for the next iteration
            prev2 = prev1;  // Move prev1 to prev2 (we are shifting one step to the right)
            prev1 = current;  // Update prev1 to be the maximum of robbing up to house i
        }

        // After iterating through all houses, prev1 will hold the maximum money that can be robbed
        return prev1;
    }

    // Main function to start solving the problem
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses

        // Handle edge cases where there are no houses or only one house
        if (n == 0) return 0; // No houses to rob
        if (n == 1) return nums[0]; // Only one house to rob, return its value

        // Call the helper function to calculate the maximum money that can be robbed
        return solve(nums, n);
    }
};
