<h1 align='center'>Binary - Tree - From - In-Order & Post-Order</h1>

## Problem Statement

**Problem URL :** [Binary Tree From In-Order & Post-Order](https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/7a3b27b3-633f-4081-86b2-73824ce1b7a4)
![image](https://github.com/user-attachments/assets/fb98adbf-7f1b-4467-b573-5a07945bc4f4)

## Problem Explanation
Given the inorder and postorder traversals of a binary tree, the goal is to reconstruct the original binary tree. 

### Input
- **Inorder Traversal**: This traversal visits nodes in the left-root-right order.
- **Postorder Traversal**: This traversal visits nodes in the left-right-root order.

### Output
Return the root of the constructed binary tree.

### Example
For the following inorder and postorder traversals:
- **Inorder**: `[9, 3, 15, 20, 7]`
- **Postorder**: `[9, 15, 7, 20, 3]`

The corresponding binary tree can be represented as:
```
       3
      / \
     9   20
        /  \
       15   7
```

### Edge Cases
1. **Empty Trees**: If both traversals are empty, return `NULL`.
2. **Single Node**: If the tree has only one node, the traversals will contain that node only.

## Step 2: Approach

### High-Level Overview
To construct the tree, we can utilize the properties of the inorder and postorder traversals:
- The last element in postorder is always the root of the tree.
- Using the root, we can find the position in the inorder array to divide the left and right subtrees.

### Step-by-Step Breakdown
1. **Mapping Indices**: Create a mapping of values to their indices from the inorder traversal for quick look-up.
2. **Recursive Function**: Create a recursive function that:
   - Takes the current root value (from postorder).
   - Finds its position in inorder to determine left and right subtree elements.
   - Recursively constructs the right and left subtrees.

### Pseudocode
```plaintext
function buildTree(inorder, postorder):
    create a mapping of inorder indices
    call recursive function solve with initial parameters
    return the constructed tree

function solve(inorder, postorder, index):
    if index is less than 0 or bounds are invalid:
        return NULL
    create a new node with postorder[index]
    decrement index
    find position in inorder using the mapping
    recursively construct right subtree
    recursively construct left subtree
    return the constructed node
```

## Problem Solution
```cpp
class Solution {
  public:
    void createMapping(vector<int> &in, map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
        
    }
    
    Node* solve(vector<int>&in , vector<int> postorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        if(index < 0 || inOrderStart > inOrderEnd) return NULL;
        
        int element = postorder[index--];
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        
        root->right = solve(in, postorder, index, position + 1, inOrderEnd, n, nodeToIndex);
        root->left = solve(in, postorder, index, inOrderStart, position - 1, n, nodeToIndex);
        
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> &postorder) {
        int n = postorder.size();
        
        int postOrderIndex = n-1;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);
       
        return solve(inorder, postorder, postOrderIndex, 0, n-1, n, nodeToIndex);
    }
};
```

## Problem Solution Explanation
Certainly! Let’s delve deeper into the provided C++ source code for constructing a binary tree from its inorder and postorder traversals. We will explain each line in detail and provide examples where necessary.

```cpp
class Solution {
```
This line defines a class named `Solution`. In competitive programming and coding interviews, it’s common to encapsulate the solution to a problem within a class.

```cpp
public:
```
This keyword indicates that the following members (functions or variables) can be accessed from outside the class.

### Function: createMapping

```cpp
void createMapping(vector<int> &in, map<int, int> &nodeToIndex, int n){
```
This function creates a mapping of node values to their indices in the inorder traversal. 
- **Parameters**:
  - `vector<int> &in`: A reference to the vector containing the inorder traversal.
  - `map<int, int> &nodeToIndex`: A reference to a map that will store each node value and its corresponding index.
  - `int n`: The number of nodes (or size of the inorder array).

```cpp
    for(int i = 0; i < n; i++){
```
This initiates a loop that iterates through all elements in the inorder array.

```cpp
        nodeToIndex[in[i]] = i; // Map value to its index
```
Here, each value in the inorder array (`in[i]`) is mapped to its index (`i`) in the `nodeToIndex` map. This allows for quick lookups of the index of any node value during the tree construction process.

### Example for createMapping
For the inorder traversal `[9, 3, 15, 20, 7]`, the map after execution will look like:
```
{
    9: 0,
    3: 1,
    15: 2,
    20: 3,
    7: 4
}
```

### Function: solve

```cpp
Node* solve(vector<int>& in, vector<int> postorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
```
This is a recursive function that constructs the binary tree. 
- **Parameters**:
  - `vector<int>& in`: The inorder traversal vector.
  - `vector<int> postorder`: The postorder traversal vector.
  - `int &index`: A reference to the index of the current root in the postorder traversal (it will decrement as we process).
  - `int inOrderStart`: The starting index of the current subtree in the inorder traversal.
  - `int inOrderEnd`: The ending index of the current subtree in the inorder traversal.
  - `int n`: The number of nodes.
  - `map<int, int>& nodeToIndex`: The map created to find indices of inorder elements.

```cpp
    if(index < 0 || inOrderStart > inOrderEnd) return NULL; // Base case
```
This checks for two base cases:
- If the index is negative, it means we have processed all nodes in postorder.
- If the starting index of the inorder segment is greater than the ending index, it indicates that there are no nodes to process in this subtree.

If either condition is true, the function returns `NULL`, indicating no node can be created.

### Example for Base Case
- If `index = -1` or `inOrderStart > inOrderEnd`, the function returns `NULL`.

```cpp
    int element = postorder[index--]; // Get the current root from postorder
```
The current root is fetched from the `postorder` array using the `index`. After retrieving, the index is decremented to move to the next root for subsequent recursive calls.

### Example
For `postorder = [9, 15, 7, 20, 3]` and starting with `index = 4`, the first root fetched will be `3`, and the index will then become `3`.

```cpp
    Node* root = new Node(element); // Create a new node for this root
```
A new `Node` is created using the fetched root value. The constructor `Node(element)` initializes the node with the value.

```cpp
    int position = nodeToIndex[element]; // Find the position in inorder
```
This line finds the index of the current root in the `inorder` array using the previously created map. This index will help divide the inorder array into left and right subtrees.

### Example
Continuing from the previous example, `position` for `element = 3` will be `1`, indicating that `3` is at index `1` in the inorder traversal.

```cpp
    // Recursively construct right subtree first, then left subtree
    root->right = solve(in, postorder, index, position + 1, inOrderEnd, n, nodeToIndex);
```
This line recursively constructs the right subtree of the current root. The new parameters are:
- `inOrderStart` is now `position + 1` (to process elements after the current root).
- `inOrderEnd` remains unchanged, as it still indicates the end of the subtree.

### Example
For `element = 3`, `position + 1` will be `2`, so the right subtree is constructed from `inorder[2...4]`, which corresponds to `[15, 20, 7]`.

```cpp
    root->left = solve(in, postorder, index, inOrderStart, position - 1, n, nodeToIndex);
```
This line constructs the left subtree with:
- `inOrderStart` remains unchanged.
- `inOrderEnd` is now `position - 1` (to process elements before the current root).

### Example
Continuing from the example, for `element = 3`, `position - 1` will be `0`, so the left subtree is constructed from `inorder[0...0]`, which corresponds to `[9]`.

```cpp
    return root; // Return the constructed node
```
Finally, the function returns the newly created node, which can be used as the root for its subtrees in the previous recursive calls.

### Main Function: buildTree

```cpp
Node* buildTree(vector<int> inorder, vector<int> &postorder) {
```
This function serves as the main entry point to construct the tree from the provided traversals.
- **Parameters**:
  - `vector<int> inorder`: The inorder traversal array.
  - `vector<int> &postorder`: The postorder traversal array.

```cpp
    int n = postorder.size(); // Size of the postorder array
```
Calculates the number of nodes based on the size of the postorder array. The number of nodes is the same as the size of either traversal.

```cpp
    int postOrderIndex = n - 1; // Initialize index for postorder
```
Sets the initial index for postorder to the last element, which will be the first root processed.

```cpp
    map<int, int> nodeToIndex; // Map to store the index of inorder elements
```
Declares a map to store the indices of the inorder elements.

```cpp
    createMapping(inorder, nodeToIndex, n); // Create the mapping
```
Calls the `createMapping` function to fill the map with indices of the inorder elements.

```cpp
    return solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex); // Start solving
```
Finally, it calls the `solve` function to start the recursive process to build the tree, and returns the root node of the constructed tree.

## Example Walkthrough
Let’s put it all together with the example:

### Input
```plaintext
Inorder: [9, 3, 15, 20, 7]
Postorder: [9, 15, 7, 20, 3]
```

1. **Mapping Creation**:
   - After calling `createMapping`, the map will be:
     ```
     {
         9: 0,
         3: 1,
         15: 2,
         20: 3,
         7: 4
     }
     ```

2. **First Call to solve**:
   - `element = 3`, creates `Node(3)`, finds `position = 1`.
   - Calls to construct right subtree with `inorder[2...4]` (subarray: `[15, 20, 7]`).

3. **Second Call to solve** (right subtree of `3`):
   - `element = 20`, creates `Node(20)`, finds `position = 3`.
   - Calls to construct right subtree with `inorder[4...4]` (subarray: `[7]`).

4. **Third Call to solve** (right subtree of `20`):
   - `element = 7`, creates `Node(7)`, finds `position = 4`.
   - Base case reached for both left and right, returns `NULL`.

5. **Backtracking**:
   - Constructs left subtree of `20` (no nodes, returns `NULL`).
   - Returns to the root node `3`, constructs left subtree with `inorder[0...0]` (subarray: `[9]`).

6. **Fourth Call to solve** (left subtree of `3`):
   - `element = 9`, creates `Node(9)`, finds `position = 0`.
   - Base case reached for both left and right, returns `NULL`.

7.

 **Final Structure**:
   - The final binary tree structure will be:
   ```
       3
      / \
     9   20
        / \
       15  7
   ```


### Example 1
**Input**:
```plaintext
Inorder: [9, 3, 15, 20, 7]
Postorder: [9, 15, 7, 20, 3]
```
**Output**:
The constructed binary tree will have `3` as the root, `9` as the left child, and `20` as the right child, which further has `15` and `7` as its children.

### Example 2
**Input**:
```plaintext
Inorder: []
Postorder: []
```
**Output**:
Returns `NULL` as the tree is empty.

### Example 3
**Input**:
```plaintext
Inorder: [1]
Postorder: [1]
```
**Output**:
A single node tree with `1` as the root.

### Explanation of Outputs
The outputs validate that the function correctly reconstructs the binary tree from the given traversals.

## Step 5: Time and Space Complexity

### Time Complexity
- **Mapping Creation**: O(n) for creating the mapping from inorder traversal.
- **Tree Construction**: O(n) as we visit each node once during the recursive calls.
- **Total Time Complexity**: O(n), where n is the number of nodes.

### Space Complexity
- **Space for Mapping**: O(n) for storing the indices of inorder elements.
- **Recursion Stack**: O(h) for the call stack in case of recursion, where h is the height of the tree.
- **Total Space Complexity**: O(n) in the worst case for skewed trees, or O(h) in balanced cases.

### Optimizations
This approach is efficient and optimal for reconstructing the binary tree with the given traversals. Any further optimizations would typically involve reducing function call overhead or minimizing space usage, but the current method strikes a balance between clarity and efficiency.

## Additional Tips
- **Error Handling**: Always check for edge cases like empty inputs and handle them gracefully.
- **Testing**: Use various test cases to ensure robustness, especially with edge cases.

This breakdown provides a comprehensive understanding of the problem and solution, making it accessible for beginners to follow along and learn.
