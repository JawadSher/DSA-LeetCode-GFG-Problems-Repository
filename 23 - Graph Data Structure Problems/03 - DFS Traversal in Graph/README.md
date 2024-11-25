<h1 align='center'>DFS - Traversal - In Graph</h1>

Depth-First Search (DFS) is a graph traversal algorithm that starts at a source node and explores as far down a branch as possible before backtracking. It systematically explores all the vertices of a graph or tree in depth.

In DFS:
- We start at a node, explore its neighbors, then explore their neighbors recursively.
- We use a **stack** (either explicitly or via recursion) to backtrack when a node has no unvisited neighbors.

### **DFS Characteristics:**
1. **Recursive or Iterative**: DFS can be implemented using recursion (which uses the call stack) or an explicit stack.
2. **Order of Exploration**: DFS explores a path to the end before trying other paths.
3. **Graph Type**: DFS can be applied to both directed and undirected graphs.

### **Approach to DFS Traversal:**
1. **Start** at a node, mark it as visited.
2. **Explore** each adjacent unvisited node (neighbor) of the current node, moving deeper.
3. If there are no unvisited adjacent nodes left, **backtrack** and return to the last node where there’s an unvisited neighbor.
4. Repeat the process until all nodes are visited.

### **DFS Example:**

Consider the following graph:

```
    0
   / \
  1   2
 / \   \
3   4   5
```

Starting from node `0`, DFS would explore the graph as follows:

1. Start at node `0`, visit node `1`.
2. From node `1`, visit node `3`, then backtrack to node `1`.
3. From node `1`, visit node `4`, then backtrack to node `1`.
4. Backtrack to node `0`, then visit node `2`.
5. From node `2`, visit node `5`.

The DFS traversal would be: **0 → 1 → 3 → 4 → 2 → 5**

### **DFS Algorithm:**
1. **Mark the starting node as visited.**
2. **Recursively visit each unvisited neighbor** until all nodes are explored.


### **Implementation of DFS**

