<h1 align='center'>Print - Adjacency - List</h1>

## Problem Statement

**Problem URL :** [Print Adjacency List](https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1)

![image](https://github.com/user-attachments/assets/55ec5006-0638-4f6b-b2c1-aded189ca8fb)
![image](https://github.com/user-attachments/assets/5efbe223-1c74-4880-bc9f-849796803f4e)

## Problem Explanation
In a graph, the **Adjacency List** is a collection of lists or arrays where each list corresponds to a node in the graph and contains all the neighbors (or connected nodes) of that node. It's a way of representing a graph in a compact format, especially for sparse graphs (graphs with fewer edges). 

Here is the problem scenario:

You are given a graph with `V` vertices and `E` edges. Each edge connects two vertices, and the graph can either be **directed** or **undirected**. Your task is to print the **adjacency list** for the graph.

For example:
- **Graph Representation:**
  - Vertices: `V = 5`
  - Edges: `E = 4`
  - Edges list: `[(0, 1), (1, 2), (2, 3), (3, 4)]`

The adjacency list for this graph would look like:

```
0 -> 1
1 -> 0, 2
2 -> 1, 3
3 -> 2, 4
4 -> 3
```

This means:
- Node 0 is connected to node 1.
- Node 1 is connected to nodes 0 and 2.
- Node 2 is connected to nodes 1 and 3, and so on.

**Objective:**
Given the number of vertices (`V`) and a list of edges, print the adjacency list.

#### Approach to Solve:

- **Step 1:** Create a class `Graph` to represent the graph.
- **Step 2:** Use an adjacency list to represent the graph. For each edge in the input, add the destination vertex to the adjacency list of the source vertex.
- **Step 3:** After constructing the graph, print the adjacency list for each vertex.

**Example Walkthrough:**

Given the graph:
- `V = 5`
- `Edges = [(0, 1), (1, 2), (2, 3), (3, 4)]`

The adjacency list would be built as follows:
- Start with an empty list of size `V`.
- For each edge `(u, v)`:
  - Add `v` to the adjacency list of `u`.
  - If the graph is undirected, also add `u` to the adjacency list of `v`.

Final adjacency list after processing:
```
0 -> 1
1 -> 0, 2
2 -> 1, 3
3 -> 2, 4
4 -> 3
```

#### Approach Steps:
1. **Initialize** a `graph` object with `V` vertices.
2. **Add edges** using the `addEdge` function for both directions (if undirected).
3. **Print adjacency list** by iterating through each vertex and displaying its neighbors.


## Problem Solution
```cpp
template <typename T>
class graph{
    public:
        vector<vector<int>> adj;
        
        graph(int V){
            adj.resize(V);
        }
        
        void addEdge(T u, T v, bool direction){
            adj[u].push_back(v);
            
            if(direction == 0) adj[v].push_back(u);
        }
        
        void printAdj(vector<vector<int>>& ans){
            for(int i = 0; i < adj.size(); i++){
                for(auto j : adj[i]){
                    ans[i].push_back(j);
                }
            }
        }
};

class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        graph<int> g(V);
        
        for(int i = 0; i < edges.size(); i++){
            g.addEdge(edges[i].first, edges[i].second, 0);
        }
        
        vector<vector<int>> ans(V);
        g.printAdj(ans);
        
        return ans;
    }
};
```

## Problem Solution Explanation

#### **1. `template <typename T>`**
- This line defines a **template** for the `graph` class. 
- **Templates** allow us to write generic code that can be used with different data types.
- `T` represents the type for the vertices (in this case, it could be `int`, but it's generalized).
- This makes the `graph` class reusable with any type of data (e.g., integers, strings, etc.).

#### **2. `class graph {`**
- This starts the definition of the `graph` class. 
- A **class** is a blueprint for creating objects that can store and manage data, and define functions to operate on that data. 
- In this case, the class will handle graphs and their adjacency lists.

#### **3. `vector<vector<int>> adj;`**
- Here, we declare a **2D vector** `adj`. 
- **`vector<vector<int>>`** means the outer vector contains inner vectors, and each inner vector stores integers.
- This is an adjacency list representation of the graph.
  - **`adj[u]`** will store a list of neighbors (connected nodes) of vertex `u`.

#### **4. `graph(int V)`**
- This is the **constructor** of the `graph` class. 
- The constructor initializes the adjacency list with `V` vertices. `V` is passed as a parameter to the constructor, representing the number of vertices in the graph.

#### **5. `adj.resize(V);`**
- This line **resizes** the adjacency list `adj` to have `V` empty sub-vectors. 
- Each sub-vector corresponds to a vertex in the graph and will eventually hold the neighbors of that vertex.
  - For example, if `V = 3`, `adj` will have 3 empty sub-vectors: `adj[0]`, `adj[1]`, `adj[2]`.

#### **6. `void addEdge(T u, T v, bool direction)`**
- This method adds an **edge** from vertex `u` to vertex `v`.
- The `direction` parameter determines whether the edge is **directed** or **undirected**:
  - If `direction == 1`, the edge is directed from `u` to `v`.
  - If `direction == 0`, the edge is undirected, so the method will add both directions (from `u` to `v` and from `v` to `u`).

#### **7. `adj[u].push_back(v);`**
- This line adds the destination vertex `v` to the adjacency list of the source vertex `u`. 
- **`adj[u]`** is the list of neighbors of vertex `u`, and **`push_back(v)`** adds `v` as a neighbor of `u`.

#### **8. `if (direction == 0) adj[v].push_back(u);`**
- If the edge is undirected (i.e., `direction == 0`), this line adds the reverse edge from `v` to `u` by adding `u` to the adjacency list of `v`.
- This ensures that the graph is undirected by making sure the edge is bidirectional (i.e., if there's an edge from `u` to `v`, there is also an edge from `v` to `u`).

#### **9. `void printAdj(vector<vector<int>>& ans)`**
- This method prints the **adjacency list** of the graph. 
- It takes a reference to a vector `ans`, which will hold the adjacency list for output.
- The function will copy the adjacency list from `adj` into `ans`.

#### **10. `for (int i = 0; i < adj.size(); i++) {`**
- This loop iterates over the entire adjacency list `adj`. 
- `adj.size()` gives the total number of vertices in the graph.
- This loop will go through each vertex and print its neighbors.

#### **11. `for (auto j : adj[i]) {`**
- This loop iterates through the list of neighbors of the `i`th vertex.
- `auto` is used for automatic type deduction, so `j` represents each neighbor of vertex `i`.
- The inner loop processes each neighbor of the current vertex.

#### **12. `ans[i].push_back(j);`**
- This line copies each neighbor `j` of vertex `i` into the `ans` vector. 
- **`ans[i].push_back(j)`** adds each neighbor of vertex `i` to the corresponding list in `ans`.

#### **13. `}`**
- This closes the inner loop that processes neighbors.

#### **14. `}`**
- This closes the outer loop that processes each vertex in the adjacency list.

### **Example and Explanation:**

Let's consider an example with `V = 3` vertices and edges between them.

- **Edges**:
  - `0 -> 1`
  - `1 -> 2`
  - `2 -> 0`

- **Adjacency List** after adding edges:
  - Vertex `0` has neighbors: `1` (i.e., `adj[0] = {1}`)
  - Vertex `1` has neighbors: `0`, `2` (i.e., `adj[1] = {0, 2}`)
  - Vertex `2` has neighbors: `1` (i.e., `adj[2] = {1}`)

### **Time and Space Complexity Analysis:**

#### **Time Complexity:**
- **Adding an edge** takes constant time `O(1)`, as we're simply adding a neighbor to a vector.
- **Printing the adjacency list** involves iterating through all vertices and their neighbors:
  - If there are `V` vertices and the total number of edges is `E`, the time complexity of printing the adjacency list is `O(V + E)`.
  - For each vertex, we go through all its neighbors, so the total time complexity for printing all vertices and their neighbors is proportional to the number of vertices and edges.

Thus, the overall **time complexity** for the code is **O(V + E)**.

#### **Space Complexity:**
- **Adjacency List**: The space required for storing the adjacency list is proportional to the number of vertices and edges. We store a list of neighbors for each vertex, and the space complexity is **O(V + E)**.
- **Answer vector `ans`**: The space used by the `ans` vector is also **O(V + E)** since it stores the same adjacency information as the `adj` vector.

Thus, the overall **space complexity** is **O(V + E)**.

### **Recommendations for Students:**
- Always keep track of the type of graph you're working with (directed vs. undirected) and the complexity of operations.
- Try implementing basic graph algorithms like BFS and DFS on the adjacency list representation to get a deeper understanding of how graphs work.
- Use a graph visualization tool to help understand how edges are added and how traversal algorithms work.


