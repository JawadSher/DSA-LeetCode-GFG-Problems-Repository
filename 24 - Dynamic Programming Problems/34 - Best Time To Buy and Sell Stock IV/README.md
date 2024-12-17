<h1 align="center">Best - Time To - Buy and Sell - Stock IV</h1>

## Problem Statement

**Problem URL :** [Best Time To Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/)

![image](https://github.com/user-attachments/assets/4264ae3f-f62d-4eaa-b988-f9bca982ab41)


### Problem Explanation
The problem is to maximize profit by completing at most (k) transactions given the prices of a stock over several days. A single transaction consists of one buy followed by one sell. 

1. **Input**:
   - `k`: Maximum number of transactions allowed.
   - `prices[]`: Array where `prices[i]` represents the stock price on day (i).

2. **Output**:
   - Maximum profit achievable by making at most (k) transactions.

3. **Constraints**:
   - You cannot engage in multiple transactions simultaneously (i.e., you must sell the stock before buying it again).
   - If there are no prices or no transactions are allowed, the profit is (0).

#### Examples:

**Example 1**:  
Input:  
[k = 2], [prices = [2, 4, 1]]  
Output:  
[2]  
Explanation:  
- Buy on day (1) (price = (2)) and sell on day (2) (price = (4)), profit = (4 - 2 = 2).
- Maximum profit = (2).


**Example 2**:  
Input:  
[k = 2], [prices = [3, 2, 6, 5, 0, 3]]  
Output:  
[7]  
Explanation:  
- Transaction 1: Buy on day (2) (price = (2)) and sell on day (3) (price = (6)), profit = (6 - 2 = 4).
- Transaction 2: Buy on day (5) (price = (0)) and sell on day (6) (price = (3)), profit = (3 - 0 = 3).
- Total profit = (4 + 3 = 7).


**Example 3**:  
Input:  
[k = 1], [prices = [1, 2, 3, 4, 5]]  
Output:  
[4]  
Explanation:  
- Since only one transaction is allowed, buy on day (1) (price = (1)) and sell on day (5) (price = (5)), profit = (5 - 1 = 4).

#### Edge Cases:

1. **No transactions allowed** ((k = 0)):  
   - Input: [k = 0, prices = [1, 2, 3]]  
   - Output: [0]  
   - Explanation: No transactions allowed, so the profit is (0).

2. **No price data available** ((prices = [])):  
   - Input: [k = 2, prices = []]  
   - Output: [0]  
   - Explanation: No prices, so no profit can be made.

3. **Prices are decreasing every day**:  
   - Input: [k = 2, prices = [5, 4, 3, 2, 1]]  
   - Output: [0]  
   - Explanation: Prices are falling, so no profitable transaction can be made.

4. **Unlimited transactions** ((k) large enough):  
   - Input: [k = 100, prices = [1, 2, 3, 4, 5]]  
   - Output: [4]  
   - Explanation: Since we can do as many transactions as needed, we can simply "buy" at the lowest point and "sell" at the highest point, which achieves the same as a single transaction.

#### Key Observations:

1. **Maximum Number of Transactions**:
   - If (k) exceeds (n/2) ((n) is the number of days), it's equivalent to making unlimited transactions because a maximum of (n/2) transactions can be made (buy-sell pairs).

2. **Dynamic Programming Approach**:
   - Track the maximum profit at each day for all possible transactions.
   - Use state variables to represent whether you are "holding a stock" or "not holding a stock" after each transaction.

This problem challenges you to balance between choosing when to buy and sell while adhering to the transaction limit. It is solved using dynamic programming techniques to ensure efficiency, especially when (n) (number of days) or (k) (number of transactions) is large.

---

## Recursive Approach (caused TLE)
The problem is to maximize the profit by making at most (k) transactions on given stock prices over (n) days. A transaction consists of buying and selling one stock. The recursive approach explores all possible ways of buying, selling, or skipping a transaction on each day to find the maximum profit.

#### **Step-by-Step Explanation of the Recursive Approach**

1. **Base Cases**:
   - If we have reached the end of the prices array (`index == n`), we can't make any further transactions, so the profit is (0).
   - If we have no transactions left (`k == 0`), we cannot buy or sell anymore, so the profit is (0).

2. **States**:
   The recursive function `solve(prices, index, buy, k)` has:
   - `index`: The current day we are on.
   - `buy`: Whether we are allowed to buy (1) or must sell (0).
   - `k`: The number of transactions remaining.

3. **Choices**:
   At each step, depending on whether we can buy or sell:
   - **If allowed to buy (`buy = 1`)**:
     - **Buy**: Subtract the current day's price and move to the next day with `buy = 0`.
     - **Skip**: Move to the next day with `buy = 1`.
   - **If allowed to sell (`buy = 0`)**:
     - **Sell**: Add the current day's price to profit, decrement (k), and move to the next day with `buy = 1`.
     - **Skip**: Move to the next day with `buy = 0`.

4. **Recursive Relation**:
   - If `buy = 1`:
     `     profit = max(-prices[index] + solve(prices, index+1, 0, k), text{skip})
     `   - If `buy = 0`:
     `     profit = max(prices[index] + solve(prices, index+1, 1, k-1), text{skip})
     `
5. **Combine Results**:
   At each step, take the maximum profit from the two possible choices (buy/sell vs. skip).


#### **Example Walkthrough**

Input: (k = 2, text{prices} = [3, 2, 6, 5, 0, 3])

**Recursive Calls**:
- Day (0): Start with (k = 2, buy = 1).
  - Buy at day (0): Move to (index = 1, buy = 0).
  - Skip day (0): Move to (index = 1, buy = 1).
- Day (1):
  - Continue recursively exploring buying, selling, or skipping until all days are processed.

**Optimal Solution**:
- Transaction (1): Buy at day (1) ((price = 2)), sell at day (2) ((price = 6)), profit = (6 - 2 = 4).
- Transaction (2): Buy at day (4) ((price = 0)), sell at day (5) ((price = 3)), profit = (3 - 0 = 3).
- Total profit = (4 + 3 = 7).

### Source Code
```cpp
class Solution {
public:
    // Recursive helper function to calculate the maximum profit
    // `prices`: vector of stock prices
    // `index`: current day index in the prices array
    // `buy`: indicates whether we are allowed to buy (1) or need to sell (0)
    // `k`: remaining transactions we are allowed to perform
    int solve(vector<int>& prices, int index, int buy, int k) {
        int n = prices.size(); // Number of days in the prices array

        // Base case: if we've reached the end of the array or have no transactions left, return 0
        if(index == n || k == 0) return 0;

        int profit = 0; // Variable to store the maximum profit at the current state

        if(buy) {
            // If we are allowed to buy, we have two choices:
            // 1. Buy the stock on this day and subtract its price from profit, then move to the next day with `buy = 0`.
            // 2. Skip buying and move to the next day with `buy = 1`.
            profit = max(
                -prices[index] + solve(prices, index + 1, 0, k), // Buy
                0 + solve(prices, index + 1, 1, k)              // Skip
            );
        } else {
            // If we are not allowed to buy (we need to sell), we have two choices:
            // 1. Sell the stock on this day and add its price to profit, then move to the next day with `buy = 1` and decrement transactions.
            // 2. Skip selling and move to the next day with `buy = 0`.
            profit = max(
                prices[index] + solve(prices, index + 1, 1, k - 1), // Sell
                0 + solve(prices, index + 1, 0, k)                // Skip
            );
        }

        return profit; // Return the maximum profit for this state
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        // Start the recursive process from day 0, with the ability to buy and `k` transactions remaining
        return solve(prices, 0, 1, k);
    }
};
```

### Source Code Explanation

```cpp
int solve(vector<int>& prices, int index, int buy, int k) {
```
- This function takes the `prices` array, `index` (current day), `buy` (whether buying is allowed), and `k` (remaining transactions).
- It calculates the maximum profit recursively.

```cpp
int n = prices.size();
if(index == n || k == 0) return 0;
```
- Base case: If we reach the end of the array or run out of transactions, return (0).

```cpp
int profit = 0;
```
- Variable to store the maximum profit at the current state.

```cpp
if(buy) {
    profit = max(
        -prices[index] + solve(prices, index + 1, 0, k),
        0 + solve(prices, index + 1, 1, k)
    );
}
```
- If buying is allowed:
  - **Buy**: Subtract the price of the current day and move to the next day where selling is allowed.
  - **Skip**: Simply move to the next day without buying.

```cpp
else {
    profit = max(
        prices[index] + solve(prices, index + 1, 1, k - 1),
        0 + solve(prices, index + 1, 0, k)
    );
}
```
- If selling is allowed:
  - **Sell**: Add the price of the current day to the profit and move to the next day with one less transaction.
  - **Skip**: Simply move to the next day without selling.

```cpp
return profit;
```
- Return the maximum profit at the current state.

```cpp
int maxProfit(int k, vector<int>& prices) {
    return solve(prices, 0, 1, k);
}
```
- Initiates the recursive process starting from day (0) with the ability to buy and (k) transactions remaining.


### **Example Output Explanation**

Input:  
(k = 2, text{prices} = [3, 2, 6, 5, 0, 3])

**Output**: (7)

**Reason**:
1. Transaction (1): Buy at day (1) ((price = 2)), sell at day (2) ((price = 6)), profit = (4).
2. Transaction (2): Buy at day (4) ((price = 0)), sell at day (5) ((price = 3)), profit = (3).

Total profit = (4 + 3 = 7).

### **Time and Space Complexities**

1. **Time Complexity**:
   - There are (n) days and (2 times k) states (for (k) transactions and buy/sell states).
   - Recursive calls explore every state, leading to (O(n times k)).

2. **Space Complexity**:
   - The recursion stack requires (O(n)) space in the worst case.
   - The recursive approach does not use memoization, so no additional storage is needed.  

---

## Top-Down Approach (DP)
In this solution, we use **dynamic programming** with **memoization** to solve the problem efficiently by storing intermediate results to avoid redundant calculations. The idea behind memoization is to store the results of already computed states so that when the same state is encountered again, the result is returned from memory rather than recalculating it.

This approach is called **Top-Down Dynamic Programming** because we break down the problem starting from the top (i.e., the current day) and store the results of subproblems in a **3D DP table**.

#### **Step-by-Step Explanation of the Top-Down Approach**

1. **Recursive Function**:
   - The recursive function `solve(prices, index, buy, k, dp)` is used to calculate the maximum profit at a given `index` (day), with the `buy` flag (whether we are allowed to buy or need to sell), and `k` remaining transactions.
   
2. **Base Case**:
   - If we have reached the end of the array (`index == n`), or if there are no remaining transactions (`k == 0`), the function returns 0, as no further profit can be made.
   
3. **Memoization**:
   - If the result for a specific state (i.e., a specific day, buy/sell flag, and remaining transactions) has already been computed, it is retrieved from the DP table (`dp[index][buy][k]`).

4. **Choices**:
   - At each state, we have two choices:
     - **If allowed to buy** (`buy = 1`):
       - **Buy the stock**: Subtract the price of the stock on the current day from the profit and move to the next day with `buy = 0` (now we can sell).
       - **Skip the buy**: Move to the next day with `buy = 1` without making any transaction.
     - **If allowed to sell** (`buy = 0`):
       - **Sell the stock**: Add the price of the stock on the current day to the profit, move to the next day with `buy = 1` (now we can buy again) and decrement the number of remaining transactions.
       - **Skip the sell**: Move to the next day with `buy = 0` without selling.

5. **Recursion**:
   - The function makes recursive calls to check both choices (buy/sell or skip) and returns the maximum of the two.

6. **Memoization Table**:
   - The result of each state is stored in a 3D table `dp[index][buy][k]` to avoid recalculating it if we encounter the same state again.

#### **Example Walkthrough**

Let’s walk through an example for better understanding.

**Example**:
Input: (k = 2), `prices = [3, 2, 6, 5, 0, 3]`

1. **Start at Day 0 with k = 2 and buy = 1** (can buy):
   - **Choice 1 (Buy)**: Subtract the price at day 0 (`prices[0] = 3`) and move to day 1 with buy = 0 (next move must be sell).
   - **Choice 2 (Skip Buy)**: Move to day 1 with buy = 1 (can still buy).

2. **At Day 1**:
   - **Choice 1 (Sell)**: Add `prices[1] = 2` to the profit and move to day 2 with buy = 1 and k = 1 (one transaction used).
   - **Choice 2 (Skip Sell)**: Move to day 2 with buy = 0 (can’t sell here).

This recursive process continues, but once we calculate a value for a specific combination of `index`, `buy`, and `k`, it is stored in `dp`.

For the example, the recursive calls and calculations lead to the maximum profit of 7 after 2 transactions.

**Output**: (7)

### Source Code
```cpp
class Solution {
public:
    // Recursive helper function to calculate the maximum profit
    // `prices`: vector of stock prices
    // `index`: current day index in the prices array
    // `buy`: indicates whether we are allowed to buy (1) or need to sell (0)
    // `k`: remaining transactions we are allowed to perform
    // `dp`: 3D DP table to store intermediate results for memoization
    int solve(vector<int>& prices, int index, int buy, int k, vector<vector<vector<int>>>& dp) {
        int n = prices.size(); // Total number of days in the prices array

        // Base case: If we reach the end of the array or have no transactions left, return 0
        if(index == n || k == 0) return 0;

        // If the current state is already computed, return the stored value
        if(dp[index][buy][k] != -1) return dp[index][buy][k];

        int profit = 0; // Variable to store the maximum profit at the current state

        if(buy) {
            // If we are allowed to buy, we have two choices:
            // 1. Buy the stock on this day and subtract its price from profit, then move to the next day with `buy = 0`.
            // 2. Skip buying and move to the next day with `buy = 1`.
            profit = max(
                -prices[index] + solve(prices, index + 1, 0, k, dp), // Buy
                0 + solve(prices, index + 1, 1, k, dp)              // Skip
            );
        } else {
            // If we are not allowed to buy (we need to sell), we have two choices:
            // 1. Sell the stock on this day and add its price to profit, then move to the next day with `buy = 1` and decrement transactions.
            // 2. Skip selling and move to the next day with `buy = 0`.
            profit = max(
                prices[index] + solve(prices, index + 1, 1, k - 1, dp), // Sell
                0 + solve(prices, index + 1, 0, k, dp)                // Skip
            );
        }

        // Store the result in the DP table for future use and return it
        return dp[index][buy][k] = profit;
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Initialize a 3D DP table with dimensions [n][2][k+1] and set all values to -1
        // dp[i][j][l]: maximum profit at day `i` with `j` (buy = 1, sell = 0) and `l` transactions remaining
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // Start the recursive process from day 0, with the ability to buy and `k` transactions remaining
        return solve(prices, 0, 1, k, dp);
    }
};
```

### Source Code Explanation

```cpp
int solve(vector<int>& prices, int index, int buy, int k, vector<vector<vector<int>>>& dp) {
```
- This is the helper function `solve` that calculates the maximum profit.
- Parameters:
  - `prices`: The list of stock prices.
  - `index`: The current day (index).
  - `buy`: Indicates whether we are allowed to buy (`1`) or must sell (`0`).
  - `k`: The remaining number of transactions we can perform.
  - `dp`: The 3D DP table to store the intermediate results.

```cpp
int n = prices.size();
if(index == n || k == 0) return 0;
```
- **Base Case**: If we've reached the end of the list (`index == n`) or have no remaining transactions (`k == 0`), return 0 as no further profit can be made.

```cpp
if(dp[index][buy][k] != -1) return dp[index][buy][k];
```
- **Memoization**: If the result for the current state (`index`, `buy`, `k`) has already been computed, return the stored value from the DP table.

```cpp
int profit = 0;
```
- Variable `profit` to store the maximum profit at the current state.

```cpp
if(buy) {
    profit = max(
        -prices[index] + solve(prices, index + 1, 0, k, dp), // Buy
        0 + solve(prices, index + 1, 1, k, dp)              // Skip
    );
}
```
- **If allowed to buy** (`buy = 1`):
  - **Buy**: Subtract the current price from the profit and move to the next day with `buy = 0` (next step will be to sell).
  - **Skip**: Do nothing and move to the next day with `buy = 1` (still allowed to buy).

```cpp
else {
    profit = max(
        prices[index] + solve(prices, index + 1, 1, k - 1, dp), // Sell
        0 + solve(prices, index + 1, 0, k, dp)                // Skip
    );
}
```
- **If not allowed to buy (i.e., need to sell)** (`buy = 0`):
  - **Sell**: Add the current price to the profit and move to the next day with `buy = 1` and decrement `k` (remaining transactions).
  - **Skip**: Do nothing and move to the next day with `buy = 0`.

```cpp
return dp[index][buy][k] = profit;
```
- Store the result for the current state in the DP table `dp[index][buy][k]` and return the profit.

```cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size(); // Total number of days

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solve(prices, 0, 1, k, dp);
}
```
- The `maxProfit` function initializes the 3D DP table (`dp`) with all values set to -1 (indicating that the state has not been computed yet).
- It starts the recursive process from day 0 with the ability to buy and `k` transactions remaining, and calls `solve` to calculate the maximum profit.

### **Example Output Explanation**

Input:  
`k = 2, prices = [3, 2, 6, 5, 0, 3]`

**Output**: (7)

**Reason**:
1. Transaction 1: Buy at day 1 ((price = 2)), sell at day 2 ((price = 6)), profit = (6 - 2 = 4).
2. Transaction 2: Buy at day 4 ((price = 0)), sell at day 5 ((price = 3)), profit = (3 - 0 = 3).

Total profit = (4 + 3 = 7).


### **Time and Space Complexities**

1. **Time Complexity**:
   - The solution explores all possible states for each day, transaction, and buy/sell flag.
   - The 3D DP table has dimensions (n times 2 times (k+1)), where (n) is the number of days and (k) is the maximum number of transactions.
   - Thus, the time complexity is (O(n times 2 times (k+1)) = O(n times k)).

2. **Space Complexity**:
   - The DP table stores values for each combination of `index`, `buy`, and `k`. The space required for the DP table is (O(n times 2 times (k+1))), which simplifies to (O(n times k)).
   - Additionally, the recursion stack requires (O(n)) space in the worst case, so the overall space complexity is (O(n times k)).

---

## Bottom-Up Approach (DP)
In the **Bottom-Up Dynamic Programming** approach for the problem "Best Time to Buy and Sell Stock IV," we aim to find the maximum profit that can be achieved with at most `k` transactions, where each transaction consists of a buy and a sell action. The bottom-up approach is iterative, meaning we solve the problem starting from the base case and build up towards the final solution.

#### **Step-by-Step Explanation of the Approach:**

Let's break down the solution:

1. **State Definition:**
   We define a 3D DP table `dp[i][buy][limit]`:
   - `i`: Day `i` (from 0 to `n-1`), where `n` is the total number of days.
   - `buy`: A binary state (1 for buying, 0 for selling).
   - `limit`: The number of transactions remaining, from 1 to `k`.

2. **Recursive Relationship:**
   For each day `i`, depending on whether we are in the buy or sell state, we calculate the maximum profit:
   - If we are in the "buy" state (`buy == 1`), we can either:
     1. Buy the stock on day `i` and move to the next day with `limit` transactions left.
     2. Skip buying and move to the next day without changing the state.
   - If we are in the "sell" state (`buy == 0`), we can either:
     1. Sell the stock on day `i` and move to the next day, decrementing the transaction limit.
     2. Skip selling and move to the next day without changing the state.

   This is the transition:
   - If `buy == 1`, we calculate:
     ```
     profit = max(-prices[i] + dp[i + 1][0][limit], dp[i + 1][1][limit])
     ```
   - If `buy == 0`, we calculate:
     ```
     profit = max(prices[i] + dp[i + 1][1][limit - 1], dp[i + 1][0][limit])
     ```

3. **Bottom-Up Calculation:**
   We start from the last day (`i = n-1`) and move backwards to the first day (`i = 0`). For each day, for each state (buy/sell), and for each transaction limit (1 to `k`), we compute the maximum profit.

4. **Final Answer:**
   After filling the DP table, the maximum profit will be at `dp[0][1][k]`, which represents starting at day 0 with the ability to buy and `k` transactions remaining.

#### **Example Walkthrough:**

**Example Input:**
- Prices: `[2, 4, 1, 7, 8, 3, 5]`
- Maximum transactions `k = 2`

Let’s visualize the DP table for the example:

- `prices = [2, 4, 1, 7, 8, 3, 5]` (n = 7 days)

### Source Code
```cpp
class Solution {
public:
    // Iterative function to calculate the maximum profit using dynamic programming (bottom-up approach)
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Total number of days

        // Create a 3D DP table where:
        // dp[i][buy][limit]: Maximum profit achievable starting from day `i` with `buy` state and `limit` transactions left
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Iterate backwards over days (from the last day to the first day)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the buy/sell state (0 = sell, 1 = buy)
            for (int buy = 0; buy <= 1; buy++) {
                // Iterate over the transaction limits (from 1 to k)
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0; // Variable to store the profit for the current state

                    if (buy) {
                        // If the current state allows buying, we have two options:
                        // 1. Buy the stock at the current price, then move to the next day with `buy = 0`.
                        // 2. Skip buying and move to the next day with `buy = 1`.
                        int buyStock = -prices[index] + dp[index + 1][0][limit]; // Buying
                        int notBuyStock = 0 + dp[index + 1][1][limit];          // Skipping
                        profit = max(buyStock, notBuyStock);                    // Maximize profit
                    } else {
                        // If the current state allows selling, we have two options:
                        // 1. Sell the stock at the current price, then move to the next day with `buy = 1` and decrement the transaction count.
                        // 2. Skip selling and move to the next day with `buy = 0`.
                        int sellStock = prices[index] + dp[index + 1][1][limit - 1]; // Selling
                        int notSellStock = 0 + dp[index + 1][0][limit];             // Skipping
                        profit = max(sellStock, notSellStock);                      // Maximize profit
                    }

                    // Store the result in the DP table
                    dp[index][buy][limit] = profit;
                }
            }
        }

        // Return the maximum profit starting from day 0, with the ability to buy and `k` transactions available
        return dp[0][1][k];
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days
        
        // Call the solve function to compute the result using dynamic programming
        return solve(prices, k);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Iterative function to calculate the maximum profit using dynamic programming (bottom-up approach)
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Total number of days
```

- **Explanation:**
  - The `solve` function is defined to take `prices` (a vector of stock prices for each day) and `k` (the maximum number of transactions allowed).
  - `n = prices.size()` initializes `n` to the size of the `prices` array, which represents the total number of days. In this case, `n = 7` since there are 7 prices in the example `[2, 4, 1, 7, 8, 3, 5]`.

```cpp
        // Create a 3D DP table where:
        // dp[i][buy][limit]: Maximum profit achievable starting from day `i` with `buy` state and `limit` transactions left
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
```

- **Explanation:**
  - This creates a 3D dynamic programming (DP) table `dp` with dimensions `[n + 1][2][k + 1]`:
    - `n + 1`: We add an extra row to handle the base case where there are no more days left (the day after the last day).
    - `2`: This represents two states: `0` for "selling" and `1` for "buying."
    - `k + 1`: We need to account for transaction limits from `0` to `k`.
  - The table is initialized with all values set to 0 because, initially, no profit is made at any state.

```cpp
        // Iterate backwards over days (from the last day to the first day)
        for (int index = n - 1; index >= 0; index--) {
```

- **Explanation:**
  - We start iterating backwards through the `prices` array, from day `n-1` (the last day) down to day `0`. This is necessary because, in dynamic programming, we typically solve the subproblems starting from the base case and build up.
  - In this case, we need to calculate the maximum profit that can be made starting from each day.

```cpp
            // Iterate over the buy/sell state (0 = sell, 1 = buy)
            for (int buy = 0; buy <= 1; buy++) {
```

- **Explanation:**
  - We iterate through two possible states for each day:
    - `buy = 0`: We are in the "sell" state.
    - `buy = 1`: We are in the "buy" state.

```cpp
                // Iterate over the transaction limits (from 1 to k)
                for (int limit = 1; limit <= k; limit++) {
```

- **Explanation:**
  - We iterate over the transaction limits from `1` to `k`. This loop represents the remaining number of transactions that can be made.
  - We solve the problem for each possible transaction count left (1 to `k`).

```cpp
                    int profit = 0; // Variable to store the profit for the current state
```

- **Explanation:**
  - A variable `profit` is initialized to 0. It will store the maximum profit achievable for the current state, considering the current day, transaction limit, and whether we are in the "buy" or "sell" state.

```cpp
                    if (buy) {
                        // If the current state allows buying, we have two options:
                        // 1. Buy the stock at the current price, then move to the next day with `buy = 0`.
                        // 2. Skip buying and move to the next day with `buy = 1`.
                        int buyStock = -prices[index] + dp[index + 1][0][limit]; // Buying
                        int notBuyStock = 0 + dp[index + 1][1][limit];          // Skipping
                        profit = max(buyStock, notBuyStock);                    // Maximize profit
                    } else {
```

- **Explanation:**
  - If we are in the "buy" state (`buy == 1`):
    - **Option 1 (Buy the stock):** The profit would be `-prices[index] + dp[index + 1][0][limit]`. This means:
      - We buy the stock at `prices[index]` (which is subtracted because it's an expense).
      - We then move to the next day (`index + 1`) in the "sell" state (`buy = 0`) with the same transaction limit.
    - **Option 2 (Do not buy the stock):** The profit is `0 + dp[index + 1][1][limit]`, meaning we skip buying and move to the next day, still in the "buy" state (`buy = 1`) with the same transaction limit.

  - The maximum of these two options is stored in `profit`.

```cpp
                        // If the current state allows selling, we have two options:
                        // 1. Sell the stock at the current price, then move to the next day with `buy = 1` and decrement the transaction count.
                        // 2. Skip selling and move to the next day with `buy = 0`.
                        int sellStock = prices[index] + dp[index + 1][1][limit - 1]; // Selling
                        int notSellStock = 0 + dp[index + 1][0][limit];             // Skipping
                        profit = max(sellStock, notSellStock);                      // Maximize profit
                    }
```

- **Explanation:**
  - If we are in the "sell" state (`buy == 0`):
    - **Option 1 (Sell the stock):** The profit would be `prices[index] + dp[index + 1][1][limit - 1]`. This means:
      - We sell the stock at `prices[index]`.
      - We move to the next day (`index + 1`) in the "buy" state (`buy = 1`), but now with one fewer transaction (`limit - 1`).
    - **Option 2 (Do not sell the stock):** The profit is `0 + dp[index + 1][0][limit]`, meaning we skip selling and move to the next day in the "sell" state (`buy = 0`) with the same transaction limit.

  - The maximum of these two options is stored in `profit`.

```cpp
                    // Store the result in the DP table
                    dp[index][buy][limit] = profit;
```

- **Explanation:**
  - The calculated profit for the current day, state, and transaction limit is stored in the DP table at `dp[index][buy][limit]`.

```cpp
                }
            }
        }
```

- **Explanation:**
  - These loops iterate over all the days, states, and transaction limits, calculating and storing the maximum profit for each combination.

```cpp
        // Return the maximum profit starting from day 0, with the ability to buy and `k` transactions available
        return dp[0][1][k];
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days
        
        // Call the solve function to compute the result using dynamic programming
        return solve(prices, k);
    }
};
```

- **Explanation:**
  - After the DP table has been filled, the maximum profit is stored in `dp[0][1][k]`, which represents the maximum profit that can be achieved starting from day 0 with `k` transactions remaining and the ability to buy.
  - The `maxProfit` function simply calls the `solve` function to compute and return the result.

### **Example Walkthrough:**

**Input:** `prices = [2, 4, 1, 7, 8, 3, 5], k = 2`

1. The DP table is initialized with zeros.
2. We start filling the table by considering each day, each state (`buy` or `sell`), and each transaction limit (`k`).
3. We calculate the profit for each option (buy or sell) and update the DP table.
4. Finally, after iterating over all the days and states, the maximum profit is stored in `dp[0][1][2]`.

**Output:** `12`

- **Explanation:**
  - Maximum profit of `12` can be achieved by:
    1. Buying at price `2` on day 0 and selling at price `7` on day 3.
    2. Buying at price `1` on day 2 and selling at price `8` on day 4.

### **Time and Space Complexity:**

1. **Time Complexity:**  
   The code has three nested loops:
   - The outer loop runs `n` times (for each day).
   - The middle loop runs `2` times (for the buy/sell state).
   - The inner loop runs `k` times (for the transaction limit).
   Therefore, the time complexity is **O(n * 2 * k) = O(n * k)**.

2. **Space Complexity:**  
   The space complexity is mainly determined by the DP table, which has dimensions `[n + 1][2][k + 1]`. Thus, the space complexity is **O(n * k)**.

---

## Space Optimization Approach (DP)

1. **Problem Recap**:
   The problem involves maximizing the profit from buying and selling a stock with at most `k` transactions. Each transaction consists of buying and then selling the stock. The goal is to find the maximum profit by making at most `k` transactions.

2. **Traditional DP Solution**:
   A typical dynamic programming (DP) solution uses a 3D table `dp[i][buy][limit]`:
   - `i`: Day index (0 to n-1)
   - `buy`: 0 for selling, 1 for buying
   - `limit`: Number of transactions left (1 to k)

   This leads to a time complexity of `O(n * 2 * k)` and a space complexity of `O(n * 2 * k)`.

3. **Space Optimization**:
   Instead of storing the entire 3D table, we optimize the space by recognizing that for calculating the profit on day `i`, we only need the information from day `i+1`. So, we only need two 2D arrays (`curr` and `next`), one for the current day's results and one for the next day's results.

4. **Key Idea**:
   - **`curr`**: Stores the DP results for the current day.
   - **`next`**: Stores the DP results for the next day.

   After processing each day, we move the `curr` array to `next`, effectively discarding the previous day's results to save space.

5. **Approach Details**:
   - Initialize two 2D arrays `curr` and `next`, both of size `2 x (k+1)` (representing two states: buy/sell, and `k+1` possible transaction limits).
   - Traverse the days backward from `n-1` to `0`, updating the `curr` array for each day based on the `next` array (the result from the next day).
   - For each day and state (buy or sell), calculate the maximum profit considering the following options:
     - **Buy the stock**: For `buy = 1`, calculate the maximum profit by either buying the stock or not buying it.
     - **Sell the stock**: For `buy = 0`, calculate the maximum profit by either selling the stock or not selling it.
   - After calculating the profit for each state and transaction limit, store it in `curr`.
   - At the end of each iteration, move `curr` to `next` for the next day's calculations.

6. **Final Result**:
   After processing all days, the result (maximum profit) for `k` transactions is stored in `curr[1][k]` (the result for the "sell" state on day 0 with `k` transactions remaining).

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Total number of days

        // Create two 2D vectors `curr` and `next` to store the DP states for the current and next days.
        // Each has 2 rows for the buy/sell state and `k+1` columns for the transaction limit.
        vector<vector<int>> curr(2, vector<int>(k + 1, 0)); // Current day's DP table
        vector<vector<int>> next(2, vector<int>(k + 1, 0)); // Next day's DP table

        // Iterate backwards over days (from the last day to the first day)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over the buy/sell state (0 = sell, 1 = buy)
            for (int buy = 0; buy <= 1; buy++) {
                // Iterate over the transaction limits (from 1 to k)
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0; // Variable to store the profit for the current state

                    if (buy) {
                        // If the current state allows buying, we have two options:
                        // 1. Buy the stock at the current price, then move to the next day with `buy = 0`.
                        // 2. Skip buying and move to the next day with `buy = 1`.
                        int buyStock = -prices[index] + next[0][limit]; // Buying
                        int notBuyStock = 0 + next[1][limit];          // Skipping
                        profit = max(buyStock, notBuyStock);           // Maximize profit
                    } else {
                        // If the current state allows selling, we have two options:
                        // 1. Sell the stock at the current price, then move to the next day with `buy = 1` and decrement the transaction count.
                        // 2. Skip selling and move to the next day with `buy = 0`.
                        int sellStock = prices[index] + next[1][limit - 1]; // Selling
                        int notSellStock = 0 + next[0][limit];             // Skipping
                        profit = max(sellStock, notSellStock);             // Maximize profit
                    }

                    // Store the result in the current DP table
                    curr[buy][limit] = profit;
                }
            }

            // Move the current DP table to the next day (space optimization)
            next = curr;
        }

        // Return the maximum profit starting from day 0, with the ability to buy and `k` transactions available
        return curr[1][k];
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days
        
        // Call the solve function to compute the result using dynamic programming
        return solve(prices, k);
    }
};
```
### Source Code Explanation

```cpp
class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Total number of days
```

- **Explanation:**
  - This function is used to compute the maximum profit using space-optimized dynamic programming (DP).
  - `prices` is the vector that contains the stock prices for each day.
  - `k` is the maximum number of transactions allowed.
  - `n` stores the total number of days (`prices.size()`), which helps in determining the range for iterating over the days.

```cpp
        // Create two 2D vectors `curr` and `next` to store the DP states for the current and next days.
        // Each has 2 rows for the buy/sell state and `k+1` columns for the transaction limit.
        vector<vector<int>> curr(2, vector<int>(k + 1, 0)); // Current day's DP table
        vector<vector<int>> next(2, vector<int>(k + 1, 0)); // Next day's DP table
