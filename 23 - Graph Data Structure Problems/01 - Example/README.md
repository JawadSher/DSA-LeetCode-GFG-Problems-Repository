<h1 align="center">Graph - Data Structure - Example</h1>

## **What is a Graph?**

A **Graph** is a data structure that models relationships or connections between entities, represented by **vertices (nodes)** and **edges (connections)**. It is a powerful tool for solving problems in various domains, such as computer science, social networks, and transportation.



### **Key Components of a Graph**
1. **Vertices (Nodes):** Represent entities or objects, such as cities, people, or devices.
   - Example: In a social network, each person can be a node.
2. **Edges (Connections):** Represent relationships or links between nodes.
   - Example: A friendship between two people is an edge in the social network.



## **Types of Graphs**

### 1. **Directed Graph (Digraph)**

- **Definition:** In a directed graph, each edge has a direction. If there’s an edge from vertex `u` to `v`, it implies a one-way connection.
  
- **Example:** 
  Imagine a task dependency chart where task A must be done before B:
  ```
  A --> B --> C
  ```
  - Here, `A` directs to `B`, and `B` directs to `C`.

- **Applications:** 
  - Webpage links (A webpage links to another page).
  - Task scheduling (one task depends on another).



### 2. **Undirected Graph**

- **Definition:** In an undirected graph, edges have no direction. If there’s an edge between `u` and `v`, they are bidirectionally connected.
  
- **Example:** 
  Think of a map where roads connect cities in both directions:
  ```
  A -- B -- C
  ```
  - Here, `A` and `B` are connected, and `B` and `C` are connected.

- **Applications:** 
  - Social networks (mutual friendships).
  - Transportation networks (two-way roads).



### **Degree of a Vertex**

The **degree** of a vertex is the number of edges connected to it.

#### **Types of Degrees in Graphs:**
1. **In-degree:** Number of incoming edges to a vertex (for directed graphs).
2. **Out-degree:** Number of outgoing edges from a vertex (for directed graphs).
3. **Total Degree:** Total number of edges connected to a vertex (applies to both directed and undirected graphs).

**Example:**
- For a directed graph:  
  ```
  A --> B --> C
  ```
  - **In-degree of B:** 1 (edge comes from A).
  - **Out-degree of B:** 1 (edge goes to C).
  - **Total degree of B:** 2.

- For an undirected graph:  
  ```
  A -- B -- C
  ```
  - **Degree of B:** 2 (connected to A and C).



### **Weighted Graphs**

A **weighted graph** assigns a weight (cost, distance, or time) to each edge.

#### **Example (Undirected Weighted Graph):**
- **Vertices:** A, B, C
- **Edges:** 
  ```
  A --5-- B
  B --3-- C
  ```
  - The weight of edge `A-B` is 5, and `B-C` is 3.

#### **Example (Directed Weighted Graph):**
- **Edges:** 
  ```
  A --5--> B
  B --3--> C
  ```
  - The weight of the edge from `A` to `B` is 5.



### **Paths in Graphs**

A **path** is a sequence of vertices connected by edges. It can be **simple** (no repeated vertices) or **non-simple** (vertices may repeat).

#### **Example:**
- Graph:
  ```
  A --> B --> C
  ```
  - Path: `A -> B -> C`



### **Cyclic and Acyclic Graphs**

1. **Cyclic Graph:** Contains at least one cycle (a path that starts and ends at the same vertex).
    - **Example:**
      ```
      A --> B --> C
      ^           |
      |--|
      ```
      - Cycle: `A -> B -> C -> A`.

2. **Acyclic Graph:** Contains no cycles.
    - **Example:**
      ```
      A --> B --> C
      ```
      - No cycles exist.



## **Why Graphs?**

Graphs are versatile and model numerous real-world problems:

### **Applications of Graphs**
1. **Social Networks:** Represent people (nodes) and their relationships (edges).
   - Example: Facebook friends.
2. **Web Graphs:** Represent webpages (nodes) and links between them (edges).
   - Example: Google PageRank algorithm.
3. **Transportation Networks:** Represent cities (nodes) and roads (edges).
   - Example: Find the shortest path between cities using Dijkstra’s algorithm.
4. **Task Scheduling:** Represent tasks (nodes) and dependencies (edges).
   - Example: Project management tools.

