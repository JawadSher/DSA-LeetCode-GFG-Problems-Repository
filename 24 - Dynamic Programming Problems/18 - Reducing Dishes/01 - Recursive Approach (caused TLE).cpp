class Solution {
public:
    // Recursive function to solve the problem
    // satisfaction: vector containing satisfaction values
    // index: current index in the satisfaction array
    // time: current time multiplier for calculating the "like-time coefficient"
    int solve(vector<int>& satisfaction, int index, int time) {
        int n = satisfaction.size();

        // Base case: if we've processed all dishes, return 0
        if (index == n) return 0;

        // Option 1: Include the current dish
        // Add the "like-time coefficient" for the current dish and move to the next dish
        int include = satisfaction[index] * time + solve(satisfaction, index + 1, time + 1);

        // Option 2: Exclude the current dish
        // Skip the current dish and keep the same time multiplier
        int exclude = 0 + solve(satisfaction, index + 1, time);

        // Return the maximum of the two options
        return max(include, exclude);
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // This ensures we process the least satisfying dishes first, enabling us to skip them if needed
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Call the recursive function starting with index 0 and time 1
        return solve(satisfaction, 0, 1);
    }
};
