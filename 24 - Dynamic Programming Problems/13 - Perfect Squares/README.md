<h1 align="center">Perfect - Squares</h1>

## Problem Statement

**Problem URL (Leetcode) :** [Perfect Sqaures](https://leetcode.com/problems/perfect-squares/description/)

**Problem URL (GFG) :** [Get Minimum Sqaures](https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1)

![image](https://github.com/user-attachments/assets/39c2a259-49fb-48d4-b7f8-41ac749eac88)


### Problem Explanation
The **Perfect Squares** problem on LeetCode asks you to find the **least number of perfect squares** that sum up to a given number (n).

Given a positive integer (n), you need to determine the minimum number of perfect square numbers (like 1, 4, 9, 16, 25, ...) that sum up to (n).

### Perfect Square:
A **perfect square** is a number that is the square of an integer. For example:
- 1 is a perfect square because (1 = 1^2).
- 4 is a perfect square because (4 = 2^2).
- 9 is a perfect square because (9 = 3^2).

The goal is to find the **minimum number of perfect squares** that sum up to the target number (n).

### Problem Approach:
We can solve this problem using **Dynamic Programming (DP)** to break the problem into smaller subproblems.

The idea is to build up the solution using previously solved subproblems to minimize the number of perfect squares needed to sum up to each intermediate result. This way, we avoid recalculating results that have already been computed.

### Approach:

1. **Dynamic Programming Array:**
   We'll create an array `dp` where `dp[i]` represents the minimum number of perfect squares needed to sum up to the integer (i).

2. **Base Case:**
   (dp[0] = 0) because it takes zero perfect squares to sum to 0.

3. **State Transition:**
   For every number (i) from 1 to (n), we check all perfect squares smaller than or equal to (i). For each perfect square (j^2), the formula is:
    `dp[i] = min(dp[i], dp[i - j^2] + 1)`
   - This means we can compute the number of perfect squares needed for (i) by subtracting a perfect square (j^2) from (i) and then adding 1 for the perfect square (j^2).

### Example 1:
#### Input: (n = 12)

We want to find the minimum number of perfect squares that sum up to 12.

1. Start with an array `dp` initialized as:
   
    `dp = [0, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty]`
   
   - Here, (dp[i]) represents the minimum number of squares needed for (i), and initially all values are set to infinity, except (dp[0] = 0).

3. Update the array:
   - For (i = 1), we have perfect square (1^2 = 1). So, (dp[1] = dp[1 - 1] + 1 = dp[0] + 1 = 1).
   - For (i = 2), we can use (1^2), so (dp[2] = dp[2 - 1] + 1 = dp[1] + 1 = 2).
   - For (i = 3), again use (1^2), so (dp[3] = dp[3 - 1] + 1 = dp[2] + 1 = 3).
   - For (i = 4), we can use (2^2 = 4), so (dp[4] = dp[4 - 4] + 1 = dp[0] + 1 = 1).
   - For (i = 5), use (1^2), so (dp[5] = dp[5 - 1] + 1 = dp[4] + 1 = 2).
   - For (i = 6), use (1^2), so (dp[6] = dp[6 - 1] + 1 = dp[5] + 1 = 3).
   - For (i = 7), use (1^2), so (dp[7] = dp[7 - 1] + 1 = dp[6] + 1 = 4).
   - For (i = 8), use (1^2), so (dp[8] = dp[8 - 1] + 1 = dp[7] + 1 = 5).
   - For (i = 9), use (3^2 = 9), so (dp[9] = dp[9 - 9] + 1 = dp[0] + 1 = 1).
   - For (i = 10), use (1^2), so (dp[10] = dp[10 - 1] + 1 = dp[9] + 1 = 2).
   - For (i = 11), use (1^2), so (dp[11] = dp[11 - 1] + 1 = dp[10] + 1 = 3).
   - For (i = 12), use (4^2 = 4) or (9), so (dp[12] = min(dp[12 - 4] + 1, dp[12 - 9] + 1) = min(dp[8] + 1, dp[3] + 1) = min(5 + 1, 3 + 1) = 3).

So, the minimum number of perfect squares that sum up to 12 is **3**, and the perfect squares are 4, 4, and 4.

### Example 2:
#### Input: (n = 13)

Using the same logic as before:

1. Start with an array `dp` initialized as:
   
   `dp = [0, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty, infty]`
   
3. Update the array:
   - For (i = 1), (dp[1] = 1).
   - For (i = 2), (dp[2] = 2).
   - For (i = 3), (dp[3] = 3).
   - For (i = 4), (dp[4] = 1).
   - For (i = 5), (dp[5] = 2).
   - For (i = 6), (dp[6] = 3).
   - For (i = 7), (dp[7] = 4).
   - For (i = 8), (dp[8] = 5).
   - For (i = 9), (dp[9] = 1).
   - For (i = 10), (dp[10] = 2).
   - For (i = 11), (dp[11] = 3).
   - For (i = 12), (dp[12] = 3).
   - For (i = 13), (dp[13] = 2) (using (4 + 9 = 13)).

So, the minimum number of perfect squares that sum up to 13 is **2**, and the perfect squares are 4 and 9.

### Time Complexity:
- The time complexity of this approach is (O(n cdot sqrt{n})), where (n) is the target number and (sqrt{n}) represents the number of perfect squares less than or equal to (n).

### Space Complexity:
- The space complexity is (O(n)) because we use an array `dp` of size (n + 1).

This dynamic programming approach ensures we efficiently compute the solution for any number (n).

---

## Recursive Approach (caused TLE)
The goal of this problem is to find the minimum number of perfect squares that sum up to a given number `n`. A perfect square is a number that can be expressed as the square of an integer. For example, 1, 4, 9, 16, etc. are perfect squares.

### Recursive Approach Step-by-Step:

The recursive approach to solving this problem involves breaking down the problem into smaller subproblems. At each step, we reduce the number by subtracting a perfect square, and recursively solve the smaller problem. Here is how the recursive approach works in detail:

1. **Base Case:**  
   - If `n` is 0, the result is 0 because no perfect squares are needed to sum up to 0.
   
2. **Recursive Step:**  
   - For a given `n`, try subtracting all perfect squares `i*i` (where `i*i <= n`) from `n` and recursively calculate the minimum number of perfect squares required for `n - i*i`.  
   - For each subtraction, add 1 to the result (since we used one perfect square `i*i`), and keep track of the minimum result.
   
3. **Termination:**  
   - Once all possibilities are explored, the function will return the minimum number of perfect squares that sum up to `n`.

### Example:

Let's consider `n = 12`:

- Start with `n = 12`.
- The perfect squares less than or equal to 12 are: 1, 4, 9.
- Try subtracting 1 from 12:
  - `solve(12 - 1 = 11)` will be computed.
  - Then, try subtracting 1 from 11, and continue recursively. Each time, we keep track of the minimum count of perfect squares.
  
In this way, the recursive approach will try all possible combinations of perfect squares and return the minimal number.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum number of perfect squares 
    int solve(int n){
        // Base case: If n is 0, no numbers are needed to sum to 0.
        if(n == 0) return 0;

        // Initialize ans with a large number. We'll try to minimize this value.
        int ans = INT_MAX;

        // Loop through all possible perfect squares less than or equal to n
        for(int i = 1; i * i <= n; i++) {
            // Recursively calculate the minimum number of perfect squares for the remaining value
            // After subtracting the current perfect square (i * i) from n
            ans = min(ans, solve(n - i*i) + 1);
        }

        // Return the minimum number of perfect squares for the given n
        return ans;
    }

    // Main function to call the solve function and return the result for the input n
    int numSquares(int n) {
        return solve(n);
    }
};
```

### Source Code Explanation

Here is the code provided, with a detailed explanation of each line:

```cpp
class Solution {
public:
    // Recursive function to calculate the minimum number of perfect squares 
    int solve(int n) {
        // Base case: If n is 0, no numbers are needed to sum to 0.
        if (n == 0) return 0;
```
- **Line 1:** Defines the `solve` function which is the recursive function that calculates the minimum number of perfect squares for a given `n`.
- **Line 2:** The base case of the recursion. If `n` is 0, no perfect squares are needed, so the function returns 0.

```cpp
        // Initialize ans with a large number. We'll try to minimize this value.
        int ans = INT_MAX;
```
- **Line 3:** Initializes `ans` to a very large number (`INT_MAX`), so we can minimize it later. This represents the current "best" solution found.

```cpp
        // Loop through all possible perfect squares less than or equal to n
        for (int i = 1; i * i <= n; i++) {
            // Recursively calculate the minimum number of perfect squares for the remaining value
            // After subtracting the current perfect square (i * i) from n
            ans = min(ans, solve(n - i * i) + 1);
        }
```
- **Line 4-6:** This is a loop that iterates through all values of `i` where `i*i` (the perfect square) is less than or equal to `n`. The loop checks perfect squares starting from 1.
- **Line 5:** For each perfect square `i*i`, we recursively call `solve(n - i*i)`, which gives the minimum number of perfect squares for the remaining value `n - i*i`. We add `1` to account for the current perfect square `i*i` being used. Then we update `ans` with the minimum of the current `ans` and the new result.

```cpp
        // Return the minimum number of perfect squares for the given n
        return ans;
    }
```
- **Line 7:** After the loop finishes, the function returns `ans`, which holds the minimum number of perfect squares for `n`.

```cpp
    // Main function to call the solve function and return the result for the input n
    int numSquares(int n) {
        return solve(n);
    }
};
```
- **Line 8-10:** The main function `numSquares` simply calls the recursive function `solve(n)` and returns the result.



### Example Walkthrough:

For `n = 12`:
1. The first call to `solve(12)` checks all perfect squares less than or equal to 12: 1, 4, and 9.
2. Subtracting 1: `solve(12 - 1 = 11)` is called, and then it tries subtracting 1, 4, and 9 from 11.
3. This process continues recursively, and finally, the result `4` (which is the minimum number of perfect squares) is returned for `n = 12`.

### Example Output:

For `n = 12`, the minimum number of perfect squares that sum up to 12 is `4`. The sum can be formed by `4 + 4 + 4 + 0`.

Output:
```
4
```



### Time and Space Complexity:

**Time Complexity:**
- The time complexity of this recursive solution is exponential. In the worst case, for every number `n`, we check all smaller values recursively, which leads to `O(2^n)` time complexity. This can be extremely inefficient for large values of `n`.

**Space Complexity:**
- The space complexity is determined by the depth of the recursion stack. In the worst case, the recursion depth is proportional to `n` because the function is called recursively for `n - 1`, `n - 2`, ..., down to `0`. Therefore, the space complexity is `O(n)`.


### Optimizations:
This recursive approach can be optimized by using **dynamic programming (DP)** to store the results of already computed subproblems, which avoids redundant calculations and significantly improves the time complexity. By using a DP array, we can reduce the time complexity to `O(n * sqrt(n))`.

---
## To-Down Approach (DP)
The problem is the same as before: Given a number `n`, we need to find the minimum number of perfect squares that sum up to `n`. A perfect square is a number that can be expressed as the square of an integer, such as 1, 4, 9, 16, and so on. The challenge is to minimize the number of perfect squares that sum up to `n`.

### Top-Down Approach with Memoization:

The top-down approach to solving this problem uses **recursion with memoization**. This means that we compute the minimum number of perfect squares for each subproblem recursively, but we store the results in a cache (memoization) to avoid recalculating the same results multiple times. Here is how the top-down approach works:

1. **Base Case:**  
   - If `n = 0`, the result is 0 because no perfect squares are needed to sum up to 0. This is stored in the memoization array `dp[0] = 0`.

2. **Recursive Step:**  
   - For a given `n`, try subtracting all possible perfect squares `i*i` (where `i*i <= n`) from `n`, and recursively calculate the minimum number of perfect squares for `n - i*i`.
   - For each subtraction, add 1 to the result to account for the perfect square `i*i` used, and keep track of the minimum result.

3. **Memoization:**  
   - To avoid recalculating the same subproblem multiple times, store the results in the `dp` array. If the result for `n` has already been computed (i.e., `dp[n] != -1`), simply return the stored value.

4. **Termination:**  
   - Once all possible perfect squares are tried, the function returns the minimum number of perfect squares needed for `n`.
     
### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum number of perfect squares 
    // using memoization to avoid redundant calculations
    int solve(int n, vector<int> &dp){
        // Base case: dp[0] = 0, as 0 can be represented by 0 perfect squares
        dp[0] = 0;

        // If the result for the current value of n has already been computed, return it
        if(dp[n] != -1) return dp[n];

        // Initialize ans to the maximum possible value, which is n (since n can be represented
        // by the sum of n 1's (1^2), which is the worst case)
        int ans = n;

        // Try all perfect squares less than or equal to n
        for(int i = 1; i * i <= n; i++){
            // The current square number
            int SQRT = i * i;

            // Recursively calculate the minimum squares needed for the remaining value (n - SQRT)
            ans = min(ans, solve(n - SQRT, dp) + 1); // Add 1 for the current perfect square used
        }

        // Store the result for the current value of n to avoid recalculating it
        dp[n] = ans;

        // Return the minimum number of perfect squares for the current value of n
        return dp[n];
    }

    // Main function to calculate the minimum number of perfect squares for the input n
    int numSquares(int n) {
        // Create a DP array of size n+1 initialized with -1 (indicating that no value has been computed yet)
        vector<int> dp(n+1, -1);

        // Call the recursive function with memoization to compute the result
        return solve(n, dp);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Recursive function to calculate the minimum number of perfect squares 
    // using memoization to avoid redundant calculations
    int solve(int n, vector<int> &dp){
        // Base case: dp[0] = 0, as 0 can be represented by 0 perfect squares
        dp[0] = 0;
```
- **Line 1-3:** The `solve` function is a recursive function that computes the minimum number of perfect squares needed for a given number `n`, using the memoization array `dp` to store previously computed values.
- **Line 3:** The base case is `dp[0] = 0`, since no squares are needed to represent `0`.

```cpp
        // If the result for the current value of n has already been computed, return it
        if(dp[n] != -1) return dp[n];
```
- **Line 4:** If `dp[n]` is not `-1`, it means the minimum number of perfect squares for `n` has already been computed. So, we return the stored result, avoiding redundant calculations.

```cpp
        // Initialize ans to the maximum possible value, which is n (since n can be represented
        // by the sum of n 1's (1^2), which is the worst case)
        int ans = n;
```
- **Line 5:** We initialize `ans` to `n`. This represents the worst-case scenario, where we can represent `n` as a sum of `n` perfect squares of 1 (`1^2`). This is the upper bound for the minimum number of perfect squares needed.

```cpp
        // Try all perfect squares less than or equal to n
        for(int i = 1; i * i <= n; i++){
            // The current square number
            int SQRT = i * i;
```
- **Line 6-7:** The loop iterates through all possible perfect squares `i*i` (starting from 1) where `i*i <= n`. For each square, we recursively calculate the minimum number of perfect squares needed for `n - SQRT`.

```cpp
            // Recursively calculate the minimum squares needed for the remaining value (n - SQRT)
            ans = min(ans, solve(n - SQRT, dp) + 1); // Add 1 for the current perfect square used
        }
```
- **Line 8:** We subtract the current square `SQRT = i*i` from `n` and recursively compute the minimum number of squares required for `n - SQRT`. We add `1` to the result because we used one perfect square. The `ans` is updated to the minimum of the current `ans` and the result of the recursive call.

```cpp
        // Store the result for the current value of n to avoid recalculating it
        dp[n] = ans;
```
- **Line 9:** After calculating the minimum number of perfect squares for `n`, we store the result in `dp[n]` to avoid recalculating it later.

```cpp
        // Return the minimum number of perfect squares for the current value of n
        return dp[n];
    }
```
- **Line 10:** The function returns the minimum number of perfect squares for `n`, which is stored in `dp[n]`.

```cpp
    // Main function to calculate the minimum number of perfect squares for the input n
    int numSquares(int n) {
        // Create a DP array of size n+1 initialized with -1 (indicating that no value has been computed yet)
        vector<int> dp(n+1, -1);

        // Call the recursive function with memoization to compute the result
        return solve(n, dp);
    }
};
```
- **Line 11-15:** The main function `numSquares` initializes the `dp` array with `-1` values, which indicates that no value has been computed yet. It then calls the `solve` function with the input `n` to compute the result.



### Example Walkthrough:

Let's consider `n = 12`:

1. The first call to `solve(12)` checks all perfect squares less than or equal to 12: 1, 4, 9.
2. Subtracting 1: `solve(12 - 1 = 11)` is called. In the recursive call, we subtract 1, 4, or 9 from 11 and continue.
3. Similarly, for other recursive calls, we continue subtracting squares and storing results in the `dp` array.
4. Eventually, the minimum number of perfect squares for `12` is found to be `4` (using the squares `4 + 4 + 4`).



### Example Output:

For `n = 12`, the minimum number of perfect squares that sum up to 12 is `4`. The result can be represented as:
```
4 (4 + 4 + 4)
```

Output:
```
4
```



### Time and Space Complexity:

**Time Complexity:**
- The time complexity of the top-down approach with memoization is reduced compared to the naive recursive approach. Since we use memoization to store results for subproblems, each subproblem is computed only once. The time complexity is approximately `O(n * sqrt(n))` because we compute the minimum for `n` and for each `n`, we try all perfect squares up to `sqrt(n)`.

**Space Complexity:**
- The space complexity is `O(n)` due to the space required to store the `dp` array of size `n+1`, which holds the computed results for all subproblems.

### Optimizations:

While the top-down approach with memoization significantly reduces redundant calculations, further optimization can be achieved by using a **bottom-up dynamic programming** approach, which iteratively computes the minimum number of squares for all values from 1 to `n` using previously computed results. This bottom-up approach can also achieve a time complexity of `O(n * sqrt(n))`.

---
## Bottom-Up Approach (DP)

The problem asks us to find the minimum number of perfect squares (numbers that can be expressed as the square of an integer, like 1, 4, 9, 16, etc.) that sum up to a given number `n`. We need to find the most efficient way to compute this minimum, and a **bottom-up dynamic programming approach** is a great choice.

### Bottom-Up Approach:

In the bottom-up approach, we start by solving the problem for smaller values and gradually build up to the solution for `n`. This is done by iterating from `1` to `n`, and for each `i`, we find the minimum number of perfect squares needed to sum up to `i`.

The key idea is that:
- For each number `i` from `1` to `n`, we check all possible perfect squares (`j*j`) that are less than or equal to `i`.
- For each square `j*j`, we update the result for `i` by considering the number of perfect squares required to sum to `i - j*j`, plus one more square (the square `j*j` itself).
- We store the result in an array `dp[]`, where `dp[i]` holds the minimum number of squares needed to sum up to `i`.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the minimum number of perfect squares
    int solve(int n){
        // Create a DP array of size n+1 initialized with INT_MAX (a large value representing infinity)
        // dp[i] will store the minimum number of perfect squares required to sum to i.
        vector<int> dp(n+1, INT_MAX);

        // Base case: dp[0] = 0, as no squares are needed to sum to 0.
        dp[0] = 0;

        // Iterate over all values of i from 1 to n
        for(int i = 1; i <= n; i++){
            // For each i, check all perfect squares (j * j) that are less than or equal to i
            for(int j = 1; j * j <= i; j++){
                int SQRT = j * j;  // Square of j

                // If subtracting SQRT from i doesn't make it negative, update dp[i]
                // Take the minimum of the current value of dp[i] and dp[i - SQRT] + 1
                // (the +1 is because we are using one more square, i.e., SQRT)
                dp[i] = min(dp[i], dp[i - SQRT] + 1);
            }
        }

        // Return the minimum number of perfect squares for the number n
        return dp[n];
    }

    // Main function to return the minimum number of perfect squares for n
    int numSquares(int n) {
        return solve(n);  // Call the solve function to calculate the result
    }
};
```
### Source Code Explanation

```cpp
class Solution {
public:
    // Function to calculate the minimum number of perfect squares
    int solve(int n){
        // Create a DP array of size n+1 initialized with INT_MAX (a large value representing infinity)
        // dp[i] will store the minimum number of perfect squares required to sum to i.
        vector<int> dp(n+1, INT_MAX);
```
- **Line 1-3:** The `solve` function initializes a `dp` array of size `n + 1` (to include 0 through n), where each value is initially set to `INT_MAX` (a large value). This represents the worst case, where `n` could be expressed as the sum of `n` ones (`1^2`). We will update these values with the actual minimum number of perfect squares needed.

```cpp
        // Base case: dp[0] = 0, as no squares are needed to sum to 0.
        dp[0] = 0;
```
- **Line 4:** The base case is `dp[0] = 0`, since no squares are needed to represent the sum `0`. This is our starting point.

```cpp
        // Iterate over all values of i from 1 to n
        for(int i = 1; i <= n; i++){
```
- **Line 5-6:** We loop through all values from `1` to `n`. For each `i`, we will compute the minimum number of perfect squares required to sum to `i`.

```cpp
            // For each i, check all perfect squares (j * j) that are less than or equal to i
            for(int j = 1; j * j <= i; j++){
                int SQRT = j * j;  // Square of j
```
- **Line 7-9:** For each `i`, we check all perfect squares `j*j` where `j*j <= i`. We compute the square `SQRT = j*j`.

```cpp
                // If subtracting SQRT from i doesn't make it negative, update dp[i]
                // Take the minimum of the current value of dp[i] and dp[i - SQRT] + 1
                // (the +1 is because we are using one more square, i.e., SQRT)
                dp[i] = min(dp[i], dp[i - SQRT] + 1);
            }
```
- **Line 10-12:** If subtracting `SQRT` from `i` doesn't make it negative (`i - SQRT >= 0`), we update `dp[i]`. The update is done by taking the minimum of the current value of `dp[i]` and `dp[i - SQRT] + 1`. The `+1` is added because we are using one additional square (`SQRT`) to form the sum.

```cpp
        }
        // Return the minimum number of perfect squares for the number n
        return dp[n];
    }
```
- **Line 13-14:** After the loop, `dp[n]` will contain the minimum number of perfect squares required to sum up to `n`. The function returns this value.

```cpp
    // Main function to return the minimum number of perfect squares for n
    int numSquares(int n) {
        return solve(n);  // Call the solve function to calculate the result
    }
};
```
- **Line 15-17:** The `numSquares` function is the main function that simply calls `solve(n)` to get the result.



### Example Walkthrough:

Let's walk through an example where `n = 12`:

1. **Initialization:**
   - `dp = [0, INT_MAX, INT_MAX, ..., INT_MAX]` (of size `n+1`).
   - `dp[0] = 0` because 0 requires 0 perfect squares.

2. **For i = 1:**
   - Check squares `1^2 = 1`.
   - `dp[1] = min(dp[1], dp[1-1] + 1) = min(INT_MAX, 0 + 1) = 1`.

3. **For i = 2:**
   - Check squares `1^2 = 1`.
   - `dp[2] = min(dp[2], dp[2-1] + 1) = min(INT_MAX, 1 + 1) = 2`.

4. **For i = 3:**
   - Check squares `1^2 = 1`.
   - `dp[3] = min(dp[3], dp[3-1] + 1) = min(INT_MAX, 2 + 1) = 3`.

5. **For i = 4:**
   - Check squares `1^2 = 1`, `2^2 = 4`.
   - `dp[4] = min(dp[4], dp[4-1] + 1) = min(INT_MAX, 3 + 1) = 4`.
   - `dp[4] = min(dp[4], dp[4-4] + 1) = min(4, 0 + 1) = 1`.

6. **For i = 12:**
   - Check squares `1^2 = 1`, `2^2 = 4`, `3^2 = 9`.
   - `dp[12] = min(dp[12], dp[12-1] + 1) = min(INT_MAX, 4 + 1) = 5`.
   - `dp[12] = min(dp[12], dp[12-4] + 1) = min(5, 1 + 1) = 2`.
   - `dp[12] = min(dp[12], dp[12-9] + 1) = min(2, 3 + 1) = 2`.

So, `dp[12] = 3`, meaning the minimum number of perfect squares needed to sum up to `12` is `3` (using `9 + 1 + 1`).

### Example Output:

For `n = 12`, the output will be:
```
3
```

### Time and Space Complexity:

**Time Complexity:**
- The outer loop runs from `1` to `n`, so it runs `n` times.
- For each `i`, the inner loop runs through all squares `j*j` where `j*j <= i`. In the worst case, the number of perfect squares less than or equal to `i` is approximately `sqrt(i)`. Hence, the time complexity is `O(n * sqrt(n))`.

**Space Complexity:**
- We use an array `dp` of size `n + 1` to store the results, so the space complexity is `O(n)`.

### Optimizations:

While the bottom-up approach is efficient for most cases, one potential optimization is to use a **queue-based BFS** approach to find the minimum number of squares. However, for most problems, this bottom-up dynamic programming solution with time complexity `O(n * sqrt(n))` should be sufficient.

---

## Space Optimization (Not Possible)
Here’s a more concise, synthetic explanation of why space optimization isn't possible in this case:

### 1. **Dependency on Multiple States:**
Each `dp[i]` requires information from multiple previous states, specifically `dp[i - j*j]` for all `j` such that `j*j <= i`. This makes it impossible to reduce the space complexity to a constant or even linear amount, as we cannot avoid storing results from all prior calculations.

### 2. **Non-Overlapping Subproblems:**
Unlike problems where only the previous or two previous states are required (e.g., Fibonacci sequence), here each state depends on a range of previous states. Therefore, we must store results for all `dp[i]` values up to `n`.

### 3. **No Efficient State Compression:**
There is no way to efficiently compress or reuse stored results. Since the calculations involve multiple potential values (all perfect squares less than `i`), the problem doesn't allow for a simple optimization of space usage.

In conclusion, space optimization is not feasible due to the need to maintain all `dp[i]` values to calculate the minimum perfect squares for each `i` from `1` to `n`.
