<h1 align="center">Ways - To Reach - N'th - Stair </h1>


## Problem Statement

**Problem URL :** [Ways To Reach N'th Stair](https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1)

![image](https://github.com/user-attachments/assets/031adec5-ed22-4f00-9b42-c4e450084b10)

### Problem Explanation
The problem involves determining how many distinct ways you can climb to the top of a staircase that has `n` steps, where at each step, you can either climb **1 step** or **2 steps**.

### Key Points:
1. You are at the bottom of the staircase (at step 0).
2. You want to reach the top, which is step `n`.
3. At each step, you can either:
   - Take **1 step** (move up by 1 step).
   - Take **2 steps** (move up by 2 steps).

You need to calculate how many distinct ways there are to climb to the top. The solution to this problem requires counting all possible sequences of 1-steps and 2-steps that sum to `n`.

### Problem Breakdown:

- **Starting Point:** You start at the 0th step, and the goal is to reach the `n`th step.
- **Moves:** At each point, you have two choices:
  - Take 1 step.
  - Take 2 steps.
  
- **Valid Paths:** A valid path consists of combinations of 1-step and 2-step moves. The goal is to find all possible combinations of these steps that lead you to step `n`.

### Example 1: `n = 2`

- **Steps:** There are two steps to climb.
- **Ways to climb:**
  1. Take **1 step** + **1 step**.
  2. Take **2 steps** at once.

- **Result:** There are **2 distinct ways** to climb to the top.

### Example 2: `n = 3`

- **Steps:** There are three steps to climb.
- **Ways to climb:**
  1. Take **1 step** + **1 step** + **1 step**.
  2. Take **1 step** + **2 steps**.
  3. Take **2 steps** + **1 step**.

- **Result:** There are **3 distinct ways** to climb to the top.

### Example 3: `n = 4`

- **Steps:** There are four steps to climb.
- **Ways to climb:**
  1. Take **1 step** + **1 step** + **1 step** + **1 step**.
  2. Take **1 step** + **1 step** + **2 steps**.
  3. Take **1 step** + **2 steps** + **1 step**.
  4. Take **2 steps** + **1 step** + **1 step**.
  5. Take **2 steps** + **2 steps**.

- **Result:** There are **5 distinct ways** to climb to the top.

### Example 4: `n = 5`

- **Steps:** There are five steps to climb.
- **Ways to climb:**
  1. Take **1 step** five times.
  2. Take **1 step** three times and **2 steps** once.
  3. Take **1 step** twice and **2 steps** twice.
  4. Take **1 step** once and **2 steps** three times.
  5. Take **2 steps** two times and **1 step** once.

- **Result:** There are **8 distinct ways** to climb to the top.

### Insights:
- Each time you climb a staircase, you have two possible choices: either move up by 1 step or 2 steps. This means the number of ways to reach the `n`th step depends on how you get to the previous steps (either step `n-1` or step `n-2`).
  
- If you know how many ways there are to reach step `n-1` and step `n-2`, you can easily calculate the number of ways to reach step `n` by summing the two.

### Recursive Nature:
- This problem exhibits a **recursive pattern**:
  - To reach the `n`th step, you can either:
    1. Come from step `n-1` (i.e., take 1 step).
    2. Come from step `n-2` (i.e., take 2 steps).
  - Therefore, the number of ways to reach step `n` is the sum of the number of ways to reach step `n-1` and step `n-2`.

### Dynamic Programming Approach:
- This problem can be efficiently solved using **Dynamic Programming** or **Memoization** to store intermediate results. By solving smaller subproblems (finding the number of ways to climb fewer steps), we can build up to the solution for `n` steps.

### Summary:
- **Input:** An integer `n`, representing the number of steps.
- **Output:** An integer representing the number of distinct ways to reach the top.
- **Constraints:** You can either take 1 step or 2 steps at a time.

### Conclusion:
This is a classic problem involving dynamic programming and can be reduced to the Fibonacci sequence due to its recursive structure. As `n` increases, the number of ways to climb the staircase grows, but the problem can be solved efficiently with the right approach.


## Recursive Approach (LTE Caused)
### **Approach 1: Using Recursion with an Index (`i`)**

This approach uses an index to represent the current step you're on and recursively calculates the number of ways to reach the top. The logic is as follows:
- From the current step `i`, you can either move to step `i+1` or `i+2`.
- We recursively calculate the number of ways to reach the top from each possible move, combining both results.

#### **Example Walkthrough (n = 3)**

Let's walk through an example where `n = 3` (3 steps in the staircase).

- Start at `currentStep = 0`.
  - From step 0, take **1 step** to step `1` → Calculate the number of ways from `1` to `3`.
  - From step 0, take **2 steps** to step `2` → Calculate the number of ways from `2` to `3`.

- From step `1`, take **1 step** to step `2` → Calculate the number of ways from `2` to `3`.
- From step `1`, take **2 steps** to step `3` → Reached the top, return `1`.

- From step `2`, take **1 step** to step `3` → Reached the top, return `1`.
- From step `2`, take **2 steps** to step `4` → Exceeded the top, return `0`.

- Combine the results:
  - From `currentStep = 0`, ways = `1 (from 0 -> 1 -> 3)` + `1 (from 0 -> 2 -> 3)` = `2`.

Thus, the number of ways to reach the top of a staircase with `3` steps is **2**.


### **Code Implementation (Approach 1: Using Recursion with Index)**

```cpp
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
```

### **Code Explanation (Line by Line)**
#### **Approach 1 (Using Recursion with an Index `i`):**

1. **`class Solution {`**  
   Defines the `Solution` class that contains the methods to solve the problem.

2. **`int calculateWays(int n, int currentStep) {`**  
   A helper function to calculate the number of ways to reach the top from `currentStep` to `n`.

3. **`if (currentStep == n) return 1;`**  
   Base case: If we have reached step `n`, we have found one valid way to reach the top.

4. **`if (currentStep > n) return 0;`**  
   Base case: If `currentStep` exceeds `n`, this is an invalid path.

5. **`return calculateWays(n, currentStep + 1) + calculateWays(n, currentStep + 2);`**  
   Recursively calculate the number of ways to reach the top by moving to the next steps (`currentStep + 1` and `currentStep + 2`).

6. **`int countWays(int n) {`**  
   Main function to start the process.

7. **`int currentStep = 0;`**  
   Initialize `currentStep` to 0, meaning we start from the bottom of the staircase.

8. **`return calculateWays(n, currentStep);`**  
   Call the helper function `calculateWays` to calculate the total number of ways to climb the staircase.


### **Approach 2: Using Recursion with Step Subtraction (n)**

This approach uses the value of `n` (number of steps left to reach the top) to recursively calculate the number of ways to climb the stairs. The logic is:
- From `n`, you can either subtract `1` (take one step) or subtract `2` (take two steps).
- Recursively calculate the number of ways to climb the remaining steps after taking either `1` or `2` steps.

#### **Example Walkthrough (n = 3)**

- Start with `n = 3`.
  - Take **1 step**, now we need to climb `3 - 1 = 2` more steps.
  - Take **2 steps**, now we need to climb `3 - 2 = 1` more step.

- From `n = 2`:
  - Take **1 step**, now we need to climb `2 - 1 = 1` more step.
  - Take **2 steps**, now we need to climb `2 - 2 = 0` steps → Base case, return `1`.

- From `n = 1`:
  - Take **1 step**, now we need to climb `1 - 1 = 0` steps → Base case, return `1`.
  - Take **2 steps**, now we need to climb `1 - 2 = -1` steps → Invalid, return `0`.

- Combine the results:
  - From `n = 3`, ways = `1 (from 3 -> 2)` + `1 (from 3 -> 1)` = `2`.

Thus, the number of ways to reach the top of a staircase with `3` steps is **2**.

### **Code Implementation (Approach 2: Using Recursion with Step Subtraction)**

```cpp
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
```

### **Code Explanation (Line by Line)**
#### **Approach 2 (Using Recursion with Step Subtraction `n`):**

1. **`class Solution {`**  
   Defines the `Solution` class.

2. **`int calculateWays(int n) {`**  
   A helper function to calculate the number of ways to reach the top from `n` steps remaining.

3. **`if (n == 0) return 1;`**  
   Base case: If `n` is 0, there’s exactly 1 way to reach the top (by doing nothing).

4. **`if (n < 0) return 0;`**  
   Base case: If `n` is negative, it's an invalid path (return 0).

5. **`return calculateWays(n - 1) + calculateWays(n - 2);`**  
   Recursively calculate the number of ways to reach the top by either taking 1 step or 2 steps.

6. **`int countWays(int n) {`**  
   Main function that calls the helper function.

7. **`return calculateWays(n);`**  
   Start the recursive process by calling `calculateWays` with `n` steps.

### **Time and Space Complexity**
#### **Time Complexity:**
- **O(2^n):**  
   Since we use recursion to explore all possible step combinations, each recursive call branches into two subproblems, leading to an exponential time complexity of **O(2^n)**.

#### **Space Complexity:**
- **O(n):**  
   The space complexity is **O(n)** due to the recursion stack, as the maximum depth of recursion is `n` (the number of steps remaining).


**Optimization:**
To optimize this approach, you can use **Memoization** or **Dynamic Programming**, which would reduce the time complexity to **O(n)**.

---

## **Top-Down Approach (Memoization)**

The **Top-Down Approach** in Dynamic Programming (DP) refers to solving a problem recursively and using memoization (storing previously computed results) to avoid redundant calculations.

#### **Steps in Top-Down DP:**
1. **Recursive Decomposition**: Break the problem into smaller subproblems, solving each smaller problem recursively.
2. **Memoization**: Store the results of subproblems in a data structure (usually an array or map). This helps to avoid recomputing the same result multiple times.
3. **Base Case**: Identify the base cases where the problem can be directly solved without recursion. For example, in climbing stairs, the base case is reaching the first step.
4. **Recursive Call**: For larger subproblems, recursively solve them by calling the function on smaller subproblems, and store the results in the memoization table.
5. **Result Construction**: Combine the results of smaller subproblems to solve the larger problem.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the number of ways to reach the top of the stairs using memoization
    int solve(int n, vector<int>& dp) {
        // Base case: If we are at the first step (n == 0), there's exactly one way to reach the top
        if(n == 0) return 1;

        // Base case: If `n` is negative, return 0 as it's an invalid path
        if(n < 0) return 0;

        // If the value for this step (`n`) is already calculated and stored in `dp`, return it (Memoization)
        if(dp[n] != -1) return dp[n];

        // Recursively calculate the number of ways to reach the top from the current step
        // We can reach step `n` by either coming from step `n-1` or step `n-2`
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        // Return the calculated result for step `n`
        return dp[n];
    }

    // Main function to start the process of calculating the number of ways to climb to the top
    int countWays(int n) {
        // Initialize a memoization array `dp` of size `n+1`, with all values set to -1
        // `dp[i]` will store the number of ways to reach step `i`
        vector<int> dp(n + 1, -1);

        // Call the recursive function to calculate the number of ways to reach the top
        return solve(n, dp);
    }
};
```

### **Step-by-Step Explanation:**

```cpp
class Solution {
public:
    // Function to calculate the number of ways to reach the top of the stairs using memoization
    int solve(int n, vector<int>& dp) {
```
- **Line 1**: We define a class `Solution`, which will contain the functions that solve the problem. The class is commonly used in LeetCode and other coding platforms to structure the solution.
- **Line 2**: We define a public member function `solve`. This function calculates the number of ways to reach the `n`th step of the staircase, where `dp` is the memoization array that stores the number of ways to reach each step.
- **Parameters**:
  - `n`: The current step that we are trying to calculate the number of ways to reach.
  - `dp`: A reference to a `vector<int>` that stores the number of ways to reach each step. This will be used to store intermediate results and avoid recomputation (memoization).

```cpp
        // Base case: If we are at the first step (n == 0), there's exactly one way to reach the top
        if(n == 0) return 1;
```
- **Line 3**: This is the base case of the recursion. If `n == 0`, it means we are at the base of the staircase (the ground level). In this case, there is exactly **1 way** to stay at the ground (no movement is required).
  - **Return 1**: We return `1` because there is only one way to "stay" at step 0 (by not moving).

```cpp
        // Base case: If `n` is negative, return 0 as it's an invalid path
        if(n < 0) return 0;
```
- **Line 4**: This is another base case. If `n` becomes negative, it means we've moved past the base of the stairs, which is invalid. Therefore, there is no valid way to reach a negative step.
  - **Return 0**: We return `0` because there is no valid way to reach a step `n` that is negative.

```cpp
        // If the value for this step (`n`) is already calculated and stored in `dp`, return it (Memoization)
        if(dp[n] != -1) return dp[n];
```
- **Line 5**: This is where memoization comes into play. Before we perform any calculations for step `n`, we check if the number of ways to reach step `n` has already been calculated and stored in the `dp` array.
  - **`dp[n] != -1`**: If the value stored in `dp[n]` is not `-1`, it means that the result has already been computed in a previous recursive call, and we can directly return that value.
  - **Return `dp[n]`**: We return the precomputed result from `dp[n]`, saving time and preventing redundant calculations.

```cpp
        // Recursively calculate the number of ways to reach the top from the current step
        // We can reach step `n` by either coming from step `n-1` or step `n-2`
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
```
- **Line 6**: This is the core logic of the recursion. To calculate the number of ways to reach step `n`, we can come from either:
  1. The previous step `n-1` (taking a 1-step move).
  2. Two steps before `n-2` (taking a 2-step move).
  - **Recursive Calls**:
    - `solve(n - 1, dp)`: This calls the `solve` function to calculate the number of ways to reach step `n-1`.
    - `solve(n - 2, dp)`: This calls the `solve` function to calculate the number of ways to reach step `n-2`.
  - **Storing the Result**: We store the sum of the two recursive calls in `dp[n]`. This is the total number of ways to reach step `n`.

```cpp
        // Return the calculated result for step `n`
        return dp[n];
    }
```
- **Line 7**: After calculating and storing the result in `dp[n]`, we return the value from `dp[n]`, which is the total number of ways to reach step `n`.

```cpp
    // Main function to start the process of calculating the number of ways to climb to the top
    int countWays(int n) {
```
- **Line 8**: This is the main function `countWays`. It is the entry point for calculating the number of ways to climb to the `n`th step from the 0th step.
  - The function receives an integer `n`, which represents the total number of steps in the staircase.

```cpp
        // Initialize a memoization array `dp` of size `n+1`, with all values set to -1
        // `dp[i]` will store the number of ways to reach step `i`
        vector<int> dp(n + 1, -1);
```
- **Line 9**: Here, we initialize the memoization array `dp` with size `n+1` (to account for all steps from `0` to `n`).
  - **`vector<int> dp(n + 1, -1)`**: This creates a vector of size `n+1`, and initializes all elements to `-1`. The value `-1` is used to indicate that a particular step has not been computed yet.
  - **Purpose of `dp`**: The `dp[i]` array will store the number of ways to reach step `i`. It allows us to store intermediate results and avoid recalculating them.

```cpp
        // Call the recursive function to calculate the number of ways to reach the top
        return solve(n, dp);
    }
};
```
- **Line 10**: Finally, we call the recursive function `solve(n, dp)` to calculate the number of ways to reach the top (step `n`) and return the result. This call initiates the memoized recursion process.
  - **Return `solve(n, dp)`**: The result returned by `solve(n, dp)` will be the final answer, which represents the number of ways to reach step `n`.

### **Detailed Example:**

Let’s go through an example where `n = 4` to see how the code works in action:

1. **First Call**: `countWays(4)`
   - Calls `solve(4, dp)`
   - Since `dp[4]` is `-1`, it proceeds to calculate the result by calling:
     - `solve(3, dp)` and `solve(2, dp)`

2. **Second Call**: `solve(3, dp)`
   - Calls `solve(2, dp)` and `solve(1, dp)`

3. **Third Call**: `solve(2, dp)`
   - Calls `solve(1, dp)` and `solve(0, dp)`

4. **Fourth Call**: `solve(1, dp)`
   - Calls `solve(0, dp)` and `solve(-1, dp)`

5. **Base Cases**:
   - `solve(0, dp)` returns `1` (since we're at the ground level).
   - `solve(-1, dp)` returns `0` (invalid path).
   - `dp[1] = 1` (1 way to reach step 1).

6. **Backtracking**:
   - `solve(2, dp)` returns `2` (`dp[2] = dp[1] + dp[0] = 1 + 1`).
   - `solve(3, dp)` returns `3` (`dp[3] = dp[2] + dp[1] = 2 + 1`).
   - `solve(4, dp)` returns `5` (`dp[4] = dp[3] + dp[2] = 3 + 2`).

7. **Final Result**: The final answer returned by `countWays(4)` is `5`.

### **Time and Space Complexity**

- **Time Complexity**: **O(n)**
  - Each step is calculated at most once due to memoization. For each step, the result is stored in `dp`, and we never recalculate it. Therefore, the time complexity is linear in terms of `n`.

- **Space Complexity**: **O(n)**
  - The space complexity is determined by the `dp` array, which stores results for all `n` steps. The recursion call stack also contributes to the space complexity, and since the maximum recursion depth is `n`, the space complexity is `O(n)`.

### **Summary**

- The code uses **memoization** to solve the problem of counting the number of ways to climb a staircase with `n` steps.
- The recursive function calculates the number of ways to reach each step from the ground level.
- Base cases handle scenarios when we are at step 0 or a negative step, and the `dp` array stores results to avoid redundant calculations.

---

## **Bottom-Up Approach (Tabulation)**
The **Bottom-Up Approach** in Dynamic Programming (DP) is an iterative approach where you start solving the problem from the smallest subproblems and build up the solution to the larger problem. This approach avoids recursion and instead uses a loop to calculate solutions from the base case upwards.

### **Steps in Bottom-Up DP Approach:**
1. **Initialization**: 
   - We initialize an array (`dp`) to store the solutions to subproblems. The array is initialized with values based on the base cases.
2. **Iteration**:
   - Starting from the smallest subproblem (usually `dp[0]`), we fill in the array using the recurrence relation.
   - Each element `dp[i]` is calculated based on the previously computed values, i.e., `dp[i] = dp[i-1] + dp[i-2]`, which represents the sum of the ways to reach the previous step (`i-1`) and the step before that (`i-2`).
3. **Final Result**:
   - The result for the original problem (`countWays(n)`) will be found in `dp[n]`.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the number of ways to climb `n` stairs using dynamic programming
    int countWays(int n) {
        // Create a dp array where dp[i] will store the number of ways to reach the ith step
        vector<int> dp(n+1, 0);

        // Base case: There's one way to reach the 0th step (by staying at the start)
        dp[0] = 1;

        // Base case: If n >= 1, there's one way to reach the 1st step (by taking a single step)
        if(n >= 1) dp[1] = 1;

        // Iterate from the 2nd step to the nth step
        for(int i = 2; i <= n; i++) {
            // The number of ways to reach step i is the sum of:
            //   - the number of ways to reach step i-1 (taking 1 step)
            //   - the number of ways to reach step i-2 (taking 2 steps)
            dp[i] = dp[i-1] + dp[i-2];
        }

        // Return the number of ways to reach the nth step
        return dp[n];
    }
};
```
Now, let's go through the given code in detail:

```cpp
class Solution {
public:
    // Function to calculate the number of ways to climb `n` stairs using dynamic programming
    int countWays(int n) {
```
- **Line 1**: The class `Solution` is defined, which will hold the function `countWays` that solves the problem.
- **Line 2**: `countWays(int n)` is the main function that calculates the number of ways to reach the top (step `n`) from the base (step `0`).

```cpp
        // Create a dp array where dp[i] will store the number of ways to reach the ith step
        vector<int> dp(n+1, 0);
```
- **Line 3**: We declare a vector `dp` of size `n+1` (because we need to calculate for all steps from `0` to `n`).
  - **Initialization**: The vector is initialized with `0`s. The value `dp[i]` will store the number of ways to reach the `i`th step.
  - **Why size `n+1`?** We need an extra index for `dp[0]` to `dp[n]`.

```cpp
        // Base case: There's one way to reach the 0th step (by staying at the start)
        dp[0] = 1;
```
- **Line 4**: The base case: There is exactly one way to stay at step `0` (by not moving).
  - **dp[0] = 1**: We set the number of ways to reach step `0` as `1`.

```cpp
        // Base case: If n >= 1, there's one way to reach the 1st step (by taking a single step)
        if(n >= 1) dp[1] = 1;
```
- **Line 5**: If `n >= 1`, there is exactly **one way** to reach step `1` (by taking a single step from step `0`).
  - **dp[1] = 1**: We set `dp[1] = 1` for the base case of reaching the first step.

```cpp
        // Iterate from the 2nd step to the nth step
        for(int i = 2; i <= n; i++) {
```
- **Line 6**: The loop starts at `i = 2` and goes up to `i = n`.
  - **Purpose of the loop**: We calculate the number of ways to reach each step starting from step `2` up to step `n`, using the recurrence relation.

```cpp
            // The number of ways to reach step i is the sum of:
            //   - the number of ways to reach step i-1 (taking 1 step)
            //   - the number of ways to reach step i-2 (taking 2 steps)
            dp[i] = dp[i-1] + dp[i-2];
```
- **Line 7**: For each step `i` (from `2` to `n`), the number of ways to reach step `i` is the sum of:
  1. The number of ways to reach step `i-1` (by taking one step from `i-1`).
  2. The number of ways to reach step `i-2` (by taking two steps from `i-2`).
  - **dp[i] = dp[i-1] + dp[i-2]**: This recurrence relation gives us the number of ways to reach step `i` as the sum of the number of ways to reach the two previous steps.

```cpp
        }
```
- **Line 8**: The loop ends after calculating all the values from step `2` to step `n`.

```cpp
        // Return the number of ways to reach the nth step
        return dp[n];
    }
};
```
- **Line 9**: After the loop completes, the value `dp[n]` contains the number of ways to reach the `n`th step.
  - **Return `dp[n]`**: The final result, which is the number of ways to reach the top of the staircase, is returned.

### **Detailed Example:**

Let's walk through the example for `n = 4` to understand how the code works:

1. **Initialization**:
   - `dp = [1, 0, 0, 0, 0]` (Array of size `n+1`, initialized with `0`, except `dp[0] = 1`)

2. **Base Case for Step 1**:
   - Since `n >= 1`, set `dp[1] = 1`
   - `dp = [1, 1, 0, 0, 0]`

3. **Start Iterating from Step 2**:

   - **i = 2**:
     - `dp[2] = dp[1] + dp[0] = 1 + 1 = 2`
     - `dp = [1, 1, 2, 0, 0]`

   - **i = 3**:
     - `dp[3] = dp[2] + dp[1] = 2 + 1 = 3`
     - `dp = [1, 1, 2, 3, 0]`

   - **i = 4**:
     - `dp[4] = dp[3] + dp[2] = 3 + 2 = 5`
     - `dp = [1, 1, 2, 3, 5]`

4. **Final Result**:
   - After the loop ends, `dp[4] = 5`, meaning there are 5 ways to climb to the top of the staircase with 4 steps.

### **Time and Space Complexity**

- **Time Complexity**: **O(n)**
  - We iterate over all steps from `2` to `n` and compute the number of ways to reach each step in constant time. Thus, the overall time complexity is linear, i.e., **O(n)**.

- **Space Complexity**: **O(n)**
  - The space complexity is determined by the `dp` array, which stores the number of ways to reach each step from `0` to `n`. Therefore, the space complexity is **O(n)**.

### **Summary**

- The given code uses the **Bottom-Up Dynamic Programming** approach to solve the problem of counting the number of ways to climb `n` stairs.
- The `dp` array is used to store the number of ways to reach each step. The solution builds from the base cases (step 0 and step 1) and calculates the number of ways to reach higher steps using the recurrence relation `dp[i] = dp[i-1] + dp[i-2]`.
- The time and space complexity are both **O(n)**, making the solution efficient and scalable for larger values of `n`.

---

## Space Optimization
In the standard dynamic programming solution for the "Climbing Stairs" problem, we used a DP array to store the number of ways to reach each step. However, this results in a space complexity of **O(n)**. 

We can **optimize the space complexity** by noting that to calculate the number of ways to reach step `i`, we only need the results of the previous two steps: `i-1` and `i-2`. Hence, we can reduce the space usage by storing only the results for the two most recent steps.

### **Space Optimization Approach**:

- Instead of storing the entire DP table (`dp[i]` for each `i` from 0 to `n`), we only need to store the number of ways to reach the last two steps, i.e., `prev1` (for `i-1`) and `prev2` (for `i-2`).
- After calculating the result for step `i`, we update `prev1` and `prev2` accordingly.

### Source Code 
```cpp
class Solution {
public:
    // Function to calculate the number of ways to climb `n` stairs using optimized space
    int countWays(int n) {
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
```

### **Detailed Explanation of the Code:**
1. **Initialization**:
   ```cpp
   int prev1 = 1;  // Represents the number of ways to reach the step (i-1)
   int prev2 = 1;  // Represents the number of ways to reach the step (i-2)
   ```
   - We initialize two variables, `prev1` and `prev2`, which represent the number of ways to reach the last step (`i-1`) and the second-to-last step (`i-2`), respectively.
   - Initially, both `prev1` and `prev2` are set to `1`, because there is exactly one way to reach both step `0` and step `1`.

2. **Iterating through the stairs**:
   ```cpp
   for(int i = 2; i <= n; i++) {
       int curr = prev1 + prev2;
       prev2 = prev1;
       prev1 = curr;
   }
   ```
   - **`for` loop**: We iterate from `2` to `n` (since we have already handled the base cases for step `0` and step `1`).
   - **`curr = prev1 + prev2`**: The number of ways to reach step `i` is the sum of the ways to reach the two previous steps (`i-1` and `i-2`).
   - **Updating `prev2` and `prev1`**: After calculating `curr`, we update `prev2` to be the value of `prev1` (as `prev1` will now represent the previous step in the next iteration). Then, we update `prev1` to the value of `curr` (as `curr` is the number of ways to reach step `i`).

3. **Return the final result**:
   ```cpp
   return prev1;
   ```
   - After the loop ends, `prev1` will hold the number of ways to reach the `n`th step. This is returned as the result.

### **Example Walkthrough**:

Let's go through the code with an example, `n = 4`, to see how the variables are updated during each iteration:

- **Initialization**:
  - `prev1 = 1` (ways to reach step `1`)
  - `prev2 = 1` (ways to reach step `0`)

- **Iteration**:

  1. **i = 2**:
     - `curr = prev1 + prev2 = 1 + 1 = 2`
     - Update `prev2 = prev1 = 1`
     - Update `prev1 = curr = 2`
  
  2. **i = 3**:
     - `curr = prev1 + prev2 = 2 + 1 = 3`
     - Update `prev2 = prev1 = 2`
     - Update `prev1 = curr = 3`

  3. **i = 4**:
     - `curr = prev1 + prev2 = 3 + 2 = 5`
     - Update `prev2 = prev1 = 3`
     - Update `prev1 = curr = 5`

- **Final result**:
  - After the loop completes, `prev1 = 5`, which is the number of ways to climb 4 stairs.

### **Time and Space Complexity**:

- **Time Complexity**: **O(n)**
  - The algorithm iterates from `2` to `n`, performing constant-time operations for each iteration. Thus, the time complexity is **O(n)**.

- **Space Complexity**: **O(1)**
  - Instead of using a `dp` array to store values for all steps, we only use two variables (`prev1` and `prev2`) to store the last two results. Therefore, the space complexity is **O(1)**, as we only use a constant amount of space.

### **Summary**:
This optimized solution uses only two variables (`prev1` and `prev2`) to store the results for the last two steps, reducing the space complexity from **O(n)** to **O(1)** while maintaining a time complexity of **O(n)**. This makes the solution much more space-efficient.
1. **Initialization**:
   ```cpp
   int prev1 = 1;  // Represents the number of ways to reach the step (i-1)
   int prev2 = 1;  // Represents the number of ways to reach the step (i-2)
   ```
   - We initialize two variables, `prev1` and `prev2`, which represent the number of ways to reach the last step (`i-1`) and the second-to-last step (`i-2`), respectively.
   - Initially, both `prev1` and `prev2` are set to `1`, because there is exactly one way to reach both step `0` and step `1`.

2. **Iterating through the stairs**:
   ```cpp
   for(int i = 2; i <= n; i++) {
       int curr = prev1 + prev2;
       prev2 = prev1;
       prev1 = curr;
   }
   ```
   - **`for` loop**: We iterate from `2` to `n` (since we have already handled the base cases for step `0` and step `1`).
   - **`curr = prev1 + prev2`**: The number of ways to reach step `i` is the sum of the ways to reach the two previous steps (`i-1` and `i-2`).
   - **Updating `prev2` and `prev1`**: After calculating `curr`, we update `prev2` to be the value of `prev1` (as `prev1` will now represent the previous step in the next iteration). Then, we update `prev1` to the value of `curr` (as `curr` is the number of ways to reach step `i`).

3. **Return the final result**:
   ```cpp
   return prev1;
   ```
   - After the loop ends, `prev1` will hold the number of ways to reach the `n`th step. This is returned as the result.

### **Example Walkthrough**:

Let's go through the code with an example, `n = 4`, to see how the variables are updated during each iteration:

- **Initialization**:
  - `prev1 = 1` (ways to reach step `1`)
  - `prev2 = 1` (ways to reach step `0`)

- **Iteration**:

  1. **i = 2**:
     - `curr = prev1 + prev2 = 1 + 1 = 2`
     - Update `prev2 = prev1 = 1`
     - Update `prev1 = curr = 2`
  
  2. **i = 3**:
     - `curr = prev1 + prev2 = 2 + 1 = 3`
     - Update `prev2 = prev1 = 2`
     - Update `prev1 = curr = 3`

  3. **i = 4**:
     - `curr = prev1 + prev2 = 3 + 2 = 5`
     - Update `prev2 = prev1 = 3`
     - Update `prev1 = curr = 5`

- **Final result**:
  - After the loop completes, `prev1 = 5`, which is the number of ways to climb 4 stairs.

### **Time and Space Complexity**:

- **Time Complexity**: **O(n)**
  - The algorithm iterates from `2` to `n`, performing constant-time operations for each iteration. Thus, the time complexity is **O(n)**.

- **Space Complexity**: **O(1)**
  - Instead of using a `dp` array to store values for all steps, we only use two variables (`prev1` and `prev2`) to store the last two results. Therefore, the space complexity is **O(1)**, as we only use a constant amount of space.

### **Summary**:
This optimized solution uses only two variables (`prev1` and `prev2`) to store the results for the last two steps, reducing the space complexity from **O(n)** to **O(1)** while maintaining a time complexity of **O(n)**. This makes the solution much more space-efficient.
