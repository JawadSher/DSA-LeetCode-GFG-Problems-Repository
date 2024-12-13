<h1 align="center">Number of - Dice Rolls - With Target - Sum</h1>

## Problem Statement

**Problem URL :** [Number of Dice Rolls with Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/)

![image](https://github.com/user-attachments/assets/aad31da2-04d6-4f83-9fa7-14fe191ac582)

### Problem Explanation

You are given the following:

1. **`n` Dice**: Each die has `k` faces numbered from `1` to `k`.
2. **Target `target`**: Your goal is to find how many ways you can roll the `n` dice such that the sum of the face-up numbers equals the target.

Since the answer may be very large, return the result **modulo (10^9 + 7)**.

### Key Constraints:

- (1 leq n, k leq 30) (Number of dice and faces are relatively small).
- (1 leq text{target} leq 1000) (The target sum can be large).
- **Each die is independent**, meaning the roll of one die doesn't affect the rolls of the others.

### Examples

#### Example 1:
**Input**:  
```plaintext
n = 1, k = 6, target = 3
```

**Explanation**:  
- We have 1 die with 6 faces: {1, 2, 3, 4, 5, 6}.
- To achieve a sum of 3, there is only **1 way**: Roll a `3`.
  
**Output**:  
```plaintext
1
```


#### Example 2:
**Input**:  
```plaintext
n = 2, k = 6, target = 7
```

**Explanation**:  
- We have 2 dice, each with 6 faces: {1, 2, 3, 4, 5, 6}.
- To achieve a sum of 7, the possible rolls are:
  1. Die 1: 1, Die 2: 6
  2. Die 1: 2, Die 2: 5
  3. Die 1: 3, Die 2: 4
  4. Die 1: 4, Die 2: 3
  5. Die 1: 5, Die 2: 2
  6. Die 1: 6, Die 2: 1
- Total ways = 6.

**Output**:  
```plaintext
6
```

#### Example 3:
**Input**:  
```plaintext
n = 30, k = 30, target = 500
```

**Explanation**:  
- It's not feasible to manually list the combinations due to the large numbers involved.
- Use a dynamic programming approach to efficiently calculate the number of ways.

**Output**:  
```plaintext
222616187
```

### Key Observations:

1. **Base Case**:
   - If `n = 0` (no dice left) and `target = 0`, there's exactly **1 way**: do nothing.
   - If `target > 0` but `n = 0`, there are **0 ways** to achieve the target.

2. **Recursive Transition**:
   - The number of ways to achieve `target` with `n` dice can be calculated by iterating over all possible face values of the dice (`1` to `k`), and reducing the problem to `n-1` dice and `target - face`.

   Mathematically:
   `{ways}(n, target) = sum_{f=1}^{k} text{ways}(n-1, target-f)`

   Where:
   - `n-1` represents rolling one fewer die.
   - `target-f` reduces the target by the current face value.

4. **Dynamic Programming**:
   - Instead of solving the problem recursively for overlapping subproblems, use a **DP table** to store intermediate results.
   - Use modulo (10^9 + 7) to handle large numbers.


### Example with DP Table:

Let’s solve **Example 2** ((n = 2, k = 6, target = 7)) step by step.

- **DP Table**:
  Rows represent the number of dice (`n`), and columns represent the target values (`target`).

  Start with:
  - `dp[0][0] = 1`: There is 1 way to achieve a target of 0 with 0 dice.
  - All other `dp[0][x]` = 0, since no target is possible without dice.

| Dice (`n`)  Target (`target`) | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  |
|--------------------------------|----|----|----|----|----|----|----|----|
| 0                              |  1 |  0 |  0 |  0 |  0 |  0 |  0 |  0 |
| 1                              |  0 |  1 |  1 |  1 |  1 |  1 |  1 |  0 |
| 2                              |  0 |  0 |  1 |  2 |  3 |  4 |  5 |  6 |

- **Explanation**:
  - `dp[1][1] = 1`: With 1 die, there is 1 way to get a sum of 1 (roll a 1).
  - `dp[2][7] = 6`: With 2 dice, there are 6 ways to get a sum of 7 (listed above).

### Approach to Solve:

1. **Recursive with Memoization**:
   - Use recursion to break down the problem into smaller subproblems.
   - Store the results of already computed subproblems in a DP table to avoid redundant calculations.

2. **Iterative Dynamic Programming**:
   - Use a 2D DP array where `dp[n][target]` represents the number of ways to achieve `target` using `n` dice.

3. **Space Optimization**:
   - Reduce the space complexity by maintaining only two arrays (`prev` and `curr`), as shown in the optimized code example.

### Complexity:

1. **Time Complexity**:
   - (O(n times target times k)): Three nested loops for dice, target, and faces.
   
2. **Space Complexity**:
   - (O(target)): Space-optimized solution uses two 1D arrays.

This problem is a classic example of dynamic programming in combinatorics, requiring efficient computation to manage large inputs.

---

## Recursive Approach (caused TLE)

We need to calculate the number of ways to roll `n` dice, each with `k` faces, such that the sum of the dice equals a given target. The dice are numbered from 1 to `k`, and each die can show any value between 1 and `k`. 

### Recursive Approach

The approach taken in the code is **recursive** in nature, which means it solves the problem by breaking it down into smaller subproblems. It keeps reducing the problem by one dice at a time and by adjusting the target after each die roll.

#### Key Ideas:
1. For each dice roll, we can try all possible outcomes (1 through `k` faces).
2. After one dice roll, the target is reduced by the value of the dice.
3. The number of ways to achieve the target with `n` dice is the sum of all ways to achieve the target with `n-1` dice, after subtracting the rolled value from the target.
4. The base cases ensure that we return `0` if it's impossible to achieve the target or if the recursion runs out of dice or target.
   
### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the number of ways to roll the dice to achieve the target
    long long solve(int dice, int faces, int target) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If no dice are left but the target is not zero, it's not a valid way
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is zero, it's also invalid
        if (target == 0 && dice != 0) return 0;

        // Base case: If no dice are left and the target is zero, it's a valid way
        if (dice == 0 && target == 0) return 1;

        // Initialize a variable to store the number of ways
        long long ans = 0;

        // Loop through all possible outcomes for a single dice roll
        for (int i = 1; i <= faces; i++) {
            // Recursively calculate the ways to achieve the remaining target
            // after rolling one die with the current face value `i`
            ans += solve(dice - 1, faces, target - i);
        }

        // Return the total number of ways
        return ans;
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper recursive function
        return solve(n, k, target);
    }
};
```

### Source Code Explanation

#### Function `solve(dice, faces, target)`:

1. **Base Case 1**: 
   ```cpp
   if (target < 0) return 0;
   ```
   - **Explanation**: If the `target` becomes negative, it's impossible to achieve that target, so the function returns `0`.

2. **Base Case 2**: 
   ```cpp
   if (dice == 0 && target != 0) return 0;
   ```
   - **Explanation**: If no dice are left (`dice == 0`), but the `target` is not zero, then it's invalid because we still have a non-zero target without any dice left. Thus, the function returns `0`.

3. **Base Case 3**:
   ```cpp
   if (target == 0 && dice != 0) return 0;
   ```
   - **Explanation**: If the target is zero but there are still dice left (`dice != 0`), it's also invalid because it means that we have unused dice but no target left to achieve. Thus, the function returns `0`.

4. **Base Case 4**:
   ```cpp
   if (dice == 0 && target == 0) return 1;
   ```
   - **Explanation**: If there are no dice left and the `target` is exactly zero, then we have found a valid solution, so the function returns `1`.

5. **Recursive Case**:
   ```cpp
   long long ans = 0;
   for (int i = 1; i <= faces; i++) {
       ans += solve(dice - 1, faces, target - i);
   }
   ```
   - **Explanation**: Here, we start a loop to simulate all possible outcomes for a single dice roll. Each die has values from 1 to `faces`. For each roll (`i`), the function recursively calculates the number of ways to achieve the target by rolling one die with the current face value `i`. We reduce the problem by:
     - Subtracting the value `i` from `target` (i.e., `target - i`).
     - Reducing the number of dice (`dice - 1`).
     - The result is accumulated in `ans`.

6. **Return the result**:
   ```cpp
   return ans;
   ```
   - **Explanation**: After iterating over all possible die rolls (from `1` to `faces`), the function returns the total number of ways to achieve the target with the remaining dice.

#### Function `numRollsToTarget(int n, int k, int target)`:

```cpp
int numRollsToTarget(int n, int k, int target) {
    return solve(n, k, target);
}
```
- **Explanation**: This is a wrapper function that simply calls the `solve` function with the given parameters `n` (number of dice), `k` (number of faces per die), and `target` (the desired target sum).


### Example Walkthrough:

Let’s go through an example to understand how the function works.

#### Example Input:
```cpp
n = 2, k = 6, target = 7
```

We have 2 dice, each with 6 faces numbered from 1 to 6, and the target sum is 7. We want to find how many ways we can roll the dice such that their sum equals 7.

#### Function Execution:

1. **First call**: `solve(2, 6, 7)`
   - We need to achieve a target of 7 with 2 dice.
   - The first die can show any value from 1 to 6. We explore each of these cases:
   
2. **For the first die roll (1)**:
   - We call `solve(1, 6, 6)` because we need 6 more from the second die.
     - The second die can show any value from 1 to 6, and we explore each case:
       - If the second die shows 6, the target is achieved (i.e., `solve(0, 6, 0)` returns 1).
       - If the second die shows 5, we call `solve(0, 6, 1)` (returns 0), and so on for all values of the second die.
   - The total ways for this first roll of 1 is 1 (because only the combination (1, 6) works).

3. **For the first die roll (2)**:
   - We call `solve(1, 6, 5)`, and similarly explore all combinations for the second die.
   - The total ways for this first roll of 2 is 1 (because the combination (2, 5) works).

4. **For the first die roll (3)**:
   - We call `solve(1, 6, 4)`, and similarly explore all combinations for the second die.
   - The total ways for this first roll of 3 is 1 (because the combination (3, 4) works).

5. **For the first die roll (4)**:
   - We call `solve(1, 6, 3)`, and similarly explore all combinations for the second die.
   - The total ways for this first roll of 4 is 1 (because the combination (4, 3) works).

6. **For the first die roll (5)**:
   - We call `solve(1, 6, 2)`, and similarly explore all combinations for the second die.
   - The total ways for this first roll of 5 is 1 (because the combination (5, 2) works).

7. **For the first die roll (6)**:
   - We call `solve(1, 6, 1)`, and similarly explore all combinations for the second die.
   - The total ways for this first roll of 6 is 1 (because the combination (6, 1) works).

In total, there are **6 ways** to achieve a target sum of 7 with 2 dice: (1, 6), (2, 5), (3, 4), (4, 3), (5, 2), (6, 1).

#### Output:
```cpp
6
```

### Time and Space Complexity:

#### Time Complexity:
- The recursive solution makes `k` recursive calls for each dice roll (since there are `k` possible faces on each die), and the recursion depth is `n` (number of dice). Thus, the time complexity is approximately (O(k^n)), where (n) is the number of dice and (k) is the number of faces per die.

#### Space Complexity:
- The space complexity is determined by the maximum depth of the recursion call stack. Since each recursive call decreases the number of dice, the maximum recursion depth is `n`. Thus, the space complexity is (O(n)) due to the recursion stack.

However, in practice, this approach can be inefficient for larger inputs, as the number of recursive calls grows exponentially. An optimized approach using dynamic programming (either memoization or bottom-up) can improve the time complexity significantly.

---

## Top-Down Approach (DP)
The given code uses a **top-down dynamic programming approach** (with memoization) to solve the problem of calculating the number of ways to roll `n` dice, each with `k` faces, such that their sum equals a target.

### Step-by-Step Explanation of the Approach

The key idea in the **top-down dynamic programming approach** is to solve the problem recursively and store the results of subproblems in a memoization table (`dp`) to avoid redundant calculations.

#### Approach:
1. **Base Cases**:
    - If the `target` is negative, return `0` because it's not possible to achieve a negative target with dice rolls.
    - If there are no dice left (`dice == 0`) and the target is not zero, return `0` because it's impossible to achieve a non-zero target with no dice.
    - If there are no dice left and the target is exactly zero (`target == 0`), return `1` because it's a valid way to achieve a sum of zero with zero dice.
    - If there are dice left but the target is zero, return `0` because it's invalid to have dice remaining with a target of zero.

2. **Memoization**:
    - If the result for the current subproblem (`dp[dice][target]`) has already been computed, return the precomputed result to avoid redundant calculations.

3. **Recursive Case**:
    - For each dice roll (from 1 to `k`), subtract the value of the dice roll from the target and call the recursive function for the remaining dice.
    - Sum the results for each dice roll (1 through `k`) and store the result in the memoization table (`dp`).

4. **Final Result**:
    - After processing all dice rolls, return the result from `dp[n][target]`, which represents the number of ways to roll `n` dice with `k` faces to achieve the target sum.

### Example Walkthrough

#### Example 1: `numRollsToTarget(2, 6, 7)`
We are asked to roll 2 dice, each with 6 faces, such that the sum of the dice equals 7. 

**Base Case Examples**:
- `solve(0, 6, 0)` returns `1`, as 0 dice and target 0 is a valid configuration.
- `solve(1, 6, 7)` recursively tries all dice rolls from 1 to 6 and computes the number of ways to achieve the target sum.

### Source Code
```cpp
class Solution {
public:
    // Constant to store the modulo value as the result can be large
    static const int MOD = 1e9 + 7;

