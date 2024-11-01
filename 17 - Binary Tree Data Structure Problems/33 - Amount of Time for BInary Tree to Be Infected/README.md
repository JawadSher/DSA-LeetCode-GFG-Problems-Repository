<h1 align='center'>Amount - of Time - For Binary - To be - Infected</h1>

## Problem Statement

**Problem URL :** [Amount of Time for Binary To be Infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)

![image](https://github.com/user-attachments/assets/048159f7-4c71-4dd4-8310-1fa7aebdcaac)
![image](https://github.com/user-attachments/assets/803844ce-33f2-4fab-8172-94a168f1d3b9)

## Problem Explanation
The problem is titled **"Amount of Time for Binary Tree to be Infected"** on LeetCode. Given a binary tree where each node has a unique integer value, we select a `start` node, which becomes infected at time 0. The infection spreads to all directly connected nodes (left child, right child, and parent node) each minute. We need to determine the total time required for the entire tree to be infected.

### Constraints
- Nodes are only infected if connected to an already infected node.
- You are given the `start` node's value, which initiates the infection.
  
### Example
Imagine the binary tree:
```
        1
       / \
      2   3
     / \
    4   5
```
If we start at node `2`, the infection spreads like this:
1. **Minute 0**: Node 2 is infected.
2. **Minute 1**: Nodes 1 and 4 (connected to node 2) are infected.
3. **Minute 2**: Nodes 3 and 5 become infected.

The entire tree is infected in **2 minutes**.

### Edge Cases
- If the tree has only one node, it’s already infected at minute 0.
- If the `start` node is a leaf node, the infection needs more time to spread upward to the root and then to other branches.

## Step 2: Approach

### High-Level Overview
1. First, find the `start` node in the binary tree.
2. Track each node’s parent using a map for easy access to all adjacent nodes.
3. Perform a level-order traversal (BFS) from the `start` node to spread the infection. Keep track of infected nodes to avoid re-infecting nodes.

### Step-by-Step Breakdown
1. **Identify the Start Node**: Traverse the tree to find the `start` node and build a map that links each node to its parent.
2. **Infection Spread Simulation**: Using a BFS from the `start` node, simulate the infection spread minute-by-minute by visiting all uninfected neighboring nodes.
3. **Count the Time**: For each level in BFS, increment the time until no uninfected nodes remain.

### Pseudocode
1. Traverse the tree to find the start node and populate the parent map.
2. Initiate BFS from the start node, marking each visited node as infected.
3. For each level, count the minutes until all nodes are infected.
   
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
    TreeNode* startPoint(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &childParentMapping){
        TreeNode* result = NULL;
        queue<TreeNode*> q;
        q.push(root);

        childParentMapping[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front -> val == start){
                result = front;
            }

            if(front -> left){
                childParentMapping[front -> left] = front;
                q.push(front -> left);
            }

            if(front -> right){
                childParentMapping[front -> right] = front;
                q.push(front -> right);
            }
        }

        return result;
    }

    int t_infected_time(TreeNode* root, unordered_map<TreeNode*, TreeNode*> childParentMapping){
        int minutes = -1;

        unordered_map<TreeNode*, bool> infected;
        queue<TreeNode*> q;

        q.push(root);

        infected[root] = true;

        while(!q.empty()){
            int size = q.size();
            bool flag = true;

            for(int i = 0; i < size; i++){
                
                TreeNode* front = q.front();
                q.pop();

                if(front -> left && !infected[front -> left]){
                    flag = true;
                    q.push(front -> left);
                    infected[front -> left] = true;
                }
                
                if(front -> right && !infected[front -> right]){
                    flag = true;
                    q.push(front -> right);
                    infected[front -> right] = true;
                }

                if(childParentMapping[front] && !infected[childParentMapping[front]]){
                    flag = true;
                    q.push(childParentMapping[front]);
                    infected[childParentMapping[front]] = true;
                }
            }

            if(flag == true) minutes++;
        }

        return minutes;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> childParentMapping;
        TreeNode* startNode = startPoint(root, start, childParentMapping);
        return t_infected_time(startNode, childParentMapping);
    }
};
```

## Problem Solution Explanation

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
```

This part sets up the `TreeNode` structure, representing each node in the binary tree, with `val` holding the node's value, and `left` and `right` pointers representing child nodes. It defines three constructors:
1. **Default Constructor**: Creates a node with `val = 0`.
2. **Parameterized Constructor**: Creates a node with a given `val`.
3. **Complete Constructor**: Creates a node with a given `val`, `left`, and `right`.


### Function 1: `startPoint`

