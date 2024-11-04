<h1 align='center'>Search - In a - Binary - Search - Tree</h1>

## Problem Statement

**Problem URL :** [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/description/)

![image](https://github.com/user-attachments/assets/7f1e0ee8-09f6-4ce1-80b8-96022eb73107)
![image](https://github.com/user-attachments/assets/9e940976-e086-488c-be85-fbb099a09637)

## Problem Explanation
Given a Binary Search Tree (BST) and a target value, the task is to locate the node in the BST that contains the target value. If the node exists, return the subtree rooted at that node. If the node does not exist in the tree, return `null`.

A **Binary Search Tree** has specific properties:
- Each node’s left child contains values **less than** the node’s value.
- Each node’s right child contains values **greater than** the node’s value.

Using these properties, we can efficiently search for the target value by comparing it with each node's value as we traverse the tree.

### Example 1

**Input:**
- A BST with the structure:
  ```
        4
       / \
      2   7
     / \
    1   3
  ```
- Target Value: `2`

**Output:**
- A subtree rooted at the node with value `2`:
  ```
      2
     / \
    1   3
  ```

**Explanation:**
- The function starts at the root (node with value `4`).
- Since `2` is less than `4`, we move to the left child (node with value `2`).
- The current node’s value is `2`, which matches the target value.
- So, the function returns the subtree rooted at this node, which includes `2` and its children `1` and `3`.

### Example 2

**Input:**
- A BST with the structure:
  ```
        4
       / \
      2   7
     / \
    1   3
  ```
- Target Value: `5`

**Output:**
- `null`

**Explanation:**
- The function starts at the root (node with value `4`).
- Since `5` is greater than `4`, we move to the right child (node with value `7`).
- The current node’s value is `7`, but `5` is less than `7`.
- We move to the left child of `7`, but there is no left child, meaning we’ve reached a `null` node.
- Since we couldn’t find the node with value `5`, the function returns `null`.

### Example 3

**Input:**
- A BST with only the root node:
  ```
      10
  ```
- Target Value: `10`

**Output:**
- The subtree rooted at the node with value `10`:
  ```
      10
  ```

**Explanation:**
- The target value matches the root node’s value, so the function returns the entire tree, which in this case is just the single node with value `10`.

### Key Points
1. The function returns the subtree rooted at the target node if the target exists.
2. If the target node is not found, the function returns `null`.
3. By leveraging the properties of a BST, we can skip unnecessary comparisons, making this a more efficient search.
   
## Problem Solution
```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int value) {
        if(root == NULL) return NULL;

        if(root -> val == value) return root;

        if(root -> val < value) return searchBST(root -> right, value);
        else return searchBST(root -> left, value);

        return root;
    }
};
```

## Problem Solution Explanation
1. **Class Declaration: `Solution`**
   ```cpp
   class Solution {
   ```
   - This line declares a class named `Solution`.
   - The purpose of this class is to hold the `searchBST` method, which performs a search in a Binary Search Tree (BST).
   - In LeetCode-style problems, functions are often encapsulated within a class for organizational purposes.

2. **Public Access Modifier**
   ```cpp
   public:
   ```
   - This is an access modifier. It allows the methods and members declared under it to be accessible from outside the class.
   - The `searchBST` method is declared under `public` to make it accessible to any code that creates an instance of `Solution`.

3. **Function Declaration: `searchBST`**
   ```cpp
   TreeNode* searchBST(TreeNode* root, int value) {
   ```
   - This line declares the `searchBST` function, which will search for a node containing the specified `value` in the BST.
   - It takes two arguments:
     - `TreeNode* root`: A pointer to the root node of the BST (or a subtree).
     - `int value`: The integer value that we want to locate in the BST.
   - The function returns a pointer to the `TreeNode` where the value is found. If the value is not found, it returns `NULL`.

4. **Base Case: Check if `root` is `NULL`**
   ```cpp
   if(root == NULL) return NULL;
   ```
   - This line checks if the `root` node is `NULL`.
   - If `root` is `NULL`, it means either the tree is empty or we've reached a leaf node without finding the target value.
   - In this case, the function returns `NULL` to indicate that the value does not exist in the tree.

5. **Check if the Current Node Contains the Target Value**
   ```cpp
   if(root->val == value) return root;
   ```
   - This line checks if the current `root` node's value is equal to the target `value`.
   - If they are equal, it means we have found the target node.
   - The function returns the pointer to the current node (`root`), which contains the target `value`.

6. **Decision to Search in the Right or Left Subtree**
   ```cpp
   if(root->val < value) return searchBST(root->right, value);
   else return searchBST(root->left, value);
   ```
   - **Condition `root->val < value`**:
     - This checks if the current node’s value is less than the target `value`.
     - Since this is a BST, if the current data is less than the target, the target must be in the **right subtree** (if it exists).
     - The function calls itself recursively on the right subtree (`root->right`) with the same target `value`.
     - This recursive call continues searching down the right branch until it either finds the node with the target value or reaches a `NULL` node.
   
   - **`else` Condition**:
     - If the current node’s value is **greater than** the target `value`, the target must be in the **left subtree** (if it exists).
     - The function calls itself recursively on the left subtree (`root->left`) with the target `value`.
     - This recursive call continues the search down the left branch of the tree.

7. **Redundant `return root;` (Safeguard)**
   ```cpp
   return root;
   ```
   - This line is technically redundant because all possible cases (matching, left, and right subtree) have already been handled.
   - It will never actually be reached due to the previous `return` statements.
   - However, it serves as a safeguard to ensure that the function has a return statement in all code paths, even though it won’t be executed.

---

### Summary of Code Execution

- The `searchBST` function is designed to locate a specific node containing `value` in a BST.
- The function uses the properties of a BST to reduce the search space by half at each step, making it efficient.
- If the node with the target `value` is found, the function returns a pointer to that node.
- If the function reaches a `NULL` pointer without finding the target value, it returns `NULL`, indicating that the value does not exist in the BST.

### Example Outputs

Let's see some example outputs for this function in action:

1. **Example 1**:
   - **Input**: `searchBST(root, 5)`
   - **Output**: Pointer to the node containing `5`
   - **Explanation**: The node with the value `5` exists in the BST, so the function returns a pointer to that node.

2. **Example 2**:
   - **Input**: `searchBST(root, 12)`
   - **Output**: `NULL`
   - **Explanation**: The value `12` is not present in the BST, so the function returns `NULL`.

3. **Example 3**:
   - **Input**: `searchBST(root, 10)`
   - **Output**: Pointer to the root node (assuming root has value `10`)
   - **Explanation**: The root node itself contains the value `10`, so the function returns the root node.

---

### Time and Space Complexity

- **Time Complexity**: \(O(h)\), where \(h\) is the height of the BST.
  - In the best case (balanced BST), the height \(h\) is \(O(\log n)\), where \(n\) is the number of nodes.
  - In the worst case (unbalanced BST, resembling a linked list), the height \(h\) is \(O(n)\).

- **Space Complexity**: \(O(h)\) for the recursive call stack.
  - In a balanced tree, this would be \(O(\log n)\), while in an unbalanced tree, it could be \(O(n)\).

---

This breakdown should provide a clear understanding of the code and its functionality.
