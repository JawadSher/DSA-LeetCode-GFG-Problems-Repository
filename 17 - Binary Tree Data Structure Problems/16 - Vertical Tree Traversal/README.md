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
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
public:
    void verticalOrder(Node* root) {
        if (root == NULL) return;

        // Map to store nodes in vertical order
        map<int, vector<int>> verticalMap;

        // Queue for BFS traversal with horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0}); // {node, horizontal distance}

        while (!q.empty()) {
            auto [node, hd] = q.front(); // Get the front element
            q.pop();

            // Store node data in the map according to horizontal distance
            verticalMap[hd].push_back(node->data);

            // Push left child with HD - 1
            if (node->left) q.push({node->left, hd - 1});
            // Push right child with HD + 1
            if (node->right) q.push({node->right, hd + 1});
        }

        // Output the vertical order
        for (const auto& pair : verticalMap) {
            for (int value : pair.second) {
                cout << value << " ";
            }
            cout << endl; // Newline for different verticals
        }
    }
};
```

## Problem Solution Explanation

1. **Include Libraries**
   ```cpp
   #include <map>
   #include <vector>
   #include <queue>
   ```
   - These lines include the necessary libraries:
     - `<map>`: For using the map data structure to store vertical nodes.
     - `<vector>`: For storing multiple values (nodes) corresponding to each vertical.
     - `<queue>`: For implementing the BFS (Breadth-First Search) traversal.

2. **Node Structure Definition**
   ```cpp
   struct Node {
       int data;
       Node *left, *right;
   };
   ```
   - This defines a `Node` structure to represent a binary tree node:
     - `data`: An integer storing the value of the node.
     - `left`: A pointer to the left child node.
     - `right`: A pointer to the right child node.

3. **Class Definition**
   ```cpp
   class Solution {
   public:
   ```
   - Defines the `Solution` class, which contains methods to solve the problem. The `public` access specifier indicates that the members of this class can be accessed from outside the class.

4. **Vertical Order Method Declaration**
   ```cpp
   void verticalOrder(Node* root) {
   ```
   - Declares the `verticalOrder` method that takes a pointer to the root of the binary tree as an argument.

5. **Check for Empty Tree**
   ```cpp
   if (root == NULL) return;
   ```
   - This line checks if the root node is `NULL`. If it is, the function immediately returns, as there are no nodes to process.

6. **Map Initialization**
   ```cpp
   map<int, vector<int>> verticalMap;
   ```
   - Initializes a map called `verticalMap` where:
     - The key is an integer (the horizontal distance from the root).
     - The value is a vector of integers (the node values at that horizontal distance).

7. **Queue Initialization for BFS**
   ```cpp
   queue<pair<Node*, int>> q;
   q.push({root, 0}); // {node, horizontal distance}
   ```
   - Declares a queue named `q` to facilitate level-order traversal. Each element in the queue is a pair consisting of:
     - A pointer to the node (`Node*`).
     - An integer representing the horizontal distance (HD) of that node.
   - Pushes the root node into the queue with an HD of `0`.

8. **BFS Loop**
   ```cpp
   while (!q.empty()) {
   ```
   - Starts a loop that continues as long as the queue is not empty, indicating there are still nodes to process.

9. **Extract Node and HD**
   ```cpp
   auto [node, hd] = q.front(); // Get the front element
   q.pop();
   ```
   - Uses structured bindings (C++17 feature) to unpack the front element of the queue into `node` and `hd`.
   - `q.front()` retrieves the element at the front of the queue without removing it.
   - `q.pop()` removes the front element from the queue after retrieving it.

10. **Store Node Data in Map**
    ```cpp
    verticalMap[hd].push_back(node->data);
    ```
    - This line adds the current node's data to the vector in `verticalMap` that corresponds to its horizontal distance (`hd`).

11. **Push Left Child into Queue**
    ```cpp
    if (node->left) q.push({node->left, hd - 1});
    ```
    - If the current node has a left child, it is pushed into the queue with an HD of `hd - 1` (since left children are one unit closer to the left).

12. **Push Right Child into Queue**
    ```cpp
    if (node->right) q.push({node->right, hd + 1});
    ```
    - If the current node has a right child, it is pushed into the queue with an HD of `hd + 1` (since right children are one unit closer to the right).

13. **Output Vertical Order**
    ```cpp
    for (const auto& pair : verticalMap) {
    ```
    - This loop iterates through each key-value pair in the `verticalMap`.

14. **Print Node Values for Each Vertical**
    ```cpp
    for (int value : pair.second) {
        cout << value << " ";
    }
    cout << endl; // Newline for different verticals
    ```
    - The inner loop iterates through the vector of node values (`pair.second`) corresponding to each HD and prints each value followed by a space.
    - After printing all values for a vertical line, it outputs a newline for better readability.


## Step 4: Output Examples with Explanation

### Example 1
Given the tree:
```
        1
       / \
      2   3
     / \   \
    4   5   6
       /
      7
```

**Output**:
```
4
2
1 5 7
3
6
```

### Explanation
- The first vertical (HD -2) contains node `4`.
- The second vertical (HD -1) contains node `2`.
- The third vertical (HD 0) contains nodes `1`, `5`, and `7` printed together.
- The fourth vertical (HD 1) contains node `3`.
- The fifth vertical (HD 2) contains node `6`.

### Example 2
For a single node tree:
```
        1
```

**Output**:
```
1
```

### Explanation
- The tree consists only of the root node, which is also the only node at HD `0`.

## Step 5: Time and Space Complexity

### Time Complexity
- The algorithm performs a level-order traversal (BFS) of the binary tree:
  - Each node is visited once.
  - Therefore, the time complexity is **O(n)**, where `n` is the number of nodes in the tree.

### Space Complexity
- The space complexity is determined by:
  - The queue used for BFS: In the worst case (a balanced tree), it can hold up to `O(w)` nodes, where `w` is the maximum width of the tree.
  - The map that stores vertical values: In the worst case, it can also hold `O(n)` nodes if every node is in a different vertical.

Thus, the space complexity is **O(n)** in the worst case due to storing nodes in the map.

### Summary
- **Time Complexity**: **O(n)**
- **Space Complexity**: **O(n)**

This thorough explanation covers the vertical tree traversal problem from understanding the problem statement to implementation and analysis of the code. If you have any questions or need further clarification, feel free to ask!