    // Recursive function with memoization to calculate the number of ways
    long long solve(int dice, int faces, int target, vector<vector<long long>>& dp) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If no dice are left but the target is not zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is already zero, it's also invalid
        if (target == 0 && dice != 0) return 0;

        // Base case: If no dice are left and the target is zero, it's a valid way
        if (dice == 0 && target == 0) return 1;

        // If the current state has already been computed, return the stored result
        if (dp[dice][target] != -1) return dp[dice][target];

        // Initialize the number of ways for the current state
        long long ans = 0;

        // Loop through all possible outcomes for a single dice roll
        for (int i = 1; i <= faces; i++) {
            // Recursively calculate the ways for the remaining dice and updated target
            ans = (ans + solve(dice - 1, faces, target - i, dp)) % MOD;
        }

        // Store the result in the dp table and return it
        return dp[dice][target] = ans;
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Create a 2D dp table initialized with -1 to indicate uncomputed states
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, -1));

        // Call the recursive helper function with the initial values
        return solve(n, k, target, dp);
    }
};
```
### Source Code Explanation

1. **MOD Constant**:
   ```cpp
   static const int MOD = 1e9 + 7;
   ```
   This constant is used to handle large numbers by returning the result modulo (10^9 + 7 ) to prevent integer overflow and ensure the result stays within bounds.

2. **Recursive `solve` Function**:
   ```cpp
   long long solve(int dice, int faces, int target, vector<vector<long long>>& dp)
   ```
   - `dice`: the number of dice left to roll.
   - `faces`: the number of faces on each die.
   - `target`: the remaining target sum.
   - `dp`: the memoization table storing the results of subproblems.

   **Base Cases**:
   ```cpp
   if (target < 0) return 0;
   if (dice == 0 && target != 0) return 0;
   if (target == 0 && dice != 0) return 0;
   if (dice == 0 && target == 0) return 1;
   ```

   These base cases handle the following:
   - If the target becomes negative, it's impossible to achieve that sum.
   - If there are no dice left and the target isn't zero, it's invalid.
   - If there are dice left but the target is zero, it's also invalid.
   - If no dice are left and the target is zero, it's a valid way (base case).

3. **Memoization Check**:
   ```cpp
   if (dp[dice][target] != -1) return dp[dice][target];
   ```

   If the result for this specific combination of `dice` and `target` has already been computed (not `-1`), return the memoized result.

4. **Recursive Calculation**:
   ```cpp
   long long ans = 0;
   for (int i = 1; i <= faces; i++) {
       ans = (ans + solve(dice - 1, faces, target - i, dp)) % MOD;
   }
   ```

   - Loop over each possible dice roll (from 1 to `faces`).
   - Recursively calculate the number of ways to achieve the remaining target with one less dice, and update `ans`.
   - The result is stored modulo (10^9 + 7 ).

5. **Storing and Returning the Result**:
   ```cpp
   return dp[dice][target] = ans;
   ```

   Store the result in the `dp` table and return it.

### Example Walkthrough

#### Example 1: `numRollsToTarget(2, 6, 7)`

1. **Initial Call**: `solve(2, 6, 7, dp)`
   - We have 2 dice, each with 6 faces, and we want to achieve a sum of 7.

2. **Recursive Steps**:
   - We try all dice rolls from 1 to 6.
   - For each dice roll, we reduce the target and recursively calculate the result for the remaining dice and target.

3. **Base Case**:
   - If we reach `solve(0, 6, 0, dp)`, it will return `1` because no dice and target 0 is valid.
   - Similarly, other base cases return appropriate values, and the memoization table (`dp`) stores these intermediate results.

4. **Final Answer**:
   - The function ultimately returns `6`, which is the number of ways to roll 2 dice to get a sum of 7.

### Time and Space Complexity

#### Time Complexity:
- The time complexity is determined by the number of subproblems that need to be computed and the work done per subproblem.
- For each combination of `dice` and `target`, there are at most `k` recursive calls (one for each dice face).
- Therefore, the time complexity is **O(n * target * k)**, where `n` is the number of dice, `target` is the sum we want to achieve, and `k` is the number of faces on each die.

#### Space Complexity:
- The space complexity is determined by the memoization table `dp`, which has dimensions `(n + 1) x (target + 1)`.
- Therefore, the space complexity is **O(n * target)**, which is the size of the `dp` table.

This approach ensures that we avoid redundant calculations and solve the problem efficiently compared to the naive recursive approach.

---

## Bottom-Up Approach (DP)
In the bottom-up approach, we solve the problem iteratively, starting from the simplest case and building up to the final solution. This approach avoids recursion and computes the result by systematically filling up a dynamic programming (DP) table.

#### Step-by-Step Explanation of the Bottom-Up Approach:

1. **Problem Understanding**: 
   You need to calculate the number of ways to roll `n` dice, each with `k` faces, to achieve a target sum. The faces of the dice are numbered from 1 to `k`, and you want to determine how many ways you can achieve the target sum by rolling all `n` dice.

2. **DP Table Definition**:
   - Create a 2D DP table `dp[d][t]`, where:
     - `d` represents the number of dice used so far.
     - `t` represents the sum we want to achieve.
     - `dp[d][t]` will store the number of ways to achieve sum `t` with `d` dice.

3. **Base Case Initialization**:
   - The base case is when no dice are rolled (`d = 0`). There is exactly one way to achieve the target of `0`, which is to not roll any dice. So, `dp[0][0] = 1`.
   - All other `dp[0][t]` values for `t > 0` are `0` because it's impossible to achieve a positive sum with `0` dice.

4. **Filling the DP Table**:
   - For each number of dice from `1` to `n` (outer loop `d`), and for each target value from `1` to `target` (inner loop `t`), you:
     - Loop through each possible face value from `1` to `k` (inner loop `f`).
     - If the current target `t` is greater than or equal to the face value `f`, add the number of ways to achieve the remaining target (`t - f`) using one fewer die (`d - 1`).

5. **Final Answer**:
   - The final answer will be stored in `dp[n][target]`, which will give the number of ways to achieve the target sum using all `n` dice.

#### Example Walkthrough:

Let's take an example to understand the process.

Suppose we have:
- `n = 2` (two dice)
- `k = 6` (each die has six faces)
- `target = 7` (we want to achieve a sum of 7)

We'll construct a DP table where:
- `dp[0][0] = 1`, meaning there's one way to achieve 0 with 0 dice.
- All other `dp[0][t]` for `t > 0` are 0.

#### Iterative Process:

- **First Die (`d = 1`)**:
  - For `t = 1`, we can get a sum of `1` by rolling `1` on the first die, so `dp[1][1] = 1`.
  - For `t = 2`, we can get a sum of `2` by rolling `2` on the first die, so `dp[1][2] = 1`.
  - Continue similarly for all targets up to `6`.

- **Second Die (`d = 2`)**:
  - For `t = 7`, we can achieve a sum of `7` by:
    - Rolling `1` on the first die and `6` on the second, or
    - Rolling `2` on the first die and `5` on the second, or
    - Rolling `3` on the first die and `4` on the second, or
    - Rolling `4` on the first die and `3` on the second, or
    - Rolling `5` on the first die and `2` on the second, or
    - Rolling `6` on the first die and `1` on the second.
  Thus, `dp[2][7] = 6`.

The final result `dp[2][7] = 6` tells us that there are 6 ways to roll two dice to achieve the target sum of 7.

### Source Code
```cpp
class Solution {
public:
    // Constant to store the modulo value as the result can be large
    static const int MOD = 1e9 + 7;

