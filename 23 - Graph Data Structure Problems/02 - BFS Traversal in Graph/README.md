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

    // Iterative BFS traversal
    void bfs(int startNode) {
        vector<bool> visited(adjacencyList.size(), false); // Visited array
        queue<int> q; // Queue for BFS

        // Start BFS from the startNode
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal (Iterative): ";

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

    // Recursive BFS traversal
    void bfsRecursiveHelper(int startNode, vector<bool>& visited, queue<int>& q) {
        if (q.empty()) {
            return;  // Base case: queue is empty, stop recursion
        }

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

        // Recursive call with the updated queue
        bfsRecursiveHelper(startNode, visited, q);
    }

    void bfsRecursive(int startNode) {
        vector<bool> visited(adjacencyList.size(), false); // Visited array
        queue<int> q; // Queue for BFS

        // Start BFS from the startNode
        visited[startNode] = true;
        q.push(startNode);

        cout << "BFS Traversal (Recursive): ";

        // Start recursive BFS traversal
        bfsRecursiveHelper(startNode, visited, q);

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

    // Perform BFS traversal starting from node 0 (Iterative)
    g.bfs(0);

    // Perform BFS traversal starting from node 0 (Recursive)
    g.bfsRecursive(0);

    return 0;
}

```

### Source Code Explanation

#### 1. **Graph Class:**

The `Graph` class manages the graph structure using an **adjacency list** to store the neighbors of each node.

##### **Constructor:**
```cpp
Graph(int totalNodes) {
    adjacencyList.resize(totalNodes);
}
```
- The constructor initializes the graph by resizing the adjacency list to hold the `totalNodes`. Each node initially has an empty list of neighbors.

##### **addEdge Function:**
```cpp
void addEdge(int sourceNode, int destinationNode, bool isDirected = false) {
    adjacencyList[sourceNode].push_back(destinationNode);
    if (!isDirected) {
        adjacencyList[destinationNode].push_back(sourceNode);
    }
}
```
- `addEdge` adds an edge from `sourceNode` to `destinationNode`. If the graph is undirected (default behavior), it adds the reverse edge from `destinationNode` to `sourceNode`.

#### 2. **BFS (Iterative) Implementation:**

##### **BFS Function:**
```cpp
void bfs(int startNode) {
    vector<bool> visited(adjacencyList.size(), false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal (Iterative): ";

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

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

- **Explanation:**
  - The function takes `startNode` as input and performs a **Breadth-First Search** (BFS) starting from that node.
  - `visited` array ensures that no node is visited more than once.
  - A `queue` is used to manage the nodes to visit next. We push the `startNode` into the queue and mark it as visited.
  - The BFS traversal proceeds by dequeuing nodes from the front of the queue and processing them. Then, all their unvisited neighbors are pushed into the queue.

#### 3. **BFS (Recursive) Implementation:**

##### **Recursive Helper Function:**
```cpp
void bfsRecursiveHelper(int startNode, vector<bool>& visited, queue<int>& q) {
    if (q.empty()) {
        return;  // Base case: queue is empty, stop recursion
    }

    int currentNode = q.front();
    q.pop();
    cout << currentNode << " ";

    for (int neighbor : adjacencyList[currentNode]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    bfsRecursiveHelper(startNode, visited, q);  // Recursive call
}
```
- **Explanation:**
  - This helper function is designed to perform the recursive part of BFS.
  - It processes nodes in a similar way to the iterative BFS but using recursion to handle the queue management.
  - If the queue is empty, the recursion terminates. Otherwise, it pops a node from the queue, processes it, and pushes all its unvisited neighbors into the queue, making a recursive call after each step.

##### **Main Recursive BFS Function:**
```cpp
void bfsRecursive(int startNode) {
    vector<bool> visited(adjacencyList.size(), false);
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal (Recursive): ";
    bfsRecursiveHelper(startNode, visited, q);
    cout << endl;
}
```
- This function initializes the `visited` array and the queue, starting from `startNode`, and calls the recursive helper to perform the BFS traversal.

#### 4. **Main Function:**
```cpp
int main() {
    int totalNodes = 6;
    Graph g(totalNodes);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.bfs(0);         // Iterative BFS starting from node 0
    g.bfsRecursive(0); // Recursive BFS starting from node 0

    return 0;
}
```
- Creates a graph with 6 nodes.
- Adds edges to the graph.
- Calls both the **Iterative BFS** (`g.bfs(0)`) and **Recursive BFS** (`g.bfsRecursive(0)`) functions to perform BFS starting from node `0`.

### **Output:**

```
BFS Traversal (Iterative): 0 1 2 3 4 5 
BFS Traversal (Recursive): 0 1 2 3 4 5
```

### **Time and Space Complexity:**

#### **Time Complexity:**
- Both **Iterative BFS** and **Recursive BFS** have the same time complexity:
  - **O(V + E)**, where:
    - `V` is the number of vertices (nodes) in the graph.
    - `E` is the number of edges in the graph.
  - We visit each vertex and edge exactly once.

#### **Space Complexity:**
- **O(V)**:
  - The space is mainly used for the `visited` array (of size `V`), the queue (`O(V)`), and the recursion stack in the recursive approach (`O(V)` in the worst case).

### **Conclusion:**
- **Iterative BFS** is more common and efficient in terms of stack space, as it avoids recursion depth limitations.
- **Recursive BFS** is an interesting implementation that can be used for educational purposes, but it may suffer from stack overflow issues for large graphs.

