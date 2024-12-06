class Solution {
public:
    // Function to calculate the number of ways to climb `n` stairs using optimized space
    int climbStairs(int n) {
        // Base cases: there's one way to stay at the 0th step (prev1) and one way to reach the 1st step (prev2)
        int prev1 = 1;  // Represents the number of ways to reach the step (i-1)
        int prev2 = 1;  // Represents the number of ways to reach the step (i-2)

        // Iterate from step 2 to step n, calculating the number of ways to reach each step
        for(int i = 2; i <= n; i++) {
            // The number of ways to reach step i is the sum of the ways to reach step (i-1) and step (i-2)
            int curr = prev1 + prev2;

            // Update prev2 to prev1 (step (i-2) becomes the previous step)
            prev2 = prev1;

            // Update prev1 to curr (step (i-1) becomes the current step)
            prev1 = curr;
        }

        // Return the number of ways to reach the nth step
        return prev1;
    }
};