```

- **Explanation:**
  - We initialize two 2D vectors, `curr` and `next`, to store the DP table for the current and the next day.
  - Each 2D vector has:
    - `2` rows (representing the buy/sell state: `0` for sell, `1` for buy).
    - `k+1` columns for the transaction limits (from `0` to `k`).
  - Both tables are initialized with `0`, as initially, no profit is made.

```cpp
        // Iterate backwards over days (from the last day to the first day)
        for (int index = n - 1; index >= 0; index--) {
```

- **Explanation:**
  - We iterate backward from the last day (`n - 1`) to the first day (`0`). This is essential for dynamic programming, where we solve the problem starting from the base case (last day) and work our way backward.

```cpp
            // Iterate over the buy/sell state (0 = sell, 1 = buy)
            for (int buy = 0; buy <= 1; buy++) {
```

- **Explanation:**
  - For each day, we consider both the "buy" (`buy = 1`) and "sell" (`buy = 0`) states. We will compute the profit for both these states.
  
```cpp
                // Iterate over the transaction limits (from 1 to k)
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0; // Variable to store the profit for the current state
```

- **Explanation:**
  - For each day and each state, we iterate through all the possible transaction limits, from `1` to `k`. The `limit` represents how many transactions are still available to perform.
  - `profit` is initialized to `0` for each state and limit, which will store the maximum profit that can be made for the current day, state, and transaction limit.

```cpp
                    if (buy) {
                        // If the current state allows buying, we have two options:
                        // 1. Buy the stock at the current price, then move to the next day with `buy = 0`.
                        // 2. Skip buying and move to the next day with `buy = 1`.
                        int buyStock = -prices[index] + next[0][limit]; // Buying
                        int notBuyStock = 0 + next[1][limit];          // Skipping
                        profit = max(buyStock, notBuyStock);           // Maximize profit
                    } else {
```

- **Explanation:**
  - If we are in the "buy" state (`buy = 1`):
    - **Option 1 (Buy the stock):** We can buy the stock at `prices[index]`, which will decrease the profit by `prices[index]` (hence `-prices[index]`).
      - After buying, we move to the next day in the "sell" state (`buy = 0`) with the same transaction limit (`limit`), and the profit would be `next[0][limit]` (from the "sell" state on the next day).
    - **Option 2 (Do not buy):** We skip buying, and stay in the "buy" state on the next day (`next[1][limit]`).
  - The maximum of these two options is chosen and stored in `profit`.

```cpp
                        // If the current state allows selling, we have two options:
                        // 1. Sell the stock at the current price, then move to the next day with `buy = 1` and decrement the transaction count.
                        // 2. Skip selling and move to the next day with `buy = 0`.
                        int sellStock = prices[index] + next[1][limit - 1]; // Selling
                        int notSellStock = 0 + next[0][limit];             // Skipping
                        profit = max(sellStock, notSellStock);             // Maximize profit
                    }
```

- **Explanation:**
  - If we are in the "sell" state (`buy = 0`):
    - **Option 1 (Sell the stock):** We can sell the stock at `prices[index]` and gain that amount. After selling, we move to the next day in the "buy" state (`buy = 1`), and decrease the transaction limit by 1 (`limit - 1`). The profit would be `prices[index] + next[1][limit - 1]` (the value from the next day’s "buy" state).
    - **Option 2 (Do not sell):** We skip selling, and stay in the "sell" state on the next day (`next[0][limit]`), keeping the same transaction limit.
  - The maximum of these two options is stored in `profit`.

```cpp
                    // Store the result in the current DP table
                    curr[buy][limit] = profit;
```

- **Explanation:**
  - The computed `profit` for the current state (`buy` or `sell`) and transaction limit (`limit`) is stored in the `curr` DP table.

```cpp
                }
            }

            // Move the current DP table to the next day (space optimization)
            next = curr;
        }
