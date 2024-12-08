<h1 align="center">0-1 Knapsack - Problem</h1>


## Problem Statement

**Problem URL :** [0-1 Knapsack Problem](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/5d46b013-faf8-40b8-9e16-51a812b72077)

### Problem Explanation
The **0/1 Knapsack Problem** is a well-known problem in computer science and dynamic programming. It is often used to demonstrate how dynamic programming can be applied to optimization problems.

You are given a set of items, each with a **weight** and a **value**, and a knapsack that can carry a certain **maximum weight**. The goal is to determine the **maximum value** that can be obtained by selecting a subset of items, such that the total weight does not exceed the capacity of the knapsack. Each item can either be **included** or **excluded** from the knapsack (hence the name 0/1 knapsack).

### Problem Definition:
- **Input:**
  - A list of items, each with a value and a weight.
  - A knapsack capacity (`W`), which is the maximum weight it can carry.
  
- **Output:**
  - The maximum value that can be obtained within the given weight capacity.

The key here is to choose a subset of items such that:
1. The total weight of the chosen items does not exceed the knapsack's capacity.
2. The total value of the chosen items is as large as possible.

### 0/1 Knapsack Rules:
- You can either take an item or leave it (0 or 1 decision).
- If you take the item, the weight of that item is subtracted from the remaining capacity.
- The value of the item is added to the total value.

### Approach (Dynamic Programming):

We solve this problem using a **dynamic programming** approach. The idea is to break the problem into smaller subproblems and build up the solution by solving these subproblems.

#### Steps:
1. **Define a DP table**: Let `dp[i][w]` be the maximum value that can be obtained by considering the first `i` items and a knapsack with capacity `w`.
2. **Initialization**: If there are no items or if the knapsack capacity is 0, the maximum value is 0. So, `dp[0][w] = 0` and `dp[i][0] = 0`.
3. **Filling the DP table**: For each item `i` (from 1 to `n`) and each capacity `w` (from 0 to `W`):
   - If the weight of the current item `weight[i-1]` is less than or equal to `w`, we have two options:
     - **Include the item**: Add its value to the solution and reduce the remaining capacity.
     - **Exclude the item**: Keep the solution without adding the item.
   - The value `dp[i][w]` is the maximum of these two options.
4. **Final Answer**: The value in `dp[n][W]` will contain the maximum value we can achieve with the given knapsack capacity.

### Example Walkthrough:

Consider the following example:

**Items:**
1. Item 1: Value = 60, Weight = 10
2. Item 2: Value = 100, Weight = 20
3. Item 3: Value = 120, Weight = 30

**Knapsack Capacity (W) = 50**

### Steps to Solve Using Dynamic Programming:

#### Step 1: Initialize the DP table
We create a DP table `dp[i][w]`, where `i` represents the number of items considered (from 0 to `n`), and `w` represents the knapsack capacity (from 0 to `W`).

Initially, we fill the DP table with 0, as with 0 items or a knapsack capacity of 0, the value is 0.

| Item/Capacity | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |
|----------------|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| **Item 0**     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 |

#### Step 2: Fill in the DP table

Now we fill the table row by row, where each row corresponds to an item and each column corresponds to a possible knapsack capacity.

- **Item 1 (Value = 60, Weight = 10)**:
  - For weights from 0 to 9, we can't include Item 1 because its weight exceeds the current capacity.
  - For weights from 10 to 50, we include Item 1 because its weight is less than or equal to the current capacity, and the value is 60.

| Item/Capacity | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |
|----------------|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| **Item 1**     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 |

- **Item 2 (Value = 100, Weight = 20)**:
  - For weights from 0 to 19, we can't include Item 2 because its weight exceeds the current capacity.
  - For weights from 20 to 50, we can either include Item 2 or exclude it. The maximum value is:
    - **Include Item 2**: Value = 100 + `dp[1][w - 20]`
    - **Exclude Item 2**: Value = `dp[1][w]`

| Item/Capacity | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |
|----------------|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| **Item 2**     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 100| 100| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160|

- **Item 3 (Value = 120, Weight = 30)**:
  - For weights from 0 to 29, we can't include Item 3.
  - For weights from 30 to 50, we can either include Item 3 or exclude it. The maximum value is:
    - **Include Item 3**: Value = 120 + `dp[2][w - 30]`
    - **Exclude Item 3**: Value = `dp[2][w]`

| Item/Capacity | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |
|----------------|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| **Item 3**     | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 0  | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 60 | 100| 100| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 160| 180| 180| 180| 180| 180| 180| 180| 180|

#### Final Result:
The maximum value that can be achieved with the given items and knapsack capacity is **180**, which is stored in `dp[3][50]`.

#### Explanation:
- Items 2 and 3 are included in the optimal solution because they provide the maximum value without exceeding the knapsack's weight capacity.

This example illustrates how the dynamic programming table is filled step by step to solve the problem. The final answer is found in the bottom-right cell of the table, which contains the maximum value achievable given the items and knapsack capacity.

### Time and Space Complexity:
- **Time Complexity**: `O(n * W)`, where `n` is the number of items and `W` is the knapsack capacity. We iterate through each item and for each item, we iterate through the capacities from `0` to `W`.
- **Space Complexity**: `O(n * W)` for the DP table. This can be optimized to `O(W)` by using a 1D array instead of a 2D table.

---

## Recursive Approach (caused TLE)
The Knapsack Problem is a classic problem in computer science where we are given a set of items, each with a weight and a value, and a knapsack with a limited capacity. Our goal is to determine the maximum value that can be obtained by selecting a subset of items without exceeding the knapsack's capacity.

The **recursive approach** for solving this problem involves the following steps:
1. At each step, we have two choices:
   - **Include the current item**: If the current item's weight is less than or equal to the remaining capacity of the knapsack, we include it. We then reduce the capacity of the knapsack and solve the remaining problem for the remaining items.
   - **Exclude the current item**: We exclude the current item and solve the remaining problem for the remaining items, keeping the same capacity.
2. The base case occurs when we reach the first item (index 0). At this point, we check if the first item's weight is less than or equal to the knapsack's remaining capacity. If yes, we include it; otherwise, we exclude it.

