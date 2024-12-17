<h1 align="center">Best - Time to - Buy and Sell - Stock with - Transaction Fee</h1>

## Problem Statement

**Problem URL :** [Best Time To Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/)

![image](https://github.com/user-attachments/assets/731bddb3-9429-45bf-80c6-e7d9163d3104)

### Problem Explanation
You are given an array `prices[]` where `prices[i]` represents the price of a stock on the `i-th` day. You are also given a transaction fee `fee`. You need to maximize your profit by choosing a single day to **buy** one stock and a different day in the future to **sell** that stock.

**However, there's a transaction fee that you need to pay each time you sell the stock**, which will reduce your profit.

The goal is to return the **maximum profit** you can achieve by performing as many transactions as you want. You can **buy and sell multiple ***, but you must pay the transaction fee on each sale. The important condition is that you **must sell the stock before buying it again**.

### Key Points:
1. You can buy the stock on one day, then sell it later.
2. You can do multiple transactions, but each sell incurs a transaction fee.
3. You are only allowed to buy or sell once per transaction, and you can’t sell without buying first.
4. The transaction fee is deducted from the profit every time you sell.

### Example 1:

**Input:**
```
prices = [1, 3, 2, 8, 4, 9], fee = 2
```

**Explanation:**
- On Day 0, the stock price is `1`.
- On Day 1, the stock price is `3`. If you sell at `3`, you will incur a fee of `2`, so the profit from this transaction would be `3 - 1 - 2 = 0`.
- On Day 2, the stock price is `2`. If you sell at `2`, after paying the fee, you will lose money (since the price is less than the previous day).
- On Day 3, the stock price is `8`. If you sell at `8`, after paying the fee, you will get `8 - 2 = 6` profit. 

You should aim to make these transactions in a way that maximizes the profit over multiple buys and sells.

**Output:** `8`  
Explanation: You can buy on Day 0 for `1`, sell on Day 3 for `8` (after the fee), buy again on Day 4 for `4`, and sell on Day 5 for `9` (after the fee). This results in a total profit of `8`.

### Example 2:

**Input:**
```
prices = [1, 2, 3, 4, 5], fee = 1
```

**Explanation:**
- On Day 0, the stock price is `1`.
- On Day 1, the stock price is `2`. If you sell at `2`, you will incur a fee of `1`, so the profit from this transaction would be `2 - 1 - 1 = 0`.
- On Day 2, the stock price is `3`. If you sell at `3`, you will get `3 - 1 - 1 = 1` profit.
- On Day 3, the stock price is `4`. If you sell at `4`, you will get `4 - 1 - 1 = 2` profit.
- On Day 4, the stock price is `5`. If you sell at `5`, you will get `5 - 1 - 1 = 3` profit.

The optimal strategy is to buy on Day 0 and sell on Day 4.

**Output:** `4`  
Explanation: You can buy on Day 0 for `1`, and sell on Day 4 for `5` (after the fee). This results in a total profit of `4`.

### Example 3:

**Input:**
```
prices = [5, 2, 4, 6, 7, 3], fee = 1
```

**Explanation:**
- On Day 0, the stock price is `5`.
- On Day 1, the stock price is `2`. The price decreases, so it’s not a good time to sell.
- On Day 2, the stock price is `4`. If you sell at `4`, you will get `4 - 2 - 1 = 1` profit.
- On Day 3, the stock price is `6`. If you sell at `6`, you will get `6 - 2 - 1 = 3` profit.
- On Day 4, the stock price is `7`. If you sell at `7`, you will get `7 - 2 - 1 = 4` profit.

The optimal strategy is to buy at Day 1 and sell at Day 4.

**Output:** `5`  
Explanation: You buy at Day 1 for `2` and sell at Day 4 for `7` (after the fee). This results in a total profit of `5`.

### Example 4:

**Input:**
```
prices = [10, 20, 30, 40, 50], fee = 5
```

**Explanation:**
- On Day 0, the stock price is `10`.
- On Day 1, the stock price is `20`. If you sell at `20`, you will get `20 - 10 - 5 = 5` profit.
- On Day 2, the stock price is `30`. If you sell at `30`, you will get `30 - 10 - 5 = 15` profit.
- On Day 3, the stock price is `40`. If you sell at `40`, you will get `40 - 10 - 5 = 25` profit.
- On Day 4, the stock price is `50`. If you sell at `50`, you will get `50 - 10 - 5 = 35` profit.

**Output:** `40`  
Explanation: The best strategy is to buy on Day 0 for `10` and sell on Day 4 for `50`, which gives a total profit of `40`.

### Conclusion:
The problem involves buying and selling a stock while considering the transaction fee applied every time a stock is sold. The goal is to maximize the total profit by making decisions about when to buy and sell over a series of days. The key challenge is to carefully manage the fee and make sure to buy before selling.

---

## Recursive Approach (caused TLE)
The problem requires calculating the maximum profit that can be made from buying and selling stocks multiple *, while taking into account a transaction fee that is deducted whenever you sell a stock. 

The recursive approach breaks down the problem by considering each day as a decision point and making a choice of either buying, selling, or doing nothing. 

**Key Points:**
- You can either **buy** or **sell** a stock, and each action has consequences on the potential future profit.
- The recursion explores all possibilities by making decisions for every day, considering two main actions: buy or sell.
- We use `index` to represent the current day and `buy` to represent whether we're in the buying state (1) or selling state (0).

### Recursive Function Explanation:

#### Base Case:
- The recursion terminates when we reach the last day (`index == n`), at which point no further transactions can be made, so the profit is 0.

#### Recursive Choices:

1. **Buy State (buy == 1):**
   - **Option 1: Buy the stock on this day** (`-prices[index]`), and then after buying, we move to the next day where we will **sell** the stock (transition to buy = 0).
   - **Option 2: Skip buying the stock** and continue to the next day without making any changes (stay in buy state, transition to buy = 1).

2. **Sell State (buy == 0):**
   - **Option 1: Sell the stock** (`prices[index] - fee`), and then after selling, we move to the next day where we can **buy** again (transition to buy = 1).
   - **Option 2: Skip selling** and continue to the next day without making any changes (stay in sell state, transition to buy = 0).

The maximum of these options gives the best possible profit for the current state.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit
    int solve(vector<int>& prices, int index, int buy, int fee) {
        int n = prices.size(); // Get the size of the prices array

        // Base case: If we've reached the end of the array, no more transactions can be made
        if(index == n) return 0;

        int profit = 0;

        // If we are in a buying state (buy == 1), we can either:
        // 1. Buy the stock at current price (this is represented by -prices[index])
        //    and move to the next index (index+1) in a "sell" state (buy = 0).
        // 2. Skip this index (do nothing) and stay in the "buy" state (buy = 1).
        if(buy) {
            profit = max((-prices[index] + solve(prices, index+1, 0, fee)), // Buy and move to the sell state
                          (0 + solve(prices, index+1, 1, fee))); // Do nothing and stay in the buy state
        } else {
            // If we are in a selling state (buy == 0), we can either:
            // 1. Sell the stock at current price (this is represented by +prices[index] - fee)
            //    and move to the next index (index+1) in a "buy" state (buy = 1).
            // 2. Skip this index (do nothing) and stay in the "sell" state (buy = 0).
            profit = max((+prices[index] - fee + solve(prices, index+1, 1, fee)), // Sell and move to the buy state
                          (0 + solve(prices, index+1, 0, fee))); // Do nothing and stay in the sell state
        }

        // Return the maximum profit for the current state
        return profit;
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        // Start solving from index 0 with the possibility of buying (buy = 1)
        return solve(prices, 0, 1, fee);
    }
};
```


### Source Code Explanation

```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit
    int solve(vector<int>& prices, int index, int buy, int fee) {
        int n = prices.size(); // Get the size of the prices array
```
- `solve` is the helper function used to recursively calculate the maximum profit.
- `prices`: The array that contains the prices of the stock on each day.
- `index`: The current day we are analyzing.
- `buy`: A flag (1 or 0) to indicate whether we are in the buying state or selling state.
- `fee`: The transaction fee deducted when selling the stock.

```cpp
        if(index == n) return 0;
```
- Base case: If we reach the last day (`index == n`), we return 0 because no profit can be made after the last day.

```cpp
        int profit = 0;
```
- Variable `profit` is initialized to 0. This will hold the maximum profit for the current state.

```cpp
        if(buy) {
```
- If `buy == 1`, it means we are considering buying the stock on this day.

```cpp
            profit = max((-prices[index] + solve(prices, index+1, 0, fee)), 
                          (0 + solve(prices, index+1, 1, fee)));
```
- **Option 1**: We buy the stock at `prices[index]`, so we subtract the price from the profit (`-prices[index]`) and move to the next day with the intention to sell the stock (`solve(prices, index+1, 0, fee)`).
- **Option 2**: We do nothing (stay in the "buy" state), so the profit remains `0`, and we move to the next day (`solve(prices, index+1, 1, fee)`).
- The maximum of these two options is stored in `profit`.

```cpp
        } else {
```
- If `buy == 0`, it means we are in the selling state.

```cpp
            profit = max((+prices[index] - fee + solve(prices, index+1, 1, fee)), 
                          (0 + solve(prices, index+1, 0, fee)));
```
- **Option 1**: We sell the stock at `prices[index]` and incur the transaction fee (`-fee`). We then move to the next day with the intention to buy again (`solve(prices, index+1, 1, fee)`).
- **Option 2**: We do nothing (stay in the "sell" state), and move to the next day (`solve(prices, index+1, 0, fee)`).
- The maximum of these two options is stored in `profit`.

```cpp
        }
        return profit;
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, 0, 1, fee);
    }
};
```
- The `solve` function is called starting from day 0 with the intention to **buy** (`buy = 1`).
- The function returns the maximum profit that can be obtained.



### Example Walkthrough:

**Input:**
```cpp
prices = [1, 3, 2, 8, 4, 9], fee = 2
```

1. **Day 0**: Price is `1`.
   - Buy at `1`, move to Day 1.
   - Skip, move to Day 1.

2. **Day 1**: Price is `3`.
   - Sell at `3`, profit = `3 - 1 - 2 = 0`, move to Day 2.
   - Skip, move to Day 2.

3. **Day 2**: Price is `2`.
   - Buy at `2`, move to Day 3.
   - Skip, move to Day 3.

4. **Day 3**: Price is `8`.
   - Sell at `8`, profit = `8 - 2 - 2 = 6`, move to Day 4.
   - Skip, move to Day 4.

5. **Day 4**: Price is `4`.
   - Buy at `4`, move to Day 5.
   - Skip, move to Day 5.

6. **Day 5**: Price is `9`.
   - Sell at `9`, profit = `9 - 4 - 2 = 3`, move to Day 6.
   - Skip, end.

- The maximum profit calculated will be `8` by buying at Day 0 for `1` and selling at Day 3 for `8`, then buying again at Day 4 for `4` and selling at Day 5 for `9`.

**Output:** `8`


### Time Complexity:
The time complexity is `O(n)` where `n` is the number of days (length of the `prices` array). This is because:
- At each day, the recursion branches into two choices (buy or not, sell or not).
- In the recursive function, for each day, the recursion proceeds to the next day with different choices.

However, since we are not using any form of dynamic programming (memoization or tabulation) in this solution, it results in a lot of repeated calculations for the same state. So the time complexity in its current form is exponential, `O(2^n)`.


### Space Complexity:
The space complexity is `O(n)` due to the recursive call stack. Each recursive call adds a new layer to the stack, which will have a maximum depth of `n` (the number of days in the `prices` array).

In summary:
- **Time Complexity:** `O(2^n)` (due to recursion without memoization).
- **Space Complexity:** `O(n)` (due to the recursion stack).

---

## Top-Down Approach (DP)
In the **top-down approach**, we recursively solve the problem by breaking it down into smaller subproblems. This method uses **memoization** to store the results of previously solved subproblems, avoiding recomputation and improving efficiency.

#### Problem Overview:
We are given an array of stock prices, and we need to calculate the maximum profit that can be obtained by buying and selling stocks, considering a transaction fee when selling a stock.

In the **top-down approach**, we start at index `0` (the first day), and at each step, we decide whether to buy, sell, or skip. The state of our solution is represented by:
- **Index** (`i`): The current day (index in the array).
- **Buy state** (`buy`): Whether we are holding a stock (`1` if holding a stock, `0` if not holding a stock).
- **Fee** (`fee`): The transaction fee for selling a stock.

We use **recursion** to explore both choices (buying/selling or skipping) at each step, storing the intermediate results in a **2D DP table** (`dp`), where `dp[i][buy]` represents the maximum profit from day `i` onward, with the state `buy` (whether we are holding a stock or not).

### **How the Top-Down Approach Works:**

1. **Base Case**:
   - If we have reached the end of the prices array (`index == n`), it means no more transactions can be made, and the profit is `0`.

2. **Recursive Case**:
   - If we are in a "buy" state (`buy == 1`), we have two options:
     1. **Buy**: Buy the stock at the current price and move to the next day, switching to a "sell" state (`buy = 0`).
     2. **Skip**: Do nothing and stay in the current "buy" state.
   
   - If we are in a "sell" state (`buy == 0`), we have two options:
     1. **Sell**: Sell the stock at the current price, subtract the transaction fee, and move to the next day, switching to a "buy" state (`buy = 1`).
     2. **Skip**: Do nothing and stay in the current "sell" state.

3. We use **memoization** to store the results of these recursive calls in the DP table to avoid recomputation. For each state `(index, buy)`, we compute the maximum profit and store it in `dp[index][buy]`.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit using dynamic programming
    int solve(vector<int>& prices, int index, int buy, int fee, vector<vector<int>>& dp) {
        int n = prices.size(); // Get the size of the prices array

        // Base case: If we've reached the end of the array (index == n), no more transactions can be made
        if(index == n) return 0;

        // If the result is already computed for this index and buy state, return it from dp array
        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        
        // If we are in a "buy" state (buy == 1), we can either:
        // 1. Buy the stock at current price (this is represented by -prices[index])
        //    and move to the next index (index+1) in a "sell" state (buy = 0).
        // 2. Skip this index (do nothing) and stay in the "buy" state (buy = 1).
        if(buy) {
            profit = max((-prices[index] + solve(prices, index+1, 0, fee, dp)), // Buy and move to the sell state
                          (0 + solve(prices, index+1, 1, fee, dp))); // Do nothing and stay in the buy state
        } else {
            // If we are in a "sell" state (buy == 0), we can either:
            // 1. Sell the stock at current price (this is represented by +prices[index] - fee)
            //    and move to the next index (index+1) in a "buy" state (buy = 1).
            // 2. Skip this index (do nothing) and stay in the "sell" state (buy = 0).
            profit = max((+prices[index] - fee + solve(prices, index+1, 1, fee, dp)), // Sell and move to the buy state
                          (0 + solve(prices, index+1, 0, fee, dp))); // Do nothing and stay in the sell state
        }

        // Store the result in dp array and return it
        return dp[index][buy] = profit;
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array

        // Initialize the dp array with -1 (indicating no result is computed yet)
        // dp[i][0] represents the maximum profit we can have at index i without buying the stock
        // dp[i][1] represents the maximum profit we can have at index i while having the stock to sell
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        // Start solving from index 0 with the possibility of buying (buy = 1)
        return solve(prices, 0, 1, fee, dp);
    }
};
```


