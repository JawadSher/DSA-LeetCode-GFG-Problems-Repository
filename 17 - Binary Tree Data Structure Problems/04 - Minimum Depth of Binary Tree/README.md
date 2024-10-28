<h1 align='center'>Minimum - Depth -  of -  Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

![image](https://github.com/user-attachments/assets/38a1136a-9d03-4879-b1f2-3049cc6ab923)

## Problem Explanation
The goal of this problem is to find the **minimum depth** of a binary tree. 

The minimum depth is defined as the shortest path from the root node down to the nearest leaf node. A **leaf node** is a node that has no children (both left and right child nodes are `NULL`). This is different from the maximum depth, which considers the longest path.

#### Examples:
1. **Example 1**:
   ```
           1
          / \
         2   3
        /
       4
   ```
   - The minimum depth here is `2`, as the shortest path is from the root `1` to node `3`.

2. **Example 2**:
   ```
           1
          /
         2
        /
       3
   ```
   - The minimum depth here is `3`, as there's only one path from the root to a leaf node (1 → 2 → 3).

3. **Example 3**: An empty tree
   - If the tree is empty (`root == NULL`), the depth is `0`.

### Step 2: Approach to Solve the Problem

#### Beginner-Friendly Thinking Process:

1. **Recursion to Simplify Tree Traversal**:
   - If we view the problem recursively, finding the minimum depth can be broken down into smaller subproblems for each subtree (left and right).
   - At each node, the minimum depth is 1 + the minimum depth of its non-null child subtree.

2. **Handling Edge Cases with NULL Nodes**:
   - If a node has no children on one side (i.e., either left or right is `NULL`), the minimum depth should only consider the non-null child.
   - For a node with both children, find the minimum depth of both subtrees and add 1 for the current node.

3. **Recursive Steps**:
   - If both children are `NULL`, it’s a leaf node, and the depth from this node is 1.
   - If only one child is `NULL`, continue down the subtree with the non-null child.
   - If both children are present, calculate the minimum depth of both left and right subtrees, then add 1 to account for the current node.

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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        if(root -> left == NULL) return minDepth(root -> right) + 1;
        if(root -> right == NULL) return minDepth(root -> left) + 1;
        
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);

        return min(left, right) + 1;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
```
- **Explanation**: If `root` is `NULL`, the tree is empty, so return `0`.

```cpp
        if(root -> left == NULL) return minDepth(root -> right) + 1;
        if(root -> right == NULL) return minDepth(root -> left) + 1;
```
- **Explanation**: If there is no left child (`root->left == NULL`), the minimum depth must come from the right subtree, so call `minDepth` on `root->right` and add 1 for the current node.
- Similarly, if there is no right child (`root->right == NULL`), the minimum depth must come from the left subtree.

```cpp
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
```
- **Explanation**: If both children exist, calculate the depth of the left and right subtrees separately.

```cpp
        return min(left, right) + 1;
    }
};
```
- **Explanation**: Return the minimum of the left and right depths plus 1 for the current node.

### Step-by-Step Example Walkthrough

For the following tree:

```
       1
      / \
     2   3
    /
   4
```

1. **Node 1**: It has both children, so find the minimum depth of both left and right subtrees.
2. **Left Subtree of 1**:
   - Node `2` has only a left child (node `4`), so continue to node `4`.
   - Node `4` has no children, so its depth is `1`.
   - Depth of left subtree from node `1` is `2` (1 for `2` and 1 for `4`).
3. **Right Subtree of 1**:
   - Node `3` has no children, so its depth is `1`.
4. **Result**: The minimum depth from root `1` is `2` (shortest path being 1 → 3).

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the tree. Each node is visited once, so the time grows linearly with the number of nodes.
2. **Space Complexity**: **O(H)**, where `H` is the height of the tree. This space is required for the recursive call stack. In the worst case, the height could be `N` (for a skewed tree), and in the best case, it’s `log(N)` for a balanced tree.
