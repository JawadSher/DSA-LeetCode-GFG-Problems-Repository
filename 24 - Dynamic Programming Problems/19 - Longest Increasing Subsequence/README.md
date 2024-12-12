<h1 align="center">Longest - Increasing - Subsequence</h1>

## Problem Statement

**Problem URL (leetcode):** [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/description/)

**Problem URL (GFG):** [Longest Increasing Subsequence](https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/ef7d8033-3a6d-4aab-b17e-115591b19a8a)

### Problem Explanation
The **Longest Increasing Subsequence (LIS)** problem is a classical problem in computer science and dynamic programming. Let's break it down step-by-step with examples to make it easier to understand.

### **Problem Statement**
You are given an array `nums` of integers. Your task is to find the length of the **longest increasing subsequence** in this array.

- A **subsequence** is a sequence derived from the array by deleting some or no elements without changing the order of the remaining elements. For example, from the array `[10, 9, 2, 5, 3, 7, 101, 18]`, the subsequences `[10, 101]`, `[2, 3, 7, 18]`, and `[9, 7]` are valid subsequences, but `[10, 2, 9]` is not (as the order is not preserved).
- An **increasing subsequence** is a subsequence where each element is greater than the previous one. For example, `[2, 3, 7, 101]` is an increasing subsequence.

Your task is to find the **length** of the longest subsequence that satisfies the "increasing" condition.

### **Steps to Solve**

#### **Step 1: Understand the Input and Output**
- **Input:** An integer array `nums` of size ( n ).
- **Output:** An integer representing the length of the longest increasing subsequence.

#### **Step 2: Constraints**
1. The length of the array ( n ) is between 1 and 2500.
2. The elements of the array ( nums[i] ) are between (-10^4) and (10^4).



### **Example Walkthrough**

#### **Example 1**
Input: `nums = [10, 9, 2, 5, 3, 7, 101, 18]`

- Possible increasing subsequences:
  - `[10]`, `[9]`, `[2]` (length = 1)
  - `[2, 5]`, `[2, 3]`, `[2, 7]` (length = 2)
  - `[2, 3, 7]`, `[2, 5, 7]`, `[2, 3, 101]` (length = 3)
  - `[2, 3, 7, 101]`, `[2, 3, 7, 18]` (length = 4)

Output: `4`

Explanation: The longest increasing subsequence is `[2, 3, 7, 101]`, and its length is 4.



#### **Example 2**
Input: `nums = [0, 1, 0, 3, 2, 3]`

- Possible increasing subsequences:
  - `[0]`, `[1]`, `[2]`, `[3]` (length = 1)
  - `[0, 1]`, `[0, 3]`, `[0, 2]` (length = 2)
  - `[0, 1, 3]`, `[0, 1, 2]`, `[0, 2, 3]` (length = 3)

Output: `4`

Explanation: The longest increasing subsequence is `[0, 1, 2, 3]`, and its length is 4.



#### **Example 3**
Input: `nums = [7, 7, 7, 7]`

- Possible increasing subsequences:
  - `[7]` (length = 1)

Output: `1`

Explanation: All elements are the same, so the longest increasing subsequence is any single element.

### **Key Points**
1. **Subsequences vs. Subsequences:**
   - A **subsequence** is different from a **subarray**. A subsequence does not require consecutive elements.
   - For example, in `nums = [2, 5, 3, 7]`, `[2, 3, 7]` is a subsequence but not a subarray.

2. **Edge Cases:**
   - Single element array: `nums = [5]`. Output: `1`.
   - Already sorted array: `nums = [1, 2, 3, 4]`. Output: `4`.
   - Reverse sorted array: `nums = [4, 3, 2, 1]`. Output: `1`.
     
### **Approaches to Solve the Problem**

#### **1. Brute Force Approach**
- Generate all possible subsequences and check if they are increasing.
- Complexity: (O(2^n)).

#### **2. Dynamic Programming (DP)**
- Use a `dp` array where `dp[i]` stores the length of the LIS ending at index `i`.
- Iterate over all pairs of indices to find the LIS.
- Complexity: (O(n^2)).

#### **3. Binary Search + DP**
- Use a dynamic array to store the smallest possible elements of subsequences of increasing lengths.
- Use binary search to efficiently replace elements.
- Complexity: (O(n log n)).

By solving smaller examples and identifying patterns, the Longest Increasing Subsequence problem becomes easier to understand and implement efficiently.

---

## Recursive Approach (caused TLE)
The recursive approach breaks down the problem into smaller subproblems by considering each element of the array and deciding whether to include it in the subsequence or exclude it. Let’s explain this step by step:

### **Steps of the Recursive Approach**

1. **Start at the First Element:**
   Begin at index 0 of the array. At each step, decide:
   - Include the current element in the subsequence (if it can be included).
   - Skip (exclude) the current element and move to the next.

2. **Conditions for Inclusion:**
   An element can only be included in the subsequence if:
   - It's the first element being considered (`prevIndex == -1`), or
   - It's greater than the last included element (`nums[currIndex] > nums[prevIndex]`).

3. **Recursive Cases:**
   - If the current element is included, move to the next element and update the `prevIndex` to the current index.
   - If the current element is excluded, move to the next element without updating the `prevIndex`.

4. **Base Case:**
   If you reach the end of the array (`currIndex == n`), return 0 because no further elements can be considered.

5. **Combine Results:**
   At each step, return the maximum of the two choices:
   - Length of the subsequence by including the current element.
   - Length of the subsequence by excluding the current element.

### **Example Walkthrough**

#### Input: `nums = [10, 9, 2, 5, 3, 7, 101, 18]`

1. Start at `currIndex = 0`, `prevIndex = -1`:
   - Include `10` → Solve for `currIndex = 1`, `prevIndex = 0`.
   - Exclude `10` → Solve for `currIndex = 1`, `prevIndex = -1`.

2. For `currIndex = 1`, `prevIndex = 0` (Include `10`):
   - Skip `9` because `9 < 10` → Solve for `currIndex = 2`, `prevIndex = 0`.

3. For `currIndex = 1`, `prevIndex = -1` (Exclude `10`):
   - Include `9` → Solve for `currIndex = 2`, `prevIndex = 1`.
   - Exclude `9` → Solve for `currIndex = 2`, `prevIndex = -1`.

This recursive process continues for all elements.

#### Final Result:
The longest increasing subsequence is `[2, 3, 7, 101]` with length `4`.

