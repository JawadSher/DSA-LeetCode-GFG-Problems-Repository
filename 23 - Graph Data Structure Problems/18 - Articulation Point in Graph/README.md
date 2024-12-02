<h1 align='center'>Articulation - Point in - Graph</h1>

## Problem Statement

**Problem URL :** [Articulation Point in Graph](https://www.geeksforgeeks.org/problems/articulation-point-1/1)

![image](https://github.com/user-attachments/assets/7ab7fe92-39a5-4470-9538-60a30982168e)
![image](https://github.com/user-attachments/assets/989e5619-5177-414a-a438-2d438658a8ba)
![image](https://github.com/user-attachments/assets/f1740e51-5670-4c7b-9516-94a47725c990)
![image](https://github.com/user-attachments/assets/33c9262f-7550-42ae-90b4-cda2384e7340)

## Problem Explanation

An **articulation point** (or **cut vertex**) in a graph is a vertex that, when removed (along with all edges connected to it), increases the number of connected components in the graph. These points are critical because their removal disrupts the connectivity of the graph.

### **Problem Statement**

Given an **undirected graph**, identify all articulation points. If no articulation points exist, return `{-1}`.

### **Why Are Articulation Points Important?**

- In **networks**, articulation points represent critical nodes. If removed, they can disrupt communication between other nodes.
- **Real-world examples**:
  - In the internet, articulation points are servers whose failure can disrupt connectivity.
  - In transportation networks, they are key junctions or bridges.

### **Definitions for Understanding**

1. **Connected Graph**:
   - A graph is connected if there is a path between every pair of vertices.

2. **Articulation Point**:
   - A vertex is an articulation point if removing it increases the number of connected components.

### **Examples**

#### **Example 1: Simple Graph**
**Graph**:
```
    0
    |
    1
   / \
  2   3
```

**Observation**:
- If node `1` is removed:
  - The graph splits into two disconnected components: `{0}` and `{2, 3}`.
- Nodes `0`, `2`, and `3` do not disconnect the graph when removed.

**Articulation Point**: `1`

#### **Example 2: Graph with Bridges**
**Graph**:
```
    0 - 1 - 2
        |
        3
```

**Observation**:
- Node `1`:
  - Removing `1` disconnects the graph into three components: `{0}`, `{2}`, `{3}`.
- Nodes `0`, `2`, and `3` do not disconnect the graph.

**Articulation Point**: `1`

#### **Example 3: Graph with Multiple Articulation Points**
**Graph**:
```
        1
      /   \
     0     2
           | \
           3  4
```

**Observation**:
- Node `2`:
  - Removing `2` splits the graph into `{0, 1}` and `{3, 4}`.
- Node `1`:
  - Removing `1` leaves `{0}` disconnected from the rest of the graph.

**Articulation Points**: `1`, `2`

#### **Example 4: Fully Connected Graph**
**Graph**:
```
    01
    | \ |
    23
```

**Observation**:
- No matter which node is removed, the graph remains connected. Each node has multiple paths to every other node.

**Articulation Points**: `{-1}` (No articulation points)

### **How to Identify Articulation Points**

1. **DFS Tree and Back Edges**:
   - Use Depth First Search (DFS) to build a tree structure of the graph.
   - Back edges help identify connections to ancestors.

2. **Conditions for Articulation Points**:
   - A **root node** in the DFS tree is an articulation point if it has more than one child.
   - Any **other node** is an articulation point if:
     - There exists a child `C` such that no vertex in the subtree rooted at `C` has a back edge to an ancestor of the node.
       
### **Key Intuition**

- Articulation points are the "weak links" in the graph. By systematically exploring the graph (e.g., using DFS), you can determine which nodes play a critical role in maintaining connectivity.

## Problem Solution
```cpp
class Solution {
  public:
    // Depth First Search to find articulation points
    void DFS(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<int>& visited, vector<int>& AP, vector<vector<int>>& adjacencyList) {
        visited[node] = true;  // Mark the node as visited
        disc[node] = low[node] = timer++;  // Assign discovery time and initialize low
        int child = 0;  // Count of children in DFS tree

        // Traverse all neighbors of the current node
        for (auto neighbour : adjacencyList[node]) {
            if (neighbour == parent) continue;  // Skip the parent node

            if (!visited[neighbour]) {  // If the neighbor is not visited
                DFS(neighbour, node, timer, disc, low, visited, AP, adjacencyList);  // Recursively visit
                low[node] = min(low[node], low[neighbour]);  // Update low value for the current node

                // Check articulation point condition
                if (low[neighbour] >= disc[node] && parent != -1) {
                    if (find(AP.begin(), AP.end(), node) == AP.end()) AP.push_back(node);
                }
                child++;
            } else {
                low[node] = min(low[node], disc[neighbour]);  // Update low value if back edge exists
            }
        }

        // Check root node condition
        if (parent == -1 && child > 1) {
            if (find(AP.begin(), AP.end(), node) == AP.end()) AP.push_back(node);
        }
    }

    // Main function to find articulation points
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> disc(V, -1);  // Discovery times
        vector<int> low(V, -1);   // Lowest discovery times
        vector<int> visited(V, false);  // Visited nodes
        vector<int> AP;  // Articulation points
        int timer = 0;  // Timer to assign discovery times
        vector<vector<int>> adjacencyList(V);

        // Convert adjacency list
        for (int i = 0; i < V; i++) {
            for (auto neighbour : adj[i]) adjacencyList[i].push_back(neighbour);
        }

        // Perform DFS for all connected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, -1, timer, disc, low, visited, AP, adjacencyList);
            }
        }

        // If no articulation points found, return {-1}
        if (AP.empty()) AP.push_back(-1);
        else sort(AP.begin(), AP.end());  // Sort the articulation points

        return AP;
    }
};

```

## Problem Solution Explanation

The provided code aims to find articulation points (critical nodes) in an undirected graph. Here's the detailed explanation with code and examples:

### **DFS Function: `DFS`**

This function is the heart of the algorithm, where Depth First Search (DFS) is performed.

#### Code:

```cpp
void DFS(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, vector<int>& visited, vector<int>& AP, vector<vector<int>>& adjacencyList) {
```

- **Purpose**: To explore all nodes using DFS and determine if the current node is an articulation point.
- **Parameters**:
  - `node`: The current node being processed.
  - `parent`: The parent of the current node in the DFS tree.
  - `timer`: A reference to the discovery time counter.
  - `disc`: Stores discovery times of nodes.
  - `low`: Tracks the smallest discovery time reachable from a node.
  - `visited`: Marks nodes as visited or not.
  - `AP`: A vector to store articulation points.
  - `adjacencyList`: The graph in adjacency list format.



#### Code:

```cpp
visited[node] = true;  // Mark the node as visited
disc[node] = low[node] = timer++;  // Assign discovery time and initialize low
int child = 0;  // Count of children in DFS tree
```

- **Explanation**:
  - Mark the current `node` as visited.
  - Set its discovery time (`disc[node]`) and initialize the `low[node]` value to the current timer, then increment the timer.
  - Initialize `child` to track the number of children in the DFS tree.



#### Code:

```cpp
for (auto neighbour : adjacencyList[node]) {
```

- **Explanation**:
  - Iterate over all neighbors of the current node from the adjacency list.



#### Code:

```cpp
if (neighbour == parent) continue;  // Skip the parent node
```

- **Explanation**:
  - Skip the edge back to the parent node to avoid revisiting it.



#### Code:

```cpp
if (!visited[neighbour]) {  // If the neighbor is not visited
    DFS(neighbour, node, timer, disc, low, visited, AP, adjacencyList);  // Recursively visit
    low[node] = min(low[node], low[neighbour]);  // Update low value for the current node
```

- **Explanation**:
  - If the neighbor is not visited, recursively call `DFS` for that neighbor.
  - Update the `low[node]` value as the minimum of its current `low[node]` and the `low` value of the neighbor.



#### Code:

```cpp
if (low[neighbour] >= disc[node] && parent != -1) {
    if (find(AP.begin(), AP.end(), node) == AP.end()) AP.push_back(node);
}
```

- **Explanation**:
  - If the `low[neighbour]` is greater than or equal to `disc[node]` and the current node is **not the root**, it is an articulation point.
  - Add the node to the `AP` list if it is not already present.



#### Code:

```cpp
child++;
} else {
    low[node] = min(low[node], disc[neighbour]);  // Update low value if back edge exists
}
```

- **Explanation**:
  - Increment the `child` count for each DFS branch.
  - If the neighbor is already visited (back edge), update the `low[node]` value using the neighbor's discovery time.



#### Code:

```cpp
if (parent == -1 && child > 1) {
    if (find(AP.begin(), AP.end(), node) == AP.end()) AP.push_back(node);
}
```

- **Explanation**:
  - If the current node is the **root** and has more than one child, it is an articulation point.



### **Main Function: `articulationPoints`**

This function initializes all necessary data structures and starts the DFS process for each component.

#### Code:

```cpp
vector<int> articulationPoints(int V, vector<int> adj[]) {
```

- **Purpose**: To manage the graph traversal and collect articulation points.
- **Parameters**:
  - `V`: The number of vertices in the graph.
  - `adj[]`: The adjacency list representation of the graph.



#### Code:

```cpp
vector<int> disc(V, -1);  // Discovery times
vector<int> low(V, -1);   // Lowest discovery times
vector<int> visited(V, false);  // Visited nodes
vector<int> AP;  // Articulation points
int timer = 0;  // Timer to assign discovery times
vector<vector<int>> adjacencyList(V);
```

- **Explanation**:
  - `disc` and `low` are initialized to `-1` for all nodes.
  - `visited` is initialized to `false` for all nodes.
  - `AP` stores the articulation points found during DFS.
  - `timer` keeps track of discovery times.



#### Code:

```cpp
for (int i = 0; i < V; i++) {
    for (auto neighbour : adj[i]) adjacencyList[i].push_back(neighbour);
}
```

- **Explanation**:
  - Converts the adjacency list from `adj[]` to a `vector<vector<int>>` format.



#### Code:

```cpp
for (int i = 0; i < V; i++) {
    if (!visited[i]) {
        DFS(i, -1, timer, disc, low, visited, AP, adjacencyList);
    }
}
```

- **Explanation**:
  - Perform DFS for each unvisited node, treating it as the root of a new component.



#### Code:

```cpp
if (AP.empty()) AP.push_back(-1);
else sort(AP.begin(), AP.end());
return AP;
```

- **Explanation**:
  - If no articulation points are found, return `{-1}`.
  - Otherwise, sort the articulation points and return the list.



### **Example**

#### Input:
```plaintext
Graph with 5 nodes:
0 -- 1 -- 2
|         |
3 - 4
```

#### Execution:

1. Start DFS from node `0` with `timer = 0`.
2. Compute `disc[]` and `low[]` for all nodes.
3. Identify articulation points:
   - Node `1` and `3` are articulation points.

#### Output:
```plaintext
[1, 3]
```



### **Time Complexity**

- **DFS Traversal**: \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.
- **Articulation Point Check**: \(O(V)\).

**Total**: \(O(V + E)\).



### **Space Complexity**

- **Auxiliary Space**: \(O(V)\) for `disc`, `low`, `visited`, and adjacency list.
- **Recursion Stack**: \(O(V)\).

**Total**: \(O(V)\).
