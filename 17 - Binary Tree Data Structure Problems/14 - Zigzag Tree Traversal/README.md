<h1 align='center'>Zigzag - Tree - Traversal</h1>

## Problem Statement

**Problem URL :** [Zigzag Tree Traversal](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

![image](https://github.com/user-attachments/assets/e7eb6fa8-f966-45de-8903-b22ea30292f4)
![image](https://github.com/user-attachments/assets/10ea8b4e-a017-4bb0-8293-83a7c72e0a74)
![image](https://github.com/user-attachments/assets/b6d9fd65-df10-4569-af5d-15b7e5e3b9a8)

## Problem Explanation
In this problem, we are given a binary tree and asked to return its level-order traversal in a zigzag pattern. A zigzag pattern means:
- Traverse the first level from left to right.
- Traverse the second level from right to left.
- Continue alternating directions for each level.

#### Example:
Consider this binary tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
```

The expected zigzag level-order traversal is:
```
[
    [1],
    [3, 2],
    [4, 5, 6]
]
```

Here:
- Level 1: Traverse left-to-right → `[1]`
- Level 2: Traverse right-to-left → `[3, 2]`
- Level 3: Traverse left-to-right again → `[4, 5, 6]`

### Step 2: Approach
To solve this, we’ll use a **Breadth-First Search (BFS)** approach with a **queue** to process each level:
1. Start by adding the root node to the queue.
2. Process each level of the tree in the queue until all nodes are covered:
   - For each level, we store nodes in a `vector<int> ans` where `ans` holds the values of nodes in the current level.
   - For left-to-right order, add nodes directly in the order they appear in the queue.
   - For right-to-left order, add nodes in reverse order.
3. Alternate the direction (left-to-right or right-to-left) for each level by using a boolean flag `LTR` (Left to Right).
4. Append each `ans` vector to the `result` vector at the end of processing each level.

## Problem Solution
```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;    // Stores the final zigzag level order traversal.
        if(root == NULL) return result;  // If the root is NULL, return an empty result.

        queue<TreeNode*> q;             // Queue to hold nodes to be processed in BFS manner.
        q.push(root);                   // Start with the root node in the queue.

        bool LTR = true;                // Left-To-Right flag; toggles direction for each level.

        while(!q.empty()){
            int size = q.size();        // Number of nodes at the current level.
            vector<int> ans(size);      // Vector to store current level's node values.

            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();  // Take the front node from the queue.
                q.pop();                          // Remove it from the queue.

                // Determine the index based on the current traversal direction:
                int index = LTR ? i : size - i - 1;
                ans[index] = frontNode->val;      // Store node's value in ans at the calculated index.

                // Add child nodes to the queue for processing in the next level.
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right); 
            }

            LTR = !LTR;               // Toggle direction for the next level.
            result.push_back(ans);    // Add the current level's result to the final output.
        }

        return result;                // Return the zigzag level-order traversal.
    }
};
```

## Problem Solution Explanation
Here’s the code with an explanation:

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
```
- **Line 1-2**: Defines a class `Solution` with a public method `zigzagLevelOrder` that takes a pointer to the root of a binary tree (`TreeNode* root`) and returns a 2D vector of integers (`vector<vector<int>>`), which will hold the zigzag level order traversal of the tree.

```cpp
        vector<vector<int>> result;    // Stores the final zigzag level order traversal.
```
- **Line 3**: Initializes a 2D vector `result` to hold the final output of the zigzag traversal.

### Example:
- If the input tree is:
```
        1
       / \
      2   3
```
- Initially, `result` is empty: `result = []`.

```cpp
        if(root == NULL) return result;  // If the root is NULL, return an empty result.
```
- **Line 4**: Checks if the `root` is `NULL` (i.e., the tree is empty). If it is, the function immediately returns the empty `result`.

### Example:
- For an empty tree (`root = NULL`), the output is: `result = []`.

```cpp
        queue<TreeNode*> q;             // Queue to hold nodes to be processed in BFS manner.
        q.push(root);                   // Start with the root node in the queue.
```
- **Lines 5-6**: Initializes a queue `q` to hold `TreeNode` pointers. The root node is added to the queue for processing.

### Example:
- For the tree:
```
        1
       / \
      2   3
```
- After these lines, the queue will contain: `q = [1]`.

```cpp
        bool LTR = true;                // Left-To-Right flag; toggles direction for each level.
```
- **Line 7**: Initializes a boolean variable `LTR` to indicate the current traversal direction. It starts with `true`, meaning the first level will be traversed from left to right.

### Example:
- At the start, `LTR = true`.

