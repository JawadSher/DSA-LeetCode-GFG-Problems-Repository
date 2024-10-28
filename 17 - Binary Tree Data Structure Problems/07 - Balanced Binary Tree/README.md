<h1 align='center'>Balanced - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)

![image](https://github.com/user-attachments/assets/6331b3cc-0b1e-4174-997c-0f1c8793e3e7)
![image](https://github.com/user-attachments/assets/00773e99-aafb-4949-93da-09323ba5a19c)

## Problem Explanation

In this problem, we are asked to determine whether a binary tree is **balanced**. A binary tree is considered balanced if, for every node in the tree, the height difference between its left and right subtrees is at most 1. This means no subtree should be significantly deeper than the other.

#### Examples:

1. **Example 1**:
   ```
         1
        / \
       2   3
      / 
     4   
   ```
   - This tree is **balanced** because every node meets the height difference requirement.
   
2. **Example 2**:
   ```
         1
        /
       2
      /
     3
   ```
   - This tree is **not balanced** because the left subtree of the root has a depth difference greater than 1 compared to the non-existent right subtree.

3. **Example 3**:
   - For an empty tree (`root == NULL`), it is considered balanced.

### Step 2: Approach to Solve the Problem

To determine if a binary tree is balanced, we need to calculate the heights of the left and right subtrees for every node. However, this can be optimized:

1. **Top-Down vs Bottom-Up Approach**:
   - A **top-down** approach might involve checking each node and calculating the height separately, which can be inefficient (repeated height calculations).
   - A **bottom-up** approach, where we calculate heights while checking the balance condition, can be more efficient, as we avoid repeated calculations.

2. **Optimized Approach**:
   - Traverse the tree using a recursive helper function (`height`).
   - If any subtree is unbalanced, immediately return `-1` up the recursive chain.
   - If the subtree is balanced, return its height.
   - This way, we only need to traverse each node once, avoiding redundant calculations.

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
private:
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int left = height(root -> left);
        if(left == -1) return -1;

        int right = height(root -> right);
        if(right == -1) return -1;


        if(abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
```

## Problem Solution Explanation

Here is the code with line-by-line explanations:

```cpp
class Solution {
private:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
```
- **Explanation**: If `root` is `NULL`, it means we've reached a leaf node, so we return `0` (base case).

```cpp
        int left = height(root -> left);
        if (left == -1) return -1;
```
- **Explanation**:
   - Recursively calculate the height of the left subtree.
   - If `left` returns `-1`, it means the left subtree is unbalanced, so we return `-1` to indicate the tree is unbalanced.

```cpp
        int right = height(root -> right);
        if (right == -1) return -1;
```
- **Explanation**:
   - Similarly, calculate the height of the right subtree.
   - If `right` returns `-1`, it means the right subtree is unbalanced, so we return `-1`.

```cpp
        if (abs(left - right) > 1) return -1;
```
- **Explanation**:
   - Check if the current node's subtrees have a height difference greater than `1`. If true, return `-1` to indicate the tree is unbalanced.

```cpp
        return max(left, right) + 1;
    }
```
- **Explanation**:
   - If the node is balanced, return the height of the subtree rooted at this node as `1 + max(left, right)`.

```cpp
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
```
- **Explanation**:
   - `isBalanced` calls the `height` helper function and checks if it returns anything other than `-1`.
   - If `height` returns `-1`, it indicates the tree is unbalanced; otherwise, the tree is balanced.

### Step-by-Step Example Walkthrough

Consider the tree:

```
        1
       / \
      2   3
     /
    4
```

1. **Node 4**:
   - Both left and right subtrees are `NULL`, so their heights are `0`.
   - Height difference is `0`, so `height(4) = 1`.
2. **Node 2**:
   - Left subtree (node `4`) has a height of `1`.
   - Right subtree is `NULL`, height `0`.
   - Height difference is `1`, so `height(2) = 2`.
3. **Node 3**:
   - Both left and right subtrees are `NULL`, so height is `1`.
4. **Node 1**:
   - Left subtree (node `2`) has a height of `2`.
   - Right subtree (node `3`) has a height of `1`.
   - Height difference is `1`, so `height(1) = 3`.

The function returns `true`, indicating the tree is balanced.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the tree.
   - Each node is visited once, and the height of each subtree is calculated in constant time.

2. **Space Complexity**: **O(H)**, where `H` is the height of the tree.
   - This space is used by the recursion stack. In the worst case (skewed tree), it could be `N`, while in a balanced tree, it’s `log(N)`.
