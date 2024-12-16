<h1 align="center">Best - Time To - Buy & Sell - Stock II</h1>

## Problem Statement

**Problem URL :** [Best Time To Buy & Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

![image](https://github.com/user-attachments/assets/9c36cc5e-587a-4803-98d0-4ff9bd7234ac)

### Problem Explanation
You are given an array `prices` where `prices[i]` is the price of a given stock on the **i-th day**. Your task is to maximize your profit by performing as many transactions as you like (buying and selling). 

- **Note:** You may not engage in multiple transactions simultaneously (you must sell the stock before buying again).

### Key Points of the Problem:
1. You can buy and sell the stock multiple times.
2. You must sell the stock before buying again.
3. The goal is to maximize the total profit.

### Examples:

#### Example 1:
**Input**: `prices = [7, 1, 5, 3, 6, 4]`

**Explanation**:
- You can perform the following transactions:
  1. Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5 - 1 = 4.
  2. Buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6 - 3 = 3.
- Total profit = 4 + 3 = 7.

**Output**: `7`

#### Example 2:
**Input**: `prices = [1, 2, 3, 4, 5]`

**Explanation**:
- The prices are continuously increasing, so you can:
  1. Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5 - 1 = 4.
- Total profit = 4.

**Output**: `4`

#### Example 3:
**Input**: `prices = [7, 6, 4, 3, 1]`

**Explanation**:
- The prices are continuously decreasing, so no transactions can provide a positive profit.
- Total profit = 0.

**Output**: `0`

### Constraints:
- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

### Approach to Solve:
The task is to maximize profit by buying and selling multiple times, where the profit is the sum of all increasing price differences. You don't need to calculate the exact buy and sell days but instead focus on finding every profitable price difference.

---

## Recursive Approach (caused TLE)
The goal is to calculate the maximum profit from multiple transactions in a stock market. The recursive approach helps break down the problem by making decisions at each day: whether to buy, sell, or skip a transaction.

We are given an array `prices[]` where `prices[i]` denotes the price of the stock on day `i`.

#### **Recursive Decision Making:**
At each day:
- If we are allowed to **buy** (i.e., `buy = 1`), we have two options:
  1. **Buy the stock** on this day (subtract the price from the profit) and move to the next day with `buy = 0` (because we now own the stock).
  2. **Do not buy** and move to the next day with `buy = 1` (no action).
  
- If we are allowed to **sell** (i.e., `buy = 0`), we have two options:
  1. **Sell the stock** on this day (add the price to the profit) and move to the next day with `buy = 1` (because we no longer own the stock).
  2. **Do not sell** and move to the next day with `buy = 0` (no action).

Each decision leads us to different recursive calls for subsequent days, and the goal is to maximize the profit by exploring all possible paths.

#### **Example:**
Let `prices = [7, 1, 5, 3, 6, 4]`.

We will break down the steps with `index = 0` (starting on day 1) and `buy = 1` (i.e., we are allowed to buy).

1. **Day 1 (`prices[0] = 7`)**:
   - **Buy (option 1)**: Buy stock for `7` and move to the next day (`index = 1`), where we can't buy anymore (i.e., `buy = 0`).
   - **Skip buying (option 2)**: Skip buying and move to the next day (`index = 1`), and still keep the option to buy (i.e., `buy = 1`).

2. **Day 2 (`prices[1] = 1`)**:
   - If **buying**: The option to buy would be `-1 + solve(prices, 2, 0)`, because we spend `1` to buy.
   - If **not buying**: We can skip buying and move to the next day.

   Now, we continue down these two branches recursively, calculating the profit for every possibility.

#### **Step-by-Step Execution of Code with Example:**

**Base Case:**  
The recursion terminates when `index == prices.size()`, meaning all days have been processed. At this point, no profit can be made, so we return 0.

**Recursive Cases:**  
For each day, depending on whether we can buy or sell, the function will calculate two values (one for buying and one for not buying or selling) and take the maximum of them. This is done recursively for each day until all the days are processed.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit using recursion.
    // Parameters:
    // prices - reference to the price array
    // index  - current day we are processing
    // buy    - whether we are allowed to buy (1) or sell (0) on the current day
    int solve(vector<int>& prices, int index, int buy) {
        // Base case: If we have processed all the days, there is no profit to be made
        if (index == prices.size()) return 0;

        int profit = 0; // Initialize profit for the current state

        if (buy) {
            // If we are allowed to buy on this day, we have two choices:
            // 1. Buy the stock today: Subtract prices[index] and move to the next day with buy=0 (since we now own the stock).
            // 2. Skip buying today: Move to the next day and keep buy=1.
            profit = max(
                (-prices[index] + solve(prices, index + 1, 0)), // Option 1: Buy today
                (0 + solve(prices, index + 1, 1))               // Option 2: Skip buying
            );
        } else {
            // If we are allowed to sell on this day, we have two choices:
            // 1. Sell the stock today: Add prices[index] to profit and move to the next day with buy=1 (since we no longer own the stock).
            // 2. Skip selling today: Move to the next day and keep buy=0.
            profit = max(
                (+prices[index] + solve(prices, index + 1, 1)), // Option 1: Sell today
                (0 + solve(prices, index + 1, 0))               // Option 2: Skip selling
            );
        }

        // Return the maximum profit for the current state
        return profit;
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        // Start from the first day (index=0) with the ability to buy (buy=1)
        return solve(prices, 0, 1);
    }
};
```

### Source Code Explanation

Let's now explain the code line by line:

```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit using recursion.
    // Parameters:
    // prices - reference to the price array
    // index  - current day we are processing
    // buy    - whether we are allowed to buy (1) or sell (0) on the current day
    int solve(vector<int>& prices, int index, int buy) {
        // Base case: If we have processed all the days, there is no profit to be made
        if (index == prices.size()) return 0;
```
- **Line 3-7**: We define the `solve` function which calculates the maximum profit starting from the given `index` (representing the current day) with the given `buy` state (whether we are allowed to buy or sell).
- The base case checks if we have processed all days (`index == prices.size()`). If true, we return `0` because there's no more profit to make.
  
```cpp
        int profit = 0; // Initialize profit for the current state
```
- **Line 8**: We initialize a `profit` variable to store the maximum profit for the current state (either buy or sell).

```cpp
        if (buy) {
            // If we are allowed to buy on this day, we have two choices:
            // 1. Buy the stock today: Subtract prices[index] and move to the next day with buy=0 (since we now own the stock).
            // 2. Skip buying today: Move to the next day and keep buy=1.
            profit = max(
                (-prices[index] + solve(prices, index + 1, 0)), // Option 1: Buy today
                (0 + solve(prices, index + 1, 1))               // Option 2: Skip buying
            );
```
- **Lines 9-12**: If `buy == 1`, we are allowed to buy on the current day. We calculate the profit for two options:
  1. **Buy today**: Subtract the price of the stock (`-prices[index]`) and call the recursive function for the next day (`index + 1`) where we cannot buy anymore (`buy = 0`).
  2. **Skip buying**: Do nothing today, move to the next day (`index + 1`) with the ability to buy again (`buy = 1`).

The maximum of the two values is stored in `profit`.

```cpp
        } else {
            // If we are allowed to sell on this day, we have two choices:
            // 1. Sell the stock today: Add prices[index] to profit and move to the next day with buy=1 (since we no longer own the stock).
            // 2. Skip selling today: Move to the next day and keep buy=0.
            profit = max(
                (+prices[index] + solve(prices, index + 1, 1)), // Option 1: Sell today
                (0 + solve(prices, index + 1, 0))               // Option 2: Skip selling
            );
```
- **Lines 13-16**: If `buy == 0`, we are allowed to sell on the current day. We calculate the profit for two options:
  1. **Sell today**: Add the price of the stock (`+prices[index]`) and call the recursive function for the next day (`index + 1`) where we can buy again (`buy = 1`).
  2. **Skip selling**: Do nothing today, move to the next day (`index + 1`) with the ability to sell again (`buy = 0`).

The maximum of the two values is stored in `profit`.

```cpp
        // Return the maximum profit for the current state
        return profit;
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        // Start from the first day (index=0) with the ability to buy (buy=1)
        return solve(prices, 0, 1);
    }
};
```
- **Lines 17-21**: The `solve` function returns the maximum profit calculated for the current day. The `maxProfit` function calls `solve` starting from the first day (`index = 0`) with the ability to buy (`buy = 1`).


### **Example Output Explanation:**

Let’s take the example `prices = [7, 1, 5, 3, 6, 4]`:

1. **First call (index = 0, buy = 1)**: We have two options:
   - **Buy today** (buying at 7 and moving to index 1, buy = 0) -> Option 1.
   - **Skip buying** and move to the next day with buy = 1 -> Option 2.
   
2. **For index 1 (buy = 0)**: We decide whether to sell the stock:
   - **Sell today** (selling at 1, moving to index 2 with buy = 1) -> Option 1.
   - **Skip selling** and move to the next day with buy = 0 -> Option 2.

We recursively explore all possibilities, calculating the maximum profit for each option, and returning the highest profit.


### **Time and Space Complexity:**

- **Time Complexity**:
  - **Naive Recursive Approach**: This approach checks all possible combinations of buying and selling days, leading to an exponential time complexity of **O(2^n)**, where `n` is the number of days (prices.length).
  
- **Space Complexity**:
  - The space complexity is determined by the recursion stack. In the worst case, the depth of recursion is `n` (the number of days). Hence, the space complexity is **O(n)**.

---

## Top-Down Approach (DP)
The **top-down approach** uses recursion combined with **memoization** to solve the problem efficiently. It recursively calculates the maximum profit but stores intermediate results in a 2D table (`dp`) to avoid redundant calculations. This approach is faster than the simple recursive solution because it caches results that would otherwise be recomputed.

Let's break down the approach, source code, example output, and the time and space complexities in detail.

### **Step-by-Step Explanation of the Top-Down Approach**

#### 1. **Recursive Solution with Memoization**

The idea is similar to the previous recursive approach but with memoization. The base case and logic for buying and selling remain the same. However, we now store intermediate results in a **2D table (`dp`)** to avoid recalculating the same subproblems.

- The `dp` table is a 2D vector where:
  - `dp[i][0]` will store the maximum profit starting from day `i` if we are **not allowed to buy** (we are in the "sell" state).
  - `dp[i][1]` will store the maximum profit starting from day `i` if we are **allowed to buy** (we are in the "buy" state).
  
#### 2. **Base Case**

The base case is when we have processed all days, which happens when `index == prices.size()`. At that point, there are no more transactions to make, so the maximum profit is 0.

#### 3. **Memoization Check**

Before calculating the profit for a given state `(index, buy)`, we first check if the result for that state has already been computed by looking it up in the `dp` table. If the result exists, we simply return it.

#### 4. **Profit Calculation**

- If we are **allowed to buy** (`buy == 1`):
  - We have two choices:
    1. **Buy the stock**: The profit will decrease by `prices[index]` (since we are buying), and we then move to the next day where we are forced to **sell** (`buy = 0`).
    2. **Skip buying**: We just move to the next day without buying (`buy = 1` remains unchanged).
  
- If we are **allowed to sell** (`buy == 0`):
  - We have two choices:
    1. **Sell the stock**: The profit will increase by `prices[index]` (since we are selling), and we then move to the next day where we are forced to **buy** (`buy = 1`).
    2. **Skip selling**: We just move to the next day without selling (`buy = 0` remains unchanged).
  
- We calculate the maximum profit for both choices and store the result in the `dp` table.

#### 5. **Return the Result**

The function finally returns the value stored in `dp[0][1]`, which gives the maximum profit starting from day `0` with the ability to buy.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit using recursion and memoization
    // Parameters:
    // prices - reference to the price array
    // index  - current day we are processing
    // buy    - whether we are allowed to buy (1) or sell (0) on the current day
    // dp     - 2D vector for memoization to store intermediate results
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
        // Base case: If we have processed all the days, there is no profit to be made
        if (index == prices.size()) return 0;

        // If the result for this state is already computed, return it
        if (dp[index][buy] != -1) return dp[index][buy];

        int profit = 0; // Initialize profit for the current state

        if (buy) {
            // If we are allowed to buy on this day, we have two choices:
            // 1. Buy the stock today: Subtract prices[index] and move to the next day with buy=0 (since we now own the stock).
            // 2. Skip buying today: Move to the next day and keep buy=1.
            profit = max(
                (-prices[index] + solve(prices, index + 1, 0, dp)), // Option 1: Buy today
                (0 + solve(prices, index + 1, 1, dp))               // Option 2: Skip buying
            );
        } else {
            // If we are allowed to sell on this day, we have two choices:
            // 1. Sell the stock today: Add prices[index] to profit and move to the next day with buy=1 (since we no longer own the stock).
            // 2. Skip selling today: Move to the next day and keep buy=0.
            profit = max(
                (+prices[index] + solve(prices, index + 1, 1, dp)), // Option 1: Sell today
                (0 + solve(prices, index + 1, 0, dp))               // Option 2: Skip selling
            );
        }

        // Store the computed profit for the current state in the dp table
        return dp[index][buy] = profit;
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); // Get the number of days

        // Create a 2D dp table with dimensions (n+1) x 2
        // dp[i][buy] stores the maximum profit from day i onward with the ability to buy or sell
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // Start from the first day (index=0) with the ability to buy (buy=1)
        return solve(prices, 0, 1, dp);
    }
};
```

### Source Code Explanation

```cpp
int solve(vector<int>& prices, int index, int buy, vector<vector<int>>& dp) {
```
This function `solve` is the helper function for recursion and memoization. It takes:
- `prices`: The array of stock prices.
- `index`: The current day we are processing.
- `buy`: A flag to indicate if we're allowed to buy (1) or sell (0).
- `dp`: The memoization table to store the computed results.

```cpp
    if (index == prices.size()) return 0;
```
This is the **base case**. If we've processed all days (`index == prices.size()`), no profit can be made, so we return 0.

```cpp
    if (dp[index][buy] != -1) return dp[index][buy];
```
Here, we check if we've already computed the result for the current state `(index, buy)`. If the value is not `-1`, we return the stored result.

```cpp
    int profit = 0;
```
Initialize a variable `profit` to store the maximum profit for the current state.

#### **If we are allowed to buy (buy == 1):**
```cpp
    if (buy) {
        profit = max(
            (-prices[index] + solve(prices, index + 1, 0, dp)), // Buy today
            (0 + solve(prices, index + 1, 1, dp))               // Skip buying
        );
    }
```
- The first option is to **buy the stock today**: We subtract `prices[index]` (since buying costs money) and recursively calculate the profit for the next day (`index + 1`), where we will sell (`buy = 0`).
- The second option is to **skip buying today** and just move to the next day (`buy = 1` remains unchanged).

#### **If we are allowed to sell (buy == 0):**
```cpp
    else {
        profit = max(
            (+prices[index] + solve(prices, index + 1, 1, dp)), // Sell today
            (0 + solve(prices, index + 1, 0, dp))               // Skip selling
        );
    }
```
- The first option is to **sell the stock today**: We add `prices[index]` (since selling gains money) and recursively calculate the profit for the next day (`index + 1`), where we will buy again (`buy = 1`).
- The second option is to **skip selling today** and just move to the next day (`buy = 0` remains unchanged).

```cpp
    return dp[index][buy] = profit;
```
After calculating the profit, we store it in the `dp` table and return the result.

```cpp
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}
```
- We initialize the `dp` table with dimensions `(n + 1) x 2` where `n` is the number of days.
- We start the recursion by calling `solve(prices, 0, 1, dp)` to calculate the maximum profit starting from day 0 with the ability to buy.


### **Example Walkthrough**

Let's consider an example with the following prices:

- **prices** = [1, 2, 3, 0, 2]

#### Process:
1. Start at `index = 0` with `buy = 1` (we can buy).
2. On day 0, we buy the stock for 1 (profit becomes `-1`).
3. Move to day 1, we decide to hold or sell.
4. On day 1, we sell for 2 (profit becomes `1`).
5. Continue recursively through the list.
6. Finally, compute the maximum profit by considering all possible actions (buy, sell, skip).

#### Output:
- **Output** = 3 (The maximum profit is achieved by buying at 1, selling at 3, and buying again at 0 and selling at 2).


### **Time and Space Complexities**

#### **Time Complexity**:
- In the top-down approach, each state `(index, buy)` is computed only once and is stored in the `dp` table.
- The number of states is proportional to the number of days (`n`) and the two possible actions (`buy` or `sell`), so the total number of states is `2n`.
- Each state involves a constant amount of work (two recursive calls and a `max` operation), so the time complexity is **O(n)**.

#### **Space Complexity**:
- The `dp` table requires **O(n)** space to store results for each state.
- The recursion depth can be at most `n`, so the space complexity due to recursion is also **O(n)**.
- Therefore, the total space complexity is **O(n)**.


### **Summary**

- **Top-down DP** improves the naive recursion by using memoization to store intermediate results, thus avoiding redundant computations.
- The approach is efficient with time complexity **O(n)** and space complexity **O(n)**.

---

## Bottom-Up Approach (DP)
The bottom-up approach for solving the "Best Time to Buy and Sell Stock" problem is based on dynamic programming. We use an iterative approach to fill a DP table, starting from the base case (when we're on the last day) and working backward to the first day.

#### **Problem Restatement:**
Given a list of stock prices where each element represents the price of the stock on a given day, we are tasked with finding the maximum profit that can be made by buying and selling the stock at most once.

The idea is to decide whether to buy or sell on each day to maximize profit.

### **Step-by-Step Explanation of the Algorithm:**

1. **Initialization:**
   We create a 2D DP table `dp[index][buy]`, where:
   - `index` refers to the day (0 to n-1).
   - `buy` represents whether we are allowed to buy (`buy=1`) or sell (`buy=0`).

2. **State Transitions:**
   For each day, we have two possible actions:
   - **If we are allowed to buy (`buy=1`)**:
     - Option 1: Buy the stock on this day. The profit would be `-prices[index]`, and we move to the next day in a sell state (`buy=0`).
     - Option 2: Do nothing. We simply move to the next day while keeping the buy state (`buy=1`).
   - **If we are allowed to sell (`buy=0`)**:
     - Option 1: Sell the stock on this day. The profit would be `prices[index]`, and we move to the next day in a buy state (`buy=1`).
     - Option 2: Do nothing. We move to the next day without selling (`buy=0`).

3. **Filling the DP Table:**
   We iterate backward from the last day to the first day and calculate the maximum profit for each state (`buy=0` and `buy=1`) at each index.

4. **Final Answer:**
   The result will be stored in `dp[0][1]`, as that represents the maximum profit starting from day 0 with the ability to buy.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum profit using an iterative dynamic programming approach
    int solve(vector<int>& prices) {

        int n = prices.size(); // Get the number of days

        // Create a 2D DP table to store the maximum profit for each state
        // dp[index][buy]:
        // - `index` represents the current day
        // - `buy` represents whether buying (1) or selling (0) is allowed on this day
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Iterate backward from the second last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the two states: buy (1) and sell (0)
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0; // Initialize profit for the current state

                if (buy) {
                    // If we are allowed to buy:
                    // - Option 1: Buy the stock today (-prices[index]) and move to the next day with buy=0
                    // - Option 2: Skip buying today and move to the next day with buy=1
                    int buyStock = -prices[index] + dp[index + 1][0];
                    int notBuyStock = 0 + dp[index + 1][1];
                    profit = max(buyStock, notBuyStock);
                } else {
                    // If we are allowed to sell:
                    // - Option 1: Sell the stock today (+prices[index]) and move to the next day with buy=1
                    // - Option 2: Skip selling today and move to the next day with buy=0
                    int sellStock = +prices[index] + dp[index + 1][1];
                    int notSellStock = 0 + dp[index + 1][0];
                    profit = max(sellStock, notSellStock);
                }

                // Store the profit for the current state in the DP table
                dp[index][buy] = profit;
            }
        }

        // The maximum profit starting from day 0 with the ability to buy (buy=1)
        return dp[0][1];
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        return solve(prices); // Call the solve function
    }
};
```

### Source Code Explanation

Let's break down the code line by line:

```cpp
class Solution {
public:
    // Function to calculate the maximum profit using an iterative dynamic programming approach
    int solve(vector<int>& prices) {
```
- **Line 1**: This is the definition of the `solve` function, which takes in `prices`, a vector containing the stock prices for each day.

```cpp
        int n = prices.size(); // Get the number of days
```
- **Line 2**: We store the number of days in the variable `n`. This will be the length of the `prices` array.

```cpp
        // Create a 2D DP table to store the maximum profit for each state
        // dp[index][buy]:
        // - `index` represents the current day
        // - `buy` represents whether buying (1) or selling (0) is allowed on this day
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));  // dp array initialized to 0
```
- **Line 3**: We create a 2D DP table `dp`. It has `n+1` rows (for each day, plus an extra row to represent an out-of-bounds day) and 2 columns:
  - `dp[index][0]` represents the maximum profit on day `index` when selling is allowed.
  - `dp[index][1]` represents the maximum profit on day `index` when buying is allowed.
  We initialize the entire table to `0`.

```cpp
        // Iterate backward from the second last day to the first day
        for (int index = n - 1; index >= 0; index--) {
```
- **Line 4**: We loop from the second-to-last day (`n-1`) to the first day (`0`). This backward iteration is the key to the bottom-up approach.

```cpp
            // Iterate over the two states: buy (1) and sell (0)
            for (int buy = 0; buy <= 1; buy++) {
```
- **Line 5**: For each day, we loop over the two possible states (`buy=1` or `buy=0`).

```cpp
                int profit = 0; // Initialize profit for the current state
```
- **Line 6**: We initialize the variable `profit` to store the maximum profit for the current state on the current day.

```cpp
                if (buy) {
                    // If we are allowed to buy:
                    // - Option 1: Buy the stock today (-prices[index]) and move to the next day with buy=0
                    // - Option 2: Skip buying today and move to the next day with buy=1
                    int buyStock = -prices[index] + dp[index + 1][0];  // Option 1: Buy today
                    int notBuyStock = 0 + dp[index + 1][1];             // Option 2: Do nothing
                    profit = max(buyStock, notBuyStock);  // Take the maximum of both options
                } else {
                    // If we are allowed to sell:
                    // - Option 1: Sell the stock today (+prices[index]) and move to the next day with buy=1
                    // - Option 2: Skip selling today and move to the next day with buy=0
                    int sellStock = +prices[index] + dp[index + 1][1]; // Option 1: Sell today
                    int notSellStock = 0 + dp[index + 1][0];           // Option 2: Do nothing
                    profit = max(sellStock, notSellStock);  // Take the maximum of both options
                }
```
- **Lines 7-18**: We handle the two cases (`buy=1` and `buy=0`) separately:
  - **When buying (`buy=1`)**: We compute the profit from buying today or skipping buying.
  - **When selling (`buy=0`)**: We compute the profit from selling today or skipping selling.

```cpp
                // Store the profit for the current state in the DP table
                dp[index][buy] = profit;
            }
        }
