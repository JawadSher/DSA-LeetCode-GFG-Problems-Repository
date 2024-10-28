<h1 align='center'>Balanced - Tree - Check</h1>

## Problem Statement

**Problem URL :** [Balanced Tree Check](https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1)

![image](https://github.com/user-attachments/assets/e405cd3c-3239-49c9-bedf-0a9a27ab4c09)
![image](https://github.com/user-attachments/assets/a300c19b-d130-463e-b378-11548b9a0247)

## Problem Explanation

In this problem, we are tasked with checking whether a given binary tree is **balanced**. A binary tree is considered balanced if, for every node, the height difference between its left and right subtrees is at most 1. If any node in the tree violates this condition, the tree is unbalanced.

#### Examples:

1. **Example 1**:
   ```
         1
        / \
       2   3
      / 
     4   
   ```
   - **Explanation**: This tree is **balanced**. The left subtree has height 2 (from node 1 to node 4), and the right subtree has height 1. The height difference is 1.

2. **Example 2**:
   ```
         1
        /
       2
      /
     3
   ```
   - **Explanation**: This tree is **not balanced** because the left subtree has height 2 and the right subtree is empty (height 0). The height difference is 2.

3. **Example 3**:
   - An empty tree (`root == NULL`) is considered **balanced**.

### Step 2: Approach to Solve the Problem

To determine if a binary tree is balanced, we can use a recursive approach:

1. **Recursive Height Calculation**:
   - Create a helper function to compute the height of the tree while also checking the balance condition.
   - If at any point the balance condition is violated (the height difference is greater than 1), return a sentinel value (like `-1`) to indicate the tree is unbalanced.

2. **Combine Height and Balance Check**:
   - For each node, calculate the heights of the left and right subtrees.
   - If both subtrees are balanced, return their maximum height plus one.
   - If not balanced, return `-1`.

## Problem Solution
```cpp
class Solution{
    public:
    int heights(Node* root){
        if(root == NULL) return 0;
        
        int left = heights(root -> left);
        if(left == -1) return -1;
        
        int right = heights(root -> right);
        if(right == -1) return -1;
        
        if(abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
    bool isBalanced(Node *root)
    {
        return heights(root) != -1;

    }
};
```

## Problem Solution Explanation

Here’s the code with detailed explanations:

```cpp
class Solution{
public:
    int heights(Node* root){
        if(root == NULL) return 0;
```
- **Explanation**: The base case checks if the current node is `NULL`. If it is, return `0`, indicating the height of an empty subtree.

```cpp
        int left = heights(root -> left);
        if(left == -1) return -1;
```
- **Explanation**:
   - Recursively calculate the height of the left subtree. 
   - If the left subtree is unbalanced (i.e., returns `-1`), return `-1` immediately.

```cpp
        int right = heights(root -> right);
        if(right == -1) return -1;
```
- **Explanation**:
   - Calculate the height of the right subtree. 
   - If the right subtree is unbalanced (i.e., returns `-1`), return `-1` immediately.
     
```cpp
        if(abs(left - right) > 1) return -1;
```
- **Explanation**:
   - Check if the absolute difference between the heights of the left and right subtrees is greater than `1`. If so, return `-1`, indicating that the tree is unbalanced.

```cpp
        return max(left, right) + 1;
    }
```
- **Explanation**:
   - If the current node is balanced, return the height of the subtree, which is `1 + max(left, right)`.

```cpp
    bool isBalanced(Node *root)
    {
        return heights(root) != -1;
    }
};
```
- **Explanation**:
   - The `isBalanced` function calls the `heights` helper function and checks if it returns `-1`. If not, the tree is balanced; otherwise, it is unbalanced.

### Step-by-Step Example Walkthrough

Consider the tree:

```
        1
       / \
      2   3
     /
    4
```

1. **Node 4**:
   - Left and right children are `NULL`, so their heights are `0`.
   - Returns `height(4) = 1`.
  
2. **Node 2**:
   - Left subtree height = `1` (from node `4`).
   - Right subtree height = `0` (no right child).
   - Height difference is `1`, so it returns `height(2) = 2`.

3. **Node 3**:
   - Left and right children are `NULL`, so height = `1`.

4. **Node 1**:
   - Left subtree height = `2` (from node `2`).
   - Right subtree height = `1` (from node `3`).
   - Height difference is `1`, so it returns `height(1) = 3`.

The function returns `true`, indicating the tree is balanced.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the tree.
   - Each node is visited once to calculate the height, ensuring efficiency.

2. **Space Complexity**: **O(H)**, where `H` is the height of the tree.
   - The space complexity is determined by the maximum height of the recursion stack. In the worst case (skewed tree), it could be `O(N)`, while for a balanced tree, it is `O(log N)`. 