### **Recursive Logic Step-by-Step (Example)**

#### Example:
- Items: 
  - Item 1: weight = 2, value = 3
  - Item 2: weight = 3, value = 4
  - Item 3: weight = 4, value = 5
- Knapsack capacity = 5

#### Recursive Decisions:
1. At the first level (index 2, Item 3 with weight 4 and value 5):
   - **Include Item 3**: The capacity will reduce from 5 to 1. Now, we solve the problem for items 1 and 2 with capacity 1.
   - **Exclude Item 3**: We solve the problem for items 1 and 2 with capacity 5.
   
2. The decision tree continues for items 1 and 2. Ultimately, the function recursively calculates the best combination of items.

### Source Code
```cpp
class Solution {
  public:
    // Recursive function to solve the knapsack problem
    int solve(int capacity, vector<int> &value, vector<int> &weight, int index){
        
        // Base case: If we are at the first item (index 0)
        if(index == 0){
            // If the weight of the first item is less than or equal to the remaining capacity, return its value
            if(weight[0] <= capacity) return value[0];
            // Otherwise, return 0 because we cannot include this item in the knapsack
            else return 0;
        }
        
        // Variable to store the value if we include the current item
        int include = 0;
        // Check if the current item's weight is less than or equal to the remaining capacity
        if(weight[index] <= capacity) {
            // If we include the current item, reduce the capacity by the item's weight, and add its value
            // Recursively solve the remaining problem (remaining capacity and items)
            include = solve(capacity - weight[index], value, weight, index-1) + value[index];
        }
        
        // Variable to store the value if we exclude the current item
        int exclude = 0;
        // If we exclude the current item, just solve the problem with the remaining items and the same capacity
        exclude = solve(capacity, value, weight, index-1);
        
        // Return the maximum of the two values: including the item or excluding the item
        return max(include, exclude);
    }
    
    // Function to initialize and call the recursive function to solve the knapsack problem
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        int n = wt.size();  // Get the number of items
        // Start the recursive function with the full capacity and all items (index n-1)
        return solve(capacity, val, wt, n-1);
    }
};
```

### Source Code Explanation

#### Function `solve`:

```cpp
int solve(int capacity, vector<int> &value, vector<int> &weight, int index)
```
This is a recursive function where:
- `capacity`: Current capacity of the knapsack.
- `value`: A vector containing the values of the items.
- `weight`: A vector containing the weights of the items.
- `index`: The current index of the item under consideration.

#### Base Case (index == 0):
```cpp
if(index == 0){
    if(weight[0] <= capacity) return value[0];
    else return 0;
}
```
- **Base Case**: If the current item is the first item (index 0), we check if the item's weight is less than or equal to the remaining capacity.
  - If yes, we include it by returning its value (`value[0]`).
  - If no, we cannot include it, so we return 0.

#### Include the Current Item:
```cpp
int include = 0;
if(weight[index] <= capacity) {
    include = solve(capacity - weight[index], value, weight, index-1) + value[index];
}
```
- **Include Item**: If the current item can fit into the knapsack (its weight is less than or equal to the remaining capacity), we recursively solve the problem for the remaining capacity (`capacity - weight[index]`) and the remaining items (`index-1`).
- Add the value of the current item (`value[index]`) to the result.

#### Exclude the Current Item:
```cpp
int exclude = 0;
exclude = solve(capacity, value, weight, index-1);
```
- **Exclude Item**: If we exclude the current item, the capacity remains the same, but we reduce the problem size by considering the remaining items (`index-1`).

#### Return Maximum of Both Choices:
```cpp
return max(include, exclude);
```
- We return the maximum value between including and excluding the current item.

### **Main Function `knapSack`**:

```cpp
int knapSack(int capacity, vector<int> &val, vector<int> &wt)
```
This function is the entry point. It initializes the recursive function by passing the full capacity and all items (`index = n-1` where `n` is the number of items).

```cpp
int n = wt.size();
return solve(capacity, val, wt, n-1);
```
Here:
- We calculate the number of items (`n`).
- Then, we call the recursive function `solve` to find the optimal solution starting with all items and the full capacity.

### **Example Walkthrough**

For the example with the knapsack capacity of 5 and items:
- Item 1: weight = 2, value = 3
- Item 2: weight = 3, value = 4
- Item 3: weight = 4, value = 5

The recursive function will explore two choices at each step (including or excluding each item). Here's the decision process:
- At index 2 (Item 3), the recursive function tries both including and excluding Item 3.
- If we include Item 3, we have a remaining capacity of 1 and consider Item 1 and Item 2.
- If we exclude Item 3, we have the full capacity of 5 and consider Items 1 and 2.

The function will calculate the optimal value and return the maximum value that can be achieved.

### **Time Complexity**

The time complexity of this recursive approach is **O(2^n)**. This is because, at each item, we make two recursive calls (one for including the item and one for excluding it), resulting in an exponential growth of the number of calls.

- **Why O(2^n)**: In the worst case, every item can either be included or excluded, leading to 2^n different combinations of items to explore.

### **Space Complexity**

The space complexity is **O(n)** because the maximum depth of the recursion tree is `n`, where `n` is the number of items. This is the amount of space used by the recursion stack.

### **Optimization: Dynamic Programming**

The recursive approach has exponential time complexity because it recalculates the same subproblems multiple times. This can be optimized using **Dynamic Programming (DP)** by storing the results of subproblems (memoization or tabulation). This reduces the time complexity to **O(n * capacity)**, where `n` is the number of items and `capacity` is the knapsack's capacity.

### **Summary**
- The recursive approach solves the knapsack problem by recursively considering whether to include or exclude each item.
- The solution uses a divide-and-conquer strategy, breaking down the problem into smaller subproblems.
- The time complexity of the recursive approach is O(2^n), which can be optimized using dynamic programming.

---

## Top-Down Approach (DP)
The **Top-Down Approach with Memoization** improves the standard recursive solution by storing the results of subproblems in a table (2D array in this case). This prevents redundant calculations and significantly reduces the time complexity by avoiding repeated recalculations of the same subproblems.