    // Function to calculate the number of ways to roll dice to achieve the target using bottom-up DP
    long long solve(int dice, int faces, int target) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If there are no dice but the target is non-zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is already zero, it's also invalid
        if (target == 0 && dice != 0) return 0;

        // Create a 2D DP table where dp[d][t] represents the number of ways to achieve
        // the target `t` using `d` dice
        vector<vector<long long>> dp(dice + 1, vector<long long>(target + 1, 0));

        // Initialize the base case: There is exactly one way to achieve a target of 0 with 0 dice
        dp[0][0] = 1;

        // Iterate over the number of dice
        for (int d = 1; d <= dice; d++) {
            // Iterate over the target values
            for (int t = 1; t <= target; t++) {
                long long ans = 0;

                // Consider each face value from 1 to `faces`
                for (int f = 1; f <= faces; f++) {
                    // If the current target `t` is greater than or equal to the face value `f`,
                    // add the number of ways to achieve the remaining target (t-f) with one less die
                    if (t - f >= 0) 
                        ans = (ans + dp[d - 1][t - f]) % MOD;
                }

                // Update the DP table for the current number of dice and target
                dp[d][t] = ans;
            }
        }

        // Return the number of ways to achieve the target with the given number of dice
        return dp[dice][target];
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper function to solve the problem using bottom-up DP
        return solve(n, k, target);
    }
};
```
### Source Code Explanation

```cpp
class Solution {
public:
    // Constant to store the modulo value as the result can be large
    static const int MOD = 1e9 + 7;
```
- `MOD` is used to store the modulo value (10^9 + 7) to ensure that the results do not exceed the limits of the data type and prevent overflow.

```cpp
    // Function to calculate the number of ways to roll dice to achieve the target using bottom-up DP
    long long solve(int dice, int faces, int target) {
```
- This function `solve` computes the number of ways to achieve a target sum with the given number of dice and faces using bottom-up dynamic programming.

```cpp
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;
```
- If the target becomes negative, it's impossible to achieve the sum, so we return 0.

```cpp
        // Base case: If there are no dice but the target is non-zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;
```
- If there are no dice left (`dice == 0`) and the target is non-zero, it's not possible to achieve that target, so we return 0.

```cpp
        // Base case: If there are dice left but the target is already zero, it's also invalid
        if (target == 0 && dice != 0) return 0;
```
- If there are dice left (`dice != 0`) but the target is zero, we can't achieve the sum using non-zero dice, so we return 0.

```cpp
        // Create a 2D DP table where dp[d][t] represents the number of ways to achieve
        // the target `t` using `d` dice
        vector<vector<long long>> dp(dice + 1, vector<long long>(target + 1, 0));
```
- We create a 2D DP table `dp[d][t]` where `dp[d][t]` will store the number of ways to achieve target `t` using `d` dice. Initially, all values are set to 0.

```cpp
        // Initialize the base case: There is exactly one way to achieve a target of 0 with 0 dice
        dp[0][0] = 1;
```
- The base case is that there is one way to achieve a target sum of 0 with 0 dice.

```cpp
        // Iterate over the number of dice
        for (int d = 1; d <= dice; d++) {
            // Iterate over the target values
            for (int t = 1; t <= target; t++) {
                long long ans = 0;
```
- We loop through all the number of dice (`d`) and all target sums (`t`).

```cpp
                // Consider each face value from 1 to `faces`
                for (int f = 1; f <= faces; f++) {
                    // If the current target `t` is greater than or equal to the face value `f`,
                    // add the number of ways to achieve the remaining target (t-f) with one less die
                    if (t - f >= 0) 
                        ans = (ans + dp[d - 1][t - f]) % MOD;
                }
```
- For each face value from `1` to `k`, if the current target `t` is greater than or equal to the face value `f`, we add the number of ways to achieve the target `t - f` using `d - 1` dice to the current value `ans`.

```cpp
                // Update the DP table for the current number of dice and target
                dp[d][t] = ans;
            }
        }
```
- We update the DP table for the current combination of dice and target.

```cpp
        // Return the number of ways to achieve the target with the given number of dice
        return dp[dice][target];
    }
```
- After filling the DP table, we return the number of ways to achieve the target using the given number of dice.

```cpp
    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper function to solve the problem using bottom-up DP
        return solve(n, k, target);
    }
};
```
- This function is the main function that calls the `solve` function to compute the result using the bottom-up approach.

### Example Output Explanation:

Suppose we have:
- `n = 2` (2 dice),
- `k = 6` (each die has 6 faces),
- `target = 7` (we want to achieve a target sum of 7).

We would fill the DP table and calculate the number of ways to achieve a sum of `7` with `2` dice, which will be `6`.

### Time and Space Complexities

#### Time Complexity:
- The time complexity is `O(n * target * k)`, where:
  - `n` is the number of dice,
  - `target` is the target sum,
  - `k` is the number of faces on each die.

In the worst case, we have three nested loops:
- The outer loop runs for `n` dice.
- The middle loop runs for `target` values.
- The inner loop runs for `k` face values.

Thus, the overall time complexity is `O(n * target * k)`.

#### Space Complexity:
- The space complexity is `O(n * target)` because we are using a DP table of size `(n+1) x (target+1)` to store the intermediate results.

Therefore, the space complexity is `O(n * target)`.

---

## Space Optimized Approach (DP)
The space-optimized approach uses dynamic programming to compute the number of ways to achieve a target sum with a specific number of dice and faces. Instead of using a full 2D table to store intermediate results, this approach uses two 1D arrays, `prev` and `curr`, which saves memory and optimizes space complexity.

#### Example Walkthrough:

Consider a scenario where we have `n = 2` dice, `k = 6` faces, and a target sum `t = 7`. The goal is to calculate the number of ways to roll 2 dice, each having faces numbered from 1 to 6, to get a total sum of 7.

##### Step-by-Step Process:

1. **Initialization**:
   - Start by initializing two arrays, `prev` and `curr`, with all elements set to zero. These arrays will store the number of ways to reach a particular target with the previous and current dice, respectively.
   - Initialize `prev[0] = 1` because there is exactly one way to achieve a target sum of 0 with 0 dice: by not rolling any dice.
   
   ```
   prev = [1, 0, 0, 0, 0, 0, 0, 0]  // Only one way to get a sum of 0 with 0 dice.
   curr = [0, 0, 0, 0, 0, 0, 0, 0]
   ```

2. **Iterate Over Dice**:
   - We start by considering the first die (i.e., `d = 1`) and compute the possible target sums for `t = 1` to `7`.
   
   For each target `t` (from 1 to 7), we try all face values `f` (from 1 to 6). For each combination, we check if it's possible to reach the target `t` by subtracting `f` from `t`. If so, we add the number of ways to achieve the target `t - f` with `d-1` dice (stored in `prev`).

3. **Transition**:
   - For `d = 1` (1 die), the calculation for each target `t` is as follows:
   
     ```
     curr[1] = prev[0] (previous target 0, current face 1)
     curr[2] = prev[1] + prev[0] (previous target 1, faces 1 and 2)
     curr[3] = prev[2] + prev[1] + prev[0] (previous target 2, faces 1, 2, and 3)
     ...
     ```

   After completing all face calculations, we copy the `curr` array to `prev` and move on to the next dice.

4. **Final Result**:
   - After processing all dice, the final answer is stored in `prev[target]` (in this case, `prev[7]`), which gives the number of ways to roll `n = 2` dice with faces `k = 6` to achieve the target sum `t = 7`.

### Source Code
```cpp
class Solution {
public:
    // Constant to store the modulo value, used to handle large numbers
    static const int MOD = 1e9 + 7;

