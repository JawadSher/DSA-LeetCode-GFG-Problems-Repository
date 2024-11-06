<h1 align='center'>Construct - Binary - Search - Tree - From - Pre-Order - Traversal</h1>

## Problem Statement

**Problem URL :** [Construct Binary Search Tree from Pre-order Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)

![image](https://github.com/user-attachments/assets/d2ba8a81-ea8f-4b55-bd0a-b899e844e88c)
![image](https://github.com/user-attachments/assets/71c26f10-04c0-4b8f-ab76-8666557b9e72)

## Problem Explanation
The problem asks us to construct a **Binary Search Tree (BST)** from the **preorder traversal** sequence. The preorder traversal visits the nodes in the following order: **Root -> Left Subtree -> Right Subtree**.

Given a sequence of values that represents the preorder traversal of a BST, we need to reconstruct the original BST.

#### Approach to Solve the Problem

1. **Understanding Preorder Traversal**:
   - In a BST, for any node:
     - All values in the **left subtree** are smaller than the node's value.
     - All values in the **right subtree** are greater than the node's value.
   - The first value in the preorder sequence is the **root** of the tree.
   - The subsequent values represent the preorder traversal of the left and right subtrees.
   
2. **Recursive Tree Construction**:
   - Starting from the first value (root), recursively construct the left and right subtrees:
     - The left subtree consists of values smaller than the root.
     - The right subtree consists of values greater than the root.
   - This recursive approach is governed by maintaining valid ranges (`mini` and `maxi`) for each node to ensure the BST property is upheld.

#### Example

Given the preorder traversal array:
```
[8, 5, 1, 7, 10, 12]
```

- The first element (`8`) is the root of the BST.
- The next value (`5`) is less than `8`, so it becomes the left child of `8`.
- The next value (`1`) is less than `5`, so it becomes the left child of `5`.
- The next value (`7`) is greater than `5` but less than `8`, so it becomes the right child of `5`.
- The next value (`10`) is greater than `8`, so it becomes the right child of `8`.
- The next value (`12`) is greater than `10`, so it becomes the right child of `10`.

The final tree looks like this:
```
        8
       / \
      5   10
     / \    \
    1   7   12
```

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
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int &i){
        if(i >= preorder.size()) return NULL;

        if(preorder[i] < mini || preorder[i] > maxi) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root -> left = solve(preorder, mini, root -> val, i);
        root -> right = solve(preorder, root -> val, maxi, i);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;

        int i = 0;
        return solve(preorder, mini, maxi, i);
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
```
- Defines the `Solution` class, which contains the function to solve the problem.

```cpp
    TreeNode* solve(vector<int>& preorder, int mini, int maxi, int &i){
        if(i >= preorder.size()) return NULL;
```
- `solve` is a helper function that will recursively build the BST.
- `preorder` is the input array representing the preorder traversal.
- `mini` and `maxi` represent the valid range of values for the current subtree.
- `i` is the index pointer that tracks the current element in the `preorder` array.
- If `i` exceeds the size of the array, it means we've processed all nodes, and `NULL` is returned (base case).

```cpp
        if(preorder[i] < mini || preorder[i] > maxi) return NULL;
```
- If the current value `preorder[i]` is outside the valid range (`mini` to `maxi`), it violates the BST property, so `NULL` is returned.

```cpp
        TreeNode* root = new TreeNode(preorder[i++]);
```
- A new node is created with the value `preorder[i]`.
- The value of `i` is incremented to move to the next element for the next recursive call.

```cpp
        root -> left = solve(preorder, mini, root -> val, i);
        root -> right = solve(preorder, root -> val, maxi, i);
```
- The left subtree is built by calling `solve` with the range from `mini` to `root->val`. This ensures all left children are smaller than the root.
- The right subtree is built by calling `solve` with the range from `root->val` to `maxi`. This ensures all right children are larger than the root.

```cpp
        return root;
    }
```
- Returns the root of the current subtree (the node created in this function).

```cpp
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
```
- The main function `bstFromPreorder` initializes the range for the root node (`mini = INT_MIN` and `maxi = INT_MAX`), representing the entire valid range for the root value.
- `i` is implicitly initialized to 0 at the start.

```cpp
        int i = 0;
        return solve(preorder, mini, maxi, i);
    }
};
```
- Calls the helper function `solve` to start building the BST.
- Returns the root of the constructed BST.

### Step 3: Example Walkthrough

Let's walk through an example:

Given the preorder traversal:
```
[8, 5, 1, 7, 10, 12]
```

1. **Initial Call**:
   - `solve([8, 5, 1, 7, 10, 12], INT_MIN, INT_MAX, i)` is called with `i = 0`.
   - `preorder[0] = 8` is within the range `INT_MIN` to `INT_MAX`, so it becomes the root.
   - Increment `i` to 1.

2. **Left Subtree**:
   - Call `solve([8, 5, 1, 7, 10, 12], INT_MIN, 8, i)` with `i = 1`.
   - `preorder[1] = 5` is within the range `INT_MIN` to `8`, so it becomes the left child of `8`.
   - Increment `i` to 2.
   - Call `solve([8, 5, 1, 7, 10, 12], INT_MIN, 5, i)` to build the left subtree of `5`.

3. **Left Subtree of 5**:
   - `preorder[2] = 1` is within the range `INT_MIN` to `5`, so it becomes the left child of `5`.
   - Increment `i` to 3.
   - Call `solve([8, 5, 1, 7, 10, 12], INT_MIN, 1, i)` to build the left subtree of `1`. This returns `NULL`.

4. **Right Subtree of 5**:
   - Call `solve([8, 5, 1, 7, 10, 12], 5, 8, i)` to build the right subtree of `5`.
   - `preorder[3] = 7` is within the range `5` to `8`, so it becomes the right child of `5`.
   - Increment `i` to 4.

The tree continues building similarly for the rest of the values. The final BST is:
```
        8
       / \
      5   10
     / \    \
    1   7   12
```

### Step 4: Time and Space Complexity

1. **Time Complexity**:
   - The time complexity of the algorithm is **O(n)**, where `n` is the number of nodes in the tree. This is because each node is processed exactly once in the preorder traversal.

2. **Space Complexity**:
   - The space complexity is **O(h)**, where `h` is the height of the tree due to the recursive call stack. In the worst case (if the tree is skewed), `h` can be `n`, leading to a space complexity of **O(n)**.
   - Additionally, the space required to store the tree is **O(n)** because each node of the tree needs to be stored.

### Step 5: Recommendations for Students

- **Understand Preorder Traversal**: Preorder traversal is crucial in tree problems. Make sure you are comfortable with it, as it helps in various types of tree construction problems.
- **Recursive Problem Solving**: This problem is a great example of using recursion for tree construction. Practice solving similar problems recursively, as it is a common approach for tree-related tasks.
- **Edge Case Considerations**: Always think about edge cases such as an empty tree (when the input preorder is empty) or trees with only one node. Handling these gracefully is important in real-world coding.

