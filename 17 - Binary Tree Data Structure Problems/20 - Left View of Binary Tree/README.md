<h1 align='center'>Left - View - Of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Left View of Binary Tree](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/4348fe64-171c-41fc-8917-40d5eb237df4)
![image](https://github.com/user-attachments/assets/aae3dc2c-f50e-47e8-8ade-a8e70b28c274)

## Problem Explanation
The **Left View** of a binary tree is the set of nodes visible when the tree is viewed from the left side. For each level of the tree, the first node encountered from the left side is included in the left view.

For example:

Given the binary tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
           /
          7
```

The **Left View** of this binary tree would be `[1, 2, 4, 7]`.

### Step 2: Approach and Explanation

To solve this problem, we can use a **recursive approach with depth tracking**:
1. Perform a **preorder traversal** (root -> left -> right) so we visit nodes level by level from left to right.
2. Track the **current level** of the tree during traversal.
3. For each level, if this is the first time we reach that level, add the node's data to our answer vector. 
4. By doing this, we ensure that only the leftmost node at each level is added to the left view.

## Problem Solution
```cpp
class Solution {
  private: 
    void solve(Node* root, vector<int> &ans, int level){
        if(root == NULL) return;
        
        if(level == ans.size()) ans.push_back(root -> data);
        
        solve(root -> left, ans, level+1);
        solve(root -> right, ans, level+1);
    }
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        
        solve(root, ans, 0);
        
        return ans;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  private: 
    void solve(Node* root, vector<int> &ans, int level){
        if(root == NULL) return;
```
- Defines a helper function `solve` that takes the current node (`root`), a reference to the answer vector (`ans`), and the current level of the tree (`level`).
- If the `root` is `NULL`, return, as there are no nodes to process.

```cpp
        if(level == ans.size()) ans.push_back(root -> data);
```
- **Condition check**: If `level` is equal to the current size of `ans`, it means we’re at a new level not yet recorded in `ans`.
- If true, add the `root`'s data to `ans`. This ensures we only add the leftmost node of each level to the result.

```cpp
        solve(root -> left, ans, level+1);
        solve(root -> right, ans, level+1);
    }
```
- Recursively call `solve` on the left child (`root->left`) and right child (`root->right`) with the incremented `level`.
- This order (left before right) ensures that we always process the leftmost nodes at each level before the right nodes.

```cpp
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        
        solve(root, ans, 0);
        
        return ans;
    }
};
```
- The `leftView` function is the main function that initializes an empty vector `ans` to store the left view nodes.
- Calls the helper function `solve` with `root`, `ans`, and the initial `level` set to `0`.
- Finally, it returns `ans`, which now contains the nodes visible from the left view.

---

### Step 4: Output Examples with Explanation

Let's consider an example.

#### Example 1
Input:
```
        1
       / \
      2   3
     / \   \
    4   5   6
           /
          7
```
- At **level 0**, we add `1` to `ans`.
- At **level 1**, the leftmost node is `2`, so we add `2` to `ans`.
- At **level 2**, the leftmost node is `4`, so we add `4` to `ans`.
- At **level 3**, the leftmost node is `7`, so we add `7` to `ans`.

Output: `[1, 2, 4, 7]`

#### Example 2
Input:
```
        10
       /
      20
       \
        30
         \
          40
```
Output: `[10, 20, 30, 40]`

### Step 5: Time and Space Complexity

#### Time Complexity
- **O(N)**: We visit each node in the tree exactly once, where **N** is the total number of nodes in the tree.

#### Space Complexity
- **O(H)**: The recursive stack takes up to **H** space, where **H** is the height of the tree. The `ans` vector also takes up **O(H)** space for storing nodes in the left view.
