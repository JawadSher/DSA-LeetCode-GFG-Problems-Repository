<h1 align="center">Minimum - Swaps To - Make Sequences - Increasing</h1>

## Problem Statement

**Problem URL :** [Minimum Swaps To Make Sequences Increasing](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/)

![image](https://github.com/user-attachments/assets/ba5c93c0-294e-4932-af16-200830a2759e)

### Problem Explanation
The problem **"Minimum Swaps to Make Sequences Increasing"** from LeetCode requires you to determine the minimum number of swaps needed to make two integer sequences strictly increasing. Let’s break it down in detail:

### **Problem Statement**

You are given two integer arrays, `nums1` and `nums2`, both of the same length `n`.  
- You can **swap** the values at the same index between the two arrays (i.e., swap `nums1[i]` with `nums2[i]`).
- Your goal is to make both arrays strictly increasing, meaning:
  - `nums1[i] > nums1[i-1]` for all `i > 0`
  - `nums2[i] > nums2[i-1]` for all `i > 0`

Return the **minimum number of swaps** required to achieve this condition.

### **Key Points**
1. The sequences must be strictly increasing:
   - For `nums1`: `nums1[1] > nums1[0], nums1[2] > nums1[1]`, and so on.
   - For `nums2`: `nums2[1] > nums2[0], nums2[2] > nums2[1]`, and so on.
2. You can swap values **only at the same index**.
3. Swapping is optional, but it must be done strategically to minimize the total swaps.

### **Examples**

#### **Example 1:**

**Input:**  
`nums1 = [1, 3, 5, 4]`  
`nums2 = [1, 2, 3, 7]`  

**Output:**  
`1`  

**Explanation:**  
- Initially:  
  `nums1 = [1, 3, 5, 4]`  
  `nums2 = [1, 2, 3, 7]`

- At index `3`, the sequences are not strictly increasing because:
  - `nums1[3] = 4` is not greater than `nums1[2] = 5`.
  - `nums2[3] = 7` is greater than `nums2[2] = 3`.

- To fix this, swap `nums1[3]` and `nums2[3]`:  
  `nums1 = [1, 3, 5, 7]`  
  `nums2 = [1, 2, 3, 4]`

Now both arrays are strictly increasing. The minimum swaps required is **1**.

#### **Example 2:**

**Input:**  
`nums1 = [0, 3, 5, 8, 9]`  
`nums2 = [2, 1, 4, 6, 9]`  

**Output:**  
`1`  

**Explanation:**  
- Initially:  
  `nums1 = [0, 3, 5, 8, 9]`  
  `nums2 = [2, 1, 4, 6, 9]`

- At index `1`, the sequences are not strictly increasing because:
  - `nums2[1] = 1` is not greater than `nums2[0] = 2`.

- To fix this, swap `nums1[1]` and `nums2[1]`:  
  `nums1 = [0, 1, 5, 8, 9]`  
  `nums2 = [2, 3, 4, 6, 9]`

Now both arrays are strictly increasing. The minimum swaps required is **1**.

### **Approach**

The key to solving the problem is to decide at each index whether to:
1. **Keep the elements as they are (no swap)**, or
2. **Swap the elements at the current index**.

#### **Conditions to Check**
For any index `i`, there are two scenarios to consider:
1. **No Swap Needed**:  
   This is possible if:
   - `nums1[i] > nums1[i-1]` and `nums2[i] > nums2[i-1]` (both arrays remain strictly increasing without swapping).

3. **Swap Needed**:  
   This is possible if:
   - `nums1[i] > nums2[i-1]` and `nums2[i] > nums1[i-1]` (swapping still keeps both arrays strictly increasing).

---

## Recursive Approach (caused TLE)
The recursive approach aims to determine the minimum number of swaps needed to make two arrays strictly increasing. Here's how it works:

1. **Problem Breakdown**:
   At each index `i`, we decide whether to:
   - Keep the elements as they are (no swap).
   - Swap the elements at the current index.

2. **Key Observations**:
   - **No Swap Condition**: If the current elements (`nums1[i]` and `nums2[i]`) are greater than their respective previous elements (`nums1[i-1]` and `nums2[i-1]`), the arrays are already increasing without a swap.
   - **Swap Condition**: If swapping the current elements still maintains the increasing order, swapping is a valid option.

3. **Recursive Decision**:
   - Check both conditions and compute the result for each.
   - Use recursion to move to the next index and repeat the process.


### **Step-by-Step Explanation with Example**

#### Example Input:
```cpp
nums1 = [1, 3, 5, 4];
nums2 = [1, 2, 3, 7];
```

#### Execution:
1. **Add Dummy Values**:
   - Insert `-1` at the start of both arrays:
     ```
     nums1 = [-1, 1, 3, 5, 4]
     nums2 = [-1, 1, 2, 3, 7]
     ```
   - This simplifies the comparison at the first index.

2. **Recursive Traversal**:
   - Start at index `1`.
   - Check the **No Swap Condition** and **Swap Condition** for each index and recurse accordingly.

3. **Recursive Calls**:
   - **Index 1**: No swap is valid. Move to the next index.
   - **Index 2**: No swap is valid. Move to the next index.
   - **Index 3**: No swap breaks the order (`nums1[3] = 5` is not greater than `nums1[2] = 5`). Consider swapping:
     - After swapping, `nums1 = [-1, 1, 3, 7, 4]`, `nums2 = [-1, 1, 2, 5, 3]`. The arrays are now increasing.
   - **Index 4**: Both conditions are checked, and the minimum swaps are computed.

4. **Base Case**:
   - When the index reaches the end of the arrays, return `0` as no further swaps are needed.

#### Result:
The minimum number of swaps is **1**.

### Source Code
```cpp
class Solution {
public:
    // Recursive helper function to solve the problem
    // `nums1` and `nums2` are the input arrays
    // `index` represents the current position in the arrays
    // `n` is the size of the arrays
    // `swapped` indicates if the previous elements were swapped
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
        // Base case: if we reach the end of the arrays, no swaps are needed
        if (index >= n) return 0;

        // Initialize the minimum swaps required as a large value
        int ans = INT_MAX;

        // Retrieve the previous elements in both arrays
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // If the previous elements were swapped, reverse them
        if (swapped) swap(prev1, prev2);

        // Case 1: No swap at the current index
        // Check if the current elements maintain the increasing order without a swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, n, 0);

        // Case 2: Swap at the current index
        // Check if swapping the current elements maintains the increasing order
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, n, 1));

        // Return the minimum number of swaps required
        return ans;
    }

    // Main function to find the minimum number of swaps needed
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of both arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Initialize the swapped flag as false
        bool swapped = 0;

        // Start solving from the first actual element
        return solve(nums1, nums2, 1, n, swapped);
    }
};
```

### Source Code Explanation

#### **Function `solve`**

1. **Base Case**:
   ```cpp
   if (index >= n) return 0;
   ```
   - If the current index exceeds the array size, no swaps are needed.
   - **Example**: For `nums1 = [-1, 1, 3, 5, 4]` at index `5`, return `0`.

2. **Initialize `ans`**:
   ```cpp
   int ans = INT_MAX;
   ```
   - Set `ans` to a large value to track the minimum swaps.

3. **Retrieve Previous Elements**:
   ```cpp
   int prev1 = nums1[index - 1];
   int prev2 = nums2[index - 1];
   ```
   - Get the previous elements for comparison.
   - **Example**: At index `3`, `prev1 = nums1[2] = 3`, `prev2 = nums2[2] = 2`.

4. **Handle Swapped Case**:
   ```cpp
   if (swapped) swap(prev1, prev2);
   ```
   - If the previous elements were swapped, reverse them.

5. **No Swap Case**:
   ```cpp
   if (nums1[index] > prev1 && nums2[index] > prev2)
       ans = solve(nums1, nums2, index + 1, n, 0);
   ```
   - Check if the current elements maintain the increasing order without swapping.
   - **Example**: At index `2`, `nums1[2] = 3 > 1` and `nums2[2] = 2 > 1`.

6. **Swap Case**:
   ```cpp
   if (nums1[index] > prev2 && nums2[index] > prev1)
       ans = min(ans, 1 + solve(nums1, nums2, index + 1, n, 1));
   ```
   - Check if swapping maintains the increasing order. If valid, compute the swaps.
   - **Example**: At index `3`, swapping results in valid arrays:
     ```
     nums1 = [-1, 1, 3, 7, 4]
     nums2 = [-1, 1, 2, 5, 3]
     ```

7. **Return the Result**:
   ```cpp
   return ans;
   ```



### **Example Output Explained**

#### Example Input:
```cpp
nums1 = [1, 3, 5, 4];
nums2 = [1, 2, 3, 7];
```

**Steps**:
1. Traverse the arrays recursively.
2. Decide whether to swap or not at each index.
3. Compute the minimum swaps required at each step.

**Final Arrays**:
- After 1 swap:
  ```
  nums1 = [1, 3, 5, 7]
  nums2 = [1, 2, 3, 4]
  ```

**Output**:
```cpp
1
```



### **Time and Space Complexity**

1. **Time Complexity**:
   - The recursion processes each index once.
   - At each index, it performs constant operations.
   - **Complexity**: (O(n)), where (n) is the length of the arrays.

2. **Space Complexity**:
   - The recursion uses the call stack for (O(n)) levels.
   - **Complexity**: (O(n)).

**Optimized Version**: Using dynamic programming, the space complexity can be reduced to (O(1)).

---

## Top-Down Approach (DP)
The **minimum swaps problem** involves ensuring that two arrays `nums1` and `nums2` are strictly increasing. At each position, you can either **swap** the elements between the two arrays or leave them as they are. The goal is to find the minimum number of swaps required to achieve this.

### **Step-by-Step Approach**

#### **1. Problem Restatement**
We have two integer arrays:
- `nums1 = [1, 3, 5, 4]`
- `nums2 = [1, 2, 3, 7]`

We need to make sure:
- `nums1[i] > nums1[i-1]` (strictly increasing order in `nums1`).
- `nums2[i] > nums2[i-1]` (strictly increasing order in `nums2`).

At each step, we can:
1. Keep both elements as they are (**no swap**).
2. Swap the elements at index `i` between the arrays (**swap**).

#### **2. Recursive Approach**
We solve the problem recursively with memoization:
1. Start from the first element (index `1`) and decide whether to swap or not.
2. Check both options at every index:
   - Case 1: No swap
   - Case 2: Swap
3. Use **memoization** to store results of overlapping subproblems.

#### **3. Base Case**
When we reach the end of the arrays (`index >= n`), no swaps are required, and we return `0`.

#### **4. State Variables**
We use:
- `index`: The current position in the arrays.
- `swapped`: A flag (`0` or `1`) indicating whether the previous elements were swapped.
- `dp[index][swapped]`: The minimum swaps needed starting from `index` with the current state of `swapped`.

#### **5. Key Decisions**
At each index:
1. **No Swap**:
   - Check if `nums1[index] > nums1[index-1]` and `nums2[index] > nums2[index-1]`.
   - If true, recursively calculate the result for the next index without swapping.

2. **Swap**:
   - Check if swapping maintains the strictly increasing order:
     - `nums1[index] > nums2[index-1]` and `nums2[index] > nums1[index-1]`.
   - If true, recursively calculate the result for the next index with a swap, adding `1` to the swap count.

### Source Code
```cpp
class Solution {
public:
    // Recursive helper function to solve the problem
    // `nums1` and `nums2` are the input arrays
    // `index` represents the current position in the arrays
    // `n` is the size of the arrays
    // `swapped` indicates if the previous elements were swapped
    // `dp` is the memoization table to store results of subproblems
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped, vector<vector<int>>& dp) {
        // Base case: if we reach the end of the arrays, no swaps are needed
        if (index >= n) return 0;

        // Check if the current subproblem has already been solved
        if (dp[index][swapped] != -1) return dp[index][swapped];

        // Initialize the minimum swaps required as a large value
        int ans = INT_MAX;

        // Retrieve the previous elements in both arrays
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // If the previous elements were swapped, reverse them
        if (swapped) swap(prev1, prev2);

        // Case 1: No swap at the current index
        // Check if the current elements maintain the increasing order without a swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, n, 0, dp);

        // Case 2: Swap at the current index
        // Check if swapping the current elements maintains the increasing order
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, n, 1, dp));

        // Store the result in the memoization table and return
        return dp[index][swapped] = ans;
    }

    // Main function to find the minimum number of swaps needed
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of both arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Initialize the memoization table with -1 (unvisited state)
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start solving from the first actual element
        bool swapped = 0;
        return solve(nums1, nums2, 1, n, swapped, dp);
    }
};
```
### Source Code Explanation

Here is the given source code with a detailed explanation line by line.

```cpp
class Solution {
public:
    // Recursive helper function to solve the problem
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped, vector<vector<int>>& dp) {
        // Base case: If we reach the end of the arrays, no swaps are needed
        if (index >= n) return 0;
```

- **Line 1-3**: A helper function `solve` is defined to handle the recursion.
- **Line 4**: The base case ensures we stop recursion when `index` reaches the end of the arrays. No swaps are needed, so we return `0`.



```cpp
        // Memoization: Return the result if already calculated
        if (dp[index][swapped] != -1) return dp[index][swapped];
```

- **Memoization Check**: Before performing calculations, check if the current state (`index`, `swapped`) has been solved. If so, return the stored result from the `dp` table.



```cpp
        int ans = INT_MAX; // Initialize answer with a large value
```

- **Initialize Answer**: Set the initial answer to a very large value (`INT_MAX`), as we are minimizing the number of swaps.



```cpp
        // Retrieve the previous elements
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // If the previous elements were swapped, reverse them
        if (swapped) swap(prev1, prev2);
```

- **Retrieve Previous Elements**: `prev1` and `prev2` represent the elements at the previous index.
- **Adjust for Swapping**: If the previous step involved swapping, swap the values of `prev1` and `prev2`.



```cpp
        // Case 1: No swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, n, 0, dp);
```

- **No Swap Case**: If no swap is performed, ensure that the current elements maintain the increasing order.
  - `nums1[index] > prev1`: Ensures `nums1` is still increasing.
  - `nums2[index] > prev2`: Ensures `nums2` is still increasing.



```cpp
        // Case 2: Swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, n, 1, dp));
```

- **Swap Case**: If swapping maintains the increasing order, calculate the result for the next index with a swap (`1 + solve(...)`).



```cpp
        // Memoize the result
        return dp[index][swapped] = ans;
    }
```

- **Store the Result**: Save the minimum swaps for the current state in `dp` to avoid redundant calculations.



```cpp
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1); // Add dummy values
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size(); // Get the size of the arrays
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Initialize memoization table

        return solve(nums1, nums2, 1, n, 0, dp); // Start from index 1 with no swaps
    }
};
```

- **Dummy Values**: Add `-1` at the beginning of both arrays to simplify comparisons.
- **Memoization Table**: Initialize a 2D vector `dp` with `-1` to store results.
- **Solve Function**: Start solving from index `1` with no swaps (`swapped = 0`).



### **Example Execution**

#### Input:
`nums1 = [1, 3, 5, 4]`  
`nums2 = [1, 2, 3, 7]`

#### Steps:
1. Add dummy values:
   - `nums1 = [-1, 1, 3, 5, 4]`
   - `nums2 = [-1, 1, 2, 3, 7]`

2. Explore both "no swap" and "swap" cases recursively:
   - At index `3`, a swap is required to maintain increasing order.

3. Memoization stores intermediate results, avoiding redundant calculations.

#### Output:
`1` (One swap is required).



### **Time Complexity**

1. **Number of States**:
   - Each `index` has two possible states (`swapped = 0 or 1`).
   - Total states = `n * 2`.

2. **Per State Computation**:
   - Each state involves a constant number of comparisons and recursive calls.

**Time Complexity**: `O(n)`.



### **Space Complexity**

1. **Memoization Table**: `O(n * 2) = O(n)`.
2. **Recursion Stack**: `O(n)` (for the depth of recursion).

**Total Space Complexity**: `O(n)`.

---

## Bottom-Up Approach (DP)
The **Bottom-Up Approach** solves the minimum swaps problem iteratively using a **dynamic programming (DP) table**. It starts solving from the end of the arrays and works backward to determine the minimum number of swaps needed at each index.



### **Step-by-Step Approach**

#### **1. Problem Restatement**
Given two integer arrays:
- `nums1 = [1, 3, 5, 4]`
- `nums2 = [1, 2, 3, 7]`

We need to ensure:
- `nums1[i] > nums1[i-1]` (strictly increasing order in `nums1`).
- `nums2[i] > nums2[i-1]` (strictly increasing order in `nums2`).

At each position, you can either:
1. Keep the elements as they are (**no swap**).
2. Swap the elements at index `i` (**swap**).

The goal is to find the minimum number of swaps required to maintain these conditions for both arrays.



#### **2. Dynamic Programming (DP) Table**
We define a 2D DP table:
- `dp[i][0]`: Minimum swaps required starting at index `i` when no swap is made at `i-1`.
- `dp[i][1]`: Minimum swaps required starting at index `i` when a swap is made at `i-1`.

#### **3. State Transitions**
At each index `i`:
1. **Case 1: No Swap at `i`**
   - This is valid if `nums1[i] > nums1[i-1]` and `nums2[i] > nums2[i-1]`.
   - If valid, `dp[i][0] = dp[i+1][0]` (carry over the swaps from the next index).

2. **Case 2: Swap at `i`**
   - This is valid if `nums1[i] > nums2[i-1]` and `nums2[i] > nums1[i-1]`.
   - If valid, `dp[i][1] = 1 + dp[i+1][1]` (add one swap to the swaps needed from the next index).



#### **4. Initialization**
We add dummy elements `-1` at the beginning of both arrays to simplify boundary conditions:
- `nums1 = [-1, 1, 3, 5, 4]`
- `nums2 = [-1, 1, 2, 3, 7]`

At the end of the arrays (`i = n`), no swaps are required:
- `dp[n][0] = dp[n][1] = 0`.



#### **5. Final Result**
The result is found at `dp[1][0]`, representing the minimum swaps needed starting from the first actual element without a swap.

### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem iteratively using bottom-up dynamic programming
    // `nums1` and `nums2` are the input arrays
    // `index` represents the current position in the arrays
    // `n` is the size of the arrays
    // `swapped` indicates whether the elements were swapped
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
        // Create a DP table with dimensions [n+1][2]
        // `dp[i][0]` represents the minimum swaps required starting at index `i` when no swap is made at `i-1`
        // `dp[i][1]` represents the same but when a swap is made at `i-1`
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Start filling the DP table from the last index towards the first
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX; // Initialize the minimum swaps for the current state to a large value

                // Determine the previous elements
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // If the previous state involved a swap, adjust `prev1` and `prev2`
                if (swapped) swap(prev1, prev2);

                // Case 1: No swap at the current index
                // Check if the current elements maintain the increasing order without a swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];

                // Case 2: Swap at the current index
                // Check if swapping the current elements maintains the increasing order
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);

                // Store the result in the DP table for the current index and swap state
                dp[index][swapped] = ans;
            }
        }

        // Return the minimum swaps required starting from the first actual element without a swap
        return dp[1][0];
    }

    // Main function to find the minimum number of swaps needed
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of both arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Initialize the process by calling the iterative DP function
        bool swapped = 0;
        return solve(nums1, nums2, 1, n, swapped);
    }
};
```

### Source Code Explanation

Here is the code with line-by-line explanations.

```cpp
class Solution {
public:
    // Function to solve the problem iteratively using bottom-up dynamic programming
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
        // Create a DP table with dimensions [n+1][2]
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
```

- **DP Table Creation**: The table `dp[n+1][2]` is initialized with dimensions based on the size of the arrays (`n+1` for ease of handling indices, `2` for swapped and non-swapped states).



```cpp
        // Start filling the DP table from the last index towards the first
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX; // Initialize the minimum swaps for the current state to a large value
```

- **Filling the Table**: Start from the last index (`n-1`) and work backward.  
- **State Iteration**: For each index, calculate both `swapped` (`1`) and `not swapped` (`0`) states.  
- **Initialize Answer**: Start with a large value (`INT_MAX`) for each state, which will be minimized during calculations.



```cpp
                // Determine the previous elements
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // If the previous state involved a swap, adjust `prev1` and `prev2`
                if (swapped) swap(prev1, prev2);
```

- **Previous Elements**: Retrieve elements at the previous index (`prev1`, `prev2`).  
- **Adjust for Swapping**: If the previous state involved a swap, reverse `prev1` and `prev2`.



```cpp
                // Case 1: No swap at the current index
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];
```

- **No Swap Case**: Ensure `nums1[index] > prev1` and `nums2[index] > prev2`.  
- **Transition**: Set `ans = dp[index+1][0]` (carry over swaps from the next index without a swap).



```cpp
                // Case 2: Swap at the current index
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);
```

- **Swap Case**: Ensure `nums1[index] > prev2` and `nums2[index] > prev1`.  
- **Transition**: Set `ans = min(ans, 1 + dp[index+1][1])` (add one swap to the result of the next index with a swap).



```cpp
                // Store the result in the DP table for the current index and swap state
                dp[index][swapped] = ans;
            }
        }
