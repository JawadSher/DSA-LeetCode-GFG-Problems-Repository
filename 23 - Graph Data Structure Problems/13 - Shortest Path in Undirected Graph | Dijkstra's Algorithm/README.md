<h1 align='center'>Shortest - Path in - Undirected - Graph</h1>

## Problem Statement

The task is to find the shortest path from a source node to all other nodes in an **undirected weighted graph**. This means:
- The graph has no direction; edges connect nodes bidirectionally.
- Each edge has a specific weight (cost).
- The goal is to calculate the minimum cost (shortest distance) from the source node to all other nodes.

##### **Example for Understanding:**
Consider the graph below:

```
Nodes: 0, 1, 2, 3
Edges:
0 --(5)-- 1
0 --(8)-- 2
1 --(9)-- 2
1 --(2)-- 3
2 --(6)-- 3
```

If the source node is `0`, the shortest paths are:
- Distance to node `1`: 5 (via edge 0 -> 1)
- Distance to node `2`: 8 (via edge 0 -> 2)
- Distance to node `3`: 7 (via path 0 -> 1 -> 3)

## Problem Explanation

### Dijkstra's Algorithm
Dijkstra's Algorithm is a **greedy algorithm** used to find the shortest path from a **single source node** to all other nodes in a graph. It works for graphs with **non-negative weights** and ensures that at the end of the algorithm:
- The shortest distance from the source node to every other node is determined.

#### **Approach to Dijkstra's Algorithm**

##### **Step 1: Initialization**
1. Create a `distance` array:
   - Set the distance to the source node as `0`.
   - Set the distances to all other nodes as infinity (`∞`), indicating they are initially unreachable.

2. Use a **priority queue** or a **set** to store nodes along with their current distances in the format `(distance, node)`.



##### **Step 2: Process the Graph**
1. Start with the source node:
   - Remove the node with the smallest distance from the priority queue or set.
   - Mark this node as processed (its shortest distance is now finalized).

2. For each **neighbor** of the current node:
   - Calculate the new potential distance to the neighbor:  
     `distance[current_node] + edge_weight`.
   - If this new distance is shorter than the previously known distance:
     - Update the distance of the neighbor.
     - Add the neighbor to the priority queue or set with the updated distance.



##### **Step 3: Repeat Until All Nodes are Processed**
- Continue removing nodes with the smallest distance and updating their neighbors.
- Once all nodes are processed, the `distance` array will hold the shortest distances from the source node to all other nodes.



#### **Detailed Example**

##### **Graph Representation**
Consider the following graph:

```
Nodes: 0, 1, 2, 3
Edges and Weights:
0 --(5)-- 1
0 --(8)-- 2
1 --(9)-- 2
1 --(2)-- 3
2 --(6)-- 3
```

#### **Objective**
Find the shortest path from the source node `0` to all other nodes.

#### **Step-by-Step Execution**

1. **Initialization**:
   - Distance array: `[0, ∞, ∞, ∞]` (Distance to `0` is `0`, all others are `∞`).
   - Priority queue (or set): `[(0, 0)]` (Start with source node `0`).



2. **Process Node 0**:
   - Current node: `0`, Distance: `0`.
   - Neighbors:
     - `1`: New distance = `0 + 5 = 5`. Update distance for `1`.
     - `2`: New distance = `0 + 8 = 8`. Update distance for `2`.

   **Updated Distance Array**: `[0, 5, 8, ∞]`  
   **Updated Priority Queue**: `[(5, 1), (8, 2)]`



3. **Process Node 1**:
   - Current node: `1`, Distance: `5`.
   - Neighbors:
     - `0`: Already processed, skip.
     - `2`: New distance = `5 + 9 = 14` (not shorter than `8`). Skip.
     - `3`: New distance = `5 + 2 = 7`. Update distance for `3`.

   **Updated Distance Array**: `[0, 5, 8, 7]`  
   **Updated Priority Queue**: `[(7, 3), (8, 2)]`