In this approach, the function uses recursion to break the problem down and store the results of each subproblem in a memoization table (`dp`). If a subproblem is encountered again, the result is retrieved directly from the `dp` table, which saves computation time.

### **Recursive Function Logic (Step-by-Step)**

1. **Base Case**: If we reach the first item (`index == 0`), we check if the first item's weight is less than or equal to the current knapsack capacity.
   - If yes, we return the value of the first item (`value[0]`).
   - If no, we cannot include the first item, so we return 0.

2. **Memoization Check**: Before recalculating the value for the current subproblem (defined by the `index` and `capacity`), we check if the result is already stored in the `dp` table.
   - If the value is already computed (i.e., `dp[index][capacity] != -1`), we return the stored result.

3. **Include or Exclude Item**: For each item at `index`:
   - **Include Item**: If the item's weight is less than or equal to the current capacity, we solve the subproblem for the remaining capacity (`capacity - weight[index]`) and the remaining items (`index - 1`), then add the value of the current item.
   - **Exclude Item**: We solve the subproblem for the remaining items with the same capacity (`index - 1`).

4. **Memoization Table Update**: After solving the subproblem, we store the result in the `dp` table (`dp[index][capacity] = max(include, exclude)`).

5. **Return the Result**: The final result is stored in the `dp` table for the current subproblem, and we return this value.

### Source Code
```cpp
class Solution {
  public:
    // Recursive function with memoization to solve the knapsack problem
    int solve(int capacity, vector<int> &value, vector<int> &weight, int index, vector<vector<int>>& dp){
        
        // Base case: If we are at the first item (index 0)
        if(index == 0){
            // If the weight of the first item is less than or equal to the remaining capacity, return its value
            if(weight[0] <= capacity) return value[0];
            // Otherwise, return 0 because we cannot include this item in the knapsack
            else return 0;
        }
        
        // If the solution for the current subproblem (index and capacity) has already been computed, return the result from dp table
        if(dp[index][capacity] != -1) return dp[index][capacity];
        
        // Variable to store the value if we include the current item
        int include = 0;
        // Check if the current item's weight is less than or equal to the remaining capacity
        if(weight[index] <= capacity) {
            // If we include the current item, reduce the capacity by the item's weight, and add its value
            // Recursively solve the remaining problem (remaining capacity and items)
            include = solve(capacity - weight[index], value, weight, index-1, dp) + value[index];
        }
        
        // Variable to store the value if we exclude the current item
        int exclude = 0;
        // If we exclude the current item, just solve the problem with the remaining items and the same capacity
        exclude = solve(capacity, value, weight, index-1, dp);
        
        // Store the result in the dp table and return the maximum of the two values: including or excluding the item
        dp[index][capacity] = max(include, exclude);
        
        return dp[index][capacity];
    }
    
    // Function to initialize and call the recursive function to solve the knapsack problem
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        int n = wt.size();  // Get the number of items
        
        // Create a memoization table (dp) to store solutions of subproblems
        // dp[i][j] will store the maximum value that can be obtained with the first i items and a knapsack capacity of j
        vector<vector<int>> dp(n+1, vector<int>(capacity + 1, -1));
        
        // Start the recursive function with the full capacity and all items (index n-1)
        return solve(capacity, val, wt, n-1, dp);
    }
};
```

### Source Code Explanation

#### Function `solve`:

```cpp
int solve(int capacity, vector<int> &value, vector<int> &weight, int index, vector<vector<int>>& dp)
```
This is the recursive function with memoization:
- `capacity`: Current capacity of the knapsack.
- `value`: A vector containing the values of the items.
- `weight`: A vector containing the weights of the items.
- `index`: The current item under consideration.
- `dp`: A 2D array that stores the result of each subproblem.

#### Base Case (index == 0):
```cpp
if(index == 0){
    if(weight[0] <= capacity) return value[0];
    else return 0;
}
```
- **Base Case**: If we're at the first item (`index == 0`), we check if the weight of this item fits within the remaining capacity. If it does, we return its value; otherwise, return 0.

#### Memoization Check:
```cpp
if(dp[index][capacity] != -1) return dp[index][capacity];
```
- **Memoization**: Before solving a subproblem, we check if its solution has already been computed and stored in the `dp` table. If it is, we return the stored value to avoid redundant calculations.

#### Include the Current Item:
```cpp
int include = 0;
if(weight[index] <= capacity) {
    include = solve(capacity - weight[index], value, weight, index-1, dp) + value[index];
}
```
- **Include Item**: If the current item fits in the knapsack (its weight is less than or equal to the capacity), we recursively solve the subproblem for the remaining items and capacity, and add the value of the current item.

#### Exclude the Current Item:
```cpp
int exclude = 0;
exclude = solve(capacity, value, weight, index-1, dp);
```
- **Exclude Item**: If we exclude the current item, we simply solve the subproblem with the same capacity and one fewer item.

#### Store the Result in `dp`:
```cpp
dp[index][capacity] = max(include, exclude);
```
- **Memoization Update**: After computing both include and exclude scenarios, we store the maximum of the two results in the `dp` table for the current subproblem.

#### Return the Result:
```cpp
return dp[index][capacity];
```
- We return the stored result for the current subproblem.

### **Main Function `knapSack`**:

```cpp
int knapSack(int capacity, vector<int> &val, vector<int> &wt)
```
This function initializes the memoization table and calls the recursive function `solve`:
- `n`: The number of items.
- `dp`: A 2D array initialized to `-1`, where `dp[i][j]` stores the maximum value for the first `i` items and a knapsack capacity of `j`.

```cpp
vector<vector<int>> dp(n+1, vector<int>(capacity + 1, -1));
```
- We create a memoization table `dp` of size `(n+1) x (capacity+1)`. The table is initialized with `-1` to signify that no subproblem has been solved yet.

```cpp
return solve(capacity, val, wt, n-1, dp);
```
- We call the `solve` function to calculate the maximum value starting with the full capacity and all items.

### **Time Complexity**

