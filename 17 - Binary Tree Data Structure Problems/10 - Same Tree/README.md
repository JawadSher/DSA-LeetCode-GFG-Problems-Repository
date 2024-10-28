<h1 align='center'>Same - Tree</h1>

## Problem Statement

**Problem URL :** [Same Tree](https://leetcode.com/problems/same-tree/)

![image](https://github.com/user-attachments/assets/b6b855e0-bfb8-496a-b37a-bcf7eee81cfb)
![image](https://github.com/user-attachments/assets/06713166-8630-4bcf-a728-0148630eeb80)

## Problem Explanation
The problem requires determining whether two binary trees are identical. Two trees are considered identical if they have the same structure and the same node values at each corresponding position.

#### Examples:

1. **Example 1**:
   - **Tree 1**:
   ```
        1
       / \
      2   3
   ```
   - **Tree 2**:
   ```
        1
       / \
      2   3
   ```
   - **Output**: `true` (The trees are identical)

2. **Example 2**:
   - **Tree 1**:
   ```
        1
       / \
      2   3
   ```
   - **Tree 2**:
   ```
        1
       / \
      2   4
   ```
   - **Output**: `false` (The trees are not identical because the values of the right children differ)

3. **Example 3**:
   - **Tree 1**:
   ```
        1
       / \
      2   3
   ```
   - **Tree 2**:
   ```
        1
       /
      2
   ```
   - **Output**: `false` (The structure of the trees is different)

### Step 2: Approach to Solve the Problem

To determine if two binary trees are identical, we can use a recursive approach:

1. **Base Case**:
   - If both nodes are `NULL`, they are identical (return `true`).
   - If one node is `NULL` and the other is not, they are not identical (return `false`).

2. **Value Comparison**:
   - Compare the values of the current nodes of both trees. If they differ, the trees are not identical (return `false`).

3. **Recursive Comparison**:
   - Recursively check the left subtrees and right subtrees of both trees.
   - If both left and right subtree checks return `true`, the trees are identical (return `true`).

## Problem Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return 1;
        if(p == NULL && q != NULL) return 0;
        if(p != NULL && q == NULL) return 0;

        bool left = isSameTree(p -> left, q -> left);
        bool right = isSameTree(p -> right, q -> right);

        bool value = p -> val == q -> val;

        if(left && right && value) return 1;

        return 0;
    }
};
```

## Problem Solution Explanation

Here’s the code with detailed explanations:

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
```
- **Explanation**: This begins the definition of the `isSameTree` function, which takes two nodes (`p` and `q`) as input.

```cpp
        if(p == NULL && q == NULL) return 1;
```
- **Explanation**: If both nodes are `NULL`, it means we have reached the end of both trees simultaneously, indicating they are identical up to this point. Return `true` (or `1`).

```cpp
        if(p == NULL && q != NULL) return 0;
        if(p != NULL && q == NULL) return 0;
```
- **Explanation**: 
   - If one node is `NULL` and the other is not, the trees cannot be identical. Hence, return `false` (or `0`) for both conditions.

```cpp
        bool left = isSameTree(p -> left, q -> left);
        bool right = isSameTree(p -> right, q -> right);
```
- **Explanation**: 
   - Recursively check the left children of both trees and store the result in `left`.
   - Recursively check the right children of both trees and store the result in `right`.

```cpp
        bool value = p -> val == q -> val;
```
- **Explanation**: Compare the values of the current nodes. This checks if the data stored in `p` and `q` are the same.

```cpp
        if(left && right && value) return 1;
```
- **Explanation**: If both the left subtree and right subtree are identical, and the current nodes' values are the same, return `true` (or `1`).

```cpp
        return 0;
    }
};
```
- **Explanation**: If any of the above conditions fail, return `false` (or `0`), indicating the trees are not identical.

### Step-by-Step Example Walkthrough

Consider the following trees:

- **Tree 1**:
```
    1
   / \
  2   3
```

- **Tree 2**:
```
    1
   / \
  2   3
```

1. **Compare Node 1**:
   - Both values are `1`, proceed to compare left and right subtrees.

2. **Compare Node 2 (Left Subtree)**:
   - Both are `2`, proceed to compare their children (both `NULL`).

3. **Compare Node 3 (Right Subtree)**:
   - Both are `3`, proceed to compare their children (both `NULL`).

4. All comparisons return `true`, thus the function returns `true` for the trees being identical.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the trees.
   - We traverse each node in both trees exactly once to check for equality.

2. **Space Complexity**: **O(H)**, where `H` is the height of the trees.
   - The space complexity is due to the recursive function calls on the stack. In the worst case (skewed tree), it could be `O(N)`, while for balanced trees, it would be `O(log N)`.

Overall, this approach effectively checks for the structural and value equivalence of two binary trees using recursion.