### Source Code Explanation

Let's break down the code line by line.

#### Helper Function: `solve()`

```cpp
int solve(vector<int>& prices, int index, int buy, int fee, vector<vector<int>>& dp) {
```
- This is the recursive helper function that computes the maximum profit starting from a given `index`, with the current state of `buy` (1 if we can buy, 0 if we can sell), and the given `fee`.
  
```cpp
    int n = prices.size();  // Get the size of the prices array
```
- We store the size of the `prices` array in `n` to know when we've reached the end.

```cpp
    if(index == n) return 0;
```
- Base case: If we've reached the end of the array (`index == n`), we cannot make any more transactions, so the profit is `0`.

```cpp
    if(dp[index][buy] != -1) return dp[index][buy];
```
- If the result for the current state (`index`, `buy`) has already been computed (i.e., `dp[index][buy] != -1`), we return the stored result to avoid recomputation.

```cpp
    int profit = 0;
```
- We initialize a variable `profit` to store the maximum profit for the current state.

#### Handling the "Buy" State (`buy == 1`)

```cpp
    if(buy) {
        profit = max((-prices[index] + solve(prices, index+1, 0, fee, dp)), 
                      (0 + solve(prices, index+1, 1, fee, dp)));
    }
```
- If we are in a "buy" state (`buy == 1`), we have two choices:
  1. **Buy**: We buy the stock at the current price (`-prices[index]`) and move to the next day (`index+1`) with a "sell" state (`buy = 0`). This is represented by the first part of the `max()` function: `(-prices[index] + solve(...))`.
  2. **Skip**: We skip buying and stay in the "buy" state. This is represented by the second part: `(0 + solve(...))`.