The time complexity of the **Top-Down Approach with Memoization** is **O(n * capacity)**, where:
- `n` is the number of items.
- `capacity` is the maximum capacity of the knapsack.

This is because:
- Each subproblem is solved once, and the subproblems are indexed by `index` (number of items) and `capacity`. So, the total number of subproblems is `n * capacity`.
- Each subproblem is solved in constant time.

Thus, the overall time complexity is **O(n * capacity)**.

### **Space Complexity**

The space complexity is also **O(n * capacity)**, where:
- The memoization table `dp` requires space for `n + 1` rows and `capacity + 1` columns, resulting in **O(n * capacity)** space.

Additionally, there is space used by the recursion stack, which has a maximum depth of `n` (the number of items), so the recursion stack adds **O(n)** space.

Thus, the overall space complexity is **O(n * capacity)**.

### **How to Detect if a Problem is Solved with 2D Array in Memoization?**

- **2D Memoization**: The problem is solved using a 2D array if the subproblems involve two dimensions (such as `index` and `capacity`). In this case:
  - `dp[i][j]` is used to store the result of the subproblem where `i` is the current item index and `j` is the remaining capacity.
  - A 1D array would be insufficient to store the results of subproblems that depend on both `index` and `capacity`.

- **Detecting 2D Memoization**: If you see a 2D array (like `vector<vector<int>> dp`) and the function is using both dimensions to store results (`dp[index][capacity]`), it indicates that the problem is solved using a 2D memoization technique.

### **Example Walkthrough**

For the example with the knapsack capacity of 5 and items:
- Item 1: weight = 2, value = 3
- Item 2: weight = 3, value = 4
- Item 3: weight = 4, value = 5

The function will explore both including and excluding each item, and memoize the results to avoid redundant calculations. The `dp` table will store the results of all subproblems and eventually return the optimal value.

### **Summary**
- The Top-Down approach with memoization reduces redundant calculations by storing the results of subproblems in a 2D array (`dp`).
- The time and space complexity is **O(n * capacity)** due to the memoization table and recursive calls.
- You can detect the use of a 2D array in memoization when the solution involves two dimensions, such as item index and capacity.

---

## Bottom-Up Approach (DP)
The **0/1 Knapsack Problem** is a classical dynamic programming problem. We are given a knapsack with a fixed capacity and a list of items, each with a weight and a value. Our task is to determine the maximum value that can be obtained by including a subset of items such that the total weight does not exceed the knapsack's capacity.

The **Bottom-Up Dynamic Programming (DP)** approach builds the solution iteratively by solving smaller subproblems and combining them to solve the original problem.

#### **Steps to Approach:**
1. **Define a DP Table:**
   - Let `dp[i][w]` represent the maximum value we can obtain with the first `i` items and a knapsack of capacity `w`.
   
2. **Base Case:**
   - When `i = 0` (i.e., no items), or `w = 0` (i.e., knapsack capacity is 0), the maximum value is 0, because no items can be included or the knapsack cannot hold any weight.
   - `dp[0][w] = 0` for all `w` (no items, so no value).
   - `dp[i][0] = 0` for all `i` (knapsack capacity 0, so no value can be carried).

3. **Recurrence Relation:**
   For each item `i` and capacity `w`:
   - If the weight of the current item `weight[i]` is less than or equal to `w`, we have two choices:
     - **Include the item**: Add its value and reduce the capacity of the knapsack by `weight[i]`.
     - **Exclude the item**: Just carry forward the value from the previous row (`dp[i-1][w]`).
   - Therefore, `dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w - weight[i]])`.

4. **Result:**
   - The final answer will be found in `dp[n][capacity]`, where `n` is the total number of items and `capacity` is the maximum capacity of the knapsack.

#### **Example:**
Let’s consider a knapsack with a capacity of `5` and 3 items:

- **Items**:
  1. Item 1: weight = 2, value = 3
  2. Item 2: weight = 3, value = 4
  3. Item 3: weight = 4, value = 5

- **Knapsack Capacity**: `5`

We will fill a DP table where `dp[i][w]` represents the maximum value achievable with the first `i` items and a knapsack capacity `w`.

### Source Code
```cpp
class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Number of items
        
        // DP table to store the maximum value for each subproblem (capacity, number of items)
        // dp[i][w] will store the maximum value with the first i items and a knapsack capacity of w
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        
        // Initialize the first row of the DP table (only for the first item)
        // We fill the DP table by checking if the current item can be included in the knapsack
        for(int w = weight[0]; w <= capacity; w++){
            dp[0][w] = (weight[0] <= w) ? value[0] : 0;  // If the first item's weight is less than or equal to the capacity, include its value
        }
        
        // Fill the rest of the DP table for all the other items (i > 0)
        for(int i = 1; i < n; i++){
            for(int w = 0; w <= capacity; w++){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // If the current item can fit in the knapsack
                    include = value[i] + dp[i-1][w - weight[i]];  // Add its value and reduce the capacity accordingly
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = dp[i-1][w];  // Simply carry forward the value from the previous row, without including the item
                
                // Store the maximum value of including or excluding the current item
                dp[i][w] = max(include, exclude);
            }
        }
        
        // The answer will be in dp[n-1][capacity], which contains the maximum value with all items and the given capacity
        return dp[n - 1][capacity];
    }
    
    // Wrapper function that calls the solve function
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
```

### Source Code Explanation

Now, let's dive into the code and explain it line by line:

```cpp
class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Number of items
```
- **Line 1**: This is the start of the `Solution` class.
- **Line 2**: We define the function `solve` that takes the capacity of the knapsack and vectors representing the values and weights of the items.
- **Line 3**: `n` is the number of items, which is derived from the size of the `weight` vector (since the length of `value` and `weight` is the same).

```cpp
        // DP table to store the maximum value for each subproblem (capacity, number of items)
        // dp[i][w] will store the maximum value with the first i items and a knapsack capacity of w
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
```
- **Line 4**: Here, we initialize a 2D DP table `dp` with `n` rows (one for each item) and `capacity + 1` columns (for each weight from `0` to `capacity`). Initially, all values in the table are set to `0`.

