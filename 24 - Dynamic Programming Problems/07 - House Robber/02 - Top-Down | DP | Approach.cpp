class Solution {
public:
    // Function to solve the problem recursively with memoization
    // `money`: vector of amounts of money in each house
    // `n`: the current house index
    // `dp`: memoization array to store the maximum money for each house index
    int solve(vector<int>& money, int n, vector<int>& dp) {
        // Base case: if the index `n` is less than 0, return 0 (no money left to rob)
        if (n < 0) return 0;

        // Base case: if we are at the first house (index 0), return the money at this house
        if (n == 0) return money[0];

        // If the result for this index `n` has already been calculated, return it from the `dp` array
        if (dp[n] != -1) return dp[n];

        // Option 1: Rob this house, so skip the next one (move to house `n-2`)
        int include = solve(money, n - 2, dp) + money[n];

        // Option 2: Skip this house, so move to the next house (house `n-1`)
        int exclude = solve(money, n - 1, dp) + 0;

        // Store the maximum of both choices in the memoization array `dp[n]`
        dp[n] = max(include, exclude);

        // Return the maximum money that can be robbed up to house `n`
        return dp[n];
    }

    // Main function to calculate the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size(); // Get the number of houses

        // Initialize the dp array with -1 (indicating uncalculated values)
        // dp[i] will store the maximum money that can be robbed from house 0 to house i
        vector<int> dp(n + 1, -1);

        // Call the helper function starting from the last house (index n-1)
        int maxMoney = solve(nums, n - 1, dp);

        // Return the maximum money that can be robbed
        return maxMoney;
    }
};