4. **Process Node 3**:
   - Current node: `3`, Distance: `7`.
   - Neighbors:
     - `1`: Already processed, skip.
     - `2`: New distance = `7 + 6 = 13` (not shorter than `8`). Skip.

   **Updated Distance Array**: `[0, 5, 8, 7]`  
   **Updated Priority Queue**: `[(8, 2)]`



5. **Process Node 2**:
   - Current node: `2`, Distance: `8`.
   - Neighbors:
     - `0`, `1`, `3`: Already processed, skip.

   **Final Distance Array**: `[0, 5, 8, 7]`  
   **Priority Queue**: Empty.



#### **Final Results**
The shortest distances from node `0` are:
- To node `0`: 0
- To node `1`: 5
- To node `2`: 8
- To node `3`: 7



#### **Visualizing the Process**
1. **Start**:  
   - Distance: `[0, ∞, ∞, ∞]`.

2. **After Processing Node 0**:  
   - Distance: `[0, 5, 8, ∞]`.

3. **After Processing Node 1**:  
   - Distance: `[0, 5, 8, 7]`.

4. **After Processing Node 3**:  
   - Distance: `[0, 5, 8, 7]`.

5. **After Processing Node 2**:  
   - Distance: `[0, 5, 8, 7]`.



#### **Key Characteristics of Dijkstra’s Algorithm**

1. **Greedy Nature**:  
   - It always picks the node with the smallest known distance to process next.

2. **Limitation**:  
   - It does not work with negative edge weights. For such cases, use **Bellman-Ford Algorithm**.

3. **Efficient for Sparse Graphs**:  
   - It is efficient when implemented with a priority queue or min-heap.



#### **Time and Space Complexity**

#### **Time Complexity**:
1. **Initialization**: \(O(V)\), where \(V\) is the number of vertices.
2. **Processing Edges**: Each edge is relaxed once: \(O(E \log V)\), where \(E\) is the number of edges.
   - Logarithmic factor comes from using a priority queue.

**Total**: \(O((V + E) \log V)\).

#### **Space Complexity**:
1. **Graph Storage**: \(O(V + E)\) for the adjacency list.
2. **Distance Array**: \(O(V)\).
3. **Priority Queue**: \(O(V)\).

**Total**: \(O(V + E)\).


#### **Practice Problems for Dijkstra's Algorithm**
1. Find the shortest path in:
   - Directed graphs.
   - Graphs with more than one source node.
2. Extend Dijkstra's Algorithm to return the actual path, not just distances.

Understanding Dijkstra's Algorithm thoroughly will help tackle many shortest-path problems in real-world applications and competitive programming.

