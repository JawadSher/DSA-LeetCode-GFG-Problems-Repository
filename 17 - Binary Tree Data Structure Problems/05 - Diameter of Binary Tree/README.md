<h1 align='center'>Diameter - of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

![image](https://github.com/user-attachments/assets/1bf407d7-02a2-46b4-a3bb-928e7c7c0f71)

## Problem Explanation
The goal of this problem is to find the **diameter** of a binary tree. 

The diameter (or width) of a binary tree is defined as the **length of the longest path** between any two nodes in the tree. This path does not necessarily pass through the root node, and it is measured by the number of edges between nodes.

#### Examples:
1. **Example 1**:
   ```
           1
          / \
         2   3
        / \
       4   5
   ```
   - The longest path is from node `4` to node `5` through node `2`, and it includes three edges (4 → 2 → 1 → 3).
   - The diameter here is `3`.

2. **Example 2**:
   ```
           1
          /
         2
        /
       3
   ```
   - The longest path is from node `3` to node `1`, which contains two edges.
   - The diameter here is `2`.

3. **Example 3**:
   - For an empty tree (`root == NULL`), the diameter is `0`.

### Step 2: Approach to Solve the Problem

#### Beginner-Friendly Thinking Process:

1. **Recursive Traversal for Longest Path Calculation**:
   - We can approach this problem by recursively finding the longest path for each node’s left and right subtrees.
   - At each node, we calculate three potential longest paths:
     - Diameter of the left subtree.
     - Diameter of the right subtree.
     - Path that passes through the node, calculated as the depth of the left subtree + depth of the right subtree + 1 (for the current node).

2. **Combine Results to Find the Maximum Diameter**:
   - For each node, take the maximum of these three options (left diameter, right diameter, path through node) and update our answer if this maximum is larger than the current maximum diameter.

3. **Recursive Steps**:
   - Traverse to the left and right children to get their respective diameters and depths.
   - Calculate the possible longest path using the node’s children.
   - Return the maximum diameter encountered so far, as well as the depth of the subtree rooted at the current node.

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
    pair<int, int> diameter(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }

        pair<int, int> left = diameter(root -> left);
        pair<int, int> right = diameter(root -> right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first - 1;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    pair<int, int> diameter(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
```
- **Explanation**: If `root` is `NULL`, we return `{0, 0}`, where `0` represents both the diameter and depth. For an empty tree, the diameter is `0`.

```cpp
        pair<int, int> left = diameter(root -> left);
        pair<int, int> right = diameter(root -> right);
```
- **Explanation**: Recursively calculate the diameter and depth for the left and right subtrees. Each subtree will return a `pair<int, int>`, where `first` is the diameter and `second` is the depth.

```cpp
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
```
- **Explanation**: 
   - `op1` is the diameter of the left subtree.
   - `op2` is the diameter of the right subtree.
   - `op3` is the diameter if the path passes through the current node, calculated as the depth of the left subtree + depth of the right subtree + 1 for the current node.

```cpp
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
```
- **Explanation**: `ans.first` stores the maximum diameter from the options `op1`, `op2`, and `op3`.
   - `ans.second` stores the depth of the subtree rooted at `root`, calculated as `1 + max(left.second, right.second)`.

```cpp
        return ans;
    }
```
- **Explanation**: Return the `pair` containing the maximum diameter and depth for the current subtree.

```cpp
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first - 1;
    }
};
```
- **Explanation**: `diameter(root).first` provides the diameter of the tree in terms of nodes, so we subtract `1` to convert it to edges, as required by the problem.

### Step-by-Step Example Walkthrough

Consider the following binary tree:

```
       1
      / \
     2   3
    / \
   4   5
```

1. **Recursive Calculations**:
   - For each node, calculate the diameter and depth of both left and right subtrees.
2. **Node 4 and Node 5**:
   - Both are leaf nodes, so the depth is `1` and the diameter is `0`.
3. **Node 2**:
   - Left subtree (node `4`) has a depth of `1`, diameter of `0`.
   - Right subtree (node `5`) has a depth of `1`, diameter of `0`.
   - Diameter at node `2` is `max(0, 0, 1 + 1 + 1) = 3`.
   - Depth at node `2` is `1 + max(1, 1) = 2`.
4. **Node 3**:
   - It has no children, so the depth is `1` and the diameter is `0`.
5. **Node 1**:
   - Left subtree (node `2`) has a depth of `2`, diameter of `3`.
   - Right subtree (node `3`) has a depth of `1`, diameter of `0`.
   - Diameter at node `1` is `max(3, 0, 2 + 1 + 1) = 3`.
   - Depth at node `1` is `1 + max(2, 1) = 3`.

The overall diameter of the tree is `3`, so the function returns `3 - 1 = 2`.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the tree. Each node is visited once, so the time complexity grows linearly with the size of the tree.
2. **Space Complexity**: **O(H)**, where `H` is the height of the tree. This space is required for the recursive call stack. In the worst case (skewed tree), it could be `N`, while in a balanced tree, it’s `log(N)`.
