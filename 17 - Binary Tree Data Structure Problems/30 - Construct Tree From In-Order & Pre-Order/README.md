<h1 align='center'>Construct - Tree - From - In-Order & Pre-Order</h1>

## Problem Statement

**Problem URL :** [Construct Tree From In-Order & Pre-Order](https://www.geeksforgeeks.org/problems/construct-tree-1/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/81adc113-3a79-484c-a53d-fb1c3a7bebe0)
![image](https://github.com/user-attachments/assets/419a1887-cea2-47a4-b02f-cf7e2c3ba9b9)

## Problem Explanation
The problem is to construct a binary tree given two arrays:
1. `inorder[]`: The inorder traversal of the tree.
2. `preorder[]`: The preorder traversal of the tree.

### Example
Consider the following arrays:
- `inorder[] = {4, 2, 5, 1, 6, 3}`
- `preorder[] = {1, 2, 4, 5, 3, 6}`

**Output**: The constructed binary tree should look like this:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

### Constraints
- The size of the input arrays will be between 1 and \(10^4\).
- All values in the tree are unique.

### Edge Cases
- If the tree is empty, both `inorder` and `preorder` will be empty arrays.
- Trees with only one node should be handled properly.

## Step 2: Approach

### High-Level Overview
To reconstruct the tree, we can utilize the properties of the preorder and inorder traversals:
- In a preorder traversal, the first element is always the root of the tree.
- In an inorder traversal, the elements to the left of the root form the left subtree, and the elements to the right form the right subtree.

### Step-by-Step Breakdown
1. **Create a mapping** of each element in the inorder array to its index for quick lookup. This helps in identifying the left and right subtree boundaries quickly.
2. **Recursively build the tree**:
   - Start from the first element of the preorder array as the root.
   - Use the mapping to find the index of the root in the inorder array.
   - Recursively build the left and right subtrees using the boundaries derived from the inorder array.

### Pseudocode
```
function buildTree(inorder[], preorder[], n):
    createMapping(inorder[], nodeToIndex)
    return solve(preorder[], 0, n-1)

function solve(preorder[], index, inOrderStart, inOrderEnd):
    if index >= n or inOrderStart > inOrderEnd:
        return NULL
    element = preorder[index]
    root = new Node(element)
    position = nodeToIndex[element]
    root.left = solve(preorder[], index+1, inOrderStart, position-1)
    root.right = solve(preorder[], index+1, position+1, inOrderEnd)
    return root
```

## Problem Solution
```cpp
class Solution{
    public:
    
    void createMapping(int in[], map<int, int> &nodeToIndex, int n){
        for(int i = 0; i < n; i++){
            nodeToIndex[in[i]] = i;
        }
        
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex){
        if(index >= n || inOrderStart > inOrderEnd) return NULL;
        
        int element = pre[index++];
        Node* root = new Node(element);
        
        int position = nodeToIndex[element];
        
        root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
        root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
       int preOrderIndex = 0;
       map<int, int> nodeToIndex;
       createMapping(in, nodeToIndex, n);
       
       return solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
       
    }
};
```

## Problem Solution Explanation

Here's the code again for reference:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - Defines a class named `Solution` that contains methods to solve the problem.

2. **Mapping Creation**:
   ```cpp
   void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
   ```
   - This method creates a mapping of each value in the `inorder` array to its index.

3. **Filling the Map**:
   ```cpp
   for (int i = 0; i < n; i++) {
       nodeToIndex[in[i]] = i;
   }
   ```
   - Iterates through the `inorder` array and fills the `nodeToIndex` map with each element's value as the key and its index as the value.

4. **Recursive Solve Function**:
   ```cpp
   Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex) {
   ```
   - This method constructs the binary tree recursively.

5. **Base Case**:
   ```cpp
   if (index >= n || inOrderStart > inOrderEnd) return NULL;
   ```
   - Checks if the index has gone out of bounds or if the current subtree is invalid. If so, it returns `NULL`.

6. **Element Extraction**:
   ```cpp
   int element = pre[index++];
   Node* root = new Node(element);
   ```
   - Gets the current root element from the preorder array and creates a new `Node` for it. The index is incremented for the next recursive call.

7. **Finding Position in Inorder**:
   ```cpp
   int position = nodeToIndex[element];
   ```
   - Finds the index of the current root in the inorder array using the previously created mapping.

8. **Building Left Subtree**:
   ```cpp
   root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
   ```
   - Recursively calls `solve` to build the left subtree using the left part of the inorder array (from `inOrderStart` to `position - 1`).

9. **Building Right Subtree**:
   ```cpp
   root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
   ```
   - Recursively calls `solve` to build the right subtree using the right part of the inorder array (from `position + 1` to `inOrderEnd`).

10. **Returning the Root**:
    ```cpp
    return root;
    ```
    - Returns the constructed subtree rooted at the current `root`.

11. **Building the Tree**:
    ```cpp
    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        
        return solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    }
    ```
    - Initializes the `preOrderIndex` to `0`, creates the mapping using `createMapping`, and starts the recursive process to build the tree.

## Step 4: Output Examples

Let's consider the following input:

### Input
- `inorder[] = {4, 2, 5, 1, 6, 3}`
- `preorder[] = {1, 2, 4, 5, 3, 6}`

### Execution Steps
1. Call `buildTree` with the given `inorder` and `preorder`.
2. The mapping created will be:
   ```
   4 -> 0
   2 -> 1
   5 -> 2
   1 -> 3
   6 -> 4
   3 -> 5
   ```
3. The recursive calls will process as follows:
   - Root is `1`, left subtree: `2`, right subtree: `3`.
   - Further decomposing `2` gives us `4` and `5`.
   - Finally, `3` leads to `6`.

### Output
The constructed tree will be:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

## Step 5: Time and Space Complexity

### Time Complexity
- **Mapping Creation**: \(O(n)\), where \(n\) is the number of nodes, since we are iterating over the inorder array once.
- **Recursive Tree Construction**: Each node is processed once, leading to \(O(n)\).
- **Total Time Complexity**: \(O(n)\) for the entire operation.

### Space Complexity
- **Auxiliary Space**: The recursive call stack can go up to \(O(h)\), where \(h\) is the height of the tree. In the worst case (for a skewed tree), this can be \(O(n)\). The map for storing indices requires \(O(n)\).
- **Total Space Complexity**: \(O(n)\) in the worst case.

### Summary
The solution efficiently constructs a binary tree from given inorder and preorder traversals by leveraging the properties of these traversals and using a map for quick index lookups. The time complexity is linear, making this approach suitable for larger trees.

If you have any further questions or need additional clarification, feel free to ask!