```
- **Lines 19-21**: After calculating the maximum profit for the current state and day, we store it in the DP table.

```cpp
        // The maximum profit starting from day 0 with the ability to buy (buy=1)
        return dp[0][1];  // The result is stored in dp[0][1] after the entire iteration
    }
```
- **Lines 22-24**: Finally, we return the value stored in `dp[0][1]`, which is the maximum profit starting from the first day with the ability to buy.

```cpp
    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        return solve(prices); // Call the solve function
    }
};
```
- **Lines 25-27**: The `maxProfit` function is the main function that calls `solve` to calculate the maximum profit.



### **Explanation of Example Output in Detail:**

#### Example 1: 
```cpp
vector<int> prices1 = {7, 1, 5, 3, 6, 4};
```

- **Day 0 (Price = 7)**: We can either buy or skip. The profit so far is `0` for both cases.
- **Day 1 (Price = 1)**: We can buy on this day (profit = `-1`), or skip (profit = `0`).
- **Day 2 (Price = 5)**: If we bought on day 1, we sell here, and profit = `5 - 1 = 4`. If we skip, profit = `0`.
- **Day 3 (Price = 3)**: If we bought on day 1 and sell on day 3, profit = `3 - 1 = 2`. If we skip, profit = `0`.
- **Day 4 (Price = 6)**: If we bought on day 1, we sell here for a profit of `6 - 1 = 5`. If we skip, profit = `0`.
- **Day 5 (Price = 4)**: We can't make a profit now, so the best option is to skip. Profit = `0`.

Thus, the maximum profit is `5`, achieved by buying on day 1 and selling on day 4.

**Example Output:**
```
Example 1 Output: 5
```


#### Example 2:
```cpp
vector<int> prices2 = {7, 6, 4, 3, 1};
```

- In this case, prices keep decreasing, so there's no point in buying at any day. The maximum profit is `0`.

**Example Output:**
```
Example 2 Output: 0
```


### **Time and Space Complexities:**

#### **Time Complexity:**
- The time complexity is `O(n)` where `n` is the number of days (i.e., the length of the `prices` array).
  - We are iterating through each day once (`n` iterations).
  - For each day, we perform constant time operations to update the DP table (`O(1)` operations for each state).

#### **Space Complexity:**
- The space complexity is `O(n)` where `n` is the number of days.
  - We use a 2D DP table of size `(n+1) x 2` to store the maximum profit for each state and day.

### Conclusion:
The bottom-up approach is an efficient solution to this problem, with a time complexity of `O(n)` and space complexity of `O(n)`. It iterates through the days in reverse and calculates the maximum profit based on whether buying or selling is allowed at each step.

---

## Space Optimization (DP)
The space-optimized approach for solving the "Best Time to Buy and Sell Stock" problem is based on dynamic programming, but instead of using a 2D DP table, we reduce the space complexity by using two 1D arrays to store the results for the current and next days. This optimization significantly reduces the memory usage while maintaining the same logic.

#### **Problem Restatement:**
We are given an array of stock prices where each element represents the price of the stock on a given day. We need to find the maximum profit that can be made by buying and selling the stock at most once.

### **Step-by-Step Explanation of the Algorithm:**

1. **Initialization:**
   We define two arrays, `curr` and `next`, each with a size of 2 (for buy and sell states). These arrays are used to store the profit for the current and next day.

2. **State Transitions:**
   - If we are in the buy state (`buy=1`), we can either:
     - **Buy the stock today** (profit = `-prices[index] + next[0]`).
     - **Skip buying today** (profit = `0 + next[1]`).
   - If we are in the sell state (`buy=0`), we can either:
     - **Sell the stock today** (profit = `+prices[index] + next[1]`).
     - **Skip selling today** (profit = `0 + next[0]`).

3. **Filling the DP Table:**
   - We loop through the days in reverse order (from `n-1` to 0).
   - For each day, we calculate the maximum profit for both the buy and sell states.

4. **Update the `next` Array:**
   - After calculating the profit for the current day, we update the `next` array with the values from `curr`.

5. **Final Answer:**
   - After processing all the days, the maximum profit will be stored in `curr[1]`, which represents the maximum profit on the first day when we are allowed to buy.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    int solve(vector<int>& prices) {
        int n = prices.size(); // Get the number of days

        // Space-optimized DP approach:
        // Instead of a 2D table, use two 1D arrays to store current and next states
        vector<int> curr(2, 0); // Array to store the current day's profit for both states (buy/sell)
        vector<int> next(2, 0); // Array to store the next day's profit for both states (buy/sell)

        // Iterate backward from the second last day to the first day
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the two states: buy (1) and sell (0)
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0; // Initialize profit for the current state

                if (buy) {
                    // If we are allowed to buy:
                    // - Option 1: Buy the stock today (-prices[index]) and move to the next day with buy=0
                    // - Option 2: Skip buying today and move to the next day with buy=1
                    int buyStock = -prices[index] + next[0];
                    int notBuyStock = 0 + next[1];
                    profit = max(buyStock, notBuyStock);
                } else {
                    // If we are allowed to sell:
                    // - Option 1: Sell the stock today (+prices[index]) and move to the next day with buy=1
                    // - Option 2: Skip selling today and move to the next day with buy=0
                    int sellStock = +prices[index] + next[1];
                    int notSellStock = 0 + next[0];
                    profit = max(sellStock, notSellStock);
                }

                // Store the profit for the current state in the current day's array
                curr[buy] = profit;
            }

            // Update the next day's array with the current day's results
            next = curr;
        }

        // The maximum profit starting from day 0 with the ability to buy (buy=1)
        return curr[1];
    }

    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        return solve(prices); // Call the solve function
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    int solve(vector<int>& prices) {
        int n = prices.size(); // Get the number of days
```
- **Line 1**: The `solve` function is defined, which takes the `prices` vector as input and returns the maximum profit. 
- **Line 2**: We get the total number of days (`n`), which is the size of the `prices` array.