#### Handling the "Sell" State (`buy == 0`)

```cpp
    else {
        profit = max((+prices[index] - fee + solve(prices, index+1, 1, fee, dp)), 
                      (0 + solve(prices, index+1, 0, fee, dp)));
    }
```
- If we are in a "sell" state (`buy == 0`), we have two choices:
  1. **Sell**: We sell the stock at the current price (`+prices[index] - fee`) and move to the next day (`index+1`) with a "buy" state (`buy = 1`).
  2. **Skip**: We skip selling and stay in the "sell" state.

#### Storing the Result

```cpp
    return dp[index][buy] = profit;
```
- Once we've computed the maximum profit for the current state (`index`, `buy`), we store it in `dp[index][buy]`.



### **Main Function: `maxProfit()`**

```cpp
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();  // Get the size of the prices array
```
- We get the size of the prices array `n` to initialize the DP table.

```cpp
    vector<vector<int>> dp(n+1, vector<int>(2, -1));  // Initialize the DP table with -1
```
- We initialize the DP table `dp` of size `(n+1) x 2`, where each entry is initially set to `-1`. `dp[i][0]` stores the maximum profit when we are not holding any stock on day `i`, and `dp[i][1]` stores the maximum profit when we are holding a stock on day `i`.

```cpp
    return solve(prices, 0, 1, fee, dp);
```
- We start the recursive function `solve()` from index `0` with the possibility of buying a stock (`buy = 1`), passing the DP table to store the results.



