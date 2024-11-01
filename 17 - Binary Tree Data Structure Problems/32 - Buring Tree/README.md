<h1 align='center'>Burning - Tree</h1>

## Problem Statement

**Problem URL :** [Burning Tree](https://www.geeksforgeeks.org/problems/burning-tree/1)

![image](https://github.com/user-attachments/assets/e9886a6e-9b0e-4d7c-ab97-0ca74a512c63)
![image](https://github.com/user-attachments/assets/11c685b8-fcf4-4011-bfd6-583b7b509990)
![image](https://github.com/user-attachments/assets/5bd4cb7c-84a0-4c62-8ee0-5a2645a9e0e9)

## Problem Explanation
Let's go through each of the steps in detail to understand and explain the solution to the **Burning Tree** problem on GeeksforGeeks.

---

### Step 1: Problem Statement

**Problem Statement**:  
Given a binary tree and a target node, imagine starting a fire at the target node. Every minute, the fire spreads to adjacent nodes (left, right, and parent). We need to calculate the minimum time required for the entire tree to be burnt.

**Example**:  
Consider a binary tree:
```
       1
      / \
     2   3
    / \
   4   5
```
If we start the fire at node `2`, then:
- At time `1`, nodes `4` and `5` catch fire.
- At time `2`, nodes `1` and `3` catch fire.
- The entire tree is burnt at time `2`, so the answer is `2`.

**Edge Cases**:
1. If the tree has only one node, the time taken would be `0`.
2. If the target node is a leaf node, then the burn would spread to its parent only in the next time unit.
3. If the tree is unbalanced, the solution must account for nodes at different depths from the target.

---

### Step 2: Approach

**High-Level Overview**:  
To solve this problem, we’ll use two main steps:
1. **Identify the Parent of Each Node**: This will help in spreading the fire upwards towards the parent nodes.
2. **Simulate the Burning Process**: Using a breadth-first search (BFS), we can track how fire spreads level by level to adjacent nodes.

**Step-by-Step Breakdown**:
1. **Parent Mapping**:
   - Traverse the tree and create a mapping of each node to its parent.
   - While creating the parent map, locate the target node in the tree.

2. **Burn Simulation Using BFS**:
   - Initialize a queue with the target node and a `visited` set to track nodes that have already caught fire.
   - At each time unit (each BFS level), spread the fire to the node’s left, right, and parent (if they haven’t burned yet).
   - Count the time units until all nodes have burned.

**Pseudocode**:
```plaintext
Function createParentMapping(root, target):
    Initialize queue with root, nodeToParent map, result (target node)
    While queue is not empty:
        Pop node from queue
        If node data equals target, set it as result
        For each child of node:
            Set node as parent in nodeToParent map
            Push child to queue
    Return result (target node)

Function burnTree(root, nodeToParent):
    Initialize queue with root, visited set, ans as 0
    While queue is not empty:
        Flag to track if any new node catches fire
        For each node in queue:
            Spread fire to unvisited neighbors (left, right, parent)
            Set flag = true if new node catches fire
        If flag is true, increment ans
    Return ans
```

## Problem Solution
```cpp
class Solution {
  public:
    Node* createParentMapping(Node* root, int target, unordered_map<Node*, Node*>&nodeToParent){
        Node* result = NULL;
        queue<Node*> q;
        q.push(root);
        
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target) result = front;
            
            if(front -> left){
                nodeToParent[front -> left] = front;
                q.push(front -> left);
            }
            
            if(front -> right){
                nodeToParent[front -> right] = front;
                q.push(front -> right);
            }
        }
        
        return result;
    }
    
    int burnTree(Node* root, unordered_map<Node*, Node*> &nodeToParent){
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        int ans = 0;
        
        while(!q.empty()){
            bool flag = false;
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                Node* front = q.front();
                q.pop();
            
                if(front -> left && !visited[front->left]){
                    flag = true;
                    q.push(front -> left);
                    visited[front -> left] = true;
                }
                
                if(front -> right && !visited[front -> right]){
                    flag = true;
                    q.push(front -> right);
                    visited[front -> right] = true;
                }
                
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            
            if(flag == true) ans++;
            
        }
        
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        return burnTree(targetNode, nodeToParent);
    }
};
```

## Problem Solution Explanation
Let’s go through the code line-by-line, focusing on each function in detail with examples.

The solution consists of three main functions:

1. **`createParentMapping`** - Builds a map of each node to its parent and identifies the target node.
2. **`burnTree`** - Uses BFS to simulate the burning process from the target node.
3. **`minTime`** - Manages the process by calling both `createParentMapping` and `burnTree`.

Let’s go over each function in detail.

#### Function `createParentMapping`

```cpp
Node* createParentMapping(Node* root, int target, unordered_map<Node*, Node*>& nodeToParent) {
    Node* result = NULL;          // To store the target node once we find it
    queue<Node*> q;               // Queue for level-order traversal
    q.push(root);                 // Start traversal from the root
    nodeToParent[root] = NULL;    // Root has no parent, so set it to NULL
```

1. **Explanation**:
   - We start with `result` as `NULL`, which will eventually store our target node.
   - A `queue` is initialized to perform a level-order traversal of the tree.
   - We map the `root` node’s parent as `NULL` since it has no parent.

**Example**:
Suppose the tree is:
```
       1
      / \
     2   3
    / \
   4   5
```
After setting `nodeToParent[root] = NULL`, `nodeToParent` will look like:
```
nodeToParent = { 1: NULL }
```

```cpp
    while (!q.empty()) {          // While there are nodes to process
        Node* front = q.front();  // Get the front node in the queue
        q.pop();                  // Remove it from the queue
```

2. **Explanation**:
   - `front` is the current node we’re processing.
   - We remove `front` from the queue as we will now check its children.

```cpp
        if (front->data == target) result = front;   // Check if this is the target node
```

3. **Explanation**:
   - If `front` has the data equal to the target value, we store `front` in `result` as the target node.

```cpp
        if (front->left) {                         // If there is a left child
            nodeToParent[front->left] = front;     // Map it to its parent
            q.push(front->left);                   // Add left child to queue
        }

        if (front->right) {                        // If there is a right child
            nodeToParent[front->right] = front;    // Map it to its parent
            q.push(front->right);                  // Add right child to queue
        }
    }
```

4. **Explanation**:
   - For each child (left and right) of `front`, we:
     - Add it to `nodeToParent` with `front` as the parent.
     - Add the child to the queue for processing.

**Example Continued**:
Let’s assume the target node is `2`. The `nodeToParent` map will be built as:
```
nodeToParent = {
    1: NULL,
    2: 1,
    3: 1,
    4: 2,
    5: 2
}
```

```cpp
    return result;     // Return the target node
}
```

5. **Explanation**:
   - We return the `result`, which contains the target node.


#### Function `burnTree`

```cpp
int burnTree(Node* root, unordered_map<Node*, Node*>& nodeToParent) {
    unordered_map<Node*, bool> visited;     // Track which nodes have burned
    queue<Node*> q;                         // Queue for level-order burning process
    q.push(root);                           // Start burning from the target node
    visited[root] = true;                   // Mark the target node as visited
    int ans = 0;                            // Time counter for burning process
```

1. **Explanation**:
   - `visited` keeps track of nodes that are already burning.
   - `q` is initialized with the `root` (target node) to begin the burn.
   - `ans` keeps track of the total time needed.

```cpp
    while (!q.empty()) {
        bool flag = false;                 // Flag to check if any new nodes catch fire
        int size = q.size();               // Current level size in BFS
```

2. **Explanation**:
   - `flag` checks if any node catches fire in the current level of the BFS.
   - `size` is used to process each level one by one.

```cpp
        for (int i = 0; i < size; i++) {
            Node* front = q.front();       // Get the front node
            q.pop();                       // Remove it from the queue
```

3. **Explanation**:
   - We process each node at the current level (`size` times).

```cpp
            if (front->left && !visited[front->left]) {    // Check left child
                flag = true;                               // Mark that a new node caught fire
                q.push(front->left);                       // Add it to queue
                visited[front->left] = true;               // Mark as visited
            }
            
            if (front->right && !visited[front->right]) {  // Check right child
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            
            if (nodeToParent[front] && !visited[nodeToParent[front]]) {  // Check parent
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
```

4. **Explanation**:
   - We check each of `front`’s neighbors (left, right, and parent) and spread the fire to unvisited nodes.
   - If any new node catches fire, we set `flag = true`.

```cpp
        }
        
        if (flag) ans++;   // Increase time if any node caught fire in this level
    }
    
    return ans;            // Return the total time taken to burn the tree
}
```

5. **Explanation**:
   - If `flag` is true, increment `ans` because it indicates another minute has passed.
   - Return `ans` once all nodes have burned.

**Example Continued**:
With the tree example and target node `2`:
1. **Minute 0**: `q = [2]`
2. **Minute 1**: `q = [1, 4, 5]`
3. **Minute 2**: `q = [3]`
   - All nodes have burned, so `ans = 2`.

#### Function `minTime`

```cpp
int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);
    
    return burnTree(targetNode, nodeToParent);
}
```

- This function:
  1. Calls `createParentMapping` to get the `targetNode` and `nodeToParent` mapping.
  2. Calls `burnTree` to calculate the burn time.


### Output Examples

Example Tree:
```
       1
      / \
     2   3
    / \
   4   5
```

**Input**: Target node is `2`.  
**Output**: `2`  
**Explanation**:
1. **Time 0**: Start burning at `2`.
2. **Time 1**: Nodes `4`, `5`, and `1` catch fire.
3. **Time 2**: Node `3` catches fire. All nodes have burned.

### Step 5: Time and Space Complexity

- **Time Complexity**:
  - `createParentMapping`: \(O(N)\) where \(N\) is the number of nodes, as we perform a single traversal.
  - `burnTree`: \(O(N)\), as we again traverse each node once.
  - **Overall**: \(O(N)\).

- **Space Complexity**:
  - The space complexity is \(O(N)\) for the `nodeToParent` map and `visited` set.
  - **Overall**: \(O(N)\).
