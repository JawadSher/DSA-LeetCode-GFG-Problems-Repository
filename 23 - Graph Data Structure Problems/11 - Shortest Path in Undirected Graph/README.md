<h1 align='center'>Shortest - Path in - Undirected - Graph</h1>

## Problem Statement

**Problem URL :** [Shortest Path in Undirected Graph](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

![image](https://github.com/user-attachments/assets/d996625a-666e-430d-ae4f-8aa290548239)
![image](https://github.com/user-attachments/assets/e9678f80-f2ef-40f3-ac14-5e7c3d3568f3)

## Problem Explanation
We are given an **undirected graph** with `N` vertices and `M` edges. The graph is represented by a list of edges, where each edge connects two nodes (vertices) in the graph. Our task is to find the **shortest path** from a given source vertex `src` to all other vertices in the graph. The path length is measured by the number of edges traversed.

#### **Example 1:**
Let's consider an example with 5 vertices (0 to 4) and the following edges:
```
Edges: 
0-1, 0-2, 1-3, 3-4
```
The graph looks like this:

```
  0 -- 1 -- 3 -- 4
   \
    2
```

If the source vertex `src = 0`, the shortest paths from vertex 0 to all other vertices are:
- `0 → 0` (distance 0)
- `0 → 1` (distance 1)
- `0 → 2` (distance 1)
- `0 → 3` (distance 2)
- `0 → 4` (distance 3)

The **shortest path** is the one that uses the least number of edges between the source and each target vertex.

#### **Approach:**
1. **Graph Representation**: We can represent the graph using an adjacency list. Each node will have a list of neighboring nodes it is connected to by an edge.
   
2. **Breadth-First Search (BFS)**: To find the shortest path in an unweighted graph, we use **BFS**. This is because BFS explores all the nodes at the present depth level before moving on to nodes at the next depth level, guaranteeing the shortest path in an unweighted graph.

    - **Why BFS?** BFS explores vertices level by level, ensuring that when we first reach a node, we do so via the shortest possible path.
  
3. **Steps to Approach**:
   - Initialize a distance array to store the shortest distance from the source to each vertex (set all distances to `-1` initially, except for the source which is set to 0).
   - Use a queue to help with BFS. Add the source node to the queue.
   - While the queue is not empty, process each node:
     - For each unvisited neighboring node, update its distance and mark it as visited, then add it to the queue.
   - Continue this process until all nodes have been visited.
   
   **Key Observations**:
   - BFS ensures that the first time we visit a node, we do so via the shortest path.

#### **Example 2:**
Consider a graph with 6 vertices and the following edges:
```
Edges: 
0-1, 0-2, 1-3, 3-4, 2-5
```
```
  0 -- 1 -- 3 -- 4
   \    \
    2 -- 5
```
If the source vertex is `src = 0`, the shortest distances from `0` to all other vertices would be:
- `0 → 0` (distance 0)
- `0 → 1` (distance 1)
- `0 → 2` (distance 1)
- `0 → 3` (distance 2)
- `0 → 4` (distance 3)
- `0 → 5` (distance 3)

## Problem Solution
```cpp
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Step 1: Create an adjacency list to represent the graph
        vector<vector<int>> adj(N);  // Adjacency list with N vertices
        // Build the adjacency list from the given edges
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];  // Start vertex of the edge
            int v = edges[i][1];  // End vertex of the edge
            adj[u].push_back(v);  // Add v as a neighbor of u
            adj[v].push_back(u);  // Add u as a neighbor of v (since the graph is undirected)
        }

        // Step 2: Initialize the distance array and visited array
        vector<int> distance(N, -1);  // Distance array, initialized to -1 (unreachable)
        vector<bool> visited(N, false);  // Visited array, initialized to false
        queue<int> q;  // Queue to store vertices during BFS

        // Step 3: Start BFS from the source node
        distance[src] = 0;  // Distance to the source is 0
        visited[src] = true;  // Mark the source as visited
        q.push(src);  // Add the source node to the queue

        // Step 4: Perform BFS to find the shortest path to all nodes
        while (!q.empty()) {
            int node = q.front();  // Get the front node from the queue
            q.pop();  // Remove the front node from the queue

            // Step 5: Explore all neighbors of the current node
            for (int neighbor : adj[node]) {
                // If the neighbor hasn't been visited, update its distance and mark it as visited
                if (!visited[neighbor]) {
                    visited[neighbor] = true;  // Mark the neighbor as visited
                    distance[neighbor] = distance[node] + 1;  // Update the distance to the neighbor
                    q.push(neighbor);  // Add the neighbor to the queue for further exploration
                }
            }
        }

        // Step 6: Return the final distance array
        return distance;  // Return the array containing the shortest distances from src to all vertices
    }
};

```

## Problem Solution Explanation
Now, let’s break down the given code line by line.

```cpp
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
```
- **Class Definition**: The solution is encapsulated in a class named `Solution`.
- The method `shortestPath` takes:
  - `edges`: A vector of edges representing the graph.
  - `N`: The number of vertices.
  - `M`: The number of edges.
  - `src`: The source vertex from which we need to calculate the shortest paths to all other vertices.

```cpp
        vector<vector<int>> adj(N);
```
- **Adjacency List**: An adjacency list `adj` is created to represent the graph. It is a 2D vector where `adj[i]` stores all the nodes connected to vertex `i`.

```cpp
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
```
- **Building the Graph**: Loop through each edge. For each edge `(u, v)`, add `v` to `adj[u]` and `u` to `adj[v]`. This creates an undirected graph by adding both directions for each edge.

```cpp
        vector<int> distance(N, -1);
        vector<bool> visited(N, false);
        queue<int> q;
```
- **Distance Array**: `distance[i]` stores the shortest distance from `src` to vertex `i`. It is initialized to `-1` to signify that no vertex has been visited yet.
- **Visited Array**: `visited[i]` indicates whether vertex `i` has been visited. It is initially set to `false` for all vertices.
- **Queue**: A queue `q` is initialized to help with BFS traversal.

```cpp
        distance[src] = 0;
        visited[src] = true;
        q.push(src);
```
- **Initialization**: The distance of the source vertex `src` is set to 0. We mark it as visited and add it to the queue.

```cpp
        while (!q.empty()) {
            int node = q.front();
            q.pop();
```
- **BFS Loop**: While the queue is not empty, we process the front node of the queue.

```cpp
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
```
- **Processing Neighbors**: For each unvisited neighbor of the current node:
  - Mark it as visited.
  - Set its distance to the current node's distance + 1.
  - Add the neighbor to the queue.

```cpp
        return distance;
    }
};
```
- **Return Result**: After processing all nodes, the `distance` array is returned, which contains the shortest distances from the source to all other vertices.

### **Step 3: Example Walkthrough**

Let’s use the graph from Example 1:

```
  0 -- 1 -- 3 -- 4
   \
    2
```

#### Input:
```
edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}}
N = 5, M = 4, src = 0
```

1. **Graph Representation**:
   The adjacency list `adj` will look like:
   ```
   adj = {{1, 2}, {0, 3}, {0}, {1, 4}, {3}}
   ```

2. **BFS Execution**:
   - `distance = {0, -1, -1, -1, -1}` (initial distances, with `src = 0` set to 0)
   - `visited = {true, false, false, false, false}` (only `src = 0` visited initially)
   - Start BFS:
     - **Process node 0**: Visit neighbors 1 and 2. Update their distances to 1.
     - **Process node 1**: Visit neighbor 3. Update its distance to 2.
     - **Process node 2**: Visit neighbor 5. Update its distance to 3.
     - **Process node 3**: Visit neighbor 4. Update its distance to 3.
     - **Process node 4**: End.
     
3. **Final Output**: 
   ```
   distance = {0, 1, 1, 2, 3}
   ```

#### Output:
```
The shortest paths from vertex 0 to all other vertices are: 0 1 1 2 3
```

### **Step 4: Time and Space Complexity**

#### **Time Complexity**:
- **Graph Construction**: \(O(M)\), where `M` is the number of edges. This is because we process each edge once.
- **BFS Traversal**: \(O(V + M)\), where `V` is the number of vertices and `M` is the number of edges. We process each vertex and each edge at most once.
- **Total Time Complexity**: \(O(V + M)\)

#### **Space Complexity**:
- **Adjacency List**: \(O(V + M)\) space is used for the adjacency list.
- **Distance Array**: \(O(V)\)
- **Visited Array**: \(O(V)\)
- **Queue**: \(O(V)\) in the worst case.
- **Total Space Complexity**: \(O(V + M)\)

### **Step 5: Additional Recommendations**
1. **Handling Multiple Components**: If the graph has multiple disconnected components, BFS will only find the shortest path within the component containing the source. If you need to handle disconnected graphs, consider adding extra logic to

 mark unreachable nodes or run BFS for each disconnected component.
2. **Edge Cases**: 
   - If there are no edges (`M = 0`), all distances except for the source should remain `-1`.
   - Ensure that `src` is always a valid vertex in the range `[0, N-1]`.
