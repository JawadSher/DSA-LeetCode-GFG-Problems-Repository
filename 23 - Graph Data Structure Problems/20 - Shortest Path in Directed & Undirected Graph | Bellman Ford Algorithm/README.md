<h1 align='center'>Shortest - Path | Bellman - Ford - Algorithm</h1>

## Problem Statement

**Problem URL :** [Billman Ford](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

![image](https://github.com/user-attachments/assets/79015840-d5a8-4d3e-841b-83147d9cdf7b)
![image](https://github.com/user-attachments/assets/a5ad3f23-e6b3-4d6c-bb45-13d972c16914)

## Problem Explanation
This problem requires you to calculate the shortest distance from a source vertex to all other vertices in a graph using the **Bellman-Ford algorithm**. The graph may contain edges with **negative weights**, but no negative weight cycles.

#### **Input:**
- V: Number of vertices in the graph.
- edges: List of edges, where each edge is represented as ([u, v, w]). u is the source vertex, v is the destination vertex, and w is the weight of the edge.
- src: The source vertex from which distances are calculated.

#### **Output:**
- A list of shortest distances from the source vertex to every other vertex. If a vertex is not reachable, its distance is 10^8.
- If a negative weight cycle exists, the function should return ([-1]).



### **Examples**

#### Example 1:
**Input:**
```
V = 5
edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}}
src = 0
```

**Output:**
```
[0, -1, 2, -2, 1]
```

**Explanation:**
- The shortest path from 0 to 1 is -1.
- The shortest path from 0 to 2 is 2.
- The shortest path from 0 to 3 is -2.
- The shortest path from 0 to 4 is 1.

#### Example 2:
**Input:**
```
V = 3
edges = {{0, 1, 4}, {1, 2, -10}, {2, 1, 3}}
src = 0
```

**Output:**
```
[-1]
```

**Explanation:**
- The graph contains a negative weight cycle involving vertices 1 and 2, so the result is ([-1]).



### **Bellman-Ford Algorithm**

The **Bellman-Ford Algorithm** is used to find the shortest paths from a single source vertex to all vertices in a weighted graph. It works for graphs with negative weights and detects negative weight cycles. This is why it is used instead of Dijkstra's algorithm in certain cases.



#### **Steps in Bellman-Ford Algorithm**

1. **Initialization**:
   - Initialize the distance of the source vertex to 0 and all other vertices to infinity (10^8).

2. **Relaxation**:
   - Iterate V-1 times (where V is the number of vertices). For each edge (u, v, w), check if the current distance to v can be minimized:
     - If distance[u] + w < distance[v], update distance[v] = distance[u] + w.

3. **Negative Cycle Detection**:
   - After V-1 iterations, run one more iteration over all edges to detect negative weight cycles. If any edge (u, v, w) can still be relaxed, it indicates a negative weight cycle.



### **Why Use Bellman-Ford Instead of Dijkstra's Algorithm?**

1. **Handling Negative Weights**:
   - Dijkstra’s algorithm fails when there are negative weight edges because it assumes once a vertex’s shortest path is found, it does not change. However, with negative weights, a shorter path might still exist later.

2. **Negative Weight Cycle Detection**:
   - Bellman-Ford can detect negative weight cycles, while Dijkstra’s algorithm cannot.

3. **Use Case**:
   - Bellman-Ford is ideal when negative weights or cycles might exist, such as in financial graphs (currency exchange rates), road networks, or other situations where weights can decrease.



### **Example: Bellman-Ford Algorithm**

#### Graph:
Vertices: 4  
Edges:  
[
{(0, 1, 1), (1, 2, 3), (2, 3, -6), (3, 1, 2)}
]  
Source: 0



#### **Step 1: Initialization**
```
distance = [0, ∞, ∞, ∞]
```



#### **Step 2: Relaxation (3 iterations)**

1. **First Iteration**:
   ```
   Relax (0 -> 1): distance[1] = 0 + 1 = 1
   Relax (1 -> 2): distance[2] = 1 + 3 = 4
   Relax (2 -> 3): distance[3] = 4 - 6 = -2
   ```
   Updated distances: `[0, 1, 4, -2]`

2. **Second Iteration**:
   ```
   Relax (3 -> 1): distance[1] = -2 + 2 = 0
   ```
   Updated distances: `[0, 0, 4, -2]`

3. **Third Iteration**:
   ```
   Relax (1 -> 2): distance[2] = 0 + 3 = 3
   Relax (2 -> 3): distance[3] = 3 - 6 = -3
   ```
   Updated distances: `[0, 0, 3, -3]`



#### **Step 3: Negative Cycle Detection**

Run one more iteration:
```
Relax (3 -> 1): distance[1] = -3 + 2 = -1
```

Since further relaxation is possible, a **negative weight cycle** exists.

**Output**: `[-1]`


## Directed Graph Solution
```cpp
class Solution {
  public:
    /* Function to implement Bellman-Ford Algorithm
     * Parameters:
     * V: Number of vertices in the graph
     * edges: A vector of vectors where each sub-vector represents an edge in the format [source, destination, weight]
     * src: Source vertex from which shortest distances are calculated
     * Returns:
     * A vector of shortest distances from the source to all vertices. 
     * If a negative-weight cycle is detected, returns [-1].
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Step 1: Initialize the distances to all vertices as a very large number (infinity)
        // Use 100000000 as the value for "infinity" as per the problem constraints
        int n = 100000000;
        vector<int> distance(V, n); // Distance array initialized to "infinity"
        distance[src] = 0; // Distance to the source vertex is 0

        // Step 2: Relax all edges (V-1) times
        // Iterate (V-1) times because the shortest path in a graph with V vertices can have at most (V-1) edges
        for (int i = 0; i < V - 1; i++) {
            // Traverse through all edges
            for (auto edge : edges) {
                int source = edge[0];       // Source vertex of the edge
                int destination = edge[1]; // Destination vertex of the edge
                int weight = edge[2];      // Weight of the edge

                // Relax the edge if the source distance is not infinity and the new path is shorter
                if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                    distance[destination] = distance[source] + weight; // Update the shortest distance
                }
            }
        }

        // Step 3: Check for negative-weight cycles
        // A negative-weight cycle exists if we can still relax any edge after (V-1) iterations
        for (auto edge : edges) {
            int source = edge[0];       // Source vertex of the edge
            int destination = edge[1]; // Destination vertex of the edge
            int weight = edge[2];      // Weight of the edge

            // If the edge can still be relaxed, a negative-weight cycle exists
            if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                return vector<int>(1, -1); // Return [-1] to indicate a negative-weight cycle
            }
        }

        // Step 4: Return the calculated shortest distances from the source vertex
        return distance;
    }
};
```

### Problem Solution Explanation

#### **Initialization**
```cpp
int n = 100000000; // Define a large value as "infinity."
vector<int> distance(V, n); // Initialize distances to all vertices as infinity.
distance[src] = 0; // Distance to the source is 0.
```

**Explanation**:
- A `distance` array is initialized to store the shortest distances from the source.
- All distances are initially set to a large value ((10^8)), except for the source, which is set to 0.

**Example**:
For V = 4 and source src = 0:
- Initial `distance` array: `[0, 100000000, 100000000, 100000000]`.



#### **Relax All Edges V-1 Times**
```cpp
for (int i = 0; i < V - 1; i++) { // Iterate (V-1) times.
    for (auto edge : edges) { // Traverse all edges.
        int source = edge[0]; // Source vertex of the edge.
        int destination = edge[1]; // Destination vertex of the edge.
        int weight = edge[2]; // Weight of the edge.

        // Relax the edge if a shorter path is found.
        if (distance[source] != n && (distance[source] + weight < distance[destination])) {
            distance[destination] = distance[source] + weight;
        }
    }
}
```

**Explanation**:
- For each edge ([u, v, w]), if the path from u to v via w is shorter than the current distance to v, update it.
- Perform this relaxation for all edges V-1 times because the shortest path in a graph with V vertices can have at most V-1 edges.

**Example**:
Graph edges:  
[
{Edges} = [[0, 1, 1], [1, 2, 3], [0, 2, 4]]
]  
After each iteration:  
1. Iteration 1: Relax edge ([0, 1, 1]), ([1, 2, 3]), ([0, 2, 4]):  
   `distance = [0, 1, 4, 100000000]`.  
2. Iteration 2: No further updates.



#### **Check for Negative-Weight Cycles**
```cpp
for (auto edge : edges) {
    int source = edge[0];
    int destination = edge[1];
    int weight = edge[2];

    // If a shorter path is still found, it indicates a negative cycle.
    if (distance[source] != n && (distance[source] + weight < distance[destination])) {
        return vector<int>(1, -1); // Return [-1] to indicate negative cycle.
    }
}
```

**Explanation**:
- If an edge can still be relaxed after V-1 iterations, a negative-weight cycle exists.

**Example**:
Graph edges:  
[
{Edges} = [[0, 1, 1], [1, 2, -3], [2, 1, -3]]
]  
- After V-1 iterations, further relaxation shows a negative-weight cycle involving edges ([1, 2, -3]) and ([2, 1, -3]).



#### **Return the Result**
```cpp
return distance; // Return shortest distances from the source.
```

**Example Output**:
For the graph without negative-weight cycles:  
[
{Edges} = [[0, 1, 1], [1, 2, 3], [0, 2, 4]]
]  
- Output: `[0, 1, 4]`.

For the graph with a negative-weight cycle:  
[
{Edges} = [[0, 1, 1], [1, 2, -3], [2, 1, -3]]
]  
- Output: `[-1]`.



### **Time Complexity**
1. **Initialization**: O(V).
2. **Edge Relaxation**: O(V times E), as we relax E edges for V-1 iterations.
3. **Negative-Weight Cycle Check**: O(E).

**Overall**:  
[
O(V times E)
]  



### **Space Complexity**
- **Distance Array**: O(V).

**Overall**:  
[
O(V)
]  


## Undirected Graph Solution
```cpp
class Solution {
  public:
    /* Function to implement Bellman-Ford Algorithm for an undirected graph
     * Parameters:
     * V: Number of vertices in the graph
     * edges: A vector of vectors where each sub-vector represents an edge in the format [source, destination, weight]
     * src: Source vertex from which shortest distances are calculated
     * Returns:
     * A vector of shortest distances from the source to all vertices. 
     * If a negative-weight cycle is detected, returns [-1].
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int n = 100000000; // Representing infinity
        vector<int> distance(V, n); // Distance array initialized to "infinity"
        distance[src] = 0; // Distance to the source vertex is 0

        // Step 1: Preprocess the edges to handle the undirected graph
        vector<vector<int>> undirectedEdges;
        for (auto edge : edges) {
            // Add both directions for the undirected graph
            undirectedEdges.push_back({edge[0], edge[1], edge[2]}); // (u -> v)
            undirectedEdges.push_back({edge[1], edge[0], edge[2]}); // (v -> u)
        }

        // Step 2: Relax all edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto edge : undirectedEdges) {
                int source = edge[0];
                int destination = edge[1];
                int weight = edge[2];

                // Relax the edge if the source distance is not infinity and the new path is shorter
                if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                    distance[destination] = distance[source] + weight;
                }
            }
        }

        // Step 3: Check for negative-weight cycles
        for (auto edge : undirectedEdges) {
            int source = edge[0];
            int destination = edge[1];
            int weight = edge[2];

            // If the edge can still be relaxed, a negative-weight cycle exists
            if (distance[source] != n && (distance[source] + weight < distance[destination])) {
                return vector<int>(1, -1); // Return [-1] to indicate a negative-weight cycle
            }
        }

        // Step 4: Return the calculated shortest distances from the source vertex
        return distance;
    }
};
```

### Problem Solution Explanation

Below is a detailed explanation of the code for solving the **Bellman-Ford Algorithm** for an undirected graph.



### **Code Explanation**

#### **1. Initialization**
```cpp
int n = 100000000; // Representing infinity
vector<int> distance(V, n); // Distance array initialized to "infinity"
distance[src] = 0; // Distance to the source vertex is 0
```

- **Purpose**: To initialize the `distance` array where:
  - All vertices are initially assigned a large value (`infinity`), representing that the shortest distance to them is unknown.
  - The `distance[src]` for the source vertex is set to 0 because the distance to itself is zero.



#### **2. Preprocess Edges for Undirected Graph**
```cpp
vector<vector<int>> undirectedEdges;
for (auto edge : edges) {
    // Add both directions for the undirected graph
    undirectedEdges.push_back({edge[0], edge[1], edge[2]}); // (u -> v)
    undirectedEdges.push_back({edge[1], edge[0], edge[2]}); // (v -> u)
}
```

- **Purpose**: Converts the graph from directed to undirected by creating edges in both directions.
  - For each edge ((u, v, w)), it adds two edges:
    - ((u to v, w))
    - ((v to u, w))
- **Why**: Bellman-Ford assumes directed edges. Since the graph is undirected, this preprocessing ensures both directions are considered.



#### **3. Relax Edges V-1 Times**
```cpp
for (int i = 0; i < V - 1; i++) { // Iterate (V-1) times
    for (auto edge : undirectedEdges) {
        int source = edge[0];
        int destination = edge[1];
        int weight = edge[2];

        // Relax the edge
        if (distance[source] != n && (distance[source] + weight < distance[destination])) {
            distance[destination] = distance[source] + weight;
        }
    }
}
```

- **Purpose**:
  - For V vertices, the shortest path can have at most V-1 edges.
  - This loop iteratively updates the shortest path for all vertices.
- **Relaxation**:
  - Check if the current distance to the source vertex is not infinity (`distance[source] != n`).
  - If traveling via this edge provides a shorter distance, update it.
- **Example**:
  - Input Graph:  
    [
    {Edges} = {(0, 1, 1), (1, 2, 2)}
    ]  
  - Initial Distance: `[0, 100000000, 100000000]`.  
  - Iteration 1:
    - Relax edge ((0, 1, 1)): Distance to 1 = 1.
    - Relax edge ((1, 2, 2)): Distance to 2 = 3.
  - Final Distance: `[0, 1, 3]`.



#### **4. Check for Negative-Weight Cycles**
```cpp
for (auto edge : undirectedEdges) {
    int source = edge[0];
    int destination = edge[1];
    int weight = edge[2];

    // If the edge can still be relaxed
    if (distance[source] != n && (distance[source] + weight < distance[destination])) {
        return vector<int>(1, -1); // Negative cycle detected
    }
}
```

- **Purpose**:
  - After V-1 iterations, if any edge can still be relaxed, it implies a negative-weight cycle exists.
- **Why**:
  - A negative cycle allows an indefinitely smaller path with repeated relaxation.



#### **5. Return the Result**
```cpp
return distance;
```

- **Purpose**: Return the shortest distances from the source vertex to all other vertices.



### **Example Walkthrough**

#### Input:
Graph:
[
{Edges} = {(0, 1, 4), (1, 2, 3), (2, 0, -5)}, V = 3, {src} = 0
]



#### Execution:
1. **Initialization**:
   - Distance: `[0, 100000000, 100000000]`.

2. **Preprocessing** (Undirected Edges):
   - [
   {undirectedEdges} = {(0, 1, 4), (1, 0, 4), (1, 2, 3), (2, 1, 3), (2, 0, -5), (0, 2, -5)}.
   ]

3. **Relaxation**:
   - Iteration 1:
     - Relax ((0, 1, 4)): Distance = `[0, 4, 100000000]`.
     - Relax ((1, 2, 3)): Distance = `[0, 4, 7]`.
     - Relax ((2, 0, -5)): Distance = `[-2, 4, 7]`.

4. **Negative-Weight Cycle Check**:
   - Further relaxation detects the cycle ((0, 1, 4) to (1, 2, 3) to (2, 0, -5)).



#### Output:
[
[-1]
]  
**Explanation**: Negative-weight cycle detected.



### **Time Complexity**
1. **Preprocessing Edges**: O(E), where E is the number of edges.
2. **Relaxation**: O(V times E), as we relax E edges V-1 times.
3. **Negative-Weight Cycle Check**: O(E).

**Overall**:  
[
O(V times E)
]



### **Space Complexity**
1. **Distance Array**: O(V).
2. **Undirected Edges Storage**: O(2 times E) = O(E).

**Overall**:  
[
O(V + E)
]
