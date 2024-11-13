<h1 align='center'>Check - Completeness - of a - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

![image](https://github.com/user-attachments/assets/5a659007-a46b-43a9-8bc8-ecbe1bb7af1f)
![image](https://github.com/user-attachments/assets/c8d2bab9-d26c-4614-b6a4-1579387efe64)

## Problem Explanation
**Problem Statement**:  In this problem, we need to determine if a given binary tree is a "complete binary tree." A binary tree is considered complete if all levels except possibly the last are fully filled, and all nodes are as far left as possible on the last level.

**Example of a Complete Binary Tree**:
```
        1
       / \
      2   3
     / \ / 
    4  5 6
```

This tree is complete since all levels except the last are fully filled, and the nodes on the last level are left-aligned.

**Example of an Incomplete Binary Tree**:
```
        1
       / \
      2   3
       \
        5
```

This tree is not complete because node `5` is not as far left as possible.

**Approach**:
1. First, count the total number of nodes in the tree (`totalCount`).
2. Use a recursive function (`isCBT`) to verify if the tree satisfies the completeness condition by following the index rules for a complete binary tree. In a complete binary tree:
   - The left child of a node at index `i` is located at index `2 * i + 1`.
   - The right child is at index `2 * i + 2`.
3. If at any point an index exceeds the total number of nodes, the tree is not complete.

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
    int totalCount(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + totalCount(root -> left) + totalCount(root -> right);
    }
    int isCBT(TreeNode* root, int index, int count){
        if(root == NULL) return true;
        if(index >= count) return false;

        bool left = isCBT(root -> left, 2 * index + 1, count);
        bool right = isCBT(root -> right, 2 * index + 2, count);

        return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int count = totalCount(root);
        return isCBT(root, index, count);
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    // Helper function to count the total nodes in the tree.
    int totalCount(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + totalCount(root -> left) + totalCount(root -> right);
    }
```
- **`totalCount` Function**: This function calculates the total number of nodes in the tree.
  - If the `root` is `NULL`, it returns `0` (no nodes).
  - Otherwise, it recursively counts the nodes in the left and right subtrees and adds `1` for the current node.

```cpp
    int isCBT(TreeNode* root, int index, int count){
        if(root == NULL) return true;
        if(index >= count) return false;

        bool left = isCBT(root -> left, 2 * index + 1, count);
        bool right = isCBT(root -> right, 2 * index + 2, count);

        return left && right;
    }
```
- **`isCBT` Function**: This function recursively checks whether the binary tree is complete.
  - If `root` is `NULL`, it returns `true` (an empty tree is considered complete).
  - If `index >= count`, it returns `false`, as it implies that a node at this position should not exist in a complete binary tree with `count` nodes.
  - It recursively checks the left and right subtrees with updated indices based on the formula for complete binary trees (`2 * index + 1` for left child and `2 * index + 2` for right child).
  - Finally, it returns `true` only if both left and right subtrees are complete.

```cpp
    bool isCompleteTree(TreeNode* root) {
        int index = 0;
        int count = totalCount(root);
        return isCBT(root, index, count);
    }
};
```
- **`isCompleteTree` Function**: This function initiates the process of checking completeness.
  - First, it calculates the total node count with `totalCount`.
  - Then it calls `isCBT` to check the completeness of the tree from the root.

### Step 3: Examples and Explanation

1. **Example 1**:
   - **Tree**:
     ```
         1
        / \
       2   3
      / \
     4   5
     ```
   - **Process**:
     - `totalCount` calculates `count = 5`.
     - `isCBT` is called for each node, validating the left and right subtrees according to index constraints.
     - Output: **`true`** (This is a complete binary tree).

2. **Example 2**:
   - **Tree**:
     ```
         1
        / \
       2   3
          /
         4
     ```
   - **Process**:
     - `totalCount` calculates `count = 4`.
     - `isCBT` identifies that `node 4` is not at the leftmost position on its level.
     - Output: **`false`** (This is not a complete binary tree).

### Step 4: Time and Space Complexity

- **Time Complexity**:
  - `totalCount` traverses all nodes, making its time complexity **O(N)**.
  - `isCBT` also traverses all nodes, so it has a time complexity of **O(N)**.
  - Overall, the time complexity is **O(N)**.

- **Space Complexity**:
  - The recursion in `totalCount` and `isCBT` could go as deep as the height of the tree, making the space complexity **O(H)**, where `H` is the height of the tree. In the worst case (skewed tree), `H` can be `N`, but in a balanced tree, `H` is `log N`.

### Step 5: Recommendations

- **Handling Edge Cases**: Ensure to handle edge cases like an empty tree or a tree with a single node.
- **Alternative Approach**: A level-order traversal could also be used to check completeness level by level, which might be easier to understand for some cases.
- **Practice**: Try to manually trace through different binary tree structures to gain confidence in understanding completeness conditions.
