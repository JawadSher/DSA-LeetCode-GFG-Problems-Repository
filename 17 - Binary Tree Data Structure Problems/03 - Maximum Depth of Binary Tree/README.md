<h1 align='center'>Maximum - Depth - Of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

![image](https://github.com/user-attachments/assets/ec2d38c2-56bd-4eaa-9c14-1f06189609b6)

## Problem Explanation
The problem is to find the maximum depth, or height, of a binary tree. In a binary tree, the depth is the length of the longest path from the root node to any leaf node.

The depth of the tree is:
- **0** for an empty tree.
- **1** for a tree with only the root node.
- **Increased by one** for each additional level from root to the furthest leaf node.

#### Examples:
1. **Example 1**:
   ```
           1
          / \
         2   3
        /
       4
   ```
   - The maximum depth is `3`, as the longest path (1 → 2 → 4) has three edges.

2. **Example 2**:
   ```
       1
   ```
   - This tree has only the root, so the depth is `1`.

3. **Example 3**: An empty tree
   - If the tree is empty (`root == NULL`), the depth is `0`.

### Step 2: Approach to Solve the Problem

#### Think Like a Beginner:

1. **Using Level-by-Level Traversal (Breadth-First Search - BFS)**:
   - We can determine the tree’s depth by traversing it level-by-level.
   - At each level, count the number of nodes and increase the depth by `1`.
   - Use a queue to keep track of nodes level-by-level.
   
2. **Tracking Each Level**:
   - Start with the root node.
   - For each level, count how many nodes there are. This count tells us how many nodes to process at the current depth.
   - As each node’s children are added to the queue, they become part of the next level.

3. **Termination**:
   - When all nodes are processed, the total depth will represent the maximum depth.


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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int levelSize = q.size();
            depth++;

            for(int i = 0; i < levelSize; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }

        return depth;
    }
};
```

## Problem Solution Explanation
Here’s how the code finds the maximum depth:

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
```
- **Explanation**: This code checks if the root is `NULL`. If so, it means the tree is empty, and the function immediately returns `0` (depth is zero).

```cpp
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
```
- **Explanation**: We create a queue `q` to keep track of nodes as we process each level. The root node is added first, and `depth` is initialized to `0`.

```cpp
        while(!q.empty()) {
            int levelSize = q.size();
            depth++;
```
- **Explanation**: As long as the queue isn’t empty, we’re still processing levels. Each level starts by getting the `levelSize`, which represents the number of nodes in the current level. `depth` is incremented each time we start a new level.

```cpp
            for(int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
```
- **Explanation**: The `for` loop goes through all nodes at the current level (`levelSize` times). `temp` points to each node in the queue, one by one, and removes it from the queue.

```cpp
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
```
- **Explanation**: For each node, if there’s a left child, it’s added to the queue; similarly, if there’s a right child, it’s added to the queue. This process adds nodes of the next level to the queue, so they’re ready for processing in the next iteration of the `while` loop.

```cpp
        return depth;
    }
};
```
- **Explanation**: When the queue is empty, all levels have been processed. `depth` now holds the maximum depth of the binary tree, and it’s returned as the result.

### Example Walkthrough

For the tree:

```
       1
      / \
     2   3
    /
   4
```

1. **Initial Queue**: `[1]`
   - Depth = 0

2. **First Level**: `[1]` → Depth = 1
   - `1` is removed, `2` and `3` are added to the queue: `[2, 3]`

3. **Second Level**: `[2, 3]` → Depth = 2
   - `2` is removed, `4` is added; `3` is removed (no children)
   - Queue after this level: `[4]`

4. **Third Level**: `[4]` → Depth = 3
   - `4` is removed (no children), queue is empty.

The final depth is `3`, so the maximum depth is `3`.

### Time and Space Complexity

1. **Time Complexity**: **O(N)**, where `N` is the number of nodes in the tree, because each node is processed once.
2. **Space Complexity**: **O(N)** for the queue in the worst case, if the last level has `N/2` nodes.