This function finds the `start` node in the tree and builds a map linking each child node to its parent for easy traversal.

```cpp
TreeNode* startPoint(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &childParentMapping) {
    TreeNode* result = NULL; // Holds the start node reference
    queue<TreeNode*> q;      // Queue for level-order traversal
    q.push(root);

    childParentMapping[root] = NULL; // Root has no parent

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        if (front->val == start) {   // Check if we found the start node
            result = front;
        }

        if (front->left) {           // Map left child to its parent
            childParentMapping[front->left] = front;
            q.push(front->left);
        }

        if (front->right) {          // Map right child to its parent
            childParentMapping[front->right] = front;
            q.push(front->right);
        }
    }

    return result; // Return the start node
}
```

#### Example 1: Basic Tree

Consider this tree and suppose `start = 2`:

```
        1
       / \
      2   3
     / \
    4   5
```

1. **Queue Initialization**: `q = [1]`
2. **Map Creation**: `childParentMapping = {1: NULL}`
3. **Node 1 Processing**:
   - Set `2`’s parent to `1`: `childParentMapping = {1: NULL, 2: 1}`
   - Set `3`’s parent to `1`: `childParentMapping = {1: NULL, 2: 1, 3: 1}`
   - `q = [2, 3]`
4. **Node 2 Processing**:
   - `start` node found, so `result = 2`
   - Set `4`’s parent to `2`: `childParentMapping = {1: NULL, 2: 1, 3: 1, 4: 2}`
   - Set `5`’s parent to `2`: `childParentMapping = {1: NULL, 2: 1, 3: 1, 4: 2, 5: 2}`
   - `q = [3, 4, 5]`
5. **Final Output**: `result = 2`

This completes the map of each node to its parent and identifies `2` as the starting node.


### Function 2: `t_infected_time`

This function calculates the total time required to infect the entire tree, starting from the given node. It uses a breadth-first search (BFS) to spread the infection level by level.

```cpp
int t_infected_time(TreeNode* root, unordered_map<TreeNode*, TreeNode*> childParentMapping) {
    int minutes = -1; // Infection time counter
    unordered_map<TreeNode*, bool> infected; // Track infected nodes
    queue<TreeNode*> q;

    q.push(root); // Start from the root node
    infected[root] = true;

    while (!q.empty()) {
        int size = q.size(); // Number of nodes in the current level
        bool flag = false;    // Track if new nodes are infected this minute

        for (int i = 0; i < size; i++) {
            TreeNode* front = q.front();
            q.pop();

            // Check left child
            if (front->left && !infected[front->left]) {
                flag = true;
                q.push(front->left);
                infected[front->left] = true;
            }
            
            // Check right child
            if (front->right && !infected[front->right]) {
                flag = true;
                q.push(front->right);
                infected[front->right] = true;
            }

            // Check parent
            if (childParentMapping[front] && !infected[childParentMapping[front]]) {
                flag = true;
                q.push(childParentMapping[front]);
                infected[childParentMapping[front]] = true;
            }
        }

        if (flag) minutes++; // Increment if any new infections occurred
    }

    return minutes;
}
```

#### Example 2: Infection Spread

Using the previous tree with `start = 2`, let’s see how the infection spreads:

1. **Minute 0**: Node `2` is infected (`q = [2]`)
2. **Minute 1**:
   - Infect nodes `1` and `4`: `q = [1, 4]`
3. **Minute 2**:
   - Infect nodes `3` and `5`: `q = [3, 5]`
4. **Result**: The tree is fully infected in **2 minutes**.

### Final Function: `amountOfTime`

This function ties everything together by calling `startPoint` to find the start node and `t_infected_time` to calculate the time to infect the tree.

```cpp
int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> childParentMapping;
    TreeNode* startNode = startPoint(root, start, childParentMapping);
    return t_infected_time(startNode, childParentMapping);
}
```

1. **Example**: For the tree above, `amountOfTime(root, 2)` returns `2` minutes.

### Step 4: Additional Examples

1. **Single Node Tree**: Tree with one node (start = 1).
   - **Input**: `root = [1]`, `start = 1`
   - **Output**: `0` minutes (tree is infected immediately).

2. **Skewed Tree** (like a linked list):
   ```
       1
        \
         2
          \
           3
            \
             4
   ```
   - **Input**: `root = [1, null, 2, null, 3, null, 4]`, `start = 1`
   - **Output**: `3` minutes (infection moves one node per minute down the chain).


### Step 5: Time and Space Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the tree. Each node is visited once during `startPoint` and `t_infected_time`.
- **Space Complexity**: \(O(n)\) for the parent map, infected map, and queue.
