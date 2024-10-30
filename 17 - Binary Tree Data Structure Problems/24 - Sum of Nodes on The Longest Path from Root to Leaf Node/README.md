<h1 align='center'>Sum of Nodes - on The - Longest Path - from Root - to Leaf - Node</h1>

## Problem Statement

**Problem URL :** [Sum of Nodes on The Longest Path from Root to Leaf Node](https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)

![image](https://github.com/user-attachments/assets/1163b45b-a6d7-4c79-80a5-3fee6c57167d)
![image](https://github.com/user-attachments/assets/4074bafe-bc79-4a0b-846b-8a8924a63fd5)

## Problem Explanation
Given a binary tree, the task is to find the largest sum of all nodes on a path from the root to a leaf node, where the path with the most nodes is chosen in case of a tie. A path is defined as any sequence from the root to a leaf node. If multiple paths have the same length, choose the path that has the maximum sum.

**Example:**
Consider the following binary tree:

```
         10
       /    \
     20      30
    /  \    /  
   40   50 60   
```

In this case:
- The longest path from the root to a leaf node is either `10 -> 20 -> 50` or `10 -> 30 -> 60`.
- The path with the maximum sum along the longest path is `10 -> 30 -> 60`, which has a sum of 100.

**Constraints:**
- If the tree is empty (root is `NULL`), the output should be `0`.
- Handle edge cases like a single node tree or trees with only one child path.

### Step 2: Approach

**High-Level Overview:**
The solution uses a recursive Depth First Search (DFS) traversal to explore each path from the root to every leaf node:
1. Traverse through each node, keeping track of:
   - The cumulative sum of the path.
   - The length of the path from root to the current node.
2. On reaching a leaf node, compare:
   - The length of this path with the longest path found so far.
   - If the path length is the same as the longest path, check if the current sum is greater than the maximum sum recorded.

**Step-by-Step Breakdown:**
1. **Define Base Condition**: When we reach a `NULL` node, it indicates a leaf node. We then compare the current path’s length and sum with the longest path and maximum sum recorded.
2. **Recursive Traversal**:
   - Recursively call the function for the left child and the right child.
   - Update the sum and length parameters for each recursive call.
3. **Update the Result**:
   - If the current path is longer, update `maxLen` and `maxSum`.
   - If the path length matches `maxLen`, update `maxSum` if the current sum is greater than `maxSum`.

## Problem Solution
```cpp
class Solution
{
public:
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
        if(root == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }else if(len == maxLen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root -> data;
        solve(root -> left, sum, maxSum, len+1, maxLen);
        solve(root -> right, sum, maxSum, len+1, maxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};
```

## Problem Solution Explanation
Let's go through each part of the code to understand how it works line-by-line, using examples for clarity.

```cpp
class Solution {
public:
    // Helper function to find the sum of the longest root-to-leaf path
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
```

### Line-by-Line Explanation

1. **Line:** `void solve(Node* root, int sum, int &maxSum, int len, int &maxLen)`
   - **Purpose:** This function recursively traverses the binary tree to find the path with the greatest length and sum from the root to a leaf node.
   - **Parameters:**
     - `Node* root`: Pointer to the current node.
     - `int sum`: Cumulative sum of the path from the root to the current node.
     - `int &maxSum`: Tracks the maximum sum found along the longest path so far (passed by reference to update the same variable across recursive calls).
     - `int len`: Current path length from the root to the current node.
     - `int &maxLen`: Tracks the maximum length of paths from the root to leaf nodes (also passed by reference).

### Example Tree
Consider this example binary tree:
```
         10
       /    \
      20     30
     /  \    /  
    40   50 60   
```

Starting at the root (node 10), the function will traverse the tree to find the longest path and the path with the highest sum.


```cpp
        // Base condition: if current node is NULL
        if(root == NULL) {
```

2. **Line:** `if(root == NULL)`
   - **Purpose:** Checks if the current node is `NULL`, indicating that we've reached a leaf node. At this point, we should evaluate the length and sum of the path that brought us here.


```cpp
            // Check if the path length is greater than the longest path found
            if(len > maxLen) {
                maxLen = len;         // Update the longest path length
                maxSum = sum;         // Update the max sum for the longest path
            } else if(len == maxLen) { // If path length is the same, check sum
                maxSum = max(sum, maxSum);  // Choose the maximum sum of paths
            }
            return;
        }
```

3. **Line:** `if(len > maxLen)`
   - **Purpose:** If the current path length (`len`) is greater than the previously recorded maximum path length (`maxLen`), we update `maxLen` to this longer length and set `maxSum` to the current path’s sum.
   
   **Example:**
   - When traversing the path `10 -> 20 -> 40`, if it’s the longest path found so far, update `maxLen` to 3 and `maxSum` to 70.

4. **Line:** `else if(len == maxLen)`
   - **Purpose:** If this path length is equal to the longest path length (`maxLen`), then we check if the current path’s sum is greater than `maxSum`. If it is, we update `maxSum` to the larger sum.

   **Example:**
   - When visiting path `10 -> 20 -> 50` (sum 80), if `len == maxLen`, we compare 80 with the previous `maxSum`. Since 80 is higher, we set `maxSum` to 80.


```cpp
        // Add the current node's data to the path sum
        sum = sum + root->data;
```

5. **Line:** `sum = sum + root->data`
   - **Purpose:** Adds the current node’s value to `sum`, accumulating the total for the path so far.
   
   **Example:**
   - At node 10, `sum` becomes `10`. At node 20, `sum` becomes `30`, and so on.

```cpp
        // Recursively call for the left and right child nodes
        solve(root->left, sum, maxSum, len + 1, maxLen); // Move to the left child
        solve(root->right, sum, maxSum, len + 1, maxLen); // Move to the right child
    }
```

6. **Line:** `solve(root->left, sum, maxSum, len + 1, maxLen)`
   - **Purpose:** Recursively moves to the left child of the current node, with updated `sum` and incremented `len`. This call continues until reaching a leaf node.
   
7. **Line:** `solve(root->right, sum, maxSum, len + 1, maxLen)`
   - **Purpose:** Similarly, this recursive call explores the right child of the current node.
   
**Example Execution:** Starting from `10`, the function will first go down the left subtree, visiting nodes `20` and `40`. Upon reaching `40` (a leaf node), it evaluates the path and then backtracks to try the right child of each node until it has explored all possible root-to-leaf paths.


```cpp
    // Main function to initialize parameters and call helper function
    int sumOfLongRootToLeafPath(Node *root) {
```

8. **Line:** `int sumOfLongRootToLeafPath(Node *root)`
   - **Purpose:** This is the main function that initializes the required variables (`len`, `maxLen`, `sum`, and `maxSum`) and calls the `solve` function.


```cpp
        // Initialize parameters for maximum path length and sum
        int len = 0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        // Call helper function to find the maximum sum path
        solve(root, sum, maxSum, len, maxLen);
        
        // Return the maximum sum found for the longest path
        return maxSum;
    }
};
```

9. **Lines:** Initialization and Call
   - `len = 0` and `maxLen = 0`: Used to track the length of the current path and the maximum path length found so far.
   - `sum = 0` and `maxSum = INT_MIN`: Used to track the sum of the current path and the highest sum found among the longest paths.

10. **Line:** `solve(root, sum, maxSum, len, maxLen)`
    - Calls the `solve` helper function with the root of the tree to initiate the recursive exploration.

11. **Line:** `return maxSum`
    - Returns the `maxSum` value, which represents the sum of nodes along the longest root-to-leaf path.


### Step 4: Output Examples

1. **Example 1:**
   - **Input**: Tree structure
     ```
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
     ```
   - **Output**: 11 (Path is `1 -> 3 -> 7`)

2. **Example 2:**
   - **Input**: Tree structure
     ```
           10
         /     \
       -2       7
       / \     /
      8  -4   5
     ```
   - **Output**: 15 (Path is `10 -> 7 -> -2 -> 5`)

3. **Example 3 (Edge Case - Empty Tree)**:
   - **Input**: `root = NULL`
   - **Output**: `0`

---

### Step 5: Time and Space Complexity

1. **Time Complexity**: \(O(N)\)
   - The function visits each node in the binary tree exactly once, where \(N\) is the number of nodes in the tree. Therefore, the time complexity is \(O(N)\).

2. **Space Complexity**: \(O(H)\)
   - The function’s recursive calls take up stack space. The maximum depth of the stack is the height \(H\) of the tree, giving a space complexity of \(O(H)\). In the worst case, \(H = N\) if the tree is skewed, but for a balanced tree, \(H = \log N\).

---

### Additional Tips:
- **Edge Cases**: Ensure to handle cases where the tree is empty or has only one node.
- **Optimizations**: This approach is already efficient, but for very large trees, consider iterative solutions or tail-call optimization if supported.