### Source Code
```cpp
class Solution {
public:
    // Helper function to find the length of the Longest Increasing Subsequence (LIS)
    // using recursion. 
    // Parameters:
    // - nums: The array of numbers.
    // - currIndex: The current index being considered.
    // - prevIndex: The index of the previous element included in the subsequence.
    int solve(vector<int>& nums, int currIndex, int prevIndex) {
        int n = nums.size(); // Get the size of the array.

        // Base case: If we reach the end of the array, return 0.
        if (currIndex == n) return 0;

        int include = 0; // Variable to store the result of including nums[currIndex].
        
        // Check if the current element can be included in the subsequence.
        // It can be included if:
        // - There is no previous element included (prevIndex == -1), OR
        // - The current element is greater than the last included element.
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solve(nums, currIndex + 1, currIndex); // Include nums[currIndex].
        }

        // Exclude the current element and move to the next.
        int exclude = solve(nums, currIndex + 1, prevIndex);

        // Return the maximum of including or excluding the current element.
        return max(include, exclude);
    }

    // Main function to calculate the length of the Longest Increasing Subsequence.
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, -1); // Start with the first element and no previous element.
    }
};
```

### Source Code Explanation
Let’s break down the provided source code **line by line** with detailed explanations and examples.

```cpp
class Solution {
```
- **Purpose:** Defines a class `Solution` to encapsulate the methods for solving the problem.
- **Example Con:** This is necessary because in coding platforms like LeetCode, solutions are expected to be inside a class.


```cpp
public:
```
- **Purpose:** Marks the following methods and variables as accessible from outside the class.
- **Example Con:** The `lengthOfLIS` function is intended to be called externally, so it is declared `public`.


### **Recursive Function: `solve`**

```cpp
int solve(vector<int>& nums, int currIndex, int prevIndex) {
```
- **Purpose:** Declares the recursive helper function.
  - `nums`: The input array.
  - `currIndex`: The index of the current element being considered.
  - `prevIndex`: The index of the last element included in the increasing subsequence.
- **Example Con:** If `nums = [10, 9, 2, 5, 3, 7]`, the function starts with `currIndex = 0` and `prevIndex = -1`.


```cpp
int n = nums.size();
```
- **Purpose:** Stores the size of the input array `nums` for easy access.
- **Example:** If `nums = [10, 9, 2, 5, 3, 7]`, then `n = 6`.

```cpp
if (currIndex == n) return 0;
```
- **Purpose:** Checks if the recursion has reached the end of the array. If true, no further elements can be considered, so return 0.
- **Example:** If `nums = [10, 9, 2]` and `currIndex = 3` (out of bounds), return 0.


```cpp
int include = 0;
```
- **Purpose:** Initializes a variable to track the length of the subsequence if the current element is included.
- **Example:** Before including any element, `include = 0`.


```cpp
if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
```
- **Purpose:** Checks if the current element can be included in the subsequence. Two conditions:
  - **No previous element**: (`prevIndex == -1`).
  - **Current element greater than previous element**: (`nums[currIndex] > nums[prevIndex]`).
- **Example:**
  - `nums = [10, 9, 2, 5]`, `currIndex = 3`, `prevIndex = 2`.
    - `nums[3] = 5`, `nums[2] = 2` → `5 > 2`, so include `5`.


```cpp
include = 1 + solve(nums, currIndex + 1, currIndex);
```
- **Purpose:** Recursively include the current element in the subsequence, add 1 to the length, and move to the next index.
- **Example:**
  - `nums = [10, 9, 2, 5]`, `currIndex = 2`, `prevIndex = -1`.
    - Include `2`: Add 1 to the length and call `solve(nums, 3, 2)`.


```cpp
int exclude = solve(nums, currIndex + 1, prevIndex);
```
- **Purpose:** Recursively exclude the current element from the subsequence and move to the next index.
- **Example:**
  - `nums = [10, 9, 2, 5]`, `currIndex = 2`, `prevIndex = -1`.
    - Exclude `2`: Call `solve(nums, 3, -1)`.


```cpp
return max(include, exclude);
```
- **Purpose:** Returns the maximum length of the subsequence by either including or excluding the current element.
- **Example:**
  - If including `2` gives length 3 and excluding gives length 2, return `3`.


### **Main Function: `lengthOfLIS`**

```cpp
int lengthOfLIS(vector<int>& nums) {
```
- **Purpose:** Declares the main function that calculates the Longest Increasing Subsequence (LIS) of the input array.
- **Example Con:** This is the entry point of the solution.


```cpp
return solve(nums, 0, -1);
```
- **Purpose:** Initiates the recursive process from the first element (`currIndex = 0`) with no previous element (`prevIndex = -1`).
- **Example:**
  - Input: `nums = [10, 9, 2, 5, 3, 7]`
    - Starts with `solve(nums, 0, -1)`.


### **Example Execution**

#### Input: `nums = [10, 9, 2, 5, 3, 7]`

1. `solve(nums, 0, -1)`:
   - Include `10`: `1 + solve(nums, 1, 0)`.
   - Exclude `10`: `solve(nums, 1, -1)`.

2. `solve(nums, 1, 0)`:
   - `nums[1] = 9` → Cannot include (less than `10`).
   - Exclude `9`: `solve(nums, 2, 0)`.

3. `solve(nums, 2, -1)`:
   - Include `2`: `1 + solve(nums, 3, 2)`.
   - Exclude `2`: `solve(nums, 3, -1)`.

4. Continue this process until all subsequences are evaluated.

#### Output:
- Longest Increasing Subsequence: `[2, 3, 7]`.
- Length: `3`.


### **Time and Space Complexities**

1. **Time Complexity:** (O(2^n))  
   - Each element has two choices (include or exclude), resulting in an exponential number of recursive calls.

2. **Space Complexity:** (O(n))  
   - The recursion stack can go up to (n) calls deep.

---

## Top-Down Approach (DP)
Let’s break down the **Top-Down Approach** with **memoization** in detail. We will explain the logic, the code line-by-line, provide examples, and analyze the output, time, and space complexities.

### **Recursive Approach with Memoization**

The key idea of this approach is to avoid redundant computations by storing the results of previously solved subproblems in a **memoization table** (`dp`). This helps optimize the recursive approach.



### **Detailed Step-by-Step Explanation**

1. **Base Case:**
   - If the recursion reaches the end of the array (`currIndex == nums.size()`), no elements can be included, so return `0`.

2. **Recursive Choices:**
   - For each element `nums[currIndex]`:
     - **Include it** in the subsequence if it's greater than the last included element (`nums[prevIndex]`).
     - **Exclude it** and move to the next element.

3. **Memoization:**
   - Use a 2D table `dp[currIndex][prevIndex+1]` to store results for unique states (`currIndex` and `prevIndex`).
   - `prevIndex+1` is used to handle the special case when `prevIndex == -1` (no element included yet).


### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using recursion with memoization.
    // Parameters:
    // - nums: The array of numbers.
    // - currIndex: The current index being considered.
    // - prevIndex: The index of the previous element included in the subsequence.
    // - dp: A 2D memoization table to store results of subproblems.
    int solve(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp) {
        int n = nums.size(); // Get the size of the array.

        // Base case: If we reach the end of the array, return 0.
        if (currIndex == n) return 0;

        // Check if the result for the current state is already computed.
        // Note: `prevIndex+1` is used to handle the -1 index case.
        if (dp[currIndex][prevIndex + 1] != -1) return dp[currIndex][prevIndex + 1];

        int include = 0; // Variable to store the result of including nums[currIndex].

        // Check if the current element can be included in the subsequence.
        // It can be included if:
        // - There is no previous element included (prevIndex == -1), OR
        // - The current element is greater than the last included element.
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
            include = 1 + solve(nums, currIndex + 1, currIndex, dp); // Include nums[currIndex].
        }

        // Exclude the current element and move to the next.
        int exclude = solve(nums, currIndex + 1, prevIndex, dp);

        // Store the result in the memoization table and return it.
        return dp[currIndex][prevIndex + 1] = max(include, exclude);
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Initialize a 2D DP table with -1 to indicate uncomputed states.
        // Dimensions are n x (n+1) to handle the case where prevIndex == -1.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Start the recursion from the first element with no previous element (-1).
        return solve(nums, 0, -1, dp);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
