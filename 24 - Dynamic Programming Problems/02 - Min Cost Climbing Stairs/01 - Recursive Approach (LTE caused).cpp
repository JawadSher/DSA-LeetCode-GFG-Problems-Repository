// Approach 1 : Starting from the Beginning of the Stairs
class Solution {
public:
    // Recursive function to calculate the minimum cost to climb stairs starting from index `i`
    int solve(vector<int>& cost, int i) {
        // Base case: If `i` exceeds the last index, there is no cost
        if (i >= cost.size()) return 0;

        // Recursive case: Add the cost at the current step and calculate the minimum cost
        // of taking either 1 or 2 steps from the current position
        return cost[i] + min(solve(cost, i + 1), solve(cost, i + 2));
    }

    // Function to calculate the minimum cost to reach the top starting from step 0 or step 1
    int minCostClimbingStairs(vector<int>& cost) {
        // Start climbing from step 0 or step 1, and take the minimum of the two
        return min(solve(cost, 0), solve(cost, 1));
    }
};


// Approach 2 : Starting from the End of the Stairs
class Solution {
public:
    // Recursive function to calculate the minimum cost to climb stairs starting from index `i`
    int solve(vector<int>& cost, int i) {
        // Base case: If `i` is 0, the cost is the cost of step 0
        if (i == 0) return cost[0];
        // Base case: If `i` is 1, the cost is the cost of step 1
        if (i == 1) return cost[1];

        // Recursive case: Add the cost at the current step and calculate the minimum cost
        // of coming from step `i-1` or step `i-2`
        return cost[i] + min(solve(cost, i - 1), solve(cost, i - 2));
    }

    // Function to calculate the minimum cost to reach the top starting from the last or second last step
    int minCostClimbingStairs(vector<int>& cost) {
        // Start climbing from the last step or the second last step, and take the minimum of the two
        return min(solve(cost, cost.size() - 1), solve(cost, cost.size() - 2));
    }
};