### **Example Walkthrough**

Let’s go through an example with prices `[1, 3, 2, 8, 4, 9]` and a fee of `2`.

- On day `0`, we start with the possibility of buying. We calculate the maximum profit recursively for all future days. The DP table is filled as the recursion proceeds.
- When we reach day `5`, we cannot make any further transactions, so the recursion starts returning `0`.
- As we backtrack, the maximum profit for each state is computed and stored in the DP table, ultimately leading to the final result.

#### Example Output:

For prices `[1, 3, 2, 8, 4, 9]` and fee `2`, the maximum profit will be `8` because:
- Buy at price `1` on day `0`.
- Sell at price `8` on day `3` (profit: 8 - 1 - 2 = 5).
- Buy at price `4` on day `4`.
- Sell at price `9` on day `5` (profit: 9 - 4 - 2 = 3).
- Total profit: `5 + 3 = 8`.


### **Time and Space Complexity**

#### Time Complexity:
- Each state (`index`, `buy`) is computed once and stored in the DP table. The recursive function makes a maximum of `n` recursive calls, and for each call, there are two choices (buy or sell).
- Therefore, the time complexity is **O(n)**, where `n` is the number of days (the size of the `prices` array).

#### Space Complexity:
- We use a 2D DP table of size `(n+1) x 2` to store the results of subproblems.
- Therefore, the space complexity is **O(n)**, where `n` is the number of days.

