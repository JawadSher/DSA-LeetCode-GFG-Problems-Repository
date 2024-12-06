// Approach 1 : Using recursion with an index (i)
class Solution {
public:
    // Function to calculate the number of ways to reach the top of the stairs starting from index `i`
    int calculateWays(int n, int currentStep) {
        // Base case: If we are at the top step (i == n), there's exactly one way to reach the top
        if (currentStep == n) return 1;
        
        // Base case: If we've exceeded the top step (i > n), return 0 as this path is invalid
        if (currentStep > n) return 0;

        // Recursively calculate the number of ways to reach the top by taking either 1 step or 2 steps at a time
        return calculateWays(n, currentStep + 1) + calculateWays(n, currentStep + 2);
    }

    // Main function to start the process of calculating the ways to climb to the top
    int countWays(int n) {
        int currentStep = 0; // Start from the first step
        return calculateWays(n, currentStep); // Call the recursive function
    }
};

// Approach 2 : Using recursion with step subtraction (n)
class Solution {
public:
    // Function to calculate the number of ways to reach the top from step `n`
    int calculateWays(int n) {
        // Base case: If we're already at the top (n == 0), there's exactly one way to reach the top (no steps to take)
        if (n == 0) return 1;
        
        // Base case: If `n` is negative, it's an invalid path, return 0
        if (n < 0) return 0;

        // Recursively calculate the number of ways to reach the top by subtracting either 1 step or 2 steps
        return calculateWays(n - 1) + calculateWays(n - 2);
    }

    // Main function to start the process of calculating the ways to climb to the top
    int countWays(int n) {
        return calculateWays(n); // Call the recursive function to calculate the number of ways
    }
};
