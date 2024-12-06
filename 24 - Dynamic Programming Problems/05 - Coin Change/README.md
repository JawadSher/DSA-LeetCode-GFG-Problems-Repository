<h1 align="center">Coin - Change</h1>

## Problem Statement

**Problem URL :** [Coin Change](https://leetcode.com/problems/coin-change/description/)

![image](https://github.com/user-attachments/assets/3862feb4-4aa0-49b7-8bfa-73bc41a050d2)

### Problem Explanation
The **Coin Change** problem is a classic optimization problem in which you are tasked with finding the minimum number of coins needed to achieve a specific target amount using a given set of coin denominations. Let’s break it down step by step:

#### Inputs:
1. **`coins[]`**: An array of positive integers representing available coin denominations.
   - Example: `[1, 2, 5]` means you have coins of values `1`, `2`, and `5`.
   
2. **`amount`**: A non-negative integer representing the target amount you need to form.
   - Example: `amount = 11` means you need to form the value `11` using the coins in `coins[]`.

#### Outputs:
- **Minimum Number of Coins**: The smallest number of coins needed to form the given `amount`.
  - Example: To form `11` with `[1, 2, 5]`, the answer is `3` (`5 + 5 + 1`).

- **Special Case**:
  - If it is **not possible** to form the `amount` with the given coins, return `-1`.
  - Example: With `coins = [2]` and `amount = 3`, the answer is `-1` because no combination of `2` can add up to `3`.



### **2. Constraints**

1. **Coin Usage**:
   - Each coin in `coins[]` can be used **multiple times** (unlimited supply of each coin).
   - Example: If `coins = [2]`, you can use `2` as many times as needed (e.g., `2 + 2 + 2`).

2. **Optimization**:
   - The goal is to minimize the number of coins used to achieve the target amount.
   - Example: To form `11` with `[1, 2, 5]`, you can use `5 + 5 + 1` (3 coins) instead of `1 + 1 + ... + 1` (11 coins).

3. **Edge Cases**:
   - If `amount = 0`: No coins are needed; the answer is `0`.
   - If `coins[] = []`: You cannot form any amount; the answer is `-1`.



### **3. Problem Statement in Mathematical Terms**

You are given:
1. A set of integers ( C = {c_1, c_2, ..., c_n} ), where each ( c_i > 0 ) (coin denominations).
2. A target amount ( T ).

Find the minimum number of coins ( m ) such that:
[
c_{i_1} + c_{i_2} + ... + c_{i_m} = T
]
If no such combination exists, return `-1`.



### **4. Real-Life Analogy**

Imagine you are at a store, and you need to pay exactly $11. You only have coins worth $1, $2, and $5. The cashier doesn't accept overpayment or underpayment. Your goal is to pay $11 with the fewest coins possible.



### **5. Examples**

#### **Example 1: `coins = [1, 2, 5], amount = 11`**
- Possible combinations:
  - Use eleven `1` coins: `1 + 1 + ... + 1 = 11` (11 coins).
  - Use five `2` coins and one `1`: `2 + 2 + 2 + 2 + 2 + 1 = 11` (6 coins).
  - Use two `5` coins and one `1`: `5 + 5 + 1 = 11` (3 coins).
- The minimum is **3 coins**: `5 + 5 + 1`.



#### **Example 2: `coins = [2], amount = 3`**
- Possible combinations:
  - You cannot form `3` because `2` cannot be added repeatedly to equal `3`.
- Result: **`-1`**.



#### **Example 3: `coins = [1], amount = 0`**
- You don't need any coins to make `0`.
- Result: **`0`**.



### **6. Challenges and Insights**

#### **A. Can We Always Form the Amount?**
- Not necessarily. If the coin denominations cannot divide the target amount or there is no combination of coins that sums to it, the answer will be `-1`.
- Example: `coins = [3], amount = 7`. You cannot form `7` using multiples of `3`.



#### **B. Multiple Solutions Are Possible**
- There might be multiple ways to form the same amount, but only the solution with the **fewest coins** matters.
- Example: `coins = [1, 2, 5], amount = 6`.
  - Using `1` coins: `1 + 1 + 1 + 1 + 1 + 1` (6 coins).
  - Using `2` coins: `2 + 2 + 2` (3 coins).
  - The optimal solution is **3 coins**: `2 + 2 + 2`.



#### **C. What Makes the Problem Challenging?**
1. The denominations can be irregular, making it difficult to identify a pattern.
   - Example: `coins = [7, 10, 1], amount = 14`.
   - Intuition might suggest using two `7`s, but the optimal solution is `10 + 1 + 1 + 1 + 1`.

2. Some amounts may not be possible at all:
   - Example: `coins = [2, 4], amount = 7`. There's no valid combination.



### **7. Key Intuition**

The problem can be thought of as solving for **subproblems**:
- To compute the minimum coins for amount ( T ), first compute the minimum coins needed for smaller amounts ( T - c ), where ( c ) is a coin denomination.
- Example: To solve for ( T = 11 ) with ( coins = [1, 2, 5] ):
  - Solve for ( T = 10 ), ( T = 9 ), ( T = 6 ), etc., recursively or iteratively.

This approach leverages the **optimal substructure** property: the solution to the whole problem depends on solutions to its smaller subproblems.



### **8. Applications**

1. **Financial Systems**:
   - Calculating the minimum number of coins/bills needed for a specific transaction.
   
2. **Resource Allocation**:
   - Distributing limited resources in an optimized way.

3. **Game Design**:
   - Minimizing the moves needed to achieve a target state in games.

---

## Recursive Approach (caused LTE)
The recursive solution for the **Coin Change** problem involves breaking the problem into smaller subproblems using the principle of **divide and conquer**. The goal is to compute the minimum number of coins required to form the target `amount`. Here's the detailed step-by-step explanation:

#### **Step 1: Base Cases**
1. **If the target amount (`x`) is 0**:
   - No coins are needed. Return `0`.

2. **If the target amount (`x`) becomes negative**:
   - It's impossible to form a negative amount. Return an invalid result, represented by `INT_MAX`.



#### **Step 2: Recursive Relation**
- For a given amount `x`, iterate over each coin in the `coins` array. Subtract the coin's value from `x` and recursively solve for the remaining amount (`x - coin`).
- If the result of the recursive call is valid (not `INT_MAX`), calculate the total number of coins required by adding `1` to include the current coin.
- Track the **minimum number of coins** required among all possible choices.



#### **Step 3: Termination**
The recursion continues until:
1. The base case `x == 0` is reached, returning `0`.
2. The amount becomes negative (`x < 0`), returning `INT_MAX`.



#### **Example**

Let’s solve `amount = 11` with `coins = [1, 2, 5]`.

1. Start with `solveRecursive(coins, 11)`:
   - Try using coin `1`: Solve for `solveRecursive(coins, 10)`.
   - Try using coin `2`: Solve for `solveRecursive(coins, 9)`.
   - Try using coin `5`: Solve for `solveRecursive(coins, 6)`.

2. For each subproblem:
   - Continue subtracting coins recursively until the amount becomes `0` or negative.

3. Optimal solution:
   - `5 + 5 + 1 = 11` (3 coins).


### Source Code
```cpp
class Solution {
public:
    // Recursive function to solve the coin change problem
    int solveRecursive(vector<int>& coins, int x) {
        // Base case: If the remaining amount is 0, no more coins are needed
        if(x == 0) return 0;

        // Base case: If the remaining amount is negative, return an invalid result
        if(x < 0) return INT_MAX;

        // Initialize the minimum number of coins needed to a large value
        int mini = INT_MAX;

        // Iterate over each coin in the list
        for(int i = 0; i < coins.size(); i++) {
            // Recursive call: Try using the current coin and solve for the remaining amount
            int ans = solveRecursive(coins, x - coins[i]);

            // If the recursive result is valid, update the minimum number of coins
            if(ans != INT_MAX) 
                mini = min(mini, 1 + ans); // Add 1 to include the current coin
        }

        // Return the minimum number of coins required to make up the amount x
        return mini;
    }

    // Main function to find the minimum number of coins to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
        // Call the recursive function to compute the result
        int ans = solveRecursive(coins, amount);

        // If no valid combination of coins is found, return -1
        if(ans == INT_MAX) return -1;

        // Otherwise, return the computed result
        return ans;
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Recursive function to solve the coin change problem
    int solveRecursive(vector<int>& coins, int x) {
```
- **`solveRecursive`**: A helper function to compute the minimum number of coins for a given amount `x`.
- **`coins`**: The array of available coin denominations.
- **`x`**: The remaining amount we need to form.

```cpp
        // Base case: If the remaining amount is 0, no more coins are needed
        if(x == 0) return 0;
```
- If `x == 0`, we have exactly achieved the target amount. No additional coins are required, so return `0`.

```cpp
        // Base case: If the remaining amount is negative, return an invalid result
        if(x < 0) return INT_MAX;
```
- If `x < 0`, it is impossible to form this amount. Return a very large value (`INT_MAX`) to signify an invalid result.

```cpp
        // Initialize the minimum number of coins needed to a large value
        int mini = INT_MAX;
```
- `mini` stores the minimum number of coins required. Initially set to `INT_MAX`.

```cpp
        // Iterate over each coin in the list
        for(int i = 0; i < coins.size(); i++) {
```
- Loop through each coin in the `coins` array.

```cpp
            // Recursive call: Try using the current coin and solve for the remaining amount
            int ans = solveRecursive(coins, x - coins[i]);
```
- Subtract the coin's value from `x` to compute the remaining amount (`x - coins[i]`).
- Recursively call `solveRecursive` for the remaining amount.

```cpp
            // If the recursive result is valid, update the minimum number of coins
            if(ans != INT_MAX) 
                mini = min(mini, 1 + ans); // Add 1 to include the current coin
```
- If the recursive call returns a valid result (`ans != INT_MAX`), calculate the total number of coins as `1 + ans` (1 for the current coin, `ans` for the remaining amount).
- Update `mini` with the smallest value.

```cpp
        }
```
- End of the loop. All coin options have been explored.

```cpp
        // Return the minimum number of coins required to make up the amount x
        return mini;
    }
```
- Return the minimum number of coins required to form `x`.



```cpp
    // Main function to find the minimum number of coins to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
```
- Main function called by the user. Takes the coin denominations (`coins`) and target amount (`amount`) as input.

```cpp
        // Call the recursive function to compute the result
        int ans = solveRecursive(coins, amount);
```
- Call the recursive helper function `solveRecursive` to compute the result.

```cpp
        // If no valid combination of coins is found, return -1
        if(ans == INT_MAX) return -1;
```
- If the result is `INT_MAX`, it means no valid combination was found. Return `-1`.

```cpp
        // Otherwise, return the computed result
        return ans;
    }
};
```
- Return the computed result.


### Examples Output
Here are some examples of inputs and outputs for the **Coin Change** problem using the **recursive approach**. These examples demonstrate how the solution behaves with different inputs.

### **Example 1:**
#### **Input:**
```plaintext
coins = [1, 2, 5]
amount = 11
```

#### **Process:**
1. Start solving for `amount = 11`:
   - Use `1`: Solve for `10`.
   - Use `2`: Solve for `9`.
   - Use `5`: Solve for `6`.

2. For `amount = 6`:
   - Use `5`: Solve for `1`.
   - Use `1`: Solve for `5`.

3. For `amount = 1`:
   - Use `1`: Solve for `0`.

4. Base case: `amount = 0` returns `0` coins.

#### **Output:**
```plaintext
3
```
#### **Explanation:**
The minimum number of coins required to make `11` is `5 + 5 + 1 = 11`.



### **Example 2:**
#### **Input:**
```plaintext
coins = [2]
amount = 3
```

#### **Process:**
1. Start solving for `amount = 3`:
   - Use `2`: Solve for `1`.
   - For `amount = 1`, no coins fit (base case `x < 0`).

2. Since there is no valid solution, return `-1`.

#### **Output:**
```plaintext
-1
```
#### **Explanation:**
It is impossible to make the amount `3` using only coins of denomination `2`.



### **Example 3:**
#### **Input:**
```plaintext
coins = [186, 419, 83, 408]
amount = 6249
```

#### **Process:**
- The recursion will try all combinations of these coins to achieve the target.
- Since the amount is large, this approach will take an impractical amount of time to compute without memoization or dynamic programming.

#### **Output:**
```plaintext
20
```
#### **Explanation:**
Using memoization or dynamic programming (optimized versions), the result can be computed as `20` coins.



### **Example 4:**
#### **Input:**
```plaintext
coins = [1]
amount = 0
```

#### **Process:**
1. Base case: If `amount = 0`, no coins are needed.

#### **Output:**
```plaintext
0
```
#### **Explanation:**
When the amount is `0`, no coins are required.



### **Example 5:**
#### **Input:**
```plaintext
coins = [3, 7, 10]
amount = 14
```

#### **Process:**
1. Start solving for `amount = 14`:
   - Use `10`: Solve for `4`.
   - Use `7`: Solve for `7`.
   - Use `3`: Solve for `11`.

2. Best combination:
   - Use `7` twice: `7 + 7 = 14`.

#### **Output:**
```plaintext
2
```
#### **Explanation:**
The minimum number of coins required is `2` coins of `7`.



### Time and Space Complexities

#### **Time Complexity**
- **Exponential**: ( O(n^{amount}) ), where ( n ) is the number of coins and `amount` is the target.
  - Each recursive call explores all coins (`n` choices).
  - The recursion depth can go up to `amount`.

#### **Space Complexity**
- ( O(amount) ):
  - The recursion stack can grow up to a maximum depth of `amount`.

#### **Why is it Inefficient?**
- Overlapping Subproblems: The same subproblem (e.g., `solveRecursive(coins, x)`) may be recomputed multiple times.
- Example: For `amount = 11` with `coins = [1, 2, 5]`, the recursive calls for `amount = 10`, `9`, etc., overlap significantly.

This inefficiency is resolved using **memoization** or **dynamic programming**, which stores results of subproblems for reuse. Let me know if you'd like to explore these optimizations!

---

## Top-Down Approach (DP)
The **top-down approach** with memoization is an optimized version of the basic recursive solution. It retains the recursive structure but uses a **memoization table (dp array)** to store the results of subproblems that have already been solved. This avoids recalculating results for the same subproblem multiple times, significantly improving efficiency.

### **Approach Explanation:**
1. **Recursive Structure:**
   - Similar to the basic recursive solution, this approach recursively tries each coin denomination for the current amount, reducing the target by the coin's value until the base case is reached.

2. **Memoization:**
   - A **memoization table** (`dp` array) is introduced to store results of subproblems. If the solution for a specific amount is already computed and stored in `dp`, it is reused directly instead of recalculating it.

3. **Base Cases:**
   - If the target amount (`x`) is `0`, no coins are needed, so the result is `0`.
   - If the target amount is negative, the result is invalid (`INT_MAX`).

4. **Recursive Steps:**
   - For each coin, calculate the result for `x - coins[i]` recursively.
   - Use the memoized result if available.
   - Keep track of the minimum number of coins required.

5. **Final Result:**
   - If no valid combination of coins is found, return `-1`.
   - Otherwise, return the minimum number of coins needed.

### Source Code
```cpp
class Solution {
public:
    // Helper function to solve the coin change problem using recursion with memoization
    int solve(vector<int>& coins, int x, vector<int>& dp) {
        // Base case: If the target amount is 0, no coins are needed
        if(x == 0) return 0;

        // Base case: If the target amount is negative, return an invalid result
        if(x < 0) return INT_MAX;

        // If the result for the current amount is already computed, return it
        if(dp[x] != -1) return dp[x];

        // Initialize the minimum number of coins required to a large value
        int mini = INT_MAX;

        // Iterate through each coin
        for(int i = 0; i < coins.size(); i++) {
            // Recursive call: Try using the current coin and solve for the remaining amount
            int ans = solve(coins, x - coins[i], dp);

            // If the recursive result is valid, update the minimum number of coins
            if(ans != INT_MAX) 
                mini = min(mini, 1 + ans); // Add 1 to include the current coin
        }

        // Store the computed result in the memoization array
        dp[x] = mini;

        // Return the computed result
        return mini;
    }

    // Main function to find the minimum number of coins needed to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
        // Create a memoization array initialized with -1
        vector<int> dp(amount + 1, -1);

        // Call the recursive helper function with memoization
        int ans = solve(coins, amount, dp);

        // If no valid combination of coins can form the amount, return -1
        if(ans == INT_MAX) return -1;

        // Otherwise, return the computed result
        return ans;
    }
};
```

### Source Code Explanation
#### **Helper Function: `solve`**
```cpp
int solve(vector<int>& coins, int x, vector<int>& dp) {
    // Base case: If the target amount is 0, no coins are needed
    if(x == 0) return 0;
```
- If the target amount (`x`) is `0`, it means we don't need any coins, so the result is `0`.

```cpp
    // Base case: If the target amount is negative, return an invalid result
    if(x < 0) return INT_MAX;
```
- If the target amount becomes negative, it means this path is invalid. Return `INT_MAX` to indicate no solution.

```cpp
    // If the result for the current amount is already computed, return it
    if(dp[x] != -1) return dp[x];
```
- Check if the result for the current amount (`x`) is already computed and stored in the `dp` array. If so, return it to avoid redundant computation.

```cpp
    // Initialize the minimum number of coins required to a large value
    int mini = INT_MAX;
```
- Initialize a variable `mini` to keep track of the minimum number of coins required for the current amount.

```cpp
    // Iterate through each coin
    for(int i = 0; i < coins.size(); i++) {
        // Recursive call: Try using the current coin and solve for the remaining amount
        int ans = solve(coins, x - coins[i], dp);
```
- For each coin in the `coins` array:
  - Calculate the number of coins needed for `x - coins[i]` using recursion.
  - `x - coins[i]` represents the remaining amount after using the current coin.

```cpp
        // If the recursive result is valid, update the minimum number of coins
        if(ans != INT_MAX) 
            mini = min(mini, 1 + ans); // Add 1 to include the current coin
    }
```
- If the recursive result (`ans`) is valid (not `INT_MAX`), update `mini` to the minimum of its current value and `1 + ans` (adding 1 accounts for the current coin).

```cpp
    // Store the computed result in the memoization array
    dp[x] = mini;
```
- Store the computed result for the current amount (`x`) in the `dp` array to use in future calculations.

```cpp
    // Return the computed result
    return mini;
}
```
- Return the minimum number of coins required for the current amount.



#### **Main Function: `coinChange`**
```cpp
int coinChange(vector<int>& coins, int amount) {
    // Create a memoization array initialized with -1
    vector<int> dp(amount + 1, -1);
```
- Create a `dp` array of size `amount + 1` initialized with `-1` to indicate that no results have been computed yet.

```cpp
    // Call the recursive helper function with memoization
    int ans = solve(coins, amount, dp);
```
- Call the helper function `solve` to calculate the minimum number of coins required for `amount`.

```cpp
    // If no valid combination of coins can form the amount, return -1
    if(ans == INT_MAX) return -1;
```
- If the result is `INT_MAX`, it means no valid combination of coins exists to form the given amount. Return `-1`.

```cpp
    // Otherwise, return the computed result
    return ans;
}
```
- Otherwise, return the computed result.



### **Examples Output**

#### **Example 1:**
```plaintext
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1 (3 coins)
```

#### **Example 2:**
```plaintext
Input: coins = [2], amount = 3
Output: -1
Explanation: No valid combination of coins can form 3.
```

#### **Example 3:**
```plaintext
Input: coins = [186, 419, 83, 408], amount = 6249
Output: 20
Explanation: Requires 20 coins with the given denominations.
```

#### **Example 4:**
```plaintext
Input: coins = [1], amount = 0
Output: 0
Explanation: No coins are needed for amount 0.
```



### **Time Complexity**
1. **Recursive Function Calls:**
   - For each amount from `0` to `amount`, the function is called once due to memoization.
2. **Loop Over Coins:**
   - For each recursive call, we iterate through all `n` coins.

**Time Complexity: ( O(n cdot text{amount}) )**

### **Space Complexity**
1. **Memoization Table:**
   - The `dp` array takes ( O(text{amount}) ) space.
2. **Recursive Call Stack:**
   - The depth of the recursive call stack is at most ( text{amount} ).

**Space Complexity: ( O(text{amount}) )**

This approach is much more efficient than the naive recursion and suitable for larger inputs.

---

## Bottom-Top Approach (DP)

The **bottom-up approach**, also called **tabulation**, solves the problem iteratively by building a solution from smaller subproblems to larger subproblems. This eliminates the recursive overhead and ensures every subproblem is solved exactly once.

### **Approach Explanation**
1. **Dynamic Programming Table (`dp`):**
   - `dp[i]` represents the minimum number of coins required to form the amount `i`.
   - Initialize `dp[0] = 0` because no coins are needed to make an amount of `0`.
   - Initialize all other `dp[i]` values to `INT_MAX` to indicate that they are initially unreachable.

2. **Iterative Process:**
   - For each amount `i` from `1` to the target amount `x`:
     - Iterate over all the coin denominations.
     - Check if using a coin `coins[j]` can form the amount `i`:
       - If `i - coins[j] >= 0` (valid amount to use this coin).
       - And `dp[i - coins[j]]` is not `INT_MAX` (valid subproblem).
       - Update `dp[i]` to the minimum value between its current value and `1 + dp[i - coins[j]]`.

3. **Final Result:**
   - If `dp[x] == INT_MAX`, it means the amount `x` cannot be formed using the given coins. Return `-1`.
   - Otherwise, return `dp[x]`, which is the minimum number of coins needed.


### Source Code
```cpp
class Solution {
public:
    // Function to solve the coin change problem using bottom-up dynamic programming
    int solve(vector<int>& coins, int x) {
        // Create a dp array where dp[i] represents the minimum number of coins needed to make up amount i
        vector<int> dp(x + 1, INT_MAX);

        // Base case: 0 coins are needed to make up amount 0
        dp[0] = 0;

        // Iterate over each amount from 1 to x
        for(int i = 1; i <= x; i++) {
            // Check each coin to see if it can contribute to the current amount
            for(int j = 0; j < coins.size(); j++) {
                // If the current coin can be used (i - coins[j] >= 0) 
                // and the subproblem dp[i - coins[j]] has a valid solution (not INT_MAX)
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    // Update dp[i] to the minimum of its current value and the result of using this coin
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        // If the amount x cannot be formed with the given coins, return -1
        if(dp[x] == INT_MAX) return -1;

        // Otherwise, return the minimum number of coins needed to make up amount x
        return dp[x];
    }

    // Main function to find the minimum number of coins to make up the given amount
    int coinChange(vector<int>& coins, int amount) {
        // Use the bottom-up approach to solve the problem
        return solve(coins, amount);
    }
};
```

### Source Code Explanation

#### **Function: `solve`**
```cpp
vector<int> dp(x + 1, INT_MAX);
```
- Create a `dp` array of size `x + 1`.
- Initialize all values to `INT_MAX` to signify that the amounts are initially unreachable.

```cpp
dp[0] = 0;
```
- Base case: `0` coins are needed to form the amount `0`.

```cpp
for(int i = 1; i <= x; i++) {
```
- Iterate over all amounts from `1` to `x` (target amount).

```cpp
    for(int j = 0; j < coins.size(); j++) {
```
- For each amount, iterate over all coin denominations.

```cpp
        if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
```
- Check if:
  - The current coin `coins[j]` can be used (`i - coins[j] >= 0`).
  - The subproblem `dp[i - coins[j]]` has a valid solution (`dp[i - coins[j]] != INT_MAX`).

```cpp
            dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
```
- Update `dp[i]` to the minimum of:
  - Its current value.
  - `1 + dp[i - coins[j]]` (using the current coin).

```cpp
if(dp[x] == INT_MAX) return -1;
```
- If `dp[x]` remains `INT_MAX`, the target amount cannot be formed with the given coins. Return `-1`.

```cpp
return dp[x];
```
- Otherwise, return `dp[x]`, the minimum number of coins required to form the target amount.



#### **Main Function: `coinChange`**
```cpp
return solve(coins, amount);
```
- Calls the `solve` function to compute the result using the bottom-up approach.



### **Examples Output**

#### **Example 1:**
```plaintext
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1 (3 coins)
```

#### **Example 2:**
```plaintext
Input: coins = [2], amount = 3
Output: -1
Explanation: No valid combination of coins can form 3.
```

#### **Example 3:**
```plaintext
Input: coins = [186, 419, 83, 408], amount = 6249
Output: 20
Explanation: Requires 20 coins with the given denominations.
```

#### **Example 4:**
```plaintext
Input: coins = [1], amount = 0
Output: 0
Explanation: No coins are needed for amount 0.
```



### **Time Complexity**
1. **Outer Loop:**
   - Iterates over all amounts from `1` to `x`.
   - Runs `O(x)` times.
2. **Inner Loop:**
   - Iterates over all `n` coins for each amount.
   - Runs `O(n)` times per amount.

**Total Time Complexity: ( O(n cdot x) )**



### **Space Complexity**
1. **Dynamic Programming Table (`dp`):**
   - Takes ( O(x) ) space to store results for amounts from `0` to `x`.

**Total Space Complexity: ( O(x) )**


### **Advantages of Tabulation**
1. No recursion, so no risk of stack overflow.
2. Efficient and straightforward, with all subproblems solved iteratively.

This bottom-up approach is faster and more memory-efficient than the recursive approaches, making it ideal for large inputs.

---

## Space Optimization (Not Possible)
In dynamic programming (DP) problems, **space optimization** is often possible when the solution only relies on a limited number of previous states. However, in the given **tabulation** approach for the **coin change problem**, space optimization is not straightforward or directly applicable for the following reasons:

### 1. **Dependence on Multiple Previous States (Coins)**
   - In the tabulation approach, the value of `dp[i]` depends on all previous `dp[i - coins[j]]` values for each coin `coins[j]` where `coins[j] ≤ i`.
   - This means that for each amount `i`, we need to look at potentially all values of `dp[i - coins[j]]`, which may come from different previous amounts.
   - Specifically, for every amount `i`, the solution depends on the results of `dp[i - coins[j]]` for every coin `coins[j]`. This introduces a **complex dependence structure** that can't easily be reduced to just the previous state or a few previous states.

### 2. **Non-overlapping Subproblems (Multiple Coins Impacting the Same Subproblem)**
   - If we attempt space optimization (such as using only a single array), we must ensure that each state is updated based on the current states only (i.e., without overwriting necessary information). 
   - However, in the coin change problem, each state (`dp[i]`) may depend on multiple earlier states (due to different coins being used). If we overwrite states too early (e.g., reusing the same `dp` array while iterating over all coins), we might lose information needed for subsequent iterations of the same amount.

### 3. **Inability to Collapse the `dp` Table**
   - In typical DP problems like the **0/1 knapsack** or **fibonnaci sequence**, the solution can often be optimized by **reducing the state space**, usually by using just a few previous values (e.g., the last row or last few columns in a 2D DP table).
   - However, in this case, the tabulation approach requires access to **all the previous subproblems**, even for the current amount `i`. As we update the table for each amount `i`, we rely on all the possible previous subproblems `dp[i - coins[j]]`, and we cannot reduce this without losing the necessary information.

### 4. **Space Optimization Works for Limited Dependencies**
   - Space optimization is more straightforward when only the last subproblem result is needed for calculating the next one, such as when there is a **linear dependency** between subproblems (e.g., Fibonacci numbers, where each number only depends on the previous two).
   - In contrast, the coin change problem has **non-linear dependencies**, as each state (`dp[i]`) can depend on multiple previous states (corresponding to using different coins). This makes reducing the table to a smaller space less feasible.

### 5. **Why Can't We Use 1D Array with Space Optimization?**
   - Typically, in problems where **only the previous row/column** (or a small constant number of rows/columns) is needed to compute the current state, we can use space optimization by reducing the 2D DP table to a 1D table.
   - However, in this coin change problem, each value `dp[i]` (for any amount `i`) requires information from multiple earlier values of the `dp` array (from `dp[i - coins[j]]`), and **not just the immediate previous state** (`dp[i-1]`). Therefore, we can't collapse the entire DP table into a smaller 1D array that only stores the previous states.

### **Example of Why Space Optimization Is Not Directly Applicable**
Let’s say the coins are `[1, 2, 5]` and we are trying to compute the minimum coins for `amount = 6`. The `dp[6]` value will depend on:
- `dp[6-1] = dp[5]`
- `dp[6-2] = dp[4]`
- `dp[6-5] = dp[1]`

Each of these subproblems relies on the result of different earlier subproblems. This is a **multi-step dependency** that doesn’t allow the easy reduction to a 1D array that would be possible with problems like Fibonacci, where the state at `i` only depends on `i-1` and `i-2`.



### **Conclusion**
Space optimization is difficult in this problem because:
- Each state (`dp[i]`) relies on **multiple previous states** (due to different coin denominations).
- The problem has a **complex dependency structure** where each amount `i` depends on results from different earlier amounts.
- Thus, unlike problems with simpler linear dependencies (e.g., Fibonacci), this problem requires maintaining all intermediate results for all amounts up to `x`.

To sum up, **space optimization** in the tabulation approach for the coin change problem is not directly applicable because the solution needs access to multiple previous states for each amount, making it hard to reduce the space complexity further.
