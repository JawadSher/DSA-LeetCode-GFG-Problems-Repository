<h1 align='center'>Right - View - Of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Right View of Binary Tree](https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/2f93fd8c-107d-483f-8eb5-1b34ca78643a)
![image](https://github.com/user-attachments/assets/0363e332-5f00-4931-9eeb-1f6ffeb3e475)


## Problem Explanation

The **Right View** of a binary tree consists of the nodes visible when the tree is viewed from the right side. For each level of the tree, only the rightmost node is included in the right view.

For example:

Given the binary tree:
```
        1
       / \
      2   3
     /     \
    4       5
             \
              6
```

The **Right View** of this binary tree would be `[1, 3, 5, 6]`.

### Step 2: Approach and Explanation

To solve this problem, we use a **recursive approach with depth tracking**:
1. Perform a **modified preorder traversal** where we visit nodes in the order of root -> right -> left. This ensures that we encounter the rightmost nodes first at each level.
2. Track the **current level** as we traverse the tree.
3. For each level, if it is the first time we are encountering that level, we add the node’s data to our result vector (`ans`).
4. This way, only the rightmost node at each level is added to the right view.

## Problem Solution
```cpp
class Solution {
  private: 
    void solve(Node* root, vector<int> &ans, int level){
        if(root == NULL) return;
        
        if(level == ans.size()) ans.push_back(root -> data);
        
        solve(root -> right, ans, level+1);
        solve(root -> left, ans, level+1);
    }
  public:
    vector<int> rightView(Node *root) {
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
- If `root` is `NULL`, return as there are no nodes to process at this point.

```cpp
        if(level == ans.size()) ans.push_back(root -> data);
```
- **Condition check**: If `level` equals `ans.size()`, it means we are at a new level that hasn’t been recorded in `ans` yet.
- Adds the `root`'s data to `ans`, ensuring that only the rightmost node of each level is added to the result.

```cpp
        solve(root -> right, ans, level+1);
        solve(root -> left, ans, level+1);
    }
```
- Recursively calls `solve` on the right child (`root->right`) and then on the left child (`root->left`) with an incremented `level`.
- This order (right before left) ensures we always encounter and process the rightmost nodes at each level before the left nodes.

```cpp
  public:
    vector<int> rightView(Node *root) {
        vector<int> ans;
        
        solve(root, ans, 0);
        
        return ans;
    }
};
```
- The `rightView` function is the main function that initializes an empty vector `ans` to store the right view nodes.
- Calls the helper function `solve` with `root`, `ans`, and the initial `level` set to `0`.
- Returns `ans`, which now contains the nodes visible from the right view.

---

### Step 4: Output Examples with Explanation

Let's consider some examples to better understand how the function works.

#### Example 1
Input:
```
        1
       / \
      2   3
     /     \
    4       5
             \
              6
```
Explanation:
- **Level 0**: We add `1` to `ans`.
- **Level 1**: The rightmost node is `3`, so we add `3`.
- **Level 2**: The rightmost node is `5`, so we add `5`.
- **Level 3**: The rightmost node is `6`, so we add `6`.

Output: `[1, 3, 5, 6]`

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
Explanation:
- **Level 0**: We add `10`.
- **Level 1**: The rightmost node is `20`.
- **Level 2**: The rightmost node is `30`.
- **Level 3**: The rightmost node is `40`.

Output: `[10, 20, 30, 40]`

### Step 5: Time and Space Complexity

#### Time Complexity
- **O(N)**: We visit each node in the tree exactly once, where **N** is the total number of nodes in the tree.

#### Space Complexity
- **O(H)**: The recursive stack takes up to **H** space, where **H** is the height of the tree. The answer vector (`ans`) will also contain up to **H** nodes, one for each level in the right view.
