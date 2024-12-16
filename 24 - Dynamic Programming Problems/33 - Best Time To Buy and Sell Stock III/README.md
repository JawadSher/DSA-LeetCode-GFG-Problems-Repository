<h1 align="center">Best - Time To - Buy and Sell - Stock III</h1>

## Problem Statement

**Problem URL :** [Best Time To Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/)

![image](https://github.com/user-attachments/assets/15fe5eec-546d-4c7f-97ea-b42c12051ba2)

### Problem Explanation
The **Best Time to Buy and Sell Stock III** problem on LeetCode (Problem #123) is a variation of the popular stock trading problem, where you are given a series of stock prices for several days, and you can buy and sell the stock multiple times. However, in this specific problem, you are restricted to making **at most two transactions**.

You are given an array `prices[]` where `prices[i]` represents the price of a stock on the `i`-th day. You can perform at most **two transactions** to maximize your profit. A transaction consists of **buying a stock** and then **selling it** later. The goal is to determine the **maximum profit** you can achieve after at most two transactions.

### Key Points:
1. **At most two transactions**:
   - You can perform **at most two buy-sell operations**. This means:
     - You can buy and sell once (one transaction).
     - You can buy and sell twice (two transactions).
   - You cannot perform a third buy-sell operation.
   
2. **Buy before you sell**:
   - For any buy and sell pair, you must **buy the stock first** and **sell it later**. This means you cannot sell before you buy.

3. **Maximizing profit**:
   - The goal is to maximize the **total profit** from performing these transactions, which means:
     - You want to buy at the lowest possible price and sell at the highest possible price.
     - You want to take advantage of fluctuations in the stock price.

4. **Transaction Restrictions**:
   - You can make **only two transactions** in total. If you choose not to make a transaction, you make zero profit for that period.

### Problem Clarification with Example:

Consider the following example:

```plaintext
prices = [3,2,6,5,0,3]
```

### Steps to Understanding the Problem:

#### Step 1: Interpret the Prices
The given array represents the stock prices on each day:

- Day 0: Price is 3
- Day 1: Price is 2
- Day 2: Price is 6
- Day 3: Price is 5
- Day 4: Price is 0
- Day 5: Price is 3

#### Step 2: Possible Transactions
You are allowed to perform **at most two transactions**. The key here is identifying **two buy-sell pairs** that maximize your total profit.

- **First transaction (Buy at 2, Sell at 6)**:
  - You buy the stock at price 2 on Day 1.
  - You sell it at price 6 on Day 2.
  - The profit from this transaction is `6 - 2 = 4`.

- **Second transaction (Buy at 0, Sell at 3)**:
  - You buy the stock at price 0 on Day 4.
  - You sell it at price 3 on Day 5.
  - The profit from this transaction is `3 - 0 = 3`.

#### Step 3: Maximum Profit
The total profit is the sum of the two transactions: `4 + 3 = 7`. This is the maximum profit you can get by performing at most two transactions.

#### Step 4: Restrictions
You cannot:
- Buy and sell the stock on the same day.
- Sell before buying.
- Perform more than two transactions.

In this example, performing just one transaction (say, buying at 2 and selling at 6) would yield a profit of 4, which is smaller than the total profit of 7 obtained by doing two transactions.

#### Step 5: Example 2
Consider a second example:

```plaintext
prices = [1,2,3,4,5]
```

Here, the stock prices are steadily increasing.

- **First transaction (Buy at 1, Sell at 5)**:
  - You buy the stock at price 1 on Day 0.
  - You sell it at price 5 on Day 4.
  - The profit from this transaction is `5 - 1 = 4`.

- Since the stock price is always increasing, there is no need for a second transaction.

The maximum profit you can achieve in this case is 4.

#### Step 6: Example 3 (No Profit Case)
Consider this example:

```plaintext
prices = [7,6,4,3,1]
```

In this case, the stock prices are always decreasing. This means no matter what, you can't make a profit, because any stock you buy will only decrease in value afterward.

- There are **no opportunities** to buy and sell to make a profit, so the maximum profit in this case is **0**.

### Key Insights:
1. **Multiple transactions** can be performed, but you are limited to **at most two**.
2. **Profit maximization** means buying low and selling high, but only twice.
3. **Edge cases**:
   - If prices are in decreasing order, no profit can be made.
   - If prices are in increasing order, the maximum profit can be made by buying at the lowest and selling at the highest.

### Conclusion:
The problem is essentially about maximizing profit from at most two stock transactions, given a series of stock prices over time. The key challenge is figuring out how to divide the problem into two sub-problems (i.e., two transactions) and calculating the maximum profit efficiently.

---

## Recursive Approach (caused TLE)
In this problem, you are tasked with maximizing your profit from **at most two transactions**: buying and then selling a stock, with the goal of getting the most profit. The recursive approach is designed to explore each day and decide whether it's optimal to buy, sell, or skip that particular day, while keeping track of how many transactions have been made.

The state of the recursive function is defined by:

- **index**: The current day we're considering.
- **buy**: Whether we are allowed to buy or sell on the current day.
  - **buy = 1**: We can buy the stock.
  - **buy = 0**: We can sell the stock.
- **limit**: The number of remaining transactions we can make. We can only make up to 2 transactions, so initially, `limit = 2`.

#### Base Case:
- The base case of the recursion happens when either:
  - We've considered all days (`index == n`), or
  - We've already completed all our allowed transactions (`limit == 0`).
In these cases, we return 0 because no further profit can be made.

#### Recursive Exploration:
1. **If `buy == 1`**: This means we are allowed to buy on the current day.
   - **Option 1**: We can buy the stock on the current day, which means we incur a loss of `prices[index]`. Then, we call the recursive function for the next day (`index + 1`) with `buy = 0` (indicating that we can sell on the next day) and the same `limit`.
   - **Option 2**: We skip the buying action for today and just move to the next day with `buy = 1` and the same `limit`.
   - We take the maximum of these two options.

2. **If `buy == 0`**: This means we are allowed to sell on the current day.
   - **Option 1**: We can sell the stock on the current day, which results in a profit of `prices[index]`. After selling, we decrement the `limit` by 1 (since a transaction is completed) and set `buy = 1` for the next day (indicating that we are now allowed to buy again).
   - **Option 2**: We skip selling for today and move to the next day with `buy = 0` and the same `limit`.
   - Again, we take the maximum of these two options.

Finally, the function returns the maximum profit achievable from either buying or selling on any of the days.

### Example Walkthrough

Consider the following example of prices:
```plaintext
prices = [3, 2, 6, 5, 0, 3]
```

We are allowed to make **at most 2 transactions**. Let's break down how the recursive function works:

1. **Start from index 0**, where `prices[0] = 3`. 
   - We are allowed to buy (since `buy == 1`).
   - Option 1: Buy at price 3, and we recursively compute the profit from the next day with `buy = 0` and `limit = 2`.
   - Option 2: Skip the buying step and go to the next day with the same parameters (`buy = 1` and `limit = 2`).

2. Let's consider Option 1 (buy at day 0):
   - **Now we are at index 1**, where `prices[1] = 2`.
     - We can sell the stock (since `buy == 0`).
     - Option 1: Sell at price 2. This would complete the first transaction, and we are left with one more transaction to make (`limit = 1`).
     - Option 2: Skip selling and move to the next day.

3. **Recursion continues for each day**:
   - The function evaluates every possible action (buy, sell, or skip) and computes the profit for each scenario.
   - It eventually determines the maximum possible profit from either performing the first transaction on earlier days or skipping some of them.

At the end of the recursion, the function returns the highest profit from all possible combinations of transactions.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate maximum profit
    int solve(vector<int>& prices, int index, int buy, int limit){
        int n = prices.size();
        
        // Base case: if we've processed all days (index == n) or no more transactions can be made (limit == 0)
        if(index == n || limit == 0) return 0;

        int profit = 0;
        
        // If we are allowed to buy (buy == 1)
        if(buy){
            // Option 1: Buy the stock today and recurse for the next day with the buy flag set to 0 (indicating we can sell next)
            // Option 2: Skip the current day and proceed to the next day with the buy flag still set to 1
            profit = max((-prices[index] + solve(prices, index+1, 0, limit)), 
                          (0 + solve(prices, index+1, 1, limit)));
        } else {
            // If we are allowed to sell (buy == 0)
            // Option 1: Sell the stock today, reduce the transaction limit by 1 and proceed to the next day with buy flag set to 1
            // Option 2: Skip the current day and proceed to the next day with buy flag still set to 0
            profit = max((+prices[index] + solve(prices, index+1, 1, limit-1)), 
                          (0 + solve(prices, index+1, 0, limit)));
        }

        return profit;
    }

    // Main function to return the maximum profit
    int maxProfit(vector<int>& prices) {
        // Starting from day 0, we can buy the stock, and we are allowed to make at most 2 transactions
        return solve(prices, 0, 1, 2);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Helper function to calculate maximum profit
    int solve(vector<int>& prices, int index, int buy, int limit){
        int n = prices.size();
        
        // Base case: if we've processed all days (index == n) or no more transactions can be made (limit == 0)
        if(index == n || limit == 0) return 0;
```
- This is the recursive helper function.
- The base case checks if we've either processed all days (`index == n`) or we've completed all allowed transactions (`limit == 0`).
- If either condition is true, return 0, as no further profit can be made.

```cpp
        int profit = 0;
        
        // If we are allowed to buy (buy == 1)
        if(buy){
```
- We initialize `profit` to 0. This variable stores the maximum profit at each step.
- If `buy == 1`, this means we can buy the stock on the current day.

```cpp
            // Option 1: Buy the stock today and recurse for the next day with the buy flag set to 0 (indicating we can sell next)
            // Option 2: Skip the current day and proceed to the next day with the buy flag still set to 1
            profit = max((-prices[index] + solve(prices, index+1, 0, limit)), 
                          (0 + solve(prices, index+1, 1, limit)));
```
- **Option 1**: Buy the stock at the current price `prices[index]`. The profit is `-prices[index]` (a negative number), and then we move to the next day with `buy = 0` (indicating we can sell the stock) and the same `limit`.
- **Option 2**: Skip buying on the current day and move to the next day, keeping `buy = 1` and the same `limit`.
- We select the option that gives the maximum profit using `max()`.

```cpp
        } else {
            // If we are allowed to sell (buy == 0)
            // Option 1: Sell the stock today, reduce the transaction limit by 1 and proceed to the next day with buy flag set to 1
            // Option 2: Skip the current day and proceed to the next day with buy flag still set to 0
            profit = max((+prices[index] + solve(prices, index+1, 1, limit-1)), 
                          (0 + solve(prices, index+1, 0, limit)));
        }
```
- If `buy == 0`, we are allowed to sell.
- **Option 1**: Sell the stock at `prices[index]`. The profit is `prices[index]`, and then we move to the next day with `buy = 1` (indicating we can buy again) and decrement `limit` by 1 because we completed a transaction.
- **Option 2**: Skip selling today and move to the next day with the same `buy = 0` and the same `limit`.

```cpp
        return profit;
    }

    // Main function to return the maximum profit
    int maxProfit(vector<int>& prices) {
        // Starting from day 0, we can buy the stock, and we are allowed to make at most 2 transactions
        return solve(prices, 0, 1, 2);
    }
};
```
- The `solve()` function is called recursively with the initial parameters: `index = 0` (starting from the first day), `buy = 1` (indicating we can buy), and `limit = 2` (allowing up to two transactions).

### Example Output

For the input:
```plaintext
prices = [3, 2, 6, 5, 0, 3]
```

- **First transaction**: Buy at 2 and sell at 6, making a profit of `6 - 2 = 4`.
- **Second transaction**: Buy at 0 and sell at 3, making a profit of `3 - 0 = 3`.

So, the total profit is `4 + 3 = 7`, and the function returns **7** as the maximum profit.

### Time Complexity

- The time complexity of the recursive approach is **O(2^n)** because, at each day, you make two recursive calls (one for buying and one for skipping or selling). This leads to an exponential growth in the number of subproblems.
  
### Space Complexity

- The space complexity is **O(n)** because we are using recursion with a maximum recursion depth of `n`. Each recursive call stores state information like the current index, whether we can buy or sell, and the remaining limit.

This can be improved using dynamic programming, where we store the intermediate results in a table to avoid recalculating the same subproblems.

---

## Top-Down Approach (DP)
The given solution is an implementation of a "top-down" dynamic programming approach with memoization to solve the problem of maximizing profit with at most two stock transactions. Here's a step-by-step breakdown of how this approach works:

#### **Understanding the Problem:**

The problem asks to maximize profit by performing at most two stock transactions, where a transaction is defined as buying and selling a stock. We can buy the stock on one day, and then sell it on a later day, but we are limited to only two transactions. The goal is to find the maximum profit that can be achieved under these constraints.

#### **Recursive Approach - Step-by-Step:**

The idea behind the solution is to recursively calculate the maximum profit we can obtain from a given day onwards with certain constraints:

1. **State Representation:**
   - `index`: the current day we are considering.
   - `buy`: a flag to indicate whether we can buy (1) or sell (0) on the current day.
   - `limit`: the number of remaining transactions we can make (maximum of 2).

2. **Base Case:**
   - If we've processed all days (i.e., `index == n`) or we can't perform any more transactions (i.e., `limit == 0`), we return `0` because no profit can be made.

3. **Memoization:**
   - Before making recursive calls, we check if we've already computed the result for the current state (`dp[index][buy][limit] != -1`). If yes, we return the precomputed value to avoid redundant calculations.

4. **Recursion:**
   - If `buy == 1`, it means we are allowed to buy:
     - **Option 1:** Buy the stock today (subtract its price from the profit) and recurse with `buy = 0` (since we cannot buy again after buying) and the same `limit`.
     - **Option 2:** Skip buying today and recurse with `buy = 1` (we can still buy) and the same `limit`.
   
   - If `buy == 0`, it means we are allowed to sell:
     - **Option 1:** Sell the stock today (add its price to the profit) and recurse with `buy = 1` (since we can buy again) and `limit - 1` (since we have used one transaction).
     - **Option 2:** Skip selling today and recurse with `buy = 0` (we can still sell) and the same `limit`.

5. **Memoize the result:** After calculating the profit for the current state, we store it in the DP table to avoid recalculating it in the future.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate maximum profit with memoization
    int solve(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        
        // Base case: If we have reached the end of the prices array (index == n) or no transactions left (limit == 0)
        if(index == n || limit == 0) return 0;

        // Check if the result for the current state has already been computed (memoized)
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int profit = 0;

        // If we are allowed to buy (buy == 1)
        if(buy){
            // Option 1: Buy the stock today, and move to the next day (after buying, we can't buy again)
            // Option 2: Skip buying and move to the next day, still with the option to buy
            profit = max((-prices[index] + solve(prices, index+1, 0, limit, dp)), 
                          (0 + solve(prices, index+1, 1, limit, dp)));
        } else {
            // If we are allowed to sell (buy == 0)
            // Option 1: Sell the stock today, reduce the transaction limit by 1 and move to the next day (after selling, we can buy again)
            // Option 2: Skip selling and move to the next day, still with the option to sell
            profit = max((+prices[index] + solve(prices, index+1, 1, limit-1, dp)), 
                          (0 + solve(prices, index+1, 0, limit, dp)));
        }

        // Store the computed result in dp to avoid redundant calculations in future recursive calls
        return dp[index][buy][limit] = profit;
    }

    // Main function to return the maximum profit
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // Create a 3D DP table initialized with -1, where:
        // dp[i][j][k] represents the maximum profit starting from index i, with a flag j (1 = can buy, 0 = can sell), 
        // and k remaining transactions.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

        // Start the recursive function with index = 0, buy = 1 (indicating we can buy), and limit = 2 (two transactions allowed)
        return solve(prices, 0, 1, 2, dp);
    }
};
```

### Source Code Explanation

```cpp
int solve(vector<int>& prices, int index, int buy, int limit, vector<vector<vector<int>>>& dp){
    int n = prices.size();
```
- `prices`: The vector of stock prices.
- `index`: The current day.
- `buy`: A flag that indicates whether we are allowed to buy (1) or sell (0).
- `limit`: The number of remaining transactions we can make.
- `dp`: The 3D DP table to store results for states we've already computed.
- `n`: The total number of days (or prices).

```cpp
    if(index == n || limit == 0) return 0;
```
- **Base case:** If we've reached the end of the prices array (`index == n`) or we can't make more transactions (`limit == 0`), we return `0`.

```cpp
    if(dp[index][buy][limit] != -1) return dp[index][buy][limit];
```
- **Memoization check:** If we've already computed the result for the current state (`dp[index][buy][limit]`), we return the stored result.

```cpp
    int profit = 0;
```
- Initialize `profit` to store the maximum profit we can get from the current state.

```cpp
    if(buy){
        profit = max((-prices[index] + solve(prices, index+1, 0, limit, dp)), 
                      (0 + solve(prices, index+1, 1, limit, dp)));
    } else {
        profit = max((+prices[index] + solve(prices, index+1, 1, limit-1, dp)), 
                      (0 + solve(prices, index+1, 0, limit, dp)));
    }
```
- **If `buy == 1`**: We are allowed to buy. We compute two options:
  - **Option 1:** Buy the stock today (`-prices[index]`), and then move to the next day with `buy = 0` (since we can't buy again).
  - **Option 2:** Skip buying today, and move to the next day with `buy = 1` (still allowed to buy).
  
- **If `buy == 0`**: We are allowed to sell. We compute two options:
  - **Option 1:** Sell the stock today (`+prices[index]`), and move to the next day with `buy = 1` (since we can buy again) and `limit - 1` (since one transaction has been used).
  - **Option 2:** Skip selling today, and move to the next day with `buy = 0` (still allowed to sell).

```cpp
    return dp[index][buy][limit] = profit;
}
```
- Store the computed `profit` in the DP table for the current state (`index`, `buy`, `limit`).

```cpp
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, 0, 1, 2, dp);
}
```
- **Initialization of DP Table:** We initialize a 3D DP table `dp` with dimensions `[n][2][3]`. The dimensions are:
  - `n`: The number of days (prices).
  - `2`: The `buy` flag (1 = buy, 0 = sell).
  - `3`: The transaction limit (0, 1, or 2 remaining transactions).
- **Recursive call:** We call the `solve()` function starting from day 0 with the option to buy (`buy = 1`) and a transaction limit of 2.

#### **Example Output Explanation:**

Let's consider the following example:

```cpp
vector<int> prices = {2, 4, 1, 7, 5, 3, 6, 4};
```
- **Max Profit:** The maximum profit with at most two transactions is calculated by evaluating all the possible states (buy/sell combinations) over the days. The recursive function calculates the maximum profit, considering all options and memoizing results to avoid redundant calculations.
  
- **First transaction:** Buy at day 0 (`price = 2`), sell at day 1 (`price = 4`) → profit = 4 - 2 = 2.
- **Second transaction:** Buy at day 3 (`price = 1`), sell at day 6 (`price = 6`) → profit = 6 - 1 = 5.
- Total profit = 2 + 5 = **7**.

#### **Time and Space Complexity Analysis:**

- **Time Complexity:**
  - The recursive function `solve()` is called for every combination of `index`, `buy`, and `limit`. There are `n` days, `2` buy/sell states, and `3` transaction limits.
  - Thus, the total number of states is `O(n * 2 * 3) = O(6n)`, which simplifies to `O(n)`.
  - Each state computation involves only a constant amount of work (a couple of comparisons and recursive calls).
  - **Overall time complexity** is `O(n)`.

- **Space Complexity:**
  - We use a 3D DP table of size `O(n * 2 * 3)` to store the results for different states.
  - **Overall space complexity** is `O(n)`.

This approach efficiently calculates the maximum profit by using memoization to avoid recalculating the same states multiple times, which optimizes the solution compared to a pure recursive approach.

---

## Bottom-Up Approach (DP)
The problem involves finding the maximum profit that can be made with at most **two transactions** in a given list of stock prices. In this approach, we will use dynamic programming (DP) to build a solution iteratively (from the bottom-up) rather than recursively.

### **Step-by-Step Explanation of the Bottom-Up Approach**:

1. **Understanding the Problem**:
   - We are given an array `prices[]` where `prices[i]` represents the price of a stock on day `i`.
   - The goal is to maximize the profit from **at most 2 transactions** (i.e., buy and sell operations).

2. **Dynamic Programming (DP) Table**:
   - We need to construct a DP table to keep track of the maximum profit we can achieve for different days (`index`), whether we are allowed to **buy** or **sell**, and how many transactions are left.
   - The DP table will have the following dimensions:
     - **`index`**: The day (starting from 0 to `n-1`).
     - **`buy/sell` flag**: Whether we can buy (`buy = 1`) or sell (`buy = 0`).
     - **`limit`**: The number of remaining transactions (can be `1` or `2`).

3. **DP Table Setup**:
   - **State Representation**: We represent each state by `dp[index][buy][limit]`:
     - `index`: The current day (or index in the `prices[]` array).
     - `buy`: Whether we can buy (`1`) or sell (`0`).
     - `limit`: The number of transactions remaining (either `1` or `2`).
   - **Base Case**: 
     - When we are beyond the last day (`index = n`), we cannot make any further profit, so all values in the DP table for that index will be `0`.
     - **Initialization**: `dp[n][buy][limit] = 0` for all `buy` and `limit`.

4. **Filling the DP Table**:
   - We will start iterating backward from the last day (`n-1`) and move towards the first day (`0`).
   - For each day, we check whether we can **buy** or **sell** based on the current `buy/sell` flag and the remaining transaction limit.
   - For each state (`buy = 1` or `buy = 0` and `limit = 1 or 2`), we calculate the possible profit and update the DP table.

5. **Transition Logic**:
   - **If `buy = 1` (can buy)**:
     - **Option 1**: Buy the stock today, move to the next day (`index + 1`), and keep the same transaction limit.
     - **Option 2**: Skip buying today and move to the next day, keeping the same `buy = 1` state.
   - **If `buy = 0` (can sell)**:
     - **Option 1**: Sell the stock today, reduce the transaction limit by 1, and move to the next day (`index + 1`).
     - **Option 2**: Skip selling today and move to the next day, keeping the same `buy = 0` state.

6. **Final Result**:
   - After filling the DP table, the final result (maximum profit) will be found at `dp[0][1][2]`, representing the maximum profit starting from day 0, with the ability to buy, and 2 transactions remaining.

### **Example**:
Let's consider the following prices for 6 days:

`prices = [1, 2, 4, 2, 5, 7]`

The goal is to maximize profit with **at most 2 transactions**.

**Step-by-Step Solution**:
1. **Initialization**: Set up a 3D DP table `dp[n+1][2][3]` where `n = 6` (length of `prices`).
   - Base case: `dp[6][buy][limit] = 0` for all `buy` and `limit`.

2. **Filling the DP Table**:
   - Start from the last day (`index = 5`) and move towards `index = 0`.
   - For each day, calculate the profit for buying or selling at each state (`buy` and `limit`).

3. **Final Result**:
   - After filling the table, the maximum profit at `dp[0][1][2]` will be the result.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate maximum profit using dynamic programming (bottom-up approach)
    int solve(vector<int>& prices){
        int n = prices.size();

        // Create a 3D DP table to store the maximum profit at each index, with the options to buy or sell, and the remaining transaction limit.
        // dp[i][j][k] represents the maximum profit starting from index i, with buy/sell option j (1 = can buy, 0 = can sell), and k remaining transactions.
        // We use n+1 for index to account for the boundary condition where we reach the end of the prices array.
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Start iterating from the last day (index = n-1) towards the first day (index = 0)
        for(int index = n-1; index >= 0; index--){
            // For each index, we check whether we can buy (buy == 1) or sell (buy == 0) and the remaining transaction limit
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){
                    int profit = 0;

                    // If we can buy (buy == 1)
                    if(buy){
                        // Option 1: Buy the stock today, and move to the next day with the ability to sell and the same remaining transaction limit
                        int buyStock = -prices[index] + dp[index+1][0][limit];
                        // Option 2: Skip buying and move to the next day, still with the ability to buy and the same remaining transaction limit
                        int notBuyStock = 0 + dp[index+1][1][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(buyStock, notBuyStock);
                    }else{
                        // If we can sell (buy == 0)
                        // Option 1: Sell the stock today, reduce the transaction limit by 1, and move to the next day with the ability to buy
                        int sellStock = +prices[index] + dp[index+1][1][limit-1];
                        // Option 2: Skip selling and move to the next day, still with the ability to sell and the same remaining transaction limit
                        int notSellStock = 0 + dp[index+1][0][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(sellStock, notSellStock);
                    }

                    // Store the computed result in the dp table for the current index, buy/sell option, and remaining transaction limit
                    dp[index][buy][limit] = profit;
                }
            }
        }

        // The final result is stored at dp[0][1][2], representing the maximum profit starting from day 0, with the ability to buy, and 2 transactions allowed
        return dp[0][1][2];
    }

    // Main function to return the maximum profit from the given prices array
    int maxProfit(vector<int>& prices) {
        // Call the solve function and return the result
        return solve(prices);
    }
};
```

### Source Code Explanation

#### **1. Class Definition**

```cpp
class Solution {
```

- This line defines a class `Solution` in which the methods will be written. This is common practice in competitive programming to encapsulate the solution into a class.



#### **2. Function Definition (solve)**

```cpp
int solve(vector<int>& prices){
```

- `solve`: This is a helper function that takes a reference to the `prices` vector (which contains the prices of stocks on different days) and computes the maximum profit using dynamic programming (bottom-up approach).

- `prices`: A vector that holds the prices of the stock for each day.



#### **3. Initialize Variables**

```cpp
int n = prices.size();
```

- `n`: The variable `n` stores the number of days (or the length of the `prices` array).
  - For example, if `prices = [1, 2, 4, 2, 5, 7]`, then `n = 6`.



#### **4. DP Table Initialization**

```cpp
vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
```

- `dp`: A 3D dynamic programming table that stores the maximum profit at each day, given the current state of whether we are allowed to buy or sell (`buy`), and how many transactions are remaining (`limit`).
  
- **Dimensions of `dp`**:
  - `n+1`: Represents the days (0 to `n`), where `n` is the number of days.
  - `2`: Represents whether we are in a "buy" or "sell" state (`buy = 1` or `buy = 0`).
  - `3`: Represents the transaction limit, where we can have at most 2 transactions (`limit = 1 or 2`).

- **Initialization**: We initialize all entries of the DP table to `0`.



#### **5. Start Iterating in Reverse Order (from Last Day to First Day)**

```cpp
for(int index = n-1; index >= 0; index--){
```

- We start from the last day (`index = n-1`) and move towards the first day (`index = 0`).
  
- This reverse iteration ensures that we are always computing the maximum profit assuming we have already made decisions for later days.



#### **6. Iterate Over "Buy" and "Sell" States**

```cpp
for(int buy = 0; buy <= 1; buy++){
```

- The `buy` variable represents whether we can buy (if `buy = 1`) or whether we can sell (if `buy = 0`).
- If `buy = 1`, it means we are allowed to buy a stock on the current day. If `buy = 0`, we are allowed to sell the stock.



#### **7. Iterate Over Transaction Limits**

```cpp
for(int limit = 1; limit <= 2; limit++){
```

- `limit` represents the number of transactions remaining. We can perform at most two transactions, so `limit` can be `1` or `2`.



#### **8. Initialize Profit for Each State**

```cpp
int profit = 0;
```

- Initialize `profit` to store the maximum profit for each state, based on whether we are in a buy or sell state.



#### **9. If We Can Buy (buy == 1)**

```cpp
if(buy){
    int buyStock = -prices[index] + dp[index+1][0][limit];
    int notBuyStock = 0 + dp[index+1][1][limit];
    profit = max(buyStock, notBuyStock);
}
```

- **If `buy == 1`**, meaning we are allowed to buy the stock on the current day:
  
  - **Option 1**: Buy the stock today, which costs `prices[index]`. We move to the next day (`index + 1`), and we still have the same number of remaining transactions (`limit`), but we are now in a "sell" state (`dp[index+1][0][limit]`).
  
    - `buyStock = -prices[index] + dp[index+1][0][limit]`
  
  - **Option 2**: Skip buying today, move to the next day, and keep the same state, i.e., stay in a "buy" state and keep the same transaction limit (`dp[index+1][1][limit]`).
  
    - `notBuyStock = 0 + dp[index+1][1][limit]`
  
  - **Choose the maximum profit** between buying today or not buying:
  
    - `profit = max(buyStock, notBuyStock)`



#### **10. If We Can Sell (buy == 0)**

```cpp
else{
    int sellStock = +prices[index] + dp[index+1][1][limit-1];
    int notSellStock = 0 + dp[index+1][0][limit];
    profit = max(sellStock, notSellStock);
}
```

- **If `buy == 0`**, meaning we are allowed to sell the stock on the current day:
  
  - **Option 1**: Sell the stock today, gaining `prices[index]`. We move to the next day (`index + 1`), reduce the remaining transaction limit by 1 (`limit-1`), and switch to a "buy" state (`dp[index+1][1][limit-1]`).
  
    - `sellStock = +prices[index] + dp[index+1][1][limit-1]`
  
  - **Option 2**: Skip selling today, move to the next day, and keep the same state (`dp[index+1][0][limit]`).
  
    - `notSellStock = 0 + dp[index+1][0][limit]`
  
  - **Choose the maximum profit** between selling today or not selling:
  
    - `profit = max(sellStock, notSellStock)`



#### **11. Store Computed Profit**

```cpp
dp[index][buy][limit] = profit;
```

- Store the calculated `profit` in the DP table for the current state (`index`, `buy`, `limit`).



#### **12. Return the Maximum Profit**

```cpp
return dp[0][1][2];
```

- After completing the iteration, the maximum profit starting from day 0, with 2 transactions allowed and the ability to buy, is stored at `dp[0][1][2]`.


### **Example Walkthrough**:

Let's take an example to walk through the entire code execution:

Given: `prices = [1, 2, 4, 2, 5, 7]`

- **Initialization**: `n = 6`, and we initialize the `dp` table of dimensions `7 x 2 x 3` with all entries set to `0`.

- **Filling the DP Table**:
  - Starting from `index = 5`, and filling the table backward:
  - For each state (`buy = 0 or 1`, `limit = 1 or 2`), we compute the maximum profit for either buying or selling, or skipping the transaction.

- **Final Output**: After filling the table, `dp[0][1][2]` will give the maximum profit, which in this case is **6** (buy at price 1 and sell at price 7).


### **Time and Space Complexity Analysis**:

#### **Time Complexity**:

- We are iterating over each day (`n` days).
- For each day, we iterate over `2` possible states (`buy = 0 or 1`).
- For each state, we iterate over `2` possible limits (`limit = 1 or 2`).
  
Thus, the time complexity is **O(n * 2 * 2) = O(4n) = O(n)**.

#### **Space Complexity**:

- We are using a 3D DP table of size `(n+1) x 2 x 3`, so the space complexity is **O(n)**.

---

## Space Optimization Approach (DP)
This problem asks us to maximize the profit from at most two stock transactions, where a transaction consists of buying and then selling a stock. We need to figure out the optimal strategy to make the most profit over the given stock prices array.

A direct dynamic programming (DP) approach would involve creating a 2D table where each entry tracks the maximum profit achievable up to a certain day, given specific transaction limits and whether you're in a buy or sell state. However, this approach can consume significant space, so we use **space optimization** to reduce the space complexity while maintaining the same time complexity.

### Approach Overview

We use **dynamic programming** (DP) to break down the problem into smaller subproblems and use their solutions to build up to the final answer. In the **space-optimized version**, instead of maintaining the entire DP table for every day, we only store information for the current and the next day, reducing the space complexity to **O(1)**.

### Steps of the Space-Optimized Approach:

#### 1. **Define State Variables**:
We define the following states:
- `buy`: Whether we are in the process of buying the stock (1) or selling the stock (0).
- `limit`: The number of remaining transactions allowed (1 or 2).

#### 2. **State Transitions**:
For each day, we calculate the maximum profit we can get by either buying, selling, or doing nothing. For each state, we have two options:
- **Buying**: If we're in a buy state (`buy == 1`), we can either:
  - Buy the stock today and transition to the next day with the ability to sell, keeping the remaining transaction limit the same.
  - Skip buying and transition to the next day, keeping the buy state and the remaining transaction limit the same.
- **Selling**: If we're in a sell state (`buy == 0`), we can either:
  - Sell the stock today and reduce the transaction limit by 1, moving to the next day with the ability to buy again.
  - Skip selling and transition to the next day, keeping the sell state and the same transaction limit.

#### 3. **Space Optimization**:
- Instead of maintaining a full 2D DP table for each day, we only maintain two 2D arrays:
  - `curr`: Stores the maximum profit for the current day’s state.
  - `next`: Stores the maximum profit for the next day’s state.
  
At each iteration (for each day), we compute the maximum profit for each state and update `curr` accordingly. Once we've processed a day, we transfer the results from `curr` to `next` for use in the next iteration.

#### 4. **Final Answer**:
After processing all the days, the final result will be stored in `curr[1][2]`, which represents the maximum profit achievable with 2 transactions allowed and starting in the buy state on day 0.

### Example Walkthrough

Let’s use the following stock prices as an example:

```
prices = [3, 2, 6, 5, 0, 3]
```

#### Step 1: Initialization
We initialize two 2D arrays `curr` and `next`, each of size 2x3 (2 for buy/sell states and 3 for the number of transactions remaining).

```
curr = next = [[0, 0, 0], [0, 0, 0]]
```

#### Step 2: Iteration (from last day to first day)

Now, we iterate backward from the last day (index 5) to the first day (index 0), calculating the profit for each state (`buy` = 0 or 1) and each transaction limit (1 or 2).

#### Day 5 (`price = 3`):
- **Buy State (`buy = 1`)**:
    - Option 1: Buy the stock today → `-3 + next[0][2] = -3 + 0 = -3`
    - Option 2: Don’t buy → `0 + next[1][2] = 0 + 0 = 0`
    - Max profit: `max(-3, 0) = 0`
    
    `curr[1][2] = 0`
    
- **Sell State (`buy = 0`)**:
    - Option 1: Sell the stock today → `+3 + next[1][1] = 3 + 0 = 3`
    - Option 2: Don’t sell → `0 + next[0][2] = 0 + 0 = 0`
    - Max profit: `max(3, 0) = 3`
    
    `curr[0][2] = 3`

After processing day 5:
```
curr = [[0, 0, 3], [0, 0, 0]]
```

#### Day 4 (`price = 0`):
- **Buy State (`buy = 1`)**:
    - Option 1: Buy the stock today → `-0 + next[0][2] = 0 + 3 = 3`
    - Option 2: Don’t buy → `0 + next[1][2] = 0 + 0 = 0`
    - Max profit: `max(3, 0) = 3`
    
    `curr[1][2] = 3`
    
- **Sell State (`buy = 0`)**:
    - Option 1: Sell the stock today → `+0 + next[1][1] = 0 + 0 = 0`
    - Option 2: Don’t sell → `0 + next[0][2] = 0 + 3 = 3`
    - Max profit: `max(0, 3) = 3`
    
    `curr[0][2] = 3`

After processing day 4:
```
curr = [[0, 0, 3], [0, 0, 3]]
```

#### Day 3 (`price = 5`):
- **Buy State (`buy = 1`)**:
    - Option 1: Buy the stock today → `-5 + next[0][2] = -5 + 3 = -2`
    - Option 2: Don’t buy → `0 + next[1][2] = 0 + 3 = 3`
    - Max profit: `max(-2, 3) = 3`
    
    `curr[1][2] = 3`
    
- **Sell State (`buy = 0`)**:
    - Option 1: Sell the stock today → `+5 + next[1][1] = 5 + 0 = 5`
    - Option 2: Don’t sell → `0 + next[0][2] = 0 + 3 = 3`
    - Max profit: `max(5, 3) = 5`
    
    `curr[0][2] = 5`

After processing day 3:
```
curr = [[0, 0, 5], [0, 0, 3]]
```

#### Day 2 (`price = 6`):
- **Buy State (`buy = 1`)**:
    - Option 1: Buy the stock today → `-6 + next[0][2] = -6 + 5 = -1`
    - Option 2: Don’t buy → `0 + next[1][2] = 0 + 3 = 3`
    - Max profit: `max(-1, 3) = 3`
    
    `curr[1][2] = 3`
    
- **Sell State (`buy = 0`)**:
    - Option 1: Sell the stock today → `+6 + next[1][1] = 6 + 0 = 6`
    - Option 2: Don’t sell → `0 + next[0][2] = 0 + 5 = 5`
    - Max profit: `max(6, 5) = 6`
    
    `curr[0][2] = 6`

After processing day 2:
```
curr = [[0, 0, 6], [0, 0, 3]]
```

#### Day 1 (`price = 2`):
- **Buy State (`buy = 1`)**:
    - Option 1: Buy the stock today → `-2 + next[0][2] = -2 + 6 = 4`
    - Option 2: Don’t buy → `0 + next[1][2] = 0 + 3 = 3`
    - Max profit: `max(4, 3) = 4`
    
    `curr[1][2] = 4`
    
- **Sell State (`buy = 0`)**:
    - Option 1: Sell the stock today → `+2 + next[1][1] = 2 + 0 = 2`
    - Option 2: Don’t sell → `0 + next[0][2] = 0 + 6 = 6`
    - Max profit: `max(2, 6) = 6`
    
    `curr[0][2] = 6`

After processing day 1:
```
curr = [[0, 0, 6], [0, 0, 4]]
```

#### Day 0 (`price = 3`):
- **Buy State (`buy = 1`)**:
    - Option 1: Buy the stock today → `-3 + next[0][2] = -3 + 6 = 3`
    - Option 2: Don’t buy → `0 + next[1][2] = 0 + 4 = 4`
    - Max profit: `max(3, 4) = 4`
    
    `curr[1][2] = 4`
    
- **Sell State (`buy = 0`)**:
    - Option 1: Sell the stock today → `+3 + next[1][1] = 3 + 0 = 3`
    - Option 2: Don’t sell

 → `0 + next[0][2] = 0 + 6 = 6`
    - Max profit: `max(3, 6) = 6`
    
    `curr[0][2] = 6`

After processing day 0:
```
curr = [[0, 0, 6], [0, 0, 4]]
```

### Final Result:
The maximum profit achievable with at most 2 transactions is stored in `curr[0][2] = 6`.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit using dynamic programming with space optimization
    int solve(vector<int>& prices){
        int n = prices.size();

        // Initialize two 2D vectors: 'curr' to store the current results and 'next' for the next day's results
        // 'curr' and 'next' are of size 2 (buy/sell) and 3 (transaction limits 1 and 2).
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));

        // Start iterating from the last day (index = n-1) to the first day (index = 0)
        for(int index = n-1; index >= 0; index--){
            // For each index, check if we can buy (buy == 1) or sell (buy == 0), and the remaining transaction limit
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){
                    int profit = 0;

                    // If we can buy (buy == 1)
                    if(buy){
                        // Option 1: Buy the stock today, and move to the next day with the ability to sell and the same remaining transaction limit
                        int buyStock = -prices[index] + next[0][limit];
                        // Option 2: Skip buying and move to the next day, still with the ability to buy and the same remaining transaction limit
                        int notBuyStock = 0 + next[1][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(buyStock, notBuyStock);
                    }else{
                        // If we can sell (buy == 0)
                        // Option 1: Sell the stock today, reduce the transaction limit by 1, and move to the next day with the ability to buy
                        int sellStock = +prices[index] + next[1][limit-1];
                        // Option 2: Skip selling and move to the next day, still with the ability to sell and the same remaining transaction limit
                        int notSellStock = 0 + next[0][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(sellStock, notSellStock);
                    }

                    // Store the computed result for the current index, buy/sell option, and transaction limit in the 'curr' vector
                    curr[buy][limit] = profit;
                }
            }

            // After processing the current index, move the results of 'curr' to 'next' for the next iteration
            next = curr;
        }

        // The final result is stored at curr[1][2], representing the maximum profit starting from day 0,
        // with the ability to buy and 2 transactions allowed.
        return curr[1][2];
    }

    // Main function to return the maximum profit from the given prices array
    int maxProfit(vector<int>& prices) {
        // Call the solve function and return the result
        return solve(prices);
    }
};
```

### Source Code Explanation
```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit using dynamic programming with space optimization
    int solve(vector<int>& prices){
        int n = prices.size();
```
- **Purpose**: The function `solve` is a helper that computes the maximum profit given the prices of stocks over `n` days. It accepts a vector `prices` that holds the stock prices on each day.
- `n = prices.size()` gets the number of days, which is the size of the `prices` vector.

```cpp
        // Initialize two 2D vectors: 'curr' to store the current results and 'next' for the next day's results
        // 'curr' and 'next' are of size 2 (buy/sell) and 3 (transaction limits 1 and 2).
        vector<vector<int>> curr(2, vector<int>(3, 0));
        vector<vector<int>> next(2, vector<int>(3, 0));
```
- **Purpose**: Two 2D vectors, `curr` and `next`, are initialized to store profits during dynamic programming transitions.
    - `curr` will store the current day's state.
    - `next` will store the next day's state.
- Each vector has 2 rows (representing whether we buy or sell, i.e., 0 = sell, 1 = buy) and 3 columns (representing the allowed transaction limits, i.e., 0, 1, or 2 transactions remaining).
- Both vectors are initialized to 0 (no profit initially).

```cpp
        // Start iterating from the last day (index = n-1) to the first day (index = 0)
        for(int index = n-1; index >= 0; index--){
```
- **Purpose**: We are processing the `prices` vector from the last day (index `n-1`) to the first day (index 0).
- This reverse iteration helps calculate the future profit first, which we then use to decide today's action.

```cpp
            // For each index, check if we can buy (buy == 1) or sell (buy == 0), and the remaining transaction limit
            for(int buy = 0; buy <= 1; buy++){
                for(int limit = 1; limit <= 2; limit++){
```
- **Purpose**: Two nested loops iterate over all possibilities:
    - `buy` determines whether we're in a "buy" (1) or "sell" (0) state.
    - `limit` represents the remaining transactions allowed (1 or 2).

```cpp
                    int profit = 0;
```
- **Purpose**: The `profit` variable is initialized to 0 at the start of each state (buy/sell, limit) for the current day.

```cpp
                    // If we can buy (buy == 1)
                    if(buy){
                        // Option 1: Buy the stock today, and move to the next day with the ability to sell and the same remaining transaction limit
                        int buyStock = -prices[index] + next[0][limit];
                        // Option 2: Skip buying and move to the next day, still with the ability to buy and the same remaining transaction limit
                        int notBuyStock = 0 + next[1][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(buyStock, notBuyStock);
                    }else{
                        // If we can sell (buy == 0)
                        // Option 1: Sell the stock today, reduce the transaction limit by 1, and move to the next day with the ability to buy
                        int sellStock = +prices[index] + next[1][limit-1];
                        // Option 2: Skip selling and move to the next day, still with the ability to sell and the same remaining transaction limit
                        int notSellStock = 0 + next[0][limit];
                        // Choose the option that gives the maximum profit
                        profit = max(sellStock, notSellStock);
                    }
```
- **Purpose**: This section handles the two possible actions at each step:
    - **If we are in a "buy" state (`buy == 1`)**:
        - Option 1: Buy the stock today. The profit from buying is `-prices[index]` (since buying reduces our balance), plus the maximum profit from the next day (`next[0][limit]`), where `next[0]` refers to the next day’s state if we sell.
        - Option 2: Skip buying today and just inherit the profit from the next day (`next[1][limit]`), where `next[1]` refers to the next day’s state if we were in a "buy" state.
        - We take the maximum of both options to maximize the profit.
    - **If we are in a "sell" state (`buy == 0`)**:
        - Option 1: Sell the stock today. The profit is `prices[index]` (since selling increases our balance), plus the maximum profit from the next day with one less transaction allowed (`next[1][limit-1]`).
        - Option 2: Skip selling today and inherit the profit from the next day (`next[0][limit]`).
        - We take the maximum of both options to maximize the profit.

```cpp
                    // Store the computed result for the current index, buy/sell option, and transaction limit in the 'curr' vector
                    curr[buy][limit] = profit;
```
- **Purpose**: After calculating the profit for a particular state (buy/sell, limit), we store the result in the `curr` vector.

```cpp
            // After processing the current index, move the results of 'curr' to 'next' for the next iteration
            next = curr;
        }
```
- **Purpose**: Once we've processed all states for the current day (index), we update `next` to be equal to `curr`, so that `curr` will hold the computed results for the current day when the next day is processed.
- This step effectively "shifts" the computed results to the "next" day for the following iteration.

```cpp
        // The final result is stored at curr[1][2], representing the maximum profit starting from day 0,
        // with the ability to buy and 2 transactions allowed.
        return curr[1][2];
    }
```
- **Purpose**: After all iterations, `curr[1][2]` holds the maximum profit that can be obtained with 2 transactions, starting with the ability to buy.
    - `curr[1]`: The state where buying is allowed.
    - `curr[2]`: The state with 2 transactions left.

```cpp
    // Main function to return the maximum profit from the given prices array
    int maxProfit(vector<int>& prices) {
        // Call the solve function and return the result
        return solve(prices);
    }
};
```
- **Purpose**: The `maxProfit` function simply calls the `solve` function with the given `prices` array and returns the computed result.
  
### Space Optimization

In this solution, we use **space optimization** by only keeping track of two states:
1. `curr`: The current day's results.
2. `next`: The next day's results.

- This significantly reduces the space complexity from `O(n * 2 * 3)` (if we stored the entire DP table) to `O(2 * 3)`, which is constant space.

Thus, instead of maintaining the entire DP table for all days, we only store the results for the current and next days, which allows us to optimize both time and space complexity.

### Example

Consider a price array: `[3,2,6,5,0,3]`.

- At day 5 (price 3), we will choose to sell if we have the chance to maximize profit.
- The process moves backward, calculating the best decision for each day.
- Finally, we arrive at the maximum profit possible with two transactions by day 0, which is stored in `curr[1][2]`.

### Time Complexity
- **Time Complexity**: `O(n)`, where `n` is the number of days. We iterate through each day once, and for each day, we iterate over 2 states (`buy/sell`) and 2 transaction limits (`1` or `2`).
- **Space Complexity**: `O(1)`, as we are using only two 2D vectors of size 2 x 3, which is constant space.

This is an optimized solution with regard to both time and space compared to a full dynamic programming approach that would require larger memory usage.
