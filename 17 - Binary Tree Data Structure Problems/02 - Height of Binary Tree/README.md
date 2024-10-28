<h1 align='center'>Height - of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Height of Binary Tree](https://www.geeksforgeeks.org/problems/height-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/2f4f578e-dc5b-401e-bff9-cae214a3d8cf)
![image](https://github.com/user-attachments/assets/0404acf1-daa4-4bb2-8c79-e95b46fc2ea7)

## Problem Explanation

The problem, "Height of Binary Tree," is about determining how tall a binary tree is. The **height of a binary tree** is defined as the number of edges in the longest path from the root node (top of the tree) to a leaf node (a node with no children). 

If there are `N` levels in the tree, the height is `N`. In an empty tree (no nodes), the height is `0`.

### Examples

1. **Example 1**: A tree with multiple levels:
   
   ```
           1
          / \
         2   3
        / \
       4   5
   ```
   - Here, the longest path from the root (1) to the deepest leaf (either 4 or 5) has **two edges** (1 → 2 → 4 or 1 → 2 → 5).
   - So, the height of this tree is `3`.

2. **Example 2**: A single-node tree:
   
   ```
       1
   ```
   - With only one node, there’s no edge from the root to a leaf, so the height is `1`.

3. **Example 3**: An empty tree:
   - An empty tree has no nodes, so the height is `0`.

### Approach to Solving the Problem (Step-by-Step)

To solve this problem, let’s approach it logically:

1. **Understanding the Tree’s Structure**:
   - For each node in the tree, the height of the tree at that node is determined by the maximum height of its left and right subtrees plus one (for the node itself).

2. **Breaking Down the Problem**:
   - The height of an empty node (base case) is `0`.
   - For each node with children, we need to:
     - Recursively determine the height of its left subtree.
     - Recursively determine the height of its right subtree.
     - Use the maximum of these two heights and add `1` to count the current node's height.

3. **Using Recursion**:
   - We can solve this problem efficiently using recursion by visiting each node once and calculating the height of its subtrees.

4. **Steps to Think as a Beginner**:
   - Think of the root as the base node.
   - Calculate the height of each subtree starting from the root and working your way down to the leaf nodes.
   - At each node, the height is `1 + max(height of left subtree, height of right subtree)`.

## Problem Solution
```cpp
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // base case
        if(node == NULL) return 0;
        
        int left = height(node -> left);
        int right = height(node -> right);
        
        return max(left, right) + 1;
    }
};
```

## Problem Solution Explanation

1. **Base Case**:
   ```cpp
   if(node == NULL) return 0;
   ```
   - If the `node` is `NULL` (meaning it's an empty branch or an empty tree), the function returns `0` because there are no nodes to contribute to the height.

2. **Recursive Calls for Left and Right Subtrees**:
   ```cpp
   int left = height(node->left);
   int right = height(node->right);
   ```
   - The function recursively calls itself on `node->left` and `node->right` to calculate the height of each subtree. 
   - Each call goes deeper into the tree until it reaches a `NULL` node, at which point it returns `0` and unwinds the recursion.

3. **Calculating Height of Current Node**:
   ```cpp
   return max(left, right) + 1;
   ```
   - `max(left, right)` finds the height of the taller subtree.
   - Adding `1` accounts for the height of the current node itself.
   - This value is returned up the recursive call stack, building the height of each node layer by layer until reaching the root.

#### Example Walkthrough

For the tree:

```
       1
      / \
     2   3
    /
   4
```

1. Starting at the root (node 1), `height(node->left)` is calculated by moving to node 2.
2. For node 2, `height(node->left)` is calculated by moving to node 4.
3. Node 4 has no children, so `height(node->left)` and `height(node->right)` return `0`, making `height(4) = 1`.
4. Moving back to node 2, `height(node->right)` returns `0` because node 2 has no right child.
5. Now, `height(2) = max(1, 0) + 1 = 2`.
6. Moving back to the root (node 1), `height(node->right)` is calculated for node 3, which returns `1` since node 3 has no children.
7. Finally, `height(1) = max(2, 1) + 1 = 3`, which is the height of the entire tree.

### Time and Space Complexity

1. **Time Complexity**:
   - The time complexity is **O(N)**, where `N` is the number of nodes in the tree.
   - This is because the function visits each node exactly once to calculate its height.

2. **Space Complexity**:
   - The space complexity is **O(H)**, where `H` is the height of the tree.
   - This complexity comes from the recursion stack. In the worst case (for a skewed tree), the height could be `N`, so the space complexity would be `O(N)`.
   - For a balanced tree, the height would be closer to `log(N)`, making the space complexity `O(log(N))`.

This approach is efficient for finding the height of a binary tree because it calculates the height of each subtree once and only requires memory for the current path in the recursive stack.
