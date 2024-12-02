<h1 align='center'>Critical - Connections - in a - Network</h1>

## Problem Statement

**Problem URL :** [Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)

![image](https://github.com/user-attachments/assets/a56e7cdf-b7ae-4876-b18f-f57401571f3d)
![image](https://github.com/user-attachments/assets/de20f0db-44b2-495c-84e1-87858eb0b290)

## Problem Explanation
The problem **Critical Connections in a Network** asks us to find all the critical connections in a given network of servers represented as an undirected graph. A **critical connection** (also known as a **bridge**) is an edge in the network whose removal will increase the number of connected components. In simpler terms, if we remove that edge, the network will be split into two or more disconnected parts.

#### Example:

Consider the following network of servers:

- `n = 4` (number of servers)
- Connections (edges): `[[0,1], [1,2], [2,0], [1,3]]`

This means:
- Server `0` is connected to Server `1` and Server `2`
- Server `1` is connected to Server `0`, Server `2`, and Server `3`
- Server `2` is connected to Server `1` and Server `0`
- Server `3` is connected to Server `1`

The graph representation looks like this:

```
    0 - 1 - 3
    |   |
    2 - 
```

#### Objective:
We need to identify the critical connections in the network. Let's analyze the connections:

- If we remove the edge `(1, 3)`, we disconnect Server `3` from the rest of the network. So, `(1, 3)` is a critical connection.
- If we remove the edge `(0, 1)`, the network will still remain connected through Server `2`. So, this is not a critical connection.

Therefore, the only critical connection in this case is `[1, 3]`.

#### Approach:

1. **Understanding Bridges**: A bridge is an edge in an undirected graph that, when removed, increases the number of connected components. 
   
2. **DFS Traversal**: 
   - We can use **Depth-First Search (DFS)** to explore the graph. During the DFS traversal, we keep track of:
     - **Discovery Time (`disc`)**: The time when a node is first visited.
     - **Lowest Point (`low`)**: The lowest discovery time reachable from a node, which includes its neighbors and any back edges.
   
3. **Bridge Condition**:
   - For each edge `(u, v)`, if `low[v] > disc[u]`, then the edge `(u, v)` is a **bridge**. This is because there is no way to reach a node earlier than `u` from `v` through a back edge.

4. **DFS Tree**: 
   - We maintain a DFS tree and check for each edge if it's a bridge based on the `low` and `disc` values.

## Problem Solution
```cpp
class Solution {
public:
    // Helper function to perform DFS traversal and find critical connections
    void DFS(int server, int timer, int parentServer, vector<int>& low, vector<int>& disc, vector<int>& visited, vector<vector<int>>& criticalEdge, vector<vector<int>>& connections){

        // Mark the current server as visited
        visited[server] = true;

        // Set discovery time and lowest reachable time for the current server
        disc[server] = low[server] = timer++; // timer is incremented after setting the discovery time
        
        // Explore all neighboring servers (connections)
        for(int & neighbourServer : connections[server]){
            
            // Skip the parent server to avoid going back to the parent in the DFS tree
            if(neighbourServer == parentServer) continue;

            // If the neighboring server is not visited, explore it
            if(!visited[neighbourServer]){
                DFS(neighbourServer, timer, server, low, disc, visited, criticalEdge, connections);

                // After visiting the neighbor, update the low time for the current server
                low[server] = min(low[server], low[neighbourServer]);

                // If the lowest time of the neighbor is greater than the discovery time of the current server,
                // it indicates that the edge between current server and the neighbor is a critical connection.
                if(low[neighbourServer] > disc[server]) 
                    criticalEdge.push_back({server, neighbourServer});
            }else {
                // If the neighboring server was already visited, update the low time
                low[server] = min(low[server], low[neighbourServer]);
            }
        }
    }

    // Main function to find all critical connections in the network
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Arrays to store the lowest time reachable from a server and the discovery time of each server
        vector<int> low(n, -1);
        vector<int> disc(n, -1);
        
        // Array to track if a server has been visited
        vector<int> visited(n, false);

        // To store the critical connections (edges)
        vector<vector<int>> criticalEdge;

        // Adjacency list to represent the network of servers
        vector<vector<int>> adjacencyList(n);
        
        // Build the adjacency list from the connections
        for(auto& edge : connections){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Start DFS from each server that hasn't been visited
        for(int i = 0; i < n; i++) 
            if(!visited[i]) 
                DFS(i, 0, -1, low, disc, visited, criticalEdge, adjacencyList);

        // Return the list of critical connections (edges)
        return criticalEdge;
    }
};

```

## Problem Solution Explanation

Now, let's go through the code to understand how it works.

#### `DFS` function:

```cpp
void DFS(int server, int timer, int parentServer, vector<int>& low, vector<int>& disc, vector<int>& visited, vector<vector<int>>& criticalEdge, vector<vector<int>>& connections) {
```
- This is the DFS function. It takes the following parameters:
  - `server`: The current server (node) being visited.
  - `timer`: A variable to keep track of the discovery time (increments with each visit).
  - `parentServer`: The parent of the current node, used to avoid revisiting the parent in DFS.
  - `low`: Stores the lowest discovery time reachable from a server.
  - `disc`: Stores the discovery time of each server.
  - `visited`: Tracks whether a server has been visited.
  - `criticalEdge`: Stores the critical connections (bridges).
  - `connections`: The adjacency list of the graph.

```cpp
    visited[server] = true;              // Mark the current server as visited
    disc[server] = low[server] = timer++; // Set the discovery and low time of the current server
```
- The `server` is marked as visited.
- We set the discovery time `disc[server]` and low time `low[server]` for this server to the current `timer` and then increment `timer`.

```cpp
    for(int & neighbourServer : connections[server]) {
```
- Loop through all the neighbors (connections) of the current server.

```cpp
        if(neighbourServer == parentServer) continue;  // Skip the parent node to avoid going backward in the DFS
```
- If the neighbor is the parent of the current server, skip it to avoid a backward traversal in the DFS tree.

```cpp
        if(!visited[neighbourServer]) {
```
- If the neighbor has not been visited, perform DFS on it.

```cpp
            DFS(neighbourServer, timer, server, low, disc, visited, criticalEdge, connections);
            low[server] = min(low[server], low[neighbourServer]);
```
- Recursively call DFS for the unvisited neighbor.
- After returning from the DFS call, update `low[server]` to the minimum of `low[server]` and `low[neighbourServer]`.

```cpp
            if(low[neighbourServer] > disc[server]) criticalEdge.push_back({server, neighbourServer});
```
- If `low[neighbourServer] > disc[server]`, this means there is no back edge from `neighbourServer` to any ancestor of `server`, indicating that `(server, neighbourServer)` is a critical connection (bridge).

```cpp
        } else low[server] = min(low[server], disc[neighbourServer]);
    }
}
```
- If the neighbor is already visited, update `low[server]` to the minimum of its current value and the discovery time of the neighbor.

#### `criticalConnections` function:

```cpp
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<int> low(n, -1);        // Low time for each server, initially set to -1
    vector<int> disc(n, -1);       // Discovery time for each server, initially set to -1
    vector<int> visited(n, false); // Visited array to track visited servers
    vector<vector<int>> criticalEdge; // Stores critical connections (bridges)
    vector<vector<int>> adjacencyList(n); // Adjacency list of the graph
```
- Initialize necessary arrays for `low`, `disc`, `visited`, and the result list `criticalEdge`.

```cpp
    for(auto& edge : connections) {
        adjacencyList[edge[0]].push_back(edge[1]);
        adjacencyList[edge[1]].push_back(edge[0]);
    }
```
- Convert the list of connections into an adjacency list representation of the graph.

```cpp
    for(int i = 0; i < n; i++) 
        if(!visited[i]) DFS(i, 0, -1, low, disc, visited, criticalEdge, adjacencyList);
```
- Run DFS from every unvisited server to ensure all servers are explored.

```cpp
    return criticalEdge; // Return the list of critical connections (bridges)
}
```
- After DFS completes, return the list of critical connections.

### Step 3: Example Walkthrough

Let's use an example to demonstrate how the code works.

#### Example 1:
```
n = 4
connections = [[0,1], [1,2], [2,0], [1,3]]
```

- Convert `connections` into an adjacency list:
  ```
  adjacencyList = [[1, 2], [0, 2, 3], [0, 1], [1]]
  ```

- Run DFS starting from node `0`:
  - Visit node `0`, discovery time is `0`, low time is `0`.
  - Visit node `1`, discovery time is `1`, low time is `1`.
  - Visit node `2`, discovery time is `2`, low time is `2`.
  - Visit node `3`, discovery time is `3`, low time is `3`.
  - Backtrack and update low values.
  - Edge `(1, 3)` is identified as a critical connection because `low[3] > disc[1]`.

Output: `[[1, 3]]`

### Step 4: Time and Space Complexity

- **Time Complexity**: 
  - The DFS traversal visits each node and edge once. Therefore, the time complexity is O(V + E), where V is the number of vertices (servers) and E is the number of edges (connections).
  
- **Space Complexity**:
  - We use several arrays to store the `disc`, `low`, and `visited` information, each of size O(V). The adjacency list also takes O(E) space.
  - Therefore, the space complexity is O(V + E).

### Step 5: Additional Recommendations

- Understand the concept of **DFS** and **low/discovery times** thoroughly, as they are key to identifying bridges.
- Practice more problems related to graph traversal (DFS/BFS) and bridges to strengthen your problem-solving skills.
- Try solving similar problems using different graph traversal techniques like BFS to get a better understanding.
