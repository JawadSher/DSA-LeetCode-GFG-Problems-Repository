<h1 align='center'>Validate - Binary - Search - Tree</h1>

## Problem Statement

**Problem URL :** [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

![image](https://github.com/user-attachments/assets/f8b0cd62-603f-4b25-be7d-2587f25e61d5)
![image](https://github.com/user-attachments/assets/4b7231fd-10de-4972-bebf-4b99fb627e17)

## Problem Explanation
Given a binary tree, determine if it is a valid binary search tree (BST). In a valid BST:
1. Each node's left subtree contains only nodes with values less than the node’s value.
2. Each node's right subtree contains only nodes with values greater than the node’s value.
3. Both the left and right subtrees must also be binary search trees.

**Example**:
Let's look at an example to clarify:
```plaintext
    2
   / \
  1   3
```
This tree is a valid BST because:
- The left child `1` is less than `2`.
- The right child `3` is greater than `2`.

Another example:
```plaintext
    5
   / \
  1   4
     / \
    3   6
```
This tree is not a valid BST because `3` is in the right subtree of `5` but is less than `5`.

**Constraints**:
- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`

**Edge Cases**:
1. A single-node tree is always a valid BST.
2. If all nodes have the same value, the tree cannot be a valid BST (except when there's only one node).
3. An empty tree is considered a valid BST.

---

### Step 2: Approach

To check if a tree is a valid BST, we need to validate that each node follows the BST property by setting boundaries (minimum and maximum values) for each node.

**Recursive Approach**:
1. Start at the root node, initially allowing the range `(-∞, ∞)` for its value.
2. For each node:
   - If the node’s value is not within its allowable range (`min < val < max`), return `false`.
   - Recur for the left subtree with an updated maximum (`max = node.val`).
   - Recur for the right subtree with an updated minimum (`min = node.val`).
3. If every node respects the constraints in its subtree, the tree is a valid BST.
   
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
    bool isBST(TreeNode* root, long min, long max){
        if(root == NULL) return true;

        if(root -> val > min && root -> val < max){
            bool left = isBST(root -> left, min, root -> val);
            bool right = isBST(root -> right, root -> val, max);

            return left && right;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
```

## Problem Solution Explanation

Let's walk through the code line by line.

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
```
The `TreeNode` structure is a basic representation of each node in a binary tree. Each node has:
- `val`: the node’s value,
- `left`: a pointer to the left child,
- `right`: a pointer to the right child.

```cpp
class Solution {
public:
    bool isBST(TreeNode* root, long min, long max) {
```
- **Function**: `isBST`
- **Purpose**: Recursively check if the tree is a valid BST within the given range `(min, max)`.

```cpp
        if(root == NULL) return true;
```
- Base Case: If `root` is `NULL`, it means we've reached the end of a path, and no BST violation was found, so we return `true`.

```cpp
        if(root->val > min && root->val < max) {
```
- Check if `root->val` is within the allowed range `(min, max)`.
- If it’s not, the tree is not a valid BST, so we return `false`.

```cpp
            bool left = isBST(root->left, min, root->val);
            bool right = isBST(root->right, root->val, max);
```
- Recursive Checks:
   - **Left Subtree**: Call `isBST` on `root->left` with an updated `max = root->val`.
   - **Right Subtree**: Call `isBST` on `root->right` with an updated `min = root->val`.
   - Store the results in `left` and `right`.

```cpp
            return left && right;
```
- Combine results: Return `true` only if both `left` and `right` subtrees are valid BSTs.

```cpp
        } else {
            return false;
        }
```
- If `root->val` is not within the range, return `false`.

```cpp
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
```
- **isValidBST**: Initializes the recursion with `LONG_MIN` and `LONG_MAX` boundaries for the root node.

### Step 4: Output Examples

**Example 1**:
Input:
```plaintext
    2
   / \
  1   3
```
Output: `true`
Explanation: This tree satisfies the BST properties.

**Example 2**:
Input:
```plaintext
    5
   / \
  1   4
     / \
    3   6
```
Output: `false`
Explanation: The node with value `3` in the right subtree of `5` is less than `5`, so it violates the BST property.


### Step 5: Time and Space Complexity

**Time Complexity**: \(O(n)\)
- Each node is visited once, so the time complexity is linear with respect to the number of nodes.

**Space Complexity**: \(O(h)\)
- This is the height of the tree, which corresponds to the recursive call stack. In the worst case (for a skewed tree), this is \(O(n)\), and in the best case (balanced tree), it is \(O(\log n)\).


### Additional Tips:
- **Binary Tree Properties**: Understanding the properties of BSTs is crucial for this problem.
- **Edge Cases**: Testing for edge cases such as null trees, single-node trees, and trees with duplicate values can help ensure the code is robust.

