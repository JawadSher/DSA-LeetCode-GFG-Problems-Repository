<h1 align='center'>Strongly - Connected - Components</h1>

## Problem Statement

**Problem URL :** [Strongly Connected Components](https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1)

![image](https://github.com/user-attachments/assets/ff9d26ad-5597-4964-a601-3671afa49c34)
![image](https://github.com/user-attachments/assets/1fb37d2d-d490-48a8-b71a-ec82350645c3)
![image](https://github.com/user-attachments/assets/8074f834-cd76-40fd-911d-584531ca1074)
![image](https://github.com/user-attachments/assets/f5f5659b-4c2c-4a35-85c5-e0f7c452d4fa)

## Problem Explanation
A **Strongly Connected Component (SCC)** of a directed graph is a maximal subgraph in which any two vertices are reachable from each other. For example, if there is a path from (u) to (v) and a path from (v) to (u), then (u) and (v) belong to the same SCC.

The goal of the problem is to find all SCCs in a directed graph using **Kosaraju's algorithm**.

### Example Problem
#### Input:
Consider a directed graph with (V = 5) vertices and the following edges:
[
text{Adjacency List Representation:} 
0 to 1 
1 to 2 
2 to 0 
1 to 3 
3 to 4
]

#### Graph Representation:
```
    0 → 1 → 3 → 4
    ↑    ↓
    2 ←  → 2
```

#### Output:
The SCCs in the graph are:
- **SCC 1**: ({0, 1, 2}) (all nodes are mutually reachable)
- **SCC 2**: ({3})
- **SCC 3**: ({4})

### Kosaraju’s Algorithm

Kosaraju's Algorithm uses **two Depth-First Searches (DFS)** to find all SCCs. It takes advantage of the fact that the **transpose** of a graph reverses all its edges, helping isolate SCCs.

#### Steps:

1. **Perform a DFS to Fill Stack Based on Finish Time**:
   - Traverse the graph using DFS. Maintain a stack to store the vertices in the order of their "finish time" (i.e., when DFS finishes for a vertex).
   - Nodes finishing last are placed on top of the stack.

   **Example**:
   - Start from node (0):
     - Visit (0 to 1 to 2) and push (2 to 1 to 0) to the stack (DFS backtracking order).
   - Visit (3) (not visited yet) and push it to the stack.
   - Visit (4) (not visited yet) and push it to the stack.
   - Stack order: ([4, 3, 0, 1, 2]).

2. **Transpose the Graph**:
   - Reverse the direction of all edges in the graph. This creates a new graph where edges point in the opposite direction.

   **Original Edges**:
   (0 to 1, 1 to 2, 2 to 0, 1 to 3, 3 to 4)

   **Transposed Edges**:
   (1 to 0, 2 to 1, 0 to 2, 3 to 1, 4 to 3)

   **Transposed Graph**:
   ```
       1 → 0 → 2
            ↑
       3 ← 4
   ```

3. **Perform DFS on Transposed Graph**:
   - Pop nodes from the stack (based on finish times in the original graph) and perform DFS on the transposed graph.
   - Each DFS traversal identifies one SCC.

   **Example**:
   - Pop (4) from the stack → Start DFS → Finds SCC ({4}).
   - Pop (3) → Start DFS → Finds SCC ({3}).
   - Pop (0) → Start DFS → Traverses (0, 1, 2) → Finds SCC ({0, 1, 2}).

4. **Return the SCC Count**:
   - The total number of SCCs is the number of DFS calls made in step 3.

### Kosaraju’s Approach: Intuition

The algorithm relies on the following properties:
1. **Finish Time Order**:
   - DFS ensures that nodes which are deeply connected in a graph are processed last.
   - By reversing the graph, SCCs become isolated components when processed in reverse order of finish time.

2. **Graph Transposition**:
   - Reversing edges isolates SCCs. Nodes in a single SCC remain reachable only to each other.

### Example Walkthrough

#### Graph:
```
    0 → 1 → 3 → 4
    ↑    ↓
    2 ←  → 2
```

1. **First DFS (Order Nodes by Finish Time)**:
   - Visit nodes (0 to 1 to 2) → Stack ([2, 1, 0]).
   - Visit (3) → Stack ([3, 2, 1, 0]).
   - Visit (4) → Stack ([4, 3, 2, 1, 0]).

2. **Transpose Graph**:
   ```
       1 → 0 → 2
            ↑
       3 ← 4
   ```

3. **Second DFS (On Transposed Graph)**:
   - Pop (4): Start DFS → ({4}).
   - Pop (3): Start DFS → ({3}).
   - Pop (0): Start DFS → ({0, 1, 2}).

4. **Result**:
   SCCs: ({0, 1, 2}, {3}, {4}).


### Why Kosaraju’s Algorithm Works?
1. **Reverse Finish Time**:
   - Processing nodes in reverse order ensures that the first DFS isolates SCCs effectively.

2. **Transposed Graph**:
   - SCCs in the original graph are strongly connected in the transposed graph as well.

## Problem Solution
```cpp
class Solution
{
    public:
    // Function to perform Depth First Search (DFS) and populate the stack with nodes in order of their finish time
    void DFS(int node, vector<int>& visited, vector<vector<int>>& adjacencyList, stack<int>& nodesOrder) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Explore all unvisited neighbors of the current node
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour]) 
                DFS(neighbour, visited, adjacencyList, nodesOrder);
        }
        
        // After visiting all neighbors, push the current node onto the stack
        nodesOrder.push(node);
    }
    
    // Function to perform DFS on the transposed graph
    void reverseDFS(int node, vector<vector<int>>& adjacencyList, vector<int>& visited) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Explore all unvisited neighbors of the current node in the transposed graph
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour]) 
                reverseDFS(neighbour, adjacencyList, visited);
        }
    }
    
    // Function to find the number of strongly connected components (SCCs) using Kosaraju's Algorithm
    int kosaraju(int V, vector<vector<int>>& adj) {
        // Step 1: Initialize visited vector and stack to store nodes in order of their finish time
        vector<int> visited(V, false);
        stack<int> nodesOrder;
        vector<vector<int>> transpose(V); // Adjacency list for the transposed graph
        int totalSCCs = 0; // Counter for SCCs
        
        // Step 2: Perform DFS on the original graph to populate the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) 
                DFS(i, visited, adj, nodesOrder);
        }
        
        // Step 3: Create the transposed graph
        for (int i = 0; i < V; i++) {
            for (auto neighbour : adj[i]) {
                // Reverse the direction of edges
                transpose[neighbour].push_back(i);
            }
        }
        
        // Step 4: Reset visited array for use in the second DFS
        fill(visited.begin(), visited.end(), false);
        
        // Step 5: Perform DFS on the transposed graph in the order of nodes in the stack
        while (!nodesOrder.empty()) {
            int node = nodesOrder.top();
            nodesOrder.pop();
            
            // If the node is not visited, it means we've found a new SCC
            if (!visited[node]) {
                totalSCCs++; // Increment SCC count
                reverseDFS(node, transpose, visited); // Explore all nodes in this SCC
            }
        }
        
        // Step 6: Return the total number of SCCs
        return totalSCCs;
    }
};

```
## Problem Solution Explanation

Here’s a detailed, line-by-line explanation of the code and its time and space complexities.

#### 1. **DFS Function (Original Graph)**

```cpp
void DFS(int node, vector<int>& visited, vector<vector<int>>& adjacencyList, stack<int>& nodesOrder) {
    visited[node] = true;
    for (auto neighbour : adjacencyList[node]) {
        if (!visited[neighbour]) 
            DFS(neighbour, visited, adjacencyList, nodesOrder);
    }
    nodesOrder.push(node);
}
```

**Purpose**:  
This function performs a **Depth-First Search (DFS)** on the graph to record nodes in their **finish time order**. It pushes nodes to a stack after exploring all their neighbors.

**Example**:  
For the graph:
```
0 → 1 → 2
↑         ↓
4 ← 3 → 5
```

- Start DFS at (0): Visits (1), then (2), and stops as there are no more unvisited neighbors.
- Push (2 to 1 to 0) into the stack in reverse order of finish time.
- Next DFS call starts from unvisited (3), visiting (5) and (4), pushing (4 to 5 to 3).
- Stack after all DFS: ([3, 5, 4, 0, 1, 2]).

**Time Complexity**: (O(V + E))  
- (V): Number of vertices.
- (E): Number of edges.



#### 2. **reverseDFS Function (Transposed Graph)**

```cpp
void reverseDFS(int node, vector<vector<int>>& adjacencyList, vector<int>& visited) {
    visited[node] = true;
    for (auto neighbour : adjacencyList[node]) {
        if (!visited[neighbour]) 
            reverseDFS(neighbour, adjacencyList, visited);
    }
}
```

**Purpose**:  
Performs DFS on the **transposed graph** to explore all nodes in a single Strongly Connected Component (SCC). Each invocation corresponds to finding one SCC.

**Example**:  
For the transposed graph of the above example:
```
1 ← 0 ← 2
↓         ↑
5 → 3 ← 4
```

- Start reverseDFS from stack’s top: (3), which explores (3 to 5 to 4).
- This marks the SCC ({3, 4, 5}).
- Continue with the next unvisited node from the stack: (0), exploring (0 to 1 to 2), forming ({0, 1, 2}).

**Time Complexity**: (O(V + E)).



#### 3. **kosaraju Function**

```cpp
int kosaraju(int V, vector<vector<int>>& adj) {
    vector<int> visited(V, false);
    stack<int> nodesOrder;
    vector<vector<int>> transpose(V);
    int totalSCCs = 0;
```

- **Input**:
  - `V`: Number of vertices.
  - `adj`: Adjacency list representation of the graph.
- **Output**:
  - Returns the number of SCCs.



##### Step 1: Populate Stack with Finish Times
```cpp
for (int i = 0; i < V; i++) {
    if (!visited[i]) 
        DFS(i, visited, adj, nodesOrder);
}
```
- Traverses the graph using DFS, pushing nodes to the stack after visiting all their neighbors. This ensures nodes are stored in reverse finish time order.

**Example Stack**: After DFS on the graph, stack = ([3, 5, 4, 0, 1, 2]).

**Time Complexity**: (O(V + E)).



##### Step 2: Transpose the Graph
```cpp
for (int i = 0; i < V; i++) {
    for (auto neighbour : adj[i]) {
        transpose[neighbour].push_back(i);
    }
}
```
- Reverse all edges in the graph.

**Example**:
Original graph edges:  
(0 to 1, 1 to 2, 2 to 0, 3 to 5, 5 to 4, 4 to 3)

Transposed graph edges:  
(1 to 0, 2 to 1, 0 to 2, 5 to 3, 4 to 5, 3 to 4)

**Time Complexity**: (O(V + E)).



##### Step 3: Reset Visited Array
```cpp
fill(visited.begin(), visited.end(), false);
```
- Clears the visited array for reuse in the second DFS.



##### Step 4: Find SCCs Using Reverse DFS
```cpp
while (!nodesOrder.empty()) {
    int node = nodesOrder.top();
    nodesOrder.pop();
    
    if (!visited[node]) {
        totalSCCs++;
        reverseDFS(node, transpose, visited);
    }
}
```
- Process nodes in reverse finish time order from the stack.
- Each DFS call identifies one SCC.

**Example**:
- Stack = ([3, 5, 4, 0, 1, 2]).
- Pop (3): Finds ({3, 4, 5}).
- Pop (0): Finds ({0, 1, 2}).

**Time Complexity**: (O(V + E)).



#### 5. **Return Total SCCs**
```cpp
return totalSCCs;
```
Returns the number of SCCs.

**Output for Example Graph**: (2) SCCs: ({0, 1, 2}, {3, 4, 5}).



### Complexity Analysis

#### **Time Complexity**
1. First DFS (original graph): (O(V + E)).
2. Transpose graph: (O(V + E)).
3. Second DFS (transposed graph): (O(V + E)).

**Total**: (O(V + E)).

#### **Space Complexity**
1. Adjacency list storage: (O(V + E)).
2. Transposed graph storage: (O(V + E)).
3. Visited array and stack: (O(V)).

**Total**: (O(V + E)).



### Intuition Behind Kosaraju's Algorithm

- The **finish time order** ensures that nodes in one SCC are processed together in the transposed graph.
- Transposing the graph isolates SCCs since edges between SCCs are reversed, breaking cross-SCC connections.
