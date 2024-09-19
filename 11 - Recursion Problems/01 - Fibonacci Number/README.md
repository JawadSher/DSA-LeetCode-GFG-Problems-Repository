<h1 align='center'>Fibonacci - Number</h1>

## Problem Statement

**Problem URL :** [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)

![image](https://github.com/user-attachments/assets/8fd0c5b7-7dc2-4d98-b09e-7df1ad711352)

## Problem Solution
```cpp
class Solution {
public:
    int fib(int n) {
        // base case
        if(n == 0) return 0;
        if(n == 1) return 1;

        int ans = fib(n-1) + fib(n-2);
        return ans;
    }
};
```

## Problem Solution Explanation
Sure! Let's break down the `fib` function and explore its recursion tree and function call stack.

### Explanation of the `fib` Function

The function `fib` is designed to compute the nth Fibonacci number using recursion. Here's a step-by-step explanation:

1. **Base Cases**:
   - If `n` is 0, the function returns 0.
   - If `n` is 1, the function returns 1.
   These are the two base cases of the Fibonacci sequence.

2. **Recursive Case**:
   - For `n > 1`, the function calculates the Fibonacci number by recursively calling itself:
     ```cpp
     int ans = fib(n-1) + fib(n-2);
     ```
   - This means that `fib(n)` is the sum of `fib(n-1)` and `fib(n-2)`.

### Function Call Stack

The function call stack for `fib(4)` would look like this:

1. **Initial Call**: `fib(4)`
   - Calls `fib(3)` and `fib(2)`

2. **Call to `fib(3)`**:
   - Calls `fib(2)` and `fib(1)`

3. **Call to `fib(2)` (from `fib(3)`)**:
   - Calls `fib(1)` and `fib(0)`

4. **Call to `fib(1)`**: 
   - Returns 1

5. **Call to `fib(0)`**:
   - Returns 0

6. **Call to `fib(2)` (from `fib(4)`)**:
   - Calls `fib(1)` and `fib(0)`

7. **Call to `fib(1)`**:
   - Returns 1

8. **Call to `fib(0)`**:
   - Returns 0

Each recursive call adds a new frame to the call stack until the base cases are reached.

### Recursion Tree

The recursion tree visualizes how the function `fib` calls itself. Here's a simplified version of the recursion tree for `fib(4)`:

```
              fib(4)
           /        \
        fib(3)     fib(2)
       /      \    /      \
   fib(2)   fib(1) fib(1) fib(0)
   /     \
fib(1) fib(0)
```

### Explanation of the Tree

1. `fib(4)` calls `fib(3)` and `fib(2)`.
2. `fib(3)` calls `fib(2)` and `fib(1)`.
3. `fib(2)` calls `fib(1)` and `fib(0)`.
4. `fib(1)` and `fib(0)` are base cases and return immediately.

### Visualizing the Function Call Stack and Recursion Tree

Let's visualize this in a more graphical way.

1. **Recursion Tree**:
   ```
   fib(4)
   ├── fib(3)
   │   ├── fib(2)
   │   │   ├── fib(1)
   │   │   └── fib(0)
   │   └── fib(1)
   └── fib(2)
       ├── fib(1)
       └── fib(0)
   ```

2. **Call Stack for `fib(4)`**:
   - `fib(4)` calls `fib(3)` and `fib(2)`.
   - `fib(3)` calls `fib(2)` and `fib(1)`.
   - `fib(2)` calls `fib(1)` and `fib(0)`.

   As the recursion goes deeper, the stack grows and once a base case is reached, the stack starts unwinding, returning values back up to the initial call.

This approach to solving Fibonacci is simple but can be inefficient for large `n` due to its exponential time complexity. Each call to `fib(n)` generates two more calls, leading to a lot of repeated calculations. An iterative approach or memoization can significantly improve efficiency.
