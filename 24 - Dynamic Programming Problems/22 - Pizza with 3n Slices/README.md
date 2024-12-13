<h1 align="center">Pizza - With - 3n - Slices</h1>

## Problem Statement

**Problem URL :** [Pizza with 3n Slices](https://leetcode.com/problems/pizza-with-3n-slices/description/)

![image](https://github.com/user-attachments/assets/57312b65-fdce-427f-a53a-47625931d8d0)

### Problem Explanation
The "Pizza with 3N Slices" problem involves selecting a subset of pizza slices to maximize the total sum, subject to the following constraints:

You have a pizza with 3N slices (where N is a positive integer). Your goal is to pick N slices in such a way that:
- You cannot pick two adjacent slices.
- You must pick exactly N slices.

You need to maximize the total sum of the selected slices. The pizza is represented as an array where each element is the score of a slice.

#### Problem Breakdown:
- **3N slices**: You are given an array of size `3 * N`, where each element represents the score of a particular slice.
- **Pick exactly N slices**: You need to choose exactly N slices from the pizza.
- **No two adjacent slices**: The slices you select cannot be adjacent to one another.
- **Maximize the sum of the slices**: Your objective is to maximize the sum of the selected slices.

#### Example:

##### Example 1:
**Input**: `slices = [1, 2, 3, 4, 5, 6]`  
**Output**: `10`  

**Explanation**:
- We are given 6 slices of pizza (`3 * 2 = 6`, where N = 2).
- We need to pick 2 slices from the array such that no two slices are adjacent.
- We can select the following two slices: `[3, 6]`. The sum of these slices is `3 + 6 = 10`.
- Thus, the maximum sum of selected slices is `10`.

##### Example 2:
**Input**: `slices = [8, 9, 8, 6, 1, 1]`  
**Output**: `16`  

**Explanation**:
- We are given 6 slices (`3 * 2 = 6`), and we need to pick 2 slices.
- The maximum sum of two non-adjacent slices can be obtained by picking the slices with scores `8` and `8`, yielding a sum of `8 + 8 = 16`.
- Thus, the result is `16`.

##### Example 3:
**Input**: `slices = [4, 1, 2, 5, 8, 3, 1, 9, 7]`  
**Output**: `21`  

**Explanation**:
- The array represents 9 slices (`3 * 3 = 9`), and you need to select 3 slices.
- The optimal slices to pick are `[4, 5, 9]` with a sum of `4 + 5 + 9 = 18`.
- Thus, the result is `18`.

#### Key Constraints:
- The number of slices, `n`, is always `3 * N`.
- The length of the array is `3 * N`, where N is a positive integer, and N is at least 1.
  
#### Objective:
- The main goal is to find the **maximum sum** of slices you can select by choosing N slices, ensuring that no two selected slices are adjacent.

#### Approach:
- This problem can be solved using **dynamic programming (DP)**, where we will maintain states for including or excluding a slice while considering the adjacency constraint. We will use two cases:
  1. The first case will consider the slice array excluding the last slice.
  2. The second case will consider the slice array excluding the first slice.

By comparing the results of both cases, we can determine the maximum sum possible for the required conditions.

---

## Recursive Approach (caused TLE)
In this problem, we need to select `N` non-adjacent slices from a circular array of pizza slices. To solve this, we can break the problem into two subproblems:

1. **Case 1:** Exclude the last slice (pick slices from index `0` to `k-2`).
2. **Case 2:** Exclude the first slice (pick slices from index `1` to `k-1`).

In both cases, the goal is to pick `n` non-adjacent slices, where `n = k / 3` (as `k` is the total number of slices, and we need to select a third of the total slices). We use **dynamic programming** in a **recursive** manner to find the optimal solution by considering two choices at each step:
- **Take the current slice.** If we take the current slice, we cannot take the next slice, so we move two steps ahead.
- **Skip the current slice.** If we skip the current slice, we simply move one step ahead.

The function `solve(index, endIndex, slices, n)` is a recursive function that returns the maximum sum of `n` non-adjacent slices from the range `[index, endIndex]` of the `slices` array.

### Source Code
```cpp
class Solution {
public:
    // Helper function to solve the subproblem of picking non-adjacent slices
    int solve(int index, int endIndex, vector<int>& slices, int n) {
        // Base case: If we've chosen n slices or we exceed the valid range, return 0 (no sum)
        if (n == 0 || index > endIndex) return 0;

        // Option 1: Take the slice at the current index and move two steps forward
        int takeSlice = slices[index] + solve(index + 2, endIndex, slices, n - 1);
        
        // Option 2: Skip the slice at the current index and move one step forward
        int noTakeSlice = 0 + solve(index + 1, endIndex, slices, n);

        // Return the maximum of taking or skipping the current slice
        return max(takeSlice, noTakeSlice);
    }

    // Main function to find the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size(); // Total number of slices
        // Case 1: Exclude the last slice (pick slices from index 0 to k-2)
        int case1 = solve(0, k - 2, slices, k / 3);
        
        // Case 2: Exclude the first slice (pick slices from index 1 to k-1)
        int case2 = solve(1, k - 1, slices, k / 3);

        // Return the maximum of the two cases
        return max(case1, case2);
    }
};
```
### Source Code Explanation

#### **Helper Function: `solve`**

```cpp
int solve(int index, int endIndex, vector<int>& slices, int n)
```

This function tries to solve the subproblem of picking `n` non-adjacent slices between the indices `index` and `endIndex` of the array `slices`.

- **Base Case 1:** If `n == 0` (no more slices to pick), return `0`. This is because we have successfully selected all the required slices, so no more slices need to be selected.
  
- **Base Case 2:** If `index > endIndex`, it means we've exceeded the range of slices, so return `0`.

Now we have two options at each step:
1. **Take the current slice at `index`.** This means we select the slice at `index` and skip the next slice (move `index+2`).
2. **Skip the current slice at `index`.** This means we don't pick the slice and move to the next slice (move `index+1`).

The function calculates both options and returns the maximum of the two.

```cpp
int takeSlice = slices[index] + solve(index + 2, endIndex, slices, n - 1);
int noTakeSlice = 0 + solve(index + 1, endIndex, slices, n);
```

- `takeSlice`: Adds the value of the current slice (`slices[index]`) and recursively solves the subproblem for the next valid slice (skip the adjacent slice by moving `index + 2`).
- `noTakeSlice`: Skips the current slice and recursively solves the subproblem by moving to the next slice (`index + 1`).

Finally, the function returns the maximum of `takeSlice` and `noTakeSlice` to ensure the optimal solution is selected.

```cpp
return max(takeSlice, noTakeSlice);
```

#### **Main Function: `maxSizeSlices`**

```cpp
int maxSizeSlices(vector<int>& slices) {
    int k = slices.size(); // Total number of slices
    // Case 1: Exclude the last slice (pick slices from index 0 to k-2)
    int case1 = solve(0, k - 2, slices, k / 3);
    
    // Case 2: Exclude the first slice (pick slices from index 1 to k-1)
    int case2 = solve(1, k - 1, slices, k / 3);

    // Return the maximum of the two cases
    return max(case1, case2);
}
```

- The total number of slices is `k = slices.size()`.
- We solve the problem in two cases:
  - **Case 1**: We exclude the last slice and solve the problem by picking slices from index `0` to `k-2`.
  - **Case 2**: We exclude the first slice and solve the problem by picking slices from index `1` to `k-1`.

- The answer is the maximum of the two cases, because we are trying to get the best possible sum of `n` slices in both cases.

### **Example Walkthrough**

Let’s use an example to explain the recursive approach in action:

**Example 1:**
```cpp
slices = [1, 2, 3, 4, 5, 6]
```

In this case, `k = 6`, and `n = k / 3 = 2` (since we need to pick `2` slices).

- **Case 1:** Exclude the last slice, so we pick slices from index `0` to `4`. The function will attempt to pick 2 non-adjacent slices from these indices.
  - It starts by choosing `slice[0] = 1` and then moves to the next valid slice, `slice[2] = 3`. It picks `1 + 3 = 4`.
  - Alternatively, it could skip the first slice and choose `slice[1] = 2` and then `slice[3] = 4`. It picks `2 + 4 = 6`, which is the maximum sum.
  
- **Case 2:** Exclude the first slice, so we pick slices from index `1` to `5`. The function will attempt to pick 2 non-adjacent slices from these indices.
  - It starts by choosing `slice[1] = 2` and then moves to the next valid slice, `slice[3] = 4`. It picks `2 + 4 = 6`.
  - Alternatively, it could skip the first slice and choose `slice[2] = 3` and then `slice[4] = 5`. It picks `3 + 5 = 8`, which is the maximum sum.

The maximum sum from either case is `10`, so the final answer is `10`.

### **Time Complexity**

- The recursive function `solve` is called multiple times, and each call performs a constant amount of work (either taking or skipping the slice).
- The function makes recursive calls with different ranges of slices, but no slice is considered more than once for each subproblem, so we can think of the recursive calls as building a tree of calls.
- In the worst case, the number of recursive calls is proportional to `O(k * n)`, where `k` is the size of the slices array and `n` is the number of slices to be selected (`k / 3`).

Thus, the time complexity is:

**Time Complexity: O(k * n)**, where `k` is the size of the array (`slices`) and `n` is the number of slices to be picked (`k / 3`).

### **Space Complexity**

- The space complexity is dominated by the recursion stack and the dynamic programming (DP) arrays used to store intermediate results.
- Since we are using `O(k)` space for storing the DP table and making at most `O(k)` recursive calls (in the worst case), the space complexity is:

**Space Complexity: O(k)**.

## Top-Down Approach (DP)
In this problem, the goal is to pick `n` non-adjacent slices from a circular array of pizza slices to maximize the sum. The recursive approach we previously discussed works, but it might recompute the same subproblems multiple times. To optimize it, we can use **dynamic programming (DP)** with **memoization**, which is known as the **Top-Down approach**. Here, we will use a DP table to store the results of previously solved subproblems to avoid redundant calculations.

---

### **Top-Down Approach**

We use a recursive approach with memoization. The recursive function computes the maximum sum for selecting `n` non-adjacent slices between indices `index` and `endIndex`. We store the results of subproblems in a DP table (`dp`) to avoid redundant calculations.

#### **Recursive Helper Function: `solve`**

The recursive function `solve` attempts to solve the subproblem of selecting `n` non-adjacent slices in the range from `index` to `endIndex`. It works as follows:

- **Base Case 1:** If `n == 0`, we've already selected the required number of slices, so return `0`.
  
- **Base Case 2:** If `index > endIndex`, it means we've exceeded the valid range, so return `0`.

- **Memoization Check:** If we have already computed the result for the subproblem defined by `index` and `n`, we return the stored result from the DP table `dp[index][n]` to avoid redundant computations.

- **Option 1:** Choose the slice at `index`, and recursively solve for the remaining slices starting from `index + 2` (because we cannot pick adjacent slices). Decrease `n` by 1.
  
- **Option 2:** Skip the slice at `index` and solve for the remaining slices starting from `index + 1`. Do not decrease `n`.

Finally, the function stores the result for the current subproblem (`dp[index][n]`) and returns the maximum of both options.

#### **Main Function: `maxSizeSlices`**

The main function is responsible for solving the problem for two cases:
1. **Case 1:** Exclude the last slice and pick slices from index `0` to `k-2`.
2. **Case 2:** Exclude the first slice and pick slices from index `1` to `k-1`.

For both cases, we call the `solve` function and return the maximum of the results from both cases.

### Source Code
```cpp
class Solution {
public:
    // Helper function to solve the subproblem of picking non-adjacent slices
    int solve(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp) {
        // Base case: If we've chosen n slices or exceed the valid range, return 0 (no sum)
        if (n == 0 || index > endIndex) return 0;

        // If the result for this subproblem has already been computed, return the cached value
        if (dp[index][n] != -1) return dp[index][n];

        // Option 1: Take the slice at the current index and move two steps forward
        int takeSlice = slices[index] + solve(index + 2, endIndex, slices, n - 1, dp);
        
        // Option 2: Skip the slice at the current index and move one step forward
        int noTakeSlice = 0 + solve(index + 1, endIndex, slices, n, dp);

        // Store the result for the current subproblem in the dp table
        return dp[index][n] = max(takeSlice, noTakeSlice);
    }

    // Main function to find the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size(); // Total number of slices
        
        // Initialize dp table for case 1 (picking slices from index 0 to k-2)
        vector<vector<int>> dp(k, vector<int>(k, -1)); 
        // Case 1: Exclude the last slice (pick slices from index 0 to k-2)
        int case1 = solve(0, k - 2, slices, k / 3, dp);

        // Initialize dp table for case 2 (picking slices from index 1 to k-1)
        vector<vector<int>> dp1(k, vector<int>(k, -1)); 
        // Case 2: Exclude the first slice (pick slices from index 1 to k-1)
        int case2 = solve(1, k - 1, slices, k / 3, dp1);

        // Return the maximum of the two cases
        return max(case1, case2);
    }
};
```
### Source Code Explanation


#### **`solve` Function**

```cpp
int solve(int index, int endIndex, vector<int>& slices, int n, vector<vector<int>>& dp)
```
This function is responsible for recursively selecting `n` non-adjacent slices from the range `[index, endIndex]` of the `slices` array. It uses a DP table `dp` to store the results of subproblems.

```cpp
if (n == 0 || index > endIndex) return 0;
```
- If `n == 0`, it means we have selected all required slices, so return `0`.
- If `index > endIndex`, it means we have exceeded the valid range, so return `0`.

```cpp
if (dp[index][n] != -1) return dp[index][n];
```
- If the result for this subproblem is already computed (i.e., `dp[index][n]` is not `-1`), return the cached value to avoid redundant calculations.

```cpp
int takeSlice = slices[index] + solve(index + 2, endIndex, slices, n - 1, dp);
```
- **Option 1**: Take the slice at `index` and move two steps forward (`index + 2`). The number of remaining slices to select decreases by 1 (`n - 1`).

```cpp
int noTakeSlice = 0 + solve(index + 1, endIndex, slices, n, dp);
```
- **Option 2**: Skip the slice at `index` and move one step forward (`index + 1`). The number of slices to select (`n`) remains unchanged.

```cpp
return dp[index][n] = max(takeSlice, noTakeSlice);
```
- Store the maximum of `takeSlice` and `noTakeSlice` in the DP table and return the result.

#### **`maxSizeSlices` Function**

```cpp
int k = slices.size(); // Total number of slices
```
- `k` is the total number of slices in the pizza.

```cpp
vector<vector<int>> dp(k, vector<int>(k, -1));
```
- Initialize the DP table for `Case 1` where we exclude the last slice (select slices from index `0` to `k-2`). All values in the table are initially set to `-1` to indicate that the subproblem hasn't been solved yet.

```cpp
int case1 = solve(0, k - 2, slices, k / 3, dp);
```
- Call the `solve` function for `Case 1` where we try to pick `n = k / 3` non-adjacent slices from the range `[0, k-2]`.

```cpp
vector<vector<int>> dp1(k, vector<int>(k, -1));
```
- Initialize a separate DP table for `Case 2` where we exclude the first slice and select slices from index `1` to `k-1`.

```cpp
int case2 = solve(1, k - 1, slices, k / 3, dp1);
```
- Call the `solve` function for `Case 2` where we try to pick `n = k / 3` non-adjacent slices from the range `[1, k-1]`.

```cpp
return max(case1, case2);
```
- Return the maximum sum of slices between the two cases (`Case 1` and `Case 2`).



### **Example Walkthrough**

Let's take the example `slices = [1, 2, 3, 4, 5, 6]`, where `k = 6`, and `n = k / 3 = 2`. We need to select 2 non-adjacent slices.

- **Case 1**: Exclude the last slice, so we select from the range `[0, 4]`.
  - The DP function would recursively calculate the best sum by choosing either to pick or skip slices at each index, storing results in the `dp` table.
  
- **Case 2**: Exclude the first slice, so we select from the range `[1, 5]`.
  - The DP function would recursively calculate the best sum by choosing either to pick or skip slices at each index, storing results in the `dp1` table.

The maximum sum between the two cases is the final answer.



### **Time Complexity**

- The recursion tree has `O(k)` levels (for each slice), and for each level, we solve a subproblem for up to `O(k)` slices.
- **Time Complexity**: **O(k * n)**, where `k` is the total number of slices and `n` is the number of slices to select (`k / 3`).

### **Space Complexity**

- We use a 2D DP table to store the results for subproblems, so the space complexity is **O(k * n)**.

---

## Bottom-Up Approach (DP)
In this problem, the goal is to pick `n` non-adjacent slices from a circular array of pizza slices to maximize the sum. The **Bottom-Up approach** uses dynamic programming (DP) in an iterative way rather than a recursive one, building up the solution from smaller subproblems. This eliminates the overhead of recursion and also avoids the risk of exceeding the maximum recursion depth.

### **Bottom-Up Approach**

In the Bottom-Up approach, we initialize a DP table and iteratively compute the results for each subproblem. We start by solving the smaller subproblems and gradually build up to the final solution. 

Here, we use two separate DP tables:
1. **`dp` for Case 1**: This DP table is used to calculate the result when we exclude the last slice (i.e., select slices from index `0` to `k-2`).
2. **`dp1` for Case 2**: This DP table is used to calculate the result when we exclude the first slice (i.e., select slices from index `1` to `k-1`).

### **Code Walkthrough**

#### **`solve` Function**

The `solve` function performs the main calculations. It iterates over the array of pizza slices, and for each index, it computes the maximum sum for choosing a given number of non-adjacent slices.

1. **Initialization**: 
   - Two DP tables `dp` and `dp1` are created with dimensions `(k + 2) x (k)`, where `k` is the number of pizza slices, and `dp[i][n]` represents the maximum sum achievable from index `i` with `n` slices left to pick.
   
2. **Case 1**: The first loop calculates the maximum sum when excluding the last slice, iterating backwards from `k-2` to `0`.
   - At each index, we consider two options:
     1. **Take the slice** at the current index and recursively solve for the remaining slices starting from `index + 2` (to avoid adjacent slices).
     2. **Skip the slice** at the current index and solve for the remaining slices starting from `index + 1`.

3. **Case 2**: The second loop calculates the maximum sum when excluding the first slice, iterating backwards from `k-1` to `1`.
   - Similarly, at each index, we consider the same two options as in Case 1.

4. **Final Answer**: After calculating both cases, we return the maximum of the results from both cases.

#### **`maxSizeSlices` Function**

The `maxSizeSlices` function simply calls the `solve` function with the given pizza slices array.

### Source Code
```cpp
class Solution {
public:
    // Helper function to solve the problem of picking non-adjacent slices
    int solve(vector<int>& slices) {
        int k = slices.size();  // Total number of slices (3 * n)

        // Initialize two DP tables:
        // dp[i][n] stores the maximum sum of slices we can pick from index i with n slices left to pick.
        vector<vector<int>> dp(k + 2, vector<int>(k, 0)); // For the first case, we exclude the last slice
        vector<vector<int>> dp1(k + 2, vector<int>(k, 0)); // For the second case, we exclude the first slice

        // DP for case 1 (excluding the last slice)
        for (int index = k - 2; index >= 0; index--) {  // Iterate backwards through the slices (0 to k-2)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward (to avoid picking adjacent slices)
                int takeSlice = slices[index] + dp[index + 2][n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + dp[index + 1][n];
                
                // Store the maximum of the two options (take or skip)
                dp[index][n] = max(takeSlice, noTakeSlice);
            }
        }

        // Store the result for case 1, excluding the last slice
        int case1 = dp[0][k / 3];  // We start from index 0 and need to pick k/3 slices

        // DP for case 2 (excluding the first slice)
        for (int index = k - 1; index >= 1; index--) {  // Iterate backwards through the slices (1 to k-1)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward
                int takeSlice = slices[index] + dp1[index + 2][n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + dp1[index + 1][n];
                
                // Store the maximum of the two options (take or skip)
                dp1[index][n] = max(takeSlice, noTakeSlice);
            }
        }

        // Store the result for case 2, excluding the first slice
        int case2 = dp1[1][k / 3];  // We start from index 1 and need to pick k/3 slices

        // Return the maximum of the two cases
        return max(case1, case2);
    }

    // Main function to calculate the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);  // Call the solve function to compute the result
    }
};
```
### Source Code Explanation

#### **`solve` Function**

```cpp
int k = slices.size();  // Total number of slices (3 * n)
```
- `k` represents the total number of pizza slices, which is equal to `3 * n` (where `n` is the number of slices we need to select).

```cpp
vector<vector<int>> dp(k + 2, vector<int>(k, 0)); // For the first case, we exclude the last slice
vector<vector<int>> dp1(k + 2, vector<int>(k, 0)); // For the second case, we exclude the first slice
```
- Two DP tables `dp` and `dp1` are initialized. Each table has dimensions `(k + 2) x (k)`. The additional rows are to handle the boundary conditions (i.e., when the `index` goes out of bounds).

```cpp
for (int index = k - 2; index >= 0; index--) {  // Iterate backwards through the slices (0 to k-2)
    for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
        int takeSlice = slices[index] + dp[index + 2][n - 1];
        int noTakeSlice = 0 + dp[index + 1][n];
        dp[index][n] = max(takeSlice, noTakeSlice);
    }
}
```
- **Case 1**: The loop iterates through the slices from index `k-2` to `0`. At each index, we compute two options:
  1. **Take the slice** at the current index and move two steps forward (`index + 2`).
  2. **Skip the slice** at the current index and move one step forward (`index + 1`).

- The maximum of the two options is stored in the `dp` table at `dp[index][n]`.

```cpp
int case1 = dp[0][k / 3];  // We start from index 0 and need to pick k/3 slices
```
- After filling the DP table, the result for **Case 1** (excluding the last slice) is stored in `dp[0][k / 3]`, which represents the maximum sum when selecting `k / 3` non-adjacent slices starting from index `0`.

```cpp
for (int index = k - 1; index >= 1; index--) {  // Iterate backwards through the slices (1 to k-1)
    for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
        int takeSlice = slices[index] + dp1[index + 2][n - 1];
        int noTakeSlice = 0 + dp1[index + 1][n];
        dp1[index][n] = max(takeSlice, noTakeSlice);
    }
}
```
- **Case 2**: The loop iterates through the slices from index `k-1` to `1`. The same logic applies here: at each index, we compute two options:
  1. **Take the slice** at the current index and move two steps forward (`index + 2`).
  2. **Skip the slice** at the current index and move one step forward (`index + 1`).

- The maximum of the two options is stored in the `dp1` table at `dp1[index][n]`.

```cpp
int case2 = dp1[1][k / 3];  // We start from index 1 and need to pick k/3 slices
```
- After filling the DP table for Case 2, the result for **Case 2** (excluding the first slice) is stored in `dp1[1][k / 3]`, which represents the maximum sum when selecting `k / 3` non-adjacent slices starting from index `1`.

```cpp
return max(case1, case2);
```
- Finally, the maximum of the results from Case 1 and Case 2 is returned as the final answer.

#### **`maxSizeSlices` Function**

```cpp
int maxSizeSlices(vector<int>& slices) {
    return solve(slices);  // Call the solve function to compute the result
}
```
- The `maxSizeSlices` function simply calls the `solve` function and returns its result.



### **Time and Space Complexity**

- **Time Complexity**: 
  - The solution iterates over the slices twice, once for each DP table. Each iteration involves filling `k / 3` entries for each slice, which gives us a time complexity of **O(k * k/3) = O(k^2)**.
  
- **Space Complexity**: 
  - We use two DP tables (`dp` and `dp1`), each of size `(k + 2) x k`. Therefore, the space complexity is **O(k^2)**.

---

## Space Optimization Approach (DP)
Let's go through the **Space Optimization Approach** step by step and break it down with examples and detailed explanations.

### **Space Optimization Approach:**

The problem at hand is a dynamic programming problem where we are asked to select slices from a circular pizza in such a way that no two selected slices are adjacent, and we maximize the sum of the selected slices. Since the pizza is circular, we need to handle two cases:
1. Case 1: Exclude the last slice.
2. Case 2: Exclude the first slice.

The traditional approach to solving this would use dynamic programming (DP) with three arrays to keep track of the previous, current, and next states. However, in the **space optimization** approach, we aim to reduce the space complexity by using only two arrays (`prev` and `curr`) to store the necessary states.

### **Space Optimization Principle:**

1. **Using two arrays for DP:**
   Instead of storing the results of all states in three separate arrays, we use two arrays (`prev` and `curr`) to hold the results of the previous and current states, respectively.

2. **Iterating through slices:**
   At each step, we calculate the best result for the current slice and store it in the `curr` array, then shift the `curr` array to `prev` for the next iteration.

3. **Reducing space complexity:**
   Since we only need the previous and current states to compute the next state, we can reduce the space complexity from **O(k^2)** (using three arrays) to **O(k)** (using only two arrays).



### **Step-by-Step Approach with Example:**

Let’s walk through a smaller example with 6 slices: `[1, 2, 3, 4, 5, 6]`. We will follow the **Space Optimization** approach.

#### Step 1: Define the Problem
We need to pick non-adjacent slices from the pizza to maximize the sum.

#### Step 2: Case 1 (Excluding the Last Slice)
We treat the slices as if they were linear, i.e., we ignore the last slice. This reduces the problem to selecting slices from `[1, 2, 3, 4, 5]`.

- We use dynamic programming with two arrays:
  - `prev`: stores the results of the previous step.
  - `curr`: stores the results of the current step.

We initialize both arrays as follows:
- `prev = [0, 0, 0, 0, 0, 0]`
- `curr = [0, 0, 0, 0, 0, 0]`

#### Step 3: Iterating Over the Slices
We iterate backward through the slices (ignoring the last slice in this case).

For each slice, we have two choices:
- **Option 1:** Take the current slice and move 2 steps forward.
- **Option 2:** Skip the current slice and keep the previous state.

Let’s go through the iterations.

- **Iteration 1:** Slice `5` (index 4):
  - Option 1: Take `5` + `prev[1]` = `5` (since `prev[1] = 0`).
  - Option 2: Skip `5` and take `curr[1]` = `0`.
  - So, `prev[1] = 5`.

- **Iteration 2:** Slice `4` (index 3):
  - Option 1: Take `4` + `prev[0]` = `4` (since `prev[0] = 0`).
  - Option 2: Skip `4` and take `curr[1]` = `5`.
  - So, `prev[1] = 5`.

- **Iteration 3:** Slice `3` (index 2):
  - Option 1: Take `3` + `prev[0]` = `3`.
  - Option 2: Skip `3` and take `curr[1]` = `5`.
  - So, `prev[1] = 5`.

- **Iteration 4:** Slice `2` (index 1):
  - Option 1: Take `2` + `prev[0]` = `2`.
  - Option 2: Skip `2` and take `curr[1]` = `5`.
  - So, `prev[1] = 5`.

- **Iteration 5:** Slice `1` (index 0):
  - Option 1: Take `1` + `prev[0]` = `1`.
  - Option 2: Skip `1` and take `curr[1]` = `5`.
  - So, `prev[1] = 5`.

#### Step 4: Result for Case 1
The result for Case 1 (excluding the last slice) is `prev[1] = 5`.



#### Step 5: Case 2 (Excluding the First Slice)
Now, we treat the problem as if we are excluding the first slice and solve the problem for the remaining slices: `[2, 3, 4, 5, 6]`.

#### Step 6: Iterating Over the Slices for Case 2
The process is similar to Case 1, but now we are working with slices `[2, 3, 4, 5, 6]`.

- We repeat the same dynamic programming approach with two arrays: `prev1` and `curr1`.
- After iterating over all the slices, we get the result for Case 2.

#### Step 7: Combine the Results
Finally, we take the maximum of the results from Case 1 and Case 2:
```cpp
result = max(case1, case2);
```

### Source Code 
```cpp
class Solution {
public:
    // Helper function to solve the problem of picking non-adjacent slices
    int solve(vector<int>& slices){
        int k = slices.size();  // Total number of slices (3 * n)

        // Initialize 3 arrays for dynamic programming:
        // prev, curr, and next are used to store the results of previous, current, and next steps, respectively.
        vector<int> prev(k+2, 0);    // To store the results of the previous step for dp
        vector<int> curr(k+2, 0);    // To store the results of the current step for dp
        vector<int> next(k+2, 0);    // To store the results of the next step for dp

        // DP for case 1 (excluding the last slice)
        for (int index = k - 2; index >= 0; index--) {  // Iterate backwards through the slices (0 to k-2)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward (to avoid picking adjacent slices)
                int takeSlice = slices[index] + next[n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + curr[n];
                
                // Store the maximum of the two options (take or skip)
                prev[n] = max(takeSlice, noTakeSlice);
            }
            // Update the dp arrays by shifting
            next = curr;   // Move current to next
            curr = prev;   // Move previous to current
        }

        // Store the result for case 1, excluding the last slice
        int case1 = curr[k / 3];  // We start from index 0 and need to pick k/3 slices

        // DP for case 2 (excluding the first slice)
        vector<int> prev1(k+2, 0);   // To store the results for the second case
        vector<int> curr1(k+2, 0);   // To store the current results for the second case
        vector<int> next1(k+2, 0);   // To store the next step results for the second case

        // Iterate through slices for case 2, starting from index 1 and excluding the first slice
        for (int index = k - 1; index >= 1; index--) {  // Iterate backwards through the slices (1 to k-1)
            for (int n = 1; n <= k / 3; n++) {  // Iterate through the number of slices left to pick
                // Option 1: Take the current slice and move 2 steps forward
                int takeSlice = slices[index] + next1[n - 1];
                
                // Option 2: Skip the current slice and move 1 step forward
                int noTakeSlice = 0 + curr1[n];
                
                // Store the maximum of the two options (take or skip)
                prev1[n] = max(takeSlice, noTakeSlice);
            }
            // Update the dp arrays by shifting
            next1 = curr1;   // Move current to next
            curr1 = prev1;   // Move previous to current
        }

        // Store the result for case 2, excluding the first slice
        int case2 = curr1[k / 3];  // We start from index 1 and need to pick k/3 slices

        // Return the maximum of the two cases
        return max(case1, case2);
    }

    // Main function to calculate the maximum sum of slices
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);  // Call the solve function to compute the result
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    int solve(vector<int>& slices){
        int k = slices.size();  // Total number of slices

        vector<int> prev(k+2, 0);    // Initialize prev array to store previous results
        vector<int> curr(k+2, 0);    // Initialize curr array to store current results
```
- Here, we initialize the two arrays `prev` and `curr` to store dynamic programming results. We set the size to `k+2` to accommodate edge cases and 0-based indexing.

```cpp
        // DP for case 1 (excluding the last slice)
        for (int index = k - 2; index >= 0; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int takeSlice = slices[index] + prev[n - 1];
                int noTakeSlice = 0 + curr[n];
                prev[n] = max(takeSlice, noTakeSlice);
            }
            fill(curr.begin(), curr.end(), 0);  // Clear curr before next use
            curr = prev;   // Move prev to curr for the next iteration
        }
```
- In the above code, we process each slice starting from the second-to-last slice (`k-2`). We compute the maximum sum for each number of slices left to pick (`n`). We then shift `curr` and `prev` arrays.

```cpp
        int case1 = curr[k / 3];  // Store the result for case 1
```
- After the loop finishes, `curr[k / 3]` gives the result for Case 1 (excluding the last slice).

```cpp
        // DP for case 2 (excluding the first slice)
        vector<int> prev1(k+2, 0);   // Initialize prev1 for Case 2
        vector<int> curr1(k+2, 0);   // Initialize curr1 for Case 2
        for (int index = k - 1; index >= 1; index--) {
            for (int n = 1; n <= k / 3; n++) {
                int takeSlice = slices[index] + prev1[n - 1];
                int noTakeSlice = 0 + curr1[n];
                prev1[n] = max(takeSlice, noTakeSlice);
            }
            fill(curr1.begin(), curr1.end(), 0);  // Clear curr1 before next use
            curr1 = prev1;   // Move prev1 to curr1 for the next iteration
        }
```
- We repeat the same DP procedure for Case 2 (excluding the first slice), using `prev1` and `curr1`.

```cpp
        int case2 = curr1[k / 3];  // Store the result for case 2
        return max(case1, case2);   // Return the maximum of the two cases
    }
```
- Finally, we return the maximum of `case1` and `case2`.



### **Example Output Explanation:**

Let’s take the example `[1, 2, 3, 4, 5, 6]`:
- Case 1 (excluding the last slice) might pick slices `[1, 3, 5]`, and the sum would be `1 + 3 + 5 = 9`.
- Case 2 (excluding the first slice) might pick slices `[2, 4, 6]`, and the sum would be `2 + 4 + 6 = 12`.
- So, the output would be `max(9, 12) = 12`.

### **Time and Space Complexity:**

- **Time Complexity:**
  - The time complexity is **O(k * k / 3)**, where `k` is the number of slices. The outer loop runs for `k` slices, and for each slice, we iterate over `k / 3` possible choices. This results in a time complexity of **O(k^2 / 3)**, which simplifies to **O(k^2)**.

- **Space Complexity:**
  - The space complexity is **O(k)** because we only use two arrays (`prev` and `curr`) to store the dynamic programming states, which reduces the space from **O(k^2)** to **O(k)**.

