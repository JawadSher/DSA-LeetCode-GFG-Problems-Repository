class Solution {
public:
    // Function to calculate the minimum cost to climb the stairs using optimized tabulation
    int solve(vector<int>& cost, int n) {
        // Step 1: Initialize two variables to store the minimum cost for the previous two steps
        int i_1 = cost[1];  // Represents the cost to reach the first step (index 1)
        int i_2 = cost[0];  // Represents the cost to reach the second step (index 0)

        // Step 2: Iterate through the cost array starting from the third step (index 2)
        for (int i = 2; i < n; i++) {
            // The minimum cost to reach the current step is the cost at this step plus the minimum
            // of the costs from the two previous steps (i-1 and i-2)
            int curr = cost[i] + min(i_1, i_2);
            
            // Update the variables for the next iteration
            i_2 = i_1;  // Move the previous step to i_2
            i_1 = curr;  // Set the current minimum cost as i_1
        }

        // Step 3: The minimum cost to reach the top is the minimum of the last two steps
        return min(i_1, i_2);
    }

    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        // Call the `solve` function with the cost array and its size
        return solve(cost, cost.size());
    }
};
