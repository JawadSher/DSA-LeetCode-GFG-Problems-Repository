<h1 align='center'>Topological - Sort - Using - Kahn's Algorithm</h1>

## Problem Statement
#### **What is Topological Sort?**

Topological sort is a linear ordering of vertices in a **Directed Acyclic Graph (DAG)** such that for every directed edge `U → V`, vertex `U` comes before vertex `V` in the ordering. It is valid only for graphs without cycles (DAG).

#### **Applications:**
1. Task scheduling with dependencies.
2. Course prerequisites (e.g., Course A must be completed before Course B).
3. Dependency resolution in build systems (e.g., linking libraries).



### **Step-by-Step Example**

#### **Graph:**
```
V = 5 (Vertices: 1, 2, 3, 4, 5)
Edges:
1 → 2, 1 → 3, 2 → 5, 3 → 5, 5 → 4
```

#### **Adjacency List Representation:**
```
1 → [2, 3]
2 → [5]
3 → [5]
5 → [4]
```



### **How to Perform Topological Sort (Kahn's Algorithm)?**

Kahn's Algorithm uses **indegree** (number of incoming edges) to determine the processing order of vertices.



### **Kahn's Algorithm: Step-by-Step Explanation**

#### **Approach:**
1. **Calculate Indegree**:
   - Compute the indegree of each vertex. The indegree of a vertex is the count of edges directed toward it.
2. **Initialize Queue**:
   - Push all vertices with indegree `0` (nodes with no dependencies) into a queue.
3. **Process Nodes**:
   - While the queue is not empty:
     1. Remove a vertex from the front of the queue.
     2. Add it to the topological order.
     3. Decrease the indegree of its neighbors by `1`.
     4. If any neighbor's indegree becomes `0`, push it into the queue.
4. **Check for Cycles**:
   - If the topological order does not include all vertices, the graph contains a cycle, and topological sorting is not possible.



#### **Example: Topological Sort Using Kahn’s Algorithm**

**Graph:**
```
1 → [2, 3]
2 → [5]
3 → [5]
5 → [4]
```



**Step 1: Calculate Indegree**
```
Initial indegree:
Vertex 1: 0
Vertex 2: 1
Vertex 3: 1
Vertex 4: 1
Vertex 5: 2
```



**Step 2: Initialize Queue**
```
Queue: [1] (only vertex 1 has indegree 0)
```



**Step 3: Process Nodes**
- Process vertex `1`:
  - Add `1` to topological order.
  - Decrease indegree of its neighbors (`2` and `3`).
  ```
  Topological Order: [1]
  Updated indegree:
  Vertex 2: 0
  Vertex 3: 0
  Vertex 4: 1
  Vertex 5: 2
  Queue: [2, 3]
  ```

- Process vertex `2`:
  - Add `2` to topological order.
  - Decrease indegree of its neighbor (`5`).
  ```
  Topological Order: [1, 2]
  Updated indegree:
  Vertex 3: 0
  Vertex 4: 1
  Vertex 5: 1
  Queue: [3]
  ```

- Process vertex `3`:
  - Add `3` to topological order.
  - Decrease indegree of its neighbor (`5`).
  ```
  Topological Order: [1, 2, 3]
  Updated indegree:
  Vertex 4: 1
  Vertex 5: 0
  Queue: [5]
  ```

- Process vertex `5`:
  - Add `5` to topological order.
  - Decrease indegree of its neighbor (`4`).
  ```
  Topological Order: [1, 2, 3, 5]
  Updated indegree:
  Vertex 4: 0
  Queue: [4]
  ```

- Process vertex `4`:
  - Add `4` to topological order.
  ```
  Topological Order: [1, 2, 3, 5, 4]
  Queue: []
  ```



**Step 4: Verify Result**
- All vertices are included in the topological order.
- Output: `1 2 3 5 4`.

## Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to perform Topological Sort using Kahn's Algorithm
void KahnsAlgorithm(vector<vector<int>>& adj, int V) {
    // Step 1: Initialize the indegree array with zeros
    // indegree[i] will store the number of incoming edges to vertex i
    vector<int> indegree(V, 0);

    // Step 2: Create a queue for processing nodes with indegree 0
    queue<int> q;

    // Step 3: Create a vector to store the topological order of nodes
    vector<int> topoOrder;

    // Step 4: Calculate the indegree for all vertices
    for (int i = 0; i < V; i++) {
        for (int neighbour : adj[i]) {
            indegree[neighbour]++; // Increment indegree of each neighbor
        }
    }

    // Step 5: Add all vertices with indegree 0 to the queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i); // Push vertices with no dependencies into the queue
        }
    }

    // Step 6: Process the vertices in the queue one by one
    while (!q.empty()) {
        int node = q.front(); // Get the vertex at the front of the queue
        q.pop(); // Remove it from the queue

        topoOrder.push_back(node); // Add the vertex to the topological order

        // Step 7: For each neighbor of the current vertex
        for (auto neighbour : adj[node]) {
            indegree[neighbour]--; // Decrease the indegree of the neighbor

            // If the indegree of the neighbor becomes 0, add it to the queue
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    // Step 8: If the topological order contains all vertices, print it
    if (topoOrder.size() != V) {
        // If the size of the topological order is not equal to the number of vertices
        // it means there was a cycle in the graph, and topological sort is not possible
        cout << "The graph is not a DAG. Topological sort not possible.\n";
        return;
    }

    // Step 9: Output the topological sort
    cout << "Topological sorting of the graph: ";
    for (int node : topoOrder) {
        cout << node + 1 << " "; // Print node numbers (1-based indexing)
    }
    cout << endl;
}

int main() {
    // Step 10: Number of vertices (nodes) in the graph
    int V = 5;

    // Step 11: Define the directed edges of the graph
    // Format: {from, to}
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 5}, {3, 5}, {5, 4}};

    // Step 12: Initialize the adjacency list for the graph
    vector<vector<int>> adj(V);

    // Step 13: Convert the edge list to an adjacency list
    // Adjusting for 0-based indexing
    for (auto i : edges) {
        adj[i[0] - 1].push_back(i[1] - 1);
    }

    // Step 14: Call the Kahn's Algorithm function to perform topological sort
    KahnsAlgorithm(adj, V);

    return 0;
}

```

## Problem Solution Explanation

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- Includes all standard C++ libraries.
- **`using namespace std;`** avoids prefixing standard library functions with `std::`.



#### **Function: `KahnsAlgorithm`**

```cpp
void KahnsAlgorithm(vector<vector<int>>& adj, int V) {
    vector<int> indegree(V, 0); // Initialize indegree array
    queue<int> q; // Queue for processing vertices
    vector<int> topoOrder; // Stores the topological order
```

- `indegree`: Tracks the number of incoming edges for each vertex.
- `q`: Queue for processing vertices with `0` indegree.
- `topoOrder`: Stores the final topological order.



```cpp
    for (int i = 0; i < V; i++) {
        for (int neighbour : adj[i]) {
            indegree[neighbour]++; // Calculate indegree for each vertex
        }
    }
```

- Traverses the adjacency list and increments the indegree for each neighbor.

**Example**:
For `1 → [2, 3]`:
- `indegree[2]++` and `indegree[3]++`.



```cpp
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i); // Push vertices with indegree 0 into the queue
    }
```

- Identifies vertices with no dependencies and adds them to the queue.

**Example**:
- Initial `indegree`: `[0, 1, 1, 1, 2]`.
- Queue: `[1]`.



```cpp
    while (!q.empty()) {
        int node = q.front(); // Get the front vertex
        q.pop(); // Remove it from the queue
        topoOrder.push_back(node); // Add it to the topological order
```

- Processes vertices in the queue.
- Adds the vertex to the topological order.



```cpp
        for (auto neighbour : adj[node]) {
            indegree[neighbour]--; // Decrease indegree of neighbors
            if (indegree[neighbour] == 0) q.push(neighbour); // Add to queue if indegree becomes 0
        }
    }
```

- Decreases the indegree of each neighbor by `1`.
- If a neighbor's indegree becomes `0`, adds it to the queue.



```cpp
    if (topoOrder.size() != V) {
        cout << "The graph is not a DAG. Topological sort not possible.\n";
        return;
    }
```

- If the topological order does not include all vertices, the graph contains a cycle, and topological sort is not possible.



```cpp
    cout << "Topological sorting of the graph: ";
    for (int node : topoOrder) cout << node + 1 << " "; // Print topological order (1-based indexing)
    cout << endl;
}
```

- Prints the final topological order.



#### **Driver Code: `main`**

```cpp
int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 5}, {3, 5}, {5, 4}};
    vector<vector<int>> adj(V); // Adjacency list
```

- Initializes the graph with `V = 5` vertices.
- Stores edges.



```cpp
    for (auto i : edges) {
        adj[i[0] - 1].push_back(i[1] - 1); // Convert edges to adjacency list
    }
```

- Converts edge list to adjacency list with `0`-based indexing.



```cpp
    KahnsAlgorithm(adj, V); // Call the topological sort function
    return 0;
}
```

- Calls `KahnsAlgorithm` and performs topological sorting.


### **Example Input and Output**

**Input:**
```
Edges:
1 → 2, 1 → 3, 2 → 5, 3 → 5, 5 → 4
```

**Adjacency List:**
```
1 → [2, 3]
2 → [5]
3 → [5]
5 → [4]
```

**Output:**
```
Topological sorting of the graph: 1 2 3 5 4
```


### **Complexities**

1. **Time Complexity**:
   - **Calculate Indegree**: \(O(V + E)\).
   - **Queue Processing**: \(O(V + E)\).
   - Total: **\(O(V + E)\)**.

2. **Space Complexity**:
   - **Indegree Array**: \(O(V)\).
   - **Queue**: \(O(V)\).
   - Total: **\(O(V)\)**.