Graphs allow for efficient representation and analysis of such problems.



## **Graph Implementations**

### 1. **Adjacency Matrix**

- A 2D matrix where `matrix[i][j]` is:
  - `1` (or weight) if there is an edge between vertex `i` and vertex `j`.
  - `0` if there’s no edge.

#### **Advantages:**
- Quick edge lookup: O(1).
- Suitable for dense graphs.

#### **Disadvantages:**
- Requires O(V²) space, even for sparse graphs.



### 2. **Adjacency List**

- Each vertex has a list of adjacent vertices.
- Representation: Use a map or vector of lists.

#### **Advantages:**
- Space-efficient for sparse graphs.
- Traversal is faster.

#### **Disadvantages:**
- Slower edge lookup: O(V).


---
### **Adjacency Matrix Approach**

An **Adjacency Matrix** is a 2D array used to represent a graph. The matrix shows whether there is an edge between any two vertices and, in some cases, the weight of the edge.

#### **How It Works**
1. Let the graph have \( V \) vertices.
2. Create a \( V \times V \) matrix, initialized with zeros.
3. For an edge between vertices \( u \) and \( v \):
   - For an **undirected graph**, set \( matrix[u][v] = 1 \) and \( matrix[v][u] = 1 \).
   - For a **directed graph**, set \( matrix[u][v] = 1 \).
4. If the graph is **weighted**, replace `1` with the weight of the edge.


#### **Example:**
Consider a graph with 3 vertices \( A, B, C \):
- Undirected edges: \( A-B \), \( B-C \).
- Directed edges: \( A \rightarrow C \).

##### **Adjacency Matrix for Undirected Graph:**
|   | A | B | C |
|--|--|--|--|
| A | 0 | 1 | 0 |
| B | 1 | 0 | 1 |
| C | 0 | 1 | 0 |

##### **Adjacency Matrix for Directed Graph:**
|   | A | B | C |
|--|--|--|--|
| A | 0 | 1 | 1 |
| B | 0 | 0 | 1 |
| C | 0 | 0 | 0 |

### Source code Implementation
```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
class graph{
    public:
        unordered_map<int, unordered_map<int, int>> adjacencyMatrix;
        
        void addEdge(T source, T destination, int weight = 1, bool isDirected = false){
            adjacencyMatrix[source][destination] = weight;
            if(!isDirected) adjacencyMatrix[destination][source] = weight;
        }
        
        void printMatrix(int totalVertices){
            for(int row = 0; row < totalVertices; row++){
                for(int col = 0; col < totalVertices; col++){
                    if (adjacencyMatrix[row].count(col) > 0) {
                        cout << adjacencyMatrix[row][col] << " ";
                    }else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;
            }
        }
        
};
int main() {
    graph<int> g;

    int totalVertices = 3;

    // Adding edges to the graph
    g.addEdge(0, 1, 1, true);
    g.addEdge(1, 2, 1, true);
    g.addEdge(2, 0, 1, true);

    // Printing the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    g.printMatrix(totalVertices);

    return 0;
}

```

### Source Code Explanation
##### **Header Files and Namespace**
```cpp
#include <iostream>
#include <unordered_map>
using namespace std;
```
- **`#include <iostream>`**: Allows input and output operations.
- **`#include <unordered_map>`**: Provides the `unordered_map` data structure for efficient key-value pair storage.
- **`using namespace std;`**: Simplifies syntax by avoiding the need to prefix `std::` before standard library elements.


##### **Graph Class Template Declaration**
```cpp
template <typename T>
class graph {
```
- **`template <typename T>`**: Makes the graph generic so it can work with different data types (e.g., `int`, `string`).
- **`class graph`**: Declares the `graph` class.


##### **Adjacency Matrix Declaration**
```cpp
unordered_map<int, unordered_map<int, int>> adjacencyMatrix;
```
- **`unordered_map<int, unordered_map<int, int>>`**: Represents the adjacency matrix.
  - The outer map’s key (`int`) represents a source vertex.
  - The inner map represents the destination vertices and their edge weights.