```cpp
        // Initialize the first row of the DP table (only for the first item)
        // We fill the DP table by checking if the current item can be included in the knapsack
        for(int w = weight[0]; w <= capacity; w++){
            dp[0][w] = (weight[0] <= w) ? value[0] : 0;  // If the first item's weight is less than or equal to the capacity, include its value
        }
```
- **Line 6**: This loop initializes the first row of the DP table, which corresponds to the first item.
- **Line 7**: For each weight `w` from the weight of the first item to the capacity, we check if the first item's weight is less than or equal to the capacity `w`. If yes, we include its value; otherwise, the value is `0`.

```cpp
        // Fill the rest of the DP table for all the other items (i > 0)
        for(int i = 1; i < n; i++){
            for(int w = 0; w <= capacity; w++){
```
- **Line 9-10**: These loops iterate over all items `i` (starting from 1) and for each capacity `w` from 0 to `capacity`. We are filling the rest of the DP table.

```cpp
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // If the current item can fit in the knapsack
                    include = value[i] + dp[i-1][w - weight[i]];  // Add its value and reduce the capacity accordingly
                }
```
- **Line 12-14**: We first check if the current item `i` can fit into the knapsack (i.e., if `weight[i] <= w`).
- **Line 13**: If it fits, we calculate the value by including this item. The value is the item's value (`value[i]`) plus the maximum value achievable with the remaining capacity (`w - weight[i]`).

```cpp
                // Case 2: Excluding the current item (i)
                int exclude = dp[i-1][w];  // Simply carry forward the value from the previous row, without including the item
```
- **Line 16**: If the current item is excluded, the value remains the same as the previous item’s value for the same capacity (`dp[i-1][w]`).

```cpp
                // Store the maximum value of including or excluding the current item
                dp[i][w] = max(include, exclude);
            }
        }
```
- **Line 18**: We store the maximum value between including and excluding the current item in the DP table at `dp[i][w]`.

```cpp
        // The answer will be in dp[n-1][capacity], which contains the maximum value with all items and the given capacity
        return dp[n - 1][capacity];
    }
```
- **Line 20-22**: The answer is found in `dp[n-1][capacity]`, which represents the maximum value that can be achieved with all items and the given knapsack capacity.

```cpp
    // Wrapper function that calls the solve function
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
```
- **Line 24-26**: This is a wrapper function `knapSack` that calls the `solve` function. It's just a more user-friendly way to use the solution.

### **Time and Space Complexity**

#### **Time Complexity:**
- The time complexity is **O(n * W)**, where `n` is the number of items and `W` is the capacity of the knapsack.
  - For each item (`n` iterations), we iterate through all possible capacities from `0` to `W` (`W` iterations).
  
#### **Space Complexity:**
- The space complexity is **O(n * W)** because we use a 2D DP table of size `n * (W + 1)`. This table stores the maximum value for each subproblem.

### **Example:**

For items:
- Item 1: weight = 2, value = 3
- Item 2: weight = 3, value = 4
- Item 3: weight = 4, value = 5

And a knapsack capacity of `5`:

- We would fill the DP table step-by-step, and the final result (`dp[3][5]`) would give the maximum value that can be achieved with a capacity of `5`, which is `7` (including Item 2 and Item 3).

---

## 1) Space Optimized Approach (DP)
The given code solves the 0/1 Knapsack problem using dynamic programming with an optimized approach to reduce the space complexity. In this approach, instead of using a 2D array, we use only two 1D arrays (one for the previous row and one for the current row), which significantly reduces memory usage.

### Step-by-Step Explanation of the Approach with a Simple Example

Let's break down the space-optimized approach with an example:

#### Problem:
Given:
- Capacity of the knapsack = 5
- Weights = [1, 2, 3, 8]
- Values = [20, 5, 10, 40]

The goal is to find the maximum value we can fit in the knapsack without exceeding the capacity.

#### Step 1: Initialize the DP arrays
We use two 1D arrays, `prev[]` and `curr[]`, both of size `capacity + 1`. These arrays store the maximum values at each capacity for the current and previous items.

- `prev[]` stores the maximum values for the previous row (previous item).
- `curr[]` stores the maximum values for the current row (current item).

