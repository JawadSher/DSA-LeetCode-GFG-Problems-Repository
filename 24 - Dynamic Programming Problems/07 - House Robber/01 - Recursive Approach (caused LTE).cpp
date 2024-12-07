// Approach 1: Recursion with Index Tracking
// In this approach, we use a helper function that tries to rob each house starting from index `i`.
// We have two choices: either rob the current house (skip the next house), or skip the current house
// and consider the next one. The solution is based on comparing both options at each step recursively.
class Solution {
public:
    // Function to solve the problem recursively by tracking the current index `i` and total number of houses `n`
    int solve(vector<int>& money, int i, int n) {
        // Base cases: if we exceed the house index range, return 0 (no money left to rob)
        if (i > n) return 0;
        
        // If we reach the last house, return the money at the current index
        if (i == n) return money[i];

        // Option 1: Rob this house and skip the next one (i+2)
        int include = solve(money, i + 2, n) + money[i];

        // Option 2: Skip this house and move to the next one (i+1)
        int exclude = solve(money, i + 1, n) + 0;

        // Return the maximum of both choices (rob this house or skip it)
        return max(include, exclude);
    }

    // Main function to initiate the recursion and find the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Call the helper function starting from the first house (index 0)
        int maxMoney = solve(nums, 0, n - 1);

        // Return the maximum money that can be robbed
        return maxMoney;
    }
};


// Approach 2: Recursion with Index Backtracking
// In this approach, we start from the last house and recursively decide whether to rob this house or not.
// We backtrack to the previous house and calculate the total money robbed based on whether we include or exclude the current house.
class Solution {
public:
    // Function to solve the problem recursively by considering houses starting from the last index `n`
    int solve(vector<int>& money, int n) {
        // Base cases: if index `n` is out of bounds, return 0
        if (n < 0) return 0;
        
        // If we are at the first house, return the amount of money in the first house
        if (n == 0) return money[0];

        // Option 1: Rob this house and skip the next one (n-2)
        int include = solve(money, n - 2) + money[n];

        // Option 2: Skip this house and move to the previous one (n-1)
        int exclude = solve(money, n - 1) + 0;

        // Return the maximum of both choices (rob this house or skip it)
        return max(include, exclude);
    }

    // Main function to initiate the recursion and find the maximum money that can be robbed
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Call the helper function starting from the last house (index n-1)
        int maxMoney = solve(nums, n - 1);

        // Return the maximum money that can be robbed
        return maxMoney;
    }
};