##### **Adding Edges**
```cpp
void addEdge(T source, T destination, int weight = 1, bool isDirected = false) {
    adjacencyMatrix[source][destination] = weight;
    if (!isDirected) adjacencyMatrix[destination][source] = weight;
}
```
- **`T source, T destination`**: Input vertices for the edge.
- **`int weight = 1`**: Optional parameter; defaults to `1` if not specified.
- **`bool isDirected = false`**: Specifies whether the graph is directed (`true`) or undirected (`false`).
- **`adjacencyMatrix[source][destination] = weight;`**: Adds an edge from `source` to `destination` with the given weight.
- **`if (!isDirected)`**: If the graph is undirected, it also adds a reverse edge from `destination` to `source`.


##### **Printing the Adjacency Matrix**
```cpp
void printMatrix(int totalVertices) {
    for (int row = 0; row < totalVertices; row++) {
        for (int col = 0; col < totalVertices; col++) {
            if (adjacencyMatrix[row].count(col) > 0) {
                cout << adjacencyMatrix[row][col] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
```
- **`void printMatrix(int totalVertices)`**: Prints the adjacency matrix for a graph with `totalVertices`.
- **Outer loop (`row`)**: Iterates over each vertex (row index).
- **Inner loop (`col`)**: Iterates over all potential connections (column index).
- **`if (adjacencyMatrix[row].count(col) > 0)`**: Checks if there is an edge between `row` and `col`.
  - **`cout << adjacencyMatrix[row][col]`**: Prints the weight of the edge if it exists.
  - **`cout << 0`**: Prints `0` if no edge exists.
- **`cout << endl`**: Moves to the next line after each row.


##### **Main Function**
```cpp
int main() {
    graph<int> g;
```
- **`graph<int> g;`**: Creates an object `g` of the `graph` class for integer vertices.

```cpp
int totalVertices = 3;
```
- **`totalVertices = 3`**: Specifies that the graph contains three vertices (0, 1, and 2).


##### **Adding Edges**
```cpp
g.addEdge(0, 1, 1, true);
g.addEdge(1, 2, 1, true);
g.addEdge(2, 0, 1, true);
```
- **`addEdge(0, 1, 1, true)`**: Adds a directed edge from vertex `0` to vertex `1` with a weight of `1`.
- **`addEdge(1, 2, 1, true)`**: Adds a directed edge from vertex `1` to vertex `2` with a weight of `1`.
- **`addEdge(2, 0, 1, true)`**: Adds a directed edge from vertex `2` to vertex `0` with a weight of `1`.


##### **Printing the Adjacency Matrix**
```cpp
cout << "Adjacency Matrix:" << endl;
g.printMatrix(totalVertices);
```
- **`g.printMatrix(totalVertices)`**: Prints the adjacency matrix for the graph.


#### **Output**
For the directed graph created:
```
Vertices: 0, 1, 2
Edges: 0->1, 1->2, 2->0
```

Adjacency Matrix:
```
0 1 0
0 0 1
1 0 0
```

### **Time Complexity**
1. **Adding an Edge:**
   - **Best case:** \(O(1)\) (hash map insertion).
   - **Average case:** \(O(1)\).
2. **Printing the Matrix:**
   - **Outer loop:** \(O(V)\) (iterate over rows).
   - **Inner loop:** \(O(V)\) (iterate over columns).
   - **Total complexity:** \(O(V^2)\).

### **Space Complexity**
- **Adjacency Matrix Storage:** 
  - In worst case (dense graph with all \(V^2\) edges), \(O(V^2)\).
  - In sparse graphs (fewer edges), space depends on the number of stored edges \(O(E)\).


### **Examples**

#### **Undirected Graph**
Vertices: 0, 1, 2  
Edges: (0-1), (1-2), (2-0)

Adjacency Matrix:
```
0 1 1
1 0 1
1 1 0
```

#### **Directed Graph**
Vertices: 0, 1, 2  
Edges: 0->1, 1->2, 2->0

Adjacency Matrix:
```
0 1 0
0 0 1
1 0 0
```


#### **Why Use Adjacency Matrix?**
- **Pros:**
  - Fast edge existence check: \(O(1)\).
  - Good for dense graphs.
- **Cons:**
  - Consumes more space for sparse graphs.
  - Adding/removing vertices is less efficient.

---
### **Adjacency List Approach**