```

- **Explanation:**
  - After completing the iterations for each day, state, and transaction limit, the current DP table (`curr`) is moved to the `next` table, which will be used for the next iteration (next day).
  - This optimizes space by reusing the same tables for each iteration (instead of creating a full 3D DP table, we only maintain two 2D tables).

```cpp
        // Return the maximum profit starting from day 0, with the ability to buy and `k` transactions available
        return curr[1][k];
    }

    // Main function to calculate the maximum profit
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days
        
        // Call the solve function to compute the result using dynamic programming
        return solve(prices, k);
    }
};
```

- **Explanation:**
  - Finally, the result is stored in `curr[1][k]`, which represents the maximum profit starting from day `0`, in the "buy" state (`buy = 1`), with `k` transactions remaining.
  - The `maxProfit` function calls the `solve` function and returns the result.

### **Example Walkthrough:**

**Input:** `prices = [2, 4, 1, 7, 8, 3, 5], k = 2`

1. The initial `curr` and `next` tables are initialized to `0`.
2. We iterate backward over each day, for each possible "buy" or "sell" state, and each transaction limit.
3. For each state, we calculate the maximum profit using two options: buy/sell or skip. The computed values are stored in the `curr` table.
4. After processing all days, the final maximum profit will be stored in `curr[1][k]`.

**Output:** `12`

- **Explanation:**
  - Maximum profit of `12` can be achieved by:
    1. Buying at price `2` on day 0 and selling at price `7` on day 3.
    2. Buying at price `1` on day 2 and selling at price `8` on day 4.

### **Time and Space Complexity:**

1. **Time Complexity:**  
   - The code has three nested loops:
     - Outer loop (days): runs `n` times.
     - Middle loop (buy/sell state): runs 2 times.
     - Inner loop (transaction limit): runs `k` times.
   - The time complexity is **O(n * 2 * k) = O(n * k)**.

2. **Space Complexity:**  
   - Instead of using a 3D DP table, we only maintain two 2D tables (`curr` and `next`), each of size `2 x (

k + 1)`.
   - The space complexity is **O(2 * (k + 1)) = O(k)**.

This space-optimized approach significantly reduces the space complexity compared to the full DP approach.

---
---

## Number of Transactions Recursive Approach (caused TLE)
1. **Problem Recap**:
   We are given an array of stock prices for `n` days, and we can perform at most `k` transactions. Each transaction consists of a buy and a sell. Our goal is to maximize the profit after at most `k` transactions.

   In this approach, instead of using a dynamic programming table, we use a recursive approach to explore all possible states.

2. **Recursive Approach**:
   The recursive approach explores each day and considers two options for every transaction:
   - **Buy**: Buy the stock on the current day.
   - **Sell**: Sell the stock on the current day.
   Each transaction is either a "buy" or a "sell", and we need to track the state of transactions using a recursive call.

3. **State Representation**:
   - `index`: The current day (we move from left to right).
   - `transactionNo`: A counter for the transaction number. If it's even, it's a "buy" transaction. If it's odd, it's a "sell" transaction.
   - `k`: The maximum number of transactions allowed.

4. **Base Case**:
   The recursion stops when we reach:
   - The end of the price list (`index == prices.size()`), or
   - We have completed `2 * k` transactions (since each transaction consists of a buy and sell).

5. **Recursive Choices**:
   - For each day, the function explores whether to buy or skip (if it's a buy transaction).
   - Similarly, for each day, it explores whether to sell or skip (if it's a sell transaction).

   The goal is to maximize the profit by comparing the results of buying, selling, and skipping for each day.

### **Step-by-Step Walkthrough with Example**

Consider `prices = [2, 4, 1, 7]` and `k = 2`.

- On day 0, the price is `2`, and we have a maximum of 2 transactions.
  - We can either buy the stock (at price `2`) or skip.
  
- On day 1, the price is `4`.
  - If we bought the stock earlier, we can now sell at price `4`.
  
- On day 2, the price is `1`.
  - If we didn't sell earlier, we can either buy again (at price `1`) or skip.

- On day 3, the price is `7`.
  - We can sell the stock if we bought earlier at price `1`.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the maximum profit
    // `prices`: vector of stock prices
    // `index`: current day index
    // `transactionNo`: current transaction number (0-based, where even = buy, odd = sell)
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int index, int transactionNo, int k) {
        // Base case: if we reach the end of the prices array or have completed `2 * k` transactions
        if (index == prices.size() || transactionNo == 2 * k) return 0;

        int profit = 0; // Variable to store the profit for the current state

        // Check if the current transaction is a "buy" (even transactionNo)
        if (transactionNo % 2 == 0) {
            // Option 1: Buy the stock on the current day and move to the next transaction
            int buyStock = -prices[index] + solve(prices, index + 1, transactionNo + 1, k);
            // Option 2: Skip buying and move to the next day
            int notBuyStock = 0 + solve(prices, index + 1, transactionNo, k);
            // Maximize the profit between buying and skipping
            profit = max(buyStock, notBuyStock);
        } else {
            // If the current transaction is a "sell" (odd transactionNo)
            // Option 1: Sell the stock on the current day and move to the next transaction
            int sellStock = +prices[index] + solve(prices, index + 1, transactionNo + 1, k);
            // Option 2: Skip selling and move to the next day
            int notSellStock = 0 + solve(prices, index + 1, transactionNo, k);
            // Maximize the profit between selling and skipping
            profit = max(sellStock, notSellStock);
        }

        return profit; // Return the profit for the current state
    }

    // Function to calculate the maximum profit with at most `k` transactions
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Call the recursive function starting from day 0 and transaction number 0
        return solve(prices, 0, 0, k);
    }
};
```