Here’s a C++ implementation of DFS using both recursive and iterative approaches:

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjacencyList;  // Adjacency list representation of the graph

    // Constructor to initialize the graph with the given number of nodes
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes);  // Resize the adjacency list to fit the total nodes
    }

    // Method to add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        adjacencyList[sourceNode].push_back(destinationNode);  // Add destination node to source node's adjacency list
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);  // For undirected graph, add the reverse edge
        }
    }

    // Recursive DFS implementation
    void dfsRecursive(int startNode, vector<bool>& visited) {
        visited[startNode] = true;  // Mark the node as visited
        cout << startNode << " ";  // Print the visited node

        // Visit all the unvisited neighbors of the current node
        for (int neighbor : adjacencyList[startNode]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);  // Recursively visit the neighbor
            }
        }
    }

    // Iterative DFS implementation using a stack
    void dfsIterative(int startNode) {
        vector<bool> visited(adjacencyList.size(), false);  // Keep track of visited nodes
        stack<int> s;  // Stack to manage the nodes

        s.push(startNode);  // Push the starting node into the stack

        while (!s.empty()) {
            int currentNode = s.top();  // Get the top node from the stack
            s.pop();  // Remove it from the stack

            if (!visited[currentNode]) {
                cout << currentNode << " ";  // Print the current node
                visited[currentNode] = true;  // Mark it as visited
            }

            // Push all unvisited neighbors of the current node into the stack
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int totalNodes = 6;  // Total number of nodes in the graph

    Graph g(totalNodes);  // Create a graph object

    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS Traversal (Recursive): ";
    vector<bool> visited(totalNodes, false);  // Visited array to track nodes
    g.dfsRecursive(0, visited);  // Perform DFS starting from node 0
    cout << endl;

    cout << "DFS Traversal (Iterative): ";
    g.dfsIterative(0);  // Perform iterative DFS starting from node 0
    cout << endl;

    return 0;
}
```
### Source Code Explanation

Let's break down the DFS implementation in C++ line by line. This will include both the **recursive** and **iterative** approaches for DFS traversal.

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
```

- **Line 1-3:** These are header files that include necessary functionalities:
  - `#include <iostream>`: Allows input and output operations (e.g., `cin`, `cout`).
  - `#include <vector>`: Enables the use of the `vector` container.
  - `#include <stack>`: Provides the `stack` container for the iterative DFS implementation.



```cpp
class Graph {
public:
    vector<vector<int>> adjacencyList;  // Adjacency list representation of the graph
```

- **Line 5-6:** Declares the `Graph` class:
  - `vector<vector<int>> adjacencyList`: This is a 2D vector (vector of vectors) used to store the adjacency list. Each node's neighbors will be stored in a list at the corresponding index.



```cpp
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes);  // Resize the adjacency list to fit the total nodes
    }
```

- **Line 8-9:** Constructor for the `Graph` class:
  - `Graph(int totalNodes)`: The constructor takes an integer (`totalNodes`) as the number of nodes in the graph.
  - `adjacencyList.resize(totalNodes)`: Resizes the `adjacencyList` to contain `totalNodes` number of empty lists. Each list will hold the neighboring nodes for each node.



```cpp
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        adjacencyList[sourceNode].push_back(destinationNode);  // Add destination node to source node's adjacency list
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);  // For undirected graph, add the reverse edge
        }
    }
```

- **Line 11-14:** Adds an edge to the graph:
  - `addEdge(int sourceNode, int destinationNode, bool isDirected = false)`: This method adds an edge from `sourceNode` to `destinationNode`. The `isDirected` flag is `false` by default, indicating an undirected graph.
  - `adjacencyList[sourceNode].push_back(destinationNode)`: Adds `destinationNode` to the adjacency list of `sourceNode`.
  - If the graph is undirected (`!isDirected`), the reverse edge is added from `destinationNode` to `sourceNode`, ensuring bidirectionality.



```cpp
    void dfsRecursive(int startNode, vector<bool>& visited) {
        visited[startNode] = true;  // Mark the node as visited
        cout << startNode << " ";  // Print the visited node
```

- **Line 16-18:** Recursive DFS method:
  - `dfsRecursive(int startNode, vector<bool>& visited)`: This method performs DFS traversal starting from `startNode`.
  - `visited[startNode] = true`: Marks the node as visited.
  - `cout << startNode << " "`: Prints the current node that is being visited.



```cpp
        for (int neighbor : adjacencyList[startNode]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);  // Recursively visit the neighbor
            }
        }
    }
```

- **Line 20-23:** Visit all unvisited neighbors of the current node:
  - `for (int neighbor : adjacencyList[startNode])`: Loops through all neighbors of `startNode` from its adjacency list.
  - `if (!visited[neighbor])`: If the neighbor hasn't been visited, we recursively call `dfsRecursive(neighbor, visited)` to visit that neighbor.
  - This ensures that we visit all connected nodes in a depth-first manner.



```cpp
    void dfsIterative(int startNode) {
        vector<bool> visited(adjacencyList.size(), false);  // Keep track of visited nodes
        stack<int> s;  // Stack to manage the nodes
```

- **Line 25-27:** Iterative DFS method:
  - `vector<bool> visited(adjacencyList.size(), false)`: Creates a `visited` vector initialized to `false` for all nodes, which tracks whether each node has been visited.
  - `stack<int> s`: Initializes a stack `s` to help manage the nodes as we explore the graph iteratively.



```cpp
        s.push(startNode);  // Push the starting node into the stack
```

- **Line 29:** Pushes the starting node into the stack, marking the beginning of our DFS traversal.



```cpp
        while (!s.empty()) {
            int currentNode = s.top();  // Get the top node from the stack
            s.pop();  // Remove it from the stack
```

- **Line 31-33:** The main iterative DFS loop:
  - `while (!s.empty())`: Continues the loop until the stack is empty.
  - `int currentNode = s.top()`: Retrieves the top node from the stack.
  - `s.pop()`: Removes the top node from the stack after processing.



```cpp
            if (!visited[currentNode]) {
                cout << currentNode << " ";  // Print the current node
                visited[currentNode] = true;  // Mark it as visited
            }
```

- **Line 35-37:** Process the current node:
  - `if (!visited[currentNode])`: Checks if the current node has been visited. If not, we process it.
  - `cout << currentNode << " "`: Prints the current node.
  - `visited[currentNode] = true`: Marks the current node as visited to prevent revisiting it.



```cpp
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);  // Push all unvisited neighbors of the current node into the stack
                }
            }
        }
    }
```

- **Line 39-42:** Explore the neighbors:
  - `for (int neighbor : adjacencyList[currentNode])`: Loops through all neighbors of the current node.
  - `if (!visited[neighbor])`: If a neighbor has not been visited, it is pushed onto the stack for future processing.



```cpp
int main() {
    int totalNodes = 6;  // Total number of nodes in the graph
```

- **Line 44:** Initializes the number of nodes in the graph to `6`.



```cpp
    Graph g(totalNodes);  // Create a graph object
```

- **Line 46:** Creates a `Graph` object `g` with `6` nodes. This initializes the graph and the adjacency list.



```cpp
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
```

- **Line 48-52:** Adds edges to the graph:
  - These calls add edges between nodes, ensuring the graph has the desired structure:
    - `0 → 1`, `0 → 2`, `1 → 3`, `1 → 4`, `2 → 5`.



```cpp
    cout << "DFS Traversal (Recursive): ";
    vector<bool> visited(totalNodes, false);  // Visited array to track nodes
    g.dfsRecursive(0, visited);  // Perform DFS starting from node 0
    cout << endl;
```

- **Line 54-57:** Performs recursive DFS traversal:
  - Initializes the `visited` array with `false`.
  - Calls `dfsRecursive(0, visited)` to start DFS from node `0`.
  - Prints the result of the recursive DFS traversal.



```cpp
    cout << "DFS Traversal (Iterative): ";
    g.dfsIterative(0);  // Perform iterative DFS starting from node 0
    cout << endl;
```

- **Line 59-61:** Performs iterative DFS traversal:
  - Calls `dfsIterative(0)` to start DFS from node `0` using an explicit stack.
  - Prints the result of the iterative DFS traversal.



```cpp
    return 0;
}
```

- **Line 63:** Exits the program.



### **Output Example:**

```
DFS Traversal (Recursive): 0 1 3 4 2 5 
DFS Traversal (Iterative): 0 1 3 4 2 5 
```

Both the recursive and iterative DFS traverse the graph starting from node `0` and visit all nodes in depth-first order.



### **Time and Space Complexity:**

#### **Time Complexity:**
- **DFS (Recursive and Iterative):** 
  - **O(V + E)**, where:
    - `V` is the number of vertices (nodes).
    - `E` is the number of edges.
  - **Explanation:** 
    - Each vertex is processed once (O(V)).
    - Each edge is explored once (O(E)).

#### **Space Complexity:**
- **DFS (Recursive):** 
  - **O(V)** due to the recursion stack and the visited array.
- **DFS (Iterative):**
  - **O(V)** for the visited array and the stack used to manage the traversal.

### **Conclusion:**
DFS is a versatile traversal technique

 for graph traversal, and both recursive and iterative methods offer efficient ways to explore graphs.