    // Function to calculate the number of ways to roll dice to achieve the target using space-optimized DP
    long long solve(int dice, int faces, int target) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;

        // Base case: If there are no dice but the target is non-zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;

        // Base case: If there are dice left but the target is already zero, it's invalid
        if (target == 0 && dice != 0) return 0;

        // Previous and current state arrays for space optimization
        // `prev` represents the number of ways to achieve a target with `d-1` dice
        // `curr` represents the number of ways to achieve a target with `d` dice
        vector<long long> prev(target + 1, 0);
        vector<long long> curr(target + 1, 0);

        // Initialize the base case: There is exactly one way to achieve a target of 0 with 0 dice
        prev[0] = 1;

        // Iterate over the number of dice
        for (int d = 1; d <= dice; d++) {
            // Iterate over the target values
            for (int t = 1; t <= target; t++) {
                long long ans = 0;

                // Consider each face value from 1 to `faces`
                for (int f = 1; f <= faces; f++) {
                    // If the current target `t` is greater than or equal to the face value `f`,
                    // add the number of ways to achieve the remaining target (t-f) with one less die
                    if (t - f >= 0) 
                        ans = (ans + prev[t - f]) % MOD;
                }

                // Update the current state for the current target
                curr[t] = ans;
            }

            // Move to the next dice: Copy `curr` to `prev` for the next iteration
            prev = curr;
        }

