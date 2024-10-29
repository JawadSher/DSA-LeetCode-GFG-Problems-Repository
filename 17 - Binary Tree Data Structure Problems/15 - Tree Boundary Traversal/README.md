<h1 align='center'>Tree - Boundary - Traversal</h1>

## Problem Statement

**Problem URL :** [Tree Boundary Traversal](https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/10595c19-4921-4c10-9af4-86fda9af2983)
![image](https://github.com/user-attachments/assets/2a884702-0d1c-41fc-a35f-5dd0fe32574b)
![image](https://github.com/user-attachments/assets/6780653a-5c25-4e48-8a42-dc316d56e56c)
![image](https://github.com/user-attachments/assets/3232130f-e59a-442a-aa10-6b647b053a83)

## Problem Explanation

The goal is to traverse the boundary of a binary tree. The boundary of a tree consists of:
1. The **left boundary** (excluding the leaves).
2. The **leaf nodes** (from left to right).
3. The **right boundary** (excluding the leaves and in reverse order).

### Example
Given the binary tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
       / \
      7   8
```

**Boundary Traversal Output**: 
- **Left Boundary**: `1, 2` (from top to bottom, excluding leaves)
- **Leaf Nodes**: `4, 7, 8, 6` (in left to right order)
- **Right Boundary**: `3` (from bottom to top, excluding leaves)

**Final Result**: `[1, 2, 4, 7, 8, 6, 3]`

## Step 2: Approach

### Approach Explanation
1. **Identify the Parts of the Boundary**:
   - **Left Boundary**: Traverse down the leftmost path, skipping leaf nodes.
   - **Leaf Nodes**: Traverse the entire tree and collect leaf nodes.
   - **Right Boundary**: Traverse down the rightmost path in reverse, skipping leaf nodes.
   
2. **Implementation**:
   - Create three helper functions to handle left boundary traversal, leaf node collection, and right boundary traversal.
   - Use a vector to store the result and return it after processing all parts.

### Beginner-Friendly Steps
1. Start with the root node. If it's `NULL`, return an empty vector.
2. Add the root's value to the result vector.
3. Implement a recursive function to traverse the left boundary and skip leaf nodes.
4. Implement another function to collect all leaf nodes by recursively checking left and right children.
5. Implement the right boundary function to traverse the rightmost path, skipping leaf nodes, and store them in reverse order.
6. Combine all the collected nodes in the final result.

```cpp
class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
        
        ans.push_back(root -> data);
        
        if(root -> left) traverseLeft(root -> left, ans);
        else traverseLeft(root -> right, ans);
    }
    
    void traverseLeaf(Node* root, vector<int> &ans){
        if(root == NULL) return;
        
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
            
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
        
    }
    
    void traverseRight(Node* root, vector<int> &ans){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
        
        
        if(root -> right) traverseRight(root -> right, ans);
        else traverseRight(root -> left, ans);
        
        ans.push_back(root -> data);
    }

   
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        
        ans.push_back(root -> data);
        
        traverseLeft(root -> left, ans);
        
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
        
        traverseRight(root -> right, ans);
        
        return ans;
    }
};
```

## Problem Solution Explanation
Let's break down the code line by line:

```cpp
class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans){
```
- **Line 1**: Defines the class `Solution` and declares the method `traverseLeft` to traverse the left boundary of the tree.
- **Line 2**: Takes a pointer to the root node of the subtree and a reference to a vector `ans` to store results.

```cpp
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
```
- **Line 3**: Checks if the current node is `NULL` or if it's a leaf node (both children are `NULL`). If true, the function returns since there's nothing to add.

### Example:
- If `root` points to a leaf node like `4`, the function returns without adding anything to `ans`.

```cpp
        ans.push_back(root -> data);
```
- **Line 4**: Adds the current node's data to the `ans` vector, as it’s part of the left boundary.

### Example:
- For node `2`, `ans` becomes `[2]`.

```cpp
        if(root -> left) traverseLeft(root -> left, ans);
        else traverseLeft(root -> right, ans);
```
- **Lines 5-6**: If there’s a left child, recursively call `traverseLeft` on the left child. If there’s no left child, call it on the right child.

### Example:
- From `2`, it goes to `4` (the left child). If it were `3`, it would have traversed the right child instead.

```cpp
    void traverseLeaf(Node* root, vector<int> &ans){
```
- **Line 8**: Declares the `traverseLeaf` function to collect leaf nodes.

```cpp
        if(root == NULL) return;
```
- **Line 9**: Checks if the current node is `NULL`. If true, returns.

```cpp
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
```
- **Lines 10-12**: Checks if the current node is a leaf. If so, adds it to `ans` and returns.

### Example:
- For node `4`, it gets added to `ans`: `ans = [2, 4]`.

```cpp
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
```
- **Lines 13-14**: Recursively calls `traverseLeaf` on the left and right children.

### Example:
- From `2`, it will recursively check `4`, `5`, and subsequently `7` and `8`.

```cpp
    void traverseRight(Node* root, vector<int> &ans){
```
- **Line 16**: Declares the `traverseRight` function for traversing the right boundary.

```cpp
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) return;
```
- **Line 17**: Checks if the current node is `NULL` or a leaf node. If so, it returns.

```cpp
        if(root -> right) traverseRight(root -> right, ans);
        else traverseRight(root -> left, ans);
```
- **Lines 18-19**: First, traverses the right child. If it doesn’t exist, it goes to the left child.

### Example:
- For node `3`, it goes right to `6`, adding `3` later after the recursive calls return.

```cpp
        ans.push_back(root -> data);
```
- **Line 20**: Adds the current node’s data to the `ans` vector after the recursive calls have returned (this ensures it adds in reverse order).

### Example:
- After visiting `6`, it adds `3` to `ans`: `ans = [2, 4, 7, 8, 6, 3]` by the end.

```cpp
    vector <int> boundary(Node *root)
    {
        vector<int> ans;          // Result vector to hold the boundary values.
        if(root == NULL) return ans;  // If root is NULL, return empty result.
```
- **Line 22-24**: Declares the main function `boundary`, initializes an empty vector `ans`, and checks if `root` is `NULL`. If true, it returns `ans`.

```cpp
        ans.push_back(root -> data);  // Add the root's data to the result.
```
- **Line 25**: Adds the root's data to `ans` as it is part of the boundary.

### Example:
- If the root is `1`, `ans` becomes: `ans = [1]`.

```cpp
        traverseLeft(root -> left, ans);
```
- **Line 26**: Calls `traverseLeft` on the left child of the root to collect the left boundary.

```cpp
        traverseLeaf(root -> left, ans);
        traverseLeaf(root -> right, ans);
```
- **Lines 27-28**: Calls `traverseLeaf` on both left and right subtrees to collect all leaf nodes.

```cpp
        traverseRight(root -> right, ans);
```
- **Line 29**: Calls `traverseRight` on the right child of the root to collect the right boundary.

```cpp
        return ans;  // Return the final boundary traversal.
```
- **Line 30**: Returns the completed `ans` vector containing the boundary values.

## Step 4: Time and Space Complexity

### Time Complexity
- **Traversal Functions**:
  - Each of the three traversal functions (`traverseLeft`, `traverseLeaf`, `traverseRight`) will visit every node in the tree once.
  - Thus, the overall time complexity is **O(n)**, where `n` is the number of nodes in the tree.

### Space Complexity
- **Space Complexity**:
  - The space complexity is primarily due to the recursion stack used in the traversal functions. In the worst case (e.g., a skewed tree), the maximum depth of recursion can be `n`.
  - However, since we're using a vector to store the results, the overall space complexity is **O(h)** for the recursion stack and **O(n)** for storing the boundary nodes in the result vector, where `h` is the height of the tree.
  
In summary, the time complexity is **O(n)**, and the space complexity is **O(n)** due to the storage of boundary nodes and potential recursion depth. 

This comprehensive explanation should help you understand the problem, the approach taken, and how the provided code works in detail!