### Source Code Explanation

```cpp
// Recursive function to calculate the maximum profit
// `prices`: vector of stock prices
// `index`: current day index
// `transactionNo`: current transaction number (0-based, where even = buy, odd = sell)
// `k`: maximum number of transactions allowed
```
- The function `solve` is responsible for recursively calculating the maximum profit starting from a given `index` and `transactionNo`.
  
```cpp
if (index == prices.size() || transactionNo == 2 * k) return 0;
```
- **Base Case**: If we've either reached the end of the price list or completed `2 * k` transactions (since each transaction consists of one buy and one sell), the recursion stops and returns `0`.

```cpp
int profit = 0; // Variable to store the profit for the current state
```
- This variable will store the maximum profit for the current day and transaction state.

```cpp
if (transactionNo % 2 == 0) {
    // Option 1: Buy the stock on the current day and move to the next transaction
    int buyStock = -prices[index] + solve(prices, index + 1, transactionNo + 1, k);
    // Option 2: Skip buying and move to the next day
    int notBuyStock = 0 + solve(prices, index + 1, transactionNo, k);
    // Maximize the profit between buying and skipping
    profit = max(buyStock, notBuyStock);
}
```
- If `transactionNo` is even (indicating it's a buy transaction):
  - **Option 1**: Buy the stock at the current price and recursively calculate the profit from the next day with the next transaction.
  - **Option 2**: Skip the buy action and move to the next day without changing the transaction state.

```cpp
else {
    // Option 1: Sell the stock on the current day and move to the next transaction
    int sellStock = prices[index] + solve(prices, index + 1, transactionNo + 1, k);
    // Option 2: Skip selling and move to the next day
    int notSellStock = 0 + solve(prices, index + 1, transactionNo, k);
    // Maximize the profit between selling and skipping
    profit = max(sellStock, notSellStock);
}
```
- If `transactionNo` is odd (indicating it's a sell transaction):
  - **Option 1**: Sell the stock at the current price and recursively calculate the profit from the next day with the next transaction.
  - **Option 2**: Skip the sell action and move to the next day without changing the transaction state.

```cpp
return profit; // Return the profit for the current state
```
- After considering both options (buy or sell), the maximum profit is returned.

```cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size(); // Total number of days
    // Call the recursive function starting from day 0 and transaction number 0
    return solve(prices, 0, 0, k);
}
```
- The `maxProfit` function is the entry point. It calls the `solve` function starting from day 0 and the first transaction (0). The function returns the maximum profit after all recursive calls are completed.

### **Example Output Walkthrough**

For `prices = [2, 4, 1, 7]` and `k = 2`:

1. **Transaction 1**: Buy at `2` (first buy).
2. **Transaction 2**: Sell at `4` (first sell). Profit = `4 - 2 = 2`.
3. **Transaction 3**: Buy at `1` (second buy).
4. **Transaction 4**: Sell at `7` (second sell). Profit = `7 - 1 = 6`.

Thus, the total profit from two transactions is `2 + 6 = 8`.

### **Time and Space Complexity**

1. **Time Complexity**:
   - In the worst case, for every combination of `index` (n days) and `transactionNo` (2 * k transactions), the recursive function is called. So, the time complexity is `O(n * 2 * k)`.

2. **Space Complexity**:
   - The space complexity is `O(n * 2 * k)` for the recursion stack due to the depth of recursive calls, which can go up to `2 * k` levels for each day (`n` days).

---

## Number of Transactions | Top-Down | Approach (DP)
This approach uses **Top-Down Dynamic Programming (DP)** with **memoization** to calculate the maximum profit for `k` transactions. The idea is to break down the problem into smaller subproblems, solve them recursively, and store the results to avoid redundant calculations.

In this solution, the maximum number of transactions allowed is `k`, and each transaction involves two actions:
- **Buy** (even transaction number)
- **Sell** (odd transaction number)

#### **Steps in the Approach:**

1. **State Representation**:
   We define the following parameters for the recursive function `solve`:
   - `index`: The current day index in the price list.
   - `transactionNo`: The number of transactions completed so far (a 0-based index where even means "buy" and odd means "sell").
   - `k`: The maximum number of transactions allowed.
   - `dp`: A memoization table (`dp[index][transactionNo]`) that stores the maximum profit for a given day (`index`) and transaction (`transactionNo`).

2. **Base Case**:
   - If we've reached the end of the price list (`index == prices.size()`) or completed `2 * k` transactions (i.e., both buy and sell for `k` times), we return `0` because no profit can be made anymore.

3. **Recursive Case**:
   - For each day, we either:
     - **Buy** the stock if the transaction number is even (i.e., a buy transaction), or
     - **Sell** the stock if the transaction number is odd (i.e., a sell transaction).
   - The two choices are:
     - **Buy**: Buy the stock and move to the next day and transaction.
     - **Sell**: Sell the stock and move to the next day and transaction.
   - For each choice, we compute the profit and take the maximum of the two.

4. **Memoization**:
   - The results for each state (`index`, `transactionNo`) are stored in the `dp` table. Before recalculating a value, we check if it's already computed.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the maximum profit with memoization
    // `prices`: vector of stock prices
    // `index`: current day index
    // `transactionNo`: current transaction number (0-based, where even = buy, odd = sell)
    // `k`: maximum number of transactions allowed
    // `dp`: memoization table to store intermediate results
    int solve(vector<int>& prices, int index, int transactionNo, int k, vector<vector<int>>& dp) {
        // Base case: If we've reached the end of the array or completed all allowed transactions
        if (index == prices.size() || transactionNo == 2 * k) return 0;

        // Check if the result for this state is already computed
        if (dp[index][transactionNo] != -1) return dp[index][transactionNo];

        int profit = 0; // Variable to store the profit for the current state

        // If the current transaction is a "buy" operation (even transaction number)
        if (transactionNo % 2 == 0) {
            // Option 1: Buy the stock on the current day and move to the next transaction
            int buyStock = -prices[index] + solve(prices, index + 1, transactionNo + 1, k, dp);
            // Option 2: Skip buying and move to the next day
            int notBuyStock = 0 + solve(prices, index + 1, transactionNo, k, dp);
            // Maximize the profit between buying and skipping
            profit = max(buyStock, notBuyStock);
        } else {
            // If the current transaction is a "sell" operation (odd transaction number)
            // Option 1: Sell the stock on the current day and move to the next transaction
            int sellStock = +prices[index] + solve(prices, index + 1, transactionNo + 1, k, dp);
            // Option 2: Skip selling and move to the next day
            int notSellStock = 0 + solve(prices, index + 1, transactionNo, k, dp);
            // Maximize the profit between selling and skipping
            profit = max(sellStock, notSellStock);
        }

        // Store the result in the dp table to avoid recomputation
        return dp[index][transactionNo] = profit;
    }

    // Function to calculate the maximum profit with at most `k` transactions
    // `k`: maximum number of transactions allowed
    // `prices`: vector of stock prices
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Memoization table to store results for each day and transaction number
        // `dp[i][j]`: Maximum profit achievable from day `i` onwards with transaction number `j`
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));

        // Call the recursive function starting from day 0 and transaction number 0
        return solve(prices, 0, 0, k, dp);
    }
};
```

### Source Code Explanation

```cpp
// Recursive function to calculate the maximum profit with memoization
// `prices`: vector of stock prices
// `index`: current day index
// `transactionNo`: current transaction number (0-based, where even = buy, odd = sell)
// `k`: maximum number of transactions allowed
// `dp`: memoization table to store intermediate results
```
- The `solve` function is defined with the above parameters to calculate the maximum profit recursively for each state (`index`, `transactionNo`).

```cpp
if (index == prices.size() || transactionNo == 2 * k) return 0;
```
- **Base case**: If we have reached the end of the price list (`index == prices.size()`) or completed all allowed transactions (`transactionNo == 2 * k`), the function returns `0` since no profit can be made.

```cpp
if (dp[index][transactionNo] != -1) return dp[index][transactionNo];
```
- **Memoization check**: If the result for the current state has already been computed and stored in `dp[index][transactionNo]`, we return it to avoid redundant calculations.

```cpp
int profit = 0; // Variable to store the profit for the current state
```
- This variable stores the maximum profit that can be obtained from the current day and transaction state.

```cpp
if (transactionNo % 2 == 0) {
    // Option 1: Buy the stock on the current day and move to the next transaction
    int buyStock = -prices[index] + solve(prices, index + 1, transactionNo + 1, k, dp);
    // Option 2: Skip buying and move to the next day
    int notBuyStock = 0 + solve(prices, index + 1, transactionNo, k, dp);
    // Maximize the profit between buying and skipping
    profit = max(buyStock, notBuyStock);
} else {
    // If the current transaction is a "sell" operation (odd transaction number)
    // Option 1: Sell the stock on the current day and move to the next transaction
    int sellStock = +prices[index] + solve(prices, index + 1, transactionNo + 1, k, dp);
    // Option 2: Skip selling and move to the next day
    int notSellStock = 0 + solve(prices, index + 1, transactionNo, k, dp);
    // Maximize the profit between selling and skipping
    profit = max(sellStock, notSellStock);
}
```
- **Recursive logic**:
  - **If `transactionNo` is even** (i.e., a "buy" transaction):
    - **Option 1**: Buy the stock on the current day and recursively calculate the profit for the next day with the next transaction (`transactionNo + 1`).
    - **Option 2**: Skip buying and move to the next day without changing the transaction state.
  - **If `transactionNo` is odd** (i.e., a "sell" transaction):
    - **Option 1**: Sell the stock on the current day and recursively calculate the profit for the next day with the next transaction.
    - **Option 2**: Skip selling and move to the next day without changing the transaction state.
  - The function maximizes the profit between buying/selling and skipping.

```cpp
return dp[index][transactionNo] = profit;
```
- **Memoization**: After calculating the profit for the current state, we store it in the `dp` table (`dp[index][transactionNo]`) to avoid recalculating it for the same state in future calls.

```cpp
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size(); // Total number of days

    // Memoization table to store results for each day and transaction number
    // `dp[i][j]`: Maximum profit achievable from day `i` onwards with transaction number `j`
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));

    // Call the recursive function starting from day 0 and transaction number 0
    return solve(prices, 0, 0, k, dp);
}
```
- **Entry Point**:
  - The `maxProfit` function initializes the memoization table `dp` with dimensions `n x (2 * k)`, where `n` is the number of days, and `2 * k` represents the maximum possible transaction numbers (each buy and sell is a transaction).
  - The function then calls the `solve` function starting from day 0 and transaction 0.

#### **Example Walkthrough**

For `prices = [2, 4, 1, 7]` and `k = 2`:

1. **Transaction 1**: Buy at `2` (first buy).
2. **Transaction 2**: Sell at `4` (first sell). Profit = `4 - 2 = 2`.
3. **Transaction 3**: Buy at `1` (second buy).
4. **Transaction 4**: Sell at `7` (second sell). Profit = `7 - 1 = 6`.

Thus, the total profit from two transactions is `2 + 6 = 8`.

#### **Time and Space Complexity**

1. **Time Complexity**:
   - The recursive function computes the maximum profit for each combination of `index` (n days) and `transactionNo` (up to `2 * k` transactions).
   - Therefore, the time complexity is `O(n * 2 * k)`, where `n` is the number of days and `k` is the number of transactions.

2. **Space Complexity**:
   - The space complexity is determined by the `dp` table, which has dimensions `n x (2 * k)`, so the space complexity is `O(n * 2 * k)`.
   - Additionally, the recursive call stack adds an extra space complexity of `O(n)` in the worst case.

---

## Number of Transactions | Bottom-Up | Approach (DP)
In the "Bottom-Up DP" approach, we aim to calculate the maximum profit from a series of stock prices while performing at most `k` transactions (each consisting of a "buy" followed by a "sell").

#### Key Concepts:

- **Transaction:** A transaction consists of a "buy" followed by a "sell" operation.
  - **Buy Operation:** You purchase a stock on a given day.
  - **Sell Operation:** You sell a stock on a given day.
- **State:** The DP state consists of two variables:
  - The day (or index) of the stock price.
  - The transaction number (either buy or sell).

We want to determine the maximum profit that can be made from performing at most `k` transactions.

#### Approach:

1. **DP Table Definition:**
   - The table `dp[i][j]` represents the maximum profit achievable starting from day `i` with transaction number `j`.
     - `i`: The day index (from `0` to `n-1`).
     - `j`: The transaction index (ranging from `0` to `2*k`).
       - If `j` is even, it represents a "buy" operation.
       - If `j` is odd, it represents a "sell" operation.

2. **Iterate Backwards:**
   - Start from the last day and move backward to day `0`. This allows us to compute the profit for each transaction as we go back in time.
   
3. **Two Possible Choices for Each Transaction:**
   - For each transaction (`j`), there are two choices:
     - **Buy:** If it's a "buy" transaction (`j` is even), you can either:
       1. Buy the stock today (subtract the price from the profit of the next transaction).
       2. Skip the buy and continue to the next day.
     - **Sell:** If it's a "sell" transaction (`j` is odd), you can either:
       1. Sell the stock today (add the price to the profit of the next transaction).
       2. Skip the sell and continue to the next day.

4. **Maximize Profit:**
   - For each transaction, choose the option that maximizes the profit.

5. **Final Answer:**
   - The final answer will be in `dp[0][0]`, representing the maximum profit starting from day 0 with no transactions.

### Example:

Let’s consider an example to understand the approach:

#### Example:
```cpp
k = 2
prices = [3, 2, 6, 5, 0, 3````

1. **Initialization:**
   - We have `n = 6` (number of days).
   - We need to create a DP table with size `(6 + 1) x (2 * 2 + 1)` (i.e., `7 x 5`).

2. **Filling the DP Table:**
   - We start iterating from the last day (day 5) and move backward.

#### DP Table for the Example:

| DayTrans. | 0 (Buy) | 1 (Sell) | 2 (Buy) | 3 (Sell) | 4 (Buy) |
|------------|---------|----------|---------|----------|---------|
| 5          | 0       | 3        | 0       | 3        | 0       |
| 4          | 3       | 3        | 3       | 3        | 3       |
| 3          | 1       | 3        | 3       | 3        | 3       |
| 2          | 1       | 3        | 3       | 3        | 3       |
| 1          | 1       | 3        | 3       | 3        | 3       |
| 0          | 1       | 3        | 3       | 3        | 3       |

- **First Iteration (Day 5):**
  - Transaction 0 (Buy): The best action is to do nothing, so profit is `0`.
  - Transaction 1 (Sell): Sell at price 3 on day 5, and profit is `3`.
  
- **Subsequent Iterations (Day 4 to Day 0):**
  - For each day, we calculate the maximum profit based on the current price and future transactions.

3. **Final Answer:**
   - The maximum profit is found at `dp[0][0] = 3`.
     
### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum profit using dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Number of days

        // Create a DP table to store the maximum profit
        // `dp[i][j]`: Maximum profit achievable from day `i` onwards with transaction number `j`
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        // Iterate through days in reverse order (bottom-up DP)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate through all possible transaction states
            for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++) {
                int profit = 0;

                // Determine whether the current transaction is a "buy" or "sell"
                if (transactionNo % 2 == 0) { // Buy operation
                    // Option 1: Buy the stock on the current day and move to the next transaction
                    int buyStock = -prices[index] + dp[index + 1][transactionNo + 1];
                    // Option 2: Skip buying and move to the next day
                    int notBuyStock = 0 + dp[index + 1][transactionNo];
                    // Maximize profit between buying and skipping
                    profit = max(buyStock, notBuyStock);
                } else { // Sell operation
                    // Option 1: Sell the stock on the current day and move to the next transaction
                    int sellStock = +prices[index] + dp[index + 1][transactionNo + 1];
                    // Option 2: Skip selling and move to the next day
                    int notSellStock = 0 + dp[index + 1][transactionNo];
                    // Maximize profit between selling and skipping
                    profit = max(sellStock, notSellStock);
                }

                // Store the calculated profit in the DP table
                dp[index][transactionNo] = profit;
            }
        }

        // The maximum profit starting from day 0 with no transactions made yet
        return dp[0][0];
    }

    // Main function to calculate the maximum profit with at most `k` transactions
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Call the solve function to compute the maximum profit
        return solve(prices, k);
    }
};
```

### Source Code Explanation

Let’s break down the code and understand each line.

```cpp
class Solution {
public:
    // Function to calculate the maximum profit using dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Number of days
```
- Here, we initialize `n` as the number of days (the size of the `prices` array).

```cpp
        // Create a DP table to store the maximum profit
        // `dp[i][j]`: Maximum profit achievable from day `i` onwards with transaction number `j`
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
```
- A DP table `dp` is created with dimensions `(n + 1) x (2 * k + 1)`. We initialize all values to `0`.

```cpp
        // Iterate through days in reverse order (bottom-up DP)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate through all possible transaction states
            for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++) {
                int profit = 0;
```
- We iterate through the days from `n-1` to `0` (reverse order) and for each day, we iterate through the transaction states.

```cpp
                // Determine whether the current transaction is a "buy" or "sell"
                if (transactionNo % 2 == 0) { // Buy operation
```
- If the transaction number (`transactionNo`) is even, it represents a "buy" operation.

```cpp
                    // Option 1: Buy the stock on the current day and move to the next transaction
                    int buyStock = -prices[index] + dp[index + 1][transactionNo + 1];
                    // Option 2: Skip buying and move to the next day
                    int notBuyStock = 0 + dp[index + 1][transactionNo];
                    // Maximize profit between buying and skipping
                    profit = max(buyStock, notBuyStock);
                } else { // Sell operation
```
- If it's a "buy" operation:
  - **Option 1:** Buy the stock today and move to the next transaction.
  - **Option 2:** Skip buying and move to the next transaction.
  
  We take the maximum of these two options.
- If the transaction is a "sell" operation (odd transaction number), similar calculations are done for selling.

```cpp
                    // Option 1: Sell the stock on the current day and move to the next transaction
                    int sellStock = +prices[index] + dp[index + 1][transactionNo + 1];
                    // Option 2: Skip selling and move to the next day
                    int notSellStock = 0 + dp[index + 1][transactionNo];
                    // Maximize profit between selling and skipping
                    profit = max(sellStock, notSellStock);
                }

                // Store the calculated profit in the DP table
                dp[index][transactionNo] = profit;
            }
        }

        // The maximum profit starting from day 0 with no transactions made yet
        return dp[0][0];
    }
