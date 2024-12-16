<h1 align="center">Best - Time To - Buy & Sell - Stock</h1>

## Problem Statement

**Problem URL :** [Best Time To Buy & Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

![image](https://github.com/user-attachments/assets/d23bc577-41f3-4a39-b8ab-f2432ad156df)

### Problem Explanation

The problem asks us to find the **maximum profit** we can achieve from buying and selling a stock at different times. You are given a list of stock prices where each price corresponds to the price of the stock on a particular day. The goal is to determine **the best time to buy and the best time to sell** in order to maximize the profit.

You are allowed to make **only one transaction** (i.e., you can buy and sell the stock once). You must buy the stock first, then sell it at a later date.

### Key Points:

1. **You must buy before you sell.**
2. **You are allowed to make only one buy and one sell.**
3. You are to find the maximum profit that can be made from buying and selling at different times.

If no profit can be made (i.e., the stock price only decreases over time), the result should be **0**.

### Input:

- A list of integers `prices`, where each element represents the stock price on a particular day.
  
### Output:

- An integer that represents the **maximum profit** that can be achieved. If no profit is possible, return **0**.


### Example 1:

**Input:**

```cpp
prices = [7, 1, 5, 3, 6, 4]
```

**Explanation:**

- On Day 1, the price is 7.
- On Day 2, the price is 1 (this is the lowest price, so it's a good time to buy).
- On Day 3, the price is 5 (this is a higher price, so you could sell here).
- On Day 4, the price is 3.
- On Day 5, the price is 6 (this is another potential time to sell).
- On Day 6, the price is 4.

The **best strategy** here is:
- Buy at Day 2 (price = 1).
- Sell at Day 5 (price = 6).

The profit is:
- **Profit = 6 - 1 = 5**.

Thus, the maximum profit is **5**.

**Output:**

```cpp
5
```


### Example 2:

**Input:**

```cpp
prices = [7, 6, 4, 3, 1]
```

**Explanation:**

- On Day 1, the price is 7.
- On Day 2, the price is 6.
- On Day 3, the price is 4.
- On Day 4, the price is 3.
- On Day 5, the price is 1.

In this case, the price keeps decreasing every day. **No profit can be made** because you would have to sell the stock at a lower price than you bought it. Therefore, the best strategy is not to buy or sell at all.

The maximum profit is **0**.

**Output:**

```cpp
0
```

### Example 3:

**Input:**

```cpp
prices = [1, 2]
```

**Explanation:**

- On Day 1, the price is 1.
- On Day 2, the price is 2.

In this case, you can:
- Buy on Day 1 (price = 1).
- Sell on Day 2 (price = 2).

The profit is:
- **Profit = 2 - 1 = 1**.

Thus, the maximum profit is **1**.

**Output:**

```cpp
1
```

### Approach to Solve the Problem:

1. **Brute Force Approach:**
   - Try every possible pair of buy and sell days. For each pair, calculate the profit (sell price - buy price) and keep track of the maximum profit.
   - This approach has a time complexity of (O(n^2)), where (n) is the number of days. This can be inefficient for larger inputs.

2. **Optimized Approach (Linear Scan):**
   - Instead of trying every pair, we can **keep track of the minimum price** seen so far as we iterate through the list. For each price, calculate the potential profit (current price - minimum price) and update the maximum profit.
   - This approach only requires one pass through the list, giving us a time complexity of (O(n)).

**Steps in the optimized approach:**
1. Initialize `min_price` to a large value (or the first element in the list) and `max_profit` to 0.
2. Loop through each price in the list:
   - Update `min_price` if the current price is lower than `min_price`.
   - Calculate the potential profit for the current price (current price - `min_price`).
   - Update `max_profit` if the current profit is higher than `max_profit`.
3. Return the `max_profit` after the loop ends.

## Problem Solution
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price to the first day's price
        int mini = prices[0];
        
        // Initialize the maximum profit to 0
        int profit = 0;

        // Iterate through the price list starting from the second day
        for(int i = 1; i < prices.size(); i++) {
            // Calculate the potential profit if the stock is sold on the current day
            int diff = prices[i] - mini;

            // Update the maximum profit if the current profit is higher
            profit = max(profit, diff);

            // Update the minimum price seen so far
            mini = min(mini, prices[i]);
        }

        // Return the maximum profit found
        return profit;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
```
- **Line 1-2**: A class `Solution` is defined, and within it, there is a method `maxProfit` that accepts a reference to a vector of integers (`prices`). This vector represents the stock prices on each day.
  


```cpp
        // Initialize the minimum price to the first day's price
        int mini = prices[0];
```
- **Line 3**: We initialize `mini` to the first element of the `prices` array, which represents the stock price on the first day. This will act as the starting "minimum price" that we are tracking.
  
**Example**:  
If `prices = [7, 1, 5, 3, 6, 4]`, then initially, `mini = 7`.



```cpp
        // Initialize the maximum profit to 0
        int profit = 0;
```
- **Line 4**: We initialize `profit` to `0`. This variable will hold the maximum profit that can be achieved. Initially, the profit is 0 because no transactions have been made yet.
  
**Example**:  
If `prices = [7, 1, 5, 3, 6, 4]`, initially, `profit = 0`.



```cpp
        // Iterate through the price list starting from the second day
        for(int i = 1; i < prices.size(); i++) {
```
- **Line 5**: We start a loop from `i = 1` because we've already set the initial `mini` to the first element of the `prices` list, so we don’t need to consider it again. We will iterate through the rest of the prices list from the second day onward.

**Example**:  
If `prices = [7, 1, 5, 3, 6, 4]`, the loop will start at `i = 1` (second day, price = 1).



```cpp
            // Calculate the potential profit if the stock is sold on the current day
            int diff = prices[i] - mini;
```
- **Line 6**: For each price at `i`, we calculate the potential profit if we had bought the stock at the `mini` price (the lowest price seen so far) and sold it on day `i`. The difference between the current price (`prices[i]`) and the `mini` price is stored in `diff`.
  
**Example**:  
For `prices = [7, 1, 5, 3, 6, 4]`:
- At `i = 1` (price = 1), `diff = 1 - 7 = -6` (this is a loss, so no action is taken).
- At `i = 2` (price = 5), `diff = 5 - 7 = -2` (still a loss).
- At `i = 3` (price = 3), `diff = 3 - 7 = -4` (still a loss).
- At `i = 4` (price = 6), `diff = 6 - 7 = -1` (still a loss).
- At `i = 5` (price = 4), `diff = 4 - 7 = -3` (still a loss).



```cpp
            // Update the maximum profit if the current profit is higher
            profit = max(profit, diff);
```
- **Line 7**: Here, we update the `profit` variable to the maximum of the current `profit` and the newly calculated `diff`. This ensures that if the `diff` (current profit) is greater than the previously stored `profit`, we update it.
  
**Example**:  
For `prices = [7, 1, 5, 3, 6, 4]`:
- Initially, `profit = 0`.
- At `i = 1` (price = 1), `diff = -6`. Since `-6 < 0`, `profit` remains 0.
- At `i = 2` (price = 5), `diff = -2`. Since `-2 < 0`, `profit` remains 0.
- At `i = 3` (price = 3), `diff = -4`. Since `-4 < 0`, `profit` remains 0.
- At `i = 4` (price = 6), `diff = -1`. Since `-1 < 0`, `profit` remains 0.
- At `i = 5` (price = 4), `diff = -3`. Since `-3 < 0`, `profit` remains 0.

At this point, `profit` is still 0 because we haven't found a profitable situation yet.



```cpp
            // Update the minimum price seen so far
            mini = min(mini, prices[i]);
```
- **Line 8**: After calculating the profit, we update `mini` to the minimum of the current `mini` and `prices[i]`. This ensures that we always know the lowest stock price encountered so far, which is critical for calculating future profits.

**Example**:
For `prices = [7, 1, 5, 3, 6, 4]`:
- Initially, `mini = 7`.
- At `i = 1` (price = 1), `mini = min(7, 1) = 1` (update `mini` to 1).
- At `i = 2` (price = 5), `mini = min(1, 5) = 1` (no update needed).
- At `i = 3` (price = 3), `mini = min(1, 3) = 1` (no update needed).
- At `i = 4` (price = 6), `mini = min(1, 6) = 1` (no update needed).
- At `i = 5` (price = 4), `mini = min(1, 4) = 1` (no update needed).

At the end of the loop, `mini` remains 1, which is the lowest price seen so far.



```cpp
        // Return the maximum profit found
        return profit;
    }
};
```
- **Line 9-10**: After finishing the loop, we return the `profit` variable, which holds the maximum profit that could be made by buying and selling once. If no profit is possible (i.e., the prices are in descending order), `profit` will remain 0.

**Example**:
For `prices = [7, 1, 5, 3, 6, 4]`, the final result is `profit = 5` because the best strategy is to buy at 1 and sell at 6.



### Final Explanation with Example:

Let's go through the example `prices = [7, 1, 5, 3, 6, 4]` step by step:

- Initially:
  - `mini = 7`
  - `profit = 0`

- **Iteration 1 (price = 1)**:
  - `diff = 1 - 7 = -6` (no profit)
  - `profit = max(0, -6) = 0` (no update)
  - `mini = min(7, 1) = 1` (update mini)

- **Iteration 2 (price = 5)**:
  - `diff = 5 - 1 = 4` (profit is 4)
  - `profit = max(0, 4) = 4` (update profit)
  - `mini = min(1, 5) = 1` (no update)

- **Iteration 3 (price = 3)**:
  - `diff = 3 - 1 = 2` (profit is 2)
  - `profit = max(4, 2) = 4` (no update)
  - `mini = min(1, 3) = 1` (no update)

- **Iteration 4 (price = 6)**:
  - `diff = 6 - 1 = 5` (profit is 5)
  - `profit = max(4, 5) = 5` (update profit)
  - `mini = min(1, 6) = 1` (no update)

- **Iteration 5 (price = 4)**:
  - `diff = 4 - 1 = 3` (profit is 3)
  - `profit = max(5, 3) = 5` (no update)
  - `mini = min(1, 4) = 1` (no update)

- At the end of the loop, the maximum profit is `5`.

Thus, the output for this input is **5**.


### Time and Space Complexity Analysis

#### Code Recap:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0]; // O(1)
        int profit = 0;       // O(1)

        for (int i = 1; i < prices.size(); i++) { // Loop runs prices.size() - 1 times
            int diff = prices[i] - mini;         // O(1)
            profit = max(profit, diff);          // O(1)
            mini = min(mini, prices[i]);         // O(1)
        }

        return profit; // O(1)
    }
};
```

### Time Complexity
1. **Initialization**:
   - Setting `mini` and `profit` takes (O(1)) time.
   
2. **Loop**:
   - The `for` loop iterates through the `prices` array exactly once, starting from the second element ((i = 1)) to the last ((i = prices.size() - 1)).
   - For each iteration, the operations inside the loop (calculating `diff`, updating `profit`, and updating `mini`) all take (O(1)) time.
   - Thus, the total time spent in the loop is proportional to the size of the array: (O(n)), where (n) is the size of `prices`.

3. **Return Statement**:
   - Returning `profit` takes (O(1)) time.

### Total Time Complexity:
The dominant factor is the single loop through the `prices` array, which is (O(n)).  
Thus, **time complexity** = **(O(n))**.

### Space Complexity
1. **Input Array**:
   - The input vector `prices` is provided as an argument, so its memory is not included in the space complexity.

2. **Variables**:
   - The algorithm uses a constant amount of extra space:
     - `mini` (stores the minimum price seen so far): (O(1))
     - `profit` (stores the maximum profit): (O(1))
     - `diff` (temporary variable for profit calculation): (O(1))



### Total Space Complexity:
Since the algorithm does not use any additional data structures and only utilizes a fixed number of variables, the **space complexity** = **(O(1))**.


### Summary:

- We are tracking the **minimum price** seen so far (`mini`).
- At each step, we calculate the **profit** if we sold on that day and update the **maximum profit** (`profit`) if it’s greater than the previous maximum.
- At the end of the loop, we return the **maximum profit** possible, which is either positive or 0 if no profit can be made.
- **Time Complexity**: (O(n)), where (n) is the size of the `prices` array.
- **Space Complexity**: (O(1)), as only constant space is used.