```cpp
        // Space-optimized DP approach:
        // Instead of a 2D table, use two 1D arrays to store current and next states
        vector<int> curr(2, 0); // Array to store the current day's profit for both states (buy/sell)
        vector<int> next(2, 0); // Array to store the next day's profit for both states (buy/sell)
```
- **Line 3**: Instead of using a 2D DP table, we use two 1D arrays (`curr` and `next`), each of size 2 (for the buy and sell states). Initially, both arrays are filled with zeros.

```cpp
        // Iterate backward from the second last day to the first day
        for (int index = n - 1; index >= 0; index--) {
```
- **Line 4**: We loop through the days from the last day (`n-1`) to the first day (`0`). The reverse iteration is crucial for the bottom-up approach.

```cpp
            // Iterate over the two states: buy (1) and sell (0)
            for (int buy = 0; buy <= 1; buy++) {
```
- **Line 5**: For each day, we check two possible states: `buy=1` (when we can buy) and `buy=0` (when we can sell).

```cpp
                int profit = 0; // Initialize profit for the current state
```
- **Line 6**: We initialize a variable `profit` to store the maximum profit for the current state (either buy or sell) on the current day.

```cpp
                if (buy) {
                    // If we are allowed to buy:
                    // - Option 1: Buy the stock today (-prices[index]) and move to the next day with buy=0
                    // - Option 2: Skip buying today and move to the next day with buy=1
                    int buyStock = -prices[index] + next[0];
                    int notBuyStock = 0 + next[1];
                    profit = max(buyStock, notBuyStock);
                } else {
                    // If we are allowed to sell:
                    // - Option 1: Sell the stock today (+prices[index]) and move to the next day with buy=1
                    // - Option 2: Skip selling today and move to the next day with buy=0
                    int sellStock = +prices[index] + next[1];
                    int notSellStock = 0 + next[0];
                    profit = max(sellStock, notSellStock);
                }
```
- **Lines 7-18**: We calculate the maximum profit for both possible states:
  - **When we can buy (`buy=1`)**: We calculate the profit from buying today or skipping buying.
  - **When we can sell (`buy=0`)**: We calculate the profit from selling today or skipping selling.

