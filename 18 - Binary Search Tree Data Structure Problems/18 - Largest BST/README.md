<h1 align='center'>Largest - BST</h1>

## Problem Statement

**Problem URL :** [Largest BST](https://www.geeksforgeeks.org/problems/largest-bst/1)

![image](https://github.com/user-attachments/assets/314a27bd-bb32-41e2-9f21-9ad20d71c9cb)
![image](https://github.com/user-attachments/assets/fbb0650a-5d7c-46a8-be78-efc98144b6ea)

## Problem Explanation
The task is to find the size of the largest Binary Search Tree (BST) within a binary tree. 

- A **Binary Search Tree (BST)** is a binary tree where each node's value must be greater than all values in its left subtree and less than all values in its right subtree.
- The "size" of a tree (or subtree) is the number of nodes it contains.

Given a binary tree, we need to find the largest subset of nodes that form a BST.

#### Example for Better Understanding

Consider the following binary tree:

```
        10
       /  \
      5   15
     / \    \
    1   8   20
```

Here, the subtree rooted at node `5` (`5 -> 1, 8`) forms a BST with size `3`. Similarly, the subtree rooted at `15` (`15 -> 20`) is also a BST with size `2`. The largest BST here is the subtree rooted at `5`, so the expected output is `3`.



### Step 2: Approach to Solve the Problem

#### Understanding the Approach

The idea is to recursively traverse each node in the binary tree and check whether the subtree rooted at that node forms a BST. While doing so:
1. Track the minimum and maximum values in each subtree.
2. Check the validity of the BST by comparing the values with left and right subtrees.

For each node:
- If both the left and right subtrees are BSTs, and the current node's value is greater than the maximum value of the left subtree and less than the minimum value of the right subtree, then the subtree rooted at this node is a BST.
- If it forms a BST, we calculate its size by summing up the sizes of left and right subtrees and adding one for the current node.

#### Example of Approach

In the binary tree:

```
       10
      /   \
     5    15
    / \     \
   1   8    20
```

- For each node, recursively check if its left and right children form valid BSTs.
- Track the minimum and maximum values in each subtree to determine if the current subtree satisfies BST properties.
- For example, at node `5`, both children (`1` and `8`) satisfy the BST properties, so we calculate its size as `3`.

## Problem Solution
```cpp
class info {
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

class Solution {
public:
    info getLargestBSTInfo(Node* root, int &ans) {
        if (root == NULL) return info{INT_MAX, INT_MIN, true, 0};

        info left = getLargestBSTInfo(root->left, ans);
        info right = getLargestBSTInfo(root->right, ans);

        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);

        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;
        }

        if (currNode.isBST) ans = max(ans, currNode.size);

        return currNode;
    }

    int largestBst(Node* root) {
        int maxSize = 0;
        getLargestBSTInfo(root, maxSize);
        return maxSize;
    }
};

```

## Problem Solution Explanation

```cpp
class info {
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};
```

- **Purpose of `info` Class**: This helper class stores information about each node in the binary tree.
  - `mini` and `maxi` track the minimum and maximum values of the subtree rooted at each node.
  - `isBST` is a flag to determine if the subtree rooted at the node forms a BST.
  - `size` represents the number of nodes in the subtree.

```cpp
class Solution {
public:
    info getLargestBSTInfo(Node* root, int &ans) {
        if(root == NULL) return info{INT_MAX, INT_MIN, true, 0};
```

- **Base Case**: If `root` is `NULL`, return an `info` object for an empty subtree:
  - `mini = INT_MAX` and `maxi = INT_MIN` ensure that they don’t interfere with comparisons.
  - `isBST = true` because an empty tree is considered a BST.
  - `size = 0` as there are no nodes in an empty subtree.

```cpp
        info left = getLargestBSTInfo(root->left, ans);
        info right = getLargestBSTInfo(root->right, ans);
```

- **Recursive Calls**: We recursively call `getLargestBSTInfo` on the left and right children to gather information on each subtree.

```cpp
        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);
```

- **Current Node Calculation**:
  - `currNode.size` is the size of the subtree rooted at the current node, calculated by summing up the sizes of the left and right subtrees and adding one for the current node itself.
  - `currNode.maxi` and `currNode.mini` update the maximum and minimum values within the subtree.

```cpp
        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;
        }
```

- **BST Check**: We check if both left and right subtrees are BSTs and if the current node satisfies the BST property with its children. If true, `currNode.isBST` is set to true.

```cpp
        if (currNode.isBST) ans = max(ans, currNode.size);
```

- **Update Largest BST Size**: If `currNode` is a BST, we update the answer with the maximum size found so far.

```cpp
        return currNode;
    }
```

- **Return `currNode`**: Return the `info` object for the current node to be used in calculations up the recursive stack.

```cpp
    int largestBst(Node* root) {
        int maxSize = 0;
        getLargestBSTInfo(root, maxSize);
        return maxSize;
    }
};
```

- **Main Function (`largestBst`)**:
  - This function initializes `maxSize` to zero and calls `getLargestBSTInfo`.
  - Finally, it returns the largest BST size found.



### Step 4: Example Walkthrough

Let's apply this on our sample tree:

```
       10
      /   \
     5    15
    / \     \
   1   8    20
```

1. **Node `1`** and `8`: Both are leaf nodes and satisfy BST conditions.
2. **Node `5`**: Receives info from `1` and `8` (both BSTs), checks `5 > 1` and `5 < 8`, confirming it as a BST with size `3`.
3. **Node `15`** and `20`: Both satisfy BST conditions.
4. **Node `10`**: Combines info from `5` and `15`, confirms it as BST with size `6`.

Output: The largest BST has `size = 3` (rooted at `5`).


### Step 5: Time and Space Complexity

1. **Time Complexity**: `O(N)` where `N` is the number of nodes. Each node is visited once, gathering information on its subtrees.
2. **Space Complexity**: `O(H)`, where `H` is the height of the tree due to the recursion stack.


### Step 6: Recommendations

- **Practice Recursive BST Validation**: This problem reinforces understanding of how BST properties work.
- **Explore Edge Cases**: Test with trees that contain duplicate values, single nodes, and completely balanced trees to deepen understanding.

This step-by-step explanation should help you grasp the code flow and logic for finding the largest BST in a binary tree.