The **Adjacency List** is a data structure commonly used to represent a graph. It is space-efficient and well-suited for sparse graphs (graphs with fewer edges compared to vertices). 

In this approach:
1. Each vertex (node) of the graph has a list of vertices that are directly connected to it.
2. The graph is represented as a collection of linked lists, arrays, or hash maps.


#### **How it Works**
- **Vertices:** Represented as keys in a map or indices in an array.
- **Edges:** For each vertex, a list of all its neighbors (vertices it is connected to) is stored.

#### **Structure:**
- **Undirected Graph:** 
  - If there is an edge between vertices `A` and `B`, both `A` and `B` will include each other in their adjacency lists.
- **Directed Graph:**
  - If there is a directed edge from vertex `A` to vertex `B`, only `A` will include `B` in its adjacency list.


#### **Example 1: Undirected Graph**
##### Graph Representation:
```
Vertices: 0, 1, 2, 3
Edges: (0-1), (0-2), (1-2), (2-3)
```

#### Adjacency List:
```
0 -> 1, 2
1 -> 0, 2
2 -> 0, 1, 3
3 -> 2
```

- **Explanation:** 
  - Vertex `0` is connected to `1` and `2`.
  - Vertex `1` is connected to `0` and `2`, and so on.

#### **Example 2: Directed Graph**
##### Graph Representation:
```
Vertices: A, B, C, D
Edges: A->B, A->C, B->D, C->D
```

##### Adjacency List:
```
A -> B, C
B -> D
C -> D
D -> 
```

- **Explanation:** 
  - Vertex `A` has outgoing edges to `B` and `C`.
  - Vertex `B` has an outgoing edge to `D`, and so on.
  - Vertex `D` has no outgoing edges.


#### **Advantages of the Adjacency List Approach**
1. **Space Efficiency:** Requires less space than an adjacency matrix for sparse graphs.
   - Space complexity: \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.
2. **Ease of Representation:** Easy to traverse and manipulate neighbors of a vertex.
3. **Flexibility:** Works well for both directed and undirected graphs.


### **Source Code Implementation**
```cpp
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

// Graph Class Definition
class Graph {
public:
    unordered_map<int, list<int>> adjacencyList;  // To store adjacency list

    // Add an edge to the graph
    void addEdge(int sourceNode, int destinationNode, bool isDirected) {
        // Add the edge from source to destination
        adjacencyList[sourceNode].push_back(destinationNode);

        // If the graph is undirected, add the reverse edge
        if (!isDirected) {
            adjacencyList[destinationNode].push_back(sourceNode);
        }
    }

    // Print the adjacency list of the graph
    void printGraph() {
        for (auto vertex : adjacencyList) {
            cout << vertex.first << " -> ";
            for (auto neighbor : vertex.second) {
                cout << neighbor << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numberOfNodes;
    cout << "Enter the number of nodes in the graph:" << endl;
    cin >> numberOfNodes;

    int numberOfEdges;
    cout << "Enter the number of edges in the graph:" << endl;
    cin >> numberOfEdges;

    Graph graphInstance;  // Create a Graph object

    // Input edges
    for (int i = 0; i < numberOfEdges; i++) {
        int sourceNode, destinationNode;
        cin >> sourceNode >> destinationNode;

        // Add the edge to the graph (default: undirected)
        graphInstance.addEdge(sourceNode, destinationNode, false);
    }

    // Print the graph representation
    graphInstance.printGraph();

    return 0;
}

```

### Source Code Explanation
#### **Header Files and Namespace**
```cpp
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
```
- **`#include <iostream>`:** Provides input/output functionalities.
- **`#include <unordered_map>`:** Used for the adjacency list representation.
- **`#include <list>`:** Used to store neighbors of each vertex in the adjacency list.
- **`using namespace std;`** Avoids writing `std::` repeatedly.

#### **Class Definition**
```cpp
class Graph {
public:
    unordered_map<int, list<int>> adjacencyList;
```
- **`class Graph`:** Encapsulates the graph-related functions and data.
- **`unordered_map<int, list<int>> adjacencyList`:** Stores the graph. Keys are nodes, and values are lists of neighbors.