```cpp
        while(!q.empty()){
```
- **Line 8**: Enters a loop that continues as long as there are nodes in the queue (`q` is not empty).

### Example:
- Initially, `q = [1]`, so we enter the loop.

```cpp
            int size = q.size();        // Number of nodes at the current level.
            vector<int> ans(size);      // Vector to store current level's node values.
```
- **Lines 9-10**: Calculates the number of nodes at the current level (`size`) and initializes a vector `ans` of that size to hold the values of nodes at the current level.

### Example:
- At the first iteration, `size = 1` (only node `1`), so `ans` is initialized as: `ans = [0]`.

```cpp
            for(int i = 0; i < size; i++){
```
- **Line 11**: Starts a loop that will iterate over each node at the current level.

### Example:
- For the first level with one node, `i` will take the value `0`.

```cpp
                TreeNode* frontNode = q.front();  // Take the front node from the queue.
                q.pop();                          // Remove it from the queue.
```
- **Lines 12-13**: Retrieves the front node from the queue (the one to be processed) and then removes it from the queue.

### Example:
- For the first iteration, `frontNode` is `1`, so after these lines, `q` will be empty: `q = []`.

```cpp
                // Determine the index based on the current traversal direction:
                int index = LTR ? i : size - i - 1;
```
- **Line 14**: Calculates the index where the node's value should be placed in the `ans` vector based on the traversal direction:
  - If `LTR` is `true`, use the current index `i`.
  - If `LTR` is `false`, calculate the index as `size - i - 1` (to fill in reverse order).

### Example:
- Since `LTR = true`, for the first iteration (`i = 0`), `index = 0`.

```cpp
                ans[index] = frontNode->val;      // Store node's value in ans at the calculated index.
```
- **Line 15**: Assigns the value of `frontNode` (the current node) to the `ans` vector at the calculated index.

### Example:
- After this line, `ans` is updated to: `ans = [1]`.

```cpp
                // Add child nodes to the queue for processing in the next level.
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right); 
```
- **Lines 16-18**: Checks if the current node has left or right children. If they exist, they are added to the queue for processing in the next level.

### Example:
- The current node (`1`) has children (`2` and `3`), so the queue will be updated to: `q = [2, 3]`.

```cpp
            LTR = !LTR;               // Toggle direction for the next level.
```
- **Line 19**: Toggles the value of `LTR`. If it was `true`, it becomes `false`, and vice versa. This ensures the next level will be processed in the opposite order.

### Example:
- After processing the first level, `LTR` is toggled to `false`.

```cpp
            result.push_back(ans);    // Add the current level's result to the final output.
```
- **Line 20**: Appends the current `ans` vector (which holds values for the current level) to the `result` vector.

### Example:
- After the first level, `result` is updated to: `result = [[1]]`.

```cpp
        return result;                // Return the zigzag level-order traversal.
```
- **Line 21**: After all levels have been processed, returns the `result` vector containing the zigzag level order traversal.

### Full Example Walkthrough:
Now let’s consider a complete example of the binary tree and see how the code works step by step:

Given the binary tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
```

1. **First Level**: `LTR = true`
   - Queue: `[1]`
   - Process node `1`: `ans = [1]`
   - Children added to queue: `[2, 3]`
   - Result after this level: `[[1]]`
   
2. **Second Level**: `LTR = false`
   - Queue: `[2, 3]`
   - Process node `2`: `ans = [0, 2]` (index `1`)
   - Process node `3`: `ans = [3, 2]` (index `0`)
   - Children added to queue: `[4, 5, 6]`
   - Result after this level: `[[1], [3, 2]]`
   
3. **Third Level**: `LTR = true`
   - Queue: `[4, 5, 6]`
   - Process node `4`: `ans = [4, 0, 0]` (index `0`)
   - Process node `5`: `ans = [4, 5, 0]` (index `1`)
   - Process node `6`: `ans = [4, 5, 6]` (index `2`)
   - Queue becomes empty after this level.
   - Result after this level: `[[1], [3, 2], [4, 5, 6]]`

Final output will be:
```cpp
[
    [1],
    [3, 2],
    [4, 5, 6]
]
```

### Time and Space Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the total number of nodes in the tree. Each node is processed once as we perform BFS traversal, visiting every level and node.
- **Space Complexity**: \(O(N)\) for storing the nodes in the queue and the result array. The queue at most holds nodes of one level, which could be up to \(N/2\) nodes for the last level in a full binary tree.

This solution is efficient for handling typical binary tree structures, even for larger trees, due to its linear complexity in both time and space.
