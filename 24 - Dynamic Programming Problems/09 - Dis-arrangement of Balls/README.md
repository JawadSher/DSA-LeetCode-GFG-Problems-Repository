<h1 align="center">Dis-arrangement - of Balls</h1>

## Problem Statement

**Problem URL :** [Dis-arrangement of Balls](https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/2a2735e2-18b6-40f1-902a-0d24494011b0)

### Problem Explanation
You are given **n balls** numbered from 1 to n, and n distinct boxes also numbered from 1 to n. The task is to find the number of ways to arrange the balls in the boxes such that **no ball is placed in its corresponding numbered box**. This is known as a **derangement problem**, which is a special case of permutations.

### Key Points of the Problem

1. **Definition of a Dearrangement**:
   - A dearrangement is a permutation of items such that no element appears in its original position.
   - For example:
     - If there are 3 balls and 3 boxes, a valid arrangement is ``2, 3, 1``, where:
       - Ball 1 is in box 2.
       - Ball 2 is in box 3.
       - Ball 3 is in box 1.

2. **Invalid Arrangements**:
   - Any arrangement where a ball is placed in the box with the same number is considered invalid. For example, in a scenario with 3 balls and boxes:
     - ``1, 2, 3`` is invalid because each ball is in its original box.
   
3. **Objective**:
   - Given `n`, you need to find how many valid dearrangements exist where no ball is placed in its corresponding numbered box.

### Understanding Through Examples

#### Example 1: `n = 1`
- Balls: `1`
- Boxes: `1`
- There is only one ball, and it can only go into box 1.
- Since the ball must not be placed in its corresponding box, there are **no valid dearrangements**.
- **Answer: 0**

#### Example 2: `n = 2`
- Balls: `1, 2`
- Boxes: `1, 2`
- There are two balls and two boxes. The possible arrangements are:
  - Ball 1 in box 1, Ball 2 in box 2 (invalid).
  - Ball 1 in box 2, Ball 2 in box 1 (valid).
- Only one valid arrangement is possible where no ball is in its corresponding box.
- **Answer: 1**

#### Example 3: `n = 3`
- Balls: `1, 2, 3`
- Boxes: `1, 2, 3`
- The possible arrangements are:
  - Ball 1 in box 1, Ball 2 in box 2, Ball 3 in box 3 (invalid).
  - Ball 1 in box 2, Ball 2 in box 3, Ball 3 in box 1 (valid).
  - Ball 1 in box 3, Ball 2 in box 1, Ball 3 in box 2 (valid).
  - Ball 1 in box 2, Ball 2 in box 1, Ball 3 in box 3 (invalid).
  - Ball 1 in box 3, Ball 2 in box 2, Ball 3 in box 1 (invalid).
  - Ball 1 in box 1, Ball 2 in box 3, Ball 3 in box 2 (invalid).
- There are **two valid arrangements**:
  - `2, 3, 1` and `3, 1, 2`.
- **Answer: 2**

#### Example 4: `n = 4`
- Balls: `1, 2, 3, 4`
- Boxes: `1, 2, 3, 4`
- The possible arrangements can be calculated based on the formula for derangements, but manually, there are **9 valid arrangements**.

### Derangement Formula

The number of derangements for `n` items, denoted as `D(n)`, can be computed using a recursive formula:

- **Base cases**:
  - (D(1) = 0) (because there is no way to place 1 ball in a box other than its own).
  - (D(2) = 1) (there is exactly one way to swap two balls).
  
- **Recursive formula** for (n >= 3):
  - (D(n) = (n - 1) * (D(n-1) + D(n-2)))
  - This formula arises because:
    - For each ball, you have `n-1` choices for where to place it (not in its corresponding box).
    - Once you place a ball, you can recursively solve for the remaining balls.
   
  Sure! Let’s break down the formula (D(n) = (n-1) * (D(n-1) + D(n-2))) using examples for better understanding.

