<h1 align='center'>Balance - a Binary - Search - Tree</h1>

## Problem Statement

**Problem URL :** [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree/)

![image](https://github.com/user-attachments/assets/a0f759f7-f26e-4243-a9b1-6d5bdd78af84)
![image](https://github.com/user-attachments/assets/b85a4bea-d997-4c9d-88d0-f0e2f41ad669)

## Problem Explanation
Given a **Binary Search Tree (BST)**, the task is to convert it into a **balanced BST**. A balanced BST ensures that the height difference between the left and right subtrees of any node is no more than 1. This balancing helps keep the search operations efficient.

#### Approach to Solve the Problem

1. **In-Order Traversal**:
   - Performing an in-order traversal of a BST visits nodes in ascending order. We store these nodes in an array or vector.
   - This array will contain the sorted values of the BST nodes.

2. **Rebuild the Balanced BST**:
   - Using the sorted array from the in-order traversal, we can build a balanced BST by picking the middle element as the root of each subtree. This middle element division helps keep the BST balanced.
   - By recursively choosing the middle element of each subarray, we ensure each subtree is balanced.

#### Example

Consider a skewed BST like this:
```
    10
      \
       20
         \
          30
            \
             40
```

Performing an in-order traversal on this BST gives the array `[10, 20, 30, 40]`.

Rebuilding this as a balanced BST gives:
```
       20
      /  \
    10    30
            \
             40
```

This balanced BST has a reduced height, making it more efficient for search operations.

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
    void inOrder(TreeNode* root, vector<TreeNode*> &inOrderValues){
        if(root == NULL) return;

        inOrder(root -> left, inOrderValues);
        inOrderValues.push_back(root);
        inOrder(root -> right, inOrderValues);
    }

    TreeNode* inorderToBST(int start, int end, vector<TreeNode*> &inOrderValues){
        if(start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode* root = inOrderValues[mid];

        root -> left = inorderToBST(start, mid-1, inOrderValues);
        root -> right = inorderToBST(mid + 1, end, inOrderValues);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inOrderValues;
        inOrder(root, inOrderValues);

        return inorderToBST(0, inOrderValues.size()-1, inOrderValues);
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
```
- Defines the `Solution` class with public member functions.

```cpp
    void inOrder(TreeNode* root, vector<TreeNode*> &inOrderValues){
        if(root == NULL) return;
```
- `inOrder` is a helper function to perform an in-order traversal of the BST.
- If `root` is `NULL`, it means there are no nodes to process, so it immediately returns.

```cpp
        inOrder(root -> left, inOrderValues);
        inOrderValues.push_back(root);
        inOrder(root -> right, inOrderValues);
    }
```
- This function recursively traverses the left subtree, then adds the current node (`root`) to the vector `inOrderValues`, and finally traverses the right subtree.
- The result is a sorted vector `inOrderValues` containing all nodes in ascending order.

```cpp
    TreeNode* inorderToBST(int start, int end, vector<TreeNode*> &inOrderValues){
        if(start > end) return NULL;
```
- `inorderToBST` is a recursive function that builds a balanced BST from the sorted nodes in `inOrderValues`.
- If `start` is greater than `end`, it means there are no nodes left to form a subtree, so it returns `NULL`.

```cpp
        int mid = start + (end - start) / 2;
```
- Calculates the middle index of the current range, which is the middle element of the sorted array.
- This middle element becomes the root of the current subtree, ensuring balance.

```cpp
        TreeNode* root = inOrderValues[mid];
```
- Sets the node at the `mid` index as the root for the current subtree.

```cpp
        root -> left = inorderToBST(start, mid-1, inOrderValues);
        root -> right = inorderToBST(mid + 1, end, inOrderValues);
```
- Recursively sets the `left` child to a balanced subtree from elements left of `mid`.
- Recursively sets the `right` child to a balanced subtree from elements right of `mid`.

```cpp
        return root;
    }
```
- Returns the `root` of the subtree, which will be attached to the main balanced BST.

```cpp
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inOrderValues;
        inOrder(root, inOrderValues);
```
- `balanceBST` is the main function to create the balanced BST.
- First, it calls `inOrder` to populate `inOrderValues` with nodes in sorted order.

```cpp
        return inorderToBST(0, inOrderValues.size()-1, inOrderValues);
    }
};
```
- It then calls `inorderToBST` to construct the balanced BST from `inOrderValues` and returns the root of the new balanced BST.

### Step 3: Example Walkthrough

Consider a skewed BST like:
```
    10
      \
       20
         \
          30
            \
             40
```

1. **In-Order Traversal**:
   - The `inOrder` function will populate `inOrderValues` with `[10, 20, 30, 40]`.

2. **Rebuilding the Balanced BST**:
   - `inorderToBST(0, 3)` is called with `start = 0` and `end = 3`.
     - Middle index `mid = 1`, so `inOrderValues[1]` (20) becomes the root.
     - **Left Subtree**: `inorderToBST(0, 0)` creates a subtree with `10` as the root.
     - **Right Subtree**: `inorderToBST(2, 3)` creates a subtree rooted at `30`, with `40` as its right child.

   The resulting balanced BST is:
   ```
       20
      /  \
    10    30
            \
             40
   ```

### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - **In-Order Traversal**: \( O(n) \) to traverse and store nodes in `inOrderValues`.
   - **Balanced Tree Construction**: \( O(n) \), as each node is processed once in `inorderToBST`.
   - **Total Time Complexity**: \( O(n) \).

2. **Space Complexity**:
   - **Auxiliary Space for Vector**: \( O(n) \), for `inOrderValues`.
   - **Recursive Call Stack**: \( O(\log n) \) for a balanced tree and up to \( O(n) \) for a skewed tree.
   - **Total Space Complexity**: \( O(n) \).

### Step 5: Recommendations for Students

- **Practice In-Order Traversal**: In-order traversal is essential for working with BSTs. Get comfortable with it, as it appears often in BST problems.
- **Recursive Tree Building**: Understanding recursive tree construction from sorted lists is a valuable skill that can help in similar tree problems.
- **Analyze Complexity**: Be sure to understand the time and space complexity of each function and how the recursive stack works, as this can help in optimizing solutions for larger inputs.
