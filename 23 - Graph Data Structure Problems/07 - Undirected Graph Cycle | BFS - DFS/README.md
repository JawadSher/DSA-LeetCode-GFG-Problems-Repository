<h1 align='center'>Undirected - Graph - Cycle</h1>

## Problem Statement

**Problem URL :** [Undirected Graph Cycle](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

![image](https://github.com/user-attachments/assets/2d5790db-b972-4dac-96a5-688c2d9a97d1)
![image](https://github.com/user-attachments/assets/800b5538-94da-449a-8fb2-acd2c53b91f8)

## Problem Explanation
The problem requires determining whether an undirected graph contains a cycle. A cycle in an undirected graph means a sequence of edges connects a node back to itself through a different path. For instance:

- **Example 1**:  
  Input:  
  Adjacency list representation:  
  ```
  0 -- 1
   \   |
    \  |
     \ 2
  ```
  Output: **True** (Cycle exists: 0 → 1 → 2 → 0).

- **Example 2**:  
  Input:  
  ```
  0 -- 1
      |
      2
  ```
  Output: **False** (No cycle exists).

#### **Approach**
The problem can be solved using **Breadth-First Search (BFS)** and **Depth-First Search (DFS)**.

1. **Using BFS**:
   - Start from an unvisited node.
   - Use a queue to explore nodes level by level.
   - Keep track of visited nodes and their parent nodes to avoid revisiting the parent as a "false positive" cycle.
   - If you encounter a previously visited node that isn’t the parent of the current node, a cycle exists.

2. **Using DFS**:
   - Start from an unvisited node.
   - Traverse the graph recursively.
   - For each neighbor of the current node, check:
     - If the neighbor hasn’t been visited, recursively traverse it.
     - If the neighbor is visited and not the parent of the current node, a cycle exists.


## BFS Approach

1. **Use a Queue**: 
   - BFS traversal is performed using a queue to explore nodes level by level.
   - Maintain a `parent` map to track the node from which the current node was reached.

2. **Mark Nodes as Visited**: 
   - Keep track of visited nodes to avoid revisiting them unnecessarily.

3. **Cycle Detection Logic**:
   - For every neighbor of the current node:
     - If it is already visited **and** is not the parent of the current node, a cycle is detected.
     - If it is not visited, enqueue it and mark it as visited.

4. **Handle Disconnected Components**:
   - Since the graph might be disconnected, perform BFS starting from each unvisited node.

### Problem Solution
```cpp
class Solution {
  public:
    // Helper function to detect a cycle using BFS
    bool isCycleBFS(int src, unordered_map<int, bool>& visited, vector<vector<int>>& adj) {
        // Parent map to track the parent of each node
        unordered_map<int, int> parent;
        
        // Initialize source node: mark visited and set parent as -1
        parent[src] = -1;
        visited[src] = true;

        // Queue for BFS traversal
        queue<int> q;
        q.push(src);

        // Perform BFS
        while (!q.empty()) {
            // Get the front node from the queue and process it
            int front = q.front();
            q.pop();

            // Iterate through all neighbors of the current node
            for (auto neighbour : adj[front]) {
                // If the neighbor is already visited and is not the parent, a cycle is detected
                if (visited[neighbour] == true && neighbour != parent[front]) {
                    return true; // Cycle found
                } 
                // If the neighbor is not visited, mark it as visited, set its parent, and enqueue it
                else if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }

        // If BFS completes and no cycle is detected, return false
        return false;
    }
    
    // Main function to check for a cycle in an undirected graph
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of nodes in the graph
        
        // Map to track visited nodes
        unordered_map<int, bool> visited;

        // Iterate through all nodes to handle disconnected components
        for (int i = 0; i < n; i++) {
            // If the node is not visited, perform BFS from this node
            if (!visited[i]) {
                bool ans = isCycleBFS(i, visited, adj); // Call BFS helper
                if (ans == true) {
                    return true; // If a cycle is found, return true
                }
            }
        }
        
        // If no cycle is found in any component, return false
        return false;
    }
};
```
### Problem Solution Explanation

#### **Helper Function: `isCycleBFS`**

```cpp
bool isCycleBFS(int src, unordered_map<int, bool> &visited, vector<vector<int>>& adj) {
```
- **Purpose**: This function performs BFS from a given source node `src` to detect a cycle in the graph.
- **Parameters**:
  - `src`: The starting node for BFS.
  - `visited`: A map to track if a node has been visited.
  - `adj`: Adjacency list representation of the graph.



```cpp
    unordered_map<int, int> parent;
```
- **Purpose**: This map keeps track of the parent of each node during BFS.  
  - `parent[node]` gives the node from which `node` was reached.



```cpp
    parent[src] = -1;
    visited[src] = true;
```
- The source node `src` is marked as visited.
- Its parent is set to `-1` (indicating that it has no parent).



```cpp
    queue<int> q;
    q.push(src);
```
- A queue is initialized to perform BFS traversal.
- The source node is added to the queue.



```cpp
    while (!q.empty()) {
```
- **Purpose**: Perform BFS until there are no nodes left to process.



```cpp
        int front = q.front();
        q.pop();
```
- Get the current node (`front`) from the queue and remove it.



```cpp
        for (auto neighbour : adj[front]) {
```
- Loop through all neighbors of the current node.



```cpp
            if (visited[neighbour] == true && neighbour != parent[front]) 
                return true;
```
- **Cycle Detection Logic**:
  - If a neighbor is already visited **and** it is not the parent of the current node, a cycle is detected. Return `true`.



```cpp
            else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
```
- If the neighbor is not visited:
  - Add it to the queue for further processing.
  - Mark it as visited.
  - Set its parent to the current node (`front`).



```cpp
    }
    
    return false;
```
- If no cycle is detected during BFS, return `false`.



#### **Main Function: `isCycle`**

```cpp
bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
```
- `adj` is the adjacency list representing the graph.
- `n` is the number of nodes in the graph.



```cpp
    unordered_map<int, bool> visited;
```
- A map to keep track of visited nodes.



```cpp
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCycleBFS(i, visited, adj);
            if (ans == 1) return true;
        }
    }
```
- Loop through all nodes to handle disconnected components.
  - If a node is unvisited, call `isCycleBFS` to check for cycles starting from that node.
  - If any call returns `true`, a cycle exists; return `true`.



```cpp
    return false;
```
- If no cycle is detected in any component, return `false`.



### **Example**

#### **Graph Representation**
```cpp
adj = {
    {1, 2},    // Node 0 is connected to 1 and 2
    {0, 2},    // Node 1 is connected to 0 and 2
    {0, 1},    // Node 2 is connected to 0 and 1
    {3, 4},    // Node 3 is connected to 4
    {3}        // Node 4 is connected to 3
};
```

#### **Visualization**:
```
0 -- 1
 \  /
  2

3 -- 4
```

#### **Execution Steps**:
1. Start BFS from node `0`:
   - `0` is visited. Queue: `[0]`.
   - Process `0`: Visit `1` (set parent to `0`), and `2` (set parent to `0`). Queue: `[1, 2]`.

2. Process node `1`:
   - `1` is visited. Queue: `[2]`.
   - Process `1`: Neighbor `0` (already visited, but it is the parent), Neighbor `2` (already visited and **not the parent** → Cycle detected!).

3. Return `true` for the cycle.



### **Time Complexity**
1. **BFS Traversal**:
   - Each node is visited once: **O(V)**.
   - All edges are processed: **O(E)**.

2. **Total Complexity**: **O(V + E)**.



### **Space Complexity**
1. **Visited Map**: **O(V)**.
2. **Parent Map**: **O(V)**.
3. **Queue**: At most **O(V)**.

**Total Space Complexity**: **O(V)**.

---

## DFS Approach
### **Steps to Detect a Cycle Using DFS**

The Depth First Search (DFS) approach involves recursive traversal of a graph. During traversal, we keep track of visited nodes and the parent node to detect cycles.

#### **Key Concepts**
1. If a node is visited and is not the parent of the current node, then a cycle exists.
2. The recursion stack helps simulate DFS traversal, visiting deeper levels of the graph and backtracking as needed.


#### **Steps**
1. **Mark Nodes as Visited**:
   - Use a `visited` map to track nodes that have been processed.

2. **Track Parent Nodes**:
   - Keep a `parent` reference to avoid false positives when revisiting nodes.

3. **Recursive Exploration**:
   - For each neighbor of the current node:
     - If the neighbor is not visited, recursively explore it.
     - If the neighbor is visited and isn’t the parent of the current node, a cycle is detected.

4. **Return Result**:
   - If a cycle is found, return `true`.
   - If all nodes are processed without finding a cycle, return `false`.

### Problem Solution
```cpp
class Solution {
public:
    // Function to perform DFS and detect a cycle in an undirected graph
    bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, vector<vector<int>>& adj) {
        // Mark the current node as visited
        visited[node] = true;

        // Traverse all neighbors of the current node
        for (auto neighbour : adj[node]) {
            // If the neighbor is not visited, recursively call DFS on it
            if (!visited[neighbour]) {
                // Check if a cycle is detected in the recursive call
                bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
                if (cycleDetected) 
                    return true; // If a cycle is detected, return true
            } 
            // If the neighbor is already visited and it's not the parent of the current node, cycle detected
            else if (neighbour != parent) 
                return true;
        }

        // No cycle detected from this node
        return false;
    }
    
    // Wrapper function to detect a cycle in the entire graph
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of nodes in the graph

        // Map to keep track of visited nodes
        unordered_map<int, bool> visited;

        // Traverse all nodes to handle disconnected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // If the current node is not visited
                // Call DFS to check for a cycle starting from this node
                bool ans = isCycleDFS(i, -1, visited, adj);
                if (ans) 
                    return true; // If a cycle is detected, return true
            }
        }

        // No cycle found in any component
        return false;
    }
};

```

### Problem Solution Explanation

#### **DFS Function**:
```cpp
bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, vector<vector<int>>& adj)
```
This function detects a cycle in the graph using DFS starting from `node`.

- **`node`**: The current node being visited.
- **`parent`**: The node that led to the current node, used to prevent false positives.
- **`visited`**: Tracks whether a node has been visited.
- **`adj`**: Adjacency list representation of the graph.



```cpp
visited[node] = true;
```
- Marks the current node as visited to ensure it isn’t revisited during DFS.



```cpp
for (auto neighbour : adj[node]) {
```
- Iterates over all neighbors of the current node.



```cpp
if (!visited[neighbour]) {
```
- Checks if the neighbor is unvisited. If true, initiates a recursive DFS call to explore it.



```cpp
bool cycleDetected = isCycleDFS(neighbour, node, visited, adj);
if (cycleDetected) return true;
```
- Recursively explores the neighbor.
- If a cycle is detected in the recursive call, propagates `true` back up the recursion stack.



```cpp
else if (neighbour != parent) return true;
```
- If the neighbor is visited and isn’t the parent of the current node, a cycle is detected.



```cpp
return false;
```
- If all neighbors are processed without detecting a cycle, returns `false`.



#### **Wrapper Function**:
```cpp
bool isCycle(vector<vector<int>>& adj)
```
This function processes all components of the graph to ensure every node is checked for cycles.



```cpp
int n = adj.size();
```
- Gets the number of nodes in the graph.



```cpp
unordered_map<int, bool> visited;
```
- Initializes the `visited` map to track visited nodes.



```cpp
for (int i = 0; i < n; i++) {
```
- Iterates through all nodes in the graph.



```cpp
if (!visited[i]) {
    bool ans = isCycleDFS(i, -1, visited, adj);
    if (ans == 1) return true;
}
```
- If the current node is unvisited, starts a DFS traversal.
- If any DFS traversal detects a cycle, returns `true`.



```cpp
return false;
```
- If no cycles are found in any component of the graph, returns `false`.



### **Example Execution**

#### **Input Graph**:
Adjacency list representation:
```
adj = {{1, 2}, {0, 2}, {0, 1}}
```
Graph structure:
```
0 -- 1
 \   |
  \  2
```



**Execution Steps**:
1. Start DFS from node `0` with `parent = -1`.  
   - Mark `0` as visited.
   - Explore neighbors `1` and `2`.

2. Visit neighbor `1` with `parent = 0`.  
   - Mark `1` as visited.
   - Explore its neighbors `0` and `2`.

3. From `1`, neighbor `0` is the parent (no cycle here).  
   Visit neighbor `2` with `parent = 1`.

4. From `2`, neighbor `0` is visited and isn’t the parent—**Cycle detected**.

**Output**: **Cycle Found**



### **Time Complexity**

1. **DFS Traversal**:
   - Each node is visited once: \(O(V)\).
   - Each edge is traversed once: \(O(E)\).

Total time complexity: **\(O(V + E)\)**.


### **Space Complexity**

1. **Visited Map**: \(O(V)\), stores the visited state for each node.
2. **Recursive Stack**: \(O(V)\) for the maximum depth of the recursion.

Total space complexity: **\(O(V)\)**.


### **Additional Notes for Beginners**

- Ensure you understand the graph representation (adjacency list) before diving into the algorithm.
- Practice drawing recursion trees for DFS to visualize the flow of execution.
- Always account for disconnected components in the graph. This is handled by iterating over all nodes in `isCycle()`.