```
- **Purpose:** Defines the class `Solution` to encapsulate the methods for solving the problem.



#### **Recursive Helper Function: `solve`**

```cpp
int solve(vector<int>& nums, int currIndex, int prevIndex, vector<vector<int>>& dp) {
```
- **Purpose:** Declares the recursive helper function.
  - `nums`: Input array of numbers.
  - `currIndex`: Current index being considered.
  - `prevIndex`: Index of the last included element in the subsequence.
  - `dp`: 2D memoization table to store subproblem results.
- **Example Con:** If `nums = [10, 9, 2, 5, 3, 7]`, starts with `currIndex = 0` and `prevIndex = -1`.



```cpp
int n = nums.size();
```
- **Purpose:** Stores the size of the input array.
- **Example:** If `nums = [10, 9, 2, 5, 3, 7]`, `n = 6`.



```cpp
if (currIndex == n) return 0;
```
- **Purpose:** Base case. If we reach the end of the array, return 0 since no elements can be included.
- **Example:** If `currIndex = 6` (out of bounds), return `0`.



```cpp
if (dp[currIndex][prevIndex + 1] != -1) return dp[currIndex][prevIndex + 1];
```
- **Purpose:** Checks if the result for the current state has already been computed. If so, return the stored value.
- **Example:**
  - Suppose `currIndex = 2` and `prevIndex = -1`. If `dp[2][0] = 3` (already computed), return `3`.



```cpp
int include = 0;
```
- **Purpose:** Initializes a variable to store the result of including the current element.



```cpp
if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
```
- **Purpose:** Checks if the current element can be included in the subsequence:
  - `prevIndex == -1`: No previous element included, so include the current element.
  - `nums[currIndex] > nums[prevIndex]`: Include the current element if it is greater than the last included element.
- **Example:**
  - `nums = [10, 9, 2, 5]`, `currIndex = 3`, `prevIndex = 2` → Include `5` because `5 > 2`.



```cpp
include = 1 + solve(nums, currIndex + 1, currIndex, dp);
```
- **Purpose:** Recursively include the current element, add 1 to the subsequence length, and move to the next index.
- **Example:**
  - `nums = [10, 9, 2, 5]`, `currIndex = 2`, `prevIndex = -1` → Include `2`, then call `solve(nums, 3, 2, dp)`.



```cpp
int exclude = solve(nums, currIndex + 1, prevIndex, dp);
```
- **Purpose:** Recursively exclude the current element and move to the next index.
- **Example:**
  - `nums = [10, 9, 2, 5]`, `currIndex = 2`, `prevIndex = -1` → Exclude `2`, then call `solve(nums, 3, -1, dp)`.



```cpp
return dp[currIndex][prevIndex + 1] = max(include, exclude);
```
- **Purpose:** Store the maximum length of the subsequence (including or excluding the current element) in the memoization table and return it.
- **Example:**
  - If including `2` gives length `3` and excluding gives length `2`, store `dp[2][0] = 3`.



#### **Main Function: `lengthOfLIS`**

```cpp
int lengthOfLIS(vector<int>& nums) {
```
- **Purpose:** Declares the main function to calculate the LIS.



```cpp
int n = nums.size();
```
- **Purpose:** Stores the size of the input array.



```cpp
vector<vector<int>> dp(n, vector<int>(n + 1, -1));
```
- **Purpose:** Initializes the 2D memoization table with `-1` to represent uncomputed states.
- **Example:** For `nums = [10, 9, 2, 5, 3, 7]`, creates a table of size `6 x 7`.



```cpp
return solve(nums, 0, -1, dp);
```
- **Purpose:** Starts the recursive process from the first element (`currIndex = 0`) with no previous element (`prevIndex = -1`).



### **Example Execution**

#### Input: `nums = [10, 9, 2, 5, 3, 7]`

1. Call `solve(nums, 0, -1, dp)`.
   - Include `10`: Call `solve(nums, 1, 0, dp)`.
   - Exclude `10`: Call `solve(nums, 1, -1, dp)`.

2. Call `solve(nums, 1, 0, dp)`.
   - Cannot include `9` (not greater than `10`).
   - Exclude `9`: Call `solve(nums, 2, 0, dp)`.

3. Call `solve(nums, 2, -1, dp)`.
   - Include `2`: Call `solve(nums, 3, 2, dp)`.
   - Exclude `2`: Call `solve(nums, 3, -1, dp)`.

4. Continue this process for all elements.

#### Output:
- Longest Increasing Subsequence: `[2, 3, 7]`.
- Length: `3`.



### **Time Complexity**

- **Time Complexity:** (O(n^2))
  - Each state (`currIndex`, `prevIndex`) is solved once and stored in the `dp` table.
  - Total states: (n times (n+1)).



### **Space Complexity**

- **Space Complexity:** (O(n^2))
  - For the 2D `dp` table.
- **Recursive Stack Space:** (O(n)), due to recursion depth.

---

## Bottom-Up Approach (DP)

The **Bottom-Up Approach** for solving the **Longest Increasing Subsequence (LIS)** problem uses a dynamic programming technique to iteratively compute the solution. Unlike the top-down approach that uses recursion and memoization, this approach solves the problem by filling up a DP table from the bottom up (starting from the last element and progressing to the first).

Here’s the line-by-line breakdown of the given code:

### **Step-by-Step Explanation**

1. **Base Idea:**
   - **Dynamic Programming (DP) Approach**: We maintain a DP table `dp[currIndex][prevIndex+1]` where:
     - `currIndex` refers to the current index in the `nums` array.
     - `prevIndex` refers to the last element included in the subsequence.
     - The value at `dp[currIndex][prevIndex+1]` represents the length of the Longest Increasing Subsequence (LIS) starting from `currIndex` and considering `prevIndex` as the previous element of the subsequence.
  
2. **Steps:**
   - **Filling the DP table**: The DP table is filled in reverse order, starting from the last element in the array.
   - **Choice for Each Element**: For each element at index `currIndex`, we have two choices:
     - **Include the element**: If the current element can form an increasing subsequence with the last included element.
     - **Exclude the element**: Move to the next element without including the current one.
  
3. **Initialization**:
   - `dp[currIndex][prevIndex+1]` starts from 0, meaning if no elements are included, the length of LIS is `0`.
  
4. **Final Answer**:
   - After filling the DP table, the result will be found at `dp[0][0]`, which represents the LIS starting from index `0` with no previous element considered.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a bottom-up dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create a 2D DP table initialized with 0.
        // dp[currIndex][prevIndex+1] represents the length of LIS starting at `currIndex`
        // with the previous element being `nums[prevIndex]`.
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Iterate over the array in reverse order for `currIndex`.
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            // Iterate over the possible values of `prevIndex` in reverse order.
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                
                // Option 1: Include the current element in the LIS.
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    // If there is no previous element or the current element is greater,
                    // include the current element in the LIS.
                    include = 1 + dp[currIndex + 1][currIndex + 1];
                }

                // Option 2: Exclude the current element and proceed.
                int exclude = dp[currIndex + 1][prevIndex + 1];

                // Take the maximum of including or excluding the current element.
                dp[currIndex][prevIndex + 1] = max(include, exclude);
            }
        }

        // Return the result for the entire array (starting at index 0 with no previous element).
        return dp[0][0];
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
```

### Source Code Explanation

```cpp
class Solution {
```
- **Purpose:** Declares the class `Solution` to contain methods for solving the problem.



#### **Helper Function: `solve`**

```cpp
int solve(vector<int>& nums) {
```
- **Purpose:** The helper function that implements the bottom-up approach to calculate the LIS.
  - `nums`: The input vector representing the array of numbers.



```cpp
int n = nums.size(); // Get the size of the array.
```
- **Purpose:** Stores the size of the input array in variable `n`.
- **Example:** If `nums = [10, 9, 2, 5, 3, 7]`, then `n = 6`.



```cpp
vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
```
- **Purpose:** Creates a 2D DP table `dp` initialized to `0` with dimensions `(n+1) x (n+1)`:
  - `dp[currIndex][prevIndex+1]` represents the length of LIS starting at index `currIndex` with the previous element being `nums[prevIndex]`.
  - The extra `+1` in dimensions accounts for the case when `prevIndex == -1` (i.e., no previous element has been selected).
  
- **Example:** For `nums = [10, 9, 2, 5, 3, 7]`, `dp` is a `7 x 7` table initialized with `0`.



```cpp
for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
```
- **Purpose:** A loop that iterates over the array `nums` in **reverse order** starting from `currIndex = n-1` down to `currIndex = 0`.
  - This ensures that we start filling the DP table from the last index and build up to the first index.



```cpp
for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
```
- **Purpose:** A loop that iterates over the possible values of `prevIndex` in reverse order, starting from `currIndex-1` down to `prevIndex = -1` (representing the case when there is no previous element).
  - This helps explore both the possibilities: including or excluding the current element in the LIS.



```cpp
int include = 0;
```
- **Purpose:** Initializes a variable `include` to store the result if we decide to **include** the current element in the LIS.



```cpp
if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
```
- **Purpose:** A condition to check if the current element can be included in the subsequence.
  - If `prevIndex == -1`, there’s no previous element, so the current element can always be included.
  - If `nums[currIndex] > nums[prevIndex]`, the current element is larger than the last included element, so it can be included in the subsequence.
  
- **Example:** If `prevIndex = -1` and `nums[currIndex] = 5`, the element `5` can always be included. If `nums[currIndex] = 7` and `prevIndex = 2`, we check if `nums[currIndex] > nums[prevIndex]`, i.e., `7 > 5`, which is true.



```cpp
include = 1 + dp[currIndex + 1][currIndex + 1];
```
- **Purpose:** If we include the current element, we add `1` to the length of the LIS formed starting from `currIndex + 1` (next element), with the previous element being `currIndex + 1`.
  - This recursively checks the LIS excluding the current element.

- **Example:** If `nums[currIndex] = 5` and `prevIndex = -1`, include `5` and add 1 to `dp[currIndex+1][currIndex+1]`, which gives the LIS length starting from the next element after `5`.



```cpp
int exclude = dp[currIndex + 1][prevIndex + 1];
```
- **Purpose:** If we exclude the current element, the LIS length remains the same as the LIS length starting from `currIndex + 1` with the same `prevIndex`. This moves to the next element without including the current one.
  
- **Example:** If `nums[currIndex] = 5`, then the LIS length excluding `5` is `dp[currIndex + 1][prevIndex + 1]`.



```cpp
dp[currIndex][prevIndex + 1] = max(include, exclude);
```
- **Purpose:** Stores the maximum of including or excluding the current element in the DP table.
  - This ensures that we always keep the longest subsequence possible for the current `currIndex` and `prevIndex`.
  
- **Example:** If `include = 3` and `exclude = 2`, store `dp[currIndex][prevIndex + 1] = 3`.



#### **Main Function: `lengthOfLIS`**

```cpp
int lengthOfLIS(vector<int>& nums) {
```
- **Purpose:** The main function that initializes the process and calls the helper function `solve` to calculate the LIS.
  


```cpp
int n = nums.size(); // Get the size of the array.
```
- **Purpose:** Stores the size of the input array in `n`.



```cpp
return solve(nums); // Call the helper function to solve the problem.
```
- **Purpose:** Calls the helper function `solve` to calculate and return the length of the Longest Increasing Subsequence (LIS).



### **Example Execution**

#### Input: `nums = [10, 9, 2, 5, 3, 7]`

1. **Initialize DP Table:**
   - DP table dimensions are `7 x 7`, all initialized to `0`.

2. **Start Filling DP Table:**
   - For each element in reverse, check if the current element can be included or excluded, and fill in the DP table.

3. **Final Answer:**
   - The result at `dp[0][0]` gives the length of the LIS, which is `3`.

#### Output: `3` (LIS: `[2, 3, 7]`)



### **Time Complexity**

- **Time Complexity:** (O(n^2))
  - There are two nested loops: one for `currIndex` and one for `prevIndex`. For each `currIndex`, we check all possible `prevIndex` values.



### **Space Complexity**

- **Space Complexity:** (O(n^2))
  - We use a 2D DP table of size `(n+1) x (n+1)` to store the results of subproblems. The space complexity is driven by the size of this table.

---
 
## 1) Space Optimization Approach (DP)
#### **Concept:**
The Space Optimization approach for solving the Longest Increasing Subsequence (LIS) problem reduces the space complexity from **O(n^2)** (in a typical dynamic programming approach) to **O(n)**, by using only two 1D arrays (instead of a 2D DP table). The idea is to keep track of only the current and the previous state of the dynamic programming table, which allows us to optimize space while still maintaining the correctness of the algorithm.



### **Explanation of the Space Optimization Approach:**

#### **1. Problem Setup:**
We are given an array `nums`, and we want to find the length of the longest increasing subsequence (LIS). A subsequence is formed by deleting some or no elements from the array without changing the order of the remaining elements. The sequence is increasing if each subsequent element is greater than the previous one.

#### **2. Using Dynamic Programming (DP):**
In the typical DP approach, a 2D DP table is used where `dp[i][j]` represents the length of the LIS considering elements from index `i` to `j`. However, we can optimize this space by noting that to compute the LIS for any `i` (i.e., at `nums[i]`), we only need information about `i + 1` (the next row in the DP table).

Thus, instead of maintaining a 2D DP table, we can use two 1D arrays:
- **`curr[]`**: Represents the current DP state for the current index being processed.
- **`next[]`**: Represents the DP state for the next index that has been processed.


### **Step-by-Step Explanation:**

#### **Step 1: Initialization**
We initialize two 1D arrays (`curr` and `next`), both of size `n+1`, where `n` is the length of the input array `nums`. These arrays are filled with zeros. The extra space is to handle the base case (no elements).

- `curr[i]`: Represents the length of the LIS considering elements from index `i` to `n-1` (current row).
- `next[i]`: Represents the length of the LIS considering elements from index `i+1` to `n-1` (next row).

#### **Step 2: Iterating Over the Array**
We iterate over the array from right to left (starting from `n-1` down to `0`). This helps us build the solution from the end of the array to the beginning.

For each element at index `currIndex`, we iterate over the possible previous indices (`prevIndex`), ranging from `currIndex-1` down to `-1`.

- `prevIndex = -1` represents the case where no previous element is available (we can start a new subsequence from `currIndex`).

#### **Step 3: Decision Making (Including vs. Excluding)**
For each pair of indices (`currIndex`, `prevIndex`), we make two choices:

1. **Include the current element (`nums[currIndex]`)**: If the element at `nums[currIndex]` is greater than `nums[prevIndex]` (or if `prevIndex == -1`), then we can include the current element in the LIS. The value for this choice would be `1 + next[currIndex + 1]`.
   
2. **Exclude the current element**: If we decide not to include `nums[currIndex]`, the value would be simply `next[prevIndex + 1]` (representing the LIS without including `nums[currIndex]`).

We store the maximum of these two options in the `curr[prevIndex + 1]`.

#### **Step 4: Update `next` for the Next Iteration**
Once the computation for `currIndex` is complete, we update the `next` array with the values from the `curr` array. This prepares the `next` array for the next iteration.

#### **Step 5: Final Result**
After processing all elements, the result of the longest increasing subsequence for the entire array is stored in `curr[0]`.

### **Example:**

Consider the input array `nums = [10, 9, 2, 5, 3, 7, 101, 18]`.

#### **Iteration 1**:
- **`curr = [0, 0, 0, 0, 0, 0, 0, 0, 0]`**
- **`next = [0, 0, 0, 0, 0, 0, 0, 0, 0]`**

We start with the last element, and for each element, we decide whether to include or exclude it from the subsequence.

After iterating through the array, the final result is stored in `curr[0]`, which will give us the length of the LIS.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a space-optimized dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create two 1D DP arrays, `curr` and `next`, initialized with 0.
        // `curr` represents the current state, and `next` represents the state of the next row in the 2D DP table.
        vector<int> curr(n + 1, 0); 
        vector<int> next(n + 1, 0);

        // Iterate over the array in reverse order for `currIndex`.
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            // Iterate over possible values of `prevIndex` in reverse order.
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                
                // Option 1: Include the current element in the LIS.
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    // If there is no previous element or the current element is greater,
                    // include the current element in the LIS.
                    include = 1 + next[currIndex + 1];
                }

                // Option 2: Exclude the current element and proceed.
                int exclude = next[prevIndex + 1];

                // Store the maximum of including or excluding the current element in `curr`.
                curr[prevIndex + 1] = max(include, exclude);
            }

            // Update `next` to the current state for the next iteration.
            next = curr;
        }

        // The result for the entire array (starting at index 0 with no previous element) is stored in `curr[0]`.
        return curr[0];
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
```

### Source Code Explanation
```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a space-optimized dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
```

**Explanation:**
- **`int solve(vector<int>& nums)`**: This function takes a reference to a vector `nums` (the input array of integers) and calculates the length of the Longest Increasing Subsequence (LIS).
- **`int n = nums.size();`**: We store the size of the input array `nums` in the variable `n`.

**Example:**
For `nums = [10, 9, 2, 5, 3, 7, 101, 18]`, `n` will be `8` because the size of the array is 8.



```cpp
        vector<int> curr(n + 1, 0); 
        vector<int> next(n + 1, 0);
