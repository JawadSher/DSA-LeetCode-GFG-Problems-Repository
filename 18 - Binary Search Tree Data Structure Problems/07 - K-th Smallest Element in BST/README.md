<h1 align='center'>K-th - Smallest - Element - In BST</h1>

## Problem Statement

**Problem URL :** [K-th Smallest Element in BST](https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1)

![image](https://github.com/user-attachments/assets/77cc928d-585c-4040-b372-91091de8d497)
![image](https://github.com/user-attachments/assets/5f2aafbb-052e-4cf9-b44a-78b785f60f15)

## Problem Explanation
The task is to find the **Kth smallest element in a Binary Search Tree (BST)**. A BST has the property that for any node, the left subtree has nodes with values less than the node's value, and the right subtree has nodes with values greater than the node's value.

Given:
- A BST with `n` nodes.
- An integer `k`, where `1 ≤ k ≤ n`.

Goal:
- Return the value of the Kth smallest element in the BST.

#### Example

If the BST is:

```
      5
     / \
    3   7
   / \   \
  2   4   8
```

- **K = 3**: The 3rd smallest element is `4`.
- **K = 1**: The 1st smallest element is `2`.

#### Edge Cases

1. **Empty Tree**: If the BST has no nodes, the function should return `-1` (or handle the case gracefully).
2. **Invalid `k`**: If `k` is larger than the number of nodes in the BST, it’s an invalid input.
3. **Single Node Tree**: If the BST has only one node, the Kth smallest element is the value of that node if `k=1`.

### Step 2: Approach

**Morris Traversal** (also known as Threaded Binary Tree traversal) is an efficient method that allows **in-order traversal without using recursion or a stack**. It uses **O(1) additional space**.

1. **In-Order Traversal**: The smallest elements are visited in increasing order using in-order traversal in a BST.
2. **Count Nodes**: Count each node during the traversal, and when the count equals `k`, we've found our answer.

#### Steps of Morris Traversal

1. Start from the root node.
2. For each node:
   - If it has no left child, visit this node and move to the right child.
   - If it has a left child, find its **in-order predecessor** (the rightmost node in the left subtree).
   - If the right pointer of the predecessor is null, make the current node its right child temporarily, then move to the left child.
   - If the right pointer of the predecessor points to the current node, break this temporary link, visit the current node, and move to the right child.
3. Stop when we've found the Kth smallest element.
   
## Problem Solution
```cpp
class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        Node* current = root;
        int count = 0;
        int element = -1;
        
        while(current != NULL){
            if(current -> left == NULL){
                count++;
                if(count == k) element = current -> data;
                current = current -> right;
            }else{
                Node* predecessor = current -> left;
                while(predecessor -> right != NULL && predecessor -> right != current){
                    predecessor = predecessor -> right;
                }
                
                if(predecessor -> right == NULL){
                    predecessor -> right = current;
                    current = current -> left;
                }else{
                    predecessor -> right = NULL;
                    count++;
                    if(count == k) element = current -> data;
                    current = current -> right;
                }
            }
            if(element != -1) break;
        }
        
        
        return element;
    }
};
```

## Problem Solution Explanation

Here's a line-by-line explanation of the solution:

```cpp
class Solution {
public:
    // Function to return the Kth smallest element in a BST.
    int KthSmallestElement(Node *root, int k) {
```

- **Line 1-4**: We define a class `Solution` with a public method `KthSmallestElement` that takes a pointer to the root node of a BST and an integer `k` as inputs.
- **Purpose**: This function will return the Kth smallest element in the BST.
- **Input**:
  - `root`: Pointer to the root of the BST.
  - `k`: The position (1-indexed) of the smallest element we want to find.

---

```cpp
        Node* current = root;  // Start from the root node.
        int count = 0;         // To keep track of the visited nodes.
        int element = -1;      // To store the Kth smallest element.
```

- **Line 6-8**: We initialize three variables:
  - `current`: Starts at the root node and will be used to traverse the tree.
  - `count`: Keeps track of the number of nodes visited so far.
  - `element`: Stores the Kth smallest element once found; initialized to `-1` as a default value.

---

```cpp
        while(current != NULL) {
```

- **Line 10**: This `while` loop runs as long as `current` is not `NULL`, meaning there are still nodes to process in the BST.
- **Purpose**: This loop allows us to traverse all nodes in the BST using Morris Traversal.

---

```cpp
            if(current->left == NULL) {
```

- **Line 12**: We check if the current node has a left child.
  - **Case 1**: If `current->left` is `NULL`, it means there are no nodes smaller than `current` in the left subtree. So, we can visit `current` directly.

---

```cpp
                count++;  // Increment the count of visited nodes.
                if(count == k) element = current->data;  // Check if this is the Kth node.
                current = current->right;  // Move to the right child.
```

- **Line 13-15**: If `current->left` is `NULL`, we:
  - Increment `count` since we are "visiting" this node.
  - Check if `count` equals `k`. If it does, we have found the Kth smallest element, so we set `element = current->data`.
  - Move `current` to its right child, continuing the in-order traversal.

#### Example (for Case 1):
If the current node is `3` and `k = 2`, after visiting the first node (say `2`), `count` is incremented to `2`, which matches `k`. So, `element` is set to `3`.

---

```cpp
            } else {
```

- **Line 16**: If `current->left` is not `NULL`, then we need to find the in-order predecessor of `current`.
  - **Purpose**: The in-order predecessor will allow us to establish a temporary link back to `current` so that we can return to it after visiting the left subtree.

---

```cpp
                Node* predecessor = current->left;
                while(predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;  // Move to the rightmost node of the left subtree.
                }
```

- **Line 17-19**: We set `predecessor` to `current->left` (the left child of `current`) and look for the **rightmost node in the left subtree**.
  - **Why the rightmost node?**: The rightmost node is the last node visited in the left subtree in an in-order traversal. By establishing a link back to `current`, we can return to `current` after completing the left subtree traversal.

---

```cpp
                if(predecessor->right == NULL) {
                    predecessor->right = current;  // Make the current node the right child of its predecessor.
                    current = current->left;  // Move to the left child of the current node.
```

- **Line 21-23**: If `predecessor->right` is `NULL`, it means we haven't visited the left subtree yet:
  - **Step 1**: Set `predecessor->right = current`. This temporary link allows us to come back to `current` after visiting the left subtree.
  - **Step 2**: Move `current` to `current->left` to continue traversing the left subtree.

#### Example:
For a node `5` with a left child `3` and a right child `7`, the predecessor of `5` would be `4` (rightmost node in the left subtree). We make `4->right = 5`, allowing us to return to `5` after visiting nodes `2`, `3`, and `4`.

---

```cpp
                } else {
                    predecessor->right = NULL;  // Break the temporary link.
                    count++;  // Visit the current node.
                    if(count == k) element = current->data;  // Check if it's the Kth smallest element.
                    current = current->right;  // Move to the right child.
                }
```

- **Line 24-28**: If `predecessor->right == current`, it means we've finished visiting the left subtree, so:
  - **Step 1**: Set `predecessor->right = NULL` to break the temporary link.
  - **Step 2**: Increment `count` since we are "visiting" `current`.
  - **Step 3**: Check if `count == k`. If true, `element` is set to `current->data`, which is the Kth smallest element.
  - **Step 4**: Move `current` to `current->right`, completing the in-order traversal of `current`.

---

```cpp
            if(element != -1) break;
```

- **Line 29**: After finding the Kth smallest element (`element`), we exit the loop early.

---

```cpp
        return element;  // Return the Kth smallest element.
    }
};
```

- **Line 31**: Finally, return the `element` found, which is the Kth smallest in the BST. If `k` is larger than the number of nodes, `element` will remain `-1`, indicating an invalid input.

---

### Example Walkthrough

Consider this BST with `k = 3`:

```
      5
     / \
    3   7
   / \
  2   4
```

1. **Visit Node 5**:
   - `current = 5`, `predecessor = 4` (rightmost node of left subtree).
   - Set `4->right = 5`.
   - Move `current = 3`.

2. **Visit Node 3**:
   - `current = 3`, `predecessor = 2` (rightmost node of left subtree).
   - Set `2->right = 3`.
   - Move `current = 2`.

3. **Visit Node 2**:
   - `current = 2` (no left child).
   - `count = 1`, move `current = 3` (via temporary link).

4. **Return to Node 3**:
   - Break link `2->right`.
   - `count = 2`, move `current = 4`.

5. **Visit Node 4**:
   - `count = 3` (equals `k`), so `element = 4`.
   - Exit loop.

### Complexity Analysis

- **Time Complexity**: `O(N)` since we visit each node at most twice.
- **Space Complexity**: `O(1)` due to the in-place traversal without using a stack or recursion. 

### Additional Tips

- **Error Handling**: Ensure `k` is valid by adding boundary checks.
- **Efficiency**: Morris Traversal is optimal for this type of problem since it uses `O(1)` space and provides an in-order sequence of elements.
  
This solution ensures that we efficiently find the Kth smallest element while maintaining low space complexity by modifying the tree's pointers temporarily.