```
- Similar to the "buy" operation, we calculate the profit for the "sell" operation.
- Finally, store the result in `dp[index][transactionNo]` and proceed to the next iteration.

```cpp
    // Main function to calculate the maximum profit with at most `k` transactions
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(); // Total number of days

        // Call the solve function to compute the maximum profit
        return solve(prices, k);
    }
};
```
- This function calls the `solve` function and returns the maximum profit starting from day `0` with no transactions.

### Example Output:

For the input:
```cpp
k = 2
prices = [3, 2, 6, 5, 0, 3
````

The DP table is filled, and the final answer is `3`, meaning the maximum profit is `3` by performing at most 2 transactions.

### Time Complexity:

- We iterate through `n` days and for each day, we iterate through `2*k` transaction states.
- Therefore, the time complexity is `O(n * k)`.

### Space Complexity:

- We use a 2D DP table of size `(n+1) x (2*k+1)` to store the results.
- Therefore, the space complexity is `O(n * k)`.

This solution is efficient in terms of both time and space, considering the problem constraints.

---

## Number of Transactions | Space Optimization | Approach (DP)
In this approach, we aim to optimize the space complexity of the previous solution by reducing the 2D DP table to two 1D arrays, `curr` and `next`. This will store the maximum profit for the current day and the next day, respectively, while still calculating the maximum profit from performing at most `k` transactions.

#### Key Concepts:

- **Transaction States:**
  - Each transaction consists of two phases: **buy** and **sell**.
  - A transaction index `j` determines whether it is a buy (even `j`) or a sell (odd `j`).
- **Optimizing Space:**
  - Instead of using a 2D DP table of size `(n+1) x (2*k+1)`, we use two 1D arrays `curr` and `next`, each of size `2*k + 1`.
  - This optimization is possible because the calculation for a given day only depends on the values from the next day.

#### Approach:

1. **Initialization:**
   - We initialize two arrays `curr` and `next` with size `2*k + 1`, each filled with `0`. These arrays will store the profit for each transaction state for the current and next day.
   
2. **Iterating Over Days:**
   - We iterate backward over the days (`n-1` to `0`), calculating the maximum profit for each transaction state.
   
3. **Transaction Decisions:**
   - For each day and each transaction state:
     - **Buy (even transactionNo):** Either buy the stock today and proceed to the next state, or skip buying.
     - **Sell (odd transactionNo):** Either sell the stock today and proceed to the next state, or skip selling.
   
4. **Switch Between `curr` and `next`:**
   - After each day's calculations, we update the `next` array to store the results of the current day (`curr`), and then swap `next` and `curr` for the next iteration.

5. **Final Answer:**
   - The final answer, which is the maximum profit starting from day `0` with no transactions made, will be in `next[0]`.

### Example:

Let’s go through an example to understand the approach:

#### Example:
```cpp
k = 2
prices = [3, 2, 6, 5, 0, 3
````

1. **Initialization:**
   - `n = 6` (number of days).
   - Two 1D arrays `curr` and `next` of size `2*k+1 = 5` are initialized to `[0, 0, 0, 0, 0]`.

2. **Iterating Over Days (Day 5 to Day 0):**
   - We start with day 5 and move backward.
   - For each day, we calculate the maximum profit based on the two possible decisions (buy or sell).

#### Iterations:

| Day | `curr` (current profit) | `next` (next day's profit) |
|-----|-------------------------|---------------------------|
| 5   | [0, 3, 0, 3, 0]         | [0, 3, 0, 3, 0]           |
| 4   | [3, 3, 3, 3, 3]         | [3, 3, 3, 3, 3]           |
| 3   | [1, 3, 3, 3, 3]         | [3, 3, 3, 3, 3]           |
| 2   | [1, 3, 3, 3, 3]         | [3, 3, 3, 3, 3]           |
| 1   | [1, 3, 3, 3, 3]         | [3, 3, 3, 3, 3]           |
| 0   | [1, 3, 3, 3, 3]         | [3, 3, 3, 3, 3]           |

- **Day 5 (prices[5] = 3):**
  - Transaction 0 (Buy): Buy at 3 (profit = 0), or skip (profit = 0).
  - Transaction 1 (Sell): Sell at 3 (profit = 3), or skip (profit = 0).
  - Continue similarly for the rest of the transactions.

3. **Final Answer:**
   - The maximum profit is found at `next[0] = 3`.


### Source Code
```cpp
class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Number of days

        // `curr` and `next` arrays store the maximum profit for the current and next days
        // Each array has size `2*k+1`, representing all transaction states
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        // Iterate through days in reverse order (bottom-up DP)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate through all transaction states
            for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++) {
                int profit = 0;

                // Determine whether the current transaction is a "buy" or "sell"
                if (transactionNo % 2 == 0) { // Buy operation
                    // Option 1: Buy the stock on the current day and move to the next transaction
                    int buyStock = -prices[index] + next[transactionNo + 1];
                    // Option 2: Skip buying and move to the next day
                    int notBuyStock = 0 + next[transactionNo];
                    // Maximize profit between buying and skipping
                    profit = max(buyStock, notBuyStock);
                } else { // Sell operation
                    // Option 1: Sell the stock on the current day and move to the next transaction
                    int sellStock = +prices[index] + next[transactionNo + 1];
                    // Option 2: Skip selling and move to the next day
                    int notSellStock = 0 + next[transactionNo];
                    // Maximize profit between selling and skipping
                    profit = max(sellStock, notSellStock);
                }

                // Store the calculated profit in the current day's array
                curr[transactionNo] = profit;
            }

            // Move to the next day by updating `next` to `curr`
            next = curr;
        }

        // The maximum profit starting from day 0 with no transactions made yet
        return next[0];
    }

    // Main function to calculate the maximum profit with at most `k` transactions
    int maxProfit(int k, vector<int>& prices) {
        // Call the `solve` function to compute the maximum profit
        return solve(prices, k);
    }
};
```

### Source Code Explanation

Let’s break down the code and explain each line in detail.

```cpp
class Solution {
public:
    // Function to calculate the maximum profit using space-optimized dynamic programming
    // `prices`: vector of stock prices
    // `k`: maximum number of transactions allowed
    int solve(vector<int>& prices, int k) {
        int n = prices.size(); // Number of days
```
- `n` stores the total number of days (size of the `prices` vector).

```cpp
        // `curr` and `next` arrays store the maximum profit for the current and next days
        // Each array has size `2*k+1`, representing all transaction states
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);
```
- Two 1D arrays `curr` and `next` are created. These arrays store the maximum profit for each transaction state on the current day (`curr`) and the next day (`next`).
- Both arrays are initialized to zeros.

```cpp
        // Iterate through days in reverse order (bottom-up DP)
        for (int index = n - 1; index >= 0; index--) {
            // Iterate through all transaction states
            for (int transactionNo = 0; transactionNo < 2 * k; transactionNo++) {
                int profit = 0;
```
- We iterate backward from day `n-1` to `0`. For each day, we iterate through the transaction states (from `0` to `2*k-1`).

```cpp
                // Determine whether the current transaction is a "buy" or "sell"
                if (transactionNo % 2 == 0) { // Buy operation
                    // Option 1: Buy the stock on the current day and move to the next transaction
                    int buyStock = -prices[index] + next[transactionNo + 1];
                    // Option 2: Skip buying and move to the next day
                    int notBuyStock = 0 + next[transactionNo];
                    // Maximize profit between buying and skipping
                    profit = max(buyStock, notBuyStock);
                } else { // Sell operation
                    // Option 1: Sell the stock on the current day and move to the next transaction
                    int sellStock = +prices[index] + next[transactionNo + 1];
                    // Option 2: Skip selling and move to the next day
                    int notSellStock = 0 + next[transactionNo];
                    // Maximize profit between selling and skipping
                    profit = max(sellStock, notSellStock);
                }
```
- If the transaction is a **buy** (even transaction number), we calculate the maximum profit by either:
  1. Buying the stock today and moving to the next transaction (`buyStock`).
  2. Skipping the buy operation (`notBuyStock`).
- If the transaction is a **sell** (odd transaction number), we calculate the maximum profit by either:
  1. Selling the stock today and moving to the next transaction (`sellStock`).
  2. Skipping the sell operation (`notSellStock`).

```cpp
                // Store the calculated profit in the current day's array
                curr[transactionNo] = profit;
            }
```
- After calculating the profit for each transaction state, we store it in the `curr` array.

```cpp
            // Move to the next day by updating `next` to `curr`
            next = curr;
        }
```
- After completing calculations for the current day, we move the `curr` values to the `next` array. This allows us to update the profit for the next day.

```cpp
        // The maximum profit starting from day 0 with no transactions made yet
        return next[0];
    }
```
- The final maximum profit is stored in `next[0]` (since we are calculating starting from day `0` with no transactions made yet).

```cpp
    // Main function to calculate the maximum profit with at most `k` transactions
    int maxProfit(int k, vector<int>& prices) {
        // Call the `solve` function to compute the maximum profit
        return solve(prices, k);
    }
};
```
- The `maxProfit` function calls `solve` to compute the maximum profit and returns the result.

### Example Output:

For the input:
```cpp
k = 2
prices = [3, 2, 6, 5, 0, 3
````

- After filling in the `curr` and `next` arrays, the final answer is `3`, meaning the maximum profit achievable by performing at most 2 transactions is `3`.

### Time Complexity:

- The time complexity is **O(n * k)** because we iterate through `n` days, and for each day, we iterate through `2*k` transaction states.

### Space Complexity:

- The space complexity is **O(k)** because we are only using two 1D arrays of size `2*k+1`, which is much more space-efficient than the 2D DP table used in the previous solution.

This approach optimizes the space complexity while maintaining the correctness of the solution.
