<h1 align='center'>Is - Binary - Tree - Heap</h1>

## Problem Statement

**Problem URL :** [Is Binary Tree Heap](https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1)

![image](https://github.com/user-attachments/assets/3668356a-d7df-4771-b73d-82e73b927367)
![image](https://github.com/user-attachments/assets/cb8ed37e-18b4-47d8-b631-fa4779f88191)

## Problem Explanation
**Problem Statement**:  
The task is to determine if a given binary tree is a **max-heap**. A binary tree satisfies the properties of a max-heap if:
1. It is a **complete binary tree** (CBT): All levels are fully filled except possibly the last level, and nodes at the last level are as far left as possible.
2. It follows the **max-heap order property**: For each node, its value is greater than or equal to the values of its children.

**Examples**:

1. **Max-Heap Example**:
   ```
           10
         /    \
        9      8
       / \    / \
      7   6  5   4
   ```
   This tree is a max-heap since it is complete and each parent node’s value is greater than its children’s values.

2. **Not a Max-Heap Example**:
   ```
           10
         /    \
        9      15
       / \    / \
      7   6  5   4
   ```
   This tree is not a max-heap because node `15` is greater than its parent `10`, violating the max-heap property.

**Approach**:
1. **Check if the tree is complete** using `isCBT`.
   - Calculate the total number of nodes using `countNodes`.
   - Traverse the tree, ensuring each node is positioned as expected for a complete binary tree.
2. **Check if the tree satisfies the max-heap property** using `isMaxOrder`.
   - For each node, compare it with its left and right children (if they exist).
   - Ensure each parent node’s value is greater than its children's values.

## Problem Solution
```cpp
class Solution {
  public:
    int countNodes(struct Node* root){
        if(root == NULL) return 0;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    bool isCBT(struct Node* root, int index, int count){
        if(root == NULL) return true;
        
        if(index >= count) return false;
        
        else {
            bool left = isCBT(root -> left, 2 * index + 1, count);
            bool right = isCBT(root -> right, 2 * index + 2, count);
            
            return left && right;
        }
    }
    
    bool isMaxOrder(struct Node* root){
        if(root -> left == NULL && root -> right == NULL) return true;
        
        if(root -> right == NULL) return (root -> data > root -> left -> data);
        else {
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            
            return (left && right && 
            (root -> data > root -> left -> data && root -> data > root -> right -> data));
        }
    }
    bool isHeap(struct Node* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root, index, totalCount) && isMaxOrder(root)) return true;
        
        return false;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
public:
    int countNodes(struct Node* root){
        if(root == NULL) return 0;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
```
- **`countNodes` Function**: This function calculates the total number of nodes in the tree.
  - If `root` is `NULL`, it returns `0`, indicating no nodes.
  - Otherwise, it recursively counts nodes in the left and right subtrees, adding `1` for the current node.

```cpp
    bool isCBT(struct Node* root, int index, int count){
        if(root == NULL) return true;
        
        if(index >= count) return false;
        
        else {
            bool left = isCBT(root -> left, 2 * index + 1, count);
            bool right = isCBT(root -> right, 2 * index + 2, count);
            
            return left && right;
        }
    }
```
- **`isCBT` Function**: This function recursively checks if the binary tree is a complete binary tree (CBT).
  - If `root` is `NULL`, it returns `true`, as an empty tree is considered complete.
  - If `index >= count`, it returns `false` because this implies that the node’s position is invalid for a CBT.
  - Recursively checks left and right subtrees with updated indices (`2 * index + 1` for the left child and `2 * index + 2` for the right child).
  - Returns `true` if both left and right subtrees are complete.

```cpp
    bool isMaxOrder(struct Node* root){
        if(root -> left == NULL && root -> right == NULL) return true;
        
        if(root -> right == NULL) return (root -> data > root -> left -> data);
        else {
            bool left = isMaxOrder(root -> left);
            bool right = isMaxOrder(root -> right);
            
            return (left && right && 
            (root -> data > root -> left -> data && root -> data > root -> right -> data));
        }
    }
```
- **`isMaxOrder` Function**: This function checks if the tree satisfies the max-heap property.
  - If the node has no children (`left` and `right` are `NULL`), it returns `true`, as a leaf node satisfies the max-heap property.
  - If the node has only a left child, it checks that `root->data` is greater than `root->left->data`.
  - If the node has both children, it checks recursively that both left and right subtrees satisfy max-order and that `root->data` is greater than both child values.

```cpp
    bool isHeap(struct Node* root) {
        int index = 0;
        int totalCount = countNodes(root);
        
        if(isCBT(root, index, totalCount) && isMaxOrder(root)) return true;
        
        return false;
    }
};
```
- **`isHeap` Function**: This function combines the previous checks to determine if the tree is a max-heap.
  - Calls `countNodes` to get the total count of nodes.
  - Calls `isCBT` to check completeness and `isMaxOrder` to check the max-heap order.
  - Returns `true` if both checks are `true`.

### Step 3: Examples and Explanation

1. **Example 1**:
   - **Tree**:
     ```
             20
           /    \
         15      18
        /  \    /
       10   13  9
     ```
   - **Process**:
     - `countNodes` returns `6`.
     - `isCBT` confirms that the tree structure meets completeness.
     - `isMaxOrder` confirms that each parent node is greater than its children.
   - **Output**: **`true`** (The tree is a max-heap).

2. **Example 2**:
   - **Tree**:
     ```
             20
           /    \
         15      30
        /  \    /
       10   13  9
     ```
   - **Process**:
     - `countNodes` returns `6`.
     - `isCBT` confirms the tree is complete.
     - `isMaxOrder` identifies node `30` as greater than its parent `20`, violating the max-heap property.
   - **Output**: **`false`** (The tree is not a max-heap).

### Step 4: Time and Space Complexity

- **Time Complexity**:
  - `countNodes` traverses each node, so its time complexity is **O(N)**.
  - `isCBT` also traverses each node for the completeness check, with **O(N)** complexity.
  - `isMaxOrder` traverses each node to validate the max-heap property, with **O(N)** complexity.
  - Overall time complexity: **O(N)**.

- **Space Complexity**:
  - The recursion depth is proportional to the height of the tree.
  - In the worst case, the height of the tree could be `log N` (balanced tree) or `N` (skewed tree).
  - Overall space complexity: **O(H)**, where `H` is the height of the tree.

### Step 5: Additional Recommendations

- **Edge Cases**: Handle cases where the tree is empty or consists of only one node.
- **Alternative Approach**: Use level-order traversal to verify completeness and heap order simultaneously for efficiency. This approach could reduce the need for separate recursive checks.
- **Practice**: Manually trace through different tree examples to better understand heap properties and recursive checks.