```

- **Store Results**: Save the computed `ans` for the current index and swap state in the DP table.



```cpp
        // Return the minimum swaps required starting from the first actual element without a swap
        return dp[1][0];
    }
```

- **Final Result**: Return `dp[1][0]` as the minimum swaps starting from index `1` without a swap.



```cpp
    // Main function to find the minimum number of swaps needed
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1); // Insert dummy value
        nums2.insert(nums2.begin(), -1); // Insert dummy value

        int n = nums1.size(); // Get the size of the arrays
        bool swapped = 0; // Initialize the swapped state
        return solve(nums1, nums2, 1, n, swapped); // Start solving from index 1
    }
};
```

- **Dummy Values**: Add `-1` at the beginning of both arrays to simplify comparisons.  
- **Start Solving**: Call the `solve` function with the initial conditions.



### **Example Execution**

#### Input:
`nums1 = [1, 3, 5, 4]`  
`nums2 = [1, 2, 3, 7]`

#### Steps:
1. Add dummy values:
   - `nums1 = [-1, 1, 3, 5, 4]`
   - `nums2 = [-1, 1, 2, 3, 7]`

2. Fill the DP table:
   - Start from the last index and work backward.
   - Explore both "no swap" and "swap" options at each index.

3. Result:
   - `dp[1][0] = 1`.

#### Output:
`1` (One swap is required).



### **Time Complexity**

1. **DP Table Size**: `O(n)` states (`n` indices and `2` swap states per index).  
2. **Per State Computation**: Each state involves constant-time comparisons.

**Time Complexity**: `O(n)`.



### **Space Complexity**

1. **DP Table**: `O(n * 2) = O(n)` for storing results.  

**Total Space Complexity**: `O(n)`.

---

## Space Optimization Approach (DP)
The **Space Optimized Approach** reduces the memory usage while solving the problem using an iterative dynamic programming technique. This is achieved by maintaining only the necessary states from the previous iteration, thus avoiding the need for a complete DP table. Below is a detailed walkthrough:

#### **Approach Overview**
The problem is to make two arrays strictly increasing with the minimum number of swaps. This approach:
1. Uses two variables (`swap` and `noswap`) to track the results of the previous state instead of a full DP table.
2. Iterates from the end of the arrays to the start.
3. Updates the results iteratively, minimizing the swaps at each step.



### **Code Walkthrough**

#### **Key Steps**

1. **State Initialization**  
   - Two arrays (`nums1` and `nums2`) are extended with a dummy value `-1` at the start for easy comparisons.  
   - Two variables, `swap` and `noswap`, are initialized to `0`. They represent:
     - `swap`: Minimum swaps required if a swap was made at the previous index.
     - `noswap`: Minimum swaps required if no swap was made at the previous index.  

2. **Iterating from Back to Front**  
   - The algorithm processes the arrays starting from the second last index (`n-1`) backward to the first index.
   - Two new variables, `currswap` and `currnoswap`, store the results for the current index.

3. **Checking Conditions**
   - **No Swap at Current Index**:  
     If the current elements maintain the increasing order, update `currnoswap` with the previous `noswap`.
   - **Swap at Current Index**:  
     If swapping the current elements maintains the increasing order, update `currswap` with the minimum of the previous `swap` plus 1.

4. **Update States**
   - After processing all cases for the current index, update the `swap` and `noswap` values to `currswap` and `currnoswap`.

5. **Result**
   - After iterating through all indices, the minimum of `swap` and `noswap` gives the final result.

### Source Code
```cpp
class Solution {
public:
    // Function to solve the problem iteratively with optimized space
    // `nums1` and `nums2` are the input arrays
    // `index` is the starting index for processing
    // `n` is the size of the arrays
    // `swapped` is the initial state indicating whether a swap was performed
    int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
        // DP arrays to store the results of the current and previous states
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Variables to store the state of swapping for the previous index
        int swap = 0;    // Minimum swaps needed if the previous state involved a swap
        int noswap = 0;  // Minimum swaps needed if the previous state did not involve a swap
        int currswap = 0;    // Current state when a swap occurs
        int currnoswap = 0;  // Current state when no swap occurs

