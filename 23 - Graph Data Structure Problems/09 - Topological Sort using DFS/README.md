<h1 align='center'>Topological - Sort - Using - DFS</h1>

## Problem Statement

**Problem URL :** [Topological Sort using DFS](https://www.geeksforgeeks.org/topological-sorting/)

### **What is Topological Sort?**
- Topological sorting is a linear ordering of vertices in a **directed acyclic graph (DAG)** such that for every directed edge `U → V`, vertex `U` appears before vertex `V` in the ordering.
- **Applications**:
  1. Task scheduling (e.g., compiling tasks with dependencies).
  2. Course prerequisite planning.
  3. Resolving symbol dependencies in linkers.


#### **Example: Understanding Topological Sort**

#### Graph:
Consider a directed graph with 4 nodes and the following edges:
```
0 → 1
1 → 2
3 → 1
3 → 2
```

#### Representation:
**Adjacency List**:
```
0 → [1]
1 → [2]
3 → [1, 2]
```

#### **Steps for Topological Sort**:
1. Identify nodes with no incoming edges (start points).
2. Use **Depth First Search (DFS)** to explore the graph.
3. When a node has no more unvisited neighbors, add it to the stack.
4. Continue until all nodes are visited.
5. The stack contains the nodes in **reverse topological order**.

**Result for the given graph**:
- One valid topological ordering: `3 0 1 2`.


### **Approach: DFS for Topological Sorting**

#### **Key Steps**:
1. **Initialization**:
   - Maintain a `visited` array to track visited nodes.
   - Use a stack to store the topological order.

2. **DFS Traversal**:
   - Visit all neighbors of the current node recursively.
   - When there are no more neighbors, add the current node to the stack.

3. **Retrieve Order**:
   - Pop all elements from the stack to get the topological order.
     

### Problem Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and topological sorting
void topologicalSortUtil(int node, vector<vector<int> >& adj, vector<bool>& visited, stack<int>& Stack){
  // Mark the current node as visited
  visited[node] = true;

  // Recur for all adjacent vertices
  for (auto neighbour : adj[node]) if (!visited[neighbour]) topologicalSortUtil(neighbour, adj, visited, Stack);
  
  // Push current vertex to stack which stores the result
  Stack.push(node);
}

// Function to perform Topological Sort
void topologicalSort(vector<vector<int> >& adj, int V){
  stack<int> Stack; // Stack to store the result
  vector<bool> visited(V, false);

  // Call the recursive helper function to store
  // Topological Sort starting from all vertices one by
  // one
  for (int i = 0; i < V; i++) if (!visited[i]) topologicalSortUtil(i, adj, visited, Stack);

  // Print contents of stack
  while (!Stack.empty()) {
    cout << Stack.top() << " ";
    Stack.pop();
  }
}

int main()
{

  // Number of nodes
  int V = 4;

  // Edges
  vector<vector<int> > edges = {{0, 1}, {1, 2}, {3, 1}, {3, 2}};

  // Graph represented as an adjacency list
  vector<vector<int> > adj(V);

  for (auto i : edges) adj[i[0]].push_back(i[1]);
  
  cout << "Topological sorting of the graph: ";
  topologicalSort(adj, V);

  return 0;
}
```

## Problem Solution Explanation

Let's go through the **Topological Sort code** line by line and explain each part with examples.

```cpp
#include <bits/stdc++.h>
using namespace std;
```

- **`#include <bits/stdc++.h>`**:
  - Includes all standard C++ libraries (e.g., iostream, vector, stack).
  - Simplifies development by allowing us to use containers like `vector`, `stack`, etc.

- **`using namespace std;`**:
  - Avoids the need to prefix standard library functions and types (e.g., `std::vector`, `std::cout`).


### **Helper Function: `topologicalSortUtil`**

```cpp
void topologicalSortUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack) {
    visited[node] = true; 
```

- **`void topologicalSortUtil(...)`**:
  - Helper function to perform **DFS**.
  - **Parameters**:
    1. `node`: The current node being processed.
    2. `adj`: Adjacency list representation of the graph.
    3. `visited`: Keeps track of nodes already visited.
    4. `Stack`: Stores nodes in reverse topological order.

- **`visited[node] = true;`**:
  - Marks the current node as visited to prevent revisiting.



```cpp
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topologicalSortUtil(neighbour, adj, visited, Stack);
        }
    }
```

- **`for (auto neighbour : adj[node]) {...}`**:
  - Iterates over all neighbors of the current node using the adjacency list.
  - **`if (!visited[neighbour])`**:
    - Checks if the neighbor is unvisited. If so, calls `topologicalSortUtil` recursively.

**Example**:
For the graph:
```
0 → [1]
1 → [2]
```
If `node = 0`, then `adj[0] = [1]`. The function recursively processes `1`.



```cpp
    Stack.push(node);
}
```

- **`Stack.push(node);`**:
  - Once all neighbors of the node are visited, the node is pushed to the stack.
  - This ensures that nodes with no dependencies are processed first.

**Example**:
For the graph:
```
0 → [1]
1 → [2]
```
Order of processing:
- Visit `2`, push it to the stack.
- Visit `1`, push it to the stack.
- Visit `0`, push it to the stack.



### **Main Function: `topologicalSort`**

```cpp
void topologicalSort(vector<vector<int>>& adj, int V) {
    stack<int> Stack;
    vector<bool> visited(V, false);
```

- **`stack<int> Stack;`**:
  - Declares a stack to store nodes in topological order.

- **`vector<bool> visited(V, false);`**:
  - Initializes a `visited` array with `false` for all nodes, indicating that no nodes have been visited yet.



```cpp
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }
```

- **`for (int i = 0; i < V; i++)`**:
  - Loops through all nodes.
  - **`if (!visited[i]) {...}`**:
    - For unvisited nodes, calls `topologicalSortUtil` to perform DFS.

**Example**:
For the graph:
```
0 → [1]
1 → [2]
3 → [1, 2]
```
- The loop starts with node `0`, calls `topologicalSortUtil` for `0`.
- Next, it processes node `3`.



```cpp
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
```

- **`while (!Stack.empty()) {...}`**:
  - Retrieves nodes from the stack one by one and prints them in topological order.
  - **`Stack.top()`**:
    - Returns the top element of the stack.
  - **`Stack.pop()`**:
    - Removes the top element from the stack.

**Example**:
For the graph:
```
0 → [1]
1 → [2]
3 → [1, 2]
```
Stack content after processing:
```
3, 0, 1, 2
```
Output:
```
3 0 1 2
```



### **Driver Code: `main`**

```cpp
int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {3, 2}};
```

- **`int V = 4;`**:
  - Defines the number of nodes (vertices) in the graph.

- **`vector<vector<int>> edges = {...};`**:
  - Represents directed edges between nodes.

**Example**:
Edges `{0, 1}, {1, 2}, {3, 1}, {3, 2}` mean:
```
0 → 1
1 → 2
3 → 1, 2
```



```cpp
    vector<vector<int>> adj(V);
    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }
```

- **`vector<vector<int>> adj(V);`**:
  - Adjacency list representation of the graph.

- **`for (auto i : edges) {...}`**:
  - Converts the list of edges into an adjacency list.

**Example**:
For edges `{0, 1}, {1, 2}, {3, 1}, {3, 2}`, adjacency list becomes:
```
0 → [1]
1 → [2]
3 → [1, 2]
```



```cpp
    cout << "Topological sorting of the graph: ";
    topologicalSort(adj, V);
    return 0;
}
```

- **`cout << ...`**:
  - Prints the message before calling the `topologicalSort` function.

- **`topologicalSort(adj, V);`**:
  - Computes the topological order and prints it.



### **Example Execution**

#### Input:
```
V = 4
Edges: {{0, 1}, {1, 2}, {3, 1}, {3, 2}}
```

#### Adjacency List:
```
0 → [1]
1 → [2]
3 → [1, 2]
```

#### Steps:
1. Start DFS from `0`:
   - Visit `0 → 1 → 2`.
   - Push `2`, then `1`, then `0` to the stack.
2. Start DFS from `3`:
   - Visit `3 → 1 → 2` (already visited).
   - Push `3` to the stack.

#### Stack:
```
Stack: [3, 0, 1, 2]
```

#### Output:
```
Topological sorting of the graph: 3 0 1 2
```



### **Time and Space Complexity**

1. **Time Complexity**:
   - Visiting all nodes: **O(V)**.
   - Traversing all edges: **O(E)**.
   - Total: **O(V + E)**.

2. **Space Complexity**:
   - Stack and visited array: **O(V)**.
   - Total: **O(V)**.
