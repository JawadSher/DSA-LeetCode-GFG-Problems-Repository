<h1 align='center'>Bottom - View - of - Binary - Tree</h1>

## Problem Statement

**Problem URL :** [Bottom View of Binary Tree](https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

![image](https://github.com/user-attachments/assets/f0107d8c-8940-4e68-b9e3-280c54f74ce5)
![image](https://github.com/user-attachments/assets/76f615a9-04ae-4a39-88f4-876fe632d13b)

## Problem Explanation
The **Bottom View** of a binary tree shows the nodes visible when the tree is viewed from the bottom. For each horizontal distance from the root, only the node that appears the lowest in the tree is included in the bottom view.

For example:

Given the binary tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
```

The **Bottom View** of this binary tree would be `[4, 2, 5, 3, 6]`.

### Step 2: Approach and Explanation

To solve this problem, we can use a level-order traversal (breadth-first traversal) while keeping track of **horizontal distances (HD)** of nodes from the root.

Steps:
1. **Start at the root** node with an HD of 0.
2. **For each node**, add its left child with HD decreased by 1 and right child with HD increased by 1.
3. We use a **map** to keep track of nodes at each HD. In this case, we always update the node at each HD, so the map holds the **last node encountered** at each HD, which will be the bottommost node at that distance.
4. After traversing all nodes, **extract values** from the map to get nodes from leftmost to rightmost HD.

## Problem Solution
```cpp
class Solution {
  public:
    vector <int> bottomView(Node *root) {
    
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
            
            topNode[hd] = frontNode -> data;
            
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
class Solution {
  public:
    vector <int> bottomView(Node *root) {
```
- Defines a class `Solution` with a public function `bottomView` that takes the root of the binary tree as input and returns a vector containing the bottom view nodes.

```cpp
        vector<int> ans;
        if(root == NULL) return ans;
```
- Initializes an empty vector `ans` to store the bottom view nodes.
- If the root is `NULL`, the tree is empty, so we return `ans` as an empty vector.

```cpp
        map<int, int> topNode;
        queue<pair<Node*, int>> q;
```
- `topNode`: A map where the key is the HD, and the value is the data of the bottommost node at that HD. As we process each node, we overwrite previous values at the same HD, ensuring the map holds the lowest (last) node encountered at each HD.
- `q`: A queue to perform level-order traversal, storing pairs of nodes and their HD.

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
- The `while` loop processes all nodes in the queue.
- Retrieves the front element in the queue, `temp`, which is a pair containing a node (`frontNode`) and its HD (`hd`).
- Removes this element from the queue with `q.pop()`.

```cpp
            topNode[hd] = frontNode -> data;
```
- For each node, update the map `topNode` at the HD `hd` with the node’s data. This will keep overwriting any previous node at that HD, ensuring that only the bottommost node remains.

```cpp
            if(frontNode -> left){
                q.push({frontNode -> left, hd -1});
            }
```
- If the current node has a left child, add it to the queue with an HD of `hd - 1` (one unit to the left).

```cpp
            if(frontNode -> right){
                q.push({frontNode -> right, hd + 1});
            }
```
- If the current node has a right child, add it to the queue with an HD of `hd + 1` (one unit to the right).

```cpp
        }
```
- Ends the `while` loop once all nodes have been processed.

```cpp
        for(auto i : topNode){
            ans.push_back(i.second);
        }
```
- Loops through the `topNode` map in ascending order of HD, pushing each node’s data into the `ans` vector. This ensures the nodes are ordered from the leftmost to rightmost in the bottom view.

```cpp
        return ans;
    }
};
```
- Returns the `ans` vector containing the bottom view of the binary tree.

---

### Step 4: Output Examples with Explanation

Consider this binary tree:

```
        1
       / \
      2   3
     / \   \
    4   5   6
```

**Horizontal Distances (HDs)**:
- HD `-2`: Node `4`
- HD `-1`: Node `2`
- HD `0`: Node `5` (bottommost at this HD)
- HD `1`: Node `3`
- HD `2`: Node `6`

The bottom view will be `[4, 2, 5, 3, 6]`.

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

**Bottom view** for this tree would be `[2, 4, 5, 6]`.

---

### Step 5: Time and Space Complexity

#### Time Complexity
- **O(N)**: We visit each node once in the level-order traversal, so the time complexity is proportional to the number of nodes, **N**.

#### Space Complexity
- **O(N)**: The space required by the map `topNode` is proportional to the number of unique HDs, which is at most **N**.
- The queue `q` also holds at most **N** nodes in the worst case.

Thus, the overall space complexity is **O(N)**.

This solution efficiently finds the bottom view by performing a level-order traversal and using HDs to keep only the bottommost node at each HD.
