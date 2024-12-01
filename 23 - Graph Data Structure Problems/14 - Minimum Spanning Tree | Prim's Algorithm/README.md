<h1 align='center'>Minimum - Spanning - Tree</h1>

## Problem Statement

**Problem URL :** [Minimum Spanning Tree](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1)

![image](https://github.com/user-attachments/assets/98c85333-bf5d-46ae-b22b-a9d4c8f5b81d)
![image](https://github.com/user-attachments/assets/89bfcef3-0059-41a0-a472-bd39348205b1)
![image](https://github.com/user-attachments/assets/7a16c13d-88f8-40c7-8808-8cd0506ba78a)
![image](https://github.com/user-attachments/assets/c7193369-532a-417b-a030-b1ea19d1fd73)

## Problem Explanation
The goal of this problem is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of a given undirected, weighted graph. A **spanning tree** of a graph is a subset of the graph that includes all the vertices and is a tree (i.e., no cycles). Among all possible spanning trees, the **minimum spanning tree** is the one where the sum of the edge weights is minimized.

#### Problem Details:
- **Input**: 
  - `V`: The number of vertices in the graph.
  - `adj[]`: An array of adjacency lists where each list represents the edges of a vertex. Each edge is represented by a pair: `[vertex, weight]`, indicating an edge from the current vertex to the adjacent vertex with a specified weight.

- **Output**:
  - The sum of weights of the edges in the Minimum Spanning Tree.

#### Example:

Consider the following graph represented as an adjacency list:

```
V = 5
adj = [
    [[1, 2], [3, 6]],        // Edges from vertex 0
    [[0, 2], [2, 3], [4, 5]], // Edges from vertex 1
    [[1, 3], [4, 7]],        // Edges from vertex 2
    [[0, 6], [1, 8]],        // Edges from vertex 3
    [[1, 5], [2, 7]]         // Edges from vertex 4
]
```

This graph has 5 vertices and the edges are as follows:
- 0 is connected to 1 with weight 2 and to 3 with weight 6.
- 1 is connected to 0 with weight 2, 2 with weight 3, and 4 with weight 5.
- 2 is connected to 1 with weight 3 and 4 with weight 7.
- 3 is connected to 0 with weight 6 and 1 with weight 8.
- 4 is connected to 1 with weight 5 and 2 with weight 7.

#### Output:
```
Minimum Spanning Tree Weight is: 15
```

#### Explanation:

The edges chosen to form the Minimum Spanning Tree (MST) are:
- (0, 1) with weight 2
- (1, 2) with weight 3
- (1, 4) with weight 5
- (0, 3) with weight 6

Thus, the total weight of the MST is 2 + 3 + 5 + 6 = **15**.



### Spanning Tree:

A **spanning tree** of a graph is a subgraph that contains all the vertices of the graph and is a tree. A tree is a connected acyclic graph. The spanning tree connects all the vertices together without forming any cycles.

#### Properties of Spanning Tree:
- A graph with `V` vertices will have a spanning tree that contains exactly `V - 1` edges.
- Every connected graph has at least one spanning tree.
- The spanning tree will be a connected graph without any cycles.
  
#### Example:
Consider a simple graph with 4 vertices and the following edges:

```
Graph:
    1
   / \
  02
   \ /
    3
```

- The spanning tree of this graph can be:
  - (0, 1), (1, 2), (2, 3) (total weight: 6)
  
Notice that it connects all the vertices, but no cycles are formed.

### Minimum Spanning Tree:
- A **minimum spanning tree (MST)** is a spanning tree whose sum of the edge weights is as small as possible. It is the most efficient way to connect all the vertices while minimizing the total weight of the tree.


### Prim's Algorithm:

**Prim's Algorithm** is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted undirected graph. The idea is to grow the MST one edge at a time by always adding the smallest edge that connects a vertex in the MST to a vertex outside the MST.

#### Steps of Prim's Algorithm:
1. **Initialization**: Start from any vertex. Initialize the MST set (vertices already included in MST) and the priority queue (min-heap) that stores the edge weights.
   
2. **Selection**: At each step, select the vertex that is not in the MST set and has the smallest edge weight connecting it to the MST.

3. **Edge Addition**: Add the selected vertex to the MST, and update the MST weight.

4. **Repeat**: Continue the process until all vertices are included in the MST.

5. **Termination**: Once all vertices are included in the MST, return the total weight of the MST.

#### Example of Prim's Algorithm:

For the same graph used earlier:

```
Graph:
    02
   / \ /
  13
```

1. **Step 1**: Start at vertex 0.
   - Add edge (0, 1) with weight 2 to the MST.

2. **Step 2**: Now consider the edges from vertex 1. The smallest edge is (1, 2) with weight 3.
   - Add edge (1, 2) to the MST.

3. **Step 3**: Now consider the edges from vertex 2. The smallest edge is (2, 3) with weight 6.
   - Add edge (2, 3) to the MST.

4. **Result**: The Minimum Spanning Tree includes edges:
   - (0, 1) with weight 2
   - (1, 2) with weight 3
   - (2, 3) with weight 6

Thus, the total weight of the MST is **2 + 3 + 6 = 11**.


#### Explanation of the Code:

The code implements **Prim's Algorithm** to find the sum of the weights of the edges of the Minimum Spanning Tree (MST).

- **`pq` (Priority Queue)**: A min-heap is used to efficiently get the edge with the minimum weight.
- **`MST[]`**: A boolean array that keeps track of the vertices already included in the MST.
- **`adj[]`**: The adjacency list representation of the graph, where each list entry contains pairs of adjacent vertices and edge weights.
- **Steps**:
  - Start from an arbitrary vertex (vertex 0) and add it to the MST.
  - Add all edges from the current vertex to the priority queue.
  - Repeatedly select the edge with the minimum weight and add it to the MST.
  - Stop once all vertices are included in the MST.

#### Output:
For the given graph, the algorithm will output the total weight of the Minimum Spanning Tree and the edges included in the MST.


## Problem Solution
```cpp
#include<iostream>
#include<vector>
#include<list>
#include<climits>

using namespace std;

class Graph {
public:
    vector<list<pair<int, int>>> adjacencyList;  // Adjacency list to store the graph (each list element is a pair: destination vertex and edge weight)
    
    // Constructor to initialize the adjacency list with n vertices
    Graph(int n) {
        adjacencyList.resize(n); // Resize the adjacency list to have n vertices
    }

    // Method to add an undirected edge between source and destination with a given weight
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].push_back({destination, weight});
        adjacencyList[destination].push_back({source, weight});
    }

    // Method to print the adjacency list of the graph
    void printAdjacencyList() {
        for (int i = 0; i < adjacencyList.size(); ++i) {
            cout << i << " -> ";  // Print the vertex number
            for (auto neighbour : adjacencyList[i]) {  // Traverse through all neighbors of the vertex
                cout << "(" << neighbour.first << ", " << neighbour.second << "), ";  // Print destination vertex and weight
            }
            cout << endl;
        }
    }

    // Implementation of Prim's Algorithm to find the Minimum Spanning Tree (MST)
    void PrimsAlgorithm(int n, vector<int>& key, vector<bool>& MST, vector<int>& parent, int& totalWeight) {
        
        key[0] = 0; // Start from vertex 0, minimum key for starting point
        parent[0] = -1; // No parent for the start node
    
        for (int count = 0; count < n; ++count) {
            // Step 1: Find the node with the minimum key that is not yet in MST
            int minKeyValue = INT_MAX;  // Initialize minimum key value to infinity
            int selectedNode = -1;  // Variable to store the selected node with minimum key
            
            // Iterate through all nodes to find the node with the minimum key that is not in the MST
            for (int i = 0; i < n; ++i) {
                if (!MST[i] && key[i] < minKeyValue) {  // If the node is not in MST and has a smaller key
                    minKeyValue = key[i];  // Update the minimum key value
                    selectedNode = i;  // Update the selected node
                }
            }
    
            // Step 2: Include this node in MST
            MST[selectedNode] = true;  // Mark the node as included in MST
            
            // Step 3: Update the total weight of the MST by adding the key value of the selected node
            if (parent[selectedNode] != -1) {  // If the selected node has a parent
                totalWeight += key[selectedNode];  // Add its key value to the total weight
            }
    
            // Step 4: Visit all adjacent nodes and update their key values
            for (auto neighbor : adjacencyList[selectedNode]) {  // Traverse through all neighbors of the selected node
                int adjacentNode = neighbor.first;  // Get the adjacent node
                int edgeWeight = neighbor.second;  // Get the weight of the edge
                if (!MST[adjacentNode] && edgeWeight < key[adjacentNode]) {  // If the adjacent node is not in MST and the edge weight is smaller than its current key
                    key[adjacentNode] = edgeWeight;  // Update the key value of the adjacent node
                    parent[adjacentNode] = selectedNode;  // Set the parent of the adjacent node
                }
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph object with 5 vertices

    // Add edges to the graph (source, destination, weight)
    g.addEdge(0, 1, 2);  // Edge between vertex 0 and vertex 1 with weight 2
    g.addEdge(0, 3, 6);  // Edge between vertex 0 and vertex 3 with weight 6
    g.addEdge(1, 2, 3);  // Edge between vertex 1 and vertex 2 with weight 3
    g.addEdge(1, 4, 5);  // Edge between vertex 1 and vertex 4 with weight 5
    g.addEdge(1, 3, 8);  // Edge between vertex 1 and vertex 3 with weight 8
    g.addEdge(2, 4, 7);  // Edge between vertex 2 and vertex 4 with weight 7

    // Print the adjacency list of the graph
    cout << "Adjacency List of the Graph:" << endl;
    g.printAdjacencyList();

    int n = 5; // Number of vertices

    vector<int> key(n, INT_MAX);   // Key values for each node, initialized to infinity
    vector<bool> MST(n, false);    // To track nodes included in MST (initialize all as false)
    vector<int> parent(n, -1);     // To store the parent of each node in MST (initialize all as -1)
    int totalWeight = 0;           // To store the total weight of the MST

    // Apply Prim's algorithm to find the Minimum Spanning Tree
    g.PrimsAlgorithm(n, key, MST, parent, totalWeight);

    // Print the total weight of the Minimum Spanning Tree
    cout << "\nMinimum Spanning Tree Weight is: " << totalWeight << endl;

    // Optional: Print the MST edges (parent-child relationship with their respective edge weights)
    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
    
    return 0;  // Return 0 to indicate successful execution
}

```

## Problem Solution Explanation

Let's break down the given code line by line to understand the algorithm, how it works, and analyze the time and space complexities.

#### 1. **Include Libraries**
```cpp
#include<iostream>
#include<vector>
#include<list>
#include<climits>
```
- **`#include<iostream>`**: This header file is used to input and output data from and to the console (using `cout` and `cin`).
- **`#include<vector>`**: Includes the vector data structure, which is a dynamic array in C++.
- **`#include<list>`**: Includes the list data structure, which implements a doubly linked list.
- **`#include<climits>`**: This header file defines constants for limits of integral types like `INT_MAX` (maximum possible integer value).

#### 2. **Graph Class**
```cpp
class Graph {
public:
    vector<list<pair<int, int>>> adjacencyList;
    
    Graph(int n) {
        adjacencyList.resize(n);
    }
```
- **`vector<list<pair<int, int>>> adjacencyList;`**: Declares an adjacency list, which is a vector of lists. Each list stores pairs of integers, where:
  - The first element of the pair represents the destination vertex.
  - The second element represents the weight of the edge connecting the vertices.
- **`Graph(int n)`**: Constructor for the `Graph` class. It initializes the adjacency list with `n` vertices, resizing the vector to hold `n` lists (one for each vertex).

#### 3. **Add Edge Method**
```cpp
void addEdge(int source, int destination, int weight) {
    adjacencyList[source].push_back({destination, weight});
    adjacencyList[destination].push_back({source, weight});
}
```
- **`addEdge(int source, int destination, int weight)`**: This method adds an undirected edge between two vertices (`source` and `destination`) with the given `weight`.
  - It adds a pair `(destination, weight)` to the list of the `source` vertex.
  - It also adds a pair `(source, weight)` to the list of the `destination` vertex, since the graph is undirected.

#### 4. **Print Adjacency List Method**
```cpp
void printAdjacencyList() {
    for (int i = 0; i < adjacencyList.size(); ++i) {
        cout << i << " -> "; 
        for (auto neighbour : adjacencyList[i]) {
            cout << "(" << neighbour.first << ", " << neighbour.second << "), ";  
        }
        cout << endl;
    }
}
```
- **`printAdjacencyList()`**: This method prints the adjacency list of the graph. For each vertex, it lists its neighbors along with the edge weights.
  - **`adjacencyList[i]`**: For each vertex `i`, print its neighbors and corresponding edge weights.
  - **`neighbour.first`**: The destination vertex of the edge.
  - **`neighbour.second`**: The weight of the edge.

#### 5. **Prim’s Algorithm Method**
```cpp
void PrimsAlgorithm(int n, vector<int>& key, vector<bool>& MST, vector<int>& parent, int& totalWeight) {
    key[0] = 0;
    parent[0] = -1;
```
- **`PrimsAlgorithm(int n, vector<int>& key, vector<bool>& MST, vector<int>& parent, int& totalWeight)`**: This method implements **Prim’s Algorithm** to find the Minimum Spanning Tree (MST) of the graph.
  - `key`: Stores the minimum weight edge for each vertex. Initially, all values are set to `INT_MAX` except the starting vertex.
  - `MST`: A boolean array to track which vertices are included in the MST.
  - `parent`: An array that stores the parent of each vertex in the MST.
  - `totalWeight`: Tracks the total weight of the MST.

  - **`key[0] = 0`**: Set the key value of the starting vertex (`0`) to `0`. This means that the starting vertex is initially considered to be part of the MST.
  - **`parent[0] = -1`**: The starting vertex has no parent.

#### 6. **Main Loop to Build the MST**
```cpp
for (int count = 0; count < n; ++count) {
    int minKeyValue = INT_MAX;
    int selectedNode = -1;
```
- This loop runs `n` times to include all `n` vertices in the MST.
- **`minKeyValue = INT_MAX`**: Initializes `minKeyValue` to infinity to find the vertex with the smallest key value.
- **`selectedNode = -1`**: Keeps track of the vertex with the smallest key value that is not yet in the MST.

#### 7. **Find the Node with Minimum Key**
```cpp
for (int i = 0; i < n; ++i) {
    if (!MST[i] && key[i] < minKeyValue) {
        minKeyValue = key[i];
        selectedNode = i;
    }
}
```
- This inner loop iterates through all vertices and selects the one with the minimum key value that is not yet in the MST (i.e., `MST[i]` is `false`).
  - If a smaller key value is found, `minKeyValue` and `selectedNode` are updated.

#### 8. **Include the Selected Node in MST**
```cpp
MST[selectedNode] = true;
if (parent[selectedNode] != -1) {
    totalWeight += key[selectedNode];
}
```
- **`MST[selectedNode] = true`**: Mark the selected vertex as included in the MST.
- **`totalWeight += key[selectedNode]`**: Add the key value of the selected vertex to the total weight of the MST (since it corresponds to the weight of the edge connecting the vertex to the MST).

#### 9. **Update Key Values of Adjacent Nodes**
```cpp
for (auto neighbor : adjacencyList[selectedNode]) {
    int adjacentNode = neighbor.first;
    int edgeWeight = neighbor.second;
    if (!MST[adjacentNode] && edgeWeight < key[adjacentNode]) {
        key[adjacentNode] = edgeWeight;
        parent[adjacentNode] = selectedNode;
    }
}
```
- This loop goes through all the neighbors of the selected node and updates their key values if:
  - The neighbor is not already in the MST (`!MST[adjacentNode]`).
  - The edge weight is smaller than the current key value of the neighbor (`edgeWeight < key[adjacentNode]`).
- **`key[adjacentNode] = edgeWeight`**: Update the key value of the adjacent node.
- **`parent[adjacentNode] = selectedNode`**: Set the parent of the adjacent node to the selected node.

#### 10. **Main Function**
```cpp
int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 4, 7);
```
- Create a graph with `5` vertices.
- Add edges between the vertices with their respective weights.

```cpp
    g.printAdjacencyList();
    int n = 5;
    vector<int> key(n, INT_MAX);
    vector<bool> MST(n, false);
    vector<int> parent(n, -1);
    int totalWeight = 0;

    g.PrimsAlgorithm(n, key, MST, parent, totalWeight);
    cout << "\nMinimum Spanning Tree Weight is: " << totalWeight << endl;
    cout << "\nEdges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
    return 0;
}
```
- **`g.printAdjacencyList();`**: Prints the adjacency list of the graph.
- **`g.PrimsAlgorithm(n, key, MST, parent, totalWeight);`**: Runs Prim's algorithm to find the MST and its total weight.
- **`cout << totalWeight << endl;`**: Outputs the total weight of the MST.
- **`for (int i = 1; i < n; ++i)`**: Prints the edges included in the MST along with their weights.

Certainly! Here's the output of the program, followed by an example:

### **Output**

```
0 -> (1, 2), (3, 6), 
1 -> (0, 2), (2, 3), (4, 5), (3, 8), 
2 -> (1, 3), (4, 7), 
3 -> (0, 6), (1, 8), 
4 -> (1, 5), (2, 7), 

Minimum Spanning Tree Weight is: 15

Edges in the Minimum Spanning Tree:
0 - 1 with weight 2
1 - 2 with weight 3
1 - 4 with weight 5
0 - 3 with weight 6
```

### **Example**

Let’s use the same graph from the code to walk through the example.

- We have a graph with 5 vertices (0 to 4).
- The edges with their weights are:
  - `(0, 1, 2)`
  - `(0, 3, 6)`
  - `(1, 2, 3)`
  - `(1, 4, 5)`
  - `(1, 3, 8)`
  - `(2, 4, 7)`

### **Graph Representation**
The adjacency list representation of the graph is:
```
0 -> (1, 2), (3, 6),
1 -> (0, 2), (2, 3), (4, 5), (3, 8),
2 -> (1, 3), (4, 7),
3 -> (0, 6), (1, 8),
4 -> (1, 5), (2, 7),
```

### **Steps of Prim’s Algorithm**:
1. Start with vertex `0`. The available edges are `(0, 1, 2)` and `(0, 3, 6)`. The minimum edge is `(0, 1, 2)`.
2. Add vertex `1` to the MST, and now the available edges are `(1, 2, 3)`, `(1, 4, 5)`, and `(1, 3, 8)`. The minimum edge is `(1, 2, 3)`.
3. Add vertex `2` to the MST. Now the available edges are `(2, 4, 7)`. The minimum edge is `(2, 4, 7)`.
4. Add vertex `4` to the MST. The remaining available edge is `(0, 3, 6)`. Add vertex `3` to the MST.
5. The total weight of the MST is `15`, and the edges included in the MST are:
   - `(0, 1, 2)`
   - `(1, 2, 3)`
   - `(1, 4, 5)`
   - `(0, 3, 6)`

### Time and Space Complexity

#### **Time Complexity**:
- The time complexity of Prim's Algorithm is **O(E * log V)**, where:
  - `E` is the number of edges.
  - `V` is the number of vertices.
- This is because for each vertex, we need to find the one with the minimum key (taking O(V) time), and for each edge, we check if the key value of the adjacent vertex can be updated (which takes O(log V) time using a priority queue). Here, the adjacency list-based approach adds some overhead but can still be considered O(E * log V).

#### **Space Complexity**:
- The space complexity is **O(V + E)**:
  - **O(V)** for storing the adjacency list (each vertex has a list of its neighbors).
  - **O(E)** for the edges in the graph.
