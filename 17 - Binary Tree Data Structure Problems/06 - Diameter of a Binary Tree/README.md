<h1 align='center'>Diameter - Of a - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Diameter of A Binary Tree](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/2ed6db95-2b18-49a0-8786-ad4bacdd73f6)
![image](https://github.com/user-attachments/assets/b75dd0bb-d8be-4442-81c1-33060c995c22)

## Problem Explanation

In this problem, you need to find the **diameter** of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root node, and the diameter is calculated based on the **number of nodes** in this longest path, including both endpoints.

#### Examples:
1. **Example 1**:
   ```
       1
      / \
     2   3
    / \
   4   5
   ```
   - The longest path is from node `4` to node `5` through node `2`, with a total of `4` nodes in the path (`4 → 2 → 1 → 3`).
   - The diameter here is `4`.

2. **Example 2**:
   ```
           1
          /
         2
        /
       3
   ```
   - The longest path is from node `3` to node `1`, which contains three nodes.
   - The diameter here is `3`.

3. **Example 3**:
   - For an empty tree (`root == NULL`), the diameter is `0`.

### Step 2: Approach to Solve the Problem

#### Beginner-Friendly Thinking Process:

1. **Recursive Traversal to Calculate Path Lengths**:
   - This problem requires calculating both **diameters** and **heights** of subtrees for every node.
   - At each node, three potential path lengths (or diameters) can be considered:
     - The diameter of the left subtree.
     - The diameter of the right subtree.
     - The path that passes through the current node, calculated as the sum of the heights of the left and right subtrees plus one (for the current node itself).

2. **Combine Results**:
   - For each node, take the maximum of these three options and store this maximum as the diameter.
   - The height of the current subtree can be calculated as `1 + max(left height, right height)`.

3. **Return Results**:
   - Use a helper function `diameterFast` that returns a `pair<int, int>`, where:
     - `first` is the diameter for that subtree.
     - `second` is the height of that subtree.


## Problem Solution
```cpp
class Solution {
  public:
    pair<int, int> diameterFast(Node* root){
        // base case
        if(root == NULL){
            pair<int, int> p = make_pair(0, 0);
            return p;
        };
        
        pair<int, int> left = diameterFast(root -> left);
        pair<int, int> right = diameterFast(root -> right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
        
        return ans;
    }
    
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    pair<int, int> diameterFast(Node* root) {
        // base case
        if(root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        };
```
- **Explanation**: If `root` is `NULL`, we return `{0, 0}`, where `0` represents both the diameter and height. For an empty tree, the diameter is `0`.

```cpp
        pair<int, int> left = diameterFast(root -> left);
        pair<int, int> right = diameterFast(root -> right);
```
- **Explanation**: Recursively calculate the diameter and height for the left and right subtrees. Each subtree returns a `pair<int, int>`, where `first` is the diameter and `second` is the height.

```cpp
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
```
- **Explanation**:
   - `op1` is the diameter of the left subtree.
   - `op2` is the diameter of the right subtree.
   - `op3` is the path that goes through the current node, calculated as the height of the left subtree plus the height of the right subtree plus one.

```cpp
        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;
```
- **Explanation**:
   - `ans.first` stores the maximum diameter, calculated as the maximum among `op1`, `op2`, and `op3`.
   - `ans.second` stores the height of the subtree rooted at `root`, which is `1 + max(left.second, right.second)`.

```cpp
        return ans;
    }
```
- **Explanation**: The `diameterFast` function returns a `pair` containing the maximum diameter and height for the current subtree.

```cpp
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
```
- **Explanation**: `diameter(root).first` provides the diameter of the tree in terms of the number of nodes in the longest path. This is the final answer for the diameter of the binary tree.

### Step-by-Step Example Walkthrough

Consider the binary tree:

```
       1
      / \
     2   3
    / \
   4   5
```

1. **Recursive Calculations**:
   - At each node, we calculate the diameter and height of both left and right subtrees.
2. **Node 4 and Node 5**:
   - Both are leaf nodes, so the height is `1` and the diameter is `0`.
3. **Node 2**:
   - Left subtree (node `4`) has a height of `1`, diameter of `0`.
   - Right subtree (node `5`) has a height of `1`, diameter of `0`.
   - Diameter at node `2` is `max(0, 0, 1 + 1 + 1) = 3`.
   - Height at node `2` is `1 + max(1, 1) = 2`.
4. **Node 3**:
   - It has no children, so the height is `1` and the diameter is `0`.
5. **Node 1**:
   - Left subtree (node `2`) has a height of `2`, diameter of `3`.
   - Right subtree (node `3`) has a height of `1`, diameter of `0`.
   - Diameter at node `1` is `max(3, 0, 2 + 1 + 1) = 4`.
   - Height at node `1` is `1 + max(2, 1) = 3`.

The overall diameter of the tree is `4`, which is the output of `diameter(root)`.

### Step 4: Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the tree. Each node is visited once, making the time complexity linear with respect to the tree’s size.
2. **Space Complexity**: **O(H)**, where `H` is the height of the tree. This space is required for the recursive call stack. In the worst case (a skewed tree), it could be `N`, while in a balanced tree, it’s `log(N)`.