        // Return the number of ways to achieve the target with the given number of dice
        return prev[target];
    }

    // Function to calculate the number of ways to roll `n` dice with `k` faces to achieve `target`
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper function to solve the problem using space-optimized DP
        return solve(n, k, target);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Constant to store the modulo value, used to handle large numbers
    static const int MOD = 1e9 + 7;
```
- The constant `MOD` is defined to avoid overflow and ensure that all calculations are performed modulo `1e9 + 7`.

```cpp
    long long solve(int dice, int faces, int target) {
        // Base case: If the target becomes negative, it's not possible to achieve it
        if (target < 0) return 0;
```
- If the target is negative, there’s no way to achieve it, so we return `0`.

```cpp
        // Base case: If there are no dice but the target is non-zero, it's an invalid configuration
        if (dice == 0 && target != 0) return 0;
```
- If there are no dice left, but the target is not zero, it's impossible to achieve the target, so return `0`.

```cpp
        // Base case: If there are dice left but the target is already zero, it's invalid
        if (target == 0 && dice != 0) return 0;
```
- If there are dice left but the target is already zero, it's an invalid configuration, so return `0`.

```cpp
        // Previous and current state arrays for space optimization
        vector<long long> prev(target + 1, 0);
        vector<long long> curr(target + 1, 0);
```
- Two arrays `prev` and `curr` are created to store the number of ways to achieve a target with `d-1` and `d` dice, respectively. These arrays have `target + 1` elements.

```cpp
        // Initialize the base case: There is exactly one way to achieve a target of 0 with 0 dice
        prev[0] = 1;
```
- The base case is initialized: There is exactly one way to achieve a sum of 0 with 0 dice: not rolling any dice.

```cpp
        // Iterate over the number of dice
        for (int d = 1; d <= dice; d++) {
            // Iterate over the target values
            for (int t = 1; t <= target; t++) {
                long long ans = 0;
```
- We loop through each die (`d`) and each target sum (`t`).

```cpp
                // Consider each face value from 1 to `faces`
                for (int f = 1; f <= faces; f++) {
                    // If the current target `t` is greater than or equal to the face value `f`,
                    // add the number of ways to achieve the remaining target (t-f) with one less die
                    if (t - f >= 0) 
                        ans = (ans + prev[t - f]) % MOD;
                }
```
- For each target `t`, we try each face value `f` and check if it's possible to reach `t` by subtracting `f` from `t`. If so, add the number of ways to achieve `t - f` with `d-1` dice (i.e., `prev[t - f]`).

```cpp
                // Update the current state for the current target
                curr[t] = ans;
            }
```
- After processing all faces for a target `t`, store the result in the `curr` array for the current target.

```cpp
            // Move to the next dice: Copy `curr` to `prev` for the next iteration
            prev = curr;
        }
```
- After processing all target sums for a given number of dice, copy the `curr` array to `prev` to prepare for the next dice.

```cpp
        // Return the number of ways to achieve the target with the given number of dice
        return prev[target];
    }
