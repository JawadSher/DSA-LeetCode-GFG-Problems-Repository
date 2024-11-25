<h1 align='center'>BFS - Traversal - In Graph</h1>

**Breadth-First Search (BFS)** is a graph traversal algorithm used to explore nodes and edges in a graph systematically. It starts at a given source node and explores all its neighboring nodes before moving to the neighbors of those neighbors, essentially performing a level-order traversal.

BFS is particularly useful for:
1. **Finding the shortest path** in an unweighted graph.
2. Checking graph connectivity.
3. Solving problems like bipartite graph detection, maze problems, and more.

#### **Characteristics of BFS**:
- Uses a **queue** to keep track of nodes to visit.
- Traverses the graph **level by level**.
- Ensures that all nodes at a given "depth" from the source node are visited before moving to the next depth.


### **Example of BFS**

**Graph**:  
Let's consider the following undirected graph:

```
    0
   / \
  1   2
 / \   \
3   4   5
```

#### BFS Traversal:
If we start BFS from node `0`, the order of traversal will be:
```
Level 0: 0
Level 1: 1, 2
Level 2: 3, 4, 5
```

So the BFS traversal order is: `0 -> 1 -> 2 -> 3 -> 4 -> 5`.


### **Approach to Implement BFS**

1. **Initialize a Queue**:
   - Use a queue to keep track of the nodes to be visited. Push the starting node into the queue.

2. **Visited Array**:
   - Maintain a `visited` array to mark nodes that have already been visited to avoid revisiting them.

3. **Process Nodes**:
   - While the queue is not empty:
     - Pop the front node from the queue.
     - Process it (e.g., print it or store it in the result).
     - Push all its unvisited neighbors into the queue and mark them as visited.

4. **End Traversal**:
   - Once the queue is empty, BFS is complete.

### **Implementation of BFS**

Here’s how BFS can be implemented for a graph using an adjacency list:

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph class definition
class Graph {
public:
    vector<vector<int>> adjacencyList;

    // Constructor to initialize the adjacency list
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes);
    }

    // Function to add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        adjacencyList[sourceNode].push_back(destinationNode);
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);
        }
    }

    // Function to perform BFS traversal
    void bfs(int startNode) {
        vector<bool> visited(adjacencyList.size(), false); // Visited array
        queue<int> q; // Queue for BFS

        // Start BFS from the startNode
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            // Process the current node (e.g., print it)
            cout << currentNode << " ";

            // Visit all unvisited neighbors
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int totalNodes = 6;

    // Create the graph
    Graph g(totalNodes);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform BFS traversal starting from node 0
    g.bfs(0);

    return 0;
}
```

### Source Code Explanation
Here’s a **line-by-line explanation** of the BFS traversal code with examples and the corresponding output:

### **Code Explanation**

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
```

- **Purpose**: These are essential header files.
  - `#include <iostream>`: For input/output operations.
  - `#include <vector>`: For using the adjacency list as a vector of vectors.
  - `#include <queue>`: BFS requires a queue to manage nodes to visit.


```cpp
class Graph {
public:
    vector<vector<int>> adjacencyList;
```

- **Explanation**: 
  - A class named `Graph` is defined.
  - `adjacencyList`: A vector of vectors to represent the graph. Each index `i` holds a list of nodes connected to node `i`.



```cpp
    Graph(int totalNodes) {
        adjacencyList.resize(totalNodes);
    }
```

- **Explanation**: 
  - Constructor initializes the graph with `totalNodes` nodes.
  - Resizes the `adjacencyList` to ensure every node has an associated list.



```cpp
    void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
        adjacencyList[sourceNode].push_back(destinationNode);
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);
        }
    }
```

- **Purpose**: Adds edges between nodes.
- **Parameters**:
  - `sourceNode`: Start of the edge.
  - `destinationNode`: End of the edge.
  - `isDirected`: If `true`, the edge is one-way; otherwise, it is bidirectional.
- **How it works**:
  - Adds `destinationNode` to `sourceNode`'s adjacency list.
  - If the graph is undirected, it also adds `sourceNode` to `destinationNode`'s adjacency list.



```cpp
    void bfs(int startNode) {
        vector<bool> visited(adjacencyList.size(), false);
        queue<int> q;
```

- **Explanation**:
  - Initializes a `visited` array to track visited nodes.
  - A queue `q` is used to manage BFS traversal.



```cpp
        visited[startNode] = true;
        q.push(startNode);
```

- **Explanation**:
  - Marks the `startNode` as visited.
  - Pushes the `startNode` into the queue to begin traversal.



```cpp
        cout << "BFS Traversal: ";
```

- **Explanation**: Outputs a label for the BFS traversal results.


```cpp
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
```

- **Explanation**:
  - The loop continues until the queue is empty.
  - Retrieves the front node of the queue (`currentNode`) and removes it.



```cpp
            cout << currentNode << " ";
```

- **Explanation**: Prints the `currentNode` to show its processing in BFS.


```cpp
            for (int neighbor : adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
```

- **Explanation**:
  - Iterates through all neighbors of the `currentNode`.
  - If a neighbor has not been visited:
    - Marks it as visited.
    - Adds it to the queue for future processing.



```cpp
int main() {
    int totalNodes = 6;

    // Create the graph
    Graph g(totalNodes);
```

- **Explanation**:
  - Declares `totalNodes` as `6`.
  - Creates a graph object `g` with `6` nodes.


```cpp
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
```

- **Explanation**:
  - Adds edges to the graph:
    - Node `0` is connected to nodes `1` and `2`.
    - Node `1` is connected to nodes `3` and `4`.
    - Node `2` is connected to node `5`.


```cpp
    g.bfs(0);

    return 0;
}
```

- **Explanation**:
  - Calls `bfs(0)` to perform BFS starting from node `0`.
  - Returns `0` to indicate successful program execution.


### **Graph Representation**

The graph looks like this:

```
    0
   / \
  1   2
 / \   \
3   4   5
```


### **Output**

```
BFS Traversal: 0 1 2 3 4 5
```

- **Explanation**:
  - BFS starts at node `0`.
  - Visits nodes `1` and `2` (neighbors of `0`).
  - Then visits nodes `3` and `4` (neighbors of `1`) and finally node `5` (neighbor of `2`).

### **Time Complexity**

1. **Adjacency List Traversal**:
   - Each edge is visited once: **O(E)**.
   - Each node is visited once: **O(V)**.

   Total Time Complexity: **O(V + E)**.


### **Space Complexity**

1. **Visited Array**: Stores the state of each node: **O(V)**.
2. **Queue**: Can hold up to **O(V)** nodes.
3. **Adjacency List**: Takes **O(V + E)**.

   Total Space Complexity: **O(V + E)**.

