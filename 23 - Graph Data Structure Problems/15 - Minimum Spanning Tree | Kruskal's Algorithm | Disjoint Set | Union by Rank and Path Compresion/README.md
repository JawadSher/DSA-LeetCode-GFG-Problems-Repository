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

---

### Disjoin Set
The **Disjoint Set Union (DSU)** or **Union-Find** is a data structure used to efficiently manage and group disjoint sets (non-overlapping subsets). It supports two primary operations: **`findParent()`** (or `findSet()`) and **`union()`** (or `unionSet()`).

#### **Core Idea**
- Each element is a part of exactly one set.
- DSU is used to determine if two elements belong to the same set and to merge sets efficiently.
- It's commonly used in graph algorithms like Kruskal's algorithm to find the Minimum Spanning Tree (MST) and detect cycles.


#### **1. `findParent()` or `findSet()`**
This operation identifies the *root* or *representative* of the set to which a given element belongs. It also performs **path compression** to optimize future queries.

##### **Steps**
1. If the current element is its own parent, it is the root of its set.
2. Otherwise, recursively find the parent of its parent until reaching the root.
3. During recursion, update the parent of the current node to the root for efficiency (path compression).

##### **Example**
- Consider elements `{0, 1, 2, 3}` and sets represented by:
  ```
  Parent array: [0, 0, 2, 2]
  ```
  - `parent[0] = 0` (0 is its own parent → root of set {0, 1}).
  - `parent[1] = 0` (1's root is 0).
  - `parent[2] = 2` (2 is its own parent → root of set {2, 3}).
  - `parent[3] = 2` (3's root is 2).

  Using `findParent()`:
  - `findParent(3)` → 2.
  - `findParent(1)` → 0.



#### **2. `union()` or `unionSet()`**
This operation merges two sets into one by connecting their roots. It uses **union by rank** to minimize tree height for efficiency.

#### **Steps**
1. Find the roots of the two sets using `findParent()`.
2. Compare the ranks (or heights) of the trees representing the sets.
3. Attach the smaller tree under the larger tree to maintain balance.
   - If ranks are equal, choose arbitrarily and increase the rank of the new root.

#### **Example**
- Initially:
  ```
  Parent array: [0, 1, 2, 3]
  Rank array:   [0, 0, 0, 0]
  ```
- `union(0, 1)`:
  - `findParent(0)` → 0, `findParent(1)` → 1.
  - Both have equal rank → make 0 the parent of 1 and increase its rank.
  ```
  Parent array: [0, 0, 2, 3]
  Rank array:   [1, 0, 0, 0]
  ```
- `union(2, 3)`:
  - `findParent(2)` → 2, `findParent(3)` → 3.
  - Both have equal rank → make 2 the parent of 3 and increase its rank.
  ```
  Parent array: [0, 0, 2, 2]
  Rank array:   [1, 0, 1, 0]
  ```
- `union(1, 3)`:
  - `findParent(1)` → 0, `findParent(3)` → 2.
  - Attach the tree with root 2 under root 0 since their ranks are equal.
  ```
  Parent array: [0, 0, 0, 2]
  Rank array:   [2, 0, 1, 0]
  ```



#### **Path Compression**
During `findParent()`, we make each node on the path directly point to the root. This reduces the tree height, making future operations nearly constant time.

##### Example
- Before compression:
  ```
  Parent array: [0, 0, 0, 2]
  Query: findParent(3) → 2 → 0.
  ```
- After compression:
  ```
  Parent array: [0, 0, 0, 0]
  ```



#### **Time Complexity**
- **`findParent()` and `union()`**:
  - Without optimizations: \(O(\log n)\).
  - With path compression and union by rank: \(O(\alpha(n))\), where \(\alpha\) is the inverse Ackermann function (extremely slow-growing).

---

### Union by Rank & Path Compression
##### **Union by Rank** and **Path Compression** are two important techniques used in the **Disjoint Set Union (DSU)** or **Union-Find** data structure to optimize its operations. These techniques improve the time complexity of operations, ensuring that the data structure operates efficiently even for large inputs.

Let's dive into both concepts in detail, explaining their purpose, working, and providing examples.

#### **1. Union by Rank**

##### **Purpose of Union by Rank:**
Union by rank is a technique that optimizes the **union operation** by minimizing the height (or depth) of the trees in the disjoint set structure. The idea is to always attach the smaller tree (based on rank) under the larger tree, keeping the overall tree shallow. This reduces the overall time complexity of subsequent `find` operations.

##### **How it works:**
- Each set is represented as a tree, and each node in the tree has a **rank**.
- The **rank** of a node is an approximation of the tree's height. Initially, the rank is set to 0 for each node.
- When we perform a union operation between two sets (trees), we compare their ranks:
  - If the ranks are different, the tree with the smaller rank gets attached to the root of the tree with the larger rank.
  - If the ranks are the same, we can choose either tree to be the root and increase its rank by 1.

##### **Union by Rank: Example**

Suppose we have the following disjoint sets with initial ranks:

- Set 1: `{0, 1}` with ranks `{0, 0}`
- Set 2: `{2, 3}` with ranks `{0, 0}`
- Set 3: `{4}` with rank `{0}`

Let's perform the following union operations step-by-step.

1. **union(0, 1):**
   - Both `0` and `1` have the same rank (0).
   - We make `0` the root of `1` and increment the rank of `0`.
   - New rank array: `{1, 0, 0, 0, 0}`.

2. **union(2, 3):**
   - Both `2` and `3` have the same rank (0).
   - We make `2` the root of `3` and increment the rank of `2`.
   - New rank array: `{1, 0, 1, 0, 0}`.

3. **union(1, 3):**
   - `1`'s root is `0` (rank 1), and `3`'s root is `2` (rank 1).
   - Both roots have the same rank (1).
   - We make `0` the root of `2` and increase the rank of `0`.
   - New rank array: `{2, 0, 1, 0, 0}`.

Now, the trees look like this:
- Set 1: `{0, 1, 2, 3}` (with root 0 and rank 2)
- Set 2: `{4}` (with rank 0)

#### **2. Path Compression**

##### **Purpose of Path Compression:**
Path compression is a technique used during the **find operation** to flatten the tree structure, making future queries faster. The idea is to make each node on the path from a node to the root point directly to the root, thus reducing the tree's height.

##### **How it works:**
- When we perform a `find` operation, instead of traversing up the tree recursively, we apply path compression. This means that every node we encounter during the recursion will directly point to the root of the set.
- The effect of path compression is that the trees get flatter, leading to faster `find` operations in future queries.

##### **Path Compression: Example**

Consider the following disjoint sets, and perform `find` operations.

1. **Initial sets (after union operations):**

   ```
   Parent array: [0, 0, 2, 2, 4]
   Rank array:   [2, 0, 1, 0, 0]
   ```

2. **find(3):**
   - `find(3)` → `find(2)` → `find(0)`.
   - Path compression: After `find(0)`, we update `parent[3] = 0` and `parent[2] = 0`.
   - Now, `parent = [0, 0, 0, 0, 4]` and the tree is flatter.

3. **find(1):**
   - `find(1)` → `find(0)` → `0`.
   - Since `1` is already pointing directly to the root `0`, there is no change in the parent array.

4. **find(4):**
   - `find(4)` → `4`.
   - No change because `4` is its own parent.

After applying path compression, the `parent` array is:
```
Parent array: [0, 0, 0, 0, 4]
Rank array:   [2, 0, 1, 0, 0]
```

Now, `find(3)` and `find(1)` are faster as the trees have been flattened.

### **Combining Union by Rank and Path Compression:**

When both techniques are applied together, the time complexity of the **`find()`** and **`union()`** operations becomes nearly constant, specifically **O(α(n))**, where **α(n)** is the **inverse Ackermann function**. This function grows extremely slowly, so in practical terms, it is almost constant for all reasonable input sizes.

### **Time Complexity Analysis:**

- **`find()` operation:**
  - Without path compression: \(O(\log n)\) (in a tree with height \( \log n \)).
  - With path compression: \(O(\alpha(n))\) (amortized time for a sequence of operations).
  
- **`union()` operation:**
  - Without union by rank: \(O(n)\) (in the worst case, if the tree height is too large).
  - With union by rank: \(O(\alpha(n))\) (amortized time).

Thus, when both **union by rank** and **path compression** are used, the operations are extremely efficient and run in near constant time.


#### **Conclusion:**

- **Union by Rank** helps optimize the tree height during unions by attaching the smaller tree under the larger tree.
- **Path Compression** optimizes the find operation by flattening the tree and making all nodes directly point to the root, speeding up subsequent operations.
- These two techniques are typically used together to ensure that the **find** and **union** operations are extremely efficient, making DSU operations nearly constant time.

---

### Kruskal's Algorithm

Kruskal's algorithm is a **greedy algorithm** used to find the **minimum spanning tree (MST)** of a connected, undirected graph. The MST is a subset of the edges of the graph that connects all the vertices together without any cycles, and the sum of the weights of the edges is minimized.

The algorithm works by sorting all the edges of the graph in increasing order of their weights and adding them one by one to the MST, ensuring no cycle is formed.

### **Steps Involved in Kruskal's Algorithm:**

1. **Sort all edges** of the graph in non-decreasing order of their weights.
2. Initialize a **disjoint-set (union-find) data structure** to keep track of which vertices are in the same connected component.
3. Process the edges one by one:
   - For each edge, check if the two vertices are in the same connected component (using the `find` operation).
   - If they are in the same component, skip the edge (since adding it would create a cycle).
   - If they are in different components, include the edge in the MST (add it to the result) and unite the components (using the `union` operation).
4. Repeat step 3 until we have added **(V - 1)** edges to the MST, where **V** is the number of vertices in the graph.
5. The result will be the **Minimum Spanning Tree** of the graph.


### **Time Complexity of Kruskal's Algorithm:**

- Sorting the edges takes **O(E log E)** time, where **E** is the number of edges.
- The **find** and **union** operations on the disjoint set take **O(α(V))** time, where **V** is the number of vertices and **α** is the inverse Ackermann function, which grows very slowly and is practically constant for all reasonable input sizes.
- Thus, the overall time complexity of Kruskal's algorithm is **O(E log E)**, which is dominated by the edge sorting step.

### **Kruskal's Algorithm: Example**

Let’s go through an example to understand how Kruskal's algorithm works.

**Example Graph:**

Consider a graph with 4 vertices (V = 4) and 5 edges (E = 5), where each edge has a weight.

```
Vertices:  0, 1, 2, 3
Edges:
(0, 1, 10)
(0, 2, 6)
(0, 3, 5)
(1, 3, 15)
(2, 3, 4)
```

We need to find the MST for this graph.

### **Step-by-Step Execution of Kruskal's Algorithm:**

1. **Sort all the edges by their weight:**

   After sorting the edges by weight in non-decreasing order:
   ```
   Edges sorted: (2, 3, 4), (0, 3, 5), (0, 2, 6), (0, 1, 10), (1, 3, 15)
   ```

2. **Initialize the disjoint-set (union-find) structure:**
   - Initially, each vertex is its own parent:
     ```
     parent = [0, 1, 2, 3]
     rank = [0, 0, 0, 0]   // rank is used for union by rank
     ```

3. **Process each edge and check if it forms a cycle:**

   - **Edge (2, 3, 4):**
     - Find the parents of 2 and 3: `find(2) = 2`, `find(3) = 3`.
     - Since they are in different components, include this edge in the MST and union the sets containing 2 and 3:
       - Union operation: `parent[2] = 3`.
     - New parent array: `[0, 1, 3, 3]`.
   
   - **Edge (0, 3, 5):**
     - Find the parents of 0 and 3: `find(0) = 0`, `find(3) = 3`.
     - Since they are in different components, include this edge in the MST and union the sets containing 0 and 3:
       - Union operation: `parent[0] = 3`.
     - New parent array: `[3, 1, 3, 3]`.
   
   - **Edge (0, 2, 6):**
     - Find the parents of 0 and 2: `find(0) = 3`, `find(2) = 3`.
     - Since they are in the same component, skip this edge (it would form a cycle).

   - **Edge (0, 1, 10):**
     - Find the parents of 0 and 1: `find(0) = 3`, `find(1) = 1`.
     - Since they are in different components, include this edge in the MST and union the sets containing 0 and 1:
       - Union operation: `parent[1] = 3`.
     - New parent array: `[3, 3, 3, 3]`.

   - **Edge (1, 3, 15):**
     - Find the parents of 1 and 3: `find(1) = 3`, `find(3) = 3`.
     - Since they are in the same component, skip this edge (it would form a cycle).

4. **Final MST:**
   After processing the edges, we have included 3 edges in the MST, which is sufficient for a graph with 4 vertices (since the MST must have **V - 1 = 3** edges). The MST is:
   ```
   Edges in MST: (2, 3, 4), (0, 3, 5), (0, 1, 10)
   ```

5. **Total weight of the MST:**
   The total weight of the MST is the sum of the weights of the selected edges:
   ```
   4 + 5 + 10 = 19
   ```

---

## Problem Solution
```cpp
class Solution
{
    public:
    // Function to initialize the parent and rank arrays for Union-Find (Disjoint Set Union)
    void makeSet(vector<int>& rank, vector<int>& parent, int n){
        for(int i = 0; i < n; i++){
            parent[i] = i; // Each node is initially its own parent
            rank[i] = 0;   // Rank of each node is initialized to 0
        }
    }
    
    // Function to find the representative (root) of a set using path compression
    int findParent(vector<int>& parent, int node){
        if(parent[node] == node) 
            return node; // If the node is its own parent, it is the root
        // Recursively find the root and apply path compression
        return parent[node] = findParent(parent, parent[node]);
    }
    
    // Function to unify two sets using union by rank
    void unionSet(int source, int destination, vector<int>& parent, vector<int>& rank){
        // Find the roots of the sets for both nodes
        source = findParent(parent, source);
        destination = findParent(parent, destination);
        
        // Attach the smaller ranked tree under the larger ranked tree
        if(rank[source] < rank[destination]) 
            parent[source] = destination; // Attach source under destination
        else if(rank[destination] < rank[source]) 
            parent[destination] = source; // Attach destination under source
        else{
            // If ranks are equal, choose one root arbitrarily and increase its rank
            parent[destination] = source;
            rank[source]++;
        }
    }
    
    // Function to calculate the weight of the Minimum Spanning Tree (MST)
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        vector<vector<int>> edges; // Vector to store all edges in the graph
        
        // Convert adjacency list to an edge list
        for(int source = 0; source < V; source++){
            for(auto &neighbour : adj[source]){
                int destination = neighbour[0]; // Neighboring node
                int weight = neighbour[1];      // Weight of the edge
                
                // To avoid duplicate edges, only consider source < destination
                if(source < destination) 
                    edges.push_back({weight, source, destination});
            }
        }
        
        // Arrays to store the rank and parent of each node
        vector<int> rank(V);
        vector<int> parent(V);
        makeSet(rank, parent, V); // Initialize the rank and parent arrays
        
        // Sort the edges by weight (Kruskal's algorithm requires this step)
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0]; // Compare weights of the edges
        });
        
        int minWeight = 0; // Variable to store the total weight of the MST
        
        // Iterate through the sorted edges
        for(int i = 0; i < edges.size(); i++){
            int source = findParent(parent, edges[i][1]); // Find root of source
            int destination = findParent(parent, edges[i][2]); // Find root of destination
            int weight = edges[i][0]; // Weight of the current edge
            
            // If the nodes belong to different sets, include this edge in the MST
            if(source != destination) {
                minWeight += weight; // Add the weight of the edge to the MST
                unionSet(source, destination, parent, rank); // Union the sets
            }
        }
        
        return minWeight; // Return the total weight of the MST
    }
};
```

## Problem Solution Explanation

This solution implements **Kruskal's algorithm** using the **Union-Find (Disjoint Set Union - DSU)** data structure with **Union by Rank** and **Path Compression**. Kruskal's algorithm is used to find the **Minimum Spanning Tree (MST)** of a weighted undirected graph.

#### **1. `makeSet` function**
```cpp
void makeSet(vector<int>& rank, vector<int>& parent, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i; // Each node is initially its own parent
        rank[i] = 0;   // Rank of each node is initialized to 0
    }
}
```
- **Purpose**: This function initializes the **parent** and **rank** arrays.
  - `parent[i] = i`: Each node starts as its own parent (each node is in its own set initially).
  - `rank[i] = 0`: Rank is initialized to 0 for all nodes. The rank helps to keep the tree flat during the **union** operation (using **Union by Rank**).
  
  **Example**: If there are 4 nodes, the initial state of `parent` and `rank` will be:
  ```cpp
  parent = [0, 1, 2, 3]
  rank = [0, 0, 0, 0]
  ```


#### **2. `findParent` function**
```cpp
int findParent(vector<int>& parent, int node){
    if(parent[node] == node) 
        return node; // If the node is its own parent, it is the root
    return parent[node] = findParent(parent, parent[node]); // Path compression
}
```
- **Purpose**: This function returns the **representative (root)** of the set that the node belongs to, with **path compression**.
  - If `parent[node] == node`, then the node is its own parent, meaning it is the root.
  - Otherwise, we recursively find the root of the parent and apply **path compression**, i.e., we directly attach the node to its root, flattening the tree for faster future lookups.

  **Example**: Suppose we have the parent array `[3, 3, 3, 3]` and we call `findParent(1)`, it will return `3` and make `parent[1] = 3` as a path compression step, ensuring all nodes point directly to the root.


#### **3. `unionSet` function**
```cpp
void unionSet(int source, int destination, vector<int>& parent, vector<int>& rank){
    source = findParent(parent, source); // Find the root of source
    destination = findParent(parent, destination); // Find the root of destination
    
    if(rank[source] < rank[destination]) 
        parent[source] = destination; // Attach source under destination
    else if(rank[destination] < rank[source]) 
        parent[destination] = source; // Attach destination under source
    else{
        parent[destination] = source; // Arbitrarily attach one root and increase its rank
        rank[source]++;
    }
}
```
- **Purpose**: This function **unites two sets**. It uses **Union by Rank** to keep the resulting tree as flat as possible, improving the efficiency of future operations.
  - First, we find the roots of both the source and destination nodes.
  - Then, based on the rank (the height of the tree), we attach the smaller tree under the larger one.
  - If both trees have the same rank, we arbitrarily attach one and increase its rank by 1.
  
  **Example**: For `source = 2` and `destination = 3`, if `rank[2] = 1` and `rank[3] = 2`, we would attach `source` to `destination`, making the tree flatter.


#### **4. `spanningTree` function**
```cpp
int spanningTree(int V, vector<vector<int>> adj[]){
    vector<vector<int>> edges; // Vector to store all edges in the graph
    
    // Convert adjacency list to an edge list
    for(int source = 0; source < V; source++){
        for(auto &neighbour : adj[source]){
            int destination = neighbour[0]; // Neighboring node
            int weight = neighbour[1];      // Weight of the edge
            
            if(source < destination) 
                edges.push_back({weight, source, destination});
        }
    }
```
- **Purpose**: This block of code is responsible for **converting the adjacency list** representation of the graph into an edge list, which contains tuples of `(weight, source, destination)`. It avoids adding duplicate edges by ensuring `source < destination` before adding the edge to the `edges` list.

  **Example**: For the graph with 4 vertices:
  ```cpp
  adj[0] = {{1, 10}, {2, 6}, {3, 5}}
  adj[1] = {{0, 10}, {3, 15}}
  adj[2] = {{0, 6}, {3, 4}}
  adj[3] = {{0, 5}, {1, 15}, {2, 4}}
  ```
  The edges list after processing would look like:
  ```cpp
  edges = {{10, 0, 1}, {6, 0, 2}, {5, 0, 3}, {15, 1, 3}, {4, 2, 3}}
  ```


#### **5. Sorting the edges**
```cpp
    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; // Compare weights of the edges
    });
```
- **Purpose**: Sort the edges by their weight in **non-decreasing** order. Kruskal's algorithm processes the edges in this sorted order to ensure we are always adding the smallest available edge to the MST.

  **Example**: After sorting, the edges list will be:
  ```cpp
  edges = {{4, 2, 3}, {5, 0, 3}, {6, 0, 2}, {10, 0, 1}, {15, 1, 3}}
  ```

#### **6. Iterating through edges and building MST**
```cpp
    int minWeight = 0; // Variable to store the total weight of the MST
    
    // Iterate through the sorted edges
    for(int i = 0; i < edges.size(); i++){
        int source = findParent(parent, edges[i][1]); // Find root of source
        int destination = findParent(parent, edges[i][2]); // Find root of destination
        int weight = edges[i][0]; // Weight of the current edge
        
        // If the nodes belong to different sets, include this edge in the MST
        if(source != destination) {
            minWeight += weight; // Add the weight of the edge to the MST
            unionSet(source, destination, parent, rank); // Union the sets
        }
    }
    
    return minWeight; // Return the total weight of the MST
}
```
- **Purpose**: This part of the algorithm processes each edge in the sorted list:
  - For each edge, we check if the source and destination vertices belong to different sets (i.e., are not connected in the MST yet).
  - If they are in different sets, we add the edge to the MST and **union** the two sets.
  - We accumulate the weight of the edges added to the MST in `minWeight`.

  **Example**: The edges are processed in the order:
  1. **(4, 2, 3)**: Add to MST (no cycle, weight = 4).
  2. **(5, 0, 3)**: Add to MST (no cycle, weight = 5).
  3. **(6, 0, 2)**: Skip (would form a cycle).
  4. **(10, 0, 1)**: Add to MST (no cycle, weight = 10).
  - The total weight of the MST will be `4 + 5 + 10 = 19`.


### **Example Output:**

For the graph:

```cpp
adj[0] = {{1, 10}, {2, 6}, {3, 5}}
adj[1] = {{0, 10}, {3, 15}}
adj[2] = {{0, 6}, {3, 4}}
adj[3] = {{0, 5}, {1, 15}, {2, 4}}
```

The **Minimum Spanning Tree** edges are:
```
(4, 2, 3), (5, 0, 3), (10, 0, 1)
```

The **total weight** of the MST is `19`.

### **Time and Space Complexity:**

- **Time Complexity**:
  - Sorting the edges: **O(E log E)**, where **E** is the number of edges.
  - For each edge, performing `find` and `union` operations: Each `find` and `union` operation takes **O(α(V))** time, where **V** is the number of vertices and **α** is the inverse Ackermann

 function, which grows very slowly.
  - Overall, the time complexity is **O(E log E + E α(V))**, where **α(V)** is almost constant.

- **Space Complexity**: **O(V + E)**, where **V** is the number of vertices and **E** is the number of edges (due to the `parent`, `rank`, and `edges` arrays).

