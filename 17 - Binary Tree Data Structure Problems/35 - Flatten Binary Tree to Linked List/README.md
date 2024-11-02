<h1 align='center'>Flatten - Binary - Tree - to - Linked - List</h1>

## Problem Statement

**Problem URL :** [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

![image](https://github.com/user-attachments/assets/e1dded1d-42ce-406f-905e-fa3e449d0195)
![image](https://github.com/user-attachments/assets/bacc21f4-ffef-49a1-9cc6-7ff61da5ced5)

## Problem Explanation

**Problem**: Given the root of a binary tree, the task is to flatten the tree into a linked list **in-place**. The flattened tree should follow the structure of a pre-order traversal, where each node's left child is null and the right child points to the next node in the traversal order.

**Constraints**:
1. Do not use extra space for a new data structure.
2. Transform the tree in-place without affecting the original node values.

**Example**:
Suppose we have the following binary tree:

```
    1
   / \
  2   5
 / \   \
3   4   6
```

The flattened linked list representation should look like this:

```
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

### Real-world Analogy
Imagine we have a series of rooms (nodes), where each room has one door (node connection) that leads to another room. Our task is to rearrange the rooms in such a way that there's only one straight hallway (linked list) connecting them all, while preserving their order as they would appear in a depth-first search of the original layout.

**Edge Cases**:
- An empty tree (`root = null`).
- A tree with only one node.
- A tree where every node has only a left child or only a right child.

---

### Step 2: Approach

#### High-Level Overview
To solve this problem, we use the **Morris Traversal** technique to modify the tree in-place. The basic idea is to find the rightmost node of the left subtree (the in-order predecessor) for each node and link it to the current node's right subtree. Then, we shift the left subtree to the right and continue to the next node.

#### Step-by-Step Breakdown

1. **Start at the Root Node**: Initialize a pointer `current` to traverse the tree starting from `root`.
2. **Process Each Node**:
   - If `current` has a left child, find its in-order predecessor in the left subtree:
     - Traverse to the rightmost node in `current`'s left subtree.
   - **Link the Right Subtree**: Link this rightmost node's right pointer to `current`'s right subtree.
   - **Move the Left Subtree**: Move the left subtree to the right and set `current`'s left pointer to null.
3. **Continue to the Right Subtree**: Move `current` to `current->right` and repeat until all nodes are visited.

#### Visual Aid
Here’s how the transformation works for each step in the above example:

```
Original Tree:
    1
   / \
  2   5
 / \   \
3   4   6

Step-by-Step Transformation:
1. Link 4's right to 5 (right subtree of 1), move 2 to the right of 1.
2. Link 3's right to 4 (right subtree of 2), move 3 to the right of 2.

Final Flattened Tree:
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

## Problem Solution
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;

        while(current != NULL){
            if(current -> left){
                TreeNode* pred = current -> left;

                while(pred -> right){
                    pred = pred -> right;
                }
                pred -> right = current -> right;
                current -> right = current -> left;
            }
            
            current -> left = NULL;
            current = current -> right;
        }
    }
};
```

## Problem Solution Explanation
Let's go through the source code for the "Flatten Binary Tree to Linked List" problem in detail, line by line, to understand how each part contributes to the solution.

```cpp
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

- **TreeNode Structure**: This defines a binary tree node. Each `TreeNode` has:
  - An integer `val` representing the value of the node.
  - Two pointers, `left` and `right`, pointing to the left and right children of the node.
  - Three constructors:
    - `TreeNode()` initializes a node with a default value `0` and both children as `nullptr`.
    - `TreeNode(int x)` initializes a node with value `x`, left child as `nullptr`, and right child as `nullptr`.
    - `TreeNode(int x, TreeNode *left, TreeNode *right)` initializes a node with value `x`, a left child as `left`, and a right child as `right`.

---

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;
```

- **Solution Class**: The `Solution` class contains the `flatten` method, which is the function that will modify the binary tree to flatten it into a linked list.
- **void flatten(TreeNode* root)**: This function takes a pointer to the root of a binary tree as input.
- `TreeNode* current = root;`: Initializes a pointer, `current`, to traverse the tree, starting at the root node.

---

```cpp
        while(current != nullptr) {
```

- **while(current != nullptr)**: This loop iterates over each node in the tree, moving along the flattened "linked list." The loop continues until `current` becomes `nullptr`, meaning all nodes have been processed.

---

```cpp
            if(current->left) {
                TreeNode* pred = current->left;
```

- **if(current->left)**: This checks if the current node has a left child. If it does, we need to re-arrange the left and right subtrees of `current` to continue the flattening process.
- **TreeNode* pred = current->left;**: `pred` is set to the left child of `current`. This pointer will be used to find the rightmost node in the left subtree of `current`, which will help in linking the left subtree correctly.

---

```cpp
                while(pred->right) {
                    pred = pred->right;
                }
```

- **while(pred->right)**: This inner loop traverses the right subtree of `pred` to find the rightmost node in `current`'s left subtree.
  - The reason we need the rightmost node is to link it to `current`'s right subtree later on, ensuring that all nodes are still accessible in the correct order.
- `pred = pred->right;`: This line moves `pred` one step to the right, iteratively finding the rightmost node in the left subtree of `current`.

---

```cpp
                pred->right = current->right;
```

- **pred->right = current->right;**: Once the rightmost node (`pred`) in the left subtree of `current` is found, its `right` pointer is linked to the right subtree of `current`.
  - This ensures that the original right subtree of `current` is preserved and attached to the end of `current`'s left subtree.

---

```cpp
                current->right = current->left;
                current->left = nullptr;
```

- **current->right = current->left;**: The left subtree of `current` is now assigned to the `right` of `current`, effectively moving it to the right side.
  - This is a crucial step as we want all left children to be removed in the final linked list, and the left subtree to be placed in the right position.
- **current->left = nullptr;**: This sets `current`'s left child to `nullptr`, flattening the current node's structure as per the requirement that each node should have only a right child in the flattened list.

---

```cpp
            }
            current = current->right;
        }
    }
};
```

- **current = current->right;**: Moves `current` to its right child. Since we’ve moved the entire left subtree to the right, this line ensures that `current` progresses along the "linked list" that’s being created.
- **End of While Loop**: The `while` loop ends when `current` becomes `nullptr`, indicating that all nodes have been processed and the tree is fully flattened.

---

### Summary of the Code's Functioning

1. For each node with a left child, we find the rightmost node of that left subtree.
2. We link this rightmost node's `right` pointer to the current node’s right subtree.
3. We move the left subtree to the right and set the left pointer to `nullptr`.
4. Finally, we advance to the next node in the newly structured list.

### Example Walkthrough

Consider this binary tree:

```
    1
   / \
  2   5
 / \   \
3   4   6
```

Step-by-step flattening process:

1. **Node 1**: Has a left child, `2`. Traverse the right subtree of `2` to find `4`. Set `4`'s right to `1`'s right subtree (`5`). Move `2` to the right of `1`, setting `1`'s left to `nullptr`.
   - Intermediate state:
   ```
   1
    \
     2
    / \
   3   4
        \
         5
          \
           6
   ```

2. **Node 2**: Has a left child, `3`. Since `3` has no right child, set `3`'s right to `2`'s right subtree (`4`). Move `3` to the right of `2`, setting `2`'s left to `nullptr`.
   - Intermediate state:
   ```
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
   ```

3. **Node 3, 4, 5**: Each of these nodes has no left child, so we simply move to the right each time.

4. **Final Flattened List**:
   ```
   1 -> 2 -> 3 -> 4 -> 5 -> 6
   ```

---

### Step 5: Time and Space Complexity

- **Time Complexity**: \( O(n) \), where \( n \) is the number of nodes in the tree. Each node is visited a fixed number of times.
  
- **Space Complexity**: \( O(1) \), since we’re transforming the tree in-place without using extra space for recursion or auxiliary data structures.