```

**Explanation:**
- **`vector<int> curr(n + 1, 0);`**: We create a vector `curr` of size `n+1` initialized to `0`. This array will store the lengths of LIS for each subproblem at the current index.
- **`vector<int> next(n + 1, 0);`**: We create another vector `next` of the same size (`n+1`) initialized to `0`. This array will store the LIS lengths for the next index in the array.

**Example:**
For `n = 8`, both `curr` and `next` will be initialized as:
```
curr = [0, 0, 0, 0, 0, 0, 0, 0, 0]
next = [0, 0, 0, 0, 0, 0, 0, 0, 0]
```



```cpp
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
```

**Explanation:**
- **`for (int currIndex = n - 1; currIndex >= 0; currIndex--)`**: We start iterating from the last index (`n-1`) down to the first index (`0`). This reverse iteration allows us to build the LIS from the end of the array to the beginning.

**Example:**
For `n = 8`, `currIndex` will start from `7` and decrement until `0`.



```cpp
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
```

**Explanation:**
- **`for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)`**: For each `currIndex`, we iterate over all previous indices (`prevIndex`) from `currIndex - 1` to `-1`. `prevIndex = -1` represents the case where there is no previous element (starting a new subsequence).

**Example:**
For `currIndex = 7`, `prevIndex` will iterate from `6` down to `-1`.



```cpp
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    include = 1 + next[currIndex + 1];
                }
