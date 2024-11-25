<h1 align='center'>DFS - of Graph</h1>

## Problem Statement

**Problem URL :** [DFS of Graph](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

![image](https://github.com/user-attachments/assets/c460c3eb-8212-4d51-80de-ee9f61fef61f)
![image](https://github.com/user-attachments/assets/30768d7b-5665-4e9a-81d3-d536df1997d5)

## Problem Explanation
#### **Problem Description:**
The problem requires you to perform a **Depth First Search (DFS)** traversal of a graph. DFS is a graph traversal algorithm that starts from a given node and explores as far as possible along each branch before backtracking. It's typically implemented using recursion (or a stack).

**DFS Characteristics:**
- It explores as deep as possible before backtracking.
- DFS can be implemented using recursion or a stack.
- It is useful for tasks like finding paths, connected components, and cycles in a graph.

#### **Input:**
- An adjacency list representing an undirected graph, where each node is connected to a list of its neighbors.

#### **Output:**
- A list of nodes in the order they are visited during a DFS traversal.

#### **Example:**

Consider the following graph represented as an adjacency list:

```
0: [1, 2]
1: [0, 3, 4]
2: [0]
3: [1]
4: [1]
```

If we start the DFS from node `0`, the expected order of nodes visited would be:
```
0, 1, 3, 4, 2
```

#### **Approach:**

1. **Recursive DFS Traversal:**
   - Start at an arbitrary node (node `0` in this case).
   - Mark the current node as visited.
   - Visit all unvisited neighbors of the current node (recursive step).
   - Backtrack once you’ve visited all neighbors.

2. **Implementation Details:**
   - A **visited** map is used to ensure each node is visited only once.
   - A **result** vector stores the nodes in the order they are visited.

3. **Process:**
   - Start from node `0`.
   - Explore neighbors recursively.
   - Return the traversal result.

## Problem Solution
```cpp
class Solution {
  public:
    void dfsUtil(int node, vector<vector<int>>& adj, unordered_map<int, bool>& visited, vector<int>& result){
        visited[node] = true;
        result.push_back(node);
        
        for(int neighbor : adj[node]){
            if(!visited[neighbor]) dfsUtil(neighbor, adj, visited, result);
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();
        unordered_map<int, bool> visited;
        vector<int> result;
        
        dfsUtil(0, adj, visited, result);
        return result;
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    void dfsUtil(int node, vector<vector<int>>& adj, unordered_map<int, bool>& visited, vector<int>& result){
```
- **Line 1:** A class `Solution` is defined, which contains the main logic for DFS.
- **Line 2:** The method `dfsUtil` is defined as a helper function that will recursively traverse the graph. It takes the following parameters:
  - `node`: the current node to start DFS from.
  - `adj`: the adjacency list representing the graph.
  - `visited`: a map to keep track of visited nodes to prevent revisiting.
  - `result`: a vector that stores the nodes in the order they are visited.

```cpp
        visited[node] = true;
        result.push_back(node);
```
- **Line 3:** Mark the current node as visited by setting `visited[node] = true`.
- **Line 4:** Add the current node to the `result` vector to record the DFS traversal order.

```cpp
        for(int neighbor : adj[node]){
            if(!visited[neighbor]) dfsUtil(neighbor, adj, visited, result);
        }
```
- **Line 5-7:** For each neighbor of the current node, check if it is visited.
  - If a neighbor has not been visited, recursively call `dfsUtil` on the neighbor. This continues until all neighbors are explored.

```cpp
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();
        unordered_map<int, bool> visited;
        vector<int> result;
        
        dfsUtil(0, adj, visited, result);
        return result;
    }
};
```
- **Line 8-10:** The function `dfsOfGraph` is the main function that initializes the visited map and result vector. It then calls `dfsUtil` starting from node `0`.
- **Line 11:** Finally, the function returns the `result` vector, which contains the DFS traversal order.



### **Step 3: Example with Explanation**

Let's consider the graph:

```
0: [1, 2]
1: [0, 3, 4]
2: [0]
3: [1]
4: [1]
```

**Step-by-Step DFS Traversal:**

1. **Start at node `0`:**
   - Mark node `0` as visited.
   - Add node `0` to the result: `result = [0]`.
   - Visit neighbors of `0`: nodes `1` and `2`.

2. **Move to node `1`:**
   - Mark node `1` as visited.
   - Add node `1` to the result: `result = [0, 1]`.
   - Visit neighbors of `1`: nodes `0`, `3`, and `4`.
     - Node `0` is already visited, so we move to node `3`.

3. **Move to node `3`:**
   - Mark node `3` as visited.
   - Add node `3` to the result: `result = [0, 1, 3]`.
   - Visit neighbors of `3`: node `1` is already visited, so we backtrack.

4. **Backtrack to node `1` and move to node `4`:**
   - Mark node `4` as visited.
   - Add node `4` to the result: `result = [0, 1, 3, 4]`.
   - Visit neighbors of `4`: node `1` is already visited, so we backtrack.

5. **Backtrack to node `0` and move to node `2`:**
   - Mark node `2` as visited.
   - Add node `2` to the result: `result = [0, 1, 3, 4, 2]`.
   - Visit neighbors of `2`: node `0` is already visited, so we finish.

The **DFS order** is: `[0, 1, 3, 4, 2]`.



### **Step 4: Time and Space Complexity**

#### **Time Complexity:**
- **DFS Traversal:** Each node is visited once and each edge is checked once. So, the time complexity is proportional to the number of vertices and edges.
- **Time Complexity:** **`O(V + E)`**, where `V` is the number of vertices and `E` is the number of edges in the graph.

#### **Space Complexity:**
- **Visited Map:** We use an unordered map to track visited nodes, which takes `O(V)` space.
- **Recursion Stack:** The depth of the recursion tree is at most `V` in the worst case, so the recursion stack takes `O(V)` space.
- **Result Vector:** The result vector stores all the vertices, which takes `O(V)` space.
- **Space Complexity:** **`O(V)`**.



### **Step 5: Recommendations for Students**

1. **Understand the Graph Representation:** Make sure you understand how graphs can be represented (adjacency list vs adjacency matrix).
2. **Recursive vs Iterative DFS:** While this solution uses recursion, DFS can also be implemented iteratively using an explicit stack. Try implementing both to understand the differences.
3. **Edge Cases:** Consider edge cases like disconnected graphs, graphs with only one node, or graphs with cycles.
4. **Practice on Various Graphs:** Try running DFS on graphs of different structures (e.g., trees, cyclic graphs, and disconnected graphs) to get a solid understanding.
5. **Explore Applications of DFS:** DFS is useful for finding connected components, checking for cycles, topological sorting, etc. Try solving problems involving these concepts to enhance your understanding of DFS.
