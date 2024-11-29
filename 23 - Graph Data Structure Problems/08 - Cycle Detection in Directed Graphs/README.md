<h1 align='center'>Detect - Cycle - in Directed - Graph</h1>

## Problem Statement

**Problem URL :** [Detect Cycle in Directed Graph](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

![image](https://github.com/user-attachments/assets/37359499-c279-4677-b7da-9b8e4ea1632f)
![image](https://github.com/user-attachments/assets/4998fd25-14a8-46e9-aa8b-8245d3831772)

## Problem Explanation
A **directed graph** consists of vertices and edges, where each edge has a direction. A **cycle** in a directed graph exists when you can start at a vertex, follow the edges, and return to the same vertex without traversing any edge twice. The task is to determine if a cycle exists in the graph using a **Breadth-First Search (BFS)** approach.

#### **Example 1:**
**Input:**
- Number of vertices: \(V = 4\)
- Adjacency list: ([[1], [2], [3], [1]])  
  This represents the edges:
  - (0 -> 1)
  - (1 -> 2)
  - (2 -> 3)
  - (3 -> 1)

**Output:**  
`true`  

**Explanation:**  
A cycle exists: (1 -> 2 -> 3 -> 1).



#### **Example 2:**
**Input:**
- Number of vertices: (V = 3)
- Adjacency list: ([[1], [2], []])  
  This represents the edges:
  - (0 -> 1)
  - (1 -> 2)

**Output:**  
`false`  

**Explanation:**  
There is no path that loops back to any node. Hence, no cycle exists.

## BFS Approach

We use **Kahn’s Algorithm** to detect cycles in a directed graph. This algorithm relies on the concept of **indegree** and **topological sorting**. If the graph contains a cycle, the topological sorting will not cover all vertices.

#### **Steps:**
1. **Calculate Indegree:**
   - Compute the number of incoming edges (indegree) for each node.

2. **Initialize Queue:**
   - Add all nodes with an indegree of \(0\) to a queue. These nodes have no dependencies and can be processed immediately.

3. **Process Nodes:**
   - While the queue is not empty:
     - Dequeue a node.
     - Increment a counter (`count`) to track the number of processed nodes.
     - For each neighbor of the current node:
       - Decrease its indegree by \(1\).
       - If its indegree becomes \(0\), enqueue it.

4. **Check for Cycles:**
   - If the `count` of processed nodes equals the total number of vertices (\(V\)), there is no cycle.
   - If \(count < V\), a cycle exists.



#### **Example:**
Graph: \(V = 4, \text{adjacency list} = [[1], [2], [3], [1]]\)

1. **Calculate Indegree:**
   ```
   Indegree: [0, 1, 1, 1]
   ```

2. **Initialize Queue:**
   - No nodes have an indegree of \(0\). The queue remains empty.

3. **Process Nodes:**
   - Since the queue is empty, we cannot process all nodes. This indicates a cycle.

4. **Output:**
   ```
   Cycle detected: true
   ```


### Problem Solution
```cpp
class Solution {
  public:
    // Function to detect a cycle using BFS (Kahn's Algorithm)
    bool isCycleBFS(int node, vector<vector<int>>& adj, int V) {
        vector<int> indegree(V, 0); // Array to store the indegree of each vertex
        queue<int> q;              // Queue to process nodes with indegree 0
        int count = 0;             // Counter to track processed nodes

        // Step 1: Calculate the indegree for all nodes
        for(int i = 0; i < V; i++) {
            for(int neighbour : adj[i]) {
                indegree[neighbour]++; // Increment indegree of the neighbor
            }
        }

        // Step 2: Add all nodes with indegree 0 to the queue
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i); // Nodes with no dependencies
        }

        // Step 3: Process nodes in the queue
        while(!q.empty()) {
            int node = q.front(); // Get the front node in the queue
            q.pop();              // Remove it from the queue

            count++; // Increment the processed node count

            // Reduce the indegree of all neighbors
            for(auto neighbour : adj[node]) {
                indegree[neighbour]--;       // Reduce indegree of the neighbor
                if(indegree[neighbour] == 0) // If indegree becomes 0
                    q.push(neighbour);       // Add it to the queue
            }
        }

        // Step 4: If all nodes are processed, no cycle exists
        if(count == V) return false; // No cycle
        return true;                 // Cycle exists
    }

    // Main function to detect cycles in a graph
    bool isCyclic(int V, vector<vector<int>> adj) {
        // Iterate through all nodes to check for cycles
        for(int i = 0; i < V; i++) {
            bool ans = isCycleBFS(i, adj, V); // Call the BFS function
            if(ans == true) return true;     // If cycle detected, return true
        }
        return false; // No cycle found
    }
};

```
### Problem Solution Explanation
Here is a **detailed line-by-line explanation** of the provided code:

```cpp
class Solution {
  public:
```

- This defines a class `Solution` containing the methods for detecting a cycle in a directed graph.



#### **Function 1: `isCycleBFS`**

```cpp
bool isCycleBFS(int node, vector<vector<int>>& adj, int V) {
```

- **Purpose:** Checks for a cycle in the graph using **Kahn’s Algorithm** (BFS approach).
- **Parameters:**
  - `node`: The current node being checked (not used directly in BFS logic).
  - `adj`: The adjacency list representing the graph.
  - `V`: The total number of vertices in the graph.



```cpp
vector<int> indegree(V, 0);
```

- **What it does:** Initializes an array `indegree` of size \(V\) to track the number of incoming edges for each vertex. Initially, all vertices have an indegree of \(0\).

**Example:**  
For a graph with \(V = 4, \text{adjacency list} = [[1], [2], [3], [1]]\):  
```
Initial indegree = [0, 0, 0, 0]
```



```cpp
queue<int> q;
int count = 0;
```

- **What it does:**  
  - `q`: A queue to store vertices with \(0\) indegree (ready to process).
  - `count`: A counter to track how many vertices have been processed.



```cpp
for(int i = 0; i < V; i++) {
    for(int neighbour : adj[i]) {
        indegree[neighbour]++;
    }
}
```

- **What it does:** Calculates the indegree for all vertices by iterating over the adjacency list. For every edge \(i \to \text{neighbour}\), it increments the indegree of `neighbour`.

**Example:**  
For \(V = 4, \text{adjacency list} = [[1], [2], [3], [1]]\):  
```
Processing:
- Node 0 → Neighbour 1 → indegree[1]++
- Node 1 → Neighbour 2 → indegree[2]++
- Node 2 → Neighbour 3 → indegree[3]++
- Node 3 → Neighbour 1 → indegree[1]++

Final indegree = [0, 2, 1, 1]
```



```cpp
for(int i = 0; i < V; i++) {
    if(indegree[i] == 0) q.push(i);
}
```

- **What it does:** Adds all vertices with \(0\) indegree (no dependencies) to the queue for processing.

**Example:**  
```
indegree = [0, 2, 1, 1]
Queue after initialization: q = [0]
```



```cpp
while(!q.empty()) {
    int node = q.front();
    q.pop();
    count++;
```

- **What it does:**  
  - Extracts the front vertex (`node`) from the queue.
  - Increments the `count` to signify that this vertex has been processed.

**Example (first iteration):**  
```
Queue before: q = [0]
Processing node = 0
Count = 1
Queue after: q = []
```



```cpp
for(auto neighbour : adj[node]) {
    indegree[neighbour]--;
    if(indegree[neighbour] == 0) q.push(neighbour);
}
```

- **What it does:**  
  - Iterates over all neighbors of the current node (`node`).
  - Decreases their indegree (as the current node is processed).
  - If any neighbor's indegree becomes \(0\), it is added to the queue.

**Example (processing neighbors of 0):**  
```
Node 0 → Neighbour 1
Decrement indegree[1]: indegree = [0, 1, 1, 1]
Neighbour 1 not added to queue (indegree ≠ 0)
```



```cpp
if(count == V) return false;
```

- **What it does:**  
  - After processing all nodes in the queue, checks if the total processed count (`count`) equals \(V\).
  - If `count == V`, all vertices were processed, indicating no cycle exists.

**Example (cycle graph):**  
```
Processed count = 1
Total vertices = 4
Count ≠ V → Cycle detected
Return true
```



```cpp
return true;
```

- **What it does:** If `count` is less than \(V\), it means some vertices were not processed because they are part of a cycle.



#### **Function 2: `isCyclic`**

```cpp
bool isCyclic(int V, vector<vector<int>> adj) {
```

- **Purpose:** Iterates through the graph and uses the `isCycleBFS` function to check for cycles.



```cpp
for(int i = 0; i < V; i++) {
    bool ans = isCycleBFS(i, adj, V);
    if(ans == true) return true;
}
```

- **What it does:**  
  - For every node, checks for cycles using `isCycleBFS`.
  - If a cycle is detected (`true`), returns `true`.

**Note:** The iteration is redundant since Kahn's Algorithm processes all nodes in one call to `isCycleBFS`.



```cpp
return false;
```

- **What it does:** If no cycles are detected for any node, returns `false`.



### **Example Walkthrough**

**Input:**  
- \(V = 4\)
- Adjacency list: \([[1], [2], [3], [1]]\)

**Execution Steps:**
1. **Calculate Indegree:**  
   ```
   indegree = [0, 2, 1, 1]
   ```

2. **Initialize Queue:**  
   ```
   Queue = [0]
   ```

3. **Process Nodes:**  
   - Node 0:
     - Processed → `count = 1`
     - Neighbors updated → `indegree = [0, 1, 1, 1]`
     - Queue = []

4. **Check:**  
   ```
   Count = 1, V = 4 → Cycle detected
   ```

**Output:**  
`true`



### **Time Complexity**

1. **Calculate Indegree:** \(O(V + E)\)
   - \(V\): Iterating over all nodes.
   - \(E\): Iterating over all edges.

2. **Queue Processing:** \(O(V + E)\)
   - \(V\): Each node enqueued once.
   - \(E\): Each edge processed once.

**Total:** \(O(V + E)\)



### **Space Complexity**

1. **Indegree Array:** \(O(V)\)
2. **Queue:** \(O(V)\)

**Total:** \(O(V)\)

---

## DFS Approach
In a directed graph, a **cycle** exists if we can traverse along the edges and return to a previously visited node along the same path. Detecting cycles is crucial in many real-world applications like deadlock detection in operating systems, dependency checking, etc.

### **Approach**
The **DFS approach** uses recursion and two tracking mechanisms:
1. **Visited Array (`visited`)**: Tracks nodes that have been visited during the entire DFS traversal.
2. **DFS Visited Array (`dfsVisited`)**: Tracks nodes in the current DFS call stack to detect cycles.


### **Steps to Solve**
1. **Initialize Tracking Structures**: Use `visited` and `dfsVisited` to monitor traversal status.
2. **Perform DFS**:
   - Mark the current node as visited and add it to the DFS stack (`dfsVisited`).
   - For each neighbor:
     - If it is **not visited**, recursively call DFS on it.
     - If it is in the **current DFS path (`dfsVisited`)**, a cycle is detected.
   - Backtrack by removing the node from the DFS stack (`dfsVisited`).
3. **Repeat for Unvisited Nodes**: Since the graph may not be connected, initiate DFS from all unvisited nodes.
4. **Return Result**: If any cycle is detected during the process, return `true`; otherwise, return `false`.


### **Example**
Consider a graph with `V = 4` and edges `[(0 → 1), (1 → 2), (2 → 0), (3 → 3)]`.

**Graph Representation (Adjacency List)**:
```
0 → [1]
1 → [2]
2 → [0]
3 → [3]
```

**Traversal**:
1. Start DFS from node `0`:
   - Visit `0` → Visit `1` → Visit `2` → Detect cycle as `0` is already in `dfsVisited`.
2. Start DFS from `3`:
   - Detect cycle at `3` due to self-loop.

**Result**: Cycle Detected.


### Problem Solution

```cpp
class Solution {
  public:
    // Helper function to check for a cycle using DFS
    bool isDFSCycle(int node, vector<vector<int>>& adj, 
                    unordered_map<int, bool>& visited, 
                    unordered_map<int, bool>& dfsVisited) {
        // Mark the current node as visited and part of the DFS path
        visited[node] = true;
        dfsVisited[node] = true;
        
        // Traverse all neighbors of the current node
        for(auto neighbour : adj[node]) {
            // If the neighbor is not visited, recursively check for a cycle
            if(!visited[neighbour]) {
                bool cycleDetected = isDFSCycle(neighbour, adj, visited, dfsVisited);
                if(cycleDetected) return true;
            }
            // If the neighbor is visited and part of the current DFS path, a cycle is detected
            else if(dfsVisited[neighbour]) return true;
        }
        
        // Backtrack: Remove the current node from the DFS path
        dfsVisited[node] = false;
        return false;
    }
    
    // Main function to detect a cycle in the graph
    bool isCyclic(int V, vector<vector<int>> adj) {
        unordered_map<int, bool> visited;   // Tracks overall visited nodes
        unordered_map<int, bool> dfsVisited; // Tracks nodes in the current DFS path
        
        // Perform DFS for each unvisited node
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool ans = isDFSCycle(i, adj, visited, dfsVisited);
                if(ans == true) return true; // Cycle found
            }
        }
        
        return false; // No cycle detected
    }
};
```

### Problem Solution Explanation
#### **Function: `isDFSCycle`**
1. **Line 1:** 
   ```cpp
   visited[node] = true; 
   dfsVisited[node] = true;
   ```
   Mark the current node as visited globally (`visited`) and as part of the current DFS call stack (`dfsVisited`).

2. **Line 2-8:**
   ```cpp
   for(auto neighbour : adj[node]) {
       if(!visited[neighbour]) {
           bool cycleDetected = isDFSCycle(neighbour, adj, visited, dfsVisited);
           if(cycleDetected) return true;
       }
       else if(dfsVisited[neighbour]) return true;
   }
   ```
   - For each neighbor of the current node:
     - If not visited, recursively check for cycles.
     - If the neighbor is in the current DFS stack (`dfsVisited`), a cycle is detected.

3. **Line 9:**
   ```cpp
   dfsVisited[node] = false;
   ```
   Backtrack: Remove the current node from the DFS stack to allow other paths.

4. **Line 10:**
   ```cpp
   return false;
   ```
   If no cycle is detected from the current node, return `false`.



#### **Function: `isCyclic`**
1. **Line 1-2:** 
   ```cpp
   unordered_map<int, bool> visited;   
   unordered_map<int, bool> dfsVisited;
   ```
   Initialize tracking structures for all nodes.

2. **Line 3-9:**
   ```cpp
   for(int i = 0; i < V; i++) {
       if(!visited[i]) {
           bool ans = isDFSCycle(i, adj, visited, dfsVisited);
           if(ans == true) return true;
       }
   }
   ```
   - Perform DFS for all unvisited nodes in the graph.
   - If any cycle is detected, return `true`.

3. **Line 10:**
   ```cpp
   return false;
   ```
   If no cycles are detected after traversing all nodes, return `false`.



#### **Step 4: Example Walkthrough**

**Input Graph (Adjacency List)**:
```
0 → [1]
1 → [2]
2 → [0]
```

**Execution**:
1. Start DFS from `0`:
   - Mark `0` as visited (`visited[0] = true`, `dfsVisited[0] = true`).
   - Visit neighbor `1`.
2. From `1`:
   - Mark `1` as visited.
   - Visit neighbor `2`.
3. From `2`:
   - Mark `2` as visited.
   - Visit neighbor `0`: Since `0` is in `dfsVisited`, a cycle is detected.

**Output**: `true` (Cycle exists).



#### **Step 5: Time and Space Complexity**

1. **Time Complexity**: 
   - Each node and edge is visited once in the DFS traversal.
   - Total complexity: **O(V + E)**, where `V` is the number of vertices and `E` is the number of edges.

2. **Space Complexity**: 
   - Space for `visited` and `dfsVisited`: **O(V)**.
   - Recursive stack space: **O(V)** (in the worst case of a single long path).
   - Total space complexity: **O(V)**. 


### **Recommendations for Students**
1. Visualize the problem with examples to understand the traversal process.
2. Practice writing the DFS code from scratch for both connected and disconnected graphs.
3. Debug with different test cases to strengthen your understanding of recursion and backtracking.