```

**Explanation:**
- **`int include = 0;`**: We initialize the `include` variable to `0`. This variable will store the length of the LIS if we include `nums[currIndex]` in the subsequence.
- **`if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])`**: We check if we can include `nums[currIndex]` in the LIS:
  - If `prevIndex == -1`, there is no previous element, so we can include `nums[currIndex]`.
  - If `nums[currIndex] > nums[prevIndex]`, the current element is greater than the previous element, so we can include it.
- **`include = 1 + next[currIndex + 1];`**: If the condition is true, we include the current element, and the LIS length becomes `1 + next[currIndex + 1]`. The `1` accounts for the current element, and `next[currIndex + 1]` gives the LIS length for the next index.

**Example:**
For `currIndex = 7` and `prevIndex = 6`, if `nums[7] = 18` and `nums[6] = 101`, the condition `nums[7] > nums[6]` is false, so `include` remains `0`. If `prevIndex = -1`, the LIS length will be `1 + next[8]`.



```cpp
                int exclude = next[prevIndex + 1];
```

**Explanation:**
- **`int exclude = next[prevIndex + 1];`**: We calculate the LIS length if we exclude `nums[currIndex]`. This is simply `next[prevIndex + 1]`, which stores the LIS length when the current element is excluded.

**Example:**
If `prevIndex = 6`, `exclude` will be `next[7]`.



```cpp
                curr[prevIndex + 1] = max(include, exclude);
```

**Explanation:**
- **`curr[prevIndex + 1] = max(include, exclude);`**: We update `curr[prevIndex + 1]` with the maximum of the two choices (include or exclude). This ensures we choose the longer subsequence.

**Example:**
If `include = 3` and `exclude = 4`, `curr[prevIndex + 1]` will be updated to `4`.



```cpp
            next = curr;
```

**Explanation:**
- **`next = curr;`**: After completing the iteration for the current `currIndex`, we update `next` to be equal to `curr`. This prepares the `next` array for the next iteration where `currIndex` is decreased by 1.

**Example:**
After processing `currIndex = 7`, `next` becomes equal to `curr`.



```cpp
        }
        return curr[0];
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
```

**Explanation:**
- **`return curr[0];`**: After processing all `currIndex` values, the final result for the LIS length is stored in `curr[0]`, since it represents the LIS length for the entire array starting from index `0` with no previous element.
  
- **`int lengthOfLIS(vector<int>& nums)`**: This is the main function that simply calls the helper function `solve` to get the LIS length for the given input `nums`.



### **Example Walkthrough:**

For `nums = [10, 9, 2, 5, 3, 7, 101, 18]`:

1. Initialize `curr` and `next` arrays with zeroes.
2. Start with `currIndex = 7` (the last element).
3. For `currIndex = 7`, iterate over `prevIndex` from `6` to `-1`:
   - If `nums[7] = 18` and `nums[6] = 101`, we cannot include `18`, so we exclude it.
   - Update `curr[prevIndex + 1]` with the maximum value of including or excluding the current element.
4. Move on to the next `currIndex` and repeat the process until all elements are processed.

After processing all elements, the result stored in `curr[0]` will give the length of the longest increasing subsequence.



### **Example Output:**

For the input `nums = [10, 9, 2, 5, 3, 7, 101, 18]`, the output will be:

```
4
```

The longest increasing subsequence is `[2, 3, 7, 101]`.



### **Time and Space Complexity:**

#### **Time Complexity:**
- The outer loop runs `n` times (from `n-1` to `0`), and for each `currIndex`, the inner loop runs at most `n` times (from `currIndex-1` to `-1`).
- Therefore, the overall time complexity is **O(n^2)**.

#### **Space Complexity:**
- We use two arrays (`curr` and `next`), each of size `n+1`, so the space complexity is **O(n)**.

---

## 2) Space Optimization Approach (DP)
The given code uses a **Dynamic Programming (DP)** approach to find the length of the **Longest Increasing Subsequence (LIS)**. While the original solution typically requires a 2D DP table to store intermediate results, this solution uses a **1D DP array** to store the results for each element in the array. We will explain the approach and the space optimization in detail step by step.

### **Space Optimization Explanation**

1. **1D DP Array (`dp`)**:
   - We only need to store the length of the longest increasing subsequence **ending at each index**.
   - In this approach, the `dp[i]` array stores the length of the LIS ending at index `i`.
   - By only storing the LIS lengths at each index, we reduce the space complexity from **O(n^2)** (for a 2D table) to **O(n)** (for a single 1D array).
   
2. **Iterative Updates**:
   - We update `dp[i]` by checking all previous elements (`nums[0]` to `nums[i-1]`).
   - If an element `nums[i]` is greater than `nums[j]` (where `j < i`), we update `dp[i]` to be the maximum of its current value and `dp[j] + 1`.
   - This way, we iteratively build the LIS at each index without needing additional space for a 2D DP table.

3. **Max Value for LIS**:
   - After constructing the `dp` array, the answer is the **maximum value** in the `dp` array because it represents the longest subsequence found.

### **Space Optimization Example:**

Consider the input array: `nums = [10, 9, 2, 5, 3, 7, 101, 18]`

1. **Initialize `dp`:**
   Initially, every element is considered as its own subsequence, so `dp` is initialized as `[1, 1, 1, 1, 1, 1, 1, 1]`.

2. **Build the DP Array:**
   - At `currIndex = 1`, we check all previous elements (`prevIndex = 0`). Since `nums[1] = 9` is less than `nums[0] = 10`, `dp[1]` remains `1`.
   - At `currIndex = 2`, we check all previous elements (`prevIndex = 0` and `prevIndex = 1`). Since `nums[2] = 2` is less than both `nums[0]` and `nums[1]`, `dp[2]` remains `1`.
   - At `currIndex = 3`, we check all previous elements (`prevIndex = 0`, `prevIndex = 1`, and `prevIndex = 2`). Since `nums[3] = 5` is greater than `nums[2] = 2`, `dp[3] = dp[2] + 1 = 2`.

   Continuing in this manner, the final `dp` array will be:
   ```
   dp = [1, 1, 1, 2, 2, 3, 4, 4]
   ```

3. **Answer:**
   The maximum value in the `dp` array is `4`, which is the length of the LIS.

### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a simple dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create a 1D DP array where dp[i] represents the length of the LIS ending at index `i`.
        vector<int> dp(n, 1);

        // Iterate through the array to build the DP table.
        for (int currIndex = 1; currIndex < n; currIndex++) {
            // For each `currIndex`, check all previous indices (`prevIndex`) to find
            // the longest increasing subsequence that can be extended by `nums[currIndex]`.
            for (int prevIndex = 0; prevIndex < currIndex; prevIndex++) {
                // If the current element is greater than the previous element,
                // update dp[currIndex] to include the LIS ending at `prevIndex`.
                if (nums[currIndex] > nums[prevIndex]) {
                    dp[currIndex] = max(dp[currIndex], dp[prevIndex] + 1);
                }
            }
        }

        // The length of the LIS is the maximum value in the DP array.
        // Use `max_element` to find the maximum value in the DP array.
        return *max_element(dp.begin(), dp.end());
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
```
### Source Code Explanation