```
- After all dice have been processed, the number of ways to achieve the target is stored in `prev[target]`, so we return this value.

```cpp
    int numRollsToTarget(int n, int k, int target) {
        // Call the helper function to solve the problem using space-optimized DP
        return solve(n, k, target);
    }
};
```
- The main function `numRollsToTarget` calls the helper function `solve` to compute the result.


### Example Output Explanation:

Consider the example with `n = 2`, `k = 6`, and `target = 7`:

- With 2 dice and faces from 1 to 6, we want to calculate how many ways we can sum the results to get 7.
- Using dynamic programming with space optimization:
  - `prev[0] = 1` (1 way to make a sum of 0 with 0 dice)
  - After processing the first die, `curr` will contain the number of ways to achieve each target sum with 1 die.
  - After processing both dice, `prev[7]` will contain the number of ways to achieve a sum of 7 with 2 dice.

Result: `prev[7] = 6`, which means there are 6 ways to roll 2 dice to achieve a sum of 7.


### Time and Space Complexities:

- **Time Complexity**: `O(dice * target * faces)`
  - We loop over `dice` (the number of dice), `target` (the target sum), and `faces` (the number of faces on each die).
  - For each combination of dice, target, and face, we perform a constant time operation (adding values).
  
- **Space Complexity**: `O(target)`
  - Instead of maintaining a full 2D table, we only need two 1D arrays (`prev` and `curr`), each of size `target + 1`. Thus, the space complexity is reduced to `O(target)`.

