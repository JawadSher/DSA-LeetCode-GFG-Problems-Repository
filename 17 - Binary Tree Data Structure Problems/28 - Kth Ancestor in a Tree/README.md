<h1 align='center'>Kth - Ansector - In a - Tree</h1>

## Problem Statement

**Problem URL :** [Kth Ancestor In a Tree](https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1)

![image](https://github.com/user-attachments/assets/bab26c0d-9294-459c-b0e3-2ddad82208ca)
![image](https://github.com/user-attachments/assets/87191a9a-897f-4855-a771-f042c5cdbcf3)
![image](https://github.com/user-attachments/assets/b4518b3a-ef0d-456f-801a-2f7c10aa5888)

## Problem Explanation
**Objective**: 
Given a binary tree, a node, and an integer `k`, find the kth ancestor of the given node. If the ancestor does not exist, return -1.

**Explanation**:
- The kth ancestor of a node is the node that is `k` levels above it in the binary tree.
- If `k = 1`, the output is the immediate parent.
- If `k = 2`, the output is the parent of the parent, and so on.
  
**Example**:
Consider the following tree:
```
        1
       / \
      2   3
     / \
    4   5
```
1. If `node = 5` and `k = 1`, the output is `2` (parent of 5).
2. If `node = 5` and `k = 2`, the output is `1` (grandparent of 5).
3. If `node = 4` and `k = 3`, the output is `-1` since the 3rd ancestor does not exist.

### Step 2: Approach

**Goal**:
We need to traverse the binary tree recursively to find the given node and then backtrack up `k` times to reach its ancestor.

**Steps**:
1. Traverse the tree using recursion.
2. When the target node is found, start counting upwards (i.e., decrease `k` at each ancestor level).
3. Once `k` reaches zero, the current ancestor is the kth ancestor.
4. If `k` becomes greater than the total levels above the node (no ancestor at `k` level), return `-1`.

**Key Insights**:
- Use recursion to traverse and backtrack up the tree.
- Maintain a count of steps (`k`) remaining to reach the desired ancestor.
  
## Problem Solution
```cpp
Node* solve(Node* root, int& k, int node){
    if(root == NULL) return NULL;
    
    if(root -> data == node) return root;
    
    Node* leftAns = solve(root -> left, k, node);
    Node* rightAns = solve(root -> right, k, node);
    
    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0) {
            k = INT_MAX;
            return root;
        }
        
        return rightAns;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ancestor = solve(root, k, node);
    if(ancestor == NULL || ancestor -> data == node) return -1;
    
    return ancestor->data;
}

```

## Problem Solution Explanation
Let's break down the provided source code for the "Kth Ancestor in a Tree" problem line by line, providing detailed explanations and examples where appropriate.

#### Function `solve(Node* root, int& k, int node)`

1. **`Node* solve(Node* root, int& k, int node)`**:
   - This function is a recursive helper function that aims to find the kth ancestor of a given node in a binary tree.
   - **Parameters**:
     - `Node* root`: Pointer to the current node being processed.
     - `int& k`: Reference to the integer `k`, which keeps track of how many levels we need to go up to find the ancestor.
     - `int node`: The value of the target node whose kth ancestor we want to find.

2. **`if (root == NULL) return NULL;`**:
   - This checks if the current node is NULL (i.e., we've reached the end of a branch in the tree).
   - If so, it returns NULL, indicating that we haven’t found the target node in this path.

3. **`if (root->data == node) return root;`**:
   - This checks if the current node's data matches the target node's data.
   - If it matches, it means we've found the target node, so we return the current node.

4. **`Node* leftAns = solve(root->left, k, node);`**:
   - This recursively calls the `solve()` function for the left child of the current node.
   - It stores the result (which could either be the target node or NULL) in the variable `leftAns`.

5. **`Node* rightAns = solve(root->right, k, node);`**:
   - Similar to the previous line, this recursively calls the `solve()` function for the right child of the current node and stores the result in `rightAns`.

#### Handling the Results from Left and Right Subtrees

6. **`if (leftAns != NULL && rightAns == NULL) {`**:
   - This checks if the target node was found in the left subtree (i.e., `leftAns` is not NULL) and not found in the right subtree (i.e., `rightAns` is NULL).
   - If this condition is true, it indicates that we need to move up one level in the tree.

7. **`k--;`**:
   - This decrements `k` because we are moving up one level in the tree, and we need to count how many levels we need to go up to find the kth ancestor.

8. **`if (k <= 0) {`**:
   - This checks if `k` has reached zero or below, which indicates that we have found the kth ancestor.
   - If this condition is true, we will reset `k` to avoid further ancestor checks and return the current node.

9. **`k = INT_MAX;`**:
   - This line sets `k` to a very high value (`INT_MAX`) so that subsequent calls do not mistakenly consider this node as a valid ancestor.
   - It's a flag indicating we found the kth ancestor.

10. **`return root;`**:
    - This returns the current node as it is the kth ancestor we are looking for.

11. **`return leftAns;`**:
    - If `k` is still greater than zero, it returns the result from the left subtree.

12. **`if (leftAns == NULL && rightAns != NULL) {`**:
    - This checks the opposite condition: whether the target node was found in the right subtree only.

13. **`k--;`**:
    - Similar to before, decrement `k` since we are moving up from the right child.

14. **`if (k <= 0) {`**:
    - This checks if `k` has reached zero, indicating we have found the kth ancestor from the right side.

15. **`k = INT_MAX;`**:
    - Again, we reset `k` to prevent further ancestor checks.

16. **`return root;`**:
    - Returns the current node as it is the kth ancestor.

17. **`return NULL;`**:
    - This line is reached when neither the left nor the right subtree contains the target node. It returns NULL to indicate that the node was not found.

### Function `kthAncestor(Node *root, int k, int node)`

18. **`int kthAncestor(Node *root, int k, int node) {`**:
    - This is the main function that users call to find the kth ancestor.
    - It initializes the search process.

19. **`Node* ancestor = solve(root, k, node);`**:
    - Calls the `solve()` function to find the ancestor. The result is stored in the `ancestor` variable.

20. **`if (ancestor == NULL || ancestor->data == node) return -1;`**:
    - This checks if no ancestor was found (i.e., `ancestor` is NULL) or if the found ancestor is actually the target node itself.
    - In either case, it returns `-1`, indicating that there is no valid kth ancestor.

21. **`return ancestor->data;`**:
    - Finally, if a valid ancestor is found, it returns the data of that ancestor.

### Example Walkthrough

Let's consider the tree structure for a clearer understanding:
```
        1
       / \
      2   3
     / \
    4   5
```

Assuming we want to find the 2nd ancestor of node `5`:
- We call `kthAncestor(root, 2, 5)`.
- The `solve` function starts at the root:
  - `root = 1`: Not equal to `5`, check left subtree.
  - `root = 2`: Not equal to `5`, check left subtree.
  - `root = 4`: Not equal to `5`, check left subtree (NULL).
  - Backtrack to `2`, now check right subtree:
  - `root = 5`: Found, return `5`.
- Backtrack to `2`:
  - `k` is decremented to `1` (moving up one level).
- Backtrack to `1`:
  - `k` is decremented to `0` (moving up another level).
- Return `1`, which is the 2nd ancestor of `5`.


Given the tree:
```
        1
       / \
      2   3
     / \
    4   5
```
1. `kthAncestor(root, 1, 5)`:
   - **Output**: `2` (Immediate parent).
2. `kthAncestor(root, 2, 5)`:
   - **Output**: `1` (Parent of parent).
3. `kthAncestor(root, 3, 5)`:
   - **Output**: `-1` (No ancestor exists at 3 levels).

### Step 5: Time and Space Complexity

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes. This is because in the worst case, we may need to traverse all nodes.
- **Space Complexity**: \(O(h)\), where \(h\) is the height of the tree. This is the space required for the recursive call stack in a binary tree of height \(h\).

This solution efficiently handles binary trees of varying structures while finding the kth ancestor for any given node within the tree.
