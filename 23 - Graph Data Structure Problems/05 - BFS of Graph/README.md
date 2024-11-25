<h1 align='center'>BFS - Of Graph</h1>

## Problem Statement

**Problem URL :** [BFS of Graph](https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

![image](https://github.com/user-attachments/assets/13cd0185-a48f-483e-aba9-9135802de86e)
![image](https://github.com/user-attachments/assets/6cfda1aa-8c6d-4a00-ae5c-eb6ed31b3e21)
![image](https://github.com/user-attachments/assets/0d0be56f-0496-43aa-baf0-2ff7f481a3b9)

## Problem Explanation
#### **Problem Description:**
The problem asks to perform a **Breadth First Traversal (BFS)** of a graph. BFS is an algorithm for traversing or searching tree or graph data structures. It starts at the root (selecting some arbitrary node as the root in case of a graph) and explores the neighbor nodes at the present depth level before moving on to nodes at the next depth level.

#### **Input:**
- A graph represented as an **adjacency list**, where each vertex has a list of all the vertices it is connected to.

#### **Output:**
- A list of vertices in the order they are visited in a **BFS traversal**.

#### **Example:**

Given a graph represented by the following adjacency list:

```
0: [1, 2]
1: [0, 3, 4]
2: [0]
3: [1]
4: [1]
```

Here, vertex 0 is connected to 1 and 2, vertex 1 is connected to 0, 3, and 4, and so on.

**Starting from node 0**, the BFS traversal will visit the nodes level by level:
- Start at node `0`, then visit its neighbors `1` and `2`.
- Visit the neighbors of node `1`, which are `3` and `4` (in the order they appear).

The expected BFS traversal order is: `0, 1, 2, 3, 4`.

#### **Approach:**
1. **Initialize:**
   - A **queue** to keep track of the nodes to visit.
   - A **visited list** to ensure that each node is visited only once.
   - A **result list** to store the nodes in the order they are visited.

2. **BFS Traversal:**
   - Start by adding the starting node (e.g., node `0`) to the queue and mark it as visited.
   - While the queue is not empty:
     - Pop the front element from the queue (this is the current node).
     - Add this node to the result list.
     - For each neighbor of the current node, if it has not been visited, add it to the queue and mark it as visited.

3. **Return the result list** containing the BFS order.

## Problem Solution
```cpp
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            
            result.push_back(currentNode);
            
            for(int neighbor : adj[currentNode]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return result;
        
    }
};
```

## Problem Solution Explanation

```cpp
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
```
- **Line 1:** This starts the definition of the `Solution` class with a public method `bfsOfGraph`.
- **Line 2:** The function `bfsOfGraph` takes an adjacency list (`adj`) as input and returns a vector of integers, which will represent the BFS traversal order.

```cpp
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V, false);
        queue<int> q;
```
- **Line 3:** We define `V` as the size of the adjacency list, which is the number of vertices in the graph.
- **Line 4:** `result` will store the BFS traversal order, initialized as an empty vector.
- **Line 5:** `visited` is a boolean vector that keeps track of whether a vertex has been visited or not. It's initialized to `false` for all vertices.
- **Line 6:** `q` is a queue that stores the vertices to be visited during BFS.

```cpp
        q.push(0);
        visited[0] = true;
```
- **Line 7:** We start the BFS traversal from vertex `0` by pushing it into the queue `q`.
- **Line 8:** Mark vertex `0` as visited by setting `visited[0]` to `true`.

```cpp
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
```
- **Line 9-10:** We enter a while loop that continues as long as the queue is not empty. In each iteration:
  - **Line 9:** `currentNode` is assigned the value of the front element of the queue (i.e., the node to be processed).
  - **Line 10:** We pop the front element from the queue since it has been processed.

```cpp
            result.push_back(currentNode);
```
- **Line 11:** We add the `currentNode` to the `result` vector to record the order in which nodes are visited.

```cpp
            for(int neighbor : adj[currentNode]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
```
- **Line 12-16:** For each neighbor of the `currentNode` (i.e., for every element in the adjacency list of the `currentNode`):
  - **Line 12:** We iterate over the neighbors of `currentNode`.
  - **Line 13:** If the neighbor has not been visited (`!visited[neighbor]`), we:
    - **Line 14:** Push the neighbor into the queue to visit it later.
    - **Line 15:** Mark the neighbor as visited.

```cpp
        }
        
        return result;
    }
};
```
- **Line 17-19:** Once all neighbors of the current node are processed, the loop continues with the next node in the queue. After the queue is empty, the function returns the `result` vector containing the BFS traversal order.

### **Step 3: Example with Explanation**

Consider the graph with 5 vertices, represented as the adjacency list:

```
0: [1, 2]
1: [0, 3, 4]
2: [0]
3: [1]
4: [1]
```

**Step-by-Step BFS Traversal:**

1. **Start at node 0**:
   - Mark node `0` as visited.
   - Add node `0` to the result: `result = [0]`.
   - Add its neighbors (1, 2) to the queue: `q = [1, 2]`.

2. **Process node 1**:
   - Dequeue node `1`, mark it as visited.
   - Add node `1` to the result: `result = [0, 1]`.
   - Add its unvisited neighbors (3, 4) to the queue: `q = [2, 3, 4]`.

3. **Process node 2**:
   - Dequeue node `2`, mark it as visited.
   - Add node `2` to the result: `result = [0, 1, 2]`.
   - Node `0` is already visited, so no new neighbors to add.

4. **Process node 3**:
   - Dequeue node `3`, mark it as visited.
   - Add node `3` to the result: `result = [0, 1, 2, 3]`.
   - Node `1` is already visited, so no new neighbors to add.

5. **Process node 4**:
   - Dequeue node `4`, mark it as visited.
   - Add node `4` to the result: `result = [0, 1, 2, 3, 4]`.
   - Node `1` is already visited, so no new neighbors to add.

At the end, the **BFS order** is: `[0, 1, 2, 3, 4]`.

### **Step 4: Time and Space Complexity**

#### **Time Complexity:**
- **Queue Operations:** Each vertex is added and removed from the queue exactly once. This results in `O(V)` time for all vertices.
- **Neighbor Processing:** For each vertex, we process all its neighbors, and each edge is processed once. This gives `O(E)` time for all edges.
- Thus, the overall **time complexity** is: **`O(V + E)`**, where `V` is the number of vertices and `E` is the number of edges in the graph.

#### **Space Complexity:**
- **Visited Array:** We use an array of size `V` to mark visited nodes, which takes `O(V)` space.
- **Queue:** The maximum number of nodes in the queue at any time is `O(V)`.
- **Result Array:** The result array stores all the vertices, which takes `O(V)` space.
- Thus, the overall **space complexity** is: **`O(V)`**.

### **Step 5: Recommendations for Students**

1. **Understand BFS Concept:** Make sure you understand the concept of BFS and how it explores nodes level by level.
2. **Practice on Different Graph Representations:** Try implementing BFS on different graph representations (adjacency matrix, adjacency list, etc.).
3. **Edge Cases:** Be mindful of edge cases, like when the graph is disconnected or when there are no edges.
4. **Explore Variants:** BFS can be used to solve problems like finding the shortest path in an unweighted graph. Try solving such problems to enhance your understanding of BFS.

