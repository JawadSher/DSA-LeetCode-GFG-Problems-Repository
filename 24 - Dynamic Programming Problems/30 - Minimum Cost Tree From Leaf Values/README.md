<h1 align="center">Minimum - Cost Tree - From Leaf - Values</h1>

## Problem Statement

**Problem URL :** [Minimum Cost Tree From Leaf Values](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

![image](https://github.com/user-attachments/assets/fa974525-01fb-4989-8f64-8d1fa428e119)

### Problem Explanation
You are given an **array of integers**, and your task is to **build a binary tree** using these integers as the leaf nodes. The internal nodes of the tree are created by taking the product of the **maximum values** from the left and right subtrees. 

The goal is to minimize the **total cost** of constructing the tree. The **cost** is defined as the sum of the products of the maximum values of the left and right subtrees at each internal node.

### Explanation:

#### **Leaf Nodes**:
The elements of the array become the leaf nodes of the tree.

#### **Internal Nodes**:
- Each internal node is computed as the product of the maximum values of its left and right subtrees.
- At each internal node, the **value** is determined by the product of the largest element in the left subtree and the largest element in the right subtree.
  
#### **Cost of the Tree**:
- The **cost** of the tree is the sum of the values of the internal nodes. Since each internal node is formed by the product of the maximum values of its left and right subtrees, the cost is calculated as the sum of those products at each internal node.

### Example:

Let’s take an example to understand the problem better.

**Example 1:**

Let the given array of leaf values be `[6, 2, 4]`.

1. The **leaf nodes** are simply the values in the array, so the tree will have the leaf nodes `6`, `2`, and `4`.
   
2. The **internal nodes** are formed by combining these leaf values. For example:
   - The internal node formed by combining `6` and `2, 4` would have a value of `max(6) * max(2, 4) = 6 * 4 = 24`.
   - The internal node formed by combining `6, 2` and `4` would have a value of `max(6, 2) * max(4) = 6 * 4 = 24`.

   So, we need to compute the **total cost** for all these combinations.

### Cost Calculation:
- The cost is the sum of the values of the internal nodes, which is the sum of products of the maximum values at each internal node.
   
### **Why This Problem is Difficult**:
- The challenge in this problem comes from finding the **optimal binary tree structure**. You need to decide how to combine the leaf nodes in such a way that the sum of products (i.e., the total cost) is minimized.
- At each step, we can choose to combine any two subarrays (or subtrees) of leaf nodes, but there are many ways to split the array. Thus, we need to carefully calculate the cost for each combination and choose the one that gives the minimum cost.

### Another Example:

**Example 2:**

Given an array of leaf values: `[1, 3, 1, 2]`.

1. The leaf nodes are `1`, `3`, `1`, and `2`.
2. To build the binary tree, we will split the array in various ways:
   - For instance, we might first split it into `[1]` and `[3, 1, 2]` and calculate the internal node cost based on these.
   - We would also split the array differently, like `[1, 3]` and `[1, 2]`, and calculate the cost again.
3. We need to compute the cost for all possible binary trees formed by these leaf nodes and choose the one with the smallest total cost.

### Conclusion:
The task is to find a way to **build a binary tree** with **minimum cost**, where the **leaf values** come from the given array, and the **internal nodes** are calculated as the product of the maximum values in the left and right subtrees.

You have to compute the **total cost** of each tree structure and return the minimum possible cost. This problem involves checking different ways to combine the subarrays and finding the one that minimizes the cost, which can lead to many different combinations.

---

## Recursive Approach (caused TLE)
The problem asks us to compute the **minimum cost** of a binary tree formed by leaf nodes that are given in an array. The cost is determined by the product of the maximum values of the left and right subtrees at each internal node. The goal is to construct the tree such that the total cost is minimized.

The **key idea** in solving this problem is to recursively break the array of leaf nodes into smaller subarrays, computing the maximum product at each step, and trying all possible splits to find the minimum cost.

### **Recursive Approach Explanation:**

The recursive approach breaks the problem down as follows:

1. **Base Case**: If the subarray only contains one element (a leaf node), no cost is incurred because it is already a leaf. Thus, the cost for a single node is `0`.

2. **Recursive Case**: For a subarray of more than one element, you split the array into two parts at every possible position. For each split:
    - Calculate the cost of combining these two parts using the **maximum value** from each partition.
    - Add the recursive cost of the left and right partitions.
    - Keep track of the minimum cost across all splits.

3. **Memoization**: The code uses a **memoization** technique with a `map` to store the maximum values for all subarrays so that we don’t recompute the maximum value for each subarray multiple *.

#### **Step-by-Step Recursive Explanation with an Example:**

Let’s take an example to understand the recursive steps.

**Example:**
Given the array of leaf values: `[6, 2, 4]`

#### **Step 1: Initial Subarray [0, 2]**
- The entire array is `[6, 2, 4]`.
- We will try every possible split point between indices `0` and `2`.
    - Split at `i = 0`:
      - Left subarray: `[6]`, right subarray: `[2, 4]`.
      - Maximum value for left is `6` (from the `maxi` map).
      - Maximum value for right subarray `[2, 4]` is `4` (from the `maxi` map).
      - Cost for this split: `6 * 4 = 24`.
      - Now, calculate the recursive cost for the left and right subarrays.
        - Left subarray `[6]` has no internal nodes, so cost = `0`.
        - Right subarray `[2, 4]` is recursively split.
    - Split at `i = 1`:
      - Left subarray: `[6, 2]`, right subarray: `[4]`.
      - Maximum value for left subarray `[6, 2]` is `6`.
      - Maximum value for right subarray `[4]` is `4`.
      - Cost for this split: `6 * 4 = 24`.
      - Now, calculate the recursive cost for the left and right subarrays.
        - Left subarray `[6, 2]` is recursively split.
        - Right subarray `[4]` has no internal nodes, so cost = `0`.

We continue this process recursively until we find the minimum cost.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum cost to combine leaf nodes
    int solve(vector<int>& arr, map<pair<int, int>, int> & maxi, int left, int right) {
        // Base case: If there is only one leaf node, no cost is required
        if(left == right) return 0;

        int mini = INT_MAX; // Initialize minimum cost to a very high value

        // Try every possible split point `i` between `left` and `right`
        for(int i = left; i < right; i++) {
            // Calculate the cost for this split:
            // maxi[{left, i}] * maxi[{i+1, right}] gives the product of the largest
            // leaf values in the two partitions
            // Add recursive costs for the left and right partitions
            mini = min(mini, 
                maxi[{left, i}] * maxi[{i+1, right}] + 
                solve(arr, maxi, left, i) + 
                solve(arr, maxi, i+1, right)
            );
        }

        return mini; // Return the minimum cost for the current range
    }

    int mctFromLeafValues(vector<int>& arr) {
        // Precompute the maximum value in all subarrays using a map
        map<pair<int, int>, int> maxi;

        // Fill the maxi map with maximum values for every subarray [i, j]
        for(int i = 0; i < arr.size(); i++) {
            // For subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, the maximum is the larger of:
                // - The current element arr[j]
                // - The maximum of the previous subarray [i, j-1]
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Call the recursive function to compute the minimum cost
        // The range is the entire array: [0, arr.size() - 1]
        return solve(arr, maxi, 0, arr.size()-1);
    }
};
```

### Source Code Explanation

#### **`solve` function**:

```cpp
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right)
```
- **Purpose**: This is the recursive function that calculates the minimum cost for the subarray `arr[left, right]`. It uses memoization to avoid redundant computations.
- `arr`: The input array containing leaf node values.
- `maxi`: A map storing the maximum values for all subarrays.
- `left`, `right`: Indices representing the current subarray in the array `arr`.

```cpp
if(left == right) return 0;
```
- **Base Case**: If the subarray has only one element, no cost is required as it is already a leaf node.

```cpp
int mini = INT_MAX;
```
- **Initialization**: The variable `mini` keeps track of the minimum cost. We initialize it to a very large number (`INT_MAX`).

```cpp
for(int i = left; i < right; i++) {
```
- **Loop over possible split points**: We loop over all possible points `i` where we can split the current subarray into two parts.

```cpp
mini = min(mini, maxi[{left, i}] * maxi[{i+1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i+1, right));
```
- **Cost Calculation**: For each split:
    - `maxi[{left, i}]`: Maximum value of the left subarray `[left, i]`.
    - `maxi[{i+1, right}]`: Maximum value of the right subarray `[i+1, right]`.
    - `solve(arr, maxi, left, i)` and `solve(arr, maxi, i+1, right)`: Recursive calls to calculate the cost for the left and right subarrays.
    - The cost for this split is the sum of the product of the maximum values and the costs of the left and right subarrays. We then update `mini` to the minimum of the current `mini` and this cost.

```cpp
return mini;
```
- **Return the result**: The minimum cost for the subarray `[left, right]` is returned.

#### **`mctFromLeafValues` function**:

```cpp
map<pair<int, int>, int> maxi;
```
- **Purpose**: The `maxi` map stores the maximum values for all subarrays in the input array. This avoids redundant calculations.

```cpp
for(int i = 0; i < arr.size(); i++) {
    maxi[{i, i}] = arr[i];
    for(int j = i + 1; j < arr.size(); j++) {
        maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
    }
}
```
- **Precompute the maximum values**: We fill the `maxi` map with the maximum values for all subarrays. For each subarray `[i, j]`, the maximum value is computed using the current element `arr[j]` and the maximum of the previous subarray `[i, j-1]`.

```cpp
return solve(arr, maxi, 0, arr.size()-1);
```
- **Call the recursive `solve` function**: We call the `solve` function for the entire array from index `0` to `arr.size() - 1` to get the minimum cost.

### **Example Output Explanation:**

**Example:**
Given the input array `[6, 2, 4]`, the function computes the minimum cost using recursive splits:

1. First, we try splitting at `i = 0`, calculating the product `6 * 4 = 24`.
2. Then, we try splitting at `i = 1`, calculating the product `6 * 4 = 24`.
3. The total minimum cost is `24`, which is returned.

### **Time Complexity:**

1. **Precomputing Maximum Values**:
    - The nested loops to fill the `maxi` map take `O(n^2)` time, where `n` is the size of the input array.

2. **Recursive Function**:
    - The recursive function `solve` is called for each subarray, and for each subarray, we check every possible split.
    - The recursive calls have a time complexity of `O(n^2)` due to the two nested loops over the subarray.
    - Overall, the time complexity of the recursive approach is **O(n^3)**.

### **Space Complexity:**

1. **Memoization (`maxi` map)**:
    - The space required for the `maxi` map is `O(n^2)` because it stores the maximum value for every pair of indices in the array.
    
2. **Recursive Call Stack**:
    - The space required for the recursion call stack is `O(n)` since the depth of recursion is proportional to the size of the input array.
    
Thus, the overall space complexity is **O(n^2)** due to the space required for the `maxi` map.

### **Conclusion:**

The recursive approach uses memoization to avoid redundant calculations and optimally computes the minimum cost to combine the leaf nodes. The time complexity is cubic, and the space complexity is quadratic, primarily due to the storage of precomputed maximum values.

## Top-Down Approach (DP)
In this approach, we solve the problem using recursion along with **memoization** to store the intermediate results and avoid redundant calculations. The goal is to compute the minimum cost of combining all leaf values in the binary tree, following the pattern that every combination of two leaf values incurs a cost equal to the product of the maximum leaf values in each partition.

#### **Recursive Steps:**
1. We aim to compute the minimum cost for a range of leaves from `left` to `right` in the array.
2. If the range consists of a single element, no cost is needed because no further combination is required. This forms the base case of the recursion.
3. For larger ranges, we recursively divide the array into two parts at each possible split `i`, calculate the cost of combining the two parts, and find the minimum cost over all splits.
4. The result for each subproblem is stored in a dynamic programming table `dp` to avoid redundant calculations. This is known as **memoization**.

### Source Code
```cpp
class Solution {
public:
    // Recursive function to calculate the minimum cost of combining leaf values
    // `arr`: The input array of leaf values
    // `maxi`: Precomputed map containing the maximum values for all subarrays
    // `left`, `right`: The current range being considered
    // `dp`: Memoization table to store results of subproblems
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi, int left, int right, vector<vector<int>>& dp) {
        // Base case: If there is only one element, the cost is zero
        if(left == right) return 0;

        // If the result for this subproblem is already computed, return it
        if(dp[left][right] != -1) return dp[left][right];

        int mini = INT_MAX; // Initialize minimum cost to a very high value

        // Try every possible split point `i` between `left` and `right`
        for(int i = left; i < right; i++) {
            // Calculate the cost of this split:
            // 1. `maxi[{left, i}] * maxi[{i+1, right}]`: Cost of combining the maximum leaf values from the two partitions
            // 2. Recursive calls to solve for the left and right partitions
            mini = min(mini, 
                maxi[{left, i}] * maxi[{i+1, right}] + 
                solve(arr, maxi, left, i, dp) + 
                solve(arr, maxi, i+1, right, dp)
            );
        }

        // Store the result in the `dp` table for future use
        return dp[left][right] = mini;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // `dp` table to memoize results for subproblems
        // `dp[i][j]` will store the minimum cost to combine leaf nodes in the range `[i, j]`
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        // Precompute the maximum values for all subarrays `[i, j]`
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < arr.size(); i++) {
            // For subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, the maximum is the larger of:
                // - The current element `arr[j]`
                // - The maximum of the previous subarray `[i, j-1]`
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Solve the problem for the full range `[0, n-1]` using the recursive function
        return solve(arr, maxi, 0, arr.size() - 1, dp);
    }
};
```

### Source Code Explanation

#### **`solve` function:**
1. **Base Case:**
   ```cpp
   if(left == right) return 0;
   ```
   - If the range `[left, right]` has only one element, no cost is required to combine it because there are no partitions left to make. So, return `0`.

2. **Memoization Check:**
   ```cpp
   if(dp[left][right] != -1) return dp[left][right];
   ```
   - Before doing the recursive calculation, check if the result for this subproblem has already been computed. If it has, return the stored value from the `dp` table.

3. **Initialize Minimum Cost:**
   ```cpp
   int mini = INT_MAX;
   ```
   - Initialize the minimum cost to a very high value, which will be updated during the process of recursion.

4. **Recursive Split Calculation:**
   ```cpp
   for(int i = left; i < right; i++) {
       mini = min(mini, 
           maxi[{left, i}] * maxi[{i+1, right}] + 
           solve(arr, maxi, left, i, dp) + 
           solve(arr, maxi, i+1, right, dp)
       );
   }
   ```
   - Loop over all possible splits `i` between `left` and `right`.
   - For each split, calculate the cost:
     - `maxi[{left, i}] * maxi[{i+1, right}]`: The cost of combining the two subarrays is the product of their maximum values.
     - Then, recursively solve the left and right subarrays using the `solve` function.
   - Keep track of the minimum cost encountered during the loop.

5. **Memoization Storage:**
   ```cpp
   return dp[left][right] = mini;
   ```
   - Store the calculated minimum cost for the subarray `[left, right]` in the `dp` table for future use.

#### **`mctFromLeafValues` function:**
1. **Initialize `dp` Table:**
   ```cpp
   vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
   ```
   - Create a 2D `dp` table where `dp[i][j]` will store the minimum cost for the subarray `[i, j]`. Initialize all values to `-1`, indicating that no subproblem has been solved yet.

2. **Precompute Maximum Values for Subarrays:**
   ```cpp
   map<pair<int, int>, int> maxi;
   for(int i = 0; i < arr.size(); i++) {
       maxi[{i, i}] = arr[i];
       for(int j = i + 1; j < arr.size(); j++) {
           maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
       }
   }
   ```
   - Use a map `maxi` to store the maximum values for every subarray `[i, j]`. This is done by iterating over all possible subarrays and storing the maximum for each range.

3. **Call the `solve` Function:**
   ```cpp
   return solve(arr, maxi, 0, arr.size() - 1, dp);
   ```
   - Finally, call the `solve` function to compute the minimum cost for the full range `[0, n-1]`.

### **Example**

Consider the array `arr = [6, 2, 4]`:

- **Step 1:** Precompute the maximum values for all subarrays:
  - `maxi[{0, 0}] = 6`, `maxi[{1, 1}] = 2`, `maxi[{2, 2}] = 4`
  - `maxi[{0, 1}] = 6`, `maxi[{1, 2}] = 4`, `maxi[{0, 2}] = 6`

- **Step 2:** Call `solve` for the range `[0, 2]`:
  - For split `i = 0`, calculate the cost:
    - `maxi[{0, 0}] * maxi[{1, 2}] + solve(arr, maxi, 0, 0, dp) + solve(arr, maxi, 1, 2, dp)`
    - `6 * 4 + 0 + (4 * 2 + 0) = 24 + 0 + 8 = 32`
  - For split `i = 1`, calculate the cost:
    - `maxi[{0, 1}] * maxi[{2, 2}] + solve(arr, maxi, 0, 1, dp) + solve(arr, maxi, 2, 2, dp)`
    - `6 * 4 + (6 * 2 + 0) + 0 = 24 + 12 + 0 = 36`
  - The minimum cost is `32`.

Thus, the output is `32`.

### **Time and Space Complexity**

1. **Time Complexity:**
   - **Memoization Table:** The `dp` table has size `O(n^2)`, where `n` is the size of the input array `arr`.
   - **Recursive Calls:** For each subproblem, we calculate the cost for all possible splits, which takes `O(n)` time.
   - Thus, the overall time complexity is `O(n^3)` because we have `O(n^2)` subproblems, and for each subproblem, we try `O(n)` splits.

2. **Space Complexity:**
   - **Memoization Table:** The `dp` table requires `O(n^2)` space.
   - **Map for Maximum Values:** The map `maxi` also requires `O(n^2)` space to store the maximum values for all subarrays.
   - Thus, the overall space complexity is `O(n^2)`.

---

## Bottom-Up Approach (DP)
We aim to calculate the minimum cost to merge the leaf values into a single tree. The cost of merging two leaf values is the product of their maximum values, and we seek to minimize this cost using dynamic programming (DP).

### **Steps:**

1. **Initialization:**
   - `arr`: The array containing the leaf values.
   - `maxi`: A map that stores the maximum values for all subarrays `[i, j]`. This map helps us quickly access the maximum value for any subarray.

2. **Dynamic Programming Table (DP):**
   - The DP table `dp[i][j]` represents the minimum cost to merge the subarray `arr[i]` to `arr[j]` into a single value.
   - We initialize `dp[i][i] = 0` for all `i` because a single leaf value doesn’t need merging (i.e., cost is 0).

3. **Iterating Over Subarrays:**
   - We iterate over all possible subarray lengths starting from 2 up to `n`, where `n` is the size of `arr`. For each subarray, we consider every possible way to split it into two parts (left and right).

4. **Cost Calculation:**
   - For each pair of subarrays `[left, right]`, we try every split point `i` between `left` and `right`. 
   - The cost of merging the subarrays is calculated as:
     - `maxi[{left, i}] * maxi[{i+1, right}]`: The cost of merging the two subarrays.
     - `dp[left][i] + dp[i+1][right]`: The cost of recursively merging the two parts.
   - We update `dp[left][right]` with the minimum cost from all possible splits.

5. **Final Result:**
   - The final result will be stored in `dp[0][n-1]`, which represents the minimum cost to merge the entire array `arr` into a single value.

### Source Code
```cpp
class Solution {
public:
    // Function to compute the minimum cost of merging the array into a single leaf value
    // `arr`: The input array of leaf values
    // `maxi`: Precomputed map storing the maximum values for all subarrays
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();

        // `dp[i][j]` stores the minimum cost to merge elements in the range `[i, j]`
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // Base case: Cost of merging a single element is zero
        for(int i = 0; i < arr.size(); i++) dp[i][i] = 0;

        // Iterate over subarray lengths from 2 to `n`
        for(int len = 2; len <= n; len++) {
            for(int left = 0; left <= n - len; left++) {
                int right = left + len - 1; // Calculate the right index for the current subarray
                
                // Try splitting the subarray at each possible position `i`
                for(int i = left; i < right; i++) {
                    // Compute the cost of this split:
                    // 1. `maxi[{left, i}] * maxi[{i+1, right}]`: Cost of combining the maximum values of the two partitions
                    // 2. `dp[left][i] + dp[i+1][right]`: Cost of solving the left and right partitions
                    dp[left][right] = min(dp[left][right], 
                        maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }
            }
        }

        // Return the result for the entire array `[0, n-1]`
        return dp[0][n-1];
    }

    // Main function to calculate the minimum cost tree from leaf values
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();

        // Precompute the maximum values for all subarrays `[i, j]`
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < arr.size(); i++) {
            // For a subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, compute the maximum as the larger of:
                // - The current element `arr[j]`
                // - The maximum of the previous subarray `[i, j-1]`
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Call the solve function to calculate the result using dynamic programming
        return solve(arr, maxi);
    }
};
```

### Source Code Explanation
Certainly! Let's go through the source code line-by-line, explaining each part in detail with examples. We'll break it down in the context of the problem where we need to calculate the minimum cost to merge an array of leaf values into a single tree, using dynamic programming and precomputed maximum values.

### Full Source Code (with explanations)
```cpp
class Solution {
public:
    // Function to compute the minimum cost of merging the array into a single leaf value
    // `arr`: The input array of leaf values
    // `maxi`: Precomputed map storing the maximum values for all subarrays
    int solve(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size(); // Store the size of the input array

        // `dp[i][j]` stores the minimum cost to merge elements in the range `[i, j]`
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX)); // Initialize a 2D DP array with INT_MAX (infinity)

        // Base case: Cost of merging a single element is zero
        for (int i = 0; i < arr.size(); i++) dp[i][i] = 0; // A single element doesn't require merging

        // Iterate over subarray lengths from 2 to `n`
        for (int len = 2; len <= n; len++) {
            for (int left = 0; left <= n - len; left++) {
                int right = left + len - 1; // Calculate the right index for the current subarray
                
                // Try splitting the subarray at each possible position `i`
                for (int i = left; i < right; i++) {
                    // Compute the cost of this split:
                    // 1. `maxi[{left, i}] * maxi[{i+1, right}]`: Cost of combining the maximum values of the two partitions
                    // 2. `dp[left][i] + dp[i+1][right]`: Cost of solving the left and right partitions
                    dp[left][right] = min(dp[left][right], 
                        maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
                }
            }
        }

        // Return the result for the entire array `[0, n-1]`
        return dp[0][n-1];
    }

    // Main function to calculate the minimum cost tree from leaf values
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(); // Store the size of the input array

        // Precompute the maximum values for all subarrays `[i, j]`
        map<pair<int, int>, int> maxi; 
        for (int i = 0; i < arr.size(); i++) {
            // For a subarray of size 1, the maximum is the element itself
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                // For larger subarrays, compute the maximum as the larger of:
                // - The current element `arr[j]`
                // - The maximum of the previous subarray `[i, j-1]`
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        // Call the solve function to calculate the result using dynamic programming
        return solve(arr, maxi);
    }
};
```

### Detailed Line-by-Line Explanation:

#### **Class Declaration and Function Definition:**

```cpp
class Solution {
public:
```

- We define a class `Solution` to implement the required functionality.
- The function `solve` computes the minimum cost of merging a subarray of leaves into a single value, and `mctFromLeafValues` is the main function to initialize and call the `solve` function.


#### **The solve Function:**

```cpp
int solve(vector<int>& arr, map<pair<int, int>, int>& maxi) {
    int n = arr.size();
```
- `solve` takes two arguments:
  - `arr`: The input array of leaf values.
  - `maxi`: A map that stores the maximum values for all subarrays `[i, j]`.
- `n = arr.size();` calculates the size of the input array `arr`.


#### **Initializing the DP Table:**

```cpp
vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
```
- We initialize a 2D vector `dp` of size `n x n` to store the minimum cost of merging the subarrays.
- `dp[i][j]` will store the minimum cost to merge the array from index `i` to `j`.
- We set all values in `dp` to `INT_MAX` (infinity), except for the diagonal, which will be set to `0` later. This is because the minimum cost for merging a single leaf is `0`.


#### **Base Case:**

```cpp
for (int i = 0; i < arr.size(); i++) dp[i][i] = 0;
```
- This is the base case: If we only have a single leaf (i.e., a subarray of length 1), no merging is required, so the cost is `0`.
- We loop over all indices `i` from `0` to `n-1`, setting `dp[i][i] = 0`.
  

#### **Filling the DP Table:**

```cpp
for (int len = 2; len <= n; len++) {
    for (int left = 0; left <= n - len; left++) {
        int right = left + len - 1;
```
- We iterate over subarray lengths `len` from `2` to `n`.
- For each subarray length, we iterate over possible starting indices `left` of the subarrays.
- The ending index `right` of the subarray is computed as `left + len - 1`.


#### **Try Every Possible Split:**

```cpp
for (int i = left; i < right; i++) {
    dp[left][right] = min(dp[left][right], 
        maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
}
```
- For each subarray `[left, right]`, we try splitting it at every index `i` from `left` to `right - 1`.
- We compute the cost of this split:
  - `maxi[{left, i}]`: The maximum value of the subarray `[left, i]`.
  - `maxi[{i+1, right}]`: The maximum value of the subarray `[i+1, right]`.
  - `dp[left][i]`: The minimum cost of merging the subarray `[left, i]`.
  - `dp[i+1][right]`: The minimum cost of merging the subarray `[i+1, right]`.
- The total cost for this split is:
  - `maxi[{left, i}] * maxi[{i+1, right}]`: The cost of combining the two subarrays.
  - `dp[left][i] + dp[i+1][right]`: The cost of merging the two subarrays.
- We update `dp[left][right]` with the minimum of the current value and the new computed cost.


#### **Returning the Final Answer:**

```cpp
return dp[0][n-1];
```
- After filling the DP table, the final answer (minimum cost to merge the entire array) is stored in `dp[0][n-1]`, which is the cost to merge the entire array from index `0` to `n-1`.
- We return `dp[0][n-1]` as the result.


#### **The mctFromLeafValues Function:**

```cpp
int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size();
```
- `mctFromLeafValues` is the main function that starts the process. It receives the array `arr` as input and computes its size `n`.


#### **Precomputing Maximum Values:**

```cpp
map<pair<int, int>, int> maxi;
for (int i = 0; i < arr.size(); i++) {
    maxi[{i, i}] = arr[i];
    for (int j = i + 1; j < arr.size(); j++) {
        maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
    }
}
```
- We create a map `maxi` to store the maximum values for all subarrays `[i, j]`.
- We iterate over all possible subarrays:
  - For a single-element subarray (`i == j`), the maximum is the element itself, i.e., `maxi[{i, i}] = arr[i]`.
  - For larger subarrays, we compute the maximum as the maximum of the current element `arr[j]` and the previous maximum value `maxi[{i, j-1}]`.


#### **Calling the solve Function:**

```cpp
return solve(arr, maxi);
```
- Once the `maxi` map is precomputed, we call the `solve` function to calculate the minimum cost of merging the array into a single tree.
- The result is returned from the `solve` function.

### **Example:**

For the input array `arr = [6, 2, 4]`, let's go through a brief example:

1. **Precompute `maxi`:**
   - `maxi[{0, 0}] = 6`, `maxi[{1, 1}] = 2`, `maxi[{2, 2}] = 4`
   - `maxi[{0, 1}] = max(6, 2) = 6`
   - `maxi[{1, 2}] = max(2, 4) = 4`
   - `maxi[{0, 2}] = max(6, 4) = 6`

2. **DP Calculation:**
   - For subarrays of length 2, calculate the cost for each split:
     - `dp[0][1] = 6 * 4 + 0 + 0 = 24`
     - `dp[1][2] = 6 * 6 + 0 + 0 = 36`
   - For subarrays of length 3:
     - `dp[0][2] = min(dp[0][1] + dp[2][2], dp[0][1] + dp[1][2]) = min(24 + 0, 24 + 36) = 24`

Thus, the minimum cost to merge the array `[6, 2, 4]` is `24`.

Let's analyze the time and space complexities of the provided solution.

### Time Complexity:
#### 1. **Precomputing the Maximum Values (Map `maxi`):**

```cpp
map<pair<int, int>, int> maxi;
for (int i = 0; i < arr.size(); i++) {
    maxi[{i, i}] = arr[i];
    for (int j = i + 1; j < arr.size(); j++) {
        maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
    }
}
```
- The outer loop runs `n` * (`i` from `0` to `n-1`).
- The inner loop runs at most `n-i` * for each `i`. 
  - For `i = 0`, the inner loop runs `n` *.
  - For `i = 1`, the inner loop runs `n-1` *.
  - For `i = 2`, it runs `n-2` *, and so on.

- The total number of operations in the nested loop is the sum of the first `n` integers: 

  `
  text{Total Operations} = n + (n-1) + (n-2) + dots + 1 = frac{n(n+1)}{2}
  `

- So, the time complexity of precomputing the maximum values is:

  `
  O(n^2)
  `

#### 2. **Filling the DP Table:**

```cpp
vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

for (int len = 2; len <= n; len++) {
    for (int left = 0; left <= n - len; left++) {
        int right = left + len - 1;
        for (int i = left; i < right; i++) {
            dp[left][right] = min(dp[left][right], 
                maxi[{left, i}] * maxi[{i+1, right}] + dp[left][i] + dp[i+1][right]);
        }
    }
}
```
- The outer loop runs for `len` from `2` to `n`, which gives `n - 1` iterations.
- The second loop iterates `n - len + 1` * for each `len`. For each `len`, the number of possible `left` values is `n - len + 1`.
- The innermost loop iterates `right - left` * for each pair of `left` and `right`. So, the number of operations depends on the subarray length.

- For each combination of `len` and `left`, we iterate over all possible splits (`i`), which is approximately `n` in the worst case.

- Therefore, the time complexity of filling the DP table is:

  `
  O(n^3)
  `
  This is because:
  - The outer two loops contribute a factor of (O(n^2)).
  - The innermost loop runs in (O(n)) for each subarray, resulting in an overall complexity of (O(n^3)).

#### 3. **Overall Time Complexity:**

- The most computationally expensive part is filling the DP table, which has a time complexity of (O(n^3)).
- The precomputing of the maximum values contributes (O(n^2)), which is dominated by the (O(n^3)) complexity of the DP table.

Thus, the **overall time complexity** is:

`
O(n^3)
`

### Space Complexity:

#### 1. **The `maxi` Map:**

- The `maxi` map stores the maximum values for all subarrays `[i, j]`.
- There are ( frac{n(n+1)}{2} ) unique subarrays, which is (O(n^2)).
- Each entry in the map stores an integer, so the space required for the map is (O(n^2)).

#### 2. **The DP Table:**

- The DP table `dp` is a 2D array of size `n x n`.
- The space complexity of the DP table is (O(n^2)).

#### 3. **Overall Space Complexity:**

- The space complexity is dominated by the `maxi` map and the DP table.
- Both structures require (O(n^2)) space.

Thus, the **overall space complexity** is:

`
O(n^2)
`

### Summary:

- **Time Complexity:** (O(n^3))
- **Space Complexity:** (O(n^2))

This means that the solution efficiently handles arrays of moderate size (e.g., up to 500 or 1000 elements) but may struggle with very large arrays, as the time complexity grows cubically. The space complexity is quadratic, which is typical for dynamic programming solutions.

## Space Optimization (Not Possible)
Space optimization may not be feasible in this problem due to the following reasons:

### 1. **Nature of the DP Table:**
   The problem involves calculating the minimum cost of combining leaf values, and the solution is based on dynamic programming (DP). The state transitions depend on both the current subarray and all possible splits within that subarray.

   - **Subproblem Dependencies:** 
     The DP table stores the minimum cost for subarrays `[i, j]`, which requires access to results from smaller subarrays such as `[i, i]`, `[i, j-1]`, and `[i+1, j]`. Each entry in the DP table is needed for further calculations.

     - Example: To calculate `dp[left][right]`, we need to compute `dp[left][i]` and `dp[i+1][right]` for every split `i` between `left` and `right`. Thus, every subarray `[left, right]` is dependent on smaller subarrays.

   - **Why It's Not Easy to Eliminate Some States:**
     Since every subarray and split is required to calculate the final minimum cost, it is difficult to remove any states from the DP table. Each value `dp[left][right]` stores an important piece of information that directly affects the final answer. If we were to store only partial results, we would lose essential information and compromise the correctness of the solution.

### 2. **Recomputing Subproblems Would Increase Time Complexity:**
   If we attempt to reduce the space complexity by not storing the DP table and recomputing subproblems, we would face the problem of repeated calculations. Without storing previously computed results, we would end up recalculating the same subproblems multiple times, significantly increasing the time complexity.

   - **Memoization vs. Recalculation:**
     Storing intermediate results (memoization) is necessary to prevent recalculating the same subproblems, which is why the DP table is essential. If we try to remove it, we would essentially be redoing the same work multiple times for the same subarrays, which would result in a time complexity of (O(2^n)) or worse (exponential time complexity), rendering the approach inefficient for larger inputs.

### 3. **Recursion and DP Table Size:**
   The problem uses a 2D DP table where each cell `dp[i][j]` stores the minimum cost for merging the leaf values in the subarray from index `i` to `j`. This requires a table of size (O(n^2)). The 2D table is necessary to store these overlapping subproblems, as the cost for merging depends on the entire subarray's values, not just the values at the boundary.

   - **Space vs. Time Tradeoff:** 
     While reducing space might seem appealing, it would lead to a significant tradeoff in time complexity. If we only keep a reduced set of subproblems, we would have to revisit the same computations repeatedly, resulting in inefficient solutions.

### 4. **Maxi Map:**
   The `maxi` map is also used to store the maximum value for all subarrays. Each subarray needs to know the maximum value within its range to calculate the cost. The map's size is (O(n^2)), and we can't reduce this without losing crucial information for the computation.

### Conclusion:
Space optimization is not easily achievable in this problem because:
- The problem relies on storing results for overlapping subarrays to avoid recalculating them.
- Removing the DP table would increase time complexity, potentially making the solution infeasible for larger inputs.
- The structure of the problem inherently requires (O(n^2)) space due to the need to store values for all subarrays and splits.

In summary, while space optimization might be possible in some problems with fewer overlapping subproblems or more independent computations, it is not feasible in this case due to the nature of dynamic programming and the required subproblem dependencies.