---

## Bottom-Up Approach (DP)
The **bottom-up approach** is an iterative way to solve the problem. It starts by solving smaller subproblems first, gradually solving larger problems based on those results. In the context of this problem, it avoids recursion and builds the solution iteratively using dynamic programming (DP).

The goal is to calculate the maximum profit from buying and selling stocks with a transaction fee, given an array of stock prices over a series of days.

#### Problem Overview:

Given an array of stock prices, `prices[]`, and a transaction fee, `fee`, we want to maximize the profit by choosing a series of buy and sell operations. You can only perform one operation (buy or sell) on each day.

We need to compute the maximum profit by using a **bottom-up dynamic programming** approach, where we calculate the profit for each state (buy or sell) iteratively for each day, starting from the last day.

#### Steps of the Bottom-Up Approach:

1. **Initialize the DP Table**:
   - We define a 2D array `dp[i][buy]` where:
     - `i`: Represents the day index.
     - `buy`: If `buy == 1`, it means we are holding a stock. If `buy == 0`, it means we are not holding a stock.

2. **Iterate Over Each Day**:
   - We start from the last day (because we know that no transactions can be made after the last day), and work our way back to the first day.
   - For each day, we consider the two states (`buy = 0` and `buy = 1`), and compute the maximum profit based on the possible actions:
     - **If we are in the "buy" state (`buy == 1`)**, we have two options:
       1. Buy the stock at the current price.
       2. Do nothing and stay in the "buy" state.
     - **If we are in the "sell" state (`buy == 0`)**, we have two options:
       1. Sell the stock and pay the transaction fee.
       2. Do nothing and stay in the "sell" state.

3. **Build the Solution Iteratively**:
   - For each day, we calculate the maximum possible profit for both "buy" and "sell" states and update the DP table.
   
4. **Return the Final Result**:
   - Once the table is filled, the maximum profit will be found in `dp[0][1]`, which represents the maximum profit we can get starting from day 0, with the possibility of buying a stock.

