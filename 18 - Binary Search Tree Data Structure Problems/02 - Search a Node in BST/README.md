<h1 align='center'>Search - a Node - In - BST</h1>

## Problem Statement

**Problem URL :** [Search a Node in BST](https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/068515b7-703c-43c2-a473-0ba53b65adcb)
![image](https://github.com/user-attachments/assets/8906487f-deb7-4f18-b50b-698bd7938c2d)

## Problem Explanation
In this problem, you're given a Binary Search Tree (BST) and a target value. You need to determine whether this target value is present in the BST. 

A **BST** is a binary tree where each node follows these properties:
1. All values in the left subtree are smaller than the node's value.
2. All values in the right subtree are larger than the node's value.

#### Objective
If the target value exists in the BST, the function should return `true`; otherwise, it should return `false`.

#### Constraints
1. The tree may be empty.
2. Node values are unique.
3. Each node only contains integer values.

#### Example
Given the following BST:

```
       10
      /  \
     5    15
    / \     \
   2   7     20
```

- If the target value is `7`, the function should return `true` because `7` is present in the tree.
- If the target value is `12`, the function should return `false` because `12` is not present in the tree.

#### Real-world Analogy
Imagine the BST as a bookshelf organized by book titles in alphabetical order. If you want to find a particular book, you can quickly decide whether to search to the left (earlier titles) or right (later titles) without checking every book. Similarly, we can efficiently locate a value in a BST.

#### Edge Cases
1. **Empty Tree**: If the tree is empty, the target value can’t be found, so the function should return `false`.
2. **Single Node Tree**: If the tree has only one node, return `true` if the target matches the node’s value; otherwise, return `false`.
3. **Value Not in Tree**: The target value may not be present in the tree, so the function should handle this gracefully.

---

### Step 2: Approach

#### High-Level Overview
Since the tree is a **Binary Search Tree**, we can take advantage of its sorted property. Starting from the root:
1. If the current node's value matches the target, return `true`.
2. If the target is smaller than the current node’s value, recursively search the left subtree.
3. If the target is larger, recursively search the right subtree.

This approach is more efficient than a linear search because each step cuts down the possible nodes by half (similar to binary search).

#### Step-by-Step Breakdown
1. **Check the Root**: Start at the root node. If it’s `NULL`, return `false` (tree is empty).
2. **Compare with Root Value**:
   - If the root’s value is equal to the target, return `true`.
   - If the root’s value is less than the target, search in the right subtree.
   - If the root’s value is greater than the target, search in the left subtree.
3. **Recursively Search**: Continue until the target value is found or the subtree becomes `NULL`.


## Problem Solution
```cpp
bool present(Node* root, int value){
    if(root == NULL) return false;
    
    if(root -> data == value) return true;
    
    
    if(root -> data < value) return present(root -> right, value);
    else return present(root -> left, value);
    
    
    return false;
}
bool search(Node* root, int x) {
    return present(root, x);
}
```

## Problem Solution Explanation
Certainly! Let's go through each line of the source code in detail.

1. **Function Declaration: `present`**
   ```cpp
   bool present(Node* root, int value) {
   ```
   - This line declares a helper function `present` that takes two arguments:
     - `Node* root`: A pointer to the root node of the BST (or subtree).
     - `int value`: The integer value that we are searching for.
   - The function returns a boolean (`true` or `false`) indicating whether the target value exists in the tree.

2. **Check if the Node is `NULL`**
   ```cpp
   if(root == NULL) 
       return false;
   ```
   - This `if` statement checks if the `root` node is `NULL`. 
   - If it’s `NULL`, it means we have reached the end of a branch without finding the target value.
   - In this case, the function returns `false` to indicate that the value is not present in the tree.

3. **Check if the Node's Data Matches the Target Value**
   ```cpp
   if(root->data == value) 
       return true;
   ```
   - This line checks if the data in the current `root` node is equal to the `value` we’re searching for.
   - If they are equal, it means we have found the target value in the tree.
   - The function returns `true` to indicate that the target value is present.

4. **Decision to Search Right or Left Subtree**
   ```cpp
   if(root->data < value) 
       return present(root->right, value);
   else 
       return present(root->left, value);
   ```
   - **Condition `root->data < value`**:
     - This checks if the current node’s data is less than the target `value`.
     - Since this is a BST, if the current data is less than the target, we only need to search in the **right subtree** (as all larger values are on the right).
     - The function calls itself recursively on the right subtree (`root->right`), with the same target `value`.
     - `return present(root->right, value);` is a recursive call, meaning the function will continue searching down the right branch until it either finds the value or reaches a `NULL` node.
   
   - **`else` Condition**:
     - If the current node’s data is **greater than** the target `value`, we search in the **left subtree** (as all smaller values are on the left).
     - The function calls itself recursively on the left subtree (`root->left`) with the target `value`.
     - `return present(root->left, value);` continues the search down the left branch of the tree.

5. **Redundant `return false;` Line (Safeguard)**
   ```cpp
   return false;
   ```
   - This line is technically redundant because all possible cases (matching, left, and right subtree) have already been handled.
   - However, it's kept as a safeguard to ensure that the function has a return statement in all code paths, even though it won't be reached.

6. **Function Declaration: `search`**
   ```cpp
   bool search(Node* root, int x) {
   ```
   - This line declares the main function `search`, which serves as an entry point for the search functionality.
   - It takes two parameters:
     - `Node* root`: A pointer to the root node of the entire BST.
     - `int x`: The integer value to search for in the BST.
   - This function returns a boolean indicating whether the value `x` exists in the tree.

7. **Calling the Helper Function `present`**
   ```cpp
   return present(root, x);
   ```
   - This line calls the `present` function, passing it the root node and the target value `x`.
   - It simply returns whatever result `present` produces—either `true` (if the value is found) or `false` (if it isn’t).
   - This function is essentially a wrapper around the `present` function to keep the interface simple for calling code.

### Summary of Code Execution

- The `search` function is the main entry point. It calls `present`, which performs a recursive search through the BST.
- The `present` function uses the properties of the BST to quickly locate or discard branches, making the search efficient.
- If the target value is found at any node, the function immediately returns `true`.
- If the search reaches the end of a branch (`NULL`), it returns `false`, indicating the value isn’t in the tree.


### Example Output

Let’s add some example outputs to see the function in action:

1. **Example 1**:
   - **Input**: `search(root, 7)`
   - **Output**: `true`
   - **Explanation**: The value `7` is in the BST, so the function returns `true`.

2. **Example 2**:
   - **Input**: `search(root, 12)`
   - **Output**: `false`
   - **Explanation**: The value `12` is not in the BST, so the function returns `false`.

3. **Example 3**:
   - **Input**: `search(root, 10)`
   - **Output**: `true`
   - **Explanation**: The root node itself contains the value `10`, so the function returns `true` immediately.

This breakdown should help beginners understand how the recursive search works in a BST, along with the code structure and execution flow.

### Step 5: Time and Space Complexity

#### Time Complexity
- **Average Case**: \( O(\log N) \) because each recursive call halves the remaining nodes by choosing either the left or right subtree, similar to binary search.
- **Worst Case**: \( O(N) \), which happens when the tree is skewed (like a linked list).

### Summary
- The `search` function checks if a given value exists in a BST by leveraging its properties.
- The solution is efficient for balanced BSTs but can be slower for skewed trees.
- **Best Practices**: Always check if the tree is balanced or apply balancing techniques (like AVL or Red-Black Trees) for consistent \( O(\log N) \) performance.
