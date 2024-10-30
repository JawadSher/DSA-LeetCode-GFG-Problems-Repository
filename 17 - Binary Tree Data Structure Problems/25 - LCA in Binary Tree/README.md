<h1 align='center'>LCA - in Binary - Tree</h1>

## Problem Statement

**Problem URL :** [LCA in Binary Tree](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/04f9127c-0588-4bdf-9d63-05e1be65c1d2)
![image](https://github.com/user-attachments/assets/b19c9a1f-a9d8-44c1-b17c-7ac13c16a1a6)
![image](https://github.com/user-attachments/assets/dbcf1e04-34fd-47f1-81eb-47afaf34a341)

## Problem Explanation

**Clarity and Conciseness:**
The problem is to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree. The LCA of two nodes \( n1 \) and \( n2 \) in a binary tree is defined as the deepest node that is an ancestor of both nodes. The function should return a pointer to the LCA node.

**Input:**
- A binary tree (represented by its root node).
- Two integers, \( n1 \) and \( n2 \), which are the values of the nodes for which we need to find the LCA.

**Output:**
- A pointer/reference to the node that is the LCA of the two given nodes.

**Constraints:**
- The tree may be empty (root can be NULL).
- The nodes may or may not be present in the tree.

**Real-world Analogy:**
Consider a family tree where each person is represented as a node. The LCA of two family members (e.g., siblings) is the closest ancestor (e.g., their parent). This concept helps in determining relationships within a hierarchy.

**Edge Cases:**
- Both nodes are the same (the LCA is the node itself).
- One or both nodes do not exist in the tree (the function should return NULL).
- The tree is empty (the function should return NULL).

### Step 2: Approach

**High-Level Overview:**
To find the LCA, we can use a recursive approach that traverses the binary tree. The idea is to traverse the tree starting from the root and explore left and right subtrees. We check if the current node is one of the nodes we are looking for and then combine the results of the left and right subtree searches.

**Step-by-Step Breakdown:**
1. **Base Case:** If the current node is NULL, return NULL.
2. **Check Current Node:** If the current node matches either \( n1 \) or \( n2 \), return the current node.
3. **Recursive Search:**
   - Recursively search for \( n1 \) and \( n2 \) in the left subtree.
   - Recursively search for \( n1 \) and \( n2 \) in the right subtree.
4. **Determine the LCA:**
   - If both left and right subtree calls return non-NULL, the current node is the LCA.
   - If only one of the calls returns a non-NULL value, return that value.
   - If both calls return NULL, return NULL.

**Visual Aids:**
```
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
```
For this tree, if \( n1 = 4 \) and \( n2 = 5 \), the LCA is \( 2 \).

**Pseudocode:**
```plaintext
function lca(root, n1, n2):
    if root is NULL:
        return NULL

    if root.data == n1 or root.data == n2:
        return root

    left = lca(root.left, n1, n2)
    right = lca(root.right, n1, n2)

    if left is not NULL and right is not NULL:
        return root
    if left is not NULL:
        return left
    if right is not NULL:
        return right

    return NULL
```

## Problem Solution
```cpp
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root == NULL) return NULL;
       
       if(root -> data == n1 || root -> data == n2) return root;
       
       Node* leftAns = lca(root -> left, n1, n2);
       Node* rightAns = lca(root -> right, n1, n2);
       
       if(leftAns != NULL && rightAns != NULL) return root;
       else if(leftAns != NULL && rightAns == NULL) return leftAns;
       else if(leftAns == NULL && rightAns != NULL) return rightAns;
       else return NULL;
    }
};
```

## Problem Solution Explanation

Here’s the given code with a line-by-line explanation:

```cpp
class Solution {
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root, int n1, int n2) {
```
- **Class Declaration:** A class named `Solution` containing the function `lca`.
- **Function Declaration:** The function `lca` takes three parameters: the root of the tree and two integers \( n1 \) and \( n2 \).

```cpp
       if(root == NULL) return NULL;
```
- **Base Case:** If the current node (root) is NULL, return NULL, indicating that the node is not found in this path.

```cpp
       if(root->data == n1 || root->data == n2) return root;
```
- **Check Current Node:** If the current node’s data matches either \( n1 \) or \( n2 \), return the current node as a potential LCA.

```cpp
       Node* leftAns = lca(root->left, n1, n2);
       Node* rightAns = lca(root->right, n1, n2);
```
- **Recursive Calls:** Recursively call `lca` for the left and right children of the current node, storing the results in `leftAns` and `rightAns`.

```cpp
       if(leftAns != NULL && rightAns != NULL) return root;
```
- **Determine LCA:** If both `leftAns` and `rightAns` are non-NULL, it means that \( n1 \) is found in one subtree and \( n2 \) in the other, so the current node is the LCA.

```cpp
       else if(leftAns != NULL && rightAns == NULL) return leftAns;
```
- If \( n1 \) or \( n2 \) is found only in the left subtree, return `leftAns`.

```cpp
       else if(leftAns == NULL && rightAns != NULL) return rightAns;
```
- If \( n1 \) or \( n2 \) is found only in the right subtree, return `rightAns`.

```cpp
       else return NULL;
    }
};
```
- If neither of the nodes is found, return NULL, indicating that both nodes are not present in this subtree.

### Step 4: Output Examples

Let’s consider some test cases with explanations:

**Example 1:**
```
Tree:
        1
       / \
      2   3
     / \
    4   5

Input: n1 = 4, n2 = 5
Output: 2
```
- **Explanation:** Nodes 4 and 5 are children of node 2, making 2 the LCA.

**Example 2:**
```
Tree:
        1
       / \
      2   3
     / \
    4   5

Input: n1 = 4, n2 = 3
Output: 1
```
- **Explanation:** Node 1 is the LCA because node 3 is in a different subtree than nodes 4.

**Example 3:**
```
Tree:
        1
       / \
      2   3
     / \
    4   5

Input: n1 = 6, n2 = 5
Output: NULL
```
- **Explanation:** Node 6 is not present in the tree, so the output is NULL.

### Step 5: Time and Space Complexity

**Time Complexity:**
- **O(N)**: In the worst case, we may have to visit every node in the tree to find \( n1 \) and \( n2 \). Therefore, the time complexity is linear in terms of the number of nodes \( N \).

**Space Complexity:**
- **O(H)**: The space complexity is determined by the height of the tree. In the worst case (for example, in a skewed tree), the height \( H \) could be equal to \( N \), giving a space complexity of O(N). In a balanced binary tree, the height \( H \) would be \( O(\log N) \).

**Detailed Analysis:**
- **Time Complexity Explanation:** Each recursive call processes one node. The total number of nodes in the tree is \( N \), leading to \( O(N) \) total time complexity.
  
- **Space Complexity Explanation:** The maximum depth of the recursive call stack will be equal to the height of the tree. Hence, in the case of a balanced tree, the space will be \( O(\log N) \) and in the case of a skewed tree, it will be \( O(N) \).

**Optimizations:**
- There is no significant optimization available for this problem since the algorithm must examine every relevant node. However, ensuring the tree is balanced can help optimize the space complexity in practice.

### Summary

The "LCA in Binary Tree" problem is a classic algorithm problem that can be solved with a straightforward recursive approach. Understanding the recursive nature and visualizing the tree structure are key to grasping how the solution works. This detailed breakdown provides a comprehensive understanding of the problem, solution approach, code functionality, and the complexity analysis involved.
