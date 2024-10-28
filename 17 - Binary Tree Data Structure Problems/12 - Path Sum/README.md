<h1 align='center'>Path - Sum</h1>

## Problem Statement

**Problem URL :** [Path Sum](https://leetcode.com/problems/path-sum/)

![image](https://github.com/user-attachments/assets/d5296fe5-59e9-42b2-bdb3-a955ea3dacb1)
![image](https://github.com/user-attachments/assets/8d85cd64-8ad2-420a-9740-083278dc0023)


## Problem Explanation
The problem requires us to determine if a given binary tree has a root-to-leaf path such that the sum of the values of the nodes along the path equals a specified target sum. A root-to-leaf path is defined as a path starting from the root node and ending at any leaf node (a node with no children).

#### Examples:

1. **Example 1**:
   - **Input**:
     - **Tree**:
     ```
         5
        / \
       4   8
      /   / \
     11  13  4
    /  \      \
   7    2      1
     ```
     - **Target Sum**: `22`
   - **Output**: `true` (The path 5 → 4 → 11 → 2 has a sum of `22`.)

2. **Example 2**:
   - **Input**:
     - **Tree**:
     ```
         1
        / \
       2   3
     ```
     - **Target Sum**: `5`
   - **Output**: `false` (There is no path that adds up to `5`.)

3. **Example 3**:
   - **Input**:
     - **Tree**:
     ```
         1
        /
       2
     ```
     - **Target Sum**: `1`
   - **Output**: `false` (The only path is 1 → 2, which sums to `3`, not `1`.)

### Step 2: Approach to Solve the Problem

To solve the problem, we can use a recursive depth-first search (DFS) approach:

1. **Base Case**:
   - If the current node is `NULL`, return `false` (no path exists).

2. **Update the Target**:
   - Subtract the value of the current node from the `targetSum`.

3. **Leaf Node Check**:
   - If the current node is a leaf (both left and right children are `NULL`), check if the updated `targetSum` is `0`. If yes, return `true` (indicating a valid path).

4. **Recursive Calls**:
   - Recursively check the left and right subtrees with the updated `targetSum`. If either subtree returns `true`, then a valid path exists.

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        targetSum -= root -> val;

        if(root -> left == NULL && root -> right == NULL){
            return targetSum == 0;
        }

        return hasPathSum(root -> left, targetSum) || hasPathSum(root -> right, targetSum);
    }
};
```

## Problem Solution Explanation
Here’s the code with detailed explanations:

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
```
- **Explanation**: The `hasPathSum` function begins with a `TreeNode* root` representing the root of the binary tree and an `int targetSum` representing the target sum we want to check.

```cpp
        if(root == NULL) return false;
```
- **Explanation**: If the current node (`root`) is `NULL`, there is no path to check, so return `false`.

```cpp
        targetSum -= root -> val;
```
- **Explanation**: Subtract the value of the current node from `targetSum`. This updates the remaining sum we need to find along the path.

```cpp
        if(root -> left == NULL && root -> right == NULL){
            return targetSum == 0;
        }
```
- **Explanation**: Check if the current node is a leaf node (both children are `NULL`). If it is, return `true` if the `targetSum` has been reduced to `0`, indicating that the path sum equals the original target sum.

```cpp
        return hasPathSum(root -> left, targetSum) || hasPathSum(root -> right, targetSum);
    }
};
```
- **Explanation**: Recursively call `hasPathSum` on the left and right children of the current node. Use the logical OR (`||`) to return `true` if either subtree contains a path that sums to the required target.

### Step-by-Step Example Walkthrough

Consider the following tree and target sum:

- **Input Tree**:
```
    5
   / \
  4   8
 /   / \
11  13  4
/  \      \
7    2      1
```
- **Target Sum**: `22`

1. **Start at Root (Node 5)**:
   - Call `hasPathSum(5, 22)`.
   - Update `targetSum` to `22 - 5 = 17`.

2. **Left Subtree (Node 4)**:
   - Call `hasPathSum(4, 17)`.
   - Update `targetSum` to `17 - 4 = 13`.

3. **Left Subtree of 4 (Node 11)**:
   - Call `hasPathSum(11, 13)`.
   - Update `targetSum` to `13 - 11 = 2`.

4. **Left Subtree of 11 (Node 7)**:
   - Call `hasPathSum(7, 2)`.
   - Both children are `NULL`. Return `false` (2 != 0).

5. **Right Subtree of 11 (Node 2)**:
   - Call `hasPathSum(2, 2)`.
   - Both children are `NULL`. Return `true` (2 == 0).

6. **Back to Node 4**: Since we found a valid path in the left subtree, we return `true`.

7. **Check Right Subtree (Node 8)**:
   - Call `hasPathSum(8, 17)`.
   - Update `targetSum` to `17 - 8 = 9`.

8. **Left Subtree of 8 (Node 13)**:
   - Call `hasPathSum(13, 9)`.
   - Both children are `NULL`. Return `false` (9 != 0).

9. **Right Subtree of 8 (Node 4)**:
   - Call `hasPathSum(4, 9)`.
   - Update `targetSum` to `9 - 4 = 5`.

10. **Right Subtree of 4 (Node 1)**:
    - Call `hasPathSum(1, 5)`.
    - Both children are `NULL`. Return `false` (5 != 0).

The final output is `true`, as we found the path `5 → 4 → 11 → 2`.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the binary tree.
   - Each node is visited once to check for the path sum.

2. **Space Complexity**: **O(H)**, where `H` is the height of the tree.
   - The space complexity is primarily due to the recursive call stack. In the worst case (skewed tree), it could be `O(N)`, while for balanced trees, it would be `O(log N)`.

Overall, this approach efficiently checks if there exists a path in the binary tree whose sum equals the specified target sum using recursion.