## Problem Solution
```cpp
#include <iostream>
#include <climits>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

// Graph class to represent the graph structure
class graph {
public:
    // Adjacency list to store the graph. Each node maps to a list of pairs (neighbor, weight)
    unordered_map<int, list<pair<int, int>>> adjacencyList;

    // Function to add an edge between two nodes with a specified weight
    void addEdge(int source, int destination, int weight) {
        // Create pairs representing the edge and its weight
        pair<int, int> u = make_pair(destination, weight); // Edge from source to destination
        pair<int, int> v = make_pair(source, weight);      // Edge from destination to source (since the graph is undirected)

        // Add the edge to the adjacency list
        adjacencyList[source].push_back(u);
        adjacencyList[destination].push_back(v);
    }

    // Function to print the adjacency list representation of the graph
    void printAdjacencyList() {
        for (auto vertex : adjacencyList) { // Loop through each vertex in the adjacency list
            cout << vertex.first << " -> "; // Print the current vertex
            for (auto neighbour : vertex.second) // Loop through its neighbors
                cout << "(" << neighbour.first << ", " << neighbour.second << "), "; // Print neighbor and weight
            cout << endl;
        }
    }

    // Function to implement Dijkstra's Algorithm
    void DijkstraAlgorithm(int node, vector<int>& distance, set<pair<int, int>>& Set) {
        // Insert the source node with distance 0 into the set
        Set.insert({0, node});
        distance[node] = 0; // Initialize the source node's distance to 0

        // Process the set until it is empty
        while (!Set.empty()) {
            // Get the node with the smallest distance (top of the set)
            auto top = *(Set.begin());
            int nodeDistance = top.first; // Distance of the current node
            int currNode = top.second;    // Current node being processed

            // Remove the processed node from the set
            Set.erase(Set.begin());

            // Traverse all neighbors of the current node
            for (auto neighbour : adjacencyList[currNode]) {
                int neighborNode = neighbour.first;  // Neighbor node
                int edgeWeight = neighbour.second;   // Weight of the edge to the neighbor

                // Check if a shorter path to the neighbor exists
                if (nodeDistance + edgeWeight < distance[neighborNode]) {
                    // If the neighbor is already in the set, remove the old record
                    auto record = Set.find({distance[neighborNode], neighborNode});
                    if (record != Set.end())
                        Set.erase(record);

                    // Update the distance to the neighbor
                    distance[neighborNode] = nodeDistance + edgeWeight;

                    // Insert the updated record into the set
                    Set.insert({distance[neighborNode], neighborNode});
                }
            }
        }
    }
};

int main() {
    graph g; // Create a graph object

    // Add edges to the graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 6);

    // Print the adjacency list of the graph
    g.printAdjacencyList();

    int n = 4; // Number of nodes in the graph
    vector<int> distance(n, INT_MAX); // Initialize distances to all nodes as infinity (INT_MAX)
    set<pair<int, int>> Set; // Min-heap implemented using a set to store (distance, node) pairs

    int src = 0; // Define the source node for Dijkstra's algorithm
    g.DijkstraAlgorithm(src, distance, Set); // Call Dijkstra's algorithm

    // Print the shortest distances from the source node to all other nodes
    cout << "Shortest distances from node " << src << ":" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (distance[i] == INT_MAX) // If the distance is still infinity, the node is unreachable
            cout << "INF" << endl;
        else
            cout << distance[i] << endl; // Print the distance to the node
    }

    return 0;
}

```

## Problem Solution Explanation

#### **Header Files and Namespace**
```cpp
#include <iostream>
#include <climits>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>
```
- **`#include <iostream>`**: Used for input/output operations like `cout`.
- **`#include <climits>`**: Provides `INT_MAX`, representing the maximum value of an integer (used to represent infinity).
- **`#include <set>`**: Implements a balanced binary search tree to efficiently store `(distance, node)` pairs.
- **`#include <list>`**: Implements adjacency lists to store neighbors of a node.
- **`#include <vector>`**: For storing distances and other linear data structures.
- **`#include <unordered_map>`**: Provides hash table implementation for adjacency list mapping.

```cpp
using namespace std;
```
- Simplifies code by avoiding the need to prefix `std::` before standard library functions.



#### **Graph Class Declaration**
```cpp
class graph {
public:
    unordered_map<int, list<pair<int, int>>> adjacencyList;
```
- **`unordered_map<int, list<pair<int, int>>>`**: Represents the graph using an adjacency list.
  - Key (`int`): A node in the graph.
  - Value (`list<pair<int, int>>`): A list of pairs where each pair consists of:
    - Neighbor node.
    - Weight of the edge to the neighbor.



#### **Adding Edges to the Graph**
```cpp
void addEdge(int source, int destination, int weight) {
    pair<int, int> u = make_pair(destination, weight);
    pair<int, int> v = make_pair(source, weight);

    adjacencyList[source].push_back(u);
    adjacencyList[destination].push_back(v);
}
```
- **`addEdge`**: Adds a bidirectional edge (undirected graph) between `source` and `destination` with the specified `weight`.
- **`make_pair(destination, weight)`**: Creates a pair representing the edge.
- **`push_back(u)`**: Adds the edge to the adjacency list of `source`.
- Similarly, the reverse edge is added for `destination` since the graph is undirected.



