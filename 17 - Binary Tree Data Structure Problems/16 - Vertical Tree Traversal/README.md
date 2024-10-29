<h1 align='center'>Vertical - Tree - Traversal</h1>

## Problem Statement

**Problem URL :** [Vertical Tree Traversal](https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1)

![image](https://github.com/user-attachments/assets/61935ab0-184f-4ce2-baee-d0764d92f9c0)
![image](https://github.com/user-attachments/assets/59fda5a8-255f-476a-92c5-5b60c7875150)
![image](https://github.com/user-attachments/assets/b8d34a2b-acf8-4e77-b8c9-fcc98233457f)


## Problem Explanation

The objective of vertical tree traversal is to print the nodes of a binary tree in vertical order. In this traversal:
- Nodes are printed vertically, from top to bottom.
- Nodes that are on the same vertical line are printed together.
- The vertical lines are defined based on the horizontal distance from the root node.

### Vertical Line Definition
- Assign a horizontal distance (HD) to each node:
  - The HD of the root node is `0`.
  - For the left child, HD is `HD of parent - 1`.
  - For the right child, HD is `HD of parent + 1`.

### Example
Consider the following binary tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
       /
      7
```

**Vertical Order Output**:
- Vertical lines:
  - HD -2: `4`
  - HD -1: `2`
  - HD 0: `1, 5, 7`
  - HD 1: `3`
  - HD 2: `6`

So the output will be:
```
4
2
1
5
7
3
6
```

## Step 2: Approach

### Approach Explanation
1. **Mapping HD**: Use a data structure (like a map) to map each HD to a list of nodes that fall under that HD.
2. **Traversal**: Perform a level-order traversal (BFS or DFS) of the tree, updating the HD for each node:
   - For each node, add its value to the list corresponding to its HD in the map.
   - Recursively traverse the left child with `HD - 1` and the right child with `HD + 1`.
3. **Output**: After collecting nodes in the map, output them in order of HD, from the smallest to the largest.

### Beginner-Friendly Steps
1. Initialize a map to store nodes against their HDs.
2. Start from the root node, initializing its HD to `0`.
3. For each node, add its value to the corresponding list in the map.
4. Traverse left and right children, adjusting the HD accordingly.
5. Finally, iterate through the sorted keys of the map to print the node values.
   
## Problem Solution
```cpp
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int, vector<int> >> nodes;
        queue<pair<Node*, pair<int, int> >> q;
        
        vector<int> ans;
        if(root == NULL) return ans;
        
        q.push(make_pair(root, make_pair(0, 0)));
        
        while(!q.empty()){
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode -> data);
            
            if(frontNode -> left)
                q.push(make_pair(frontNode -> left, make_pair(hd -1 , lvl + 1)));
                
            if(frontNode -> right)
                q.push(make_pair(frontNode -> right, make_pair(hd + 1, lvl + 1)));
        }
        
        for(auto i : nodes){
            for(auto j : i.second){
                for(auto k : j.second){
                    ans.push_back(k);
                }
            }
        }
        
        
        return ans;
    }
};
```

## Problem Solution Explanation

Let's break down the provided source code for the vertical order traversal of a binary tree. This code uses a combination of a queue for level-order traversal and a nested map to store node values by their horizontal and vertical distances.

1. **Class Definition**
   ```cpp
   class Solution
   {
   public:
   ```
   - Defines the `Solution` class, which will contain the method for vertical order traversal.

2. **Vertical Order Method Declaration**
   ```cpp
   vector<int> verticalOrder(Node *root)
   {
   ```
   - Declares the `verticalOrder` method, which takes a pointer to the root of the binary tree as its argument and returns a vector of integers.

3. **Nested Map Initialization**
   ```cpp
   map<int, map<int, vector<int> >> nodes;
   ```
   - Initializes a nested map called `nodes`:
     - The outer map's key (`int`) represents the horizontal distance from the root.
     - The inner map's key (`int`) represents the level of the node, with the value being a vector of integers (the node data at that horizontal distance and level).

4. **Queue Initialization for BFS**
   ```cpp
   queue<pair<Node*, pair<int, int> >> q;
   ```
   - Declares a queue `q` to perform level-order traversal, where each element is a pair consisting of:
     - A pointer to the node (`Node*`).
     - A pair of integers representing the horizontal distance and the level of the node.

5. **Output Vector Initialization**
   ```cpp
   vector<int> ans;
   if(root == NULL) return ans;
   ```
   - Initializes a vector `ans` to store the final vertical order traversal result.
   - Checks if the root is `NULL`, returning an empty vector if it is, as there are no nodes to process.

6. **Push Root into Queue**
   ```cpp
   q.push(make_pair(root, make_pair(0, 0)));
   ```
   - Pushes the root node into the queue with a horizontal distance (`hd`) of `0` and level (`lvl`) of `0`.

7. **BFS Loop**
   ```cpp
   while(!q.empty()){
   ```
   - Starts a loop that continues as long as the queue is not empty, indicating there are still nodes to process.

8. **Extract Node, HD, and Level**
   ```cpp
   pair<Node*, pair<int, int> > temp = q.front();
   q.pop();
   Node* frontNode = temp.first;
   int hd = temp.second.first;
   int lvl = temp.second.second;
   ```
   - Retrieves the front element of the queue and unpacks it into `temp`, which contains:
     - `frontNode`: The current node being processed.
     - `hd`: The horizontal distance of `frontNode`.
     - `lvl`: The level of `frontNode`.
   - Calls `q.pop()` to remove the processed node from the queue.

9. **Store Node Data in Map**
   ```cpp
   nodes[hd][lvl].push_back(frontNode -> data);
   ```
   - Stores the current node's data in the nested map `nodes` based on its horizontal distance (`hd`) and level (`lvl`).

10. **Push Left Child into Queue**
    ```cpp
    if(frontNode -> left)
        q.push(make_pair(frontNode -> left, make_pair(hd -1 , lvl + 1)));
    ```
    - If the current node has a left child, it is pushed into the queue with:
      - Horizontal distance (`hd - 1`) because the left child is one unit to the left.
      - Level (`lvl + 1`) because it is one level deeper.

11. **Push Right Child into Queue**
    ```cpp
    if(frontNode -> right)
        q.push(make_pair(frontNode -> right, make_pair(hd + 1, lvl + 1)));
    ```
    - If the current node has a right child, it is pushed into the queue with:
      - Horizontal distance (`hd + 1`) because the right child is one unit to the right.
      - Level (`lvl + 1`) because it is one level deeper.

12. **Output the Vertical Order**
    ```cpp
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    ```
    - This nested loop iterates through the `nodes` map:
      - The outer loop iterates through each horizontal distance (`i`).
      - The middle loop iterates through each level at that horizontal distance (`j`).
      - The inner loop iterates through each node value at that level and pushes it into the `ans` vector.
    - This effectively constructs the vertical order of the binary tree.

13. **Return the Result**
    ```cpp
    return ans;
    }
   };
   ```
   - Finally, returns the `ans` vector containing the vertical order traversal of the binary tree.

```
### Example

Given the following binary tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

The vertical order traversal would be: `4 2 1 5 3 6`. 

1. **Horizontal distances:**
   - `2` has HD `-1`, `1` has HD `0`, `3` has HD `1`.
   - `4` has HD `-2`, `5` has HD `0`, `6` has HD `1`.

2. **Levels:**
   - The levels of nodes are considered while traversing to maintain the order when nodes have the same HD.

### Time Complexity

- **BFS Traversal:** Each node is processed once, leading to a time complexity of **O(N)**, where **N** is the number of nodes in the tree.

- **Map Operations:** The operations on the map also take **O(N)** time in the worst case for insertion and retrieval.

Overall, the time complexity is **O(N)**.

### Space Complexity

- **Queue Space:** The queue can hold at most **O(N)** nodes in the worst case (e.g., a completely unbalanced tree).

- **Map Space:** The map stores each node, leading to an additional **O(N)** space.

Overall, the space complexity is **O(N)** due to the space needed for the queue and the nested map.

### Conclusion

The code effectively utilizes a queue for level-order traversal and a nested map to organize nodes by their vertical order, considering both horizontal distance and level to provide a well-structured output. If you have further questions or need clarifications, feel free to ask!
