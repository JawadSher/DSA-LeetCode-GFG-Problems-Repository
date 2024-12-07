class Solution {
public:
    // Function to solve the problem using dynamic programming (bottom-up approach)
    // `money`: vector containing the amounts of money in each house
    // `n`: the number of houses
    int solve(vector<int>& money, int n) {
        // If there are no houses, return 0 (no money can be robbed)
        if (n == 0) return 0;
        
        // Create a DP array to store the maximum money that can be robbed up to each house
        // dp[i] will store the maximum money that can be robbed from house 0 to house i
        vector<int> dp(n, 0);

        // Base case: Only one house, so rob it
        dp[0] = money[0];

        // If there are at least two houses, calculate the maximum money from the first two houses
        if (n > 1) dp[1] = max(money[0], money[1]);

        // Loop through the remaining houses starting from the third house
        for (int i = 2; i < n; i++) {
            // Option 1: Rob this house (house i), and add the money from the house two steps before (dp[i-2])
            int include = dp[i - 2] + money[i];

            // Option 2: Skip this house (house i), and take the maximum money robbed from the previous house (dp[i-1])
            int exclude = dp[i - 1] + 0;

            // Store the maximum of the two options in dp[i]
            dp[i] = max(include, exclude);
        }

        // Return the maximum money that can be robbed up to the last house (dp[n-1])
        return dp[n - 1];
    }

    // Main function to start solving the problem
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses
        
        // Call the helper function to calculate the maximum money that can be robbed
        int maxMoney = solve(nums, n);

        // Return the result
        return maxMoney;
    }
};