### Source Code 
```
class Solution {
public:
    // Helper function to calculate the maximum profit with transaction fee using dynamic programming (bottom-up approach)
    int solve(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array

        // Initialize the dp array with 0, where dp[i][0] represents the maximum profit at index i without holding the stock
        // dp[i][1] represents the maximum profit at index i when holding the stock
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        // Iterate backwards through the prices array starting from the last index
        for(int index = n-1; index >= 0; index--) {
            // Iterate through both possible states: buy (1) or sell (0)
            for(int buy = 0; buy <= 1; buy++) {

                int profit = 0;
                
                // If we are in a "buy" state (buy == 1), we have two options:
                // 1. Buy the stock at the current price (represented by -prices[index])
                //    and move to the next index where we are in a "sell" state (dp[index+1][0]).
                // 2. Do nothing and stay in the "buy" state at the next index (dp[index+1][1]).
                if(buy) {
                    int buyStock = -prices[index] + dp[index+1][0];  // Buy stock
                    int notBuyStock = 0 + dp[index+1][1];  // Do nothing (stay in the "buy" state)
                    profit = max(buyStock, notBuyStock);  // Take the maximum of these two options
                } else {
                    // If we are in a "sell" state (buy == 0), we have two options:
                    // 1. Sell the stock at the current price and subtract the fee (represented by +prices[index] - fee)
                    //    and move to the next index where we are in a "buy" state (dp[index+1][1]).
                    // 2. Do nothing and stay in the "sell" state at the next index (dp[index+1][0]).
                    int sellStock = +prices[index] - fee + dp[index+1][1];  // Sell stock and pay the fee
                    int notSellStock = 0 + dp[index+1][0];  // Do nothing (stay in the "sell" state)
                    profit = max(sellStock, notSellStock);  // Take the maximum of these two options
                }

                // Store the calculated profit in the dp array
                dp[index][buy] = profit;
            }
        }

        // Return the maximum profit starting from index 0 with the possibility of buying the stock (buy = 1)
        return dp[0][1];
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array
        return solve(prices, fee); // Call the solve function to calculate the maximum profit
    }
};
```

### Source Code Explanation
Now, let's explain the source code in detail, line by line.

#### **Helper Function: `solve()`**

```cpp
int solve(vector<int>& prices, int fee) {
    int n = prices.size(); // Get the size of the prices array
```
- Here, we get the number of days `n` from the size of the `prices` array. This tells us how many days of stock prices we have.

```cpp
    vector<vector<int>> dp(n+1, vector<int>(2, 0));  // Initialize the dp array with 0
```
- We initialize a 2D DP array `dp`, where `dp[i][0]` represents the maximum profit on day `i` without holding a stock, and `dp[i][1]` represents the maximum profit on day `i` when holding a stock. We add `n+1` rows to accommodate for the 0-based indexing and an extra row for base case handling (index `n`).

```cpp
    for(int index = n-1; index >= 0; index--) { // Iterate backwards through the prices array starting from the last index
```
- We loop through the array starting from the last day (`index = n-1`) to the first day (`index = 0`). This is because in a bottom-up approach, we need to fill the table iteratively, starting from the base case.

```cpp
        for(int buy = 0; buy <= 1; buy++) { // Iterate through both possible states: buy (1) or sell (0)
```
- For each day (`index`), we need to calculate the maximum profit for both possible states:
  - `buy == 1`: We are holding a stock.
  - `buy == 0`: We are not holding a stock.

```cpp
            int profit = 0;
```
- We initialize a variable `profit` to store the maximum profit for the current day and state.

#### **Handling the "Buy" State (`buy == 1`)**

```cpp
            if(buy) {
                int buyStock = -prices[index] + dp[index+1][0];  // Buy stock and move to the "sell" state
                int notBuyStock = 0 + dp[index+1][1];  // Do nothing (stay in the "buy" state)
                profit = max(buyStock, notBuyStock);  // Take the maximum of these two options
            }
```
- If we are in the "buy" state (`buy == 1`):
  1. **Buy stock**: We subtract the price of the stock at the current day (`-prices[index]`) and move to the next day (`index+1`) in a "sell" state (`dp[index+1][0]`).
  2. **Do nothing**: Stay in the "buy" state by moving to the next day (`dp[index+1][1]`).
- We calculate the maximum of these two options (`buyStock` and `notBuyStock`) and store the result in `profit`.

#### **Handling the "Sell" State (`buy == 0`)**

```cpp
            else {
                int sellStock = +prices[index] - fee + dp[index+1][1];  // Sell stock and pay the fee
                int notSellStock = 0 + dp[index+1][0];  // Do nothing (stay in the "sell" state)
                profit = max(sellStock, notSellStock);  // Take the maximum of these two options
            }
```
- If we are in the "sell" state (`buy == 0`):
  1. **Sell stock**: We add the price of the stock (`+prices[index]`), subtract the fee (`-fee`), and move to the next day (`index+1`) in a "buy" state (`dp[index+1][1]`).
  2. **Do nothing**: Stay in the "sell" state by moving to the next day (`dp[index+1][0]`).
- Again, we calculate the maximum of these two options (`sellStock` and `notSellStock`) and store the result in `profit`.