Now, let's go through the code line by line:

```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a simple dynamic programming approach.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
```

**Explanation:**
- **`int solve(vector<int>& nums)`**: This function calculates the length of the Longest Increasing Subsequence (LIS) using a dynamic programming approach.
- **`int n = nums.size();`**: We store the size of the array in the variable `n`.



```cpp
        // Create a 1D DP array where dp[i] represents the length of the LIS ending at index `i`.
        vector<int> dp(n, 1);
```

**Explanation:**
- **`vector<int> dp(n, 1);`**: We initialize a `dp` array of size `n`, with all elements set to `1`. This represents the minimum LIS length (each element is an LIS of length 1 by itself).

**Example:**
For `nums = [10, 9, 2, 5, 3, 7, 101, 18]`, the `dp` array is initialized as:
```
dp = [1, 1, 1, 1, 1, 1, 1, 1]
```



```cpp
        // Iterate through the array to build the DP table.
        for (int currIndex = 1; currIndex < n; currIndex++) {
```

**Explanation:**
- **`for (int currIndex = 1; currIndex < n; currIndex++)`**: We start iterating from the second element (`currIndex = 1`) to the last element of the array (`n-1`).



```cpp
            // For each `currIndex`, check all previous indices (`prevIndex`) to find
            // the longest increasing subsequence that can be extended by `nums[currIndex]`.
            for (int prevIndex = 0; prevIndex < currIndex; prevIndex++) {
```

**Explanation:**
- **`for (int prevIndex = 0; prevIndex < currIndex; prevIndex++)`**: For each `currIndex`, we loop through all previous indices (`prevIndex = 0` to `currIndex-1`) to find the LIS that can be extended by `nums[currIndex]`.



```cpp
                // If the current element is greater than the previous element,
                // update dp[currIndex] to include the LIS ending at `prevIndex`.
                if (nums[currIndex] > nums[prevIndex]) {
                    dp[currIndex] = max(dp[currIndex], dp[prevIndex] + 1);
                }
```

**Explanation:**
- **`if (nums[currIndex] > nums[prevIndex])`**: If `nums[currIndex]` is greater than `nums[prevIndex]`, we can extend the LIS ending at `prevIndex` by including `nums[currIndex]`.
- **`dp[currIndex] = max(dp[currIndex], dp[prevIndex] + 1);`**: We update `dp[currIndex]` to be the maximum of its current value and `dp[prevIndex] + 1`. The `+1` accounts for including `nums[currIndex]` in the LIS.



```cpp
        // The length of the LIS is the maximum value in the DP array.
        // Use `max_element` to find the maximum value in the DP array.
        return *max_element(dp.begin(), dp.end());
    }
```

**Explanation:**
- **`return *max_element(dp.begin(), dp.end());`**: After building the `dp` array, we return the maximum value in the array, which represents the length of the longest increasing subsequence.



```cpp
    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
```

**Explanation:**
- **`int lengthOfLIS(vector<int>& nums)`**: This is the main function that calls the helper function `solve` to compute the LIS for the given input array `nums`.



### **Example Walkthrough**

Let’s consider the input array:

```
nums = [10, 9, 2, 5, 3, 7, 101, 18]
```

1. **Initialize `dp`:**
   ```
   dp = [1, 1, 1, 1, 1, 1, 1, 1]
   ```

2. **Iterate and update `dp`:**
   - For `currIndex = 1`, `nums[1] = 9`, no update.
   - For `currIndex = 2`, `nums[2] = 2`, no update.
   - For `currIndex = 3`, `nums[3] = 5`, update `dp[3]` because `nums[3] > nums[2]`.
   - For `currIndex = 4`, `nums[4] = 3`, update `dp[4]` because `nums[4] > nums[2]`.

3. **Final `dp`:**
   ```
   dp = [1, 1, 1, 2, 2, 3, 4, 4]
   ```

4. **Answer:**
   The maximum value in `dp` is `4`, so the length of the LIS is `4`.

### **Example Output**

For the input `nums = [10, 9, 2, 5, 3, 7, 101, 18]`, the output will be:

```
4
```

The LIS is `[2, 3, 7, 101]`.



### **Time and Space Complexity**

#### **Time Complexity:**
- The outer loop runs `n` times (from `1` to `n-1`), and for each `currIndex`, the inner loop runs `currIndex` times.
- Therefore, the overall time complexity is **O(n^2)**.

#### **Space Complexity:**
- We use only a single `dp` array of size `n`, so the space complexity is **O(n)**.

---

## DP With Binary Search Approach
This approach optimizes the typical Dynamic Programming (DP) solution for the Longest Increasing Subsequence (LIS) problem by using binary search. The key idea is to maintain a list (`ans`) that helps track the potential elements of the LIS. This list is not necessarily the actual LIS, but it has the same length as the LIS, and we aim to find the longest subsequence efficiently.

Here’s how the approach works, step-by-step:

1. **Initialization**:
   We start with an empty vector `ans` to store the potential LIS.
   
2. **Iterating Over the Array**:
   - For each element in the input array, we check if it can extend the current LIS.
   - If the current element is larger than the last element of `ans`, it means it can extend the LIS, and we simply append it to `ans`.
   - Otherwise, we use binary search (`lower_bound`) to find the first element in `ans` that is greater than or equal to the current element, and replace that element with the current element. This ensures that `ans` always contains the smallest possible elements while maintaining the length of the LIS.

3. **Binary Search**:
   The `lower_bound` function finds the first element in the sorted `ans` that is not smaller than the current element. This replaces the element with the current element, ensuring the smallest possible values are maintained, which optimizes the length of the LIS.

4. **Final Answer**:
   The size of `ans` at the end of the iteration is the length of the Longest Increasing Subsequence because it reflects the length of the LIS formed by the array elements.

### Example Walkthrough

**Input:**
```cpp
nums = [10, 9, 2, 5, 3, 7, 101, 18]
```

**Step-by-Step Process**:

1. **Initialize `ans`** as an empty vector: `ans = []`.

2. Iterate through the array:
   - **First element (10)**: `ans` is empty, so we add 10 to `ans`: `ans = [10]`.
   - **Second element (9)**: 9 is smaller than 10, so we find the position where it fits using `lower_bound`. It will replace 10: `ans = [9]`.
   - **Third element (2)**: 2 is smaller than 9, so it replaces 9: `ans = [2]`.
   - **Fourth element (5)**: 5 is greater than 2 but smaller than the current last element in `ans` (which is 9). Using binary search, we find the position where 5 fits: `ans = [2, 5]`.
   - **Fifth element (3)**: 3 is greater than 2 but smaller than 5. It replaces 5: `ans = [2, 3]`.
   - **Sixth element (7)**: 7 is greater than 3, so we add it to `ans`: `ans = [2, 3, 7]`.
   - **Seventh element (101)**: 101 is greater than 7, so we add it to `ans`: `ans = [2, 3, 7, 101]`.
   - **Eighth element (18)**: 18 is smaller than 101, so we use binary search to find the place for 18: it replaces 101: `ans = [2, 3, 7, 18]`.

