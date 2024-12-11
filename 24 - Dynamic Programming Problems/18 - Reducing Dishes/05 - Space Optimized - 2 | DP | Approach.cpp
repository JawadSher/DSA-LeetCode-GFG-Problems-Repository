class Solution {
public:
    // Function to calculate the maximum "like-time coefficient"
    // satisfaction: vector containing satisfaction values of dishes
    int solve(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Variables to keep track of the results
        int maxSatisfaction = 0;  // Maximum satisfaction achieved so far
        int cumulativeSum = 0;    // Running sum of satisfaction values
        int runningTotal = 0;     // Current "like-time coefficient"

        // Traverse the satisfaction array in reverse order
        // This ensures we consider the most satisfying dishes last
        for (int i = n - 1; i >= 0; i--) {
            cumulativeSum += satisfaction[i];  // Add current satisfaction value to the cumulative sum
            runningTotal += cumulativeSum;     // Update the running total with the new cumulative sum

            // Update the maximum satisfaction if the current running total is greater
            if (runningTotal > maxSatisfaction) 
                maxSatisfaction = runningTotal;
            else 
                break;  // Stop processing if adding more dishes reduces the total
        }

        // Return the maximum satisfaction found
        return maxSatisfaction;
    }

    // Main function to calculate the maximum "like-time coefficient"
    int maxSatisfaction(vector<int>& satisfaction) {
        // Step 1: Sort the satisfaction array in ascending order
        // Sorting ensures we can efficiently process from least to most satisfying
        sort(satisfaction.begin(), satisfaction.end());

        // Step 2: Use the solve function to compute the result
        return solve(satisfaction);
    }
};
