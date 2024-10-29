<h1 align='center'>Top - View - of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Top view of Binary Tree](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/7c4f2586-eb7a-4c34-9bed-b39301389150)
![image](https://github.com/user-attachments/assets/06bde3b1-3f05-48bd-bc65-ab60fd9a78e6)

## Problem Explanation

In this problem, you need to find the **top view** of a binary tree. The top view is the set of nodes that are visible when the tree is viewed from above. If two nodes exist at the same horizontal distance from the root, only the topmost node is considered visible.

For example:

Given a binary tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
```

The **top view** of this binary tree is `[4, 2, 1, 3, 6]`.

### Step 2: Approach and Explanation

To solve this problem, we can use the concept of **horizontal distance (HD)**:
1. We start at the root node, which has an HD of 0.
2. For the left child of a node, the HD decreases by 1, and for the right child, the HD increases by 1.
3. We use a **queue** to process nodes in level-order (breadth-first traversal) and a **map** to store the first node encountered at each HD, which represents the topmost node at that HD.

By processing nodes level-by-level and recording only the first node at each HD in the map, we capture the top view of the tree.

## Problem Solution
```cpp
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode -> data;
            }
            
            if(frontNode -> left){
                q.push({frontNode -> left, hd -1});
            }
            
            if(frontNode -> right){
                q.push({frontNode -> right, hd + 1});
            }
            
        }
        for(auto i : topNode){
            ans.push_back(i.second);
        }
        
        
        return ans;
    }

};
```

## Problem Solution Explanation

```cpp
class Solution
{
    public:
    // Function to return a list of nodes visible from the top view 
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
```
- Defines a class `Solution` containing the function `topView` that takes the root of the tree as input and returns a vector of integers representing the top view of the tree.

```cpp
        vector<int> ans;
        if(root == NULL) return ans;
```
- Initializes an empty vector `ans` to store the top view.
- If the root is `NULL`, the tree is empty, so we return `ans` as an empty vector.

```cpp
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
```
- `topNode`: A map where the key is the horizontal distance (HD) and the value is the data of the topmost node at that HD.
- `q`: A queue to perform level-order traversal, storing pairs of a node and its horizontal distance.

```cpp
        q.push({root, 0});
```
- Adds the root node to the queue with an HD of `0`.

```cpp
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
```
- The `while` loop runs until the queue is empty.
- Retrieves the front element from the queue (`temp`), which is a pair containing the node (`frontNode`) and its HD (`hd`).
- Removes this element from the queue with `q.pop()`.

```cpp
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode -> data;
            }
```
- Checks if the HD `hd` is already present in the map `topNode`.
- If not, it means this is the first node encountered at this HD, so it stores the node’s data at `topNode[hd]`.

```cpp
            if(frontNode -> left){
                q.push({frontNode -> left, hd -1});
            }
```
- If the current node has a left child, it is added to the queue with an HD of `hd - 1` (one unit to the left).

```cpp
            if(frontNode -> right){
                q.push({frontNode -> right, hd + 1});
            }
```
- If the current node has a right child, it is added to the queue with an HD of `hd + 1` (one unit to the right).

```cpp
        }
```
- Ends the `while` loop once all nodes have been processed.

```cpp
        for(auto i : topNode){
            ans.push_back(i.second);
        }
```
- Loops through the `topNode` map in ascending order of HD and pushes each node’s data into the `ans` vector. This ensures the nodes are ordered from leftmost to rightmost in the top view.

```cpp
        return ans;
    }
};
```
- Returns the `ans` vector containing the top view of the binary tree.

### Step 4: Output Examples with Explanation

Given this binary tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

**Horizontal Distances**:
- HD `-2`: Node `4`
- HD `-1`: Node `2`
- HD `0`: Node `1` (root)
- HD `1`: Node `3`
- HD `2`: Node `6`

The top view would be: `[4, 2, 1, 3, 6]`.

Another example:

```
        1
       / \
      2   3
       \
        4
         \
          5
           \
            6
```

Top view for this tree would be: `[2, 1, 3, 6]`.

### Step 5: Time and Space Complexity

#### Time Complexity
- **O(N)**: Every node is processed once in the level-order traversal, so the time complexity is proportional to the number of nodes, **N**.

#### Space Complexity
- **O(N)**: The space required by the map `topNode` is proportional to the number of nodes.
- The queue `q` also holds at most **N** nodes in the worst case.

So the overall space complexity is **O(N)**.

This approach captures the top view efficiently using horizontal distances and level-order traversal, ensuring only the topmost node at each HD is stored.
