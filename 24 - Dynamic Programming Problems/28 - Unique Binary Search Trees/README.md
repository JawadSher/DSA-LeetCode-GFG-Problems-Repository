<h1 align="center">Unique - Binary Search - Trees</h1>

## Problem Statement

**Problem URL (leetcode):** [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/description/)

**Problem URL (GFG):** [Unique Binary Search Trees](https://www.geeksforgeeks.org/problems/unique-bsts-1587115621/1)

![image](https://github.com/user-attachments/assets/53eb0026-a472-4e7a-a7a6-a755e9664ee4)

### Problem Explanation
The problem **"Unique Binary Search Trees"** on LeetCode involves finding the number of structurally unique Binary Search Trees (BSTs) that can be formed using `n` distinct values (from 1 to `n`).

## Problem Description

A **Binary Search Tree (BST)** is a binary tree where:
- The value of each node in the left subtree is **less than** the value of the root.
- The value of each node in the right subtree is **greater than** the value of the root.

Given an integer ( n ), the task is to calculate how many structurally unique BSTs can be formed with nodes labeled from ( 1 ) to ( n ).


## Key Insights
1. The problem is inherently **combinatorial**:
   - For each number ( i ) chosen as the root of the BST:
     - The numbers ( 1, 2, dots, i-1 ) will form the left subtree.
     - The numbers ( i+1, i+2, dots, n ) will form the right subtree.
   - The number of BSTs for ( n ) is the **Cartesian product** of the number of BSTs in the left and right subtrees.

2. This leads to a recursive relationship:
   `G(n) = sum_{i=1}^{n} G(i-1) . G(n-i)`
   Where:
   - ( G(n) ): The number of unique BSTs for ( n ) nodes.
   - ( G(0) = 1 ): A BST with 0 nodes is empty (base case).
   - ( G(1) = 1 ): A BST with 1 node is unique (the single node is the tree).

## Examples

### Example 1: ( n = 3 )
Input:
`n = 3`

### Unique BSTs:
The numbers are ( 1, 2, 3 ). Each number can be the root:
1. **Root = 1**:
   - Left subtree: ( { } ) (0 nodes, 1 way)
   - Right subtree: ( { 2, 3 } ) (2 nodes, calculated as ( G(2) ))
   - Total ways for this configuration: ( G(0) * G(2) = 1 * 2 = 2 )

2. **Root = 2**:
   - Left subtree: ( { 1 } ) (1 node, ( G(1) ))
   - Right subtree: ( { 3 } ) (1 node, ( G(1) ))
   - Total ways for this configuration: ( G(1) * G(1) = 1 * 1 = 1 )

3. **Root = 3**:
   - Left subtree: ( { 1, 2 } ) (2 nodes, ( G(2) ))
   - Right subtree: ( { } ) (0 nodes, ( G(0) ))
   - Total ways for this configuration: ( G(2) * G(0) = 2 * 1 = 2 )

Adding all configurations:
`G(3) = G(0) . G(2) + G(1) . G(1) + G(2) . G(0) = 2 + 1 + 2 = 5`

Output:
`5`

### Example 2: ( n = 1 )
Input:
`n = 1`

### Unique BSTs:
- Only one tree can be formed with one node:
  ```
  1
  ```

Output:
`1`


### Example 3: ( n = 0 )
Input:
`n = 0`

### Unique BSTs:
- An empty tree is the only possible BST.

Output:
`1`

## Visualization of Unique BSTs for ( n = 3 )

### 1. Root = 1
```
   1
    
     2
      
       3
```
```
   1
    
     3
    /
   2
```

### 2. Root = 2
```
     2
    / 
   1   3
```

### 3. Root = 3
```
       3
      /
     2
    /
   1
```
```
       3
      /
     1
      
       2
```

## Approach to Solve

1. **Recursive Solution**:
   - Base cases:
     - ( G(0) = 1 ), ( G(1) = 1 ).
   - Use the recursive relationship:
     `G(n) = sum_{i=1}^{n} G(i-1) . G(n-i)`
     
   - Time Complexity: ( O(2^n) ) due to repeated calculations.
   - Space Complexity: ( O(n) ) for the recursion stack.

2. **Dynamic Programming Solution**:
   - Use a `dp` array where ( dp[i] ) stores ( G(i) ).
   - Iteratively compute ( dp[i] ) using the formula.
   - Time Complexity: ( O(n^2) ).
   - Space Complexity: ( O(n) ).

3. **Catalan Number Formula**:
   - Compute ( C(n) ) directly using:
     `C(n) = {{(2n)!}/}{{(n+1)! . n!}}`
     
   - Time Complexity: ( O(n) ) (iterative computation).
   - Space Complexity: ( O(1) ).

### Constraints
- ( 1 <= n <= 19 ): Handle large values of ( n ) efficiently without integer overflow (use `long long` if needed).

This problem tests your understanding of combinatorial logic, recursion, and dynamic programming.

---

## Recursive Approach
The goal is to find the number of structurally unique Binary Search Trees (BSTs) for ( n ) nodes labeled from ( 1 ) to ( n ).

#### **Key Idea**
- Choose a number ( i ) as the root of the BST.
- The numbers ( 1, 2, ..., i-1 ) will form the **left subtree** (with ( i-1 ) nodes).
- The numbers ( i+1, i+2, ..., n ) will form the **right subtree** (with ( n-i ) nodes).
- The total number of BSTs when ( i ) is the root is the **product** of:
  - Number of BSTs possible with ( i-1 ) nodes (left subtree).
  - Number of BSTs possible with ( n-i ) nodes (right subtree).

The process is repeated recursively for each ( i ), and the results are summed up for all possible roots from ( 1 ) to ( n ).


### **Example Walkthrough**
Let’s calculate ( {numTrees}(3) ):
1. **Base Case:** ( {numTrees}(0) = 1 ) and ( {numTrees}(1) = 1 ).
2. For ( n = 3 ):
   - **Root = 1:**
     - Left subtree: ( {numTrees}(0) = 1 ).
     - Right subtree: ( {numTrees}(2) ) (to be calculated).
   - **Root = 2:**
     - Left subtree: ( {numTrees}(1) = 1 ).
     - Right subtree: ( {numTrees}(1) = 1 ).
   - **Root = 3:**
     - Left subtree: ( {numTrees}(2) ) (to be calculated).
     - Right subtree: ( {numTrees}(0) = 1 ).

We recursively compute ( {numTrees}(2) ):
1. For ( n = 2 ):
   - **Root = 1:**
     - Left subtree: ( {numTrees}(0) = 1 ).
     - Right subtree: ( {numTrees}(1) = 1 ).
   - **Root = 2:**
     - Left subtree: ( {numTrees}(1) = 1 ).
     - Right subtree: ( {numTrees}(0) = 1 ).

   Summing up:
   `
   {numTrees}(2) = 1 . 1 + 1 . 1 = 2
   `

Substituting back into ( {numTrees}(3) ):
`
{numTrees}(3) = 1 . 2 + 1 . 1 + 2 . 1 = 5
`

### Source Code
```cpp
class Solution {
public:
    int numTrees(int n) {
        // Base case: If there are 0 or 1 nodes, there is only 1 unique BST possible.
        if(n <= 1) return 1;

        int ans = 0; // Initialize the variable to store the total number of unique BSTs.

        // Loop through each number i from 1 to n.
        // Treat 'i' as the root of the BST.
        for(int i = 1; i <= n; i++) {
            // Recursively calculate the number of unique BSTs for the left and right subtrees.
            // Left subtree has (i-1) nodes.
            // Right subtree has (n-i) nodes.
            ans += numTrees(i-1) * numTrees(n-i);
        }

        // Return the total count of unique BSTs for n nodes.
        return ans;
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    int numTrees(int n) {
        // Base case: If there are 0 or 1 nodes, there is only 1 unique BST possible.
        if(n <= 1) return 1;
```
- **Explanation**: 
  - If ( n = 0 ), there’s one possible tree: the empty tree.
  - If ( n = 1 ), there’s only one possible BST with one node.

```cpp
        int ans = 0; // Initialize the variable to store the total number of unique BSTs.
```
- **Explanation**: 
  - ( ans ) will store the cumulative number of unique BSTs for all possible roots.

```cpp
        for(int i = 1; i <= n; i++) {
```
- **Explanation**:
  - Loop through each number ( i ) from ( 1 ) to ( n ). Treat ( i ) as the root of the BST.

```cpp
            ans += numTrees(i-1) * numTrees(n-i);
```
- **Explanation**:
  - Recursively calculate the number of BSTs for the left subtree (( i-1 ) nodes) and the right subtree (( n-i ) nodes).
  - Multiply the results to account for all combinations of left and right subtrees.
  - Add the result to ( ans ).

```cpp
        return ans; // Return the total count of unique BSTs for n nodes.
    }
};
```
- **Explanation**:
  - Return the total number of BSTs for ( n ).



### **Example Output**

#### Input:
`
n = 3
`

#### Execution:
- ( {numTrees}(3) ):
  - Root ( = 1 ): ( {numTrees}(0) * {numTrees}(2) = 1 * 2 = 2 )
  - Root ( = 2 ): ( {numTrees}(1) * {numTrees}(1) = 1 * 1 = 1 )
  - Root ( = 3 ): ( {numTrees}(2) * {numTrees}(0) = 2 * 1 = 2 )
- Total: ( 2 + 1 + 2 = 5 )

#### Output:
`
5
`

### **Time Complexity**

- **Recursive calls**:
  - For ( n = 3 ), each root makes two recursive calls.
  - For ( n ), this forms a **Catalan number sequence**. The recursion tree has exponential growth.

- **Complexity**:
  `
  O(2^n)
  `
  This is inefficient for large ( n ) due to overlapping subproblems.


### **Space Complexity**

- **Recursive stack**:
  - The depth of the recursion tree is ( O(n) ) (maximum ( n ) recursive calls).
- **Complexity**:
  `
  O(n)
  `

### **Optimization**

To improve performance, use **dynamic programming** or compute directly using the **Catalan number formula**.

---

## Top-Down Approach (DP)
The goal is to find the number of unique Binary Search Trees (BSTs) that can be formed using `n` nodes with unique values from `1` to `n`. A BST must satisfy the property that all nodes in the left subtree are smaller than the root, and all nodes in the right subtree are larger.

The top-down approach uses recursion with **memoization**, where the results of previously computed subproblems are stored in a table (`dp array`) to avoid redundant calculations.

### **Step-by-Step Explanation of the Approach**

1. **Recursive Formula**:  
   For `n` nodes:
   - Pick a node `i` (from `1` to `n`) as the root.
   - Nodes on the left of `i` form the left subtree, with `i-1` nodes.
   - Nodes on the right of `i` form the right subtree, with `n-i` nodes.
   - The total number of BSTs with `i` as the root is the product of BSTs possible in the left and right subtrees:  
     `
     {Total BSTs} = {numTrees(i-1)} * {numTrees(n-i)}
     `
   - Sum up the results for all possible roots `i` to get the total BSTs for `n`.

2. **Memoization**:  
   To avoid recomputing subproblems, store results in a `dp` array where `dp[x]` holds the number of BSTs for `x` nodes.

3. **Base Cases**:  
   - For `n = 0` or `n = 1`, there is exactly **1 BST** possible (an empty tree or a single-node tree).
     
### Source Code
```cpp
class Solution {
public:
    // Helper function to calculate the number of unique BSTs for 'n' nodes using memoization.
    int solve(int n, vector<int>& dp) {
        // Base case: If there are 0 or 1 nodes, there is only 1 unique BST possible.
        if(n <= 1) return 1;

        // Check if the result for 'n' is already computed and stored in dp.
        if(dp[n] != -1) return dp[n];

        int ans = 0; // Initialize the variable to store the total number of unique BSTs.

        // Loop through each number i from 1 to n.
        // Treat 'i' as the root of the BST.
        for(int i = 1; i <= n; i++) {
            // Recursively calculate the number of unique BSTs for the left and right subtrees.
            // Left subtree has (i-1) nodes.
            // Right subtree has (n-i) nodes.
            ans += solve(i-1, dp) * solve(n-i, dp);
        }

        // Store the computed result for 'n' in the dp array for future use.
        return dp[n] = ans;
    }

    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        // Create a dp array initialized with -1 to indicate uncomputed results.
        vector<int> dp(n+1, -1);

        // Call the helper function with the initial value of 'n' and the dp array.
        return solve(n, dp);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Helper function to calculate the number of unique BSTs for 'n' nodes using memoization.
    int solve(int n, vector<int>& dp) {
        // Base case: If there are 0 or 1 nodes, there is only 1 unique BST possible.
        if(n <= 1) return 1;
```
- The base case ensures that for `n = 0` (empty tree) or `n = 1` (single-node tree), the result is directly returned as 1.

```cpp
        // Check if the result for 'n' is already computed and stored in dp.
        if(dp[n] != -1) return dp[n];
```
- Before performing any computation, check the `dp` array. If `dp[n]` is not `-1`, it means the result for `n` nodes has already been calculated, so we return it directly.

```cpp
        int ans = 0; // Initialize the variable to store the total number of unique BSTs.
```
- `ans` is used to accumulate the results of all possible configurations of BSTs for `n` nodes.

```cpp
        // Loop through each number i from 1 to n.
        // Treat 'i' as the root of the BST.
        for(int i = 1; i <= n; i++) {
            // Recursively calculate the number of unique BSTs for the left and right subtrees.
            // Left subtree has (i-1) nodes.
            // Right subtree has (n-i) nodes.
            ans += solve(i-1, dp) * solve(n-i, dp);
        }
```
- For each `i` from `1` to `n`, treat `i` as the root.
- Calculate the number of BSTs in the left subtree (`solve(i-1, dp)`) and right subtree (`solve(n-i, dp)`).
- Multiply these results and add them to `ans`.

```cpp
        // Store the computed result for 'n' in the dp array for future use.
        return dp[n] = ans;
    }
```
- Once the result for `n` nodes is computed, store it in `dp[n]` for reuse.

```cpp
    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        // Create a dp array initialized with -1 to indicate uncomputed results.
        vector<int> dp(n+1, -1);
```
- Initialize a `dp` array of size `n+1` with all elements set to `-1`.

```cpp
        // Call the helper function with the initial value of 'n' and the dp array.
        return solve(n, dp);
    }
};
```
- Start the recursive computation for `n` nodes using the `solve` function.



### **Example**

#### Input:  
`n = 3`

#### Calculation:  

1. Compute `numTrees(3)`:
   - Choose `1` as root:
     `
     {Left: numTrees(0), Right: numTrees(2)} = 1 * 2 = 2
     `
   - Choose `2` as root:
     `
     {Left: numTrees(1), Right: numTrees(1)} = 1 * 1 = 1
     `
   - Choose `3` as root:
     `
     {Left: numTrees(2), Right: numTrees(0)} = 2 * 1 = 2
     `
   - Total:
     `
     2 + 1 + 2 = 5
     `

#### Output:  
`5`



### **Time Complexity**  
- **Recursive Calls**: Each `solve(n)` computes results for subproblems of sizes `n-1`, `n-2`, ..., `1`.
- Using memoization, each subproblem is computed **only once**.
- Overall complexity:  
  `
  O(n^2)
  `

### **Space Complexity**  
- **Auxiliary Space**: The `dp` array requires `O(n)` space.  
- **Recursive Stack**: The recursion depth is at most `n`.  
- Overall complexity:  
  `
  O(n)
  `

---
## Bottom-Up Approach (DP)
The problem asks to find the number of unique Binary Search Trees (BSTs) that can be formed using `n` nodes with distinct values from `1` to `n`. A BST is a binary tree where the left subtree of a node contains only nodes with values less than the node's value, and the right subtree only nodes with values greater than the node's value.

The **bottom-up approach** solves this problem using dynamic programming. Instead of using recursion with memoization (top-down approach), this approach iteratively builds the solution from smaller subproblems to the final solution.


### **Step-by-Step Explanation of the Approach**

1. **Dynamic Programming Array (dp)**:  
   The idea is to use a `dp` array where `dp[i]` represents the number of unique BSTs that can be formed using `i` nodes. The base cases are straightforward:
   - `dp[0] = 1`: There is exactly **1 BST** when there are no nodes (an empty tree).
   - `dp[1] = 1`: There is exactly **1 BST** when there is only one node.

2. **Iterating through all subproblems**:  
   For each `i` from `2` to `n`, compute `dp[i]`:
   - For each node `j` from `1` to `i`, consider `j` as the root of the tree.
     - The left subtree consists of `j-1` nodes, so there are `dp[j-1]` possible BSTs for the left subtree.
     - The right subtree consists of `i-j` nodes, so there are `dp[i-j]` possible BSTs for the right subtree.
   - Multiply the number of BSTs in the left and right subtrees to find the total number of BSTs for the current `i`.

3. **Final Result**:  
   After iterating through all subproblems, the result for `n` nodes is stored in `dp[n]`.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the number of unique BSTs for 'n' nodes using a bottom-up approach.
    int solve(int n) {
        // Create a dp array of size (n+1) to store the results for subproblems.
        // dp[i] will hold the number of unique BSTs that can be formed with 'i' nodes.
        vector<int> dp(n+1, 0);

        // Base cases:
        // When there are 0 nodes, there is 1 unique BST (an empty tree).
        // When there is 1 node, there is 1 unique BST (the single node as the root).
        dp[0] = dp[1] = 1;

        // Fill the dp array for all values from 2 to n (Bottom-Up approach).
        for (int i = 2; i <= n; i++) {
            // Calculate the number of unique BSTs for 'i' nodes.
            for (int j = 1; j <= i; j++) {
                // Treat 'j' as the root node.
                // The left subtree has (j-1) nodes.
                // The right subtree has (i-j) nodes.
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        // Return the result for 'n' nodes.
        return dp[n];
    }

    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        return solve(n); // Call the helper function with the input 'n'.
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to calculate the number of unique BSTs for 'n' nodes using a bottom-up approach.
    int solve(int n) {
        // Create a dp array of size (n+1) to store the results for subproblems.
        // dp[i] will hold the number of unique BSTs that can be formed with 'i' nodes.
        vector<int> dp(n+1, 0);
```
- Initialize a dynamic programming array `dp` of size `n+1` to store the number of unique BSTs for each number of nodes from `0` to `n`. Initially, all elements are set to `0`.

```cpp
        // Base cases:
        // When there are 0 nodes, there is 1 unique BST (an empty tree).
        // When there is 1 node, there is 1 unique BST (the single node as the root).
        dp[0] = dp[1] = 1;
```
- Set the base cases:
  - `dp[0] = 1`: One way to form a BST with zero nodes (an empty tree).
  - `dp[1] = 1`: One way to form a BST with one node (a single-node tree).

```cpp
        // Fill the dp array for all values from 2 to n (Bottom-Up approach).
        for (int i = 2; i <= n; i++) {
```
- Start filling the `dp` array from `i = 2` to `n`. For each `i`, we compute the number of unique BSTs that can be formed with `i` nodes.

```cpp
            // Calculate the number of unique BSTs for 'i' nodes.
            for (int j = 1; j <= i; j++) {
                // Treat 'j' as the root node.
                // The left subtree has (j-1) nodes.
                // The right subtree has (i-j) nodes.
                dp[i] += dp[j-1] * dp[i-j];
            }
```
- For each root node `j` (from `1` to `i`), the left subtree has `j-1` nodes, and the right subtree has `i-j` nodes.
- Multiply the number of unique BSTs for the left and right subtrees: `dp[j-1] * dp[i-j]`.
- Accumulate the results to find `dp[i]`, the total number of unique BSTs for `i` nodes.

```cpp
        }
        // Return the result for 'n' nodes.
        return dp[n];
    }
```
- After filling the `dp` array, return `dp[n]`, which contains the number of unique BSTs for `n` nodes.

```cpp
    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        return solve(n); // Call the helper function with the input 'n'.
    }
};
```
- The `numTrees` function is the main function that calls the `solve` function with the input `n` to get the final result.



### **Example**

#### Input:
`n = 3`

#### Calculation:

1. **Base Case Initialization**:
   - `dp[0] = 1` (1 BST for 0 nodes)
   - `dp[1] = 1` (1 BST for 1 node)

2. **Filling `dp` for `i = 2`**:
   - For root `1`: Left subtree with `0` nodes, right subtree with `1` node.  
     Result: `dp[0] * dp[1] = 1 * 1 = 1`
   - For root `2`: Left subtree with `1` node, right subtree with `0` nodes.  
     Result: `dp[1] * dp[0] = 1 * 1 = 1`
   - Total for `i = 2`: `1 + 1 = 2`

3. **Filling `dp` for `i = 3`**:
   - For root `1`: Left subtree with `0` nodes, right subtree with `2` nodes.  
     Result: `dp[0] * dp[2] = 1 * 2 = 2`
   - For root `2`: Left subtree with `1` node, right subtree with `1` node.  
     Result: `dp[1] * dp[1] = 1 * 1 = 1`
   - For root `3`: Left subtree with `2` nodes, right subtree with `0` nodes.  
     Result: `dp[2] * dp[0] = 2 * 1 = 2`
   - Total for `i = 3`: `2 + 1 + 2 = 5`

#### Output:
`5`

Thus, the number of unique BSTs that can be formed with 3 nodes is **5**.



### **Time Complexity**

- The outer loop runs from `2` to `n`, i.e., `O(n)`.
- For each `i`, the inner loop runs from `1` to `i`, i.e., `O(i)`.
- Total time complexity:  
  `
  O(1) + O(2) + O(3) + dots + O(n) = O(n^2)
  `

Thus, the **time complexity** is `O(n^2)`.

### **Space Complexity**

- The `dp` array requires `O(n)` space.
- The space complexity is `O(n)` due to the dynamic programming array.

Thus, the **space complexity** is `O(n)`.

---

## Catalan Number Approach
In this approach, we are using the **Catalan number** formula to calculate the number of unique Binary Search Trees (BSTs) that can be formed with `n` nodes. The Catalan number `C(n)` gives the number of distinct BSTs that can be formed using `n` distinct nodes. The formula for the nth Catalan number is:

`
C(n) = {(2n)!}/{(n+1)!n!}
`

Where:
- ( (2n)! ) is the factorial of `2n`
- ( n! ) is the factorial of `n`
- ( (n+1)! ) is the factorial of `n+1`

We can calculate this number using an optimized iterative approach to avoid calculating large factorials directly.



### **Step-by-Step Explanation of the Approach**

1. **Catalan Number Formula**:  
   The Catalan number for `n` can be calculated as:

`
C(n) = {(2n)!}/{(n+1)!n!}
`

Instead of computing large factorials directly, we can compute this iteratively in a more efficient manner:

`
C(n)= 
n−1
∏
i=0
(2n−i) / (i+1)
`

This formula avoids calculating the full factorial values and instead uses a product to compute the result step-by-step.

2. **Iterative Computation**:  
   We start by initializing the Catalan number as `1`. Then, for each `i` from `0` to `n-1`, we iteratively compute the result by multiplying the current value by `(2n - i)` and dividing by `(i + 1)`.

3. **Final Adjustment**:  
   After calculating the product, we divide the result by `(n + 1)` to get the final Catalan number.

4. **Result**:  
   The final value of the `catalan` variable will be the nth Catalan number, which is the number of unique BSTs that can be formed with `n` nodes.

### Source Code
```cpp
class Solution {
public:
    // Function to calculate the nth Catalan number using a mathematical formula.
    int solve(int n) {
        // Initialize a variable to store the computed Catalan number.
        // Using 'long long' to handle intermediate results that might exceed int limits.
        long long catalan = 1;

        // Compute the value of (2n)! / n! in a loop.
        // This is a part of the Catalan number formula: C(n) = (2n)! / ((n+1)! * n!).
        for (int i = 0; i < n; i++) {
            // Update 'catalan' using the current term of the formula.
            // Multiply by (2n - i) and divide by (i + 1) iteratively.
            catalan = catalan * (2 * n - i) / (i + 1);
        }

        // Divide the computed value by (n + 1) to complete the Catalan number calculation.
        return catalan / (n + 1);
    }

    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        // Call the helper function 'solve' to compute the nth Catalan number.
        return solve(n);
    }
};
```

### Source Code Explanation

```cpp
class Solution {
public:
    // Function to calculate the nth Catalan number using a mathematical formula.
    int solve(int n) {
        // Initialize a variable to store the computed Catalan number.
        // Using 'long long' to handle intermediate results that might exceed int limits.
        long long catalan = 1;
```
- We initialize the `catalan` variable to `1`.  
- We use `long long` to handle intermediate results that might exceed the size limits of regular integers.

```cpp
        // Compute the value of (2n)! / n! in a loop.
        // This is a part of the Catalan number formula: C(n) = (2n)! / ((n+1)! * n!).
        for (int i = 0; i < n; i++) {
            // Update 'catalan' using the current term of the formula.
            // Multiply by (2n - i) and divide by (i + 1) iteratively.
            catalan = catalan * (2 * n - i) / (i + 1);
        }
```
- We iterate over `i` from `0` to `n-1`.  
- In each iteration, we update the `catalan` value using the formula ( {catalan} * {(2n - i)}{(i + 1)} ). This avoids calculating large factorials directly and computes the Catalan number efficiently.

```cpp
        // Divide the computed value by (n + 1) to complete the Catalan number calculation.
        return catalan / (n + 1);
    }
```
- Finally, we divide the computed value by `(n + 1)` to complete the Catalan number calculation.
- The resulting value is returned as the nth Catalan number.

```cpp
    // Main function to calculate the number of unique BSTs for 'n' nodes.
    int numTrees(int n) {
        // Call the helper function 'solve' to compute the nth Catalan number.
        return solve(n);
    }
};
```
- The `numTrees` function is the main function that calls the helper function `solve(n)` to compute the nth Catalan number and returns the result. This value represents the number of unique BSTs that can be formed with `n` nodes.



### **Example**

#### Input:
`n = 3`

#### Calculation:

The nth Catalan number can be calculated as:

`
C(3) = {(2 * 3)!}{(3+1)!3!} = {6!}{4!3!}
`

This formula can be optimized as follows:

`
C(3) = prod_{i=0}^{2} {(6 - i)}{(i + 1)} = {6}{1} * {5}{2} * {4}{3}
`

Thus, the result is:

`
C(3) = {6 * 5 * 4}{1 * 2 * 3} = 5
`

#### Output:
`5`

Thus, the number of unique BSTs that can be formed with 3 nodes is **5**.



### **Time Complexity**

- The loop runs from `0` to `n-1`, so it performs `n` iterations.
- In each iteration, we perform a constant number of arithmetic operations.
- Therefore, the time complexity is **O(n)**.

### **Space Complexity**

- We use only a few variables (`catalan` and `i`), so the space complexity is **O(1)**, i.e., constant space. We don't need extra space for an array or other data structures.

Thus, the **time complexity** is `O(n)` and the **space complexity** is `O(1)`.



### **Summary of Advantages**
- The Catalan number approach efficiently calculates the number of unique BSTs for `n` nodes in **O(n)** time and **O(1)** space.
- By using the mathematical formula iteratively, we avoid computing large factorials directly and reduce the computational overhead.