#### Step 2: Initialize for the first item
For the first item (value = 20, weight = 1), we check if the weight fits in the knapsack for each capacity. If it does, we store the value of the item in `prev[]` (otherwise, it's 0).

#### Step 3: Process the remaining items
For each subsequent item:
1. We calculate two possibilities:
   - **Include the item**: If the item fits, we add its value to the best possible value from the previous row with the reduced capacity.
   - **Exclude the item**: We take the value from the previous row for the same capacity.

2. We update `curr[]` with the maximum of the two possibilities for each capacity.

#### Step 4: Move `curr[]` to `prev[]`
After processing each item, we move `curr[]` to `prev[]` so that it can be used in the next iteration.

#### Step 5: Result
After all items are processed, the value in `curr[capacity]` gives the maximum value we can fit into the knapsack.

### Source Code
```cpp
class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Get the number of items
        
        // We only need two rows at a time (previous and current), so we create two 1D arrays:
        // prev[] will store the maximum values for the previous item, 
        // curr[] will store the maximum values for the current item.
        vector<int> prev(capacity + 1, 0);
        vector<int> curr(capacity + 1, 0);
        
        // Initialize the first row of the DP table for the first item.
        // If the weight of the first item is less than or equal to the current capacity,
        // we store its value in the prev[] array (otherwise 0).
        for(int w = 0; w <= capacity; w++) {
            prev[w] = (weight[0] <= w) ? value[0] : 0; // If the first item's weight <= w, include its value
        }
        
        // Process the remaining items (i from 1 to n-1)
        for(int i = 1; i < n; i++){
            // For each capacity from 0 to the given capacity
            for(int w = 0; w <= capacity; w++){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // Check if the current item's weight can fit in the knapsack
                    include = value[i] + prev[w - weight[i]]; // Add the value of the current item and reduce the capacity
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = prev[w];  // Simply carry forward the value from the previous row without including the item
                
                // Store the maximum value of including or excluding the current item
                curr[w] = max(include, exclude);
            }
            
            // After processing the current item, move curr[] to prev[] to use it in the next iteration
            prev = curr;
        }
        
        // The answer will be in curr[capacity], which contains the maximum value with all items considered
        return curr[capacity];
    }
    
    // Wrapper function that calls the solve function with the given capacity, values, and weights
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};

```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Get the number of items
        
        // We only need two rows at a time (previous and current), so we create two 1D arrays:
        vector<int> prev(capacity + 1, 0);  // Stores results of the previous item
        vector<int> curr(capacity + 1, 0);  // Stores results of the current item
```
- Here, we initialize two arrays `prev[]` and `curr[]` of size `capacity + 1`. Both arrays are initially filled with 0 because with a knapsack capacity of 0, no items can be included, so the value is 0.


```cpp
        // Initialize the first row of the DP table for the first item.
        // If the weight of the first item is less than or equal to the current capacity,
        // we store its value in the prev[] array (otherwise 0).
        for(int w = 0; w <= capacity; w++) {
            prev[w] = (weight[0] <= w) ? value[0] : 0; // If the first item's weight <= w, include its value
        }
```
- This loop initializes the first row, corresponding to the first item. If the weight of the first item is less than or equal to the current capacity, we set the value in `prev[]` to the value of the first item. If not, the value is 0.


```cpp
        // Process the remaining items (i from 1 to n-1)
        for(int i = 1; i < n; i++){
            // For each capacity from 0 to the given capacity
            for(int w = 0; w <= capacity; w++){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // Check if the current item's weight can fit in the knapsack
                    include = value[i] + prev[w - weight[i]]; // Add the value of the current item and reduce the capacity
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = prev[w];  // Simply carry forward the value from the previous row without including the item
                
                // Store the maximum value of including or excluding the current item
                curr[w] = max(include, exclude);
            }
            
            // After processing the current item, move curr[] to prev[] to use it in the next iteration
            prev = curr;
        }
```
- In the outer loop, we iterate through all items (`i` from 1 to `n-1`).
- In the inner loop, we iterate through all possible capacities (`w` from 0 to `capacity`).
- We calculate two possibilities for each capacity:
  1. **Including the current item**: If the weight of the current item can fit, we calculate the new value as the sum of the current item's value and the best value from the previous row (`prev[w - weight[i]]`).
  2. **Excluding the current item**: We simply take the value from `prev[w]`, which is the best value without including the current item.
  
- After processing each item, we move `curr[]` to `prev[]`, so `prev[]` will be used for the next iteration.


```cpp
        // The answer will be in curr[capacity], which contains the maximum value with all items considered
        return curr[capacity];
    }
    
    // Wrapper function that calls the solve function with the given capacity, values, and weights
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
```
- After all iterations, the final result, which is the maximum value we can achieve with the given capacity, is stored in `curr[capacity]`.
- The `knapSack()` function is a wrapper that calls the `solve()` function.


### Example with Explanation

Given:
- Capacity = 5
- Weights = [1, 2, 3, 8]
- Values = [20, 5, 10, 40]

**Initialization**:
- `prev[]` and `curr[]` are initialized to 0.

**Processing the first item** (weight = 1, value = 20):
- For each capacity `w`, if `w >= 1`, `prev[w] = 20`. Otherwise, it remains 0.

**Processing the second item** (weight = 2, value = 5):
- For each capacity `w`, we check the two cases:
  - If we include the item, the new value is `prev[w - 2] + 5`.
  - If we exclude it, we carry forward the value from `prev[w]`.

**Continue for all items** until we reach the last item.

### Time and Space Complexity

#### Time Complexity:
- **Time complexity**: O(n * capacity)
  - We loop through each item (`n` items) and for each item, we loop through all possible capacities (from 0 to `capacity`).
  
#### Space Complexity:
- **Space complexity**: O(capacity)
  - We use two 1D arrays of size `capacity + 1`, which reduces the space from O(n * capacity) to O(capacity).

This space-optimized approach significantly reduces memory usage while keeping the time complexity the same as the original 2D DP approach.

---

## 2) Space Optimized Approach (DP)

Approach 2 optimizes the space usage of the dynamic programming solution to the **0/1 Knapsack Problem**. While Approach 1 uses two 2D arrays (which takes `O(n * W)` space), Approach 2 reduces this to a single 1D array (`curr[]`), which only needs `O(W)` space. This optimization focuses on reducing memory usage while maintaining the same time complexity.

### Source Code
```cpp
class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Get the number of items
        
        // Create a 1D array `curr[]` to store the maximum value for each weight capacity from 0 to the given capacity.
        // It will store the result of the current item.
        vector<int> curr(capacity + 1, 0); 
        
        // Initialize the first row of the DP table for the first item.
        // If the weight of the first item is less than or equal to the current capacity,
        // we store its value in the `curr[]` array (otherwise 0).
        for(int w = 0; w <= capacity; w++) {
            curr[w] = (weight[0] <= w) ? value[0] : 0; // If the first item's weight <= w, include its value
        }
        
        // Process the remaining items (i from 1 to n-1)
        for(int i = 1; i < n; i++){
            // For each capacity from the given weight to 0 (iterating backwards)
            // This prevents overwriting results of the current item during the same iteration
            for(int w = capacity; w >= 0; w--){
                
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // Check if the current item's weight can fit in the knapsack
                    include = value[i] + curr[w - weight[i]]; // Add the value of the current item and reduce the capacity
                }
                
                // Case 2: Excluding the current item (i)
                int exclude = curr[w];  // Simply carry forward the value from the previous item (same weight)
                
                // Store the maximum value of including or excluding the current item
                curr[w] = max(include, exclude);  // The optimal solution for this capacity is the best of both cases
            }
        }
        
        // The final answer is in `curr[capacity]`, which contains the maximum value achievable with the given capacity
        return curr[capacity];
    }
    
    // Wrapper function that calls the solve function with the given capacity, values, and weights
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        return solve(capacity, val, wt);  // Return the result from the solve function
    }
};
```

### Source Code Explanation
```cpp
class Solution {
  public:
    // Function to solve the 0/1 Knapsack problem using dynamic programming
    int solve(int capacity, vector<int> &value, vector<int> &weight){
        int n = weight.size();  // Get the number of items
```
- **`n = weight.size()`**: This line stores the number of items in the `n` variable. The size of the `weight` vector indicates the number of items available.
- Example: If `weight = [1, 3, 4, 5]`, then `n = 4` because there are 4 items.

```cpp
        // Create a 1D array `curr[]` to store the maximum value for each weight capacity from 0 to the given capacity.
        // It will store the result of the current item.
        vector<int> curr(capacity + 1, 0); 
```
- **`vector<int> curr(capacity + 1, 0)`**: This creates a 1D array `curr[]` of size `capacity + 1`. Each element of this array represents the maximum value achievable for knapsack capacities from `0` to `capacity`.
- **Initialization**: All elements in the array are initialized to `0` since the maximum value for a capacity of `0` is `0`.
- Example: If `capacity = 7`, `curr` would be initialized to `[0, 0, 0, 0, 0, 0, 0, 0]`.

```cpp
        // Initialize the first row of the DP table for the first item.
        // If the weight of the first item is less than or equal to the current capacity,
        // we store its value in the `curr[]` array (otherwise 0).
        for(int w = 0; w <= capacity; w++) {
            curr[w] = (weight[0] <= w) ? value[0] : 0; // If the first item's weight <= w, include its value
        }
```
- **`for(int w = 0; w <= capacity; w++)`**: This loop initializes the `curr[]` array for the first item. For each possible weight `w` from `0` to `capacity`, it checks whether the weight of the first item (`weight[0]`) is less than or equal to `w`. If it is, it includes the value of the first item (`value[0]`) in the knapsack. Otherwise, it sets `curr[w]` to `0`.
- **Example**: If the first item has weight 1 and value 1, for a knapsack with capacity 7, the array will be `[0, 1, 1, 1, 1, 1, 1, 1]` (because we can include the first item if `w >= 1`).

```cpp
        // Process the remaining items (i from 1 to n-1)
        for(int i = 1; i < n; i++){
            // For each capacity from the given weight to 0 (iterating backwards)
            // This prevents overwriting results of the current item during the same iteration
            for(int w = capacity; w >= 0; w--){
```
- **`for(int i = 1; i < n; i++)`**: This loop processes all the remaining items starting from the second item (since the first item is already processed).
- **`for(int w = capacity; w >= 0; w--)`**: This loop iterates backward through the capacities from `capacity` down to `0`. This reverse iteration ensures that the results for the current item are not overwritten before they are used.

```cpp
                // Case 1: Including the current item (i)
                int include = 0;
                if(weight[i] <= w) {  // Check if the current item's weight can fit in the knapsack
                    include = value[i] + curr[w - weight[i]]; // Add the value of the current item and reduce the capacity
                }
```
- **`if(weight[i] <= w)`**: Checks if the current item's weight fits into the knapsack with capacity `w`.
- **`include = value[i] + curr[w - weight[i]]`**: If the item can be included, the `include` variable is set to the value of the current item (`value[i]`) plus the value of the remaining capacity (`w - weight[i]`), which is stored in `curr[w - weight[i]]`.

```cpp
                // Case 2: Excluding the current item (i)
                int exclude = curr[w];  // Simply carry forward the value from the previous row without including the item
```
- **`int exclude = curr[w]`**: If the current item is excluded, the value at `curr[w]` (the value from the previous item for this capacity) is carried forward.

```cpp
                // Store the maximum value of including or excluding the current item
                curr[w] = max(include, exclude);  // The optimal solution for this capacity is the best of both cases
            }
        }
```
- **`curr[w] = max(include, exclude)`**: After considering both including and excluding the current item, we store the maximum of the two in `curr[w]`. This ensures we always keep the best possible value for the knapsack capacity `w`.

```cpp
        // The final answer is in `curr[capacity]`, which contains the maximum value achievable with the given capacity
        return curr[capacity];
    }
```
- **`return curr[capacity]`**: After processing all items, the final answer (the maximum value that can be obtained with the given knapsack capacity) is stored in `curr[capacity]`.

### **Example Walkthrough**

Given the following input:
- **Values**: `value = [1, 4, 5, 7]`
- **Weights**: `weight = [1, 3, 4, 5]`
- **Capacity**: `capacity = 7`

1. **Initialization**: 
   - `curr[]` starts as `[0, 0, 0, 0, 0, 0, 0, 0]`.

2. **Processing the First Item** (weight = 1, value = 1):
   - For each `w` from 0 to 7, we update `curr[]` to `[0, 1, 1, 1, 1, 1, 1, 1]` because the first item can be included for capacities ≥ 1.

3. **Processing the Second Item** (weight = 3, value = 4):
   - For each `w` from 7 down to 0, we update `curr[]` by considering both including and excluding the second item.
   - After processing, `curr[]` becomes `[0, 1, 1, 4, 5, 5, 5, 5]`.

4. **Processing the Third Item** (weight = 4, value = 5):
   - Similarly, we update `curr[]` and after processing, `curr[]` becomes `[0, 1, 1, 4, 5, 6, 6, 9]`.

5. **Processing the Fourth Item** (weight = 5, value = 7):
   - After processing all items, `curr[]` becomes `[0, 1, 1, 4, 5, 7, 8, 9]`.

   - The final result is `curr[7] = 9`, which is the maximum value that can be obtained with a knapsack of capacity 7.

### **Approach 2 vs Approach 1**

#### **Space Complexity Comparison**:
- **Approach 1** uses two 2D arrays (`prev[]` and `curr[]`), which results in an overall space complexity of `O(n * W)`.
- **Approach 2** uses only one 1D array (`curr[]`), reducing the space complexity to `O(W)`.

#### **How Approach 2 Works Better**:
- **Space Optimization**: By using a 1D array (`curr[]`) to store the intermediate results of each iteration, Approach 2 reduces the space complexity from `O(n * W)` (in Approach 1) to `O(W)`.
- **Memory Efficiency**: This makes Approach 2 much more memory efficient, especially for problems with large input sizes (many items or large capacity).

#### Problem Example:
- Knapsack capacity: 5
- Items:
  - Item 1: Value = 10, Weight = 1
  - Item 2: Value = 20, Weight = 2
  - Item 3: Value = 30, Weight = 3

#### Step 1: Initialize the DP Array
We use a 1D DP array `curr[]` where `curr[w]` will store the maximum value achievable with a weight limit `w`. The array is initialized to zero.

```cpp
vector<int> curr(capacity + 1, 0);
```
For a capacity of 5, the array `curr[]` will have a size of 6 (i.e., indices from 0 to 5):

**Initial `curr[]`**: `[0, 0, 0, 0, 0, 0]`


#### Step 2: Process the First Item (Value = 10, Weight = 1)

We loop through the array `curr[]` from `w = 0` to `w = 5` and decide whether to include or exclude the first item.

For each capacity `w`:
- **If `weight[0] <= w`** (i.e., if the current item can fit in the knapsack), we check the maximum value:
  ```cpp
  curr[w] = max(curr[w], value[0] + curr[w - weight[0]]);
  ```

- For `w = 0` to `w = 0`, the item cannot fit, so `curr[0] = 0`.
- For `w = 1`, the item fits, so:
  ```cpp
  curr[1] = max(curr[1], 10 + curr[1 - 1]) = max(0, 10 + 0) = 10;
  ```
  **Updated `curr[]`**: `[0, 10, 0, 0, 0, 0]`
- For `w = 2` to `w = 5`, the item fits, so:
  ```cpp
  curr[2] = curr[3] = curr[4] = curr[5] = 10;
  ```
  **Updated `curr[]`**: `[0, 10, 10, 10, 10, 10]`


#### Step 3: Process the Second Item (Value = 20, Weight = 2)

Now, we process the second item. We loop through `w` from `w = 5` to `w = 0` (in reverse order to prevent overwriting results during the same iteration).

- For `w = 5`, the item fits, so:
  ```cpp
  curr[5] = max(curr[5], 20 + curr[5 - 2]) = max(10, 20 + 10) = 30;
  ```
  **Updated `curr[]`**: `[0, 10, 10, 10, 10, 30]`

- For `w = 4`, the item fits, so:
  ```cpp
  curr[4] = max(curr[4], 20 + curr[4 - 2]) = max(10, 20 + 10) = 30;
  ```
  **Updated `curr[]`**: `[0, 10, 10, 10, 30, 30]`

- For `w = 3`, the item fits, so:
  ```cpp
  curr[3] = max(curr[3], 20 + curr[3 - 2]) = max(10, 20 + 10) = 30;
  ```
  **Updated `curr[]`**: `[0, 10, 10, 30, 30, 30]`

- For `w = 2`, the item fits, so:
  ```cpp
  curr[2] = max(curr[2], 20 + curr[2 - 2]) = max(10, 20 + 0) = 20;
  ```
  **Updated `curr[]`**: `[0, 10, 20, 30, 30, 30]`

#### Step 4: Process the Third Item (Value = 30, Weight = 3)

Now, we process the third item. Again, we loop through `w` from `w = 5` to `w = 0` in reverse order.

- For `w = 5`, the item fits, so:
  ```cpp
  curr[5] = max(curr[5], 30 + curr[5 - 3]) = max(30, 30 + 20) = 50;
  ```
  **Updated `curr[]`**: `[0, 10, 20, 30, 30, 50]`

- For `w = 4`, the item fits, so:
  ```cpp
  curr[4] = max(curr[4], 30 + curr[4 - 3]) = max(30, 30 + 10) = 40;
  ```
  **Updated `curr[]`**: `[0, 10, 20, 30, 40, 50]`

- For `w = 3`, the item fits, so:
  ```cpp
  curr[3] = max(curr[3], 30 + curr[3 - 3]) = max(30, 30 + 0) = 30;
  ```
  **Updated `curr[]`**: `[0, 10, 20, 30, 40, 50]`


### Final Step: Get the Result

After processing all the items, the final result will be stored in `curr[capacity]`. In this case, `curr[5] = 50` is the maximum value that can be achieved with a knapsack capacity of 5.

### Example Walkthrough:

| Item | Value | Weight | knapsack capacity 0 | knapsack capacity 1 | knapsack capacity 2 | knapsack capacity 3 | knapsack capacity 4 | knapsack capacity 5 |
|------|-------|--------|---------------------|---------------------|---------------------|---------------------|---------------------|---------------------|
| 1    | 10    | 1      | 0                   | 10                  | 10                  | 10                  | 10                  | 10                  |
| 2    | 20    | 2      | 0                   | 10                  | 20                  | 30                  | 30                  | 30                  |
| 3    | 30    | 3      | 0                   | 10                  | 20                  | 30                  | 40                  | 50                  |

### Conclusion:
The maximum value we can carry in the knapsack of capacity 5 is `50`.

### Advantages of Approach 2 Over Approach 1:

- **Space Optimization**: 
  - Approach 2 uses only one array (`curr[]`) to store the results, reducing space complexity from `O(n * capacity)` in Approach 1 to `O(capacity)`.
  - Approach 1 requires two 2D arrays (`prev[]` and `curr[]`), whereas Approach 2 only requires one.

- **How it Works**:
  - In both approaches, the problem is solved using dynamic programming, but Approach 2 avoids storing results for all previous items. Instead, it only keeps the results for the current item, thereby reducing the space complexity.
  - By iterating backward when processing each item, it ensures that the current item’s result doesn't overwrite the previous results for the same item.
  
#### **Time Complexity**:
- Both approaches have the same time complexity of `O(n * W)` because:
  - **n** is the number of items, and
  - **W** is the knapsack capacity.
  
Each iteration involves processing each item for all possible capacities, leading to `O(n * W)` time complexity.

#### **Space Complexity**:
- **Approach 1**: `O(n * W)` (since two 2D arrays of size `n x W` are used).
- **Approach 2**: `O(W)` (since only one 1D array of size `W + 1` is used).
