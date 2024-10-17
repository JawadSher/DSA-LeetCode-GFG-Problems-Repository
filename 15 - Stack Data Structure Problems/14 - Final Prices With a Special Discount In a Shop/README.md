<h1 align='center'>Final - Prices - With a - Special - Discount - In a - Shop</h1>

## Problem Statement

**Problem URL :** [Final Prices With a Special Discount In a Shop](https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/)

![image](https://github.com/user-attachments/assets/3fc9261f-4df2-46cf-b7bc-5b3e0fbbcb89)
![image](https://github.com/user-attachments/assets/931c984f-8051-4557-88c9-60717a8f1598)

## Problem Explanation

**Objective:** Given a list of prices, the task is to find the final price of each item after applying a special discount. The discount for an item is the next smaller price in the list (if any); if there is no smaller price, the final price remains the same.

#### Example:
1. **Input:** 
   - `prices = [8, 4, 6, 2, 3]`
   
   **Output:**
   - `final_prices = [4, 2, 4, 2, 3]`
   
   **Explanation:** 
   - For price `8`, the next smaller price is `4` → `8 - 4 = 4`
   - For price `4`, the next smaller price is `2` → `4 - 2 = 2`
   - For price `6`, the next smaller price is `2` → `6 - 2 = 4`
   - For price `2`, there is no smaller price → `2 - 0 = 2`
   - For price `3`, there is no smaller price → `3 - 0 = 3`

2. **Input:**
   - `prices = [1, 2, 3, 4]`
   
   **Output:**
   - `final_prices = [1, 2, 3, 4]`
   
   **Explanation:** 
   - There are no smaller prices for any of the items, so the final prices remain the same.

### Approach:

To solve this problem, we can use a **stack** to efficiently track the next smaller price for each item. The key idea is to traverse the list from right to left and use the stack to maintain potential smaller prices.

1. **Initialize:** 
   - Create a vector `ans` to store the final prices.
   - Use a stack to keep track of prices as we iterate.

2. **Iterate Backwards:** 
   - For each price, check the top of the stack:
     - If the top of the stack is greater than the current price, pop the stack.
     - The next smaller price will be on the top of the stack (or zero if the stack is empty).
     - Calculate the final price by subtracting the smaller price from the current price.

3. **Push Current Price to Stack:** 
   - After processing, push the current price onto the stack for future comparisons.

## Problem Solution
```cpp
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);

        st.push(0);

        for(int i = n-1; i >= 0; i--){
            int current = prices[i];

            while(!st.empty() && st.top() > current){
                st.pop();
            }

            ans[i] = prices[i] - st.top();
            st.push(current);
        }

        return ans;
    }
};
```

## Problem Solution Explanation
Let's break down the provided C++ code for the `finalPrices` function step by step, following the structured format.

#### Initialization

- **Variables**:
  ```cpp
  int n = prices.size();
  stack<int> st;  // Stack to hold prices
  vector<int> ans(n);  // Vector to hold the final prices
  ```

- **Push a Dummy Value**:
  ```cpp
  st.push(0);
  ```
  - A dummy value is pushed onto the stack to handle cases where no smaller price exists.

---

#### Main Loop

- **Loop Through Prices**:
  ```cpp
  for(int i = n-1; i >= 0; i--){
      int current = prices[i];
  ```
  - Iterate from the last price to the first. `current` holds the current price being processed.

---

#### Stack Processing

- **Find Next Smaller Price**:
  ```cpp
  while(!st.empty() && st.top() > current){
      st.pop();
  }
  ```
  - While the stack is not empty and the top of the stack is greater than the current price, pop elements from the stack. This ensures that we only keep smaller prices in the stack.

---

#### Calculate Final Price

- **Update Final Prices**:
  ```cpp
  ans[i] = prices[i] - st.top();
  ```
  - Subtract the top of the stack (next smaller price) from the current price to get the final price.
  
- **Push Current Price**:
  ```cpp
  st.push(current);
  ```
  - Push the current price onto the stack for future comparisons.

---

### Return Result

- **Final Return Statement**:
  ```cpp
  return ans;
  ```
  - The function returns the vector `ans`, which contains the final prices after applying discounts.

---

### Example Walkthrough

Let's work through an example to clarify how the algorithm works.

#### Input
```cpp
prices = [8, 4, 6, 2, 3]
```

#### Step-by-Step Execution

1. **Initialization**:
   - `n = 5`, `st = {0}`, `ans = [0, 0, 0, 0, 0]`

2. **Iteration**:
   - **i = 4** (current = `3`):
     - `st = {0}` (stack remains unchanged)
     - `ans[4] = 3 - 0 = 3`
     - Push `3` onto the stack: `st = {0, 3}`

   - **i = 3** (current = `2`):
     - Pop `3` (top of the stack is greater than `2`).
     - `st = {0}`
     - `ans[3] = 2 - 0 = 2`
     - Push `2` onto the stack: `st = {0, 2}`

   - **i = 2** (current = `6`):
     - `st = {0, 2}` (stack remains unchanged)
     - `ans[2] = 6 - 2 = 4`
     - Push `6` onto the stack: `st = {0, 2, 6}`

   - **i = 1** (current = `4`):
     - Pop `6` (top of the stack is greater than `4`).
     - `st = {0, 2}`
     - `ans[1] = 4 - 2 = 2`
     - Push `4` onto the stack: `st = {0, 2, 4}`

   - **i = 0** (current = `8`):
     - Pop `4` and `2` (both are less than `8`).
     - `st = {0}`
     - `ans[0] = 8 - 0 = 8`
     - Push `8` onto the stack: `st = {0, 8}`

#### Final Output

- After completing the iteration, `ans = [8, 2, 4, 2, 3]`.

#### Result

```cpp
finalPrices = [8, 2, 4, 2, 3]
```

### Complexity Analysis

- **Time Complexity**: O(n) - Each price is pushed and popped from the stack at most once.
- **Space Complexity**: O(n) - The stack and the answer array may hold up to n elements.

---

### Summary

This code efficiently computes the final prices after applying discounts based on the next smaller price using a stack for fast access, resulting in an optimal solution with linear time complexity.