```cpp
            dp[index][buy] = profit; // Store the calculated profit in the dp array
```
- We store the calculated `profit` for the current day (`index`) and state (`buy`) in the DP table.

```cpp
    return dp[0][1]; // Return the maximum profit starting from index 0 with the possibility of buying the stock
```
- Once the table is filled, we return the maximum profit at index `0` with the possibility of buying a stock (`dp[0][1]`).



#### **Main Function: `maxProfit()`**

```cpp
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();  // Get the size of the prices array
    return solve(prices, fee);  // Call the solve function to calculate the maximum profit
}
```
- The main function simply calls the `solve()` function to compute the maximum profit given the stock prices and transaction fee.



### **Example Walkthrough**

Let’s walk through an example with prices `[1, 3, 2, 8, 4, 9]` and a transaction fee of `2`.

- On day `0`, the price is `1`. We start by considering buying the stock.
- On day `1`, the price is `3`. We consider the options of either buying or selling.
- We keep building the solution iteratively. The final DP table will store the maximum profits for each day and state, and the result will be found in `dp[0][1]`.

**Example Output**:

For prices `[1, 3, 2, 8, 4, 9]` and fee `2`, the maximum profit will be `8` because:
1. Buy at `1` (day `0`).
2. Sell at `8` (day `3`), profit: `8 - 1 - 2 = 5`.
3. Buy at `4` (day `4`).
4. Sell at `9` (day `5`), profit: `9 - 4 - 2 = 3`.
5. Total profit: `5 + 3 = 8`.

### **Time and Space Complexity**

#### Time Complexity:
- We have a 2D DP table with `n` rows and 2 columns, where `n` is the number of days. For each day, we calculate the profit for two possible states (buy and sell).
- Thus, the time complexity is **O(n)**, where `n` is the length of the `prices` array.

#### Space Complexity:
- The DP table has a size of `n+1` rows and 2 columns, which results in a space complexity of **O(n)**.

---

## Space Optimization Approach (DP)
In the space optimization approach, we aim to reduce the space complexity by eliminating the need for a 2D DP array. Instead, we use only two 1D arrays to represent the current and next states, effectively optimizing the space used by the dynamic programming solution.

#### Key Concepts:
- **`curr` and `next` Arrays**: These arrays represent the current and next states of the dynamic programming solution. `curr` holds the profit values for the current index, while `next` holds the profit values for the next index (future state). By alternating between these two arrays, we save space and only store what is needed at any given point in time.

- **DP Transitions**: The transitions (decisions of whether to buy or sell) at each index depend on the states from the next index. Thus, after each iteration, we update the `next` array with the values from the `curr` array.

### Source Code
```
class Solution {
public:
    // Helper function to calculate the maximum profit with transaction fee using dynamic programming (optimized space approach)
    int solve(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array
        
        // Initialize two arrays to store the maximum profit for the current and next states.
        // 'curr' will represent the current state (profit at index 'index'), 
        // 'next' will represent the state for the next index (future state).
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        // Iterate backwards through the prices array starting from the last index
        for(int index = n-1; index >= 0; index--) {
            // Iterate through both possible states: buy (1) or sell (0)
            for(int buy = 0; buy <= 1; buy++) {

                int profit = 0;

                // If we are in a "buy" state (buy == 1), we have two options:
                // 1. Buy the stock at the current price (represented by -prices[index]) and 
                //    move to the next index where we are in a "sell" state (next[0]).
                // 2. Do nothing and stay in the "buy" state at the next index (next[1]).
                if(buy) {
                    int buyStock = -prices[index] + next[0];  // Buy stock
                    int notBuyStock = 0 + next[1];  // Do nothing (stay in the "buy" state)
                    profit = max(buyStock, notBuyStock);  // Take the maximum of these two options
                } else {
                    // If we are in a "sell" state (buy == 0), we have two options:
                    // 1. Sell the stock at the current price and subtract the fee (represented by +prices[index] - fee)
                    //    and move to the next index where we are in a "buy" state (next[1]).
                    // 2. Do nothing and stay in the "sell" state at the next index (next[0]).
                    int sellStock = +prices[index] - fee + next[1];  // Sell stock and pay the fee
                    int notSellStock = 0 + next[0];  // Do nothing (stay in the "sell" state)
                    profit = max(sellStock, notSellStock);  // Take the maximum of these two options
                }

                // Store the calculated profit for the current state in the 'curr' array
                curr[buy] = profit;
            }

            // Move the current state (curr) to the next state (next) for the next iteration
            next = curr;
        }

        // Return the maximum profit starting from index 0 with the possibility of buying the stock (buy = 1)
        return next[1];
    }

    // Main function to calculate the maximum profit with transaction fee
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array
        return solve(prices, fee); // Call the solve function to calculate the maximum profit
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Helper function to calculate the maximum profit with transaction fee using dynamic programming (optimized space approach)
    int solve(vector<int>& prices, int fee) {
        int n = prices.size(); // Get the size of the prices array
        
        // Initialize two arrays to store the maximum profit for the current and next states.
        vector<int> curr(2, 0);  // curr[0] -> not holding stock, curr[1] -> holding stock
        vector<int> next(2, 0);  // next[0] -> not holding stock, next[1] -> holding stock
```
- We start by determining the number of days (`n`) based on the `prices` array size.
- `curr` and `next` arrays are initialized to store the maximum profit for each state (either holding or not holding stock) at any given index. Both arrays are of size 2 (for the two states: "hold" and "don't hold").

