<h1 align='center'>Kth - Smallest - Element - In a - BST</h1>

## Problem Statement

**Problem URL :** [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

![image](https://github.com/user-attachments/assets/4fe3cb7a-d1d7-4d14-8a9d-890f7299cc59)
![image](https://github.com/user-attachments/assets/c04fafd3-0728-4fb2-a36f-844b883c0334)

## Problem Explanation
Given a Binary Search Tree (BST) and an integer `k`, the task is to find the `k`th smallest element in the BST. In a BST, the in-order traversal (left-root-right) produces elements in ascending order. 

**Example**:
Let's look at a couple of examples:

1. **Example 1**:
   ```plaintext
       3
      / \
     1   4
      \
       2
   ```
   - If `k = 1`, the output should be `1` (the smallest element).
   - If `k = 3`, the output should be `3` (the third smallest element).

- If `k = 3`, the output should be `3`.

**Constraints**:
1. The number of nodes in the tree ranges from `1` to `10^4`.
2. `k` is always valid, meaning `1 <= k <= total number of nodes`.

**Edge Cases**:
1. If there’s only one node, `k` must be `1`, so we return that node’s value.
2. A very small or very large `k` should be checked correctly based on node count.

### Step 2: Approach

Since an in-order traversal of a BST produces sorted elements, the `k`th smallest element is simply the `k`th node visited in in-order.

**Steps**:
1. Perform an in-order traversal, which will naturally visit nodes in ascending order.
2. Use a counter (`i`) to keep track of the number of nodes visited.
3. Once `i` reaches `k`, we’ve found the `k`th smallest element and can return it immediately without further traversals.

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
    int solve(TreeNode* root, int &i, int k){
        if(root == NULL) return -1;

        int left = solve(root -> left, i, k);
        if(left != -1) return left;

        i++;
        if(i == k) return root -> val;

        return solve(root -> right, i, k);
    }
    int kthSmallest(TreeNode* root, int k) {

        int i = 0;
        int ans = solve(root, i, k);

        return ans;
    }
};
```

## Problem Solution Explanation
Here’s a detailed explanation for solving the "Kth Smallest Element in a BST" problem from LeetCode using the provided code and structure:

```cpp
class Solution {
public:
    int solve(TreeNode* root, int &i, int k){
        if(root == NULL) return -1;
```
- **Function**: `solve`
- **Purpose**: Recursively finds the `k`th smallest element.
- **Parameters**:
  - `TreeNode* root`: Pointer to the current node.
  - `int &i`: Reference counter for the number of nodes visited so far.
  - `int k`: The target position (kth smallest element).

- **Base Case**: If `root` is `NULL`, we return `-1`, as there’s nothing to process.

```cpp
        int left = solve(root->left, i, k);
        if(left != -1) return left;
```
- **Left Subtree Traversal**: Recursively call `solve` on the left subtree.
- **Check Return**: If the left subtree call found the `k`th smallest element (returning a non-`-1` value), immediately return it, as it will propagate up the recursive calls.

```cpp
        i++;
        if(i == k) return root->val;
```
- **Increment Counter**: After visiting the left subtree, we increase the counter `i` to reflect the current node visit.
- **Check Position**: If `i` equals `k`, we’ve found the `k`th smallest element and return the current node’s value (`root->val`).

```cpp
        return solve(root->right, i, k);
    }
```
- **Right Subtree Traversal**: If the `k`th smallest element hasn’t been found, we continue with the right subtree.

```cpp
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = solve(root, i, k);
        return ans;
    }
};
```
- **Wrapper Function**: `kthSmallest`
  - Initializes the counter `i` to `0` and starts the recursion with `solve`.
  - Returns the result of `solve`, which is the `k`th smallest element.

### Step 4: Output Examples

1. **Example 1**:
   ```plaintext
       3
      / \
     1   4
      \
       2
   ```
   **Input**: `k = 1`
   **Output**: `1`
   **Explanation**: The smallest element is `1`.

3. **Edge Case (Single Node)**:
   ```plaintext
       1
   ```
   **Input**: `k = 1`
   **Output**: `1`
   **Explanation**: A single-node tree has only one element, which is also the smallest.

### Step 5: Time and Space Complexity

**Time Complexity**: \(O(H + k)\)
- **Traversal Cost**: In the best case, we may need to traverse only part of the tree to find the `k`th smallest element. The complexity is influenced by the height of the tree (`H`) and `k`.
  - In a balanced BST, `H = O(\log n)`, so the complexity becomes \(O(\log n + k)\).
  - In a worst-case scenario (skewed tree), `H` can be \(O(n)\), so the complexity could be \(O(n)\).

**Space Complexity**: \(O(H)\)
- **Recursive Stack**: The space complexity depends on the maximum depth of the recursive stack, which is the height `H` of the tree.
  - For a balanced tree, this would be \(O(\log n)\).
  - For a skewed tree, this could be \(O(n)\).


### Additional Tips

- **Edge Cases**: Always handle trees with a single node or cases where `k` is the number of nodes in the tree.
- **Optimizations**: For extremely large trees, consider an iterative approach to minimize recursive overhead.
- **Real-world Analogy**: Think of an in-order traversal as a sorted array, where each element corresponds to a position in the array. Finding the `k`th smallest element is like accessing the `k`th position in a sorted list.

This method provides a clear, efficient way to find the `k`th smallest element in a BST by leveraging in-order traversal.