3. **Final `ans`**: `ans = [2, 3, 7, 18]` which has a size of 4.

**The length of the Longest Increasing Subsequence is 4**.

### Source Code
```cpp
nums =
### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the length of the Longest Increasing Subsequence (LIS)
    // using a more efficient approach with binary search.
    int solve(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.

        // Create a vector `ans` to store the elements of the current LIS.
        // It will not necessarily be the actual LIS but will have the same length.
        vector<int> ans;
        
        // Add the first element to the LIS tracker.
        ans.push_back(nums[0]);

        // Iterate over the rest of the elements in the array.
        for (int i = 1; i < n; i++) {
            // If the current element is greater than the last element of `ans`,
            // it extends the LIS, so add it to the end of `ans`.
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } 
            // Otherwise, replace the smallest element in `ans` that is greater than
            // or equal to the current element using `lower_bound`.
            else {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        // The size of the `ans` vector represents the length of the LIS.
        return ans.size();
    }

    // Main function to calculate the length of the Longest Increasing Subsequence (LIS).
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the array.
        return solve(nums); // Call the helper function to solve the problem.
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
```
- **`class Solution`**: This defines a class `Solution` which contains the logic for solving the problem. 
- **`public:`**: This is an access modifier, indicating that the members below it are accessible from outside the class.



#### Line 4: Helper Function Definition

```cpp
int solve(vector<int>& nums) {
```
- **`int solve(vector<int>& nums)`**: This is a helper function that takes a vector `nums` (which represents the input array) and returns the length of the Longest Increasing Subsequence (LIS).
- The function will use binary search to find the LIS length efficiently.



#### Line 5: Size of the Array

```cpp
int n = nums.size(); // Get the size of the array.
```
- **`int n = nums.size();`**: This line stores the size of the input array `nums` in the variable `n`.



#### Line 7: Initialize the Answer Vector

```cpp
vector<int> ans;
```
- **`vector<int> ans;`**: A vector `ans` is created to store the potential elements of the LIS as we process the array. This vector will represent the current LIS, but not necessarily the actual LIS values.



#### Line 9: Add First Element

```cpp
ans.push_back(nums[0]);
```
- **`ans.push_back(nums[0]);`**: The first element of `nums` is added to the `ans` vector. Initially, `ans` will contain just this one element.



#### Line 11-19: Iterate Over Remaining Elements

```cpp
for (int i = 1; i < n; i++) {
```
- **`for (int i = 1; i < n; i++)`**: This loop iterates over the remaining elements in the input array `nums` (starting from the second element).



#### Line 13-15: Check If Current Element Extends LIS

```cpp
if (nums[i] > ans.back()) {
    ans.push_back(nums[i]);
}
```
- **`if (nums[i] > ans.back())`**: This condition checks if the current element `nums[i]` is greater than the last element of the `ans` vector (`ans.back()`).
- If true, it means that `nums[i]` can extend the current LIS, so the element is added to the end of `ans` using `push_back`.



#### Line 17-19: Binary Search for Replacement

```cpp
else {
    int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
    ans[index] = nums[i];
}
```
- **`else`**: If the current element `nums[i]` cannot extend the LIS, we need to replace an element in `ans` with `nums[i]`.
- **`lower_bound(ans.begin(), ans.end(), nums[i])`**: The `lower_bound` function performs a binary search to find the position of the first element in `ans` that is **not less than** `nums[i]`. This is an efficient way to find where `nums[i]` should go.
- **`int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();`**: We store the index where `nums[i]` can be placed in `ans`.
- **`ans[index] = nums[i];`**: The element at the found index is replaced with `nums[i]`. This ensures that the LIS subsequence remains valid, and the `ans` vector always contains the smallest possible values.



#### Line 21: Return the Length of the LIS

```cpp
return ans.size();
```
- **`return ans.size();`**: After iterating through all elements of `nums`, the size of `ans` represents the length of the Longest Increasing Subsequence because `ans` contains the elements of the LIS in increasing order (though not necessarily the exact LIS).



#### Line 24: Main Function

```cpp
int lengthOfLIS(vector<int>& nums) {
    return solve(nums); // Call the helper function to solve the problem.
}
```
- **`int lengthOfLIS(vector<int>& nums)`**: This is the main function that is called to compute the length of the LIS.
- **`return solve(nums);`**: The main function calls the helper function `solve(nums)` to compute and return the length of the LIS.



### Example Walkthrough

#### Input:
```cpp
nums = [10, 9, 2, 5, 3, 7, 101, 18]
```

1. **Initialize**:
   - `ans = [10]` (The first element is added to `ans`).

2. **First iteration (i = 1)**:
   - `nums[1] = 9`
   - `9 < 10` → Use binary search to find where to replace 10 in `ans`.
   - `ans = [9]`

3. **Second iteration (i = 2)**:
   - `nums[2] = 2`
   - `2 < 9` → Replace `9` with `2`.
   - `ans = [2]`

4. **Third iteration (i = 3)**:
   - `nums[3] = 5`
   - `5 > 2` → Add `5` to `ans`.
   - `ans = [2, 5]`

5. **Fourth iteration (i = 4)**:
   - `nums[4] = 3`
   - `3 > 2` but `3 < 5` → Replace `5` with `3`.
   - `ans = [2, 3]`

6. **Fifth iteration (i = 5)**:
   - `nums[5] = 7`
   - `7 > 3` → Add `7` to `ans`.
   - `ans = [2, 3, 7]`

7. **Sixth iteration (i = 6)**:
   - `nums[6] = 101`
   - `101 > 7` → Add `101` to `ans`.
   - `ans = [2, 3, 7, 101]`

8. **Seventh iteration (i = 7)**:
   - `nums[7] = 18`
   - `18 < 101` → Replace `101` with `18`.
   - `ans = [2, 3, 7, 18]`

At the end of the loop, the length of `ans` is 4, which is the length of the Longest Increasing Subsequence.

#### Output:
```
Length of LIS: 4
```

### Time and Space Complexity

- **Time Complexity**: `O(n log n)`
  - The loop runs `n` times (for each element in `nums`).
  - Each call to `lower_bound` is `O(log n)` because `lower_bound` uses binary search on the `ans` vector.
  - Hence, the total time complexity is `O(n log n)`.

- **Space Complexity**: `O(n)`
  - We use an additional vector `ans` to store potential elements of the LIS, which could contain up to `n` elements.
  - Thus, the space complexity is `O(n)`.

This approach is efficient compared to the traditional DP solution, which would have a time complexity of `O(n^2)`.
