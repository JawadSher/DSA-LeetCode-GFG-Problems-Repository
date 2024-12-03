class Solution {
  public:
    int nthFibonacci(int n) {
        // Base case: If n is 0, return 0 (F(0) = 0)
        if (n == 0) 
            return 0;

        // Base case: If n is 1, return 1 (F(1) = 1)
        if (n == 1) 
            return 1;

        // Initialize the first two Fibonacci numbers
        int a = 0; // F(0)
        int b = 1; // F(1)

        // Variable to store the current Fibonacci number
        int m = 0;

        // Loop from 2 to n to calculate the nth Fibonacci number iteratively
        for (int i = 2; i <= n; i++) {
            // The nth Fibonacci number is the sum of the previous two numbers
            m = a + b;

            // Update a and b for the next iteration
            a = b; // Move to the next value in the sequence
            b = m; // Current Fibonacci number becomes the next "b"
        }

        // Return the nth Fibonacci number
        return m;
    }
};
