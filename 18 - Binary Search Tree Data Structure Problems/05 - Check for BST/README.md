<h1 align='center'>Check - for - BST</h1>

## Problem Statement

**Problem URL :** [Check for BST](https://www.geeksforgeeks.org/problems/check-for-bst/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/5c02ddba-5e1b-46cc-98da-9ce2d6b67715)
![image](https://github.com/user-attachments/assets/b260615a-24da-4cc4-820c-cce57f4c0e0a)

## Problem Explanation
The task is to determine if a given binary tree is a Binary Search Tree (BST). A binary tree is a BST if:
1. All nodes in the left subtree of a node have values less than the node's value.
2. All nodes in the right subtree of a node have values greater than the node's value.
3. Both the left and right subtrees of each node must also be binary search trees.

**Example**:
Let's go through some examples to understand the problem better:

1. **Valid BST**:
   ```plaintext
       4
      / \
     2   5
    / \
   1   3
   ```
   This tree is a valid BST because:
   - Node `2` is less than `4` and greater than `1`, which satisfies BST rules for `4`.
   - Similarly, `5` is greater than `4`, and all nodes follow the BST conditions.

2. **Invalid BST**:
   ```plaintext
       5
      / \
     1   4
        / \
       3   6
   ```
   This is not a valid BST because node `3` is in the right subtree of `5` but is less than `5`.

**Constraints**:
- Number of nodes in the binary tree can vary, which affects traversal and checks.
- All values are distinct, which simplifies checking.

**Edge Cases**:
1. An empty tree is considered a valid BST.
2. A single-node tree is a valid BST.
3. Trees with incorrect placements should return `false`.

---

### Step 2: Approach

To verify that a binary tree is a BST, we can perform an **in-order traversal**. In a BST, an in-order traversal produces values in strictly increasing order. Here’s the approach:

1. **In-Order Traversal with Validation**:
   - Perform an in-order traversal of the tree, visiting the left subtree, then the current node, and finally the right subtree.
   - Track the last visited node (using a `prev` pointer) and compare it with the current node. If any node’s value is less than or equal to the `prev` node’s value, the tree is not a BST.
2. **Base Case**:
   - If the node is `NULL`, return `true` since an empty tree or subtree is valid by definition.

## Problem Solution
```cpp
class Solution {
  public:
    bool isBST(Node* root, Node* & prev){
        if(root == NULL) return true;
        
        if(!isBST(root -> left, prev)) return false;
        
        if(prev != NULL && root -> data <= prev -> data) return false;
        
        prev = root;
        
        return isBST(root -> right, prev);
        
    }
    
    bool isBST(Node* root) {
        Node* prev = NULL;
        return isBST(root, prev);
    }
};

```

## Problem Solution Explanation
Let’s examine the code line by line.

```cpp
class Solution {
  public:
    bool isBST(Node* root, Node* &prev) {
```
- **Function**: `isBST`
- **Purpose**: Recursively checks if the tree rooted at `root` is a BST.
- **Parameters**:
  - `Node* root`: Current node in the tree.
  - `Node* &prev`: Reference to the previous node visited in in-order traversal. The reference allows us to update `prev` in recursive calls.

```cpp
        if(root == NULL) return true;
```
- **Base Case**: If `root` is `NULL`, the function returns `true`, indicating this subtree (or lack of one) is valid.

```cpp
        if(!isBST(root->left, prev)) return false;
```
- **Recursive Left Subtree Check**: Recursively check the left subtree. If it’s not a BST, return `false` immediately.

```cpp
        if(prev != NULL && root->data <= prev->data) return false;
```
- **BST Validation**: If `prev` is not `NULL`, check if `root->data` is greater than `prev->data`. If it’s not, the BST property is violated, and we return `false`.

```cpp
        prev = root;
```
- **Update `prev`**: Set `prev` to the current node after confirming the left subtree and the current node satisfy the BST properties.

```cpp
        return isBST(root->right, prev);
```
- **Recursive Right Subtree Check**: Continue checking the right subtree. Return the result of this recursive check.

```cpp
    }
    
    bool isBST(Node* root) {
        Node* prev = NULL;
        return isBST(root, prev);
    }
};
```
- **Wrapper Function**: `isBST` initializes `prev` as `NULL` and starts the recursion.

---

### Step 4: Output Examples

1. **Example 1**:
   ```plaintext
       2
      / \
     1   3
   ```
   **Input**: Root of the tree above.
   **Output**: `true`
   **Explanation**: The tree follows the BST property, with `1 < 2 < 3`.

2. **Example 2**:
   ```plaintext
       5
      / \
     1   4
        / \
       3   6
   ```
   **Input**: Root of the tree above.
   **Output**: `false`
   **Explanation**: The tree does not follow the BST property since `3` is less than `5` but is in the right subtree of `5`.

3. **Edge Case (Single Node)**:
   ```plaintext
       1
   ```
   **Input**: A single-node tree.
   **Output**: `true`
   **Explanation**: A single node tree is always a valid BST.

---

### Step 5: Time and Space Complexity

**Time Complexity**: \(O(n)\)
- Each node is visited once during the in-order traversal, making the time complexity \(O(n)\), where `n` is the number of nodes in the tree.

**Space Complexity**: \(O(h)\)
- The space complexity is determined by the height `h` of the tree, due to the recursive call stack. In the worst case (skewed tree), this can be \(O(n)\), and in the best case (balanced tree), it is \(O(\log n)\).

### Additional Tips

- **Edge Cases Handling**: Consider special cases like single-node trees and trees where all nodes have the same value.
- **Improvement**: To save space, an iterative approach could replace the recursion if memory usage is a concern in very deep trees.
