<h1 align='center'>Shortest - Path in - Directed - Acyclic - Graph</h1>

## Problem Statement

**Problem URL :** [Shortest Path in Directed Acyclic Grpah](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0)

![image](https://github.com/user-attachments/assets/bd5a35d9-1461-49e0-9e8b-5331c7df5907)

## Problem Explanation

#### Problem Description:
You are given a **Directed Acyclic Graph (DAG)** with `V` vertices and `E` edges, where each edge has a specific weight. Your task is to find the shortest path from a given source vertex (`src`) to all other vertices in the graph. 

**Key Points to Note:**
1. The graph is **directed** and **acyclic**, meaning it does not contain any cycles.
2. Each edge has a weight, which may be positive or negative (but no negative weight cycles exist due to the acyclic property).

#### Example:
Consider the graph with 6 vertices (`V = 6`) and the following edges:
| Source | Destination | Weight |
|--|-|--|
| 0      | 1           | 5      |
| 0      | 2           | 3      |
| 1      | 2           | 2      |
| 1      | 3           | 6      |
| 2      | 3           | 7      |
| 2      | 4           | 4      |
| 2      | 5           | 2      |
| 3      | 4           | -1     |
| 4      | 5           | -2     |

If the source vertex (`src`) is `1`, the shortest path to all vertices will be:
```
Shortest Path: INF 0 2 6 5 3
```
Here, `INF` indicates that the vertex is unreachable from the source.

#### Approach to Solve:
To solve the problem, we use **Topological Sorting** and process nodes in this order to calculate the shortest paths efficiently.

1. **Topological Sorting**:
   - Since the graph is acyclic, we can order its nodes in a way such that every directed edge `(u, v)` has `u` appearing before `v`.
   - This ensures that when processing a node `u`, all nodes reachable from it have not been processed yet.

2. **Relax Edges**:
   - Using the topological order, relax all edges emanating from the current node:
     - If the current shortest distance to a node `u` is updated, propagate it to its neighbors.

#### Steps in the Approach:
1. **Build the Adjacency List**:
   - Represent the graph using an adjacency list for efficient edge traversal.

2. **Perform Topological Sorting**:
   - Use Depth-First Search (DFS) to generate a topological ordering of nodes.

3. **Calculate Shortest Paths**:
   - Using the topological order, calculate the shortest distances from the source to all nodes.

## Problem Solution
```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <stack>
#include <unordered_map>

using namespace std;

// Class representing a graph
class Graph {
public:
    // Adjacency list to store the graph as source -> {destination, weight}
    unordered_map<int, list<pair<int, int>>> adjacencyList;

    // Method to add a directed edge with a weight
    void addEdge(int source, int destination, int weight) {
        pair<int, int> edge = make_pair(destination, weight); // Create a pair of destination and weight
        adjacencyList[source].push_back(edge);               // Add the edge to the adjacency list
    }

    // Method to print the adjacency list for visualization
    void printAdjacencyList() {
        for (auto vertex : adjacencyList) {
            cout << vertex.first << " -> ";
            for (auto neighbour : vertex.second) {
                cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
            }
            cout << endl;
        }
    }

    // Helper method for topological sorting (DFS-based)
    void topologicalSort(int node, vector<int>& visited, stack<int>& sortedNodes) {
        visited[node] = true; // Mark the current node as visited

        // Recursively visit all unvisited neighbors
        for (auto neighbour : adjacencyList[node]) {
            if (!visited[neighbour.first]) {
                topologicalSort(neighbour.first, visited, sortedNodes);
            }
        }

        // Push the current node onto the stack after processing all its neighbors
        sortedNodes.push(node);
    }

    // Method to calculate the shortest path from a given source in a DAG
    void getShortestPath(int source, vector<int>& distance, stack<int>& sortedNodes) {
        distance[source] = 0; // Distance to the source itself is 0

        // Process nodes in topological order
        while (!sortedNodes.empty()) {
            int currentNode = sortedNodes.top();
            sortedNodes.pop();

            // Update distances for all neighbors if the current node has a valid distance
            if (distance[currentNode] != INT_MAX) {
                for (auto neighbour : adjacencyList[currentNode]) {
                    if (distance[currentNode] + neighbour.second < distance[neighbour.first]) {
                        distance[neighbour.first] = distance[currentNode] + neighbour.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph graph;

    // Add edges with weights to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 4, 4);
    graph.addEdge(2, 5, 2);
    graph.addEdge(3, 4, -1);
    graph.addEdge(4, 5, -2);

    // Print the adjacency list to visualize the graph
    graph.printAdjacencyList();

    int numNodes = 6;                       // Number of nodes in the graph
    stack<int> sortedNodes;                 // Stack to store nodes in topological order
    vector<int> visited(numNodes, 0);       // Visited array to keep track of visited nodes

    // Perform topological sort for all unvisited nodes
    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            graph.topologicalSort(i, visited, sortedNodes);
        }
    }

    int source = 1;                         // Source node for shortest path calculation
    vector<int> distance(numNodes, INT_MAX); // Initialize distances to infinity

    // Compute the shortest paths from the source
    graph.getShortestPath(source, distance, sortedNodes);

    // Print the shortest path distances
    cout << "Shortest Path is : ";
    for (int i = 0; i < numNodes; i++) {
        if (distance[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distance[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

```

## Problem Solution Explanation

#### **Header Files**
```cpp
#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <stack>
#include <unordered_map>
```
- **`#include <iostream>`**: Provides input and output functions.
- **`#include <vector>`**: Allows the use of dynamic arrays.
- **`#include <climits>`**: Defines constants like `INT_MAX` for maximum integer value.
- **`#include <list>`**: Used to implement adjacency lists for graph representation.
- **`#include <stack>`**: Used for the topological sort.
- **`#include <unordered_map>`**: Provides a hash map for efficient adjacency list implementation.



#### **Graph Class**
```cpp
class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adjacencyList;
```
- **`adjacencyList`**: Represents the graph as an adjacency list. 
  - **Key**: A node in the graph.
  - **Value**: A list of pairs representing the connected nodes and their weights.



#### **`addEdge` Method**
```cpp
void addEdge(int source, int destination, int weight) {
    pair<int, int> edge = make_pair(destination, weight); 
    adjacencyList[source].push_back(edge); 
}
```
- **Parameters**:
  - `source`: Starting node of the edge.
  - `destination`: Ending node of the edge.
  - `weight`: Weight of the edge.
- Adds a directed edge from `source` to `destination` with the given weight.

**Example**: 
```cpp
graph.addEdge(0, 1, 5);
```
- Adds an edge from node 0 to node 1 with weight 5.



#### **`printAdjacencyList` Method**
```cpp
void printAdjacencyList() {
    for (auto vertex : adjacencyList) {
        cout << vertex.first << " -> ";
        for (auto neighbour : vertex.second) {
            cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
        }
        cout << endl;
    }
}
```
- Iterates over the `adjacencyList`.
- Prints each node and its connected neighbors with weights.

**Example Output**:
```
0 -> (1, 5), (2, 3), 
1 -> (2, 2), (3, 6), 
...
```



#### **`topologicalSort` Method**
```cpp
void topologicalSort(int node, vector<int>& visited, stack<int>& sortedNodes) {
    visited[node] = true;

    for (auto neighbour : adjacencyList[node]) {
        if (!visited[neighbour.first]) {
            topologicalSort(neighbour.first, visited, sortedNodes);
        }
    }

    sortedNodes.push(node);
}
```
- **Purpose**: Performs a Depth-First Search (DFS) to sort nodes in topological order.
- **Parameters**:
  - `node`: Current node being processed.
  - `visited`: Tracks visited nodes.
  - `sortedNodes`: Stack to store nodes in topological order.
- **Steps**:
  1. Mark the current node as visited.
  2. Recursively visit unvisited neighbors.
  3. After visiting all neighbors, push the current node onto the stack.

**Example**:
For the graph:
```
0 -> 1, 2
1 -> 3
2 -> 3
```
Topological order: `[0, 2, 1, 3]`.



#### **`getShortestPath` Method**
```cpp
void getShortestPath(int source, vector<int>& distance, stack<int>& sortedNodes) {
    distance[source] = 0;

    while (!sortedNodes.empty()) {
        int currentNode = sortedNodes.top();
        sortedNodes.pop();

        if (distance[currentNode] != INT_MAX) {
            for (auto neighbour : adjacencyList[currentNode]) {
                if (distance[currentNode] + neighbour.second < distance[neighbour.first]) {
                    distance[neighbour.first] = distance[currentNode] + neighbour.second;
                }
            }
        }
    }
}
```
- **Purpose**: Calculates the shortest path from the `source` in a Directed Acyclic Graph (DAG).
- **Steps**:
  1. Initialize the source's distance as 0.
  2. Process nodes in topological order:
     - For each neighbor, update the distance if a shorter path is found.
     
**Example**:
For `source = 0`:
- Distance array after processing: `[0, 5, 3, 9, 7, 9]`.



#### **`main` Function**
```cpp
int main() {
    Graph graph;

    // Adding edges to the graph
    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 2);
    ...
    
    // Printing adjacency list
    graph.printAdjacencyList();
```
- Initializes the graph and adds edges using `addEdge`.



#### **Topological Sorting**
```cpp
    int numNodes = 6;
    stack<int> sortedNodes;
    vector<int> visited(numNodes, 0);

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            graph.topologicalSort(i, visited, sortedNodes);
        }
    }
```
- Performs topological sorting on all unvisited nodes.



#### **Calculating Shortest Paths**
```cpp
    int source = 1;
    vector<int> distance(numNodes, INT_MAX);
    graph.getShortestPath(source, distance, sortedNodes);

    cout << "Shortest Path is : ";
    for (int i = 0; i < numNodes; i++) {
        if (distance[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distance[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```
- Sets the `source` node and initializes distances.
- Prints the shortest path distances.

**Output**:
```
Shortest Path is : INF 0 2 6 5 3
```



### **Time Complexity**
1. **Building Adjacency List**: \( O(E) \), where \( E \) is the number of edges.
2. **Topological Sort**: \( O(V + E) \), where \( V \) is the number of vertices.
3. **Shortest Path Calculation**: \( O(V + E) \).

**Overall Complexity**: \( O(V + E) \).



### **Space Complexity**
1. **Adjacency List**: \( O(V + E) \).
2. **Visited Array**: \( O(V) \).
3. **Stack for Topological Sort**: \( O(V) \).
4. **Distance Array**: \( O(V) \).

**Overall Space Complexity**: \( O(V + E) \).