### Formula Recap:
- (D(n)) represents the number of derangements for `n` items (i.e., how many ways `n` items can be arranged such that no item is in its original position).
- The recursive formula states:
  - (D(n) = (n-1) * (D(n-1) + D(n-2)))
  - The base cases are:
    - (D(1) = 0) (with only 1 item, there is no valid derangement because it must be placed in its original position).
    - (D(2) = 1) (with 2 items, only one valid arrangement exists where each item is swapped).

### Let's go step by step with examples to better understand the formula:

#### Example 1: (D(3))
We want to find the number of derangements for `n = 3` (3 items and 3 boxes).

##### Step 1: Use the formula for (D(3)):
` D(3) = (3-1) * (D(3-1) + D(3-2)) `
` D(3) = 2 * (D(2) + D(1)) `

#### Step 2: Substitute the base case values:
- From the base cases, we know that:
  - (D(2) = 1)
  - (D(1) = 0)
  
So:
` D(3) = 2 * (1 + 0) `
` D(3) = 2 * 1 = 2 `

#### Result:
There are **2 valid derangements** for 3 items. The valid derangements are:
1. Ball 1 goes to box 2, Ball 2 goes to box 3, Ball 3 goes to box 1.
2. Ball 1 goes to box 3, Ball 2 goes to box 1, Ball 3 goes to box 2.

#### Example 2: (D(4))
Now, let’s calculate (D(4)) for 4 items and 4 boxes.

##### Step 1: Use the formula for (D(4)):
` D(4) = (4-1) * (D(4-1) + D(4-2)) `
` D(4) = 3 * (D(3) + D(2)) `

#### Step 2: Substitute the known values:
- From the previous calculation, we know:
  - (D(3) = 2)
  - (D(2) = 1)
  
So:
` D(4) = 3 * (2 + 1) `
` D(4) = 3 * 3 = 9 `

#### Result:
There are **9 valid derangements** for 4 items. These derangements can be found by generating all the permutations of 4 items and excluding the ones where any item is in its original position.

#### Example 3: (D(5))
Now, let’s calculate (D(5)) for 5 items and 5 boxes.

#### Step 1: Use the formula for (D(5)):
` D(5) = (5-1) * (D(5-1) + D(5-2)) `
` D(5) = 4 * (D(4) + D(3)) `

##### Step 2: Substitute the known values:
- From the previous calculations, we know:
  - (D(4) = 9)
  - (D(3) = 2)

So:
`D(5) = 4 * (9 + 2)`
`D(5) = 4 * 11 = 44`

#### Result:
There are **44 valid derangements** for 5 items.


### Recap of the Steps:
1. The formula (D(n) = (n-1) * (D(n-1) + D(n-2))) is used to calculate the number of derangements for `n` items.
2. Start with the base cases:
   - (D(1) = 0)
   - (D(2) = 1)
3. Use the recursive relation to compute derangements for larger values of `n`.

### Conclusion:
The recursive formula allows you to compute derangements for any `n`, using the results of previous calculations. This is a great example of a dynamic programming problem, where you build up the solution step by step using previous results to avoid redundant calculations.

---

## Recursive Approach
The **recursive approach** step by step, explain the given code line by line, and analyze its **time and space complexity**. We will also provide an example and output to ensure everything is clear.

In the **derangement problem**, we are tasked with finding the number of ways to rearrange `n` items such that no item is in its original position. The recursive formula used to calculate the derangement for `n` items is:

`D(n) = (n-1) * (D(n-1) + D(n-2))`

- **Base Cases**:
  - **D(1) = 0**: With 1 item, there is no valid derangement because the only option is to leave the item in its original position.
  - **D(2) = 1**: With 2 items, there is exactly 1 valid derangement where the items swap positions.