        // Iterate backwards from the second last index to the first index
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX; // Initialize the minimum swaps for this state

                // Determine the previous elements
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // Adjust previous elements if the previous state was swapped
                if (swapped) {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                // Case 1: No swap at the current index
                // Check if the current elements maintain the increasing order without a swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noswap;

                // Case 2: Swap at the current index
                // Check if swapping the current elements maintains the increasing order
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + swap);

                // Update the current state variables
                if (swapped)
                    currswap = ans; // If current state involves a swap
                else
                    currnoswap = ans; // If current state does not involve a swap
            }

            // Update the previous state variables for the next iteration
            swap = currswap;
            noswap = currnoswap;
        }

        // Return the minimum swaps needed starting from index 1 without a swap
        return min(swap, noswap);
    }

    // Main function to find the minimum number of swaps required
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // Insert dummy values at the start of the arrays to simplify comparisons
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // Get the size of the arrays
        int n = nums1.size();

        // Call the solve function to compute the result
        bool swapped = 0;
        return solve(nums1, nums2, 1, n, swapped);
    }
};
```

### Source Code Explanation

### **Class Definition**

```cpp
class Solution {
```
- **Line 1**: Defines the `Solution` class where the solution for the problem will be implemented.



### **Main Function `minSwap`**

```cpp
int minSwap(vector<int>& nums1, vector<int>& nums2) {
```
- **Line 2**: The main function `minSwap` is defined to find the minimum number of swaps required. It takes two arrays, `nums1` and `nums2`, as input.

```cpp
nums1.insert(nums1.begin(), -1);
nums2.insert(nums2.begin(), -1);
```
- **Lines 3-4**: These lines insert a dummy value `-1` at the beginning of both `nums1` and `nums2`. This is done to simplify comparisons, as it eliminates the need to check if the previous elements are in bounds (since there are no comparisons with index `0` due to the dummy value).

**Example:**
- If `nums1 = [1, 3, 5, 4, 2]` and `nums2 = [1, 2, 3, 6, 7]`, after inserting the dummy value, both arrays will become:
  - `nums1 = [-1, 1, 3, 5, 4, 2]`
  - `nums2 = [-1, 1, 2, 3, 6, 7]`

```cpp
int n = nums1.size();
```
- **Line 5**: `n` is set to the size of the `nums1` array (which is the same size as `nums2` after inserting the dummy value).



### **Calling `solve` Function**

```cpp
bool swapped = 0;
return solve(nums1, nums2, 1, n, swapped);
```
- **Line 6**: Initializes the `swapped` variable to `0` (indicating that no swap is performed initially).
- **Line 7**: Calls the `solve` function with the arguments:
  - `nums1`, `nums2` (the input arrays),
  - `1` (the starting index, skipping the dummy value),
  - `n` (the size of the arrays),
  - `swapped` (indicating the initial state where no swap is made).



### **Solve Function (`solve`)**

```cpp
int solve(vector<int>& nums1, vector<int>& nums2, int index, int n, bool swapped) {
```
- **Line 8**: The `solve` function is defined to handle the logic for calculating the minimum swaps iteratively, using dynamic programming with optimized space. It receives the following parameters:
  - `nums1`, `nums2`: The arrays representing the input values.
  - `index`: The current index to process (starting from 1).
  - `n`: The size of the arrays.
  - `swapped`: A flag to indicate whether the previous elements were swapped or not.

```cpp
int swap = 0;    // Minimum swaps if previous state was swapped
int noswap = 0;  // Minimum swaps if previous state was not swapped
int currswap = 0;    // Current state when a swap occurs
int currnoswap = 0;  // Current state when no swap occurs
```
- **Lines 9-12**: The variables `swap`, `noswap`, `currswap`, and `currnoswap` are initialized to `0`. These variables track the number of swaps required for different states:
  - `swap`: Minimum swaps if the previous index involved a swap.
  - `noswap`: Minimum swaps if the previous index did not involve a swap.
  - `currswap`: Tracks the minimum swaps required for the current index if the current state involves a swap.
  - `currnoswap`: Tracks the minimum swaps required for the current index if the current state does not involve a swap.

```cpp
for (int index = n - 1; index >= 1; index--) {
```
- **Line 13**: A loop that iterates backward from the second last index (`n-1`) to the first index (`1`). The loop processes the elements from the end of the arrays to the start.

```cpp
for (int swapped = 1; swapped >= 0; swapped--) {
```
- **Line 14**: A second loop for iterating over two cases: `swapped = 1` (if the previous elements were swapped) and `swapped = 0` (if the previous elements were not swapped).

```cpp
int ans = INT_MAX; // Initialize minimum swaps for this state
```
- **Line 15**: Initializes a variable `ans` to `INT_MAX`, which will hold the minimum swaps required for the current state (we will minimize this value as we process the conditions).

```cpp
int prev1 = nums1[index - 1];
int prev2 = nums2[index - 1];
```
- **Lines 16-17**: `prev1` and `prev2` are assigned the values from the previous index (one position before the current `index`). These values will be used for comparing the current elements to maintain the strictly increasing order.

```cpp
if (swapped) {
    int temp = prev2;
    prev2 = prev1;
    prev1 = temp;
}
```
- **Lines 18-21**: If the `swapped` flag is `1` (i.e., the previous elements were swapped), the values of `prev1` and `prev2` are swapped to reflect the correct order.

**Example:**
- If `nums1 = [-1, 1, 3, 5, 4, 2]` and `nums2 = [-1, 1, 2, 3, 6, 7]`, and we are checking at index 2 (where `prev1 = 3` and `prev2 = 2`), if `swapped = 1`, then `prev1` becomes `2` and `prev2` becomes `3`.

```cpp
if (nums1[index] > prev1 && nums2[index] > prev2)
    ans = noswap;
```
- **Line 22**: This condition checks if the current elements (`nums1[index]` and `nums2[index]`) maintain a strictly increasing order without a swap. If they do, the result is the same as `noswap`, which means no swap is needed at the current index.

```cpp
if (nums1[index] > prev2 && nums2[index] > prev1)
    ans = min(ans, 1 + swap);
```
- **Line 23**: This condition checks if swapping the current elements (`nums1[index]` and `nums2[index]`) will maintain a strictly increasing order. If it does, the result is the minimum of the current `ans` and `1 + swap`, meaning one swap is added to the previous swap count.

```cpp
if (swapped)
    currswap = ans; // For swap state
else
    currnoswap = ans; // For no swap state
```
- **Lines 24-26**: Depending on the value of `swapped`, either `currswap` or `currnoswap` is updated with the minimum number of swaps calculated for the current state.

```cpp
swap = currswap;
noswap = currnoswap;
```
- **Lines 27-28**: After processing the current index, the `swap` and `noswap` variables are updated for the next iteration to reflect the results of the current state.



### **Final Result**

```cpp
return min(swap, noswap);
```
- **Line 29**: After completing all iterations, the function returns the minimum value between `swap` and `noswap`, which represents the minimum number of swaps required to make both arrays strictly increasing.



### **Time Complexity**

- **Time Complexity**:  
  The solution iterates through the array once in a backward manner, performing constant-time operations inside the inner loop. Hence, the time complexity is **O(n)** where `n` is the size of the input arrays.

### **Space Complexity**

- **Space Complexity**:  
  Since we are using only a few variables (`swap`, `noswap`, `currswap`, `currnoswap`) and not maintaining a full DP table, the space complexity is **O(1)**, which is constant space.