```cpp
                // Store the profit for the current state in the current day's array
                curr[buy] = profit;
            }
```
- **Line 19**: We store the maximum profit for the current day and state in the `curr` array.

```cpp
            // Update the next day's array with the current day's results
            next = curr;
        }
```
- **Line 20**: After processing all states for the current day, we update the `next` array to hold the values from the `curr` array for the next iteration.

```cpp
        // The maximum profit starting from day 0 with the ability to buy (buy=1)
        return curr[1];  // The result is stored in curr[1] after the entire iteration
    }
```
- **Line 21**: After all days have been processed, the result (maximum profit starting from day 0 with the ability to buy) will be stored in `curr[1]`.

```cpp
    // Main function to calculate the maximum profit
    int maxProfit(vector<int>& prices) {
        return solve(prices); // Call the solve function
    }
};
```
- **Lines 22-24**: The `maxProfit` function simply calls the `solve` function and returns its result.



### **Explanation of Example Output in Detail:**

#### Example 1:
```cpp
vector<int> prices1 = {7, 1, 5, 3, 6, 4};
```

- **Day 0 (Price = 7)**: We can either buy or skip. The profit so far is `0` for both cases.
- **Day 1 (Price = 1)**: We can buy on this day (profit = `-1`), or skip (profit = `0`).
- **Day 2 (Price = 5)**: If we bought on day 1, we sell here, and profit = `5 - 1 = 4`. If we skip, profit = `0`.
- **Day 3 (Price = 3)**: If we bought on day 1 and sell on day 3, profit = `3 - 1 = 2`. If we skip, profit = `0`.
- **Day 4 (Price = 6)**: If we bought on day 1, we sell here for a profit of `6 - 1 = 5`. If we skip, profit = `0`.
- **Day 5 (Price = 4)**: We can't make a profit now, so the best option is to skip. Profit = `0`.

Thus, the maximum profit is `5`, achieved by buying on day 1 and selling on day 4.

**Example Output:**
```
Example 1 Output: 5
```

#### Example 2:
```cpp
vector<int> prices2 = {7, 6, 4, 3, 1};
```

- In this case, prices keep decreasing, so there's no point in buying at any day. The maximum profit is `0`.

**Example Output:**
```
Example 2 Output: 0
```


### **Time and Space Complexities:**

#### **Time Complexity:**
- The time complexity is `O(n)` where `n` is the number of days (i.e., the length of the `prices` array).
  - We are iterating through each day once (`n` iterations).
  - For each day, we perform constant time operations to update the DP table (`O(1)` operations for each state).

#### **Space Complexity:**
- The space complexity is `O(1)` because we are using only two 1D arrays (`curr` and `next`), each of size 2, regardless of the number of days. This space optimization reduces the space complexity compared to the original 2D DP approach.

### Conclusion:
The space-optimized approach uses only `O(1)` additional space and performs the same `O(n)` time complexity as the full 2D DP approach. It efficiently calculates the maximum profit using two
1D arrays to track the profit for the buy and sell states on each day.

