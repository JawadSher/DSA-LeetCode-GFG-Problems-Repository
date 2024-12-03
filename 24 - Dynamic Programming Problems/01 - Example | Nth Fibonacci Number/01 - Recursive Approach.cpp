class Solution {
  public:
    int nthFibonacci(int n) {
        // Base case: If n is 0 or 1, return n directly.
        // F(0) = 0 and F(1) = 1 are the first two terms of the Fibonacci sequence.
        if (n == 0 || n == 1) 
            return n;

        // Recursive case:
        // The nth Fibonacci number is the sum of the (n-1)th and (n-2)th Fibonacci numbers.
        // Recursively calculate the values for smaller subproblems.
        return nthFibonacci(n - 1) + nthFibonacci(n - 2);
    }
};
