<h1 align="center">Min - Cost - Climbing - Stairs</h1>

## Problem Statement

**Problem URL :** [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/description/)

![image](https://github.com/user-attachments/assets/6f51bdf4-1090-42b8-869f-2e6f5fb8d0dd)


### Problem Explanation
The "Min Cost Climbing Stairs" problem is a classic dynamic programming problem where you are given an array representing the cost to reach each step on a staircase. Your task is to find the **minimum cost to reach the top of the staircase**, where you can either climb **1 step** or **2 steps** at a time.

You are given an array `cost[]`, where `cost[i]` represents the cost of stepping on the `i`-th stair. The goal is to reach the top of the staircase by either starting from the first or second step and moving towards the top. You can choose to either:
- Climb **1 step** (i.e., go from step `i` to step `i+1`).
- Climb **2 steps** (i.e., go from step `i` to step `i+2`).

The key idea is to determine the minimum cost of climbing to the top.

#### **Example 1**:

For `cost[] = [10, 15, 20]`, the steps and their respective costs are as follows:

- The first step costs 10.
- The second step costs 15.
- The third step costs 20.

You can either:
- Move from step 0 → step 1 → step 2 (with total cost = 10 + 15 = 25), or
- Move from step 0 → step 2 (with total cost = 10 + 20 = 30).

The minimum cost is **25**.

#### **Example 2**:

For `cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]`, the costs vary, and the challenge is to find the most efficient way to minimize the total cost while climbing to the top.

The main challenge lies in minimizing the total cost while making the least expensive moves. You can climb either 1 or 2 steps at a time, and each move has a different cost associated with it.

### Two Approaches to Solve the Problem:

There are **two main approaches** to solve this problem based on how you think about the direction of the traversal (i.e., whether you are thinking about moving forward or moving backward):

### 1. **From Start to End Approach (i+1, i+2)**

In this approach, you calculate the minimum cost by starting from the bottom (i.e., from the first or second step) and then moving **upward** to the top. 

- You can start from either step 0 or step 1.
- At each step `i`, you have two options:
  - **Move 1 step forward**: from step `i` to step `i+1`.
  - **Move 2 steps forward**: from step `i` to step `i+2`.
  
- The goal is to compute the minimum cost to reach the top by considering both possibilities at every step, and then choosing the minimum between them.

This approach works by either:
- Starting from the first step and moving upward.
- Or starting from the second step and moving upward.

At the end, you pick the minimum cost from the two possible paths.

#### **Recursive Approach:**

In this approach, we start at the base (either the first or second step) and make recursive calls to move upwards. At each step, we have two options:
- Climb 1 step (i.e., go from step `i` to step `i+1`).
- Climb 2 steps (i.e., go from step `i` to step `i+2`).

We then compute the minimum cost to reach the top from the current step, by choosing the minimum of these two options.

#### **Example 1:**

Let’s take `cost[] = [10, 15, 20]`.

We are tasked with finding the minimum cost to reach the top. We will use recursion starting from step 0 or step 1.

1. **Start at step 0:**
   - We can either:
     - Climb 1 step: move to step 1.
     - Climb 2 steps: move to step 2.

2. **At step 1:**
   - We can either:
     - Climb 1 step: move to step 2.
   - The recursive calls return the total costs.

Let’s break it down further:

- `solve(0)`:
  - Option 1: Climb 1 step → `solve(1)`.
  - Option 2: Climb 2 steps → `solve(2)`.
  - We take the minimum of these two costs.

At each recursive call, we move up the staircase and accumulate the costs. The base case will be when we reach or exceed the number of steps, where we return 0.

#### **Recursive Steps:**

1. **`solve(0)`** → min(`cost[0] + solve(1)`, `cost[0] + solve(2)`).
   - **`solve(1)`** → min(`cost[1] + solve(2)`, `cost[1] + solve(3)`).
     - **`solve(2)`** → 0 (since we reached the top).
     - **`solve(3)`** → 0 (past the top).
     - Cost from step 1 = `cost[1] + min(0, 0) = 15 + 0 = 15`.
   - **`solve(2)`** → 0 (base case).
   - Cost from step 0 = `cost[0] + min(15, 0) = 10 + 15 = 25`.

So, the minimum cost to reach the top is **25**.




### 2. **From End to Start Approach (i-1, i-2)**

In this approach, you start from the **end** of the staircase (i.e., the last or second-last step) and then calculate the minimum cost to reach the top **moving backward**.

- You can start from the last step (`n-1`) or the second last step (`n-2`), and then move backward.
- At each step `i`, you have two options:
  - **Move 1 step backward**: from step `i` to step `i-1`.
  - **Move 2 steps backward**: from step `i` to step `i-2`.

- The goal is to compute the minimum cost to reach the first step by considering both options (moving 1 or 2 steps backward) at each step, and then choosing the minimum cost.

By working backward, we can iteratively compute the cost for each step until we reach the starting steps, and then determine the minimum cost from the two starting points.

#### **Recursive Approach:**

In this approach, we start from the top of the staircase (either the last or second last step) and recursively move backward to find the minimum cost to reach the first step.

At each step, we have two options:
- Move 1 step backward (i.e., go from step `i` to step `i-1`).
- Move 2 steps backward (i.e., go from step `i` to step `i-2`).

We compute the minimum cost to reach the base, and then select the minimum of the two options.

#### **Example 2:**

Let’s take `cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]`.

We want to calculate the minimum cost to reach the top, starting from either the second last step or the last step.

1. **Start at step 9 (last step)**:
   - We can either:
     - Move 1 step backward: from step 9 to step 8.
     - Move 2 steps backward: from step 9 to step 7.

2. **At step 8:**
   - We can either:
     - Move 1 step backward: from step 8 to step 7.
     - Move 2 steps backward: from step 8 to step 6.
   
Let’s break it down step-by-step recursively:

- `solve(9)`:
  - Option 1: Move 1 step → `solve(8)`.
  - Option 2: Move 2 steps → `solve(7)`.
  - We take the minimum of these two.

At each recursive call, we move backward and calculate the cost. The base case is when we reach the first step (index 0), where we return the cost of that step.

#### **Recursive Steps:**

1. **`solve(9)`** → min(`cost[9] + solve(8)`, `cost[9] + solve(7)`).
   - **`solve(8)`** → min(`cost[8] + solve(7)`, `cost[8] + solve(6)`).
     - **`solve(7)`** → min(`cost[7] + solve(6)`, `cost[7] + solve(5)`).
       - Continue recursively calculating costs from step to step until reaching step 0.
       
2. Finally, we return the minimum cost from step 0 or step 1.


### **Conclusion:**

Both approaches solve the problem by calculating the minimum cost to reach the top of the staircase. However, they differ in their direction of traversal:

- **From Start to End (i+1, i+2)**: We start at step 0 (or step 1) and move upwards, making recursive calls for each step until we reach the top.
- **From End to Start (i-1, i-2)**: We start at the top and work backward, making recursive calls for each step until we reach step 0.

Both approaches involve breaking down the problem into smaller subproblems (recursive calls) and finding the minimum cost at each step by considering both possible moves (1 step or 2 steps).

## Problem Solution (Recursive)
Let's break down the code line by line, explain each part in detail, and illustrate it with examples.

#### **Approach 1: Starting from the Beginning of the Stairs**

```cpp
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
```

### **Line-by-Line Explanation:**

#### **Line 1: `class Solution {`**
- This defines the class `Solution`, which contains the methods for solving the problem.

#### **Line 2: `public:`**
- This marks the section of the class that is publicly accessible. All methods defined below this line are accessible from outside the class.

#### **Line 3-4: `int solve(vector<int>& cost, int i) {`**
- Defines the helper function `solve`, which is a **recursive function** that will be used to calculate the minimum cost starting from a given step `i`. The function accepts:
  - `cost`: A vector representing the cost of climbing each step.
  - `i`: The current step index.

#### **Line 5: `if (i >= cost.size()) return 0;`**
- **Base case**: If `i` exceeds or equals the size of the `cost` vector, this means we've either reached the top of the stairs or beyond. Thus, there’s no cost to incur, so it returns `0`.
  
#### **Line 6-7: `return cost[i] + min(solve(cost, i + 1), solve(cost, i + 2));`**
- **Recursive case**:
  - The function first adds the **cost of the current step (`cost[i]`)**.
  - Then, it calculates the minimum cost of moving forward 1 step or 2 steps:
    - `solve(cost, i + 1)` calculates the cost if we move 1 step forward.
    - `solve(cost, i + 2)` calculates the cost if we move 2 steps forward.
  - The function then returns the current step's cost plus the minimum of the two possible future steps.

#### **Line 8: `}`**
- Ends the definition of the `solve` function.

#### **Line 9: `int minCostClimbingStairs(vector<int>& cost) {`**
- This is the main function that will be called from outside to solve the problem. It calculates the minimum cost to climb the stairs starting from either the 0th or the 1st step.

#### **Line 10: `return min(solve(cost, 0), solve(cost, 1));`**
- This line calls the `solve` function twice, once for starting from step 0 and once from step 1.
  - `solve(cost, 0)` starts the recursion from the 0th step.
  - `solve(cost, 1)` starts the recursion from the 1st step.
- It returns the minimum of the two results, which gives the lowest cost to reach the top.

#### **Line 11: `}`**
- Ends the definition of the `minCostClimbingStairs` function.

#### **Line 12: `};`**
- Closes the `Solution` class definition.



### **Example to Illustrate Approach 1:**

Let's use an example to see how this approach works.

#### Example 1: `cost = [10, 15, 20]`

We start at step 0 or step 1:

1. **Starting from step 0 (i = 0)**:
   - We can either move 1 step (i = 1) or 2 steps (i = 2).
   - Moving 1 step (i = 1): We need to calculate the cost from `i = 1`.
     - From `i = 1`, we can either move 1 step (i = 2) or 2 steps (i = 3). Since `i = 3` exceeds the array size, we stop and return 0.
     - Moving 1 step: `cost[1] + 0 = 15 + 0 = 15`
     - Moving 2 steps: `cost[2] + 0 = 20 + 0 = 20`
     - Minimum cost from i = 1: `min(15, 20) = 15`
   - Therefore, cost from i = 0 is `cost[0] + min(15, 20) = 10 + 15 = 25`.

2. **Starting from step 1 (i = 1)**:
   - We can either move 1 step (i = 2) or 2 steps (i = 3).
   - Moving 1 step (i = 2): Since `i = 3` exceeds the array size, we stop and return 0.
     - Cost: `cost[2] + 0 = 20 + 0 = 20`
   - Therefore, cost from i = 1 is 20.

Finally, the minimum cost to climb the stairs is `min(25, 20) = 20`.



### **Time and Space Complexity of Approach 1:**

1. **Time Complexity**:
   - **Exponential Time Complexity**: The recursive function explores all possible paths (1-step or 2-steps at each level). For each step, it recursively calls two functions, leading to an exponential growth in the number of calls.
   - **Worst Case**: O(2^n), where `n` is the number of steps.

2. **Space Complexity**:
   - **Recursion Stack**: The maximum recursion depth is proportional to the number of steps `n`, as we are going down one step at a time. Thus, the space complexity is O(n) due to the recursion stack.


#### **Approach 2: Starting from the End of the Stairs**

```cpp
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
```

### **Line-by-Line Explanation:**

1. **`solve(vector<int>& cost, int i)` function**:
   - The function calculates the minimum cost to reach the top of the stairs starting from the index `i` (working backwards).
   - **Base cases**: If `i == 0`, the cost is just the cost of step 0. If `i == 1`, the cost is the cost of step 1.
   - **Recursive case**: For any step `i > 1`, the function recursively calculates the cost of moving from step `i-1` and step `i-2`, and returns the minimum of those two.

2. **`minCostClimbingStairs(vector<int>& cost)` function**:
   - The function starts at either the last step or the second last step, as the top can be reached from these steps.
   - It returns the minimum of the two results, thus finding the least expensive way to reach the top.



### **Example to Illustrate Approach 2:**

For the same example `cost = [10, 15, 20]`:

1. **Starting from the last step (i = 2)**:
   - We have two choices: 
     - Coming from step `i = 1`: `cost[2] + solve(cost, 1) = 20 + 15 = 35`
     - Coming from step `i = 0`: `cost[2] + solve(cost, 0) = 20 + 10 = 30`
   - The minimum cost to reach step 2 is `min(35, 30) = 30`.

2. **Starting from the second last step (i = 1)**:
   - We can only come from step `i = 0`: `cost[1] + solve(cost, 0) = 15 + 10 = 25`.
   - So, the final result is `min(30, 25) = 25`.

### **Time and Space Complexity of Approach 2:**

1. **Time Complexity**:
   - **Exponential Time Complexity**: Just like Approach 1, this approach also uses recursion and explores multiple paths. The time complexity is also O(2^n) in the worst case.
  
2. **Space Complexity**:
   - The space complexity is O(n), as the maximum recursion depth can be `n` (in the worst case).

---

### **Top-Down Approach (Memoization)**

The **Top-Down Approach** is an optimization technique used to solve recursive problems efficiently by storing the results of subproblems in a data structure (usually an array or map) to avoid recomputing them. This technique is also known as **memoization**.

In this approach, you solve the problem starting from the top (in this case, the last step), and whenever you solve a subproblem, you store the result to be reused in subsequent calculations. This helps reduce the time complexity from exponential to linear by avoiding redundant calculations.

### **Steps in the Top-Down Approach:**

1. **Recursion with Memoization**:
   - We use recursion to break the problem into smaller subproblems (finding the minimum cost to reach a certain step).
   - We store the results of subproblems in a memoization array `dp`. The index `i` of `dp` stores the minimum cost to reach step `i`.
   - If a subproblem has already been computed (i.e., `dp[i]` is not -1), we simply return the stored result to avoid recalculating.

2. **Base Case**:
   - For the base case, if we are at the first step (`i == 0`) or the second step (`i == 1`), the cost is simply the cost of that step.

3. **Recursive Case**:
   - For each step `i`, we calculate the minimum cost by considering two possibilities:
     - **Step 1**: Moving 1 step backward (from `i - 1`).
     - **Step 2**: Moving 2 steps backward (from `i - 2`).
   - The minimum cost for reaching step `i` is the cost at step `i` plus the minimum of the two previous steps.

4. **Memoization**:
   - Once we calculate the minimum cost for a step `i`, we store the result in the `dp` array to reuse it in future recursive calls.

#### Source Code
```cpp
class Solution {
public:
    // Function to recursively calculate the minimum cost to climb stairs starting from index `i`
    int solve(vector<int>& cost, int i, vector<int>& dp) {
        // Base case 1: If we are at the first step, the cost is simply the cost of step 0
        if (i == 0) return cost[0];
        // Base case 2: If we are at the second step, the cost is simply the cost of step 1
        if (i == 1) return cost[1];

        // Step 3: If the result for this step is already computed (memoized), return it
        if (dp[i] != -1) return dp[i];

        // Step 2: Calculate the minimum cost for the current step
        // Add the cost at the current step to the minimum of:
        //   - the cost of taking 1 step back
        //   - the cost of taking 2 steps back
        dp[i] = cost[i] + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));

        // Return the memoized result
        return dp[i];
    }

    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        // Step 1: Create a memoization array `dp` initialized with -1
        // The size of `dp` is `cost.size() + 1` to handle the maximum index
        vector<int> dp(cost.size() + 1, -1);

        // Start from the last two possible steps to reach the top and return the minimum
        return min(solve(cost, cost.size() - 1, dp), solve(cost, cost.size() - 2, dp));
    }
};
```

### **Line-by-Line Explanation of the Code:**

```cpp
class Solution {
public:
    // Function to recursively calculate the minimum cost to climb stairs starting from index `i`
    int solve(vector<int>& cost, int i, vector<int>& dp) {
```
- **Line 1-2**: Defines the recursive helper function `solve`, which calculates the minimum cost to reach step `i`. It takes three arguments:
  - `cost`: A vector containing the cost of each step.
  - `i`: The current step index.
  - `dp`: A memoization array that stores the minimum cost to reach each step.

```cpp
        // Base case 1: If we are at the first step, the cost is simply the cost of step 0
        if (i == 0) return cost[0];
```
- **Line 3-4**: **Base Case 1**: If the current step `i` is 0 (the first step), the cost to reach this step is just the cost of step 0 itself, which is `cost[0]`.

```cpp
        // Base case 2: If we are at the second step, the cost is simply the cost of step 1
        if (i == 1) return cost[1];
```
- **Line 5-6**: **Base Case 2**: If the current step `i` is 1 (the second step), the cost to reach this step is simply the cost of step 1, which is `cost[1]`.

```cpp
        // Step 3: If the result for this step is already computed (memoized), return it
        if (dp[i] != -1) return dp[i];
```
- **Line 7-8**: **Memoization Check**: If the result for the current step `i` has already been computed and stored in the `dp` array (`dp[i] != -1`), return the memoized value. This prevents recomputing the same value multiple times, which is a major optimization.

```cpp
        // Step 2: Calculate the minimum cost for the current step
        // Add the cost at the current step to the minimum of:
        //   - the cost of taking 1 step back
        //   - the cost of taking 2 steps back
        dp[i] = cost[i] + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));
```
- **Line 9-11**: **Recursive Case**:
  - If the result for the current step has not been computed, we calculate the minimum cost for reaching step `i`. This is done by considering two options:
    - **Option 1**: Moving 1 step back from `i-1` (i.e., `solve(cost, i - 1, dp)`).
    - **Option 2**: Moving 2 steps back from `i-2` (i.e., `solve(cost, i - 2, dp)`).
  - The minimum cost to reach step `i` is the cost at step `i` plus the minimum of the two options.
  - We store this value in the `dp[i]` array to memoize the result for future use.

```cpp
        // Return the memoized result
        return dp[i];
    }
```
- **Line 12-13**: **Return the Memoized Result**: After calculating the minimum cost for step `i`, we return the value stored in `dp[i]`.

```cpp
    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
```
- **Line 14-15**: Defines the main function `minCostClimbingStairs`, which calculates the minimum cost to reach the top of the stairs. It takes the `cost` vector as an argument.

```cpp
        // Step 1: Create a memoization array `dp` initialized with -1
        // The size of `dp` is `cost.size() + 1` to handle the maximum index
        vector<int> dp(cost.size() + 1, -1);
```
- **Line 16-17**: **Initialize the Memoization Array**:
  - A `dp` array of size `cost.size() + 1` is created and initialized with `-1`. The extra element is used to handle the edge case where we might be calculating the minimum cost for an index one step beyond the last element in the `cost` array.

```cpp
        // Start from the last two possible steps to reach the top and return the minimum
        return min(solve(cost, cost.size() - 1, dp), solve(cost, cost.size() - 2, dp));
    }
};
```
- **Line 18-20**: 
  - We call the `solve` function twice to calculate the minimum cost starting from the last step (`cost.size() - 1`) and the second last step (`cost.size() - 2`).
  - We return the minimum of the two values as the final answer, as we can either start from the second last step or the last step to reach the top.

### **Time and Space Complexity:**

#### **Time Complexity:**
- **Time Complexity**: O(n), where `n` is the number of steps in the `cost` array.
  - **Why?**: Each subproblem is solved once and its result is memoized (stored in the `dp` array). Therefore, we only need to compute the minimum cost for each step once, resulting in a linear time complexity.

#### **Space Complexity:**
- **Space Complexity**: O(n), where `n` is the number of steps in the `cost` array.
  - **Why?**: We use the `dp` array of size `n+1` to store the minimum cost for each step. Additionally, the recursive function uses space for the call stack, which can go up to a maximum depth of `n` (in the worst case, when we recurse to the first step).

### **Example:**

Let’s take an example to demonstrate how the code works.

#### Example 1: `cost = [10, 15, 20]`

1. **Initialization**: The `dp` array is initialized as `[-1, -1, -1, -1]` (size is `cost.size() + 1`).

2. **First Recursive Call**: We start by calling `solve(cost, 2, dp)`.
   - We calculate the cost of moving to step 2 from step 1 (`solve(cost, 1, dp)`) and step 0 (`solve(cost, 0, dp)`).
   - These are base cases, so `solve(cost, 1, dp)` returns `15`, and `solve(cost, 0, dp)` returns `10`.
   - The minimum cost to reach step 2 is `20 + min(15, 10) = 30`.
   - The `dp` array is updated: `dp = [10, 15, 30, -1]`.

3. **Second Recursive Call**: We also call `solve(cost, 1, dp)` from the main function.
   - This is a base case, and it returns `15`.

4. **Final Result**: The minimum cost to reach the top is `min(30, 15) = 15`.

Thus, the function will return `15` as the minimum cost to climb the stairs.

---

### **Bottom-Up Approach (Tabulation)**
This new code implements the **Tabulation (Bottom-Up)** approach to solve the **minimum cost to climb stairs** problem efficiently. Let's break it down step by step.

- We used recursion with memoization to calculate the minimum cost. Here, you recursively calculate the cost for each step starting from the bottom, while memoizing the results to avoid redundant calculations.

#### **Approach:**
In the **Tabulation** approach, we solve the problem iteratively and fill up a table (or array) starting from the base case. This is an optimal way to compute dynamic programming problems as we avoid recursion.

#### Source Code
```cpp
class Solution {
public:
    // Function to calculate the minimum cost to climb the stairs using tabulation
    int solve(vector<int>& cost, int n) {
        // Step 1: Create a DP table `dp` of size `n+1` to store the minimum cost at each step
        vector<int> dp(n + 1);

        // Step 2: Initialize the base cases
        // If starting at the first step, the cost is simply `cost[0]`
        dp[0] = cost[0];
        // If starting at the second step, the cost is simply `cost[1]`
        dp[1] = cost[1];

        // Step 3: Fill the DP table for steps from 2 to n-1
        for (int i = 2; i < n; i++) {
            // The minimum cost to reach step `i` is the cost at step `i` plus
            // the minimum cost to reach either of the two previous steps
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Step 4: The minimum cost to reach the top is the minimum of the last two steps
        return min(dp[n - 1], dp[n - 2]);
    }

    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        // Call the `solve` function with the cost array and its size
        return solve(cost, cost.size());
    }
};
```

### **Explanation of the Code:**

1. **Function Definition:**
    ```cpp
    int solve(vector<int>& cost, int n) {
    ```
    - The `solve` function takes the `cost` array and the number of steps `n` as inputs.
    - We will iteratively calculate the minimum cost for each step and store it in the DP table.

2. **DP Table Initialization:**
    ```cpp
    vector<int> dp(n + 1);
    ```
    - Create a `dp` array of size `n + 1`. This array will hold the minimum cost to reach each step. We need `n + 1` because the problem considers an imaginary "step" at the top (just beyond the last step).
    - `dp[i]` will store the minimum cost to reach step `i`.

3. **Base Case Initialization:**
    ```cpp
    dp[0] = cost[0];
    dp[1] = cost[1];
    ```
    - The first two steps are base cases:
      - `dp[0]` is simply the cost of the first step, i.e., `cost[0]`.
      - `dp[1]` is simply the cost of the second step, i.e., `cost[1]`.

4. **Filling the DP Table:**
    ```cpp
    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    ```
    - Now, we start from step `2` and calculate the minimum cost for each step up to `n - 1`.
    - For each step `i`, we calculate:
        - The cost of reaching `i` is the cost at that step (`cost[i]`), plus the minimum of:
            - The cost to reach `i-1` (previous step), i.e., `dp[i-1]`.
            - The cost to reach `i-2` (step before the previous one), i.e., `dp[i-2]`.
    - This ensures we are considering the minimum possible cost to get to the current step.

5. **Return the Minimum Cost to Reach the Top:**
    ```cpp
    return min(dp[n - 1], dp[n - 2]);
    ```
    - Once the DP table is filled, the minimum cost to reach the top of the stairs is the minimum of either the last step (`dp[n-1]`) or the step just before it (`dp[n-2]`), because you can take either the last step or jump directly to the top from the second-to-last step.

6. **Main Function Call:**
    ```cpp
    return solve(cost, cost.size());
    ```
    - The `minCostClimbingStairs` function calls the `solve` function, passing the `cost` array and its size (`cost.size()`).

### **Example Walkthrough:**

Let’s walk through the code with an example:
- Given the `cost` array: `{10, 15, 20, 25, 30}`.

1. Initialize `dp`:
    ```cpp
    dp = {10, 15, 0, 0, 0}
    ```

2. Fill the DP table starting from `i = 2`:
    - For `i = 2`:
      ```cpp
      dp[2] = cost[2] + min(dp[1], dp[0]) = 20 + min(15, 10) = 20 + 10 = 30
      ```
      - `dp = {10, 15, 30, 0, 0}`

    - For `i = 3`:
      ```cpp
      dp[3] = cost[3] + min(dp[2], dp[1]) = 25 + min(30, 15) = 25 + 15 = 40
      ```
      - `dp = {10, 15, 30, 40, 0}`

    - For `i = 4`:
      ```cpp
      dp[4] = cost[4] + min(dp[3], dp[2]) = 30 + min(40, 30) = 30 + 30 = 60
      ```
      - `dp = {10, 15, 30, 40, 60}`

3. The minimum cost to reach the top is the minimum of `dp[4]` and `dp[3]`:
    ```cpp
    return min(dp[4], dp[3]) = min(60, 40) = 40
    ```

### **Time and Space Complexity:**

- **Time Complexity:**  
    The time complexity is `O(n)` because we iterate through the `cost` array once, where `n` is the number of steps.

- **Space Complexity:**  
    The space complexity is `O(n)` due to the `dp` array storing the minimum cost for each step.

This tabulation approach is more efficient in terms of space and computation when compared to the top-down approach, which uses recursion and memoization.

---

### Space Optimization

This new solution implements an **optimized tabulation approach** to solve the **minimum cost to climb stairs** problem. Let's go through the solution line by line.

#### Source Code
```cpp
class Solution {
public:
    // Function to calculate the minimum cost to climb the stairs using optimized tabulation
    int solve(vector<int>& cost, int n) {
        // Step 1: Initialize two variables to store the minimum cost for the previous two steps
        int i_1 = cost[1];  // Represents the cost to reach the first step (index 1)
        int i_2 = cost[0];  // Represents the cost to reach the second step (index 0)

        // Step 2: Iterate through the cost array starting from the third step (index 2)
        for (int i = 2; i < n; i++) {
            // The minimum cost to reach the current step is the cost at this step plus the minimum
            // of the costs from the two previous steps (i-1 and i-2)
            int curr = cost[i] + min(i_1, i_2);
            
            // Update the variables for the next iteration
            i_2 = i_1;  // Move the previous step to i_2
            i_1 = curr;  // Set the current minimum cost as i_1
        }

        // Step 3: The minimum cost to reach the top is the minimum of the last two steps
        return min(i_1, i_2);
    }

    // Main function to calculate the minimum cost to climb to the top of the stairs
    int minCostClimbingStairs(vector<int>& cost) {
        // Call the `solve` function with the cost array and its size
        return solve(cost, cost.size());
    }
};
```
### **Source-code explanation**
1. **Overview of Optimization:**
    - The main idea of optimization here is that we do not need to keep track of the entire `dp` table. Instead, we only need the minimum costs of the previous two steps at each point. This reduces the space complexity from `O(n)` to `O(1)` (constant space).

2. **Function Definition:**
    ```cpp
    int solve(vector<int>& cost, int n) {
    ```
    - The `solve` function takes the `cost` array and the number of steps `n` as input.
    - It calculates the minimum cost to reach the top of the stairs using the optimized approach.

3. **Initialization:**
    ```cpp
    int i_1 = cost[1];  // Represents the cost to reach the first step (index 1)
    int i_2 = cost[0];  // Represents the cost to reach the second step (index 0)
    ```
    - Instead of storing the cost for every step, we only need the cost to reach the two previous steps (`i_1` and `i_2`).
    - `i_1` stores the minimum cost to reach step 1 (`cost[1]`).
    - `i_2` stores the minimum cost to reach step 0 (`cost[0]`).

4. **Loop to Compute Minimum Costs:**
    ```cpp
    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(i_1, i_2);
        i_2 = i_1;  // Move the previous step to i_2
        i_1 = curr;  // Set the current minimum cost as i_1
    }
    ```
    - Start a loop from the third step (index 2) to `n - 1`:
        - For each step `i`, calculate the minimum cost to reach that step:
            - The cost is the cost of the current step (`cost[i]`) plus the minimum of the costs of the previous two steps (`i_1` and `i_2`).
        - Update the previous two steps for the next iteration:
            - Set `i_2` to the value of `i_1` (i.e., move `i_1` to `i_2`).
            - Set `i_1` to the newly calculated minimum cost (`curr`).

5. **Return the Result:**
    ```cpp
    return min(i_1, i_2);
    ```
    - After the loop ends, the minimum cost to reach the top will be the minimum of `i_1` (the cost to reach the last step) and `i_2` (the cost to reach the second-to-last step).
    - We return the minimum of these two values because, at the end, you can either reach the top from the last step or the second-to-last step.

6. **Main Function:**
    ```cpp
    return solve(cost, cost.size());
    ```
    - The main function, `minCostClimbingStairs`, calls the `solve` function with the `cost` array and its size (`cost.size()`).

### **Example Walkthrough:**

Let’s walk through an example:

#### Example 1: 
Given the `cost` array: `{10, 15, 20, 25, 30}`.

1. **Initial State:**
   - `i_1 = 15` (cost to reach the first step)
   - `i_2 = 10` (cost to reach the second step)

2. **Iteration 1 (i = 2):**
   - `curr = cost[2] + min(i_1, i_2) = 20 + min(15, 10) = 20 + 10 = 30`
   - Update:
     - `i_2 = i_1 = 15`
     - `i_1 = curr = 30`
   - Current state: `i_1 = 30`, `i_2 = 15`

3. **Iteration 2 (i = 3):**
   - `curr = cost[3] + min(i_1, i_2) = 25 + min(30, 15) = 25 + 15 = 40`
   - Update:
     - `i_2 = i_1 = 30`
     - `i_1 = curr = 40`
   - Current state: `i_1 = 40`, `i_2 = 30`

4. **Iteration 3 (i = 4):**
   - `curr = cost[4] + min(i_1, i_2) = 30 + min(40, 30) = 30 + 30 = 60`
   - Update:
     - `i_2 = i_1 = 40`
     - `i_1 = curr = 60`
   - Current state: `i_1 = 60`, `i_2 = 40`

5. **Final Result:**
   - Return the minimum of `i_1` and `i_2`: `min(60, 40) = 40`.

So, the minimum cost to reach the top of the stairs is `40`.

### **Time and Space Complexity:**

- **Time Complexity:**
  - The loop runs `n - 2` times (where `n` is the number of steps), so the time complexity is `O(n)`.

- **Space Complexity:**
  - Since we are only using two variables (`i_1` and `i_2`), the space complexity is **optimized to `O(1)`** (constant space).

### **Advantages of This Approach:**
1. **Space Optimization:** We reduced the space complexity from `O(n)` to `O(1)` by storing only the minimum costs of the last two steps instead of the entire `dp` array.
2. **Efficiency:** The time complexity remains `O(n)`, which is optimal for this problem.

This solution is both time-efficient and space-efficient.