- **Recursive Case**:
  - When calculating (D(n), we consider two main possibilities:
    1. **Placing the first item in a position other than its original**: This gives us `(n-1)` options.
    2. **The remaining items**: After placing the first item, there are two possibilities for how the remaining items will be deranged:
        - One case is that the second item goes into the position of the first item and the remaining `n-2` items are deranged. This is represented by `D(n-2)`.
        - Another case is that the second item does not go into the first item's original position. The derangement of the remaining `n-1` items is represented by `D(n-1)`.

Thus, the formula becomes:

`D(n) = (n-1) * (D(n-1) + D(n-2))`


### Source Code

```cpp
class Solution {
public:
    // Function to calculate the number of derangements for n items
    int countDer(int n) {
        // Base case: For n = 1, there is no valid derangement
        if (n == 1) return 0;

        // Base case: For n = 2, there is exactly one valid derangement: {2, 1}
        if (n == 2) return 1;

        // Recursive relation for derangement:
        // totalRelations = (n-1) * (countDer(n-1) + countDer(n-2))
        // Explanation:
        // - (n-1): Choose a position for the first item (other than its original position).
        // - countDer(n-1): Solve the subproblem for the remaining (n-1) items.
        // - countDer(n-2): Solve the subproblem for (n-2) items when swapping is involved.
        int totalRelations = (n-1) * (countDer(n-1) + countDer(n-2));

        // Return the total number of derangements for n items
        return totalRelations;
    }
};
```

### Source Code Explanation
#### 1. **Function Definition**
```cpp
int countDer(int n)
```
This defines a function `countDer` that takes an integer `n` and returns the number of derangements for `n` items.

#### 2. **Base Case: n = 1**
```cpp
if (n == 1) return 0;
```
- When `n = 1`, there is no valid derangement because there’s only one item, and it must remain in its original position.
- So, we return `0` as there are no derangements for a single item.

#### 3. **Base Case: n = 2**
```cpp
if (n == 2) return 1;
```
- When `n = 2`, there is exactly one valid derangement where the two items swap positions. For example, if the items are `[1, 2]`, the valid derangement is `[2, 1]`.
- Hence, we return `1`.

#### 4. **Recursive Case**
```cpp
int totalRelations = (n-1) * (countDer(n-1) + countDer(n-2));
```
- This line calculates the derangement recursively using the formula:
  - The first part, `(n-1)`, represents the number of ways to place the first item in any position other than its original position.
  - `countDer(n-1)` is the number of derangements for the remaining `n-1` items (after placing the first item).
  - `countDer(n-2)` is the number of derangements for `n-2` items when swapping the positions of two specific items.
  
  The total number of derangements is calculated by multiplying `(n-1)` with the sum of derangements for the remaining `n-1` and `n-2` items.

#### 5. **Return the Result**
```cpp
return totalRelations;
```
- Finally, we return the calculated number of derangements for `n` items.

### **Example Walkthrough**

Let’s calculate the derangements for `n = 4` using this approach:

1. (D(4) = (4-1) * (D(3) + D(2))
2. First, calculate (D(3) and (D(2):
    - (D(3) = (3-1) * (D(2) + D(1))
    - (D(2) = 1 (from the base case)
    - (D(1) = 0 (from the base case)
    - So, (D(3) = 2 * (1 + 0) = 2
    - (D(2) = 1 (from the base case)
3. Now, calculate (D(4):
    - (D(4) = 3 * (2 + 1) = 3 * 3 = 9

Thus, the number of derangements for `n = 4` is **9**.

### **Example Output**

```cpp
int n = 4;
Solution sol;
cout << sol.countDer(n); // Output: 9
```

Output:
```
9
```

### **Time Complexity**

- **Recursive Calls**: The function makes two recursive calls: `countDer(n-1)` and `countDer(n-2)`.
- In the worst case, this leads to a lot of redundant calculations. The time complexity for this approach is **O(2^n)** because of the overlapping subproblems (for example, calculating `countDer(n-1)` and `countDer(n-2)` multiple times).

### **Space Complexity**

- The space complexity is **O(n)** because the recursion stack depth is proportional to `n` (due to the recursive calls to `countDer(n-1)` and `countDer(n-2)`).

### **Conclusion**

- This approach works, but it can be inefficient due to the repeated calculation of the same values. To optimize it, dynamic programming or memoization can be used to store previously calculated values and avoid redundant calculations.

---
## Top-Down Approach (DP)
The **top-down approach** for solving problems using **dynamic programming** involves solving the problem recursively while using **memoization** to store intermediate results. This ensures that we do not recompute the same subproblem multiple times, significantly improving efficiency.

#### **How Memoization Works:**
1. **Recursive calls** are made to break the problem down into smaller subproblems.
2. **Base cases** are used to handle the simplest cases directly.
3. **Memoization** ensures that once a subproblem is solved, its result is stored (in a data structure like an array or hash map). This prevents recalculating the result if the same subproblem is encountered again.
4. The final result is obtained by building up solutions to smaller subproblems.


### Source Code
```cpp
class Solution {
  public:
    // Helper function to calculate derangements recursively with memoization
    int solve(int n, vector<int>& dp) {
        // Base case: For n = 1, no valid dearrangements exist
        if(n == 1) return 0;

        // Base case: For n = 2, exactly one valid dearrangement exists
        if(n == 2) return 1;

        // If the result for this value of n has already been computed, return it
        if(dp[n] != -1) return dp[n];

        // Use the recursive relation:
        // D(n) = (n-1) * (D(n-1) + D(n-2))
        dp[n] = (n-1) * (solve(n-1, dp) + solve(n-2, dp));

        // Return the computed result
        return dp[n];
    }

    // Main function to compute derangements of n items
    int countDer(int n) {
        // Create a memoization array initialized with -1
        // dp[i] will store the number of derangements for i items
        vector<int> dp(n+1, -1);

        // Call the helper function to compute the result
        return solve(n, dp);
    }
};
```

### Source Code Explanation
#### **1. solve Function (Recursive Helper)**

This function handles the recursive calculation of the derangements.

```cpp
int solve(int n, vector<int>& dp)
```

- **`n`**: The current number of items for which we need to find the derangement.
- **`dp`**: A vector that stores the derangement results for each value of `n` from 0 to `n`. Initially, all values are set to `-1` to indicate that they haven't been computed yet.

##### **Base Cases:**

```cpp
if (n == 1) return 0;
```
- For `n = 1`, there is no valid derangement (the only item must be in its original position). Hence, the function returns `0`.

```cpp
if (n == 2) return 1;
```
- For `n = 2`, there is exactly one valid derangement: the two items swap places. Therefore, `D(2) = 1`.

##### **Memoization Check:**

```cpp
if (dp[n] != -1) return dp[n];
```
- This checks if the derangement for `n` items has already been computed and stored in `dp[n]`. If it has, the function directly returns this value, avoiding redundant calculations.

##### **Recursive Relation:**

```cpp
dp[n] = (n - 1) * (solve(n - 1, dp) + solve(n - 2, dp));
```
- If the result for `D(n)` is not found in `dp[n]`, the function computes it using the recursive relation:
  - `(n-1)` represents the number of possible ways the first item can be placed in a different position.
  - `solve(n - 1, dp)` calculates the derangement for `n - 1` items.
  - `solve(n - 2, dp)` calculates the derangement for `n - 2` items (considering possible swaps).
- The result is stored in `dp[n]` to avoid recalculating it in future calls.

#### **2. countDer Function**

This is the main function that initializes the memoization array and calls the `solve` function.

```cpp
int countDer(int n)
```
- **`n`**: The number of items for which we need to find the derangement.
- The function initializes the `dp` array with `-1` for all values from `0` to `n` and then calls `solve(n, dp)` to compute the derangement for `n` items.

```cpp
vector<int> dp(n + 1, -1);
return solve(n, dp);
```
- The `dp` array of size `n + 1` is created and initialized with `-1` to indicate that no results have been computed yet.
- The `solve` function is called to compute the final derangement for `n` items.

### **Example Walkthrough**

Let’s calculate `D(4)` as an example.

- **Step 1:** Start by calling `countDer(4)`, which initializes `dp` and calls `solve(4, dp)`.
- **Step 2:** `solve(4, dp)` checks if `dp[4]` is already computed (it’s not, so it proceeds).
- **Step 3:** Using the recursive relation:
  - `D(4) = (4 - 1) * (D(3) + D(2))`
  - To compute `D(4)`, we need `D(3)` and `D(2)`.
- **Step 4:** Compute `D(3)`:
  - `D(3) = (3 - 1) * (D(2) + D(1))`
  - `D(2) = 1` (base case), and `D(1) = 0` (base case).
  - `D(3) = 2 * (1 + 0) = 2`.
- **Step 5:** Compute `D(4)`:
  - `D(4) = 3 * (2 + 1) = 9`.
- **Step 6:** The result `D(4) = 9` is stored in `dp[4]`.

**Example Output:**
For `countDer(4)`, the output will be `9`.

### **Time and Space Complexity**

#### **Time Complexity:**
- **Memoization** ensures that each value of `D(n)` is computed only once. Each recursive call either computes a value or uses a previously computed one from the `dp` array.
- Therefore, the **time complexity** is **O(n)**, where `n` is the number of items. This is because the function will compute each derangement from `1` to `n` exactly once, and each recursive call makes a constant amount of work (besides the recursive calls).

#### **Space Complexity:**
- **Memoization Array**: The `dp` array stores the results for each number of items, so it takes **O(n)** space.
- **Recursive Call Stack**: The maximum recursion depth is `n`, as the function makes recursive calls for `n-1` and `n-2`. Thus, the space required for the recursion stack is **O(n)**.
- Therefore, the **space complexity** is **O(n)**.

### **Conclusion**

- **Top-Down Approach** with **Memoization** efficiently computes derangements by using recursion and caching intermediate results.
- **Time Complexity**: **O(n)**
- **Space Complexity**: **O(n)**

---

## Bottom-Up Approach (DP)
The **bottom-up approach** (also known as **tabulation**) is an iterative method where we solve the problem by starting from the smallest subproblem and build up to the solution of the larger problem. In this approach, all intermediate results are computed and stored in a table (usually an array), and we use these results to build up the final solution.

#### **How Tabulation Works:**
1. **Initialization**: We start by defining the base cases, which are the simplest cases that can be solved directly.
2. **Iterative Computation**: Using the recursive formula, we compute the solution for larger subproblems by using the results of smaller subproblems that have already been computed.
3. **Final Result**: Once all the subproblems are solved, the final answer is available in the last element of the table.

### Source Code
```cpp
class Solution {
  public:
    // Function to calculate derangements using tabulation (iterative dynamic programming)
    int solve(int n) {
        // Create a DP array to store the number of derangements for each value from 0 to n
        vector<int> dp(n + 1, -1);

        // Base cases:
        // For n = 1, there are no valid derangements
        dp[1] = 0;

        // For n = 2, there is exactly one valid derangement
        dp[2] = 1;

        // Fill the DP array iteratively using the relation:
        // D(i) = (i-1) * (D(i-1) + D(i-2))
        for (int i = 3; i <= n; i++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
        }

        // Return the result for n
        return dp[n];
    }

    // Main function to calculate derangements
    int countDer(int n) {
        // Delegate the computation to the solve function
        return solve(n);
    }
};
```

### Source Code Explanation
#### **1. solve Function**

This function calculates the derangement for `n` items using an iterative approach.

```cpp
int solve(int n) {
    // Create a DP array to store the number of derangements for each value from 0 to n
    vector<int> dp(n + 1, -1);
```
- We initialize a vector `dp` of size `n + 1` to store the derangement values for all numbers from `0` to `n`. Initially, all values are set to `-1` to indicate that they have not been computed yet.

```cpp
    // Base cases:
    // For n = 1, there are no valid derangements
    dp[1] = 0;

    // For n = 2, there is exactly one valid derangement
    dp[2] = 1;
```
- **Base Case for `n = 1`**: There are no derangements for a single item (`D(1) = 0`).
- **Base Case for `n = 2`**: There is exactly one valid derangement for two items (swap the two items: `D(2) = 1`).

```cpp
    // Fill the DP array iteratively using the relation:
    // D(i) = (i-1) * (D(i-1) + D(i-2))
    for (int i = 3; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
```
- Starting from `i = 3`, we fill the `dp` array using the **recursive relation**:
  - `D(i) = (i - 1) * (D(i - 1) + D(i - 2))`
  - This means that for `i` items, the derangement is calculated by choosing a position for the first item (there are `i - 1` possible choices), and then considering the derangements of the remaining `i - 1` and `i - 2` items.

```cpp
    // Return the result for n
    return dp[n];
}
```
- Once the loop is completed, the final result for `D(n)` is stored in `dp[n]`, which is returned.

#### **2. countDer Function**

This is the main function that delegates the calculation of derangements to the `solve` function.

```cpp
int countDer(int n) {
    // Delegate the computation to the solve function
    return solve(n);
}
```
- The `countDer` function simply calls `solve(n)` to compute the derangement for `n` items.

### **Example Walkthrough**

Let’s calculate `D(4)` using the bottom-up approach.

1. **Initialize `dp` array**: `dp = [-1, -1, -1, -1, -1]`
2. **Base cases**:
   - `dp[1] = 0` (No derangement for 1 item)
   - `dp[2] = 1` (One derangement for 2 items)
3. **Iterate from 3 to 4**:
   - For `i = 3`: `dp[3] = (3 - 1) * (dp[2] + dp[1]) = 2 * (1 + 0) = 2`
   - For `i = 4`: `dp[4] = (4 - 1) * (dp[3] + dp[2]) = 3 * (2 + 1) = 9`
4. The final `dp` array: `dp = [-1, 0, 1, 2, 9]`
5. **Return the result**: `D(4) = 9`

**Example Output:**
For `countDer(4)`, the output will be `9`.

### **Time and Space Complexity**

#### **Time Complexity:**
- The function uses a single loop to compute the derangement for each number from `3` to `n`. Therefore, the time complexity is **O(n)**.
- Each iteration of the loop involves a constant amount of work (a few arithmetic operations), and the loop runs for `n - 2` iterations.
- Hence, the **time complexity** is **O(n)**.

#### **Space Complexity:**
- The function uses a vector `dp` of size `n + 1` to store the results for each number from `0` to `n`. Thus, the space complexity is **O(n)**.
- There are no additional data structures used in the function, so the **space complexity** is dominated by the size of the `dp` array.

### **Conclusion**

- The **bottom-up approach** efficiently computes the derangements using dynamic programming with tabulation.
- **Time Complexity**: **O(n)**
- **Space Complexity**: **O(n)**

This approach avoids the overhead of recursion and stack calls, making it more space-efficient in some cases compared to the recursive approach with memoization.

---

## Space Optimized Approach (DP)
In the **space-optimized approach** for calculating derangements, the goal is to reduce the space complexity by using only a constant amount of space, rather than storing the entire array of results (as we did in the bottom-up dynamic programming approach). This is done by noticing that at any given point, we only need the results of the last two states (i.e., `D(n-1)` and `D(n-2)`) to compute the current state `D(n)`. Thus, we can avoid using an entire array and instead use just two variables to keep track of the last two results, significantly improving space efficiency.

### **How Space-Optimized Approach Works:**

1. **Base Cases:**
   - **D(1) = 0**: For one item, there are no valid derangements.
   - **D(2) = 1**: For two items, the only valid derangement is swapping the two items.

2. **Using Recurrence Relation:**
   The recurrence relation is:  

   `D(i) = (i - 1) \times (D(i - 1) + D(i - 2))`

   This means to compute the derangement for `i` items, we need the results for `i-1` and `i-2` items. With this, we can compute `D(i)` iteratively.

3. **Optimized Space Storage:**
   We do not need to store all intermediate values for `D(i)` for every `i` from `0` to `n`. Instead, we only keep track of the results for the last two `D(i)` values, namely `D(i-1)` and `D(i-2)`.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate derangements using space-optimized approach
    int solve(int n) {
        // Base case: For n = 1, there are no valid derangements
        if (n == 1) return 0;

        // Base case: For n = 2, there is exactly one valid derangement
        if (n == 2) return 1;

        // Initialize variables to store results for the last two states
        // prev: D(n-2), curr: D(n-1)
        int prev = 0; // D(1)
        int curr = 1; // D(2)

        // Loop to calculate D(n) iteratively using the relation:
        // D(i) = (i-1) * (D(i-1) + D(i-2))
        for (int i = 3; i <= n; i++) {
            // Compute the next derangement value
            int next = (i - 1) * (curr + prev);

            // Update prev and curr for the next iteration
            prev = curr;
            curr = next;
        }

        // Return the result for D(n)
        return curr;
    }
    
    // Main function to calculate derangements
    int countDer(int n) {
        // Delegate the computation to the solve function
        return solve(n);    
    }
};
```

### Source Code Explanation
```cpp
int solve(int n) {
    // Base case: For n = 1, there are no valid derangements
    if (n == 1) return 0;

    // Base case: For n = 2, there is exactly one valid derangement
    if (n == 2) return 1;

    // Initialize variables to store results for the last two states
    // prev: D(n-2), curr: D(n-1)
    int prev = 0; // D(1)
    int curr = 1; // D(2)
```
- We start by defining the base cases:
  - `D(1) = 0` (no valid derangements for a single item).
  - `D(2) = 1` (one valid derangement for two items).
- We initialize two variables, `prev` and `curr`, to hold `D(n-2)` and `D(n-1)`, respectively. Initially, `prev` is set to `0` (for `D(1)`), and `curr` is set to `1` (for `D(2)`).

```cpp
    // Loop to calculate D(n) iteratively using the relation:
    // D(i) = (i-1) * (D(i-1) + D(i-2))
    for (int i = 3; i <= n; i++) {
        // Compute the next derangement value
        int next = (i - 1) * (curr + prev);

        // Update prev and curr for the next iteration
        prev = curr;
        curr = next;
    }
```
- We now enter a loop starting from `i = 3` and iterating until `n`. For each `i`, we compute the derangement `D(i)` using the formula:
  - `D(i) = (i - 1) * (D(i - 1) + D(i - 2))`
  - We store the result of `D(i)` in the variable `next`.
- After calculating `D(i)`, we update `prev` to `curr` (the previous derangement), and set `curr` to the newly computed `next` (the current derangement).

```cpp
    // Return the result for D(n)
    return curr;
}
```
- After the loop finishes, `curr` will contain the value of `D(n)`, which is then returned.

```cpp
int countDer(int n) {
    // Delegate the computation to the solve function
    return solve(n);
}
```
- The `countDer` function simply calls the `solve` function to compute the derangement for `n` items and returns the result.

### **Example Walkthrough:**

Let’s calculate `D(4)` using this space-optimized approach:

1. **Initialize:**
   - `prev = 0` (for `D(1)`)
   - `curr = 1` (for `D(2)`)

2. **Iteration for `i = 3`:**
   - Calculate `D(3) = (3 - 1) * (1 + 0) = 2 * 1 = 2`
   - Update `prev = 1` and `curr = 2` (now `D(3) = 2`)

3. **Iteration for `i = 4`:**
   - Calculate `D(4) = (4 - 1) * (2 + 1) = 3 * 3 = 9`
   - Update `prev = 2` and `curr = 9` (now `D(4) = 9`)

4. **Return the result:** The final value of `curr` is `9`, which is `D(4)`.

**Example Output:**
For `countDer(4)`, the output will be `9`.

### **Time and Space Complexity:**

#### **Time Complexity:**
- The loop runs from `3` to `n`, performing constant-time operations in each iteration. Thus, the **time complexity** is **O(n)**.

#### **Space Complexity:**
- Instead of using an array to store all the derangements, we only use two variables (`prev` and `curr`) to store the results of the last two values. Therefore, the **space complexity** is **O(1)**, as we are only using a constant amount of space.

### **Conclusion:**
- This space-optimized approach reduces the space complexity from **O(n)** (in the bottom-up approach) to **O(1)**, making it highly efficient in terms of space.
- The **time complexity** remains **O(n)**, as we still need to iterate from `3` to `n` to compute the derangements.