#### **Printing the Adjacency List**
```cpp
void printAdjacencyList() {
    for (auto vertex : adjacencyList) {
        cout << vertex.first << " -> ";
        for (auto neighbour : vertex.second)
            cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
        cout << endl;
    }
}
```
- Iterates through the adjacency list to print each node and its neighbors.
- **`vertex.first`**: The current node.
- **`vertex.second`**: The list of neighbors for the current node.
- Example Output for this graph:
  ```
  0 -> (1, 5), (2, 8),
  1 -> (0, 5), (2, 9), (3, 2),
  2 -> (0, 8), (1, 9), (3, 6),
  3 -> (1, 2), (2, 6),
  ```



#### **Dijkstra's Algorithm Implementation**
```cpp
void DijkstraAlgorithm(int node, vector<int>& distance, set<pair<int, int>>& Set) {
```
- **Parameters**:
  - `node`: Source node for the algorithm.
  - `distance`: Vector storing the shortest distance from the source to all nodes.
  - `Set`: Min-heap using `set` to store `(distance, node)` pairs.



##### **Initialization**
```cpp
Set.insert({0, node});
distance[node] = 0;
```
- **`Set.insert({0, node})`**: Insert the source node with a distance of 0 into the set.
- **`distance[node] = 0`**: Initialize the source node's distance to `0`.



##### **Processing Nodes**
```cpp
while (!Set.empty()) {
    auto top = *(Set.begin());
    int nodeDistance = top.first;
    int currNode = top.second;

    Set.erase(Set.begin());
```
- **`while (!Set.empty())`**: Process until all nodes are handled.
- **`Set.begin()`**: Retrieves the node with the smallest distance.
- **`Set.erase(Set.begin())`**: Remove the processed node from the set.



##### **Updating Neighbors**
```cpp
for (auto neighbour : adjacencyList[currNode]) {
    int neighborNode = neighbour.first;
    int edgeWeight = neighbour.second;

    if (nodeDistance + edgeWeight < distance[neighborNode]) {
        auto record = Set.find({distance[neighborNode], neighborNode});
        if (record != Set.end())
            Set.erase(record);

        distance[neighborNode] = nodeDistance + edgeWeight;
        Set.insert({distance[neighborNode], neighborNode});
    }
}
```
- **Neighbor Processing**:
  - Calculate the new distance: `nodeDistance + edgeWeight`.
  - If the new distance is shorter than the current distance:
    - Remove the old record from the set (if it exists).
    - Update the distance in the `distance` array.
    - Insert the updated `(distance, node)` pair back into the set.



#### **Main Function**
```cpp
int main() {
    graph g;
```
- **`graph g;`**: Create a graph object.

##### **Add Edges**
```cpp
g.addEdge(0, 1, 5);
g.addEdge(0, 2, 8);
g.addEdge(1, 2, 9);
g.addEdge(1, 3, 2);
g.addEdge(2, 3, 6);
```
- Add edges to the graph with weights.



##### **Run Dijkstra's Algorithm**
```cpp
vector<int> distance(n, INT_MAX);
set<pair<int, int>> Set;

g.DijkstraAlgorithm(src, distance, Set);
```
- **`distance(n, INT_MAX)`**: Initialize distances as infinity.
- **`DijkstraAlgorithm`**: Compute the shortest distances from the source node.



##### **Output Results**
```cpp
for (int i = 0; i < n; i++) {
    cout << "Node " << i << ": ";
    if (distance[i] == INT_MAX)
        cout << "INF" << endl;
    else
        cout << distance[i] << endl;
}
```
- Print the shortest distances from the source to all nodes.
- Example Output:
  ```
  Node 0: 0
  Node 1: 5
  Node 2: 8
  Node 3: 7
  ```



### **Time and Space Complexity**

#### **Time Complexity**
1. **Set Operations**:
   - Insertions and deletions: \(O(\log V)\) per operation.
   - For \(E\) edges and \(V\) vertices: \(O(E \log V)\).
2. **Total**: \(O((V + E) \log V)\).

#### **Space Complexity**
1. **Adjacency List**: \(O(V + E)\).
2. **Distance Array**: \(O(V)\).
3. **Set**: \(O(V)\).
4. **Total**: \(O(V + E)\).