```cpp
        // Iterate backwards through the prices array starting from the last index
        for (int index = n - 1; index >= 0; index--) {
```
- We iterate backward through the `prices` array because we're solving the problem in a bottom-up manner. We want to compute the maximum profit starting from the last day and moving backward to the first day.

```cpp
            // Iterate through both possible states: buy (1) or sell (0)
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
```
- We loop over the two possible states for each day:
  - `buy == 1`: Holding a stock.
  - `buy == 0`: Not holding a stock.

```cpp
                if (buy) {
                    int buyStock = -prices[index] + next[0];  // Buy stock at current price
                    int notBuyStock = 0 + next[1];  // Do nothing and stay in "buy" state
                    profit = max(buyStock, notBuyStock);  // Choose the best option
                } else {
                    int sellStock = prices[index] - fee + next[1];  // Sell stock and pay the fee
                    int notSellStock = 0 + next[0];  // Do nothing and stay in "sell" state
                    profit = max(sellStock, notSellStock);  // Choose the best option
                }
```
- For each state:
  - If we are **buying** (holding a stock), we have two options:
    1. **Buy** the stock at the current price and move to the next day where we're in the "sell" state (`next[0]`).
    2. **Do nothing** and stay in the "buy" state at the next index (`next[1]`).
  
  - If we are **selling** (not holding a stock), we have two options:
    1. **Sell** the stock at the current price, paying the transaction fee, and move to the next day where we're in the "buy" state (`next[1]`).
    2. **Do nothing** and stay in the "sell" state at the next index (`next[0]`).

- The `profit` is the maximum of the two options in each case.

```cpp
                curr[buy] = profit;  // Store the calculated profit for the current state in the 'curr' array
            }
            next = curr;  // Move the current state (curr) to the next state (next) for the next iteration
        }
```
- After calculating the profit for both "buy" and "sell" states, we store the result in `curr[buy]`.
- After processing the current day (index), we move the current state (`curr`) to the next state (`next`) for the next iteration.

```cpp
        return next[1];  // Return the maximum profit starting from index 0 with the possibility of buying the stock (buy = 1)
    }
```
- After all iterations, the maximum profit will be stored in `next[1]`, which represents the profit when starting with the possibility of buying the stock on the first day.

### Example Output Explanation

#### Example Input:
```cpp
vector<int> prices = {1, 3, 2, 8, 4, 9};
int fee = 2;
```

- Prices on each day: `[1, 3, 2, 8, 4, 9]`.
- Transaction fee: `2`.

#### Example Process:
- We iterate backward through the array and decide, for each day, whether it's better to buy or sell stock, keeping in mind the transaction fee.

For example, on day 4 (`price = 4`), if we sell stock:
- Sell at `4`, after subtracting the fee (`2`), the profit is `2`.
- On day 5 (`price = 9`), we can sell the stock bought on day 4, getting the maximum profit.

By considering all possible options, the final maximum profit after all iterations is `8`.

#### Final Output:
```cpp
maxProfit(prices, fee) -> 8;
```

### Time Complexity

- **Outer loop**: The outer loop iterates through the prices array backward, so it runs `n` *.
- **Inner loop**: The inner loop runs twice, corresponding to the two possible states (buy = 0 or buy = 1).
- Hence, the time complexity is `O(n)` where `n` is the length of the `prices` array.

### Space Complexity

- We are using two arrays (`curr` and `next`), each of size 2. Therefore, the space complexity is `O(1)`, constant space.

### Conclusion

This space-optimized approach reduces the space complexity significantly by using two 1D arrays instead of a 2D array, while maintaining the same time complexity (`O(n)`). The solution works efficiently even for large inputs where memory usage is a concern.