#### **Adding an Edge**
```cpp
void addEdge(int sourceNode, int destinationNode, bool isDirected) {
    adjacencyList[sourceNode].push_back(destinationNode);
    if (!isDirected) {
        adjacencyList[destinationNode].push_back(sourceNode);
    }
}
```
1. **`addEdge(int sourceNode, int destinationNode, bool isDirected)`:**
   - Adds an edge between two nodes.
   - **`sourceNode`**: Starting node of the edge.
   - **`destinationNode`**: End node of the edge.
   - **`isDirected`**: Boolean flag indicating whether the edge is directed (`true`) or undirected (`false`).

2. **`adjacencyList[sourceNode].push_back(destinationNode);`:**
   - Adds an edge from `sourceNode` to `destinationNode`.

3. **`if (!isDirected)`:**
   - If the graph is undirected, adds the reverse edge: `destinationNode -> sourceNode`.



#### **Printing the Graph**
```cpp
void printGraph() {
    for (auto vertex : adjacencyList) {
        cout << vertex.first << " -> ";
        for (auto neighbor : vertex.second) {
            cout << neighbor << ", ";
        }
        cout << endl;
    }
}
```
1. **`for (auto vertex : adjacencyList)`:**
   - Iterates through each vertex in the graph.

2. **`cout << vertex.first << " -> ";`:**
   - Prints the current vertex.

3. **`for (auto neighbor : vertex.second)`:**
   - Iterates through all neighbors of the current vertex.

4. **`cout << neighbor << ", ";`:**
   - Prints each neighbor, separated by commas.



#### **Main Function**
```cpp
int main() {
    int numberOfNodes;
    cout << "Enter the number of nodes in the graph:" << endl;
    cin >> numberOfNodes;

    int numberOfEdges;
    cout << "Enter the number of edges in the graph:" << endl;
    cin >> numberOfEdges;

    Graph graphInstance;
```
1. **`int numberOfNodes;`**:  
   - Stores the number of vertices in the graph.

2. **`int numberOfEdges;`**:  
   - Stores the number of edges in the graph.

3. **`Graph graphInstance;`**:  
   - Creates a new graph object.



#### **Input Edges**
```cpp
for (int i = 0; i < numberOfEdges; i++) {
    int sourceNode, destinationNode;
    cin >> sourceNode >> destinationNode;
    graphInstance.addEdge(sourceNode, destinationNode, false);
}
```
1. **`for (int i = 0; i < numberOfEdges; i++)`:**
   - Loops through all edges.

2. **`cin >> sourceNode >> destinationNode;`**
   - Reads the two nodes connected by the current edge.

3. **`graphInstance.addEdge(sourceNode, destinationNode, false);`**
   - Adds an undirected edge between `sourceNode` and `destinationNode`.



#### **Printing the Graph**
```cpp
graphInstance.printGraph();
return 0;
```
- **`graphInstance.printGraph();`**
   - Prints the adjacency list representation of the graph.



### **Example Outputs**

#### **Example 1: Undirected Graph**
**Input:**
```
Enter the number of nodes in the graph:
3
Enter the number of edges in the graph:
2
0 1
1 2
```

**Output:**
```
0 -> 1,
1 -> 0, 2,
2 -> 1,
```



#### **Example 2: Directed Graph**
Change `graphInstance.addEdge(sourceNode, destinationNode, false);` to `true`:
```cpp
graphInstance.addEdge(sourceNode, destinationNode, true);
```

**Input:**
```
Enter the number of nodes in the graph:
3
Enter the number of edges in the graph:
2
0 1
1 2
```

**Output:**
```
0 -> 1,
1 -> 2,
```



### **Time and Space Complexity**
1. **Time Complexity:**
   - **Adding an edge:** \( O(1) \) (inserting into a list).
   - **Printing adjacency list:** \( O(V + E) \), where \( V \) is the number of vertices and \( E \) is the number of edges.

2. **Space Complexity:**
   - **Storage:** \( O(V + E) \), as the adjacency list stores all edges.


### **Why Use Adjacency List Instead of Matrix?**
- **Adjacency Matrix:**  
  - Takes \( O(V^2) \) space, even for sparse graphs.
  - Faster edge lookup: \( O(1) \).

- **Adjacency List:**  
  - Space-efficient for sparse graphs: \( O(V + E) \).
  - Better for graph traversal algorithms like BFS/DFS.
