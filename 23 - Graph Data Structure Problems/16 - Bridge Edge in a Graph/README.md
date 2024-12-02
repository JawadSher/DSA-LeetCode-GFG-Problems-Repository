<h1 align='center'>Bridge - Edge - in a - Graph</h1>

## Problem Statement

**Problem URL :** [Bridge Edge in a Graph](https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1)

![image](https://github.com/user-attachments/assets/9a20ce6e-2ad3-4e7c-ae67-62f51930cbc8)
![image](https://github.com/user-attachments/assets/10bafc54-4a8c-47f4-85b7-62a4e6ba4c96)
![image](https://github.com/user-attachments/assets/86b5473e-1c7a-47ec-951a-09c3452b0071)
![image](https://github.com/user-attachments/assets/3ec3da89-de6a-4123-8fa2-143a4fcba2e6)

## Problem Explanation
In graph theory, a **bridge** (also known as a **cut-edge**) is an edge in an undirected graph that, if removed, would cause the graph to become disconnected. Essentially, removing a bridge would split the graph into two disconnected components.

The problem requires us to check whether a specific edge `(c, d)` in an undirected graph is a **bridge**.

Given:
1. A graph with `V` vertices and `E` edges.
2. An edge list, representing the graph's connectivity.
3. Two vertices `c` and `d` are given, and we need to determine if the edge between `c` and `d` is a **bridge**.

**What is a Bridge (Cut-Edge)?**
A **bridge** in a graph is an edge that, if removed, would make the graph disconnected. This means that the removal of this edge would break the graph into two disconnected parts.

#### **Example 1:**

Consider the following graph:

```
Vertices: 5
Edges: (0-1), (1-2), (2-3), (3-4)

Graph visualization:

  0 -- 1 -- 2 -- 3 -- 4
```

The graph looks like this:
```
0 - 1 - 2 - 3 - 4
```

Let’s say we are asked whether the edge `(1, 2)` is a bridge. 

- If we remove the edge `(1, 2)`, the graph would become disconnected because there would be no path between vertex `0` and vertex `3` (or between `3` and `4`). Hence, the edge `(1, 2)` is a **bridge**.

Now, if we check if the edge `(0, 1)` is a bridge:
- Removing `(0, 1)` leaves the graph as:
```
1 - 2 - 3 - 4
```
In this case, the graph is still connected because the path `(1 - 2 - 3 - 4)` still exists. Hence, the edge `(0, 1)` is **not** a bridge.

#### **Example 2:**

Consider a more complex graph:

```
Vertices: 6
Edges: (0-1), (1-2), (2-3), (3-4), (4-5), (2-4)

Graph visualization:

  0 -- 1 -- 2 -- 3 -- 4 -- 5
             |
             4
```

In this graph, the edge `(3, 4)` is a **bridge** because removing it would disconnect vertex `3` from vertex `4`. However, the edge `(2, 4)` is **not a bridge** because removing it does not disconnect the graph (there is still a path through vertices `1-2-4-5`).



### **Approach to Solve the Problem**

1. **DFS (Depth-First Search):**
   To determine if an edge is a bridge, we can use DFS traversal. During the DFS, we maintain:
   - `disc[]`: Discovery time of each vertex.
   - `low[]`: The lowest discovery time reachable from the vertex's subtree.
   - `parent[]`: Parent of each vertex in the DFS tree.

2. **Key Concept:**
   If `low[v] > disc[u]`, where `u` is the current node and `v` is its adjacent vertex, then the edge `(u, v)` is a bridge.

   The reason:
   - The value of `low[v]` represents the earliest visited vertex reachable from `v`.
   - If `low[v]` is greater than `disc[u]`, it means there is no back edge from `v` or any of its descendants that can connect to `u` or its ancestors, which implies that removing the edge `(u, v)` would disconnect the graph.



### **Algorithm**

1. Perform DFS starting from any unvisited node.
2. For each vertex `u`, for each adjacent vertex `v`:
   - If `v` is not visited, recursively call DFS for `v` and update the `low[u]` value.
   - If `v` is already visited and is not the parent of `u`, update `low[u]` based on the discovery time of `v`.
   - After processing the neighbors, check if `low[v] > disc[u]` and if `u-v` is the target edge. If true, mark the edge as a bridge.



### **Example Walkthrough**

Consider the graph from **Example 1**:

```
  0 -- 1 -- 2 -- 3 -- 4
```

1. **DFS starting from vertex 0**:
   - Discovery times: `disc[0] = 0`, `disc[1] = 1`, `disc[2] = 2`, `disc[3] = 3`, `disc[4] = 4`.
   - Low values are initially the same as the discovery times, i.e., `low[] = {0, 1, 2, 3, 4}`.

2. **Exploring edge (1, 2)**:
   - From node `1`, we visit node `2`, and upon backtracking, we find that `low[2] > disc[1]`, indicating that `(1, 2)` is a bridge.
   
3. **Exploring edge (0, 1)**:
   - Similarly, upon exploring the edge `(0, 1)`, we see that removing it will not disconnect the graph, so it is **not** a bridge.



### **Edge Case Considerations**
1. **Graphs with no bridges**: Some graphs may have no bridges at all, such as fully connected graphs or graphs with cycles.
2. **Graphs with only two vertices**: A graph with two vertices connected by a single edge is trivially a bridge.


### **Conclusion**

This problem involves detecting **bridges** in a graph using **DFS** traversal and checking if the edge `(c, d)` is a bridge. The key idea is to track discovery and low times during the DFS, and if an edge `(u, v)` satisfies the condition `low[v] > disc[u]`, it is a bridge. The solution uses DFS with appropriate updates to discovery and low times to find and identify the bridge edges.

## Problem Solution
```cpp
class Solution {
public:
    // Depth-First Search (DFS) function to explore the graph
    void dfs(int node, int parent, int timer, int& result, vector<int>& visited, vector<int>& disc, vector<int>& low, vector<vector<int>>& adjacencyList, int c, int d){
        visited[node] = true;                  // Mark the current node as visited
        disc[node] = low[node] = timer++;     // Set discovery time and low time of the node
        
        // Traverse all adjacent vertices (neighbors) of the current node
        for(int vertex : adjacencyList[node]){
            if(vertex == parent) continue;     // Skip the parent node to avoid going backward in the DFS

            if(!visited[vertex]){              // If the neighbor is unvisited, perform DFS on it
                dfs(vertex, node, timer, result, visited, disc, low, adjacencyList, c, d);
                low[node] = min(low[node], low[vertex]); // Update the low time of the current node
                
                // If low value of the neighbor is greater than the discovery time of the current node
                // and the edge (node, vertex) is the target edge (c, d), set result to 1 (indicating it's a bridge)
                if(low[vertex] > disc[node] && ((node == c && vertex == d) || (node == d && vertex == c))) 
                    result = 1;
            } else {
                low[node] = min(low[node], disc[vertex]); // Update the low time if the neighbor is already visited
            }
        }
    }
    
    // Function to check if the edge (c, d) is a bridge
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<int> disc(V, -1); // Discovery time for each vertex (initially -1, indicating unvisited)
        vector<int> low(V, -1);  // Lowest discovery time reachable from the vertex (initially -1)
        vector<int> visited(V, false); // To keep track of visited nodes
        int result = 0; // Variable to store the result (0 means no bridge, 1 means it's a bridge)
        
        vector<vector<int>> adjacencyList(V); // Adjacency list to represent the graph
        
        // Build the adjacency list from the given edge list
        for(int i = 0; i < V; i++){
            for(auto& vertex : adj[i]){
                adjacencyList[i].push_back(vertex);
            }
        }
        
        // Perform DFS from every unvisited node
        for(int i = 0; i < V; i++) 
            if(!visited[i]) 
                dfs(i, -1, 0, result, visited, disc, low, adjacencyList, c, d);
        
        return result; // Return 1 if the edge (c, d) is a bridge, else return 0
    }
};

```

## Problem Solution Explanation
This code implements the solution to the problem of checking whether a given edge `(c, d)` is a **bridge** in an undirected graph using **Depth-First Search (DFS)**. A bridge, or cut-edge, is an edge that, if removed, will disconnect the graph. Let's break down this code step-by-step, explaining the logic and how it works.

### **Class Declaration**

```cpp
class Solution {
```
- The code starts by defining a class `Solution`, which will contain the solution to the problem.



### **DFS Helper Function**

```cpp
void dfs(int node, int parent, int timer, int& result, vector<int>& visited, vector<int>& disc, vector<int>& low, vector<vector<int>>& adjacencyList, int c, int d) {
```

- This function performs a **Depth-First Search (DFS)** to explore the graph and find whether a given edge `(c, d)` is a bridge.
- **Parameters:**
  - `node`: The current node being visited in the DFS.
  - `parent`: The parent of the current node in the DFS tree.
  - `timer`: A timer to assign discovery times to nodes.
  - `result`: The result, which is set to `1` if the edge `(c, d)` is a bridge, otherwise remains `0`.
  - `visited`: A vector to track whether a node has been visited during DFS.
  - `disc`: Discovery times of nodes.
  - `low`: Lowest discovery times reachable from a node.
  - `adjacencyList`: Adjacency list representing the graph.
  - `c` and `d`: The two vertices representing the edge to be checked.

```cpp
    visited[node] = true;                 // Mark the current node as visited
    disc[node] = low[node] = timer++;     // Set discovery time and low time of the node
```
- `visited[node] = true`: Marks the current `node` as visited.
- `disc[node] = low[node] = timer++`: Sets the discovery time (`disc[node]`) and low time (`low[node]`) of the node to the current timer value. The `timer++` increments the timer for the next node.



### **Loop Over Adjacent Vertices**

```cpp
    for(int vertex : adjacencyList[node]) {
        if(vertex == parent) continue;  // Skip the parent node to avoid going backward in the DFS
```

- The function then loops over all vertices adjacent to the current node (`node`) from the `adjacencyList`. The variable `vertex` is each adjacent vertex to the `node`.
- The `if(vertex == parent)` condition ensures that the DFS does not go backward to the parent node, which is a common mechanism in DFS to avoid revisiting the parent node.



### **Handling Unvisited Neighbors**

```cpp
        if(!visited[vertex]) {  // If the neighbor is unvisited, perform DFS on it
            dfs(vertex, node, timer, result, visited, disc, low, adjacencyList, c, d);
            low[node] = min(low[node], low[vertex]); // Update the low time of the current node
```

- `if(!visited[vertex])`: If the adjacent vertex `vertex` has not been visited, the function recurses into `dfs(vertex, node, timer, ...)` to perform DFS on `vertex`. The current node (`node`) is passed as the parent of `vertex`.
- `low[node] = min(low[node], low[vertex])`: After the recursive DFS call, the low value of the current node is updated. It’s the minimum of the current low value (`low[node]`) and the low value of the adjacent node (`low[vertex]`). This step helps track the lowest discovery time reachable from the current node.



### **Check for Bridge Condition**

```cpp
            if(low[vertex] > disc[node] && ((node == c && vertex == d) || (node == d && vertex == c)))
                result = 1;
```

- **Bridge Condition**: The critical part of the DFS:
  - If `low[vertex] > disc[node]`, this means that there is no back edge from the subtree rooted at `vertex` that can reach any ancestor of `node`. In other words, removing the edge `(node, vertex)` will disconnect the graph, making it a bridge.
  - The condition `((node == c && vertex == d) || (node == d && vertex == c))` checks if the edge being considered is the target edge `(c, d)`. If it is, we set `result = 1`, indicating that `(c, d)` is a bridge.



### **Handling Already Visited Neighbors**

```cpp
        } else {
            low[node] = min(low[node], disc[vertex]); // Update the low time if the neighbor is already visited
        }
    }
```

- If the neighbor `vertex` has already been visited, the function updates the low value of the current node (`low[node]`) with the discovery time of `vertex` (`disc[vertex]`). This is done to account for the possibility of back edges, where a node can reach an earlier node (an ancestor) via a different path.



### **Main Function: `isBridge`**

```cpp
int isBridge(int V, vector<int> adj[], int c, int d) {
    vector<int> disc(V, -1); // Discovery time for each vertex (initially -1, indicating unvisited)
    vector<int> low(V, -1);  // Lowest discovery time reachable from the vertex (initially -1)
    vector<int> visited(V, false); // To keep track of visited nodes
    int result = 0; // Variable to store the result (0 means no bridge, 1 means it's a bridge)
```

- **Variables Initialization**:
  - `disc(V, -1)`: Initializes the discovery time array to `-1` (indicating unvisited nodes).
  - `low(V, -1)`: Initializes the low value array to `-1` (no low value calculated yet).
  - `visited(V, false)`: Keeps track of visited nodes during DFS, initialized to `false`.
  - `result = 0`: Initially, the edge `(c, d)` is assumed not to be a bridge.



### **Building the Adjacency List**

```cpp
    vector<vector<int>> adjacencyList(V); // Adjacency list to represent the graph
    for(int i = 0; i < V; i++) {
        for(auto& vertex : adj[i]) {
            adjacencyList[i].push_back(vertex);
        }
    }
```

- This code constructs the **adjacency list** for the graph using the given adjacency list `adj`. This list represents the graph, where `adj[i]` contains the adjacent vertices of vertex `i`.



### **Calling DFS from Every Unvisited Node**

```cpp
    for(int i = 0; i < V; i++) 
        if(!visited[i]) 
            dfs(i, -1, 0, result, visited, disc, low, adjacencyList, c, d);
```

- A DFS is performed starting from every unvisited node in the graph. The parent of the starting node is passed as `-1`, and the initial timer value is `0`. If an edge `(c, d)` is a bridge, `result` will be set to `1`.



### **Returning the Result**

```cpp
    return result; // Return 1 if the edge (c, d) is a bridge, else return 0
}
```

- After the DFS completes, the function returns the value of `result`. If the edge `(c, d)` was found to be a bridge, `result` will be `1`; otherwise, it will remain `0`.

### Example Output
Consider a simple graph with 5 vertices and the following edges:

- Vertices: `0, 1, 2, 3, 4`
- Edges: `(0, 1), (1, 2), (2, 3), (3, 4), (1, 3)`

We want to check if the edge `(1, 3)` is a bridge.

#### Graph Representation:

```
    0 - 1 - 2 - 3 - 4
         \   /
          1
```

### **Steps**:

1. **Initialization**:
   - We initialize the arrays `disc[]`, `low[]`, and `visited[]` as follows:
     - `disc[] = [-1, -1, -1, -1, -1]` (all nodes are unvisited initially).
     - `low[] = [-1, -1, -1, -1, -1]` (no low values initially).
     - `visited[] = [false, false, false, false, false]` (no nodes are visited initially).
   
2. **DFS Traversal**:
   - We start DFS from node `0`:
     - `disc[0] = 0`, `low[0] = 0`.
     - Visit node `1`: `disc[1] = 1`, `low[1] = 1`.
     - Visit node `2`: `disc[2] = 2`, `low[2] = 2`.
     - Visit node `3`: `disc[3] = 3`, `low[3] = 3`.
     - Visit node `4`: `disc[4] = 4`, `low[4] = 4`.
   - At this point, we finish visiting all the nodes.
   
3. **Bridge Condition Check**:
   - For edge `(1, 3)`, after finishing DFS on node `3`, we find that `low[3] > disc[1]` (because `low[3] = 4` and `disc[1] = 1`), so this edge is a bridge.
   - The function sets `result = 1` to indicate that `(1, 3)` is a bridge.

### **Output**:
```
1
```

This indicates that the edge `(1, 3)` is indeed a bridge in the graph.



### **Example 2:**

Consider a different graph with 4 vertices and the following edges:

- Vertices: `0, 1, 2, 3`
- Edges: `(0, 1), (1, 2), (2, 3), (1, 3)`

We want to check if the edge `(1, 3)` is a bridge.

#### Graph Representation:

```
    0 - 1 - 2
         |   |
         3
```

### **Steps**:

1. **Initialization**:
   - We initialize the arrays `disc[]`, `low[]`, and `visited[]` as follows:
     - `disc[] = [-1, -1, -1, -1]`.
     - `low[] = [-1, -1, -1, -1]`.
     - `visited[] = [false, false, false, false]`.
   
2. **DFS Traversal**:
   - Start DFS from node `0`:
     - `disc[0] = 0`, `low[0] = 0`.
     - Visit node `1`: `disc[1] = 1`, `low[1] = 1`.
     - Visit node `2`: `disc[2] = 2`, `low[2] = 2`.
     - Visit node `3`: `disc[3] = 3`, `low[3] = 3`.
   - At this point, we finish visiting all nodes.
   
3. **Bridge Condition Check**:
   - For edge `(1, 3)`, after finishing DFS on node `3`, we find that `low[3] <= disc[1]` (because `low[3] = 3` and `disc[1] = 1`), meaning it is **not** a bridge because there is a back edge between nodes `1` and `3`.

### **Output**:
```
0
```

This indicates that the edge `(1, 3)` is **not** a bridge in the graph.



### **Summary of Outputs**:
- For **Example 1**, the edge `(1, 3)` **is a bridge**, so the output is `1`.
- For **Example 2**, the edge `(1, 3)` **is not a bridge**, so the output is `0`.

The result is either `1` (if the edge is a bridge) or `0` (if the edge is not a bridge).

### **Summary of Logic**
1. The DFS traversal explores each node and its neighbors.
2. The `disc[]` array tracks the discovery times of the nodes, and `low[]` tracks the lowest reachable discovery time from the node.
3. If there is no back edge from the subtree rooted at `vertex` to an ancestor of `node`, then `(node, vertex)` is a bridge.
4. The edge `(c, d)` is specifically checked, and the result is updated if it's a bridge.

### **Time and Space Complexity**
- **Time Complexity**: \(O(V + E)\), where `V` is the number of vertices and `E` is the number of edges, since we perform DFS, which explores each vertex and edge exactly once.
- **Space Complexity**: \(O(V + E)\), due to the adjacency list and additional arrays (`disc[]`, `low[]`, `visited[]`).

This solution efficiently checks if the edge `(c, d)` is a bridge in the graph using DFS and is optimal for typical graph traversal problems.
